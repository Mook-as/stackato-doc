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

    
.. _command-login:
  
  login
    Log in to the current or specified target with the named user.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --passwd
      Alias of --password.
    --ignore-missing
      
		Disable errors generated for missing organization and/or space.
	    
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --space
      
		The space (in the organization) to use.
		This is a stackato/CFv2 specific option.
		If not specified the user is asked interactively
		to choose among the possible spaces in
		either the chosen organization, or all
		organizations it belongs to.
	    
    --non-interactive
      Alias of --no-prompt.
    --organization
      
		The organization to use.
		This is a stackato/CFv2 specific option.
		If not specified the user is asked interactively
		to choose an organization.
	    
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    --password
      
		The password to use.
	    
    --group
      
		The group to use for the login.
		This is a stackato/CFv1 specific option.
	    
    
.. _command-logout:
  
  logout
    Log out of the current, specified, or all targets.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    --all
      
		When present, log out of all targets we know.
		Cannot be used together with a target.
	    
    
.. _command-target:
  
  target
    Set the target API endpoint for the client, or report the current target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    -n
      Alias of --no-prompt.
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --verbose
       More verbose operation. 
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --space
      
	    The space to set as current for this target.
	    This is a stackato/CFv2 specific option.
	
    --non-interactive
      Alias of --no-prompt.
    --organization
      
	    The organization to set as current for this target.
	    This is a stackato/CFv2 specific option.
	
    -s
      Alias of --space.
    --no-prompt
      
	    Disable interactive queries.
	
    --allow-http
      
	    Required to prevent the client from rejecting http urls.
	

    ..raw:: html

      </div></div>

  
Applications
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-app:
  
  app
    Show the information of the specified application.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --path
      
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
    -t
      Alias of --trace.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    --manifest
      
	    Path of the manifest file to use.
	    If not specified a search is done.
	
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --space
      
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --space-guid
      
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
    --organization
      
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    --group
      
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
    
.. _command-apps:
  
  apps
    List the applications deployed to the target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --space
      
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --space-guid
      
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
    --organization
      
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    --all
      
		Show all applications instead of just those
		associated with the current space.
	    
    --group
      
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
    
.. _command-list:
  
  list
    List the applications deployed to the target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --space
      
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --space-guid
      
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
    --organization
      
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    --all
      
		Show all applications instead of just those
		associated with the current space.
	    
    --group
      
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

    ..raw:: html

      </div></div>

    
.. _command-Applications-Information:
    
  **Information**
      
.. _command-crashes:

      crashes
        List recent application crashes.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --no-tail
          Complementary alias of --tail.
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-crashlogs:

      crashlogs
        Display log information for the application. An alias of 'logs'.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --filename
          
		Filter the log stream by origin file (glob pattern).
		Target version 2.4+ only.
	    
        --no-tail
          Complementary alias of --tail.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --instance
          
		The id of the instance to filter the log stream for,
		or (before 2.3), to retrieve the logs of.
	    
        --no-trace
          Complementary alias of --trace.
        -n
          Alias of --no-prompt.
        --num
          
		Show the last num entries of the log stream.
		Target version 2.4+ only.
	    
        --text
          
		Filter the log stream by log entry text (glob pattern).
		Target version 2.4+ only.
	    
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --prefix
          
		Put instance information before each line of a
		shown log file. Before 2.3 only.
	    
        --follow
          
		Tail -f the log stream. Target version 2.4+ only.
	    
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --all
          
		Retrieve the logs from all instances. Before 2.3 only.
	    
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --prefix-logs
          Alias of --prefix.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --prefixlogs
          Alias of --prefix.
        --source
          
		Filter the log stream by origin stage (glob pattern).
		Target version 2.4+ only.
	    
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --json
          
		Print the raw json log stream, not human-formatted data.
	    
        --non-interactive
          Alias of --no-prompt.

          ..raw:: html

            </div></div>

.. _command-disk:

      disk
        Show the disk reservation for a deployed application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-drains:

      drains
        Show the list of drains attached to the application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --no-tail
          Complementary alias of --tail.
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-env:

      env
        List the application's environment variables.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --no-tail
          Complementary alias of --tail.
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-events:

      events
        Show the application's events as recorded so far.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --no-tail
          Complementary alias of --tail.
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-file:

      file
        Display directory listing or file.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        -n
          Alias of --no-prompt.
        --no-tail
          Complementary alias of --tail.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --instance
          
		When present the instance to query.
		Cannot be used together with --all.
		Defaults to 0 (except when --all is present).
	    
        --no-trace
          Complementary alias of --trace.
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --prefix
          
		Put instance information before each line of a
		shown file or directory listing. Effective only
		for --all.
	    
        -t
          Alias of --trace.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --all
          
		When present, access all instances for the file or directory.
		Cannot be used together with --instance.
	    
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --prefix-logs
          Alias of --prefix.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --prefixlogs
          Alias of --prefix.
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --non-interactive
          Alias of --no-prompt.

          ..raw:: html

            </div></div>

.. _command-files:

      files
        Display directory listing or file.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        -n
          Alias of --no-prompt.
        --no-tail
          Complementary alias of --tail.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --instance
          
		When present the instance to query.
		Cannot be used together with --all.
		Defaults to 0 (except when --all is present).
	    
        --no-trace
          Complementary alias of --trace.
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --prefix
          
		Put instance information before each line of a
		shown file or directory listing. Effective only
		for --all.
	    
        -t
          Alias of --trace.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --all
          
		When present, access all instances for the file or directory.
		Cannot be used together with --instance.
	    
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --prefix-logs
          Alias of --prefix.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --prefixlogs
          Alias of --prefix.
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --non-interactive
          Alias of --no-prompt.

          ..raw:: html

            </div></div>

.. _command-health:

      health
        Report the health of the specified application(s).

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        -n
          Alias of --no-prompt.
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --noprompt
          Alias of --no-prompt.
        --non-interactive
          Alias of --no-prompt.
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --all
          
		Report on all applications in the current space.
		Cannot be used together with application names.
	    
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	

          ..raw:: html

            </div></div>

