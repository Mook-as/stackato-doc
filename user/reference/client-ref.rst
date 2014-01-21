.. index:: Command Reference: Client

.. _command-ref-client:

Stackato Client Command Reference
=================================

Usage
-----

**stackato** [*options*] *command* [*arguments*] [*command-options*]

Try ``stackato help``, ``stackato help [command]``, and ``stackato options`` for more information.

Many of the informational commands take a ``--json`` option if you wish to generate machine-parseable output.
In some cases the  ``--json`` option reveals additional details.

.. note::
    Administrative user privileges are required for some commands.

  
Getting Started
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-stackato login:
  
  stackato login  *<email>* 
    Log in to the current or specified target with the named user.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --credentials
      
		The credentials to use.
		Each use of the option declares a single element,
		using the form "key: value" for the argument.
		This is a Stackato 3 specific option.
	    
    --group
      
		The group to use for the login.
		This is a Stackato 2 specific option.
	    
    --ignore-missing
      
		Disable errors generated for missing organization and/or space.
	    
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
		The organization to use.
		This is a Stackato 3 specific option.
		If not specified the user is asked interactively
		to choose an organization.
	    
    --passwd
      Alias of --password.
    --password
      
		The password to use. 
		For Stackato 3 this is a shorthand
		for --credentials 'password: ...'.
	    
    --space
      
		The space (in the organization) to use.
		This is a Stackato 3 specific option.
		If not specified the user is asked interactively
		to choose among the possible spaces in
		either the chosen organization, or all
		organizations it belongs to.
	    
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato logout:
  
  stackato logout  *<target>* 
    Log out of the current, specified, or all targets.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --all
      
		When present, log out of all targets we know.
		Cannot be used together with a target.
	    
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato target:
  
  stackato target  *<url>* 
    Set the target API endpoint for the client, or report the current target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --allow-http
      
	    Required to prevent the client from rejecting http urls.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The organization to set as current for this target.
	    This is a Stackato 3 specific option.
	
    --space
      
	    The space to set as current for this target.
	    This is a Stackato 3 specific option.
	
    --verbose
       More verbose operation. 
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -s
      Alias of --space.

      </div></div>

  
Applications
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-stackato apps:
  
  stackato apps 
    List the applications deployed to the target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --all
      
		Show all applications instead of just those
		associated with the current space.
	    
    --group
      
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
    --space
      
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
    --space-guid
      
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.
    
.. _command-stackato app:
  
  stackato app  *<application>* 
    Show the information of the specified application.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --group
      
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --manifest
      
	    Path of the manifest file to use.
	    If not specified a search is done.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
    --path
      
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
    --space
      
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
    --space-guid
      
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.
    
.. _command-stackato list:
  
  stackato list 
    List the applications deployed to the target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --all
      
		Show all applications instead of just those
		associated with the current space.
	    
    --group
      
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
    --space
      
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
    --space-guid
      
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.

      </div></div>

    
.. _command-Applications-Information:
    
  **Information**
      
.. _command-stackato crashes:

      stackato crashes  *<application>*       
        List recent application crashes.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato crashlogs:

      stackato crashlogs  *<application>*       
        Display log information for the application. An alias of 'logs'.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --all
          
		Retrieve the logs from all instances. Before 2.3 only.
	    
        --filename
          
		Filter the log stream by origin file (glob pattern).
		Target version 2.4+ only.
	    
        --follow
          
		Tail -f the log stream. Target version 2.4+ only.
	    
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --instance
          
		The id of the instance to filter the log stream for,
		or (before 2.3), to retrieve the logs of.
	    
        --json
          
		Print the raw json log stream, not human-formatted data.
	    
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --num
          
		Show the last num entries of the log stream.
		Target version 2.4+ only.
	    
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --prefix
          
		Put instance information before each line of a
		shown log file. Before 2.3 only.
	    
        --prefix-logs
          Alias of --prefix.
        --prefixlogs
          Alias of --prefix.
        --source
          
		Filter the log stream by origin stage (glob pattern).
		Target version 2.4+ only.
	    
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --text
          
		Filter the log stream by log entry text (glob pattern).
		Target version 2.4+ only.
	    
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato disk:

      stackato disk  *<application>*       
        Show the disk reservation for a deployed application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato drain list:

      stackato drain list  *<application>*       
        Show the list of drains attached to the application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato drains:

      stackato drains  *<application>*       
        Show the list of drains attached to the application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato env:

      stackato env  *<application>*       
        List the application's environment variables.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato events:

      stackato events  *<application>*       
        Show recorded application events, for application or space. Without an application given the current or specified space is used, otherwise that application. This is a Stackato 3 specific command.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato files:

      stackato files  *<application>*  *<apath>*       
        Display directory listing or file.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --all
          
		When present, access all instances for the file or directory.
		Cannot be used together with --instance.
	    
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --instance
          
		When present the instance to query.
		Cannot be used together with --all.
		Defaults to 0 (except when --all is present).
	    
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --prefix
          
		Put instance information before each line of a
		shown file or directory listing. Effective only
		for --all.
	    
        --prefix-logs
          Alias of --prefix.
        --prefixlogs
          Alias of --prefix.
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato file:

      stackato file  *<application>*  *<apath>*       
        Display directory listing or file.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --all
          
		When present, access all instances for the file or directory.
		Cannot be used together with --instance.
	    
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --instance
          
		When present the instance to query.
		Cannot be used together with --all.
		Defaults to 0 (except when --all is present).
	    
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --prefix
          
		Put instance information before each line of a
		shown file or directory listing. Effective only
		for --all.
	    
        --prefix-logs
          Alias of --prefix.
        --prefixlogs
          Alias of --prefix.
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato health:

      stackato health  *<application>*       
        Report the health of the specified application(s).

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --all
          
		Report on all applications in the current space.
		Cannot be used together with application names.
	    
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -t
          Alias of --trace.


