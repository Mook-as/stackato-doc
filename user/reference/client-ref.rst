
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
    Administrative user privileges are required where "*(admin)*" is noted.

**Getting Started**

    login
        Log with the named user into the current or specified target.
    logout
        Log out of the current, specified, or all targets.
    target
        Report the current target, or set a new target.
    targets
        List the available targets, and their authorization tokens, if any.
    tokens
        List the available targets, and their authorization tokens, if any.

**Applications**

    app
        Show the information of the specified application.
    apps
        List the applications deployed to the target.
    list
        List the applications deployed to the target.

        *Information*
        
            crashes
                List recent application crashes.
            crashlogs
                Display log information for the application. An alias of 'logs'.
            disk
                Show the disk reservation for a deployed application.
            drains
                Show the list of drains attached to the application.
            env
                List the application's environment variables.
            events
                Show the application's events as recorded so far.
            file
                Display directory listing or file download.
            files
                Display directory listing or file download.
            health
                Report the health of the seecified applications.
            instances
                List application instances for a deployed application.
            logs
                Display log information for the application.
            mem
                Show the memory reservation for a deployed application.
            stats
                Display resource usage for a deployed application.
            tail
                Monitor file for changes and stream them.
            drain list
                Show the list of drains attached to the application.
        *Management*
        
            create-app
                Create an empty application with the specified configuration.
            dbshell
                Invoke interactive db shell for a bound service.
            delete
                Delete the specified applications.
            env-add
                Add the specified environment variable to the named application.
            env-del
                Remove the specified environment variable from the named application.
            map
                Make the application accessible through the url (a route consisting of host and domain)
            open
                Open the application|url|target (web console) in a browser
            push
                Configure, create, push, map, and start a new application.
            rename
                Rename the specified application.
            restart
                Stop and restart a deployed application.
            run
                Run an arbitrary command on a running instance.
            scale
                Update the number of instances, memory and/or disk reservation for a deployed application.
            scp
                Copy source files and directories to the destination.
            set-env
                Add the specified environment variable to the named application.
            ssh
                ssh to a running instance (or target), or run an arbitrary command.
            start
                Start a deployed application.
            stop
                Stop a deployed application.
            unmap
                Unregister the application from the url.
            unset-env
                Remove the specified environment variable from the named application.
            drain add
                Attach a new named drain to the application.
            drain delete
                Remove the named drain from the application.
**Services**

    service
        Show the information about the named service.
    service-plans
        List all available plans of the supported services.
    services
        List the supported and provisioned services of the target.

        *Authentication Tokens*
        
            create-service-auth-token
                Create a new service authentication token.
            delete-service-auth-token
                Delete the specified service authentication token.
            service-auth-tokens
                Show all service authentication tokens knowns to the target.
            update-service-auth-token
                Update the specified service authentication token.
        *Brokers*
        
            add-service-broker
                Make the named service broker known.
            service-brokers
                Show the list of known service brokers.
        *Management*
        
            bind-service
                Bind the named service to the specified application.
            bind_service
                Bind the named service to the specified application.
            clone-services
                Copy the service bindings of the source application to the destination application.
            create-service
                Create a new provisioned service, possibly bind it to an application.
            create_service
                Create a new provisioned service, possibly bind it to an application.
            delete-service
                Delete the named provisioned service.
            delete_service
                Delete the named provisioned service.
            rename-service
                Rename the specified service instance.
            rename_service
                Rename the specified service instance.
            tunnel
                Create a local tunnel to a service, possibly start a local client as well.
            unbind-service
                Disconnect the named service from the specified application.
            unbind_service
                Disconnect the named service from the specified application.
**Organizations**

    create-org
        Create a new organization.
    delete-org
        Delete the named organization.
    org
        Show the named organization's information.
    orgs
        List the available organizations.
    quota-org
        Set the quotas for the current or named organization.
    rename-org
        Rename the named organization.
    switch-org
        Switch the current organization to the named organization. This invalidates the current space.

**Spaces**

    create-space
        Create a new space.
    delete-space
        Delete the named space.
    rename-space
        Rename the named space.
    space
        Show the named space's information.
    spaces
        List the available spaces in the specified organization. See --organization for details
    switch-space
        Switch the current space to the named space. This may switch the organization as well.

