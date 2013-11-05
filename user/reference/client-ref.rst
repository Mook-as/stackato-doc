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
    
.. _command-logout:
  
  logout
    Log out of the current, specified, or all targets.
    
.. _command-target:
  
  target
    Set the target API endpoint for the client, or report the current target.

  
Applications
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-app:
  
  app
    Show the information of the specified application.
    
.. _command-apps:
  
  apps
    List the applications deployed to the target.
    
.. _command-list:
  
  list
    List the applications deployed to the target.

    *Information*
      
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
              
    *Management*
      
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
    
.. _command-service-plans:
  
  service-plans
    List all available plans of the supported services.
    
.. _command-services:
  
  services
    List the supported and provisioned services of the target.

    *Authentication Tokens*
      
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
              
    *Brokers*
      
.. _command-add-service-broker:

      add-service-broker
        Make the named service broker known.
              
.. _command-service-brokers:

      service-brokers
        Show the list of known service brokers.
              
    *Management*
      
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
    
.. _command-delete-org:
  
  delete-org
    Delete the named organization.
    
.. _command-link-user-org:
  
  link-user-org
    Add the specified user to the named organization, in various roles. This is a CFv2 specific command
    
.. _command-org:
  
  org
    Show the named organization's information.
    
.. _command-orgs:
  
  orgs
    List the available organizations.
    
.. _command-quota-org:
  
  quota-org
    Set the quotas for the current or named organization.
    
.. _command-rename-org:
  
  rename-org
    Rename the named organization.
    
.. _command-switch-org:
  
  switch-org
    Switch the current organization to the named organization. This invalidates the current space.
    
.. _command-unlink-user-org:
  
  unlink-user-org
    Remove the specified user from the named organization, in various roles. This is a CFv2 specific command

  
Spaces
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-create-space:
  
  create-space
    Create a new space.
    
.. _command-delete-space:
  
  delete-space
    Delete the named space.
    
.. _command-link-user-space:
  
  link-user-space
    Add the specified user to the named space, in various roles. This is a CFv2 specific command
    
.. _command-rename-space:
  
  rename-space
    Rename the named space.
    
.. _command-space:
  
  space
    Show the named space's information.
    
.. _command-spaces:
  
  spaces
    List the available spaces in the specified organization. See --organization for details
    
.. _command-switch-space:
  
  switch-space
    Switch from the current space to the named space. This may switch the organization as well.
    
.. _command-unlink-user-space:
  
  unlink-user-space
    Remove the specified user from the named space, in various roles. This is a CFv2 specific command

  
Routes
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-delete-route:
  
  delete-route
    Delete the named route.
    
.. _command-routes:
  
  routes
    List all available routes.

  
Domains
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-domains:
  
  domains
    List the available domains in the specified space, or all.
    
.. _command-map-domain:
  
  map-domain
    Add the named domain to an organization or space.
    
.. _command-unmap-domain:
  
  unmap-domain
    Remove the named domain from an organization or space.

  
Administration
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-frameworks:
  
  frameworks
    List the supported frameworks of the target.
    
.. _command-group:
  
  group
    Report the current group, or (un)set it.
    
.. _command-info:
  
  info
    Show the basic system and account information.
    
.. _command-limits:
  
  limits
    Show and/or modify the limits applying to applications in the named group.
    
.. _command-quotas:
  
  quotas
    List the available quota definitions.
    
.. _command-runtimes:
  
  runtimes
    List the supported runtimes of the target.
    
.. _command-stacks:
  
  stacks
    List the supported stacks of the target.
    
.. _command-targets:
  
  targets
    List the available targets, and their authorization tokens, if any.
    
.. _command-tokens:
  
  tokens
    List the available targets, and their authorization tokens, if any.
    
.. _command-usage:
  
  usage
    Show the current memory allocation and usage of the active or specified user/group (CFv1), or the specified or current space (CFv2).
    
.. _command-user:
  
  user
    Show the name of the current user in the current or specified target.
    
.. _command-user-info:
  
  user-info
    Shows the information of a user in the current or specified target. Defaults to the current user. Naming a specific user requires a CFv2 target.
    
.. _command-version:
  
  version
    Print the version number of the client.
    
.. _command-admin grant:
  
  admin grant
    Grant the named user administrator privileges for the current or specified target.
    
.. _command-admin list:
  
  admin list
    Show a list of the administrators for the current or specified target.
    
.. _command-admin patch:
  
  admin patch
    Apply a patch to the current or specified target.
    
.. _command-admin report:
  
  admin report
    Retrieve a report containing the logs of the current or specified target.
    
.. _command-admin revoke:
  
  admin revoke
    Revoke administrator privileges for the named user at the current or specified target.
    
.. _command-groups add-user:
  
  groups add-user
    Add the named user to the specified group.
    
.. _command-groups create:
  
  groups create
    Create a new group with the specified name.
    
.. _command-groups delete-user:
  
  groups delete-user
    Remove the named user from the specified group.
    
.. _command-groups delete:
  
  groups delete
    Delete the named group.
    
.. _command-groups limits:
  
  groups limits
    Show and/or modify the limits applying to applications in the named group.
    
.. _command-groups show:
  
  groups show
    Show the list of groups known to the target.
    
.. _command-groups users:
  
  groups users
    Show the list of users in the named group.
    
.. _command-quota configure:
  
  quota configure
    Reconfigure the named quota definition.
    
.. _command-quota create:
  
  quota create
    Create a new quota definition.
    
.. _command-quota delete:
  
  quota delete
    Delete the named quota definition.
    
.. _command-quota list:
  
  quota list
    List the available quota definitions.
    
.. _command-quota rename:
  
  quota rename
    Rename the named quota definition.
    
.. _command-quota show:
  
  quota show
    Show the details of the named quota definition. If not specified it will be asked for interactively (menu).

    *User Management*
      
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
    
.. _command-aliases:
  
  aliases
    List the known aliases (shortcuts).
    
.. _command-unalias:
  
  unalias
    Remove a shortcut by name.

  
Miscellaneous
^^^^^^^^^^^^^^^^^^^^^

    
.. _command-curl:
  
  curl
    Run a raw rest request against the chosen target
    
.. _command-guid:
  
  guid
    Map the specified name into a uuid, given the type.
    
.. _command-help:
  
  help
    Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.
    
.. _command-named-entities:
  
  named-entities
    List the entity types usable for 'guid'. I.e. the types of the named entities known to the client.
    
.. _command-trace:
  
  trace
    Print the saved REST trace for the last client command to stdout.
    
.. _command-admin help:
  
  admin help
    Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.
    
.. _command-drain help:
  
  drain help
    Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.
    
.. _command-groups help:
  
  groups help
    Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.
    
.. _command-quota help:
  
  quota help
    Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.