.. _command-stackato instances:

      stackato instances  *<application>*       
        List application instances for a deployed application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato logs:

      stackato logs  *<application>*       
        Display the application log stream.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --all
          
		Retrieve the logs from all instances. Before 2.3 only.
	    
        --filename
          
		Filter the log stream by origin file (glob pattern).
		Target version 2.4+ only.
	    
        --follow
          
		Tail -f the log stream. Target version 2.4+ only.
	    
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --instance
          
		The id of the instance to filter the log stream for,
		or (before 2.3), to retrieve the logs of.
	    
        --json
          
		Print the raw json log stream, not human-formatted data.
	    
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --num
          
		Show the last num entries of the log stream.
		Target version 2.4+ only.
	    
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --prefix
          
		Put instance information before each line of a
		shown log file. Before 2.3 only.
	    
        --prefix-logs
          Alias of --prefix.
        --prefixlogs
          Alias of --prefix.
        --source
          
		Filter the log stream by origin stage (glob pattern).
		Target version 2.4+ only.
	    
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --text
          
		Filter the log stream by log entry text (glob pattern).
		Target version 2.4+ only.
	    
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato mem:

      stackato mem  *<application>*       
        Show the memory reservation for a deployed application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato stats:

      stackato stats  *<application>*       
        Display the resource usage for a deployed application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato tail:

      stackato tail  *<application>*  *<apath>*       
        Monitor file for changes and stream them.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --instance
          
		When present the instance to query.
		Cannot be used together with --all.
		Defaults to 0 (except when --all is present).
	    
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


    
.. _command-Applications-Management:
    
  **Management**
      
