.. index:: Kato Commands

.. _kato-command-ref:

Kato Command Reference
======================

Stackato administration utility

Usage
-----

**kato** *command* [**-h**] [**--help**] [*arguments*] [*command-options*] 

.. _kato-command-ref-list:

Commands
--------

* :ref:`admin <kato-command-ref-admin>` DEPRECATED: Use "kato config" instead
* :ref:`config <kato-command-ref-config>` Manipulate configuration values of Stackato components.
* :ref:`data <kato-command-ref-data-export>` Import or export Stackato system data to or from clusters/nodes.
* :ref:`debug <kato-command-ref-debug-configwatch>` Commands for debugging for Stackato internals.
* :ref:`history <kato-command-ref-history>` Show the kato commands that have been run
* :ref:`info <kato-command-ref-info>` Show information about this node or cluster including assigned and
* :ref:`inspect <kato-command-ref-inspect>` Detect common problems with your Stackato install using 'kato inspect'
* :ref:`log <kato-command-ref-log-drain-add>` Logging utilities for Stackato
* :ref:`node <kato-command-ref-node-attach>` Node management
* :ref:`op <kato-command-ref-op>` Various operational commands
* :ref:`patch <kato-command-ref-patch>` Update a Stackato cluster with post-release fixes.
* :ref:`process <kato-command-ref-process-list>` Start, stop, or restart individual processes. Generally not required;
* :ref:`relocate <kato-command-ref-relocate>` Move containers, application droplets, or services to a new mount point
* :ref:`report <kato-command-ref-report>` Generate a report that can be sent to Stackato support.
* :ref:`restart <kato-command-ref-restart>` Restart Stackato or individual roles.
* :ref:`role <kato-command-ref-role-add>` Management of node roles
* :ref:`shell <kato-command-ref-shell>` Interactive shell for kato
* :ref:`start <kato-command-ref-start>` Start Stackato or individual roles.
* :ref:`status <kato-command-ref-status>` List configured roles and their current status across the cluster.
* :ref:`stop <kato-command-ref-stop>` Stop Stackato or individual roles.
* :ref:`version <kato-command-ref-version>` Display the version of Stackato being run.

----

.. _kato-command-ref-admin:

**admin** [**options**] **grant** *<email>...*

**admin** [**options**] **revoke** *<email>...*

  DEPRECATED: Use "kato config" instead
    
    kato config (push|pop) cloud_controller admins <email>

  **-h** **--help**                       Show help information



----

.. _kato-command-ref-config:

**config** **get** [**options**] [*<component>*] [*<key-path>*]

**config** **set** [**options**] *<component>* *<key-path>* [*<value>*]

**config** **del** [**options**] *<component>* *<key-path>*

**config** **push** [**options**] *<component>* *<key-path>* *<list-value>*

**config** **pop** [**options**] *<component>* *<key-path>* *<list-value>*

  Manipulate configuration values of Stackato components.

  *<value>*                               If value is not given for "set", then it read from STDIN.

  *<component>*                           Can be "cluster", "local" or the name of a process.


  **-h** **--help**                       Show help information

  **-j** **--json**                       For "set", use JSON format when setting config key values.

                                          For "get", use JSON format for displaying output.

  **-y** **--yaml**                       Use YAML format when retrieving or setting config key values.

                                          YAML is the default output format.

  **-f** **--flat**                       Use a flat output format "<full-config-path> <value>"

  **-n** **--node** *<node-IP>*           Take action on a specific cluster node

  **--force**                             Force updating value to different type.



----

.. _kato-command-ref-data-export:

**data** **export** **--only-this-node** [**options**] [*<filename>*]