**Routes**

    delete-route
        Delete the named route.
    routes
        List all available routes.

**Domains**

    domains
        List the available domains in the specified space, or all.
    map-domain
        Add the named domain to an organization or space.
    unmap-domain
        Remove the named domain from an organization or space.

**Administration**

    frameworks
        List the supported frameworks of the target.
    group
        Report the current group, or (un)set it.
    info
        Show the basic system and account information.
    limits
        Show and/or modify the limits applying to applications in the named group.
    quota-org
        Set the quotas for the current or named organization.
    quotas
        List the available quota definitions.
    runtimes
        List the supported runtimes of the target.
    stacks
        List the supported stacks of the target.
    target
        Report the current target, or set a new target.
    targets
        List the available targets, and their authorization tokens, if any.
    tokens
        List the available targets, and their authorization tokens, if any.
    usage
        Show the current memory allocation and usage of the active or specified user/group (CFv1), or the specified or current space (CFv2).
    user
        Show the name of the user we are logged in as in the current or specified target.
    user-info
        Shows the information of a user in the current or specified target. Defaults to the current user. Naming a specific user requires a CFv2 target.
    version
        Print the version number of the client.
    admin grant
        Grant the named user administrator privileges for the current or specified target.
    admin list
        Show a list of the administrators for the current or specified target.
    admin patch
        Apply a patch to the current or specified target.
    admin report
        Retrieve a report containing the logs of the current or specified target.
    admin revoke
        Revoke the administrator privileges for named user at the current or specified target.
    groups add-user
        Add the named user to the specified group.
    groups create
        Create a new group with the specified name.
    groups delete-user
        Remove the named user from the specified group.
    groups delete
        Delete the named group.
    groups limits
        Show and/or modify the limits applying to applications in the named group.
    groups show
        Show the list of groups known to the target.
    groups users
        Show the list of users in the named group.
    quota configure
        Reconfigure the named quota definition.
    quota create
        Create a new quota definition.
    quota delete
        Delete the named quota definition.
    quota list
        List the available quota definitions.
    quota rename
        Rename the named quota definition.
    quota show
        Show the details of the named quota definition. If not specified it will be asked for interactively (menu).

        *User Management*
        
            add-user
                Register a new user in the current or specified target. This operation requires administrator privileges, except if "allow_registration" is set server-side.
            add_user
                Register a new user in the current or specified target. This operation requires administrator privileges, except if "allow_registration" is set server-side.
            create-user
                Register a new user in the current or specified target. This operation requires administrator privileges, except if "allow_registration" is set server-side.
            create_user
                Register a new user in the current or specified target. This operation requires administrator privileges, except if "allow_registration" is set server-side.
            delete-user
                Delete the named user, its applications and services from the current or specified target. This operation requires administrator privileges.
            delete_user
                Delete the named user, its applications and services from the current or specified target. This operation requires administrator privileges.
            login
                Log with the named user into the current or specified target.
            logout
                Log out of the current, specified, or all targets.
            passwd
                Change the password of the user we are logged in as in the current or specified target.
            register
                Register a new user in the current or specified target. This operation requires administrator privileges, except if "allow_registration" is set server-side.
            token
                Interactively set authentication token.
            unregister
                Delete the named user, its applications and services from the current or specified target. This operation requires administrator privileges.
            users
                Show the list of users known to the current or specified target.
**Convenience**

    alias
        Create a shortcut for a command (prefix).
    aliases
        List the known aliases (shortcuts).
    unalias
        Remove a shortcut by name.

**Miscellaneous**

    curl
        Run a raw rest request against the chosen target
    guid
        Map the specified name into a uuid, given the type.
    help
        Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.
    named-entities
        List the entity types usable for 'guid'. I.e. the types of the named entities known to the client.
    trace
        Print the saved REST trace for the last client command to stdout.
    admin help
        Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.
    drain help
        Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.
    groups help
        Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.
    quota help
        Retrieve help for a command or command set. Without arguments help for all commands is given. The default format is --full.