.. _command-stackato create-app:

      stackato create-app  *<application>*       
        Create an empty application with the specified configuration.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --buildpack
          
		Url of a custom buildpack.
		This is a Stackato 3 specific option.
	    
        --command
          
		The application's start command.
		Defaults to a framework-specific value if required
		and not specified by stackato.yml.
	    
        --disk
          
		The application's per-instance disk allocation.
		Defaults to a framework-specific value if not
		specified by stackato.yml.
	    
        --env
          
		Environment variable overrides. These are always applied
		regardless of --env-mode. The mode is restricted to the
		variable declarations found in the manifest.
	    
        --env-mode
          
		Environment replacement mode. One of preserve, or replace.
		The default is "preserve". Using mode "replace" implies
		--reset as well, for push. Note that new variables are always
		set. Preserve only prevents update of existing variables.
		This setting applies only to the variable declarations found
		in the manifest.  Overrides made with --env are always applied.
	    
        --framework
          
		Specify the framework to use.
		Cannot be used together with --no-framework.
		Defaults to a heuristically chosen value if
		not specified, and none for --no-framework.
		This is a Stackato 2 specific option.
	    
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --instances
          
		The number of application instances to create.
		Defaults to 1, if not specified by a stackato.yml.
	    
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --mem
          
		The application's per-instance memory allocation.
		Defaults to a framework-specific value if not
		specified by stackato.yml.
	    
        --no-framework
          
		Create application without any framework.
		Cannot be used together with --framework.
		This is a Stackato 2 specific option.
	    
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --reset
          
		Analogue of --env-mode, for the regular settings.
	    
        --runtime
          
		The name of the runtime to use.
		Default is framework specific, if not specified
		by a stackato.yml.
		This is a Stackato 2 specific option.
	    
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --stack
          
		The OS foundation the application will run on.
		This is a Stackato 3 specific option.
	    
        --stackato-debug
          
		host:port of the Komodo debugger listener to inject
		into the application as environment variables.
	    
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --url
          
		The urls to map the application to.
		I.e. can be specified muliple times.
	    
        -d
          
		Set up debugging through an application-specific
		harbor (port) service. Target version 2.8+ only.
	    
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato dbshell:

      stackato dbshell  *<application>*  *<service>*       
        Invoke interactive db shell for a bound service.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --dry
          
	    Print the low-level ssh command to stdout
	    instead of executing it.
	
        --dry-run
          Alias of --dry.
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato delete:

      stackato delete  *<application>*       
        Delete the specified application(s).

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --all
          
		Delete all applications.
		Cannot be used together with application names.
	    
        --force
          
		Force deletion.
	    
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato drain add:

      stackato drain add  *<application>*  *<drain>*  *<uri>*       
        Attach a new named drain to the application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --json
          
		    The drain target takes raw json log entries.
		
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato drain delete:

      stackato drain delete  *<application>*  *<drain>*       
        Remove the named drain from the application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato env-add:

      stackato env-add  *<application>*  *<varname>*  *<value>*       
        Add the specified environment variable to the named application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --timeout
          
	    The time the client waits for an application to
	    start before giving up and returning, in seconds.
	    Note that this is measured from the last entry
	    seen in the log stream. While there is activity
	    in the log the timeout is reset.

	    The default is 2 minutes.

	    Use the suffixes 'm', 'h', and 'd' for the convenient
	    specification of minutes, hours, and days. The optional
	    suffix 's' stands for seconds.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato env-del:

      stackato env-del  *<application>*  *<varname>*       
        Remove the specified environment variable from the named application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --timeout
          
	    The time the client waits for an application to
	    start before giving up and returning, in seconds.
	    Note that this is measured from the last entry
	    seen in the log stream. While there is activity
	    in the log the timeout is reset.

	    The default is 2 minutes.

	    Use the suffixes 'm', 'h', and 'd' for the convenient
	    specification of minutes, hours, and days. The optional
	    suffix 's' stands for seconds.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato map:

      stackato map  *<application>*  *<url>*       
        Make the application accessible through the specified URL (a route consisting of host and domain)

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato open:

      stackato open  *<application>*       
        Open the url of the specified application in the default web browser. If 'api' is specified as the app name, the Management Console is opened. With no arguments, the 'name' value from the stackato.yml/manifest.yml in the current directory is used (if present).

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato push:

      stackato push  *<application>*       
        Configure, create, push, map, and start a new application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --as
          
		The name of the application to push/update the selected application as.
		Possible only if a single application is pushed or updated.
	    
        --buildpack
          
		Url of a custom buildpack.
		This is a Stackato 3 specific option.
	    
        --command
          
		The application's start command.
		Defaults to a framework-specific value if required
		and not specified by stackato.yml.
	    
        --copy-unsafe-links
          
		Links pointing outside of the application directory
		are copied into the application.
	    
        --disk
          
		The application's per-instance disk allocation.
		Defaults to a framework-specific value if not
		specified by stackato.yml.
	    
        --env
          
		Environment variable overrides. These are always applied
		regardless of --env-mode. The mode is restricted to the
		variable declarations found in the manifest.
	    
        --env-mode
          
		Environment replacement mode. One of preserve, or replace.
		The default is "preserve". Using mode "replace" implies
		--reset as well, for push. Note that new variables are always
		set. Preserve only prevents update of existing variables.
		This setting applies only to the variable declarations found
		in the manifest.  Overrides made with --env are always applied.
	    
        --force-start
          
		Push, and start the application, even when stopped.
	    
        --framework
          
		Specify the framework to use.
		Cannot be used together with --no-framework.
		Defaults to a heuristically chosen value if
		not specified, and none for --no-framework.
		This is a Stackato 2 specific option.
	    
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --instances
          
		The number of application instances to create.
		Defaults to 1, if not specified by a stackato.yml.
	    
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --mem
          
		The application's per-instance memory allocation.
		Defaults to a framework-specific value if not
		specified by stackato.yml.
	    
        --no-framework
          
		Create application without any framework.
		Cannot be used together with --framework.
		This is a Stackato 2 specific option.
	    
        --no-prompt
          
	    Disable interactive queries.
	
        --no-resources
          
		Do not optimize upload by checking for existing file resources.
	    
        --no-start
          
		Push, but do not start the application.
	    
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --noresources
          Alias of --no-resources.
        --nostart
          Alias of --no-start.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --reset
          
		Analogue of --env-mode, for the regular settings.
	    
        --runtime
          
		The name of the runtime to use.
		Default is framework specific, if not specified
		by a stackato.yml.
		This is a Stackato 2 specific option.
	    
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --stack
          
		The OS foundation the application will run on.
		This is a Stackato 3 specific option.
	    
        --stackato-debug
          
		host:port of the Komodo debugger listener to inject
		into the application as environment variables.
	    
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --timeout
          
	    The time the client waits for an application to
	    start before giving up and returning, in seconds.
	    Note that this is measured from the last entry
	    seen in the log stream. While there is activity
	    in the log the timeout is reset.

	    The default is 2 minutes.

	    Use the suffixes 'm', 'h', and 'd' for the convenient
	    specification of minutes, hours, and days. The optional
	    suffix 's' stands for seconds.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --url
          
		The urls to map the application to.
		I.e. can be specified muliple times.
	    
        -d
          
		Set up debugging through an application-specific
		harbor (port) service. Target version 2.8+ only.
	    
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato rename:

      stackato rename  *<application>*  *<name>*       
        Rename the specified application. This is a Stackato 3 specific command.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato restart:

      stackato restart  *<application>*       
        Stop and restart a deployed application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --timeout
          
	    The time the client waits for an application to
	    start before giving up and returning, in seconds.
	    Note that this is measured from the last entry
	    seen in the log stream. While there is activity
	    in the log the timeout is reset.

	    The default is 2 minutes.

	    Use the suffixes 'm', 'h', and 'd' for the convenient
	    specification of minutes, hours, and days. The optional
	    suffix 's' stands for seconds.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato run:

      stackato run  *<command>*       
        Run an arbitrary command on a running instance.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --all
          
		Run the command on all instances.
		Cannot be used together with --instance.
	    
        --application
          
		Name of the application to operate on.
	    
        --banner
          
		Show the leading and trailing banner to separate
		instance data. Applies only when --all is used.
		Defaults to on.
	    
        --dry
          
	    Print the low-level ssh command to stdout
	    instead of executing it.
	
        --dry-run
          Alias of --dry.
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --instance
          
		The instance to access with the command.
		Defaults to 0.
		Cannot be used together with --all.
	    
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-banner
          Complementary alias of --banner.
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -a
          Alias of --application.
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato scale:

      stackato scale  *<application>*       
        Update the number of instances, memory and/or disk reservation for a deployed application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --disk
          
		The new disk reservation to use.
	    
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --instances
          
		Absolute number of instances to scale to, or
		relative change.
	    
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --mem
          
		The new memory reservation to use.
	    
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --timeout
          
	    The time the client waits for an application to
	    start before giving up and returning, in seconds.
	    Note that this is measured from the last entry
	    seen in the log stream. While there is activity
	    in the log the timeout is reset.

	    The default is 2 minutes.

	    Use the suffixes 'm', 'h', and 'd' for the convenient
	    specification of minutes, hours, and days. The optional
	    suffix 's' stands for seconds.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -d
          Alias of --disk.
        -i
          Alias of --instances.
        -m
          Alias of --mem.
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato scp:

      stackato scp  *<paths>*       
        Copy source files and directories to the destination.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --application
          
		Name of the application to operate on.
	    
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --instance
          
		The instance to access with the command.
		Defaults to 0.
	    
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -a
          Alias of --application.
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato set-env:

      stackato set-env  *<application>*  *<varname>*  *<value>*       
        Add the specified environment variable to the named application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --timeout
          
	    The time the client waits for an application to
	    start before giving up and returning, in seconds.
	    Note that this is measured from the last entry
	    seen in the log stream. While there is activity
	    in the log the timeout is reset.

	    The default is 2 minutes.

	    Use the suffixes 'm', 'h', and 'd' for the convenient
	    specification of minutes, hours, and days. The optional
	    suffix 's' stands for seconds.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato ssh:

      stackato ssh  *<command>*       
        SSH to a running instance (or target), or run an arbitrary command.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --all
          
		Run the command on all instances.
		Cannot be used together with --instance.
	    
        --application
          
		Name of the application to operate on, or
		"api" to talk to the cloud controller node.
	    
        --banner
          
		Show the leading and trailing banner to separate
		instance data. Applies only when --all is used.
		Defaults to on.
	    
        --dry
          
	    Print the low-level ssh command to stdout
	    instead of executing it.
	
        --dry-run
          Alias of --dry.
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --instance
          
		The instance to access with the command.
		Defaults to 0.
		Cannot be used together with --all.
	    
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-banner
          Complementary alias of --banner.
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -a
          Alias of --application.
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato start:

      stackato start  *<application>*       
        Start a deployed application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --timeout
          
	    The time the client waits for an application to
	    start before giving up and returning, in seconds.
	    Note that this is measured from the last entry
	    seen in the log stream. While there is activity
	    in the log the timeout is reset.

	    The default is 2 minutes.

	    Use the suffixes 'm', 'h', and 'd' for the convenient
	    specification of minutes, hours, and days. The optional
	    suffix 's' stands for seconds.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato stop:

      stackato stop  *<application>*       
        Stop a deployed application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato unmap:

      stackato unmap  *<application>*  *<url>*       
        Unregister the application from a URL.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato unset-env:

      stackato unset-env  *<application>*  *<varname>*       
        Remove the specified environment variable from the named application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --timeout
          
	    The time the client waits for an application to
	    start before giving up and returning, in seconds.
	    Note that this is measured from the last entry
	    seen in the log stream. While there is activity
	    in the log the timeout is reset.

	    The default is 2 minutes.

	    Use the suffixes 'm', 'h', and 'd' for the convenient
	    specification of minutes, hours, and days. The optional
	    suffix 's' stands for seconds.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


  