**data** **export** **--cluster** [**options**] [*<filename>*]

  Export Stackato system data to or from clusters/nodes. With no
  options specified, includes all data except 'resources' and 'aok-config'.

  *<filename>*                            The filename the export will be written to


  **-h** **--help**                       Show help information

  **--cluster**                           Operate on the entire cluster

  **--only-this-node**                    Only affect this node

  **--manual**                            Only import/export roles specified on the command line

  **--force**                             Force import/export of specified roles even if they are not enabled

                                          Requires --manual

                                          Implies --only-this-node

  **--dry-run**                           Do not actually import/export anything

  **--remote**                            Remote import/export (internal use only)

  **--base-dir** *<base-dir>*             Base directory for extracting temporary files

  **--droplets**                          Include droplets (uploaded apps)

  **--exclude-droplets**                  Do not include droplets (uploaded apps)

  **--resources**                         Include the upload cache

  **--exclude-resources**                 Do not include the upload cache (default)

  **--license**                           Include the Stackato license

  **--exclude-license**                   Do not include the Stackato license

  **--admins-list**                       Include the list of users that are admins

  **--exclude-admins-list**               Do not include the list of users that are admins

  **--main-db**                           Include the cloud controller's main database

  **--exclude-main-db**                   Do not include the cloud controller's main database

  **--aok-db**                            Include AOK's database

  **--exclude-aok-db**                    Do not include AOK's database

  **--aok-config**                        Include AOK's configuration 

  **--exclude-aok-config**                Do not include AOK's configuration (default)

  **--filesystem**                        Include the filesystem service

  **--exclude-filesystem**                Do not include the filesystem service

  **--exclude-filesystem-data**           Do not include the filesystem service's user data

  **--exclude-filesystem-user-creation**  Do not include the filesystem service's user creation/quota

  **--harbor**                            Include the harbor service

  **--exclude-harbor**                    Do not include the harbor service

  **--exclude-harbor-data**               Do not include the harbor service's user data

  **--exclude-harbor-metadata**           Do not include the harbor service's metadata

  **--mysql**                             Include the MySQL service

  **--exclude-mysql**                     Do not include the MySQL service

  **--exclude-mysql-data**                Do not include the MySQL service's data

  **--exclude-mysql-metadata**            Do not include the MySQL service's metadata

  **--postgresql**                        Include the PostgreSQL service

  **--exclude-postgresql**                Do not include the PostgreSQL service

  **--exclude-postgresql-data**           Do not include the PostgreSQL service's data

  **--exclude-postgresql-metadata**       Do not include the PostgreSQL service's metadata

  **--mongodb**                           Include the MongoDB service

  **--exclude-mongodb**                   Do not include the MongoDB service

  **--exclude-mongodb-data**              Do not include the MongoDB service's data

  **--exclude-mongodb-metadata**          Do not include the MongoDB service's metadata

  **--memcached**                         Include the memcached service

  **--exclude-memcached**                 Do not include the memcached service

  **--exclude-memcached-data**            Do not include the memcached service's data

  **--exclude-memcached-metadata**        Do not include the memcached service's metadata

  **--redis**                             Include the Redis service

  **--exclude-redis**                     Do not include the Redis service

  **--exclude-redis-data**                Do not include the Redis service's data

  **--exclude-redis-metadata**            Do not include the Redis service's metadata

  **--rabbit**                            Include the RabbitMQ service

  **--exclude-rabbit**                    Do not include the RabbitMQ service

  **--exclude-rabbit-data**               Do not include the RabbitMQ service's data

  **--exclude-rabbit-metadata**           Do not include the RabbitMQ service's metadata



----

.. _kato-command-ref-data-import:

**data** **import** **--only-this-node** [**options**] *<source>*