.. _command-instances:

      instances
        List application instances for a deployed application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --no-tail
          Complementary alias of --tail.
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-logs:

      logs
        Display log information for the application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --filename
          
		Filter the log stream by origin file (glob pattern).
		Target version 2.4+ only.
	    
        --no-tail
          Complementary alias of --tail.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --instance
          
		The id of the instance to filter the log stream for,
		or (before 2.3), to retrieve the logs of.
	    
        --no-trace
          Complementary alias of --trace.
        -n
          Alias of --no-prompt.
        --num
          
		Show the last num entries of the log stream.
		Target version 2.4+ only.
	    
        --text
          
		Filter the log stream by log entry text (glob pattern).
		Target version 2.4+ only.
	    
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --prefix
          
		Put instance information before each line of a
		shown log file. Before 2.3 only.
	    
        --follow
          
		Tail -f the log stream. Target version 2.4+ only.
	    
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --all
          
		Retrieve the logs from all instances. Before 2.3 only.
	    
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --prefix-logs
          Alias of --prefix.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --prefixlogs
          Alias of --prefix.
        --source
          
		Filter the log stream by origin stage (glob pattern).
		Target version 2.4+ only.
	    
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --json
          
		Print the raw json log stream, not human-formatted data.
	    
        --non-interactive
          Alias of --no-prompt.

          ..raw:: html

            </div></div>

.. _command-mem:

      mem
        Show the memory reservation for a deployed application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-stats:

      stats
        Display the resource usage for a deployed application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --no-tail
          Complementary alias of --tail.
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-tail:

      tail
        Monitor file for changes and stream them.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --no-trace
          Complementary alias of --trace.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --instance
          
		When present the instance to query.
		Cannot be used together with --all.
		Defaults to 0 (except when --all is present).
	    
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-drain list:

      drain list
        Show the list of drains attached to the application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --no-tail
          Complementary alias of --tail.
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

    
.. _command-Applications-Management:
    
  **Management**
      
.. _command-create-app:

      create-app
        Create an empty application with the specified configuration.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --instances
          
		The number of application instances to create.
		Defaults to 1, if not specified by a stackato.yml.
	    
        -n
          Alias of --no-prompt.
        --env-mode
          
		Environment replacement mode. One of preserve, or replace.
		The default for create and push is "replace", and for
		update it is "preserve". Replace-mode also implies --reset.
	    
        --env
          
		Environment variable overrides for declarations in
		the stackato.yml. Ignored without environment variable
		declarations in the manifest.
	    
        --no-tail
          Complementary alias of --tail.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --no-trace
          Complementary alias of --trace.
        -d
          
		Set up debugging through an application-specific
		harbor (port) service. Target version 2.8+ only.
	    
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --command
          
		The application's start command.
		Defaults to a framework-specific value if required
		and not specified by stackato.yml.
	    
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        -t
          Alias of --trace.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --stackato-debug
          
		host:port of the Komodo debugger listener to inject
		into the application as environment variables.
	    
        --no-framework
          
		Create application without any framework.
		Cannot be used together with --framework.
	    
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --url
          
		The urls to map the application to.
		I.e. can be specified muliple times.
	    
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --runtime
          
		The name of the runtime to use.
		Default is framework specific, if not specified
		by a stackato.yml.
	    
        --reset
          
		Analogue of --env-mode, for the regular settings.
	    
        --stack
          
		The OS foundation the application will run on.
	    
        --buildpack
          
		Url of a custom buildpack.
	    
        --non-interactive
          Alias of --no-prompt.
        --framework
          
		Specify the framework to use.
		Cannot be used together with --no-framework.
		Defaults to a heuristically chosen value if
		not specified, and none for --no-framework.
	    
        --mem
          
		The application's per-instance memory allocation.
		Defaults to a framework-specific value if not
		specified by stackato.yml.
	    
        --disk
          
		The application's per-instance disk allocation.
		Defaults to a framework-specific value if not
		specified by stackato.yml.
	    

          ..raw:: html

            </div></div>

.. _command-dbshell:

      dbshell
        Invoke interactive db shell for a bound service.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --dry
          
		Print the low-level ssh command to stdout
		instead of executing it.
	    
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --dry-run
          Alias of --dry.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-delete:

      delete
        Delete the specified application(s).

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --force
          
		Force deletion.
	    
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --all
          
		Delete all applications.
		Cannot be used together with application names.
	    
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-env-add:

      env-add
        Add the specified environment variable to the named application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-env-del:

      env-del
        Remove the specified environment variable from the named application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-map:

      map
        Make the application accessible through the specified URL (a route consisting of host and domain)

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-open:

      open
        Open the application|URL|target (web console) in a browser

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-push:

      push
        Configure, create, push, map, and start a new application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --instances
          
		The number of application instances to create.
		Defaults to 1, if not specified by a stackato.yml.
	    
        -n
          Alias of --no-prompt.
        --copy-unsafe-links
          
		Links pointing outside of the application directory
		are copied into the application.
	    
        --env
          
		Environment variable overrides for declarations in
		the stackato.yml. Ignored without environment variable
		declarations in the manifest.
	    
        --no-tail
          Complementary alias of --tail.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --stackato-debug
          
		host:port of the Komodo debugger listener to inject
		into the application as environment variables.
	    
        --no-trace
          Complementary alias of --trace.
        -d
          
		Set up debugging through an application-specific
		harbor (port) service. Target version 2.8+ only.
	    
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --non-interactive
          Alias of --no-prompt.
        --no-resources
          
		Do not optimize upload by checking for existing file resources.
	    
        --as
          
		The name of the application to push/update the selected application as.
		Possible only if a single application is pushed or updated.
	    
        --noprompt
          Alias of --no-prompt.
        --force-start
          
		Push, and start the application, even when stopped.
	    
        --noresources
          Alias of --no-resources.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        -t
          Alias of --trace.
        --no-framework
          
		Create application without any framework.
		Cannot be used together with --framework.
	    
        --target
          
	    The once-off target to use for the current operation.
	
        --no-start
          
		Push, but do not start the application.
	    
        --url
          
		The urls to map the application to.
		I.e. can be specified muliple times.
	    
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --nostart
          Alias of --no-start.
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --tail
          
	    Request target to stream the log.
	
        --name
          Alias of --as.
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --runtime
          
		The name of the runtime to use.
		Default is framework specific, if not specified
		by a stackato.yml.
	    
        --reset
          
		Analogue of --env-mode, for the regular settings.
	    
        --stack
          
		The OS foundation the application will run on.
	    
        --buildpack
          
		Url of a custom buildpack.
	    
        --env-mode
          
		Environment replacement mode. One of preserve, or replace.
		The default for create and push is "replace", and for
		update it is "preserve". Replace-mode also implies --reset.
	    
        --framework
          
		Specify the framework to use.
		Cannot be used together with --no-framework.
		Defaults to a heuristically chosen value if
		not specified, and none for --no-framework.
	    
        --command
          
		The application's start command.
		Defaults to a framework-specific value if required
		and not specified by stackato.yml.
	    
        --mem
          
		The application's per-instance memory allocation.
		Defaults to a framework-specific value if not
		specified by stackato.yml.
	    
        -o
          Alias of --organization.
        --disk
          
		The application's per-instance disk allocation.
		Defaults to a framework-specific value if not
		specified by stackato.yml.
	    

          ..raw:: html

            </div></div>

