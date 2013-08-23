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

Getting Started
---------------

**target** [**--allow-http**] [*URL*]
    Reports current target or sets a new target.
    Expects the target *URL* to use the ``https`` scheme.
    URLs containing the ``http`` scheme will be accepted with the ``--allow-http`` option.
    
**login** [*email*] [**--email** *email*] [**--passwd** *password*] [**--token-file** *path*] [**--group** *groupname*]
    Log into the current target.
    
    If ``--token-file`` is used, the authentication token is saved in the specified token file.
    Subsequent ``stackato`` commands will make use of the specified authentication and token file.

    If ``--group`` is used, client will persistently set the current group.
    (All the applicaton and services commands use the option for current
    group also, but only for that one operation, i.e. transient).

    .. note::
        The admin user has the ability to switch to any other user without password when using the login command.

.. _command-token:

**token** { **--token-file** | **--target** }
    Used to interactively set an authentication token for external SSO
    systems which do not use an email/password interactive login.
    
    The command displays a Management Console URL which generates a
    token once the user has authenticated with the SSO provider in the
    browser. Paste the generated token into the CLI prompt to save it
    and authenticate.
    
    Use ``--token-file`` to set the path to an existing file containing
    the targets and authorization tokens.
    
    Use ``--target`` to specify an API endpoint other than the current
    target.

**info**
    System and account information
    
**usage** [**--all**] [*user|group*]
    Shows the current memory allocation and usage of the active or specified user/group.

**version**
    Shows the version of this ``stackato`` command.

Applications
------------

**apps**
    List deployed applications

.. _command-push:

Application Creation
--------------------

**push** [*appname*]
    Create, push, map, and start a new application
    
**push** [*appname*] **--path** *path*
    Push application from specified *path*

.. _command-push-url:
    
**push** [*appname*] **--url** *URL*
    Set the *URL* for the application,
    such that the application will respond to HTTP requests sent to the given URL.
    
**push** [*appname*] **--instances** *N*
    Set the expected number *N* of instances
    
**push** [*appname*] **--mem**  *memsize*
    Set the memory reservation for the application.
    Memory value *memsize* can be specified in megabytes (M) as an integer (64M, 256M, 500M)
    or in gigabytes (G) as an integer or float (1G, 1.5G, 1.75G)
    
**push** [*appname*] **--runtime** *runtime*
    Set the runtime to use for the application

**push** [*appname*] { **--framework** | **-f** } *framework*
    Set the framework to use for the application
    
**push** [*appname*] **--no-start**
    Do not auto-start the application

**push** [*appname*] { **--no-prompt** | **-n** }
    No input.  Take settings from *stackato.yml*.

**push** [*appname*] **--copy-unsafe-links**
	Copy links to outside of the application into it, instead of rejecting them with an error.

.. _command-operations:

Application Operations
----------------------

**start** [*appname*]
    Start the application
    
**stop** [*appname*]
    Stop the application
    
**restart** [*appname*]
    Restart the application
    
**delete** [*appname*]
    Delete the named applications

.. _command-updates:

Application Updates
-------------------

**update** [*appname*] [**--path** *path*]
    Update the application bits
    
**update** [*appname*] { **--no-prompt** | **-n** }
    Do not prompt user for details, use defaults.
    
**update** [*appname*] { **--env-mode** **replace** | **preserve** }
    By default, an update will preserve any environment variables set
    previously. Use *--env-mode replace* to delete/unset variables or
    override variable values with those set in stackato.yml,
    manifest.yml or using the *--env* option
    
**mem** [*appname*] [*memsize*]
    Update the memory reservation for an application.
    Memory value *memsize* can be specified in megabytes (M) as an integer (64M, 256M, 500M)
    or in gigabytes (G) as an integer or float (1G, 1.5G, 1.75G)

.. _command-map:
    
**map** [*appname*] *URL*
    Register the application to the *URL*,
    such that the application will respond to HTTP requests sent to the given URL.
    
.. _command-unmap:

**unmap** [*appname*] *URL*
    Unregister the application from the *URL*
    
**instances** [*appname*] { *number* | *delta* }
    Scale the application instances up or down. A number on its own sets
    the absolute number of instances. A "+" or "-" prefix to a number
    adjusts from the current number of instances.