Services
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-stackato service-plans:
  
  stackato service-plans 
    List all available plans of the supported services. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato services:
  
  stackato services 
    List the supported and provisioned services of the target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --group
      
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
    --space
      
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
    --space-guid
      
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.
    
.. _command-stackato service:
  
  stackato service  *<name>* 
    Show the information about the named service.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --group
      
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
    --space
      
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
    --space-guid
      
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.

      </div></div>

    
.. _command-Services-Authentication Tokens:
    
  **Authentication Tokens**
      
.. _command-stackato create-service-auth-token:

      stackato create-service-auth-token  *<label>*  *<provider>*       
        Create a new service authentication token. This is a Stackato 3 specific command.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --auth-token
          
		    Value of the new token.
		
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato delete-service-auth-token:

      stackato delete-service-auth-token  *<label>*       
        Delete the specified service authentication token. This is a Stackato 3 specific command.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato service-auth-tokens:

      stackato service-auth-tokens       
        Show all service authentication tokens knowns to the target. This is a Stackato 3 specific command.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato update-service-auth-token:

      stackato update-service-auth-token  *<label>*       
        Update the specified service authentication token. This is a Stackato 3 specific command.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --auth-token
          
		    New value of the specified token.
		
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


    
.. _command-Services-Brokers:
    
  **Brokers**
      
.. _command-stackato add-service-broker:

      stackato add-service-broker  *<name>*       
        Make the named service broker known. This is a Stackato 3 specific command.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --broker-token
          
		    Value of the broker's token.
		
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --url
          
		    Location of the broker.
		
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato remove-service-broker:

      stackato remove-service-broker  *<name>*       
        Remove the named service broker from the target. This is a Stackato 3 specific command.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato service-brokers:

      stackato service-brokers       
        Show the list of known service brokers. This is a Stackato 3 specific command.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato update-service-broker:

      stackato update-service-broker  *<name>*  *<newname>*       
        Update the target's knowledge of the named service broker. This is a Stackato 3 specific command.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --broker-token
          
		    New value of the broker's token.
		
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --url
          
		    New location of the broker.
		
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


    
.. _command-Services-Management:
    
  **Management**
      