.. _command-rename:

      rename
        Rename the specified application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-restart:

      restart
        Stop and restart a deployed application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-run:

      run
        Run an arbitrary command on a running instance.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --noprompt
          Alias of --no-prompt.
        --dry
          
		Print the low-level ssh command to stdout
		instead of executing it.
	    
        --no-tail
          Complementary alias of --tail.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --instance
          
		The instance to access with the command.
		Defaults to 0.
	    
        --no-trace
          Complementary alias of --trace.
        -a
          Alias of --application.
        -o
          Alias of --organization.
        -n
          Alias of --no-prompt.
        -t
          Alias of --trace.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --application
          
		Name of the application to operate on.
	    
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --non-interactive
          Alias of --no-prompt.
        --dry-run
          Alias of --dry.

          ..raw:: html

            </div></div>

.. _command-scale:

      scale
        Update the number of instances, memory and/or disk reservation for a deployed application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --instances
          
		Absolute number of instances to scale to, or
		relative change.
	    
        -n
          Alias of --no-prompt.
        --no-tail
          Complementary alias of --tail.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --no-trace
          Complementary alias of --trace.
        -d
          Alias of --disk.
        -m
          Alias of --mem.
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        -i
          Alias of --instances.
        -t
          Alias of --trace.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --non-interactive
          Alias of --no-prompt.
        --mem
          
		The new memory reservation to use.
	    
        --disk
          
		The new disk reservation to use.
	    

          ..raw:: html

            </div></div>

.. _command-scp:

      scp
        Copy source files and directories to the destination.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --noprompt
          Alias of --no-prompt.
        --no-tail
          Complementary alias of --tail.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --instance
          
		The instance to access with the command.
		Defaults to 0.
	    
        --no-trace
          Complementary alias of --trace.
        -a
          Alias of --application.
        -o
          Alias of --organization.
        -n
          Alias of --no-prompt.
        -t
          Alias of --trace.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --application
          
		Name of the application to operate on.
	    
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --non-interactive
          Alias of --no-prompt.

          ..raw:: html

            </div></div>

.. _command-set-env:

      set-env
        Add the specified environment variable to the named application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-ssh:

      ssh
        SSH to a running instance (or target), or run an arbitrary command.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --noprompt
          Alias of --no-prompt.
        --dry
          
		Print the low-level ssh command to stdout
		instead of executing it.
	    
        --no-tail
          Complementary alias of --tail.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        --instance
          
		The instance to access with the command.
		Defaults to 0.
	    
        --no-trace
          Complementary alias of --trace.
        -a
          Alias of --application.
        -o
          Alias of --organization.
        -n
          Alias of --no-prompt.
        -t
          Alias of --trace.
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --application
          
		Name of the application to operate on, or
		"api" to talk to the cloud controller node.
	    
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --tail
          
	    Request target to stream the log.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        --non-interactive
          Alias of --no-prompt.
        --dry-run
          Alias of --dry.

          ..raw:: html

            </div></div>

.. _command-start:

      start
        Start a deployed application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-stop:

      stop
        Stop a deployed application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-unmap:

      unmap
        Unregister the application from a URL.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-unset-env:

      unset-env
        Remove the specified environment variable from the named application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-drain add:

      drain add
        Attach a new named drain to the application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --json
          
		    The drain target takes raw json log entries.
		
        --no-tail
          Complementary alias of --tail.
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-drain delete:

      drain delete
        Remove the named drain from the application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

  
Services
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-service:
  
  service
    Show the information about the named service.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --space
      
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --space-guid
      
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
    --organization
      
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    --group
      
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
    
.. _command-service-plans:
  
  service-plans
    List all available plans of the supported services.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-services:
  
  services
    List the supported and provisioned services of the target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --space
      
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --space-guid
      
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
    --organization
      
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    --group
      
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

    ..raw:: html

      </div></div>

    
.. _command-Services-Authentication Tokens:
    
  **Authentication Tokens**
      
.. _command-create-service-auth-token:

      create-service-auth-token
        Create a new service authentication token.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --auth-token
          
		    Value of the new token.
		
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -t
          Alias of --trace.
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-delete-service-auth-token:

      delete-service-auth-token
        Delete the specified service authentication token.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -t
          Alias of --trace.
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-service-auth-tokens:

      service-auth-tokens
        Show all service authentication tokens knowns to the target.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -t
          Alias of --trace.
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-update-service-auth-token:

      update-service-auth-token
        Update the specified service authentication token.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --auth-token
          
		    New value of the specified token.
		
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -t
          Alias of --trace.
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --no-trace
          Complementary alias of --trace.
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

    
.. _command-Services-Brokers:
    
  **Brokers**
      