**data** **import** **--cluster** [**options**] *<source>*

  Import Stackato system data to or from clusters/nodes. With no
  options specified, includes all data except 'resources' and 'aok-config'.

  *<source>*                              This can a hostname or a filename to import from


  **-h** **--help**                       Show help information

  **--cluster**                           Operate on the entire cluster

  **--only-this-node**                    Only affect this node

  **--manual**                            Only import/export roles specified on the command line

  **--force**                             Force import/export of specified roles even if they are not enabled

                                          Requires --manual

                                          Implies --only-this-node

  **--dry-run**                           Do not actually import/export anything

  **--remote**                            Remote import/export (internal use only)

  **--base-dir** *<base-dir>*             Base directory for extracting temporary files

  **--droplets**                          Include droplets (uploaded apps)

  **--exclude-droplets**                  Do not include droplets (uploaded apps)

  **--resources**                         Include the upload cache

  **--exclude-resources**                 Do not include the upload cache (default)

  **--license**                           Include the Stackato license

  **--exclude-license**                   Do not include the Stackato license

  **--admins-list**                       Include the list of users that are admins

  **--exclude-admins-list**               Do not include the list of users that are admins

  **--main-db**                           Include the cloud controller's main database

  **--exclude-main-db**                   Do not include the cloud controller's main database

  **--aok-db**                            Include AOK's database

  **--exclude-aok-db**                    Do not include AOK's database

  **--aok-config**                        Include AOK's configuration 

  **--exclude-aok-config**                Do not include AOK's configuration (default)

  **--filesystem**                        Include the filesystem service

  **--exclude-filesystem**                Do not include the filesystem service

  **--exclude-filesystem-data**           Do not include the filesystem service's user data

  **--exclude-filesystem-user-creation**  Do not include the filesystem service's user creation/quota

  **--harbor**                            Include the harbor service

  **--exclude-harbor**                    Do not include the harbor service

  **--exclude-harbor-data**               Do not include the harbor service's user data

  **--exclude-harbor-metadata**           Do not include the harbor service's metadata

  **--mysql**                             Include the MySQL service

  **--exclude-mysql**                     Do not include the MySQL service

  **--exclude-mysql-data**                Do not include the MySQL service's data

  **--exclude-mysql-metadata**            Do not include the MySQL service's metadata

  **--postgresql**                        Include the PostgreSQL service

  **--exclude-postgresql**                Do not include the PostgreSQL service

  **--exclude-postgresql-data**           Do not include the PostgreSQL service's data

  **--exclude-postgresql-metadata**       Do not include the PostgreSQL service's metadata

  **--mongodb**                           Include the MongoDB service

  **--exclude-mongodb**                   Do not include the MongoDB service

  **--exclude-mongodb-data**              Do not include the MongoDB service's data

  **--exclude-mongodb-metadata**          Do not include the MongoDB service's metadata

  **--memcached**                         Include the memcached service

  **--exclude-memcached**                 Do not include the memcached service

  **--exclude-memcached-data**            Do not include the memcached service's data

  **--exclude-memcached-metadata**        Do not include the memcached service's metadata

  **--redis**                             Include the Redis service

  **--exclude-redis**                     Do not include the Redis service

  **--exclude-redis-data**                Do not include the Redis service's data

  **--exclude-redis-metadata**            Do not include the Redis service's metadata

  **--rabbit**                            Include the RabbitMQ service

  **--exclude-rabbit**                    Do not include the RabbitMQ service

  **--exclude-rabbit-data**               Do not include the RabbitMQ service's data

  **--exclude-rabbit-metadata**           Do not include the RabbitMQ service's metadata



----

.. _kato-command-ref-data-users:

**data** **users** **import** [**options**] *<filename>*

**data** **users** **export** [**options**] [**--exclude-password-hashes**] [*<filename>*]

  Import or export a list of Stackato users (CSV format).

  **-h** **--help**                       Show help information

  **-p** **--exclude-password-hashes**    Do not include hashed passwords in export

  **-d** **--dry-run**                    Do not import/export anything, just show

                                          what will be done



----

.. _kato-command-ref-debug-configwatch:

**debug** **configwatch** [**options**]

  Watch changes to doozer config

  **-n** **--node** *<node-IP>*           Watch config changes for a specific cluster node

  **-p** **--process** *<process-name>*   The name of process to watch config for

  **-g** **--global**                     Config is global and not specific to any node

  **-d** **--dump-tree**                  Dump the config tree seen since starting

  **-i** **--ignore-ctl**                 Ignore doozer tree under /ctl

  **-a** **--show-applied**               Exit once we see this value is seen

  **-w** **--with-revs**                  Show the revisions of config entries

  **-s** **--no-value**                   Do not print the value of path

  **-u** **--until-path** *<path>*        Exit once we see this path

  **-v** **--until-value** *<value>*      Exit once we see this value



----

.. _kato-command-ref-history:

**history** [**--help**] [**-n** *<node-IP>*] [**--json**]

  Show the kato commands that have been run

  **-h** **--help**                       Show help information

  **-n** **--node** *<node-IP>*           Get command history from a specific cluster node

  **-j** **--json**                       Output as JSON



----

.. _kato-command-ref-info:

**info** [**--help**] [**-n** *<node-IP>*] [**--json**] [**--yaml**]

  Show information about this node or cluster including assigned and
  available roles.

  **-h** **--help**                       Show help information

  **-n** **--node** *<node-IP>*           Show info on a specific cluster node

  **-j** **--json**                       Output as JSON

  **-y** **--yaml**                       Output as YAML