.. _command-stackato bind-service:

      stackato bind-service  *<service>*  *<application>*       
        Bind the named service to the specified application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --timeout
          
	    The time the client waits for an application to
	    start before giving up and returning, in seconds.
	    Note that this is measured from the last entry
	    seen in the log stream. While there is activity
	    in the log the timeout is reset.

	    The default is 2 minutes.

	    Use the suffixes 'm', 'h', and 'd' for the convenient
	    specification of minutes, hours, and days. The optional
	    suffix 's' stands for seconds.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato clone-services:

      stackato clone-services  *<source>*  *<application>*       
        Copy the service bindings of the source application to the destination application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --timeout
          
	    The time the client waits for an application to
	    start before giving up and returning, in seconds.
	    Note that this is measured from the last entry
	    seen in the log stream. While there is activity
	    in the log the timeout is reset.

	    The default is 2 minutes.

	    Use the suffixes 'm', 'h', and 'd' for the convenient
	    specification of minutes, hours, and days. The optional
	    suffix 's' stands for seconds.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato create-service:

      stackato create-service  *<vendor>*  *<name>*  *<application>*       
        Create a new provisioned service, and optionally bind it to an application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --credentials
          
		The credentials to use.
		Each use of the option declares a single element,
		using the form "key: value" for the argument.
		This is a Stackato 3 specific option.
		This is restricted to user-provided services.
	    
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --plan
          
		The service plan to use.
		This is a Stackato 3 specific option.
	    
        --provider
          
		The service provider. Use this to disambiguate
		between multiple providers of the same vendor/type.
		This is a Stackato 3 specific option.
	    
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --timeout
          
	    The time the client waits for an application to
	    start before giving up and returning, in seconds.
	    Note that this is measured from the last entry
	    seen in the log stream. While there is activity
	    in the log the timeout is reset.

	    The default is 2 minutes.

	    Use the suffixes 'm', 'h', and 'd' for the convenient
	    specification of minutes, hours, and days. The optional
	    suffix 's' stands for seconds.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --version
          
		The service version. Use this to disambiguate
		between multiple versions of the same vendor/type.
		This is a Stackato 3 specific option.
	    
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato delete-service:

      stackato delete-service  *<service>*       
        Delete the named provisioned service.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --all
          
		Delete all services.
		Cannot be used together with named service instances.
	    
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --unbind
          
		Unbind service from applications before deleting.
		By default bound services are skipped and not deleted.
		This is a Stackato 3 specific option.
	    
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato rename-service:

      stackato rename-service  *<service>*  *<name>*       
        Rename the specified service instance. This is a Stackato 3 specific command.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato tunnel:

      stackato tunnel  *<service>*  *<tunnelclient>*       
        Create a local tunnel to a service, optionally start a local client as well.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --allow-http
          
	    Required to prevent the client from rejecting http urls.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --port
          
		Port used for the tunnel.
	    
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --url
          
		Url the tunnel helper application is mapped to and
		listens on. Relevant if and only if the helper has
		to be pushed,i.e. on first use of the tunnel command.
	    
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato unbind-service:

      stackato unbind-service  *<service>*  *<application>*       
        Disconnect the named service from the specified application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --group
          
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-tail
          Complementary alias of --tail.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --timeout
          
	    The time the client waits for an application to
	    start before giving up and returning, in seconds.
	    Note that this is measured from the last entry
	    seen in the log stream. While there is activity
	    in the log the timeout is reset.

	    The default is 2 minutes.

	    Use the suffixes 'm', 'h', and 'd' for the convenient
	    specification of minutes, hours, and days. The optional
	    suffix 's' stands for seconds.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


  
Organizations
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-stackato create-org:
  
  stackato create-org  *<name>* 
    Create a new organization. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --activate
      
		Switch the current organization to the newly created one.
		Done by default.
	    
    --add-self
      
		Add yourself to the new organization, as developer.
		Done by default.
	    
    --no-activate
      Complementary alias of --activate.
    --no-add-self
      Complementary alias of --add-self.
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --quota
      
		The named quota of the new organization.
		Default is the target's choice.
	    
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato delete-org:
  
  stackato delete-org  *<name>* 
    Delete the named organization. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --recursive
      
	    Remove all sub-ordinate parts, and relations.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -r
      Alias of --recursive.
    -t
      Alias of --trace.
    
.. _command-stackato link-user-org:
  
  stackato link-user-org  *<user>*  *<org>* 
    Add the specified user to the named organization, in various roles. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --auditor
       Affect the auditor role 
    --billing
       Affect the billing manager role 
    --manager
       Affect the manager role 
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato orgs:
  
  stackato orgs 
    List the available organizations. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --full
      
		Show more details.
	    
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato org:
  
  stackato org  *<name>* 
    Show the named organization's information. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --full
      
		Show more details.
	    
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato quota-org:
  
  stackato quota-org  *<name>*  *<quota>* 
    Set the quotas for the current or named organization. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato rename-org:
  
  stackato rename-org  *<name>*  *<newname>* 
    Rename the named organization. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato switch-org:
  
  stackato switch-org  *<name>* 
    Switch the current organization to the named organization. This invalidates the current space. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato unlink-user-org:
  
  stackato unlink-user-org  *<user>*  *<org>* 
    Remove the specified user from the named organization, in various roles. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --auditor
       Affect the auditor role 
    --billing
       Affect the billing manager role 
    --manager
       Affect the manager role 
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.

      </div></div>

  
Spaces
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-stackato create-space:
  
  stackato create-space  *<name>* 
    Create a new space. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --activate
      
		Switch the current space to the newly created one.
		Done by default.
	    
    --auditor
      
		Add yourself to the new space, as auditor.
		By request.
	    
    --developer
      
		Add yourself to the new space, as developer.
		Done by default.
	    
    --manager
      
		Add yourself to the new space, as manager.
		Done by default.
	    
    --no-activate
      Complementary alias of --activate.
    --no-auditor
      Complementary alias of --auditor.
    --no-developer
      Complementary alias of --developer.
    --no-manager
      Complementary alias of --manager.
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.
    
.. _command-stackato delete-space:
  
  stackato delete-space  *<name>* 
    Delete the named space. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --recursive
      
	    Remove all sub-ordinate parts, and relations.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -r
      Alias of --recursive.
    -t
      Alias of --trace.
    
.. _command-stackato link-user-space:
  
  stackato link-user-space  *<user>*  *<space>* 
    Add the specified user to the named space, in various roles. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --auditor
       Affect the auditor role 
    --developer
       Affect the developer role 
    --manager
       Affect the manager role 
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.
    
.. _command-stackato rename-space:
  
  stackato rename-space  *<name>*  *<newname>* 
    Rename the named space. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.
    
.. _command-stackato spaces:
  
  stackato spaces 
    List the available spaces in the specified organization. See --organization for details This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --full
      
		Show more details.
	    
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.
    