.. _command-add-service-broker:

      add-service-broker
        Make the named service broker known.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --noprompt
          Alias of --no-prompt.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -t
          Alias of --trace.
        -o
          Alias of --organization.
        --broker-token
          
		    Value of the broker's token.
		
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --url
          
		    Location of the broker.
		
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-service-brokers:

      service-brokers
        Show the list of known service brokers.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -t
          Alias of --trace.
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

    
.. _command-Services-Management:
    
  **Management**
      
.. _command-bind-service:

      bind-service
        Bind the named service to the specified application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-bind_service:

      bind_service
        Bind the named service to the specified application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-clone-services:

      clone-services
        Copy the service bindings of the source application to the destination application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -t
          Alias of --trace.
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-create-service:

      create-service
        Create a new provisioned service, and optionally bind it to an application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --provider
          
		The service provider. Use this to disambiguate
		between multiple providers of the same vendor/type.
		This is a stackato/CFv2 specific option.
	    
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --plan
          
		The service plan to use.
		This is a stackato/CFv2 specific option.
	    
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --credentials
          
		The credentials to use.
		Each use of the option declares a single element,
		using the form "key: value" for the argument.
		This is a stackato/CFv2 specific option.
		This is restricted to user-provided services.
	    
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --version
          
		The service version. Use this to disambiguate
		between multiple versions of the same vendor/type.
		This is a stackato/CFv2 specific option.
	    
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	

          ..raw:: html

            </div></div>

.. _command-create_service:

      create_service
        Create a new provisioned service, and optionally bind it to an application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --provider
          
		The service provider. Use this to disambiguate
		between multiple providers of the same vendor/type.
		This is a stackato/CFv2 specific option.
	    
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --plan
          
		The service plan to use.
		This is a stackato/CFv2 specific option.
	    
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --credentials
          
		The credentials to use.
		Each use of the option declares a single element,
		using the form "key: value" for the argument.
		This is a stackato/CFv2 specific option.
		This is restricted to user-provided services.
	    
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --version
          
		The service version. Use this to disambiguate
		between multiple versions of the same vendor/type.
		This is a stackato/CFv2 specific option.
	    
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	

          ..raw:: html

            </div></div>

.. _command-delete-service:

      delete-service
        Delete the named provisioned service.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -t
          Alias of --trace.
        --unbind
          
		Unbind service from applications before deleting.
		By default bound services are skipped and not deleted.
	    
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --all
          
		Delete all services.
		Cannot be used together with named service instances.
	    
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
        -o
          Alias of --organization.

          ..raw:: html

            </div></div>

.. _command-delete_service:

      delete_service
        Delete the named provisioned service.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -t
          Alias of --trace.
        --unbind
          
		Unbind service from applications before deleting.
		By default bound services are skipped and not deleted.
	    
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --all
          
		Delete all services.
		Cannot be used together with named service instances.
	    
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
        -o
          Alias of --organization.

          ..raw:: html

            </div></div>

.. _command-rename-service:

      rename-service
        Rename the specified service instance.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -t
          Alias of --trace.
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-rename_service:

      rename_service
        Rename the specified service instance.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -t
          Alias of --trace.
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-tunnel:

      tunnel
        Create a local tunnel to a service, optionally start a local client as well.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --port
          
		Port used for the tunnel.
	    
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -t
          Alias of --trace.
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --url
          
		Url the tunnel helper application is mapped to and
		listens on. Relevant if and only if the helper has
		to be pushed,i.e. on first use of the tunnel command.
	    
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --allow-http
          
	    Required to prevent the client from rejecting http urls.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-unbind-service:

      unbind-service
        Disconnect the named service from the specified application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

.. _command-unbind_service:

      unbind_service
        Disconnect the named service from the specified application.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --path
          
	    Path of the directory holding the application files to push.
	    Defaults to the current working directory.
	
        -t
          Alias of --trace.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --manifest
          
	    Path of the manifest file to use.
	    If not specified a search is done.
	
        -o
          Alias of --organization.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-tail
          Complementary alias of --tail.
        --non-interactive
          Alias of --no-prompt.
        --space-guid
          
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
        --organization
          
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
        --tail
          
	    Request target to stream the log.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --space
          
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
        --group
          
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	

          ..raw:: html

            </div></div>

  
Organizations
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-create-org:
  
  create-org
    Create a new organization.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --no-prompt
      
	    Disable interactive queries.
	
    -n
      Alias of --no-prompt.
    --add-self
      
		Add yourself to the new organization, as developer.
		Done by default.
	    
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --activate
      
		Switch the current organization to the newly created one.
		Done by default.
	    
    --non-interactive
      Alias of --no-prompt.
    --no-activate
      Complementary alias of --activate.
    --no-add-self
      Complementary alias of --add-self.
    --no-trace
      Complementary alias of --trace.
    
.. _command-delete-org:
  
  delete-org
    Delete the named organization.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -r
      Alias of --recursive.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --recursive
      
	    Remove all sub-ordinate parts, and relations.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-link-user-org:
  
  link-user-org
    Add the specified user to the named organization, in various roles. This is a CFv2 specific command

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    --manager
       Affect the manager role 
    -t
      Alias of --trace.
    --auditor
       Affect the auditor role 
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --billing
       Affect the billing manager role 
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --developer
       Affect the developer role 
    
.. _command-org:
  
  org
    Show the named organization's information.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    --full
      
		Show more details.
	    
    
.. _command-orgs:
  
  orgs
    List the available organizations.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    --full
      
		Show more details.
	    
    
.. _command-quota-org:
  
  quota-org
    Set the quotas for the current or named organization.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-rename-org:
  
  rename-org
    Rename the named organization.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-switch-org:
  
  switch-org
    Switch the current organization to the named organization. This invalidates the current space.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-unlink-user-org:
  
  unlink-user-org
    Remove the specified user from the named organization, in various roles. This is a CFv2 specific command

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    --manager
       Affect the manager role 
    -t
      Alias of --trace.
    --auditor
       Affect the auditor role 
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --billing
       Affect the billing manager role 
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --developer
       Affect the developer role 

    ..raw:: html

      </div></div>

  