----

.. _kato-command-ref-inspect:

**inspect** [**options**]

**inspect** [**options**] [**all**]

**inspect** [**options**] **group** *<group-name>*

**inspect** [**options**] **tests** *<test-name>...*

  Detect common problems with your Stackato install using 'kato inspect'
  
  To run all tests, run:
    kato inspect
  To use a specific group of tests, run:
    kato inspect group <name of group>
  To run specific tests, run:
    kato inspect tests <test1> <test2> <test3>

  **-h** **--help**                       Show help information

  **-v** **--verbose**                    Verbose output



----

.. _kato-command-ref-log-drain-add:

**log** **drain** **add** [**options**] *<name>* *<uri>* [*<param>...*]

  Add a new log drain.
  
  Examples:
  
    # Add a drain to receive system logs
    
    kato log drain add system_splunk udp://logs.splunk.com:1234/
    
    # Add a drain to forward all application logs as json
    
    kato log drain add -f json -p apptail app_splunk udp://logs.splunk.com:1235/
    
    # Add a drain with custom format,
    
    kato log drain add -f "{{.Name}}: {{.Text}}"  system_splunk_2 udp://logs.splunk.com:1236/

  **-h** **--help**                       Show help information

  **-f** **--format** *<format>*          Message format

  **-p** **--prefix** *<prefix>*          Message key prefix; possible values: systail, event, apptail



----

.. _kato-command-ref-log-drain-delete:

**log** **drain** **delete** [**options**] *<name>*

  Delete a drain

  **-h** **--help**                       Show help information



----

.. _kato-command-ref-log-drain-list:

**log** **drain** **list** [**options**]

  List all log drains

  **-h** **--help**                       Show help information


----

.. _kato-command-ref-log-tail:

**log** **tail** [**options**] [*<component>...*]

  *<component>*                           Can be a process name, role name or role group name


  **-h** **--help**                       Show help information

  **--no-color**                          Turn off color

  **--raw**                               Show unformatted logs, including logyard INFO records (skipped by default)

  **--time**                              Show timestamp

  **--legacy**                            Legacy "kato tail" behaviour (without logyard)

  **-n** **--node** *<node-IP>*           Only show logs from a specific cluster node

  **-l** **--local**                      Only show logs from the current node



----

.. _kato-command-ref-node-attach:

**node** **attach** [**options**] *<core-ip>*

  Attach this node to a stackato core node

  **-h** **--help**                       Show help information

  **-e** **--enable** *<roles>*           Enable the specified roles (comma-separated, no spaces)

  **-s** **--no-start**                   Do not auto start processes

  **-v** **--verbose**                    Show process information when starting/stopping roles



----

.. _kato-command-ref-node-list:

**node** **list**

  List all nodes known to this cluster

  **-h** **--help**                       Show help information



----

.. _kato-command-ref-node-migrate:

**node** **migrate** *<old-node-IP>* *<new-node-IP>*

  Migrate the node configuration from old node to a new node

  **-h** **--help**                       Show help information



----

.. _kato-command-ref-node-remove:

**node** **remove** *<node-IP>*

  Remove the node from the cluster

  **-h** **--help**                       Show help information



----

.. _kato-command-ref-node-rename:

**node** **rename** [**options**] *<hostname>*

  **-h** **--help**                       Show help information.

  **-s** **--skip-remap-hosts**           Skip the remapping of existing app URLS to the

                                          new domain.

  **-r** **--no-restart**                 Do not restart roles.

  **-v** **--verbose**                    Show process information when restarting roles.



----

.. _kato-command-ref-node-reset:

**node** **reset** **soft**

**node** **reset** **factory**

**node** **reset** **--help**

  Reset the Stackato VM to its default configuration.
  
  * soft: clears all data and resets the VM to its state
    immediately after first boot.
  * factory: returns the VM to its state prior to first boot.

  **-h** **--help**                       Show help information



----

.. _kato-command-ref-node-setup-core:

**node** **setup** **core** [*<endpoint>*]

**node** **setup** **core** **--help**

  Configure the core node of your Stackato cluster

  **-h** **--help**                       Show help information

  **-v** **--verbose**                    Show process information