.. _command-stackato space:
  
  stackato space  *<name>* 
    Show the named space's information. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --full
      
		Show more details.
	    
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.
    
.. _command-stackato switch-space:
  
  stackato switch-space  *<name>* 
    Switch from the current space to the named space. This may switch the organization as well. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.
    
.. _command-stackato unlink-user-space:
  
  stackato unlink-user-space  *<user>*  *<space>* 
    Remove the specified user from the named space, in various roles. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --auditor
       Affect the auditor role 
    --developer
       Affect the developer role 
    --manager
       Affect the manager role 
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.

      </div></div>

  
Routes
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-stackato delete-route:
  
  stackato delete-route  *<name>* 
    Delete the named route. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --space
      
	    The name of the space to use as context.

	    Defaults to the current space.

	    A current space is automatically set if there is none,
	    either by taking the one space the user has, or
	    asking the user to choose among the possibilities.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.
    
.. _command-stackato routes:
  
  stackato routes 
    List all available routes. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.

      </div></div>

  
Domains
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-stackato domains:
  
  stackato domains 
    List the available domains in the specified space, or all. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --all
      
		Query information about all domains.
		Cannot be used together with a space.
	    
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --space
      
		The name of the space to use as context.

		Defaults to the current space.

		A current space is automatically set if there is none,
		either by taking the one space the user has, or
		asking the user to choose among the possibilities.

		Cannot be used together with --all.
	    
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.
    
.. _command-stackato map-domain:
  
  stackato map-domain  *<name>* 
    Add the named domain to an organization or space. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --space
      
	    The name of the space to use as context.

	    Defaults to the current space.

	    A current space is automatically set if there is none,
	    either by taking the one space the user has, or
	    asking the user to choose among the possibilities.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.
    
.. _command-stackato unmap-domain:
  
  stackato unmap-domain  *<name>* 
    Remove the named domain from an organization or space. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --space
      
	    The name of the space to use as context.

	    Defaults to the current space.

	    A current space is automatically set if there is none,
	    either by taking the one space the user has, or
	    asking the user to choose among the possibilities.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.

      </div></div>

  
Administration
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-stackato admin grant:
  
  stackato admin grant  *<email>* 
    Grant the named user administrator privileges for the current or specified target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato admin list:
  
  stackato admin list 
    Show a list of the administrators for the current or specified target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato admin patch:
  
  stackato admin patch  *<patch>* 
    Apply a patch to the current or specified target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --dry
      
	    Print the low-level ssh command to stdout
	    instead of executing it.
	
    --dry-run
      Alias of --dry.
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato admin report:
  
  stackato admin report  *<destination>* 
    Retrieve a report containing the logs of the current or specified target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato admin revoke:
  
  stackato admin revoke  *<email>* 
    Revoke administrator privileges for the named user at the current or specified target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato frameworks:
  
  stackato frameworks 
    List the supported frameworks of the target. This is a Stackato 2 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato groups add-user:
  
  stackato groups add-user  *<group>*  *<user>* 
    Add the named user to the specified group. This is a Stackato 2 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato groups create:
  
  stackato groups create  *<name>* 
    Create a new group with the specified name. This is a Stackato 2 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato groups delete-user:
  
  stackato groups delete-user  *<group>*  *<user>* 
    Remove the named user from the specified group. This is a Stackato 2 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato groups delete:
  
  stackato groups delete  *<name>* 
    Delete the named group. This is a Stackato 2 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato groups limits:
  
  stackato groups limits  *<group>* 
    Show and/or modify the limits applying to applications in the named group. This is a Stackato 2 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --apps
      
	    Limit for the number of applications in the group.
	
    --appuris
      
	    Limit for the number of mapped uris per application.
	
    --drains
      
	    Limit for the number of drains in the group.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --mem
      
	    Amount of memory applications can use.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-sudo
      Complementary alias of --sudo.
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --services
      
	    Limit for the number of services in the group.
	
    --sudo
      
	    Applications can use sudo (or not).
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato groups show:
  
  stackato groups show 
    Show the list of groups known to the target. This is a Stackato 2 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato groups users:
  
  stackato groups users  *<group>* 
    Show the list of users in the named group. This is a Stackato 2 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato group:
  
  stackato group  *<name>* 
    Report the current group, or (un)set it. This is a Stackato 2 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --reset
      
	    Reset the current group to nothing.
	    Cannot be used together with name.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato info:
  
  stackato info 
    Show the basic system and account information.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --group
      
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
    --space
      
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
    --space-guid
      
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.
    