Spaces
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-create-space:
  
  create-space
    Create a new space.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    --manager
      
		Add yourself to the new space, as manager.
		Done by default.
	    
    -t
      Alias of --trace.
    --no-developer
      Complementary alias of --developer.
    --auditor
      
		Add yourself to the new space, as auditor.
		By request.
	    
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --target
      
	    The once-off target to use for the current operation.
	
    --no-auditor
      Complementary alias of --auditor.
    --activate
      
		Switch the current space to the newly created one.
		Done by default.
	    
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --no-activate
      Complementary alias of --activate.
    --no-manager
      Complementary alias of --manager.
    --no-prompt
      
	    Disable interactive queries.
	
    --developer
      
		Add yourself to the new space, as developer.
		Done by default.
	    
    
.. _command-delete-space:
  
  delete-space
    Delete the named space.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -r
      Alias of --recursive.
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --recursive
      
	    Remove all sub-ordinate parts, and relations.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    
.. _command-link-user-space:
  
  link-user-space
    Add the specified user to the named space, in various roles. This is a CFv2 specific command

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    --manager
       Affect the manager role 
    -t
      Alias of --trace.
    --auditor
       Affect the auditor role 
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --developer
       Affect the developer role 
    
.. _command-rename-space:
  
  rename-space
    Rename the named space.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-space:
  
  space
    Show the named space's information.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    --full
      
		Show more details.
	    
    
.. _command-spaces:
  
  spaces
    List the available spaces in the specified organization. See --organization for details

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    --full
      
		Show more details.
	    
    
.. _command-switch-space:
  
  switch-space
    Switch from the current space to the named space. This may switch the organization as well.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-unlink-user-space:
  
  unlink-user-space
    Remove the specified user from the named space, in various roles. This is a CFv2 specific command

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    --manager
       Affect the manager role 
    -t
      Alias of --trace.
    --auditor
       Affect the auditor role 
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --no-trace
      Complementary alias of --trace.
    --developer
       Affect the developer role 

    ..raw:: html

      </div></div>

  
Routes
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-delete-route:
  
  delete-route
    Delete the named route.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --space
      
	    The name of the space to use as context.

	    Defaults to the current space.

	    A current space is automatically set if there is none,
	    either by taking the one space the user has, or
	    asking the user to choose among the possibilities.
	
    --non-interactive
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-routes:
  
  routes
    List all available routes.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	

    ..raw:: html

      </div></div>

  
Domains
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-domains:
  
  domains
    List the available domains in the specified space, or all.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --space
      
		The name of the space to use as context.

		Defaults to the current space.

		A current space is automatically set if there is none,
		either by taking the one space the user has, or
		asking the user to choose among the possibilities.

		Cannot be used together with --all.
	    
    --non-interactive
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    --all
      
		Query information about all domains.
		Cannot be used together with a space.
	    
    
.. _command-map-domain:
  
  map-domain
    Add the named domain to an organization or space.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --space
      
	    The name of the space to use as context.

	    Defaults to the current space.

	    A current space is automatically set if there is none,
	    either by taking the one space the user has, or
	    asking the user to choose among the possibilities.
	
    --non-interactive
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-unmap-domain:
  
  unmap-domain
    Remove the named domain from an organization or space.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --space
      
	    The name of the space to use as context.

	    Defaults to the current space.

	    A current space is automatically set if there is none,
	    either by taking the one space the user has, or
	    asking the user to choose among the possibilities.
	
    --non-interactive
      Alias of --no-prompt.
    --organization
      
	    The name of the parent organization to use as context.

	    Defaults to the current organization.

	    A current organization is automatically set if there is none,
	    either by taking the one organization the user belongs to, or
	    asking the user to choose among the possibilities.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	

    ..raw:: html

      </div></div>

  
Administration
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-frameworks:
  
  frameworks
    List the supported frameworks of the target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-group:
  
  group
    Report the current group, or (un)set it.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --reset
      
	    Reset the current group to nothing.
	    Cannot be used together with name.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-info:
  
  info
    Show the basic system and account information.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --space
      
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --space-guid
      
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
    --organization
      
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    --group
      
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
    
.. _command-limits:
  
  limits
    Show and/or modify the limits applying to applications in the named group.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --services
      
	    Limit for the number of services in the group.
	
    --noprompt
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --apps
      
	    Limit for the number of applications in the group.
	
    --non-interactive
      Alias of --no-prompt.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --no-sudo
      Complementary alias of --sudo.
    --appuris
      
	    Limit for the number of mapped uris per application.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --sudo
      
	    Applications can use sudo (or not).
	
    --mem
      
	    Amount of memory applications can use.
	
    --drains
      
	    Limit for the number of drains in the group.
	
    
.. _command-quotas:
  
  quotas
    List the available quota definitions.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-runtimes:
  
  runtimes
    List the supported runtimes of the target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-stacks:
  
  stacks
    List the supported stacks of the target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-targets:
  
  targets
    List the available targets, and their authorization tokens, if any.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --noprompt
      Alias of --no-prompt.
    -n
      Alias of --no-prompt.
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-tokens:
  
  tokens
    List the available targets, and their authorization tokens, if any.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --noprompt
      Alias of --no-prompt.
    -n
      Alias of --no-prompt.
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-usage:
  
  usage
    Show the current memory allocation and usage of the active or specified user/group (CFv1), or the specified or current space (CFv2).

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -o
      Alias of --organization.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --space
      
	    The once-off space to use for the current operation, specified
	    by name. This is a stackato CF v2 option.
	    Cannot be used together with --space-guid.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --space-guid
      
	    The once-off space to use for the current operation, specified
	    by guid. This is a stackato CF v2 option.
	    Cannot be used together with --space.
	
    --organization
      
	    The once-off organization to use for the current operation.
	    This is a stackato CF v2 option.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    --all
      
		Query information about everything.
		Cannot be used together with userOrGroup.
	    
    --group
      
	    The once-off group to use for the current operation.
	    This is a stackato V1 option.
	
    
.. _command-user:
  
  user
    Show the name of the current user in the current or specified target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-user-info:
  
  user-info
    Shows the information of a user in the current or specified target. Defaults to the current user. Naming a specific user requires a CFv2 target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-version:
  
  version
    Print the version number of the client.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    -n
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --non-interactive
      Alias of --no-prompt.
    
