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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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

  **Information**
      
.. _command-crashes:

      crashes
        List recent application crashes.
              
.. _command-crashlogs:

      crashlogs
        Display log information for the application. An alias of 'logs'.
              
.. _command-disk:

      disk
        Show the disk reservation for a deployed application.
              
.. _command-drains:

      drains
        Show the list of drains attached to the application.
              
.. _command-env:

      env
        List the application's environment variables.
              
.. _command-events:

      events
        Show the application's events as recorded so far.
              
.. _command-file:

      file
        Display directory listing or file.
              
.. _command-files:

      files
        Display directory listing or file.
              
.. _command-health:

      health
        Report the health of the specified application(s).
              
.. _command-instances:

      instances
        List application instances for a deployed application.
              
.. _command-logs:

      logs
        Display log information for the application.
              
.. _command-mem:

      mem
        Show the memory reservation for a deployed application.
              
.. _command-stats:

      stats
        Display the resource usage for a deployed application.
              
.. _command-tail:

      tail
        Monitor file for changes and stream them.
              
.. _command-drain list:

      drain list
        Show the list of drains attached to the application.
              
  **Management**
      
.. _command-create-app:

      create-app
        Create an empty application with the specified configuration.
              
.. _command-dbshell:

      dbshell
        Invoke interactive db shell for a bound service.
              
.. _command-delete:

      delete
        Delete the specified application(s).
              
.. _command-env-add:

      env-add
        Add the specified environment variable to the named application.
              
.. _command-env-del:

      env-del
        Remove the specified environment variable from the named application.
              
.. _command-map:

      map
        Make the application accessible through the specified URL (a route consisting of host and domain)
              
.. _command-open:

      open
        Open the application|URL|target (web console) in a browser
              
.. _command-push:

      push
        Configure, create, push, map, and start a new application.
              
.. _command-rename:

      rename
        Rename the specified application.
              
.. _command-restart:

      restart
        Stop and restart a deployed application.
              
.. _command-run:

      run
        Run an arbitrary command on a running instance.
              
.. _command-scale:

      scale
        Update the number of instances, memory and/or disk reservation for a deployed application.
              
.. _command-scp:

      scp
        Copy source files and directories to the destination.
              
.. _command-set-env:

      set-env
        Add the specified environment variable to the named application.
              
.. _command-ssh:

      ssh
        SSH to a running instance (or target), or run an arbitrary command.
              
.. _command-start:

      start
        Start a deployed application.
              
.. _command-stop:

      stop
        Stop a deployed application.
              
.. _command-unmap:

      unmap
        Unregister the application from a URL.
              
.. _command-unset-env:

      unset-env
        Remove the specified environment variable from the named application.
              
.. _command-drain add:

      drain add
        Attach a new named drain to the application.
              
.. _command-drain delete:

      drain delete
        Remove the named drain from the application.
              
  
Services
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-service:
  
  service
    Show the information about the named service.

    .. raw:: html

      <div class="spoiler">
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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

  **Authentication Tokens**
      
.. _command-create-service-auth-token:

      create-service-auth-token
        Create a new service authentication token.
              
.. _command-delete-service-auth-token:

      delete-service-auth-token
        Delete the specified service authentication token.
              
.. _command-service-auth-tokens:

      service-auth-tokens
        Show all service authentication tokens knowns to the target.
              
.. _command-update-service-auth-token:

      update-service-auth-token
        Update the specified service authentication token.
              
  **Brokers**
      
.. _command-add-service-broker:

      add-service-broker
        Make the named service broker known.
              
.. _command-service-brokers:

      service-brokers
        Show the list of known service brokers.
              
  **Management**
      
.. _command-bind-service:

      bind-service
        Bind the named service to the specified application.
              
.. _command-bind_service:

      bind_service
        Bind the named service to the specified application.
              
.. _command-clone-services:

      clone-services
        Copy the service bindings of the source application to the destination application.
              
.. _command-create-service:

      create-service
        Create a new provisioned service, and optionally bind it to an application.
              
.. _command-create_service:

      create_service
        Create a new provisioned service, and optionally bind it to an application.
              
.. _command-delete-service:

      delete-service
        Delete the named provisioned service.
              
.. _command-delete_service:

      delete_service
        Delete the named provisioned service.
              
.. _command-rename-service:

      rename-service
        Rename the specified service instance.
              
.. _command-rename_service:

      rename_service
        Rename the specified service instance.
              
.. _command-tunnel:

      tunnel
        Create a local tunnel to a service, optionally start a local client as well.
              
.. _command-unbind-service:

      unbind-service
        Disconnect the named service from the specified application.
              
.. _command-unbind_service:

      unbind_service
        Disconnect the named service from the specified application.
              
  
Organizations
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-create-org:
  
  create-org
    Create a new organization.

    .. raw:: html

      <div class="spoiler">
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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

  **User Management**
      
.. _command-add-user:

      add-user
        Register a new user in the current or specified target. This operation requires administrator privileges, except if "allow_registration" is set server-side.
              
.. _command-add_user:

      add_user
        Register a new user in the current or specified target. This operation requires administrator privileges, except if "allow_registration" is set server-side.
              
.. _command-create-user:

      create-user
        Register a new user in the current or specified target. This operation requires administrator privileges, except if "allow_registration" is set server-side.
              
.. _command-create_user:

      create_user
        Register a new user in the current or specified target. This operation requires administrator privileges, except if "allow_registration" is set server-side.
              
.. _command-delete-user:

      delete-user
        Delete the named user, and the user's applications and services from the current or specified target. This operation requires administrator privileges.
              
.. _command-delete_user:

      delete_user
        Delete the named user, and the user's applications and services from the current or specified target. This operation requires administrator privileges.
              
.. _command-passwd:

      passwd
        Change the password of the current user in the current or specified target.
              
.. _command-register:

      register
        Register a new user in the current or specified target. This operation requires administrator privileges, except if "allow_registration" is set server-side.
              
.. _command-token:

      token
        Interactively set authentication token.
              
.. _command-unregister:

      unregister
        Delete the named user, and the user's applications and services from the current or specified target. This operation requires administrator privileges.
              
.. _command-users:

      users
        Show the list of users known to the current or specified target.
              
  
Convenience
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-alias:
  
  alias
    Create a shortcut for a command (prefix).

    .. raw:: html

      <div class="spoiler">
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      <input type="button" onclick="showSpoiler(this);" value="Show/Hide Options" />
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
      if (inner.style.display == "none")
        inner.style.display = "";
      else
        inner.style.display = "none";
    }
    </script>