.. _command-app-info:

Application Information
-----------------------

**crashes** [*appname*]
    List recent application crashes
    
**crashlogs** [*appname*]
    Deprecated in Stackato 2.4. Currently an alias for **logs** which
    now includes logs for crashed applications. When targeting Stackato
    2.2 and older systems, displays logs for crashed applications. Takes
    the same options as **logs** (below)
 
.. _command-logs:

**logs** [*appname*] [*options...*]
  Display logs for application instances. Takes the following options:

  **--follow** : Tail the stream of log entries.

  **--num** *N* : Show the last N log entries. Default: 100. 0 shows the whole log.

  **--source** *S* : Show only log entries coming from source *S* (glob pattern).

  **--instance** *N* : Show only log entries coming from instance *N*.

  **--filename** *F* : Show only log entries coming from file *F* (glob pattern).

  **--text** *T* : Show only log entries matching the glob pattern *T*.

.. _command-drain:

**drain add** [*appname*] *drain-name* *drain-uri*
    Add a named log drain to the application.
    <uri> specifies the log destination.

**drain delete** [*appname*] *drain-name*
    Delete the named log drain from the application.

**drain list** [*appname*]
    List all log drains defined for the application.

.. _command-files:

**files** [*appname*] [*path*] [**--all**]
    Display directory listing or file download for optional *path*

**ssh** [**--instance** *instance*] [*appname*] [*command*]

    Allows ``ssh`` access to an app in an interactive shell::
	
        $ stackato ssh myapp
	
    If a command is added, it is run and the connection exited::
		
        $ stackato ssh myapp ls -l
	
    By default, the first instance (0) is targeted. Specify other instances with the ``--instance`` option::
	
        $ stackato ssh myapp --instance 1 ls -l

**ssh api** [*command*]
    Opens an ``ssh`` session to the Stackato VM (Primary) as
    the 'stackato' system user. Available to Admin users only. Prompts
    for the 'stackato' user password.

**scp** [*--instance* *N*] [*appname*] *[:]source* *[:]destination*
    Copy files and directories to and from application containers. The
    colon ":" character preceding a specified source or destination
    indicates a remote file or path. Sources and destinations can be
    file names, directory names, or full paths.
	
**run** [**--instance** *instance*] [*appname*] [*command*]
    Run an arbitrary command on a running instance.
    
**stats** [*appname*]
    Display resource usage for the application
    
**instances** [*appname*]
    List application instances
    
**open** [*appname*]
    Open primary application URL in a browser

**open** *URL*
    Open any URL in a browser [HTTP]

**open api**
    Open target web console in a browser [HTTPS]

.. _command-app-env:

Application Environment
-----------------------

**env** [*appname*]
    List application environment variables
    
**env-add** [*appname*] *variable* [**=**] *value*
    Add an environment variable in an application
    
**env-del** [*appname*] *variable*
    Delete an environment variable in an application

.. _command-services:

Services
--------

**service** *servicename*
    Shows the specific details of a particular service
    
**services**
    Lists of services available and provisioned
    
**create-service** *service* [**--name** *servicename*] [**--bind** *appname*]
    Create a provisioned service
    
**create-service** *service* *servicename*
    Create a provisioned *service* and assign it *name*
    
**create-service** *service* *servicename* [*appname*]
    Create a provisioned *service*, assign it *name*, and bind to *appname*
    
**delete-service** [*--all*] [*servicename*]
    Delete a provisioned service by *servicename*, or delete all services
    not bound to any application using *--all* 
    
**bind-service** [*servicename*] [appname]
    Bind a service to an application
    
**unbind-service** [*servicename*] [appname]
    Unbind service from the application
    
**clone-services** *src-app* *dst-app*
    Clone service bindings from *src-app* application to *dst-app*
    
**dbshell** [*appname*]* [*servicename*]
    Invoke interactive db shell for a bound service.

**tunnel** [*servicename*] [**--port** *port*] [**--allow-http**]
    Create a local tunnel to a service.

**tunnel** [*servicename*] [*client-command*] [**--allow-http**]
    As above, and start a local client.

.. _command-administration:

Administration
--------------