.. _command-stackato limits:
  
  stackato limits  *<group>* 
    Show and/or modify the limits applying to applications in the named group. This is a Stackato 2 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --apps
      
	    Limit for the number of applications in the group.
	
    --appuris
      
	    Limit for the number of mapped uris per application.
	
    --drains
      
	    Limit for the number of drains in the group.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --mem
      
	    Amount of memory applications can use.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-sudo
      Complementary alias of --sudo.
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --services
      
	    Limit for the number of services in the group.
	
    --sudo
      
	    Applications can use sudo (or not).
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato quota configure:
  
  stackato quota configure  *<name>* 
    Reconfigure the named quota definition. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --allow-sudo
      
		Applications can use sudo in their container.
	    
    --mem
      
		Amount of memory applications can use.
	    
    --no-allow-sudo
      Complementary alias of --allow-sudo.
    --no-paid-services-allowed
      Complementary alias of --paid-services-allowed.
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --no-trial-db-allowed
      Complementary alias of --trial-db-allowed.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --paid-services-allowed
      
		Applications can use non-free services.
	    
    --services
      
		Limit for the number of services in the quota.
	    
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    --trial-db-allowed
      
		Applications can use trial databases.
	    
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato quota create:
  
  stackato quota create  *<name>* 
    Create a new quota definition. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --allow-sudo
      
		Applications can use sudo in their container.
	    
    --mem
      
		Amount of memory applications can use.
	    
    --no-allow-sudo
      Complementary alias of --allow-sudo.
    --no-paid-services-allowed
      Complementary alias of --paid-services-allowed.
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --no-trial-db-allowed
      Complementary alias of --trial-db-allowed.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --paid-services-allowed
      
		Applications can use non-free services.
	    
    --services
      
		Limit for the number of services in the quota.
	    
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    --trial-db-allowed
      
		Applications can use trial databases.
	    
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato quota delete:
  
  stackato quota delete  *<name>* 
    Delete the named quota definition. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato quota list:
  
  stackato quota list 
    List the available quota definitions. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato quota rename:
  
  stackato quota rename  *<name>*  *<newname>* 
    Rename the named quota definition. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato quota show:
  
  stackato quota show  *<name>* 
    Show the details of the named quota definition. If not specified it will be asked for interactively (menu). This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato quotas:
  
  stackato quotas 
    List the available quota definitions. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato runtimes:
  
  stackato runtimes 
    List the supported runtimes of the target. This is a Stackato 2 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato stacks:
  
  stackato stacks 
    List the supported stacks of the target. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato targets:
  
  stackato targets 
    List the available targets, and their authorization tokens, if any.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    
.. _command-stackato tokens:
  
  stackato tokens 
    List the available targets, and their authorization tokens, if any.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    
.. _command-stackato usage:
  
  stackato usage  *<userOrGroup>* 
    Show the current memory allocation and usage of the active or specified user/group (Stackato 2), or the specified or current space (Stackato 3).

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --all
      
		Query information about everything.
		Cannot be used together with userOrGroup.
	    
    --group
      
	    The once-off group to use for the current operation.
	    This is a Stackato 2 option.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --organization
      
	    The once-off organization to use for the current operation.
	    This is a Stackato 3 option.
	
    --space
      
	    The once-off space to use for the current operation, specified
	    by name. This is a Stackato 3 option.
	    Cannot be used together with --space-guid.
	
    --space-guid
      
	    The once-off space to use for the current operation, specified
	    by guid. This is a Stackato 3 option.
	    Cannot be used together with --space.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    -t
      Alias of --trace.
    
.. _command-stackato user-info:
  
  stackato user-info  *<name>* 
    Shows the information of a user in the current or specified target. Defaults to the current user. Naming a specific user requires a Stackato 3 target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato user:
  
  stackato user 
    Show the name of the current user in the current or specified target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato version:
  
  stackato version 
    Print the version number of the client.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    -n
      Alias of --no-prompt.

      </div></div>

    
.. _command-Administration-User Management:
    
  **User Management**
      
.. _command-stackato add-user:

      stackato add-user  *<name>*       
        Register a new user in the current or specified target. This operation requires administrator privileges, except if "allow_registration" is set server-side.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --admin
          
		Give the newly created user administrator privileges.
	    
        --apps
          
	    Limit for the number of applications in the group.
	
        --appuris
          
	    Limit for the number of mapped uris per application.
	
        --drains
          
	    Limit for the number of drains in the group.
	
        --email
          
		The email of the user to create.
		This is a Stackato 3 specific option.
	    
        --group
          
		The group to put the new user into.
		This is a Stackato 2 specific option.
	    
        --mem
          
	    Amount of memory applications can use.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-sudo
          Complementary alias of --sudo.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
		The organization to place the new user into.
		Defaults to the current organization.
		This is a Stackato 3 specific option.
	    
        --passwd
          Alias of --password.
        --password
          
		The password to use.
	    
        --services
          
	    Limit for the number of services in the group.
	
        --sudo
          
	    Applications can use sudo (or not).
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato delete-user:

      stackato delete-user  *<email>*       
        Delete the named user, and the user's applications and services from the current or specified target. This operation requires administrator privileges.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -t
          Alias of --trace.


.. _command-stackato login-fields:

      stackato login-fields       
        Show the names of the credential fields needed for a login. This is a Stackato 3 specific command.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --json
          
	    Print raw json as output, not human-formatted data.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -t
          Alias of --trace.


.. _command-stackato passwd:

      stackato passwd       
        Change the password of the current user in the current or specified target.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --passwd
          Alias of --password.
        --password
          
		The new password. If not present it will be interactively
		asked for.
	    
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -t
          Alias of --trace.


.. _command-stackato register:

      stackato register  *<name>*       
        Register a new user in the current or specified target. This operation requires administrator privileges, except if "allow_registration" is set server-side.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --admin
          
		Give the newly created user administrator privileges.
	    
        --apps
          
	    Limit for the number of applications in the group.
	
        --appuris
          
	    Limit for the number of mapped uris per application.
	
        --drains
          
	    Limit for the number of drains in the group.
	
        --email
          
		The email of the user to create.
		This is a Stackato 3 specific option.
	    
        --group
          
		The group to put the new user into.
		This is a Stackato 2 specific option.
	    
        --mem
          
	    Amount of memory applications can use.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-sudo
          Complementary alias of --sudo.
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --organization
          
		The organization to place the new user into.
		Defaults to the current organization.
		This is a Stackato 3 specific option.
	    
        --passwd
          Alias of --password.
        --password
          
		The password to use.
	    
        --services
          
	    Limit for the number of services in the group.
	
        --sudo
          
	    Applications can use sudo (or not).
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -o
          Alias of --organization.
        -t
          Alias of --trace.


.. _command-stackato token:

      stackato token       
        Interactively set authentication token.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --no-prompt
          
	    Disable interactive queries.
	
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.


