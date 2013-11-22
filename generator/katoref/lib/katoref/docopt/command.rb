
require "docopt"

module KatoRef
  module Docopt
    class Command

      DEPRECATED_COMMANDS = {
      }

      def initialize(cli_dir, argv=[])
	@cli_dir = cli_dir
        @argv = argv
      end

      def sub_command_names
        dir = get_cmd_dir(@argv)
        Dir.entries(dir).select {|entry| File.directory? File.join(dir, entry) and not entry.start_with? "." }.sort
      end

      def tokenized
        usage_pattern = ::Docopt.formal_usage(::Docopt.printable_usage(get_cmd_usage))
        usage_pattern_list = self.class.parse_usage_pattern usage_pattern
      end

      def usage_sections
        description_lines = []
        section = nil
        sections = {}
        get_cmd_usage.split(/\r?\n/).each do |line|

          # Anchored to start of line, ends in ":"
          if /^(Usage|Options|Arguments|Commands)\:\s*$/.match(line)
            # section heading such as "Usage:" or "Options:"
            section = $1.downcase.to_sym

          # 2-spaces then text within section
          elsif section and /^\s{2}(\S+(?:\s\S+)*)?\s{2}?\s*(\S.*)\s*$/.match(line)
            # line under section "Usage:" or "Options:"
            sections[section] ||= []
            if $1
              description_line = $2
              sections[section] << {
                :arg => $1.split(/[\s\,]+/),
                :description => [description_line]
              }
            elsif sections[section].size > 0
              sections[section][-1][:description] << $2
            else
              $stderr.puts "Unrecognized section line : '#{line}' for #{File.join(@argv)} #{section} section"
            end

          # in section, with blank line
          elsif section and line.strip.size == 0
            # skip blank lines within section

          else
            # description line
            section = nil
            sections[:description] ||= []
            if sections[:description].size > 0 or line.strip.size > 0
              sections[:description] << line
            end
          end

        end

        # remove blank lines from the end of the description
        sections[:description].reverse.each do |line|
          if line.strip.size == 0
            sections[:description].pop
          else
            break
          end
        end

        sections.keys.each do |section|
          if sections[section].join("\n").strip == ""
            sections.delete(section)
          end
        end

        sections
      end

      def get_cmd_dir(argv=@argv)
        File.join(@cli_dir, "cmd", argv.join("/"))
      end

      def has_specific_usage_file?(argv=@argv)
        File.file? File.join(get_cmd_dir(argv), "usage")
      end

      def get_cmd_usage(argv=@argv)
        cmd_dir = get_cmd_dir(argv)
        usage_path = File.join(cmd_dir, "usage")
        usage_erb_path = File.join(cmd_dir, "usage.erb")
        if File.file? usage_path
          IO.read(usage_path)
        elsif File.file? usage_erb_path
          require "erb"

          cmds = {}
          DEPRECATED_COMMANDS.each_pair do |old_cmd, new_cmd|
            cmds[old_cmd] = "DEPRECATED: Use \"kato #{new_cmd}\"."
          end

          # Get the first line from each sub-command
          Dir.foreach(cmd_dir) do |filename|
            next if filename.start_with? "."
            cmd_path = File.join(cmd_dir, filename)
            next unless File.directory? cmd_path
            cmds[filename] = ""
            File.open(File.join(cmd_path, "usage")).each do |line|
              line.strip!
              if line.size > 0
                if line != "Usage:"
                  cmds[filename] = line
                end
                break
              end
            end
          end

          # Render the ERB template
          ERB.new(IO.read(usage_erb_path), 0, "%").result(binding)
        else
          raise "File not found : #{usage_path}"
        end
      end

      def self.parse_usage_pattern usage_pattern
        parsed = []
        while usage_pattern.sub!(/^\s*\(\s*/, "") # open command
          current = []
          while true
            # close command
            if usage_pattern.sub!(/^\s*\)\s*/, "")
              parsed << current
              break
            end
            # enumerated options. eg. " ( grant | revoke ) "
            if usage_pattern.sub! /^\s*\(\s*([^\)]+)\s*\)\s*/ do |match|
                current << $1.split(/\s*\|\s*/)
                ''
              end
            # variable or variable list... eg. "<foo>" or "<foo>..." or "<foo-bar>"
            elsif usage_pattern.sub! /^\s*(\<[^\>]+\>(?:\.\.\.)?)\s*/ do |match|
                current << $1
                ''
              end
            # optional variable or option. eg. "[<foo>]" or "[--node <node-IP>]"
            elsif usage_pattern.sub! /^\s*(\[[^\]]+\])\s*/ do |match|
                current << $1
                ''
              end
            # command keyword. eg. "config" or "monkey-nuts"
            elsif usage_pattern.sub! /^\s*(\S+)\s*/ do |match|
                current << $1
                ''
              end
            else
              raise "No pattern match for '#{usage_pattern}'"
            end
            if current.size > 100
              raise "Parsing failed '#{usage_pattern}'"
            end
          end
          unless usage_pattern.sub!(/^\s*\|\s*/, "")
            break
          end
        end
        parsed
      end

    end
  end
end