.. _command-admin grant:
  
  admin grant
    Grant the named user administrator privileges for the current or specified target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --noprompt
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -n
      Alias of --no-prompt.
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-admin list:
  
  admin list
    Show a list of the administrators for the current or specified target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-admin patch:
  
  admin patch
    Apply a patch to the current or specified target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-admin report:
  
  admin report
    Retrieve a report containing the logs of the current or specified target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-admin revoke:
  
  admin revoke
    Revoke administrator privileges for the named user at the current or specified target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --noprompt
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    -n
      Alias of --no-prompt.
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-groups add-user:
  
  groups add-user
    Add the named user to the specified group.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-groups create:
  
  groups create
    Create a new group with the specified name.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-groups delete-user:
  
  groups delete-user
    Remove the named user from the specified group.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-groups delete:
  
  groups delete
    Delete the named group.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-groups limits:
  
  groups limits
    Show and/or modify the limits applying to applications in the named group.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --services
      
	    Limit for the number of services in the group.
	
    --noprompt
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --apps
      
	    Limit for the number of applications in the group.
	
    --non-interactive
      Alias of --no-prompt.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --no-sudo
      Complementary alias of --sudo.
    --appuris
      
	    Limit for the number of mapped uris per application.
	
    --no-prompt
      
	    Disable interactive queries.
	
    --sudo
      
	    Applications can use sudo (or not).
	
    --mem
      
	    Amount of memory applications can use.
	
    --drains
      
	    Limit for the number of drains in the group.
	
    
.. _command-groups show:
  
  groups show
    Show the list of groups known to the target.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-groups users:
  
  groups users
    Show the list of users in the named group.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-quota configure:
  
  quota configure
    Reconfigure the named quota definition.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trial-db-allowed
      
		Applications can use trial databases.
	    
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    --paid-services-allowed
      
		Applications can use non-free services.
	    
    --services
      
		Limit for the number of services in the quota.
	    
    --noprompt
      Alias of --no-prompt.
    --no-trial-db-allowed
      Complementary alias of --trial-db-allowed.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    --mem
      
		Amount of memory applications can use.
	    
    --no-paid-services-allowed
      Complementary alias of --paid-services-allowed.
    
.. _command-quota create:
  
  quota create
    Create a new quota definition.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    --trial-db-allowed
      
		Applications can use trial databases.
	    
    -n
      Alias of --no-prompt.
    -t
      Alias of --trace.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    --paid-services-allowed
      
		Applications can use non-free services.
	    
    --services
      
		Limit for the number of services in the quota.
	    
    --noprompt
      Alias of --no-prompt.
    --no-trial-db-allowed
      Complementary alias of --trial-db-allowed.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --target
      
	    The once-off target to use for the current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    --mem
      
		Amount of memory applications can use.
	    
    --no-paid-services-allowed
      Complementary alias of --paid-services-allowed.
    
.. _command-quota delete:
  
  quota delete
    Delete the named quota definition.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-quota list:
  
  quota list
    List the available quota definitions.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-quota rename:
  
  quota rename
    Rename the named quota definition.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-quota show:
  
  quota show
    Show the details of the named quota definition. If not specified it will be asked for interactively (menu).

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	

    ..raw:: html

      </div></div>

    
.. _command-Administration-User Management:
    
  **User Management**
      
.. _command-add-user:

      add-user
        Register a new user in the current or specified target. This operation requires administrator privileges, except if "allow_registration" is set server-side.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --noprompt
          Alias of --no-prompt.
        --passwd
          Alias of --password.
        --apps
          
	    Limit for the number of applications in the group.
	
        --no-trace
          Complementary alias of --trace.
        -o
          Alias of --organization.
        -n
          Alias of --no-prompt.
        -t
          Alias of --trace.
        --services
          
	    Limit for the number of services in the group.
	
        --appuris
          
	    Limit for the number of mapped uris per application.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --organization
          
		The organization to place the new user into.
		Defaults to the current organization.
		This is a stackato/CFv2 specific option.
	    
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --admin
          
		Give the newly created user administrator privileges.
	    
        --password
          
		The password to use.
	    
        --group
          
		The group to put the new user into.
		This is a stackato/CFv1 specific option.
	    
        --sudo
          
	    Applications can use sudo (or not).
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --email
          
		The email of the user to create.
		This is a stackato/CFv2 specific option.
	    
        --non-interactive
          Alias of --no-prompt.
        --no-sudo
          Complementary alias of --sudo.
        --mem
          
	    Amount of memory applications can use.
	
        --drains
          
	    Limit for the number of drains in the group.
	

          ..raw:: html

            </div></div>

.. _command-add_user:

      add_user
        Register a new user in the current or specified target. This operation requires administrator privileges, except if "allow_registration" is set server-side.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --noprompt
          Alias of --no-prompt.
        --passwd
          Alias of --password.
        --apps
          
	    Limit for the number of applications in the group.
	
        --no-trace
          Complementary alias of --trace.
        -o
          Alias of --organization.
        -n
          Alias of --no-prompt.
        -t
          Alias of --trace.
        --services
          
	    Limit for the number of services in the group.
	
        --appuris
          
	    Limit for the number of mapped uris per application.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --organization
          
		The organization to place the new user into.
		Defaults to the current organization.
		This is a stackato/CFv2 specific option.
	    
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --admin
          
		Give the newly created user administrator privileges.
	    
        --password
          
		The password to use.
	    
        --group
          
		The group to put the new user into.
		This is a stackato/CFv1 specific option.
	    
        --sudo
          
	    Applications can use sudo (or not).
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --email
          
		The email of the user to create.
		This is a stackato/CFv2 specific option.
	    
        --non-interactive
          Alias of --no-prompt.
        --no-sudo
          Complementary alias of --sudo.
        --mem
          
	    Amount of memory applications can use.
	
        --drains
          
	    Limit for the number of drains in the group.
	

          ..raw:: html

            </div></div>