**user**
    Display user account information
    
**passwd**
    Change the password for the current user
    
**logout** { *URL* | *--all* }
    Logs current user out of the current target. With an API endpoint
    URL argument, logs user out of the specified target only. With --all
    argument, logs user out of all targets.
    
**add-user** [**--email** *email*] [**--passwd** *password*] [**--admin**] *(admin)*
    Register a new user. If ``--admin`` is specified, grant the new user
    admin privileges.
    
**delete-user** *email* *(admin)*
    Delete a user and all associated applications and services
    
**users** *(admin)*
    List all users and associated applications
    
**admin grant|revoke** *email* *(admin)*
    Grant or revoke admin privileges for the specified user. The email
    address is validated against the list of known users and rejected if
    unknown. Caution: The ``revoke`` command can be used on the
    current user. Be careful not to lock yourself out.

**admin list** *(admin)*
    List users with admin privileges.

**admin patch** [*patchfile|name|url*]
    Upload and execute patchfile (via ssh) to modify the server.
    Will ask for the stackato password.

**admin report** [*destinationfile*] *(admin)*
    Retrieve a ``gzip`` compressed tarball of a Stackato system report
    from the primary node.  Used for diagnosing server issues.
    If output *filename* is not specified, it defaults to *<target>-report.tgz*.
    To generate a report for a node other than the primary,
    run ``kato report`` on that node.

.. _command-system:

System
------

**runtimes**
    Display the supported runtimes of the target system
    
**frameworks**
    Display the recognized frameworks of the target system

.. _command-host-file:

Host File
---------

**host add** [**--dry-run**] [*<ip-address> <host>*]

**host update** [**--dry-run**] [*<ip-address> <host>*]

**host remove** [**--dry-run**] [*<ip-address>|<host>*]

**host list**
    
    Manipulate the hosts file on the Stackato client system.
    Add mappings, replace, remove, and show them.

    .. note::
        Unlike most ``stackato`` command options, this one operates on the *client* 
        system, not the *target* system.

.. _command-misc:

Misc
----

**aliases**
    List aliases
    
**alias** *alias* [**=**] *command*
    Create an alias for a command
    
**unalias** *alias*
    Remove an alias
    
**targets**
    List known targets and associated authorization tokens

.. _command-users-groups-limits:

Users, Groups, and Limits
-------------------------

**group**
    Show the current group. May be none.

**group** *groupname*
    Make the named group the current group to use.
    Once set, the group name does not need to be specified for ``stackato groups`` commands.

**group --reset**
    Unset the current group

**groups create** *groupname* *(admin)*
    Create a new named group

**groups delete** *groupname* *(admin)*
    Remove the named group

**groups** *(admin)*
    List the known groups, and the users belonging to them

**limits** { *groupname* | *username* } [**--mem** *mem*] [**--apps** *N*] [**--appuris** *N*] [**--services** *N*] [**--sudo** { **true** | **false** }]
    Set *(admin only)* or retrieve limits for a group or user.
    Without *groupname* or *username* use current group.
    Without current group use current user.

**groups limits** *groupname*
    Displays the current limits for a group

**groups add-user** *groupname* *username* *(admin)*
    Add the specified user *username* to the group *groupname*

**groups delete-user** *groupname* *username* *(admin)*
    Remove the specified user *username* from the group *groupname*

**groups users** [*groupname*]
    List users belonging to group *groupname*.
    Without *groupname*, list for the current group.
    Non-admin users can only query groups for which they are a member.

.. _command-options:

Options
-------

Most of the options below are also listed above with the commands they
apply to. This list is equivalent to the output of ``stackato help
options`` and is included as a cross-reference.


**--copy-unsafe-links**
    For push, links pointing outside are copied into the application.

**-d**
    Create and bind an app-specific harbor service for debugging

**--email** *value*
    User name, identified by email address <no default>

**--env** *value*
    Environment setting <no default>

**--env-mode** *value*
    How to manipulate the environment on application update <preserve>

**--user** *value*
    Alias of --email <no default>

**--passwd** *value*
    Password for the account <no default>

**--pass** *value*
    Alias of --passwd <no default>

**--password** *value*
    Alias of --passwd <no default>