----

.. _kato-command-ref-node-setup-firstuser:

**node** **setup** **firstuser** [**options**] *<email>*

**setup** **--help**

  First user setup.

  *<email>*                               First user's email.


  **-h** **--help**                       Show help information

  **-p** **--password** *<password>*      First user's password.

                                          If your unix password has not been updated, then

                                          your unix password will be updated to this.

                                          Will be prompted for if not given.



----

.. _kato-command-ref-node-setup-load_balancer:

**node** **setup** **load_balancer**

**node** **setup** **load_balancer** *<IP>* [*<IP>...*]

**node** **setup** **load_balancer** **--help**

  Configure this node as a HTTP/S load balancer

  **-h** **--help**                       Show help information



----

.. _kato-command-ref-node-setup-micro:

**node** **setup** **micro** [**options**] [*<role>...*]

**node** **setup** **micro** **--help**

  Configure this instance as a micro cloud

  **-h** **--help**                       Show help information

  **-d** **--delete**                     Delete old configuration and re-initialize everything

  **-s** **--no-start**                   Do not auto start processes

  **-v** **--verbose**                    Show process information



----

.. _kato-command-ref-op:

**op** **--help**

**op** **remap_hosts** *<old-hostname>* *<new-hostname>*

**op** **max_client_upload** *<max-size>*

**op** **upstream_proxy** **set** *<proxy-address>* [**-u** *<user>*] [**-p** *<pass>*]

**op** **upstream_proxy** **delete**

**op** **regenerate** **nginx**

**op** **regenerate** **mysql**

**op** **regenerate** **postgresql** [**--no-restart**]

**op** **update_hostsfile**

**op** **static_ip**

**op** **dhcp**

**op** **defer** *<command>* [**--run-as-root**] [**--reset**]

**op** **run_deferred**

  Various operational commands

  **remap_hosts**                         Change the hostname to look for when remapping

  **max_client_upload**                   Set the maximum upload size in MB

  **upstream_proxy**                      Configure Stackato to use an external or upstream proxy

                                          server

  **regenerate**                          Regenerate the configuration for a process

  **update_hostsfile**                    Updates the /etc/hosts file with the endpoint URI mapped

                                          to the CC's internal IP

  **static_ip**                           Configures this node to use a static IP

  **dhcp**                                Configures this node's networking to use DHCP

  **defer**                               Defers a kato command to be run by 'op run_deferred'

  **run_deferred**                        Runs any previously deferred kato commands


  **-h** **--help**                       Show help information

  **-u** **--user** *<user>*              Proxy username

  **-p** **--pass** *<pass>*              Proxy password

  **-r** **--no-restart**                 Do not restart processes.



----

.. _kato-command-ref-patch:

**patch** **status**

**patch** **status** **--all**

**patch** **install** [**--all**]

**patch** **install** *<patchname>*

**patch** **reset**

  Update a Stackato cluster with post-release fixes.

  **-h** **--help**                       Show help information

  **-a** **--all**                        Show status for all patches 

  **-n** **--only-this-node**             Only patch this node (otherwise entire cluster will be patched)

  **-r** **--no-restart**                 Don't restart any roles during patching



----

.. _kato-command-ref-process-list:

**process** **list** [**--help**] [**-a**] [**--node** *<node-IP>*] [*<process>...*]

  Lists configured processes and their current running status.

  **-h** **--help**                       Show help information

  **-n** **--node** *<node-IP>*           Get status for a specific cluster node (defaults to local node)

  **-a** **--all**                        Include status of all cluster nodes



----

.. _kato-command-ref-process-ready:

**process** **ready** [**options**] *<process>*

  **-h** **--help**                       Show help information

  **-b** **--block** *<seconds>*          Block until ready, for max <seconds> seconds.

                                          If <seconds> is 0, then block forever

  **-n** **--node** *<node-IP>*           Check process on a specific cluster node



----

.. _kato-command-ref-process-restart:

**process** **restart** [**options**] [*<process>...*]

  **-h** **--help**                       Show help information

  **-n** **--node** *<node-IP>*           Restart process on a specific cluster node



----

.. _kato-command-ref-process-start:

**process** **start** [**options**] [*<process>...*]

  **-h** **--help**                       Show help information

  **-n** **--node** *<node-IP>*           Start process on a specific cluster node



----

.. _kato-command-ref-process-stop:

**process** **stop** [**options**] [*<process>...*]

  **-h** **--help**                       Show help information

  **-n** **--node** *<node-IP>*           Stop process on a specific cluster node



----

.. _kato-command-ref-relocate:

**relocate** [**-h**] **containers** *<new_location>*

**relocate** [**-h**] **droplets** *<new_location>*

**relocate** [**-h**] **services** *<new_location>*

  Move containers, application droplets, or services to a new mount point
  or filesystem location.

  **-h** **--help**                       Show help information



----

.. _kato-command-ref-report:

**report**

**report** **--node** *<node-IP>*

**report** **--all**

**report** **--help**

  Generate a report that can be sent to Stackato support.

  **-h** **--help**                       Show help information

  **-a** **--all**                        Gather reports from entire cluster into one tarball

  **-n** **--node** *<node-IP>*           Gather report from a specific cluster node



----

.. _kato-command-ref-restart:

**restart** [**options**] [*<role>...*]

**restart** **--help**

  Restart Stackato or individual roles.

  **-a** **--all**                        Also restart doozerd

  **-n** **--node** *<node-IP>*           Restart a specific cluster node

  **-v** **--verbose**                    Show process information



----

.. _kato-command-ref-role-add:

**role** **add** **--help**

**role** **add** [**-v**] [**--node** *<node-IP>*] [**--no-start**] *<role>...*

**role** **add** [**-v**] [**--node** *<node-IP>*] [**--no-start**] **--all**

**role** **add** [**-v**] [**--node** *<node-IP>*] [**--no-start**] **--all-but** *<role>...*

**role** **add** [**-v**] [**--node** *<node-IP>*] **--only** *<role>...*

  Enable roles on a node

  **-h** **--help**                       Show help information

  **-a** **--all**                        Enable all available roles

  **-b** **--all-but**                    Enable all available roles except these

  **-o** **--only**                       Enable only these roles, while disabling others

  **-n** **--node** *<node-IP>*           Add a role on a specific cluster node

  **-s** **--no-start**                   Do not start processes

  **-v** **--verbose**                    Show process information



----

.. _kato-command-ref-role-remove:

**role** **remove** **--help**

**role** **remove** [**-v**] [**--node** *<node-IP>*] [**--no-stop**] *<role>...*

**role** **remove** [**-v**] [**--node** *<node-IP>*] [**--no-stop**] **--all**

**role** **remove** [**-v**] [**--node** *<node-IP>*] [**--no-stop**] **--all-but** *<role>...*

  Disable roles for a node

  **-h** **--help**                       Show help information

  **-a** **--all**                        Disable all available roles

  **-b** **--all-but**                    Disable all available roles except these

  **-n** **--node** *<node-IP>*           Remove a role on a specific cluster node

  **-v** **--verbose**                    Show process information

  **-s** **--no-stop**                    Do not stop processes



----

.. _kato-command-ref-shell:

**shell** [**--help**]

  Interactive shell for kato

  **-h** **--help**                       Show help information



----

.. _kato-command-ref-start:

**start** [**options**] [*<role>...*]

**start** **--help**

  Start Stackato or individual roles.

  **-n** **--node** *<node-IP>*           Start a specific cluster node

  **-e** **--ephemeral**                  Try not to regenerate/modify any config items

  **-v** **--verbose**                    Show process information



----

.. _kato-command-ref-status:

**status** [**options**]

  List configured roles and their current status across the cluster.

  **-h** **--help**                       Show help information

  **-a** **--all**                        Show all roles, including roles not configured on cluster

  **-j** **--json**                       Use JSON format for displaying output.

  **-y** **--yaml**                       Use YAML format for displaying output.



----

.. _kato-command-ref-stop:

**stop** [**options**] [*<role>...*]

**stop** **--help**

  Stop Stackato or individual roles.

  **-a** **--all**                        Also stop doozerd

  **-n** **--node** *<node-IP>*           Stop a specific cluster node

  **-v** **--verbose**                    Show process information



----

.. _kato-command-ref-version:

**version** [**--help**]

  Display the version of Stackato being run.

  **-h** **--help**                       Show help information