.. _command-create-user:

      create-user
        Register a new user in the current or specified target. This operation requires administrator privileges, except if "allow_registration" is set server-side.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --noprompt
          Alias of --no-prompt.
        --passwd
          Alias of --password.
        --apps
          
	    Limit for the number of applications in the group.
	
        --no-trace
          Complementary alias of --trace.
        -o
          Alias of --organization.
        -n
          Alias of --no-prompt.
        -t
          Alias of --trace.
        --services
          
	    Limit for the number of services in the group.
	
        --appuris
          
	    Limit for the number of mapped uris per application.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --organization
          
		The organization to place the new user into.
		Defaults to the current organization.
		This is a stackato/CFv2 specific option.
	    
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --admin
          
		Give the newly created user administrator privileges.
	    
        --password
          
		The password to use.
	    
        --group
          
		The group to put the new user into.
		This is a stackato/CFv1 specific option.
	    
        --sudo
          
	    Applications can use sudo (or not).
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --email
          
		The email of the user to create.
		This is a stackato/CFv2 specific option.
	    
        --non-interactive
          Alias of --no-prompt.
        --no-sudo
          Complementary alias of --sudo.
        --mem
          
	    Amount of memory applications can use.
	
        --drains
          
	    Limit for the number of drains in the group.
	

          ..raw:: html

            </div></div>

.. _command-create_user:

      create_user
        Register a new user in the current or specified target. This operation requires administrator privileges, except if "allow_registration" is set server-side.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --noprompt
          Alias of --no-prompt.
        --passwd
          Alias of --password.
        --apps
          
	    Limit for the number of applications in the group.
	
        --no-trace
          Complementary alias of --trace.
        -o
          Alias of --organization.
        -n
          Alias of --no-prompt.
        -t
          Alias of --trace.
        --services
          
	    Limit for the number of services in the group.
	
        --appuris
          
	    Limit for the number of mapped uris per application.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --organization
          
		The organization to place the new user into.
		Defaults to the current organization.
		This is a stackato/CFv2 specific option.
	    
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --admin
          
		Give the newly created user administrator privileges.
	    
        --password
          
		The password to use.
	    
        --group
          
		The group to put the new user into.
		This is a stackato/CFv1 specific option.
	    
        --sudo
          
	    Applications can use sudo (or not).
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --email
          
		The email of the user to create.
		This is a stackato/CFv2 specific option.
	    
        --non-interactive
          Alias of --no-prompt.
        --no-sudo
          Complementary alias of --sudo.
        --mem
          
	    Amount of memory applications can use.
	
        --drains
          
	    Limit for the number of drains in the group.
	

          ..raw:: html

            </div></div>

.. _command-delete-user:

      delete-user
        Delete the named user, and the user's applications and services from the current or specified target. This operation requires administrator privileges.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -t
          Alias of --trace.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --non-interactive
          Alias of --no-prompt.
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	

          ..raw:: html

            </div></div>

.. _command-delete_user:

      delete_user
        Delete the named user, and the user's applications and services from the current or specified target. This operation requires administrator privileges.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -t
          Alias of --trace.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --non-interactive
          Alias of --no-prompt.
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	

          ..raw:: html

            </div></div>

.. _command-passwd:

      passwd
        Change the password of the current user in the current or specified target.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --passwd
          Alias of --password.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -t
          Alias of --trace.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --non-interactive
          Alias of --no-prompt.
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	
        --password
          
		The new password. If not present it will be interactively
		asked for.
	    

          ..raw:: html

            </div></div>

.. _command-register:

      register
        Register a new user in the current or specified target. This operation requires administrator privileges, except if "allow_registration" is set server-side.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --noprompt
          Alias of --no-prompt.
        --passwd
          Alias of --password.
        --apps
          
	    Limit for the number of applications in the group.
	
        --no-trace
          Complementary alias of --trace.
        -o
          Alias of --organization.
        -n
          Alias of --no-prompt.
        -t
          Alias of --trace.
        --services
          
	    Limit for the number of services in the group.
	
        --appuris
          
	    Limit for the number of mapped uris per application.
	
        --no-prompt
          
	    Disable interactive queries.
	
        --organization
          
		The organization to place the new user into.
		Defaults to the current organization.
		This is a stackato/CFv2 specific option.
	    
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --admin
          
		Give the newly created user administrator privileges.
	    
        --password
          
		The password to use.
	    
        --group
          
		The group to put the new user into.
		This is a stackato/CFv1 specific option.
	    
        --sudo
          
	    Applications can use sudo (or not).
	
        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --email
          
		The email of the user to create.
		This is a stackato/CFv2 specific option.
	    
        --non-interactive
          Alias of --no-prompt.
        --no-sudo
          Complementary alias of --sudo.
        --mem
          
	    Amount of memory applications can use.
	
        --drains
          
	    Limit for the number of drains in the group.
	

          ..raw:: html

            </div></div>

.. _command-token:

      token
        Interactively set authentication token.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        --noprompt
          Alias of --no-prompt.
        -n
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --non-interactive
          Alias of --no-prompt.
        --no-prompt
          
	    Disable interactive queries.
	

          ..raw:: html

            </div></div>

.. _command-unregister:

      unregister
        Delete the named user, and the user's applications and services from the current or specified target. This operation requires administrator privileges.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -t
          Alias of --trace.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --non-interactive
          Alias of --no-prompt.
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	

          ..raw:: html

            </div></div>

.. _command-users:

      users
        Show the list of users known to the current or specified target.

        .. raw:: html

          <div class="spoiler">
          <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
          <div class="inner" style="display:none;">

        --token-file
          
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
        -n
          Alias of --no-prompt.
        --trace
          
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
        -t
          Alias of --trace.
        --noprompt
          Alias of --no-prompt.
        --target
          
	    The once-off target to use for the current operation.
	
        --json
          
	    Print raw json as output, not human-formatted data.
	
        --non-interactive
          Alias of --no-prompt.
        --token
          
	    The once-off authentication token to use for the
	    current operation.
	
        --no-trace
          Complementary alias of --trace.
        --no-prompt
          
	    Disable interactive queries.
	

          ..raw:: html

            </div></div>

  