**--app** *value*
    Application name <no default>

**--name** *value*
    Alias of --app <no default>

**--bind** *value*
    Name of application to bind a new service to <no default>

**--instance** *value*
    Id of the instance to talk to <no default>

**--instances** *value*
    Number of instances to run the application with <no default>

**--url** *value*
    Primary application url to map to <Default derived from application name>

**--mem** *value*
    Memory requirement of pushed application <Default is framework dependent>

**--path** *value*
    directory the application files to push are in <Default is working directory>

**--manifest** *value*
    Location of the manifest file to use <Default is stackato.yml/manifest.yml in --path directory>

**--no-create**
    If specified assume that the application was created already. push is a super-update.

**--no-start**
    If specified do not start the pushed application

**--nostart**
    Alias of --no-start

**--force**
    Force deletion

**--all**
    Operation is for all applications, files, or logs

**--admin**
    Make the new user an admin

**-t**
    Activate tracing of http requests and responses. OPTIONAL argument!

**--trace**
    Alias of -t

**--token-file** *value*
    File with login tokens to use <~/.stackato/client/tokens>

**--token** *value*
    Value of the login token to use <>

**--timeout** *value*
    Timeout in seconds for the 'run' command. <No timeout>

**--target** *value*
    Target server to use for this command, instead of configured default. <Configuration files>

**--group** *value*
    Group to use for this command, instead of default. <>

**--debug-group**
    Internal use. Intentionally not documented

**--tail**
    Activate tailing of stager operation (push, update, start, restart)

**--notail**
    Deactivate tailing of stager operation (push, update, start, restart)

**--no-tail**
    Alias of --notail

**-q**
    Alias of --quiet

**--quiet**
    Quiet operation

**--no-resources**
    Do not upload resources when pushing

**--noresources**
    Alias of --no-resources

**--no-color**
    Do not colorize output

**--verbose**
    More verbose operation

**--no-prompt**
    Disable interactive queries
  
**-n**
    Alias of --no-prompt

**--noprompt**
    Alias of --no-prompt

**--non-interactive**
    Alias of --no-prompt

**--prefix**
    Put instance information before each line of a shown logfile

**--prefix-logs**
    Alias of --prefix

**--prefixlogs**
    Alias of --prefix

**--json**
    Print raw json as output, not human-formatted data

**--print**
    Print dbshell connection command
    
**-v**
    Print client version

**--version**
    Alias of -v

**-h**
    Print command help

**--runtime** *value*
    Name of runtime to use <no default>

**--exec** *value*
    Execution/start mode <Default framework specific>

**--noframework**
    Application getting pushed has no framework

**--framework** *value*
    Framework to use for the application <Default is auto-detected>

**-f** *value*
    Alias of --framework <Default is auto-detected>

**-u** *value*
    User for which we are doing the operation <no default>

**--options**
    Print the help on options
    
**--port** *value*
    Port for tunneling <10000>

**--allow-http**
    Required to prevent rejection of http urls

**--dry-run**
    Do run launch internal command, but display it.

**--debug** *value*
    Activate tracing of specific client internals <no default>

**--apps** *value*
    Limit for number of applicatons in group <target dependent>

**--appuris** *value*
    Limit for number of mapped uris per app <target dependent>

**--services** *value*
    Limit for number of services in group <target dependent>

**--sudo** *value*
    Applications can use sudo <target dependent>

**--drains** *value*
    Limit for number of drains in group <target dependent>

**--stackato-debug** *value*
    Host:Port for debugging the user app <no defaults>

**--reset**
    Reset current group

**--num** *value*
    Number of log records to retrieve <100>

**--follow**
    Tail the logs

**--no-timestamps**
    Do not display the log entry timestamps

**--source** *value*
    Glob pattern to filter logs by (source field) <*>

**--text** *value*
    Glob pattern to filter logs by (text field) <*>

**--filename** *value*
    Glob pattern to filter logs by (filename field) <*>

**--newer** *value*
    Seconds since epoch to filter logs by (timestamp field) <0>

**--**
    Forcibly stop option processing


.. _command-help:

Help
----

**help** [*command*]
    Get general help or help on a specific command

**options**
    Get help on available options 