.. _command-stackato unregister:

      stackato unregister  *<email>*       
        Delete the named user, and the user's applications and services from the current or specified target. This operation requires administrator privileges.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -t
          Alias of --trace.


.. _command-stackato users:

      stackato users       
        Show the list of users known to the current or specified target.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --json
          
	    Print raw json as output, not human-formatted data.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --non-interactive
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -n
          Alias of --no-prompt.
        -t
          Alias of --trace.


  
Convenience
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-stackato aliases:
  
  stackato aliases 
    List the known aliases (shortcuts).

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    -n
      Alias of --no-prompt.
    
.. _command-stackato alias:
  
  stackato alias  *<name>*  *<command>* 
    Create a shortcut for a command (prefix).

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    -n
      Alias of --no-prompt.
    
.. _command-stackato unalias:
  
  stackato unalias  *<name>* 
    Remove a shortcut by name.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    -n
      Alias of --no-prompt.

      </div></div>

  
Miscellaneous
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-stackato admin exit:
  
  stackato admin exit 
    Exit the shell. No-op if not in a shell.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    -n
      Alias of --no-prompt.
    
.. _command-stackato admin help:
  
  stackato admin help  *<cmdname>* 
    Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --by-category
      
		Activate by-category form of the help.
	    
    --full
      
		Activate full form of the help.
	    
    --json
      
		Activate json form of the help.
	    
    --list
      
		Activate list form of the help.
	    
    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --short
      
		Activate short form of the help.
	    
    --width
      
	    The line width to format the help for.
	    Defaults to the terminal width, or 80 when
	    no terminal is available.
	
    -n
      Alias of --no-prompt.
    -w
      Alias of --width.
    
.. _command-stackato curl:
  
  stackato curl  *<operation>*  *<path>*  *<header>* 
    Run a raw rest request against the chosen target

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    
.. _command-stackato debug-packages:
  
  stackato debug-packages 
    Show the packages used the client, and their versions.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    -n
      Alias of --no-prompt.
    
.. _command-stackato drain exit:
  
  stackato drain exit 
    Exit the shell. No-op if not in a shell.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    -n
      Alias of --no-prompt.
    
.. _command-stackato drain help:
  
  stackato drain help  *<cmdname>* 
    Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --by-category
      
		Activate by-category form of the help.
	    
    --full
      
		Activate full form of the help.
	    
    --json
      
		Activate json form of the help.
	    
    --list
      
		Activate list form of the help.
	    
    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --short
      
		Activate short form of the help.
	    
    --width
      
	    The line width to format the help for.
	    Defaults to the terminal width, or 80 when
	    no terminal is available.
	
    -n
      Alias of --no-prompt.
    -w
      Alias of --width.
    
.. _command-stackato exit:
  
  stackato exit 
    Exit the shell. No-op if not in a shell.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    -n
      Alias of --no-prompt.
    
.. _command-stackato groups exit:
  
  stackato groups exit 
    Exit the shell. No-op if not in a shell.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    -n
      Alias of --no-prompt.
    
.. _command-stackato groups help:
  
  stackato groups help  *<cmdname>* 
    Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --by-category
      
		Activate by-category form of the help.
	    
    --full
      
		Activate full form of the help.
	    
    --json
      
		Activate json form of the help.
	    
    --list
      
		Activate list form of the help.
	    
    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --short
      
		Activate short form of the help.
	    
    --width
      
	    The line width to format the help for.
	    Defaults to the terminal width, or 80 when
	    no terminal is available.
	
    -n
      Alias of --no-prompt.
    -w
      Alias of --width.
    
.. _command-stackato guid:
  
  stackato guid  *<type>*  *<name>* 
    Map the specified name into a uuid, given the type. This is a Stackato 3 specific command.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    -n
      Alias of --no-prompt.
    
.. _command-stackato help:
  
  stackato help  *<cmdname>* 
    Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --by-category
      
		Activate by-category form of the help.
	    
    --full
      
		Activate full form of the help.
	    
    --json
      
		Activate json form of the help.
	    
    --list
      
		Activate list form of the help.
	    
    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --short
      
		Activate short form of the help.
	    
    --width
      
	    The line width to format the help for.
	    Defaults to the terminal width, or 80 when
	    no terminal is available.
	
    -n
      Alias of --no-prompt.
    -w
      Alias of --width.
    
.. _command-stackato named-entities:
  
  stackato named-entities 
    List the entity types usable for 'guid'. I.e. the types of the named entities known to the client.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --json
      
	    Print raw json as output, not human-formatted data.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    -n
      Alias of --no-prompt.
    
.. _command-stackato quota exit:
  
  stackato quota exit 
    Exit the shell. No-op if not in a shell.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    -n
      Alias of --no-prompt.
    
.. _command-stackato quota help:
  
  stackato quota help  *<cmdname>* 
    Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --by-category
      
		Activate by-category form of the help.
	    
    --full
      
		Activate full form of the help.
	    
    --json
      
		Activate json form of the help.
	    
    --list
      
		Activate list form of the help.
	    
    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --short
      
		Activate short form of the help.
	    
    --width
      
	    The line width to format the help for.
	    Defaults to the terminal width, or 80 when
	    no terminal is available.
	
    -n
      Alias of --no-prompt.
    -w
      Alias of --width.
    
.. _command-stackato trace:
  
  stackato trace 
    Print the saved REST trace for the last client command to stdout.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    --non-interactive
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    -n
      Alias of --no-prompt.

      </div></div>


.. raw:: html

  <script type="text/javascript">
    function showSpoiler(obj)
    {
      var inner = obj.parentNode.getElementsByTagName("div")[0];
      if (inner.style.display == "none") {
        inner.style.display = "";
        obj.innerHTML = '- options'
      }
      else {
        inner.style.display = "none";
        obj.innerHTML = '+ options'
      }

	return false;

    }
  </script>