Convenience
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-alias:
  
  alias
    Create a shortcut for a command (prefix).

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    -n
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --non-interactive
      Alias of --no-prompt.
    
.. _command-aliases:
  
  aliases
    List the known aliases (shortcuts).

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    -n
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    
.. _command-unalias:
  
  unalias
    Remove a shortcut by name.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    -n
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --non-interactive
      Alias of --no-prompt.

    ..raw:: html

      </div></div>

  
Miscellaneous
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-curl:
  
  curl
    Run a raw rest request against the chosen target

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --token-file
      
	    Path to an existing and readable file containing
	    the targets and authorization tokens.
	
    -n
      Alias of --no-prompt.
    --trace
      
	    Activate tracing of the issued REST requests and responses.
	    This option is a no-op now. Tracing is always active. See
	    the 'trace' command to print the saved trace to stdout.
	
    -t
      Alias of --trace.
    --noprompt
      Alias of --no-prompt.
    --target
      
	    The once-off target to use for the current operation.
	
    --token
      
	    The once-off authentication token to use for the
	    current operation.
	
    --non-interactive
      Alias of --no-prompt.
    --no-trace
      Complementary alias of --trace.
    --no-prompt
      
	    Disable interactive queries.
	
    
.. _command-guid:
  
  guid
    Map the specified name into a uuid, given the type.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    -n
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    
.. _command-help:
  
  help
    Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --query
      
		Activate query form of the help.
	    
    -n
      Alias of --no-prompt.
    --query-actor
      
		Activate query-actor form of the help.
	    
    --width
      
	    The line width to format the help for.
	    Defaults to the terminal width, or 80 when
	    no terminal is available.
	
    --noprompt
      Alias of --no-prompt.
    --json
      
		Activate json form of the help.
	    
    --short
      
		Activate short form of the help.
	    
    --non-interactive
      Alias of --no-prompt.
    -w
      Alias of --width.
    --list
      
		Activate list form of the help.
	    
    --no-prompt
      
	    Disable interactive queries.
	
    --full
      
		Activate full form of the help.
	    
    --by-category
      
		Activate by-category form of the help.
	    
    
.. _command-named-entities:
  
  named-entities
    List the entity types usable for 'guid'. I.e. the types of the named entities known to the client.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    -n
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --json
      
	    Print raw json as output, not human-formatted data.
	
    --non-interactive
      Alias of --no-prompt.
    
.. _command-trace:
  
  trace
    Print the saved REST trace for the last client command to stdout.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --no-prompt
      
	    Disable interactive queries.
	
    -n
      Alias of --no-prompt.
    --noprompt
      Alias of --no-prompt.
    --non-interactive
      Alias of --no-prompt.
    
.. _command-admin help:
  
  admin help
    Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --query
      
		Activate query form of the help.
	    
    -n
      Alias of --no-prompt.
    --query-actor
      
		Activate query-actor form of the help.
	    
    --width
      
	    The line width to format the help for.
	    Defaults to the terminal width, or 80 when
	    no terminal is available.
	
    --noprompt
      Alias of --no-prompt.
    --json
      
		Activate json form of the help.
	    
    --short
      
		Activate short form of the help.
	    
    --non-interactive
      Alias of --no-prompt.
    -w
      Alias of --width.
    --list
      
		Activate list form of the help.
	    
    --no-prompt
      
	    Disable interactive queries.
	
    --full
      
		Activate full form of the help.
	    
    --by-category
      
		Activate by-category form of the help.
	    
    
.. _command-drain help:
  
  drain help
    Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --query
      
		Activate query form of the help.
	    
    -n
      Alias of --no-prompt.
    --query-actor
      
		Activate query-actor form of the help.
	    
    --width
      
	    The line width to format the help for.
	    Defaults to the terminal width, or 80 when
	    no terminal is available.
	
    --noprompt
      Alias of --no-prompt.
    --json
      
		Activate json form of the help.
	    
    --short
      
		Activate short form of the help.
	    
    --non-interactive
      Alias of --no-prompt.
    -w
      Alias of --width.
    --list
      
		Activate list form of the help.
	    
    --no-prompt
      
	    Disable interactive queries.
	
    --full
      
		Activate full form of the help.
	    
    --by-category
      
		Activate by-category form of the help.
	    
    
.. _command-groups help:
  
  groups help
    Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --query
      
		Activate query form of the help.
	    
    -n
      Alias of --no-prompt.
    --query-actor
      
		Activate query-actor form of the help.
	    
    --width
      
	    The line width to format the help for.
	    Defaults to the terminal width, or 80 when
	    no terminal is available.
	
    --noprompt
      Alias of --no-prompt.
    --json
      
		Activate json form of the help.
	    
    --short
      
		Activate short form of the help.
	    
    --non-interactive
      Alias of --no-prompt.
    -w
      Alias of --width.
    --list
      
		Activate list form of the help.
	    
    --no-prompt
      
	    Disable interactive queries.
	
    --full
      
		Activate full form of the help.
	    
    --by-category
      
		Activate by-category form of the help.
	    
    
.. _command-quota help:
  
  quota help
    Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.

    .. raw:: html
    
      <div class="spoiler">
      <a style="font-size: x-small" onclick="showSpoiler(this);"/>+ options</a>
      <div class="inner" style="display:none;">

    --query
      
		Activate query form of the help.
	    
    -n
      Alias of --no-prompt.
    --query-actor
      
		Activate query-actor form of the help.
	    
    --width
      
	    The line width to format the help for.
	    Defaults to the terminal width, or 80 when
	    no terminal is available.
	
    --noprompt
      Alias of --no-prompt.
    --json
      
		Activate json form of the help.
	    
    --short
      
		Activate short form of the help.
	    
    --non-interactive
      Alias of --no-prompt.
    -w
      Alias of --width.
    --list
      
		Activate list form of the help.
	    
    --no-prompt
      
	    Disable interactive queries.
	
    --full
      
		Activate full form of the help.
	    
    --by-category
      
		Activate by-category form of the help.
	    

    ..raw:: html

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


