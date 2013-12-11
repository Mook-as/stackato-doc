
require "erb"
require "katoref/docopt/command"

KATO_ROOT = File.join(File.dirname(__FILE__), "../../../../docopts/kato")

# find cli cmds in the following kato lib directories
$LOAD_PATH << File.join(KATO_ROOT, "lib")
$LOAD_PATH << File.join(KATO_ROOT, "cli/lib")
$LOAD_PATH << File.join(KATO_ROOT, "upgrade/lib")

TEMPLATE_FILENAME = File.join(File.dirname(__FILE__), "..", "..", "..", "..", "doc", "reference", "kato-ref.rst.erb")
 
class String
  def syntax_highlight
    return unless self and self.size > 0
    if self.start_with? "["
      # highlight inside "[...]" only
      self.sub(/^\s*(\[)\s*([^\]]+)\s*(\])\s*$/) { |match| [$1, $2.syntax_highlight, $3].join("") }
    elsif self.start_with? "<"
      # single star highlight around "<...>"
      "*#{self}*"
    elsif self.start_with? "-"
      # highlight "-arg", "--arg", "-a <arg>" or "--arg <arg>"
      # "--arg <arg>" becomes "**--arg** *<arg>*"
      self.sub(/^\s*(\S+)(?:\s+(\S+))?\s*$/) { |match| ["**", $1, "**", ($2 && [" ", $2.syntax_highlight])].flatten.join("") }
    else
      # highlight whole string
      "**#{self}**"
    end
  end
end

def push_sub_cmds(cmds, argv)
  sibling_usage_cmds = []
  parent_argv = argv
  KatoRef::Docopt::Command.new(parent_argv).sub_command_names.each do |cmd_name|
    argv = parent_argv + [cmd_name]
    command = KatoRef::Docopt::Command.new(argv)
    if command.has_specific_usage_file?
      cmd = {
        :name => argv.join(" "),
        :level => argv.size,
        :argv => argv,
        :token_lines => command.tokenized,
      }
      cmds << cmd
      child_cmds = push_sub_cmds(cmds, argv)
      if child_cmds.size > 0
        cmd[:has_children] = true
        cmd[:children] = child_cmds
        added_child_usage = true
      else
        cmd.update(command.usage_sections)
        sibling_usage_cmds << cmd
      end
    else
      $stderr.puts "No command.has_specific_usage_file for #{argv}"
    end
  end
  sibling_usage_cmds
end

def render_kato_ref(template_filename=TEMPLATE_FILENAME)
  cmds = []
  one_liners = {}
  KatoRef::Docopt::Command.new.usage_sections[:commands].each do |command|
    one_liners[command[:arg].join(" ")] = command[:description].join(" ")
  end
  push_sub_cmds(cmds, [])
  cmds.each do |cmd|
    if cmd[:level] == 1
      cmd[:one_liner] = one_liners[cmd[:name]]
    end
  end
  template = ERB.new(IO.read(template_filename), 0, "%")
  puts template.result(binding)
end

