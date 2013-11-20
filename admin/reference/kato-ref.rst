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

* :ref:`config <kato-command-ref-config>` Manipulate configuration values of Stackato components.
* :ref:`data <kato-command-ref-data-export>` Import or export Stackato system data to or from clusters/nodes.

  * :ref:`data export <kato-command-ref-data-export>`

  * :ref:`data import <kato-command-ref-data-import>`

  * :ref:`data users <kato-command-ref-data-users>`
* :ref:`debug <kato-command-ref-debug-configwatch>` Commands for debugging for Stackato internals.

  * :ref:`debug configwatch <kato-command-ref-debug-configwatch>`

  * :ref:`debug redis <kato-command-ref-debug-redis>`
* :ref:`history <kato-command-ref-history>` Show the kato commands that have been run
* :ref:`info <kato-command-ref-info>` Show information about this node or cluster including assigned and
* :ref:`inspect <kato-command-ref-inspect>` Detect common problems with your Stackato install using 'kato inspect'
* :ref:`log <kato-command-ref-log-stream>` Logging utilities for Stackato

  * :ref:`log drain <kato-command-ref-log-drain-add>`

  * :ref:`log stream <kato-command-ref-log-stream>`

  * :ref:`log tail <kato-command-ref-log-tail>`
* :ref:`node <kato-command-ref-node-attach>` Node management

  * :ref:`node attach <kato-command-ref-node-attach>`

  * :ref:`node detach <kato-command-ref-node-detach>`

  * :ref:`node list <kato-command-ref-node-list>`

  * :ref:`node migrate <kato-command-ref-node-migrate>`

  * :ref:`node remove <kato-command-ref-node-remove>`

  * :ref:`node rename <kato-command-ref-node-rename>`

  * :ref:`node reset <kato-command-ref-node-reset>`

  * :ref:`node retire <kato-command-ref-node-retire>`

  * :ref:`node setup <kato-command-ref-node-setup-core>`

  * :ref:`node upgrade <kato-command-ref-node-upgrade>`

  * :ref:`node version <kato-command-ref-node-version>`
* :ref:`op <kato-command-ref-op>` Various operational commands
* :ref:`patch <kato-command-ref-patch>` Update a Stackato cluster with post-release fixes.
* :ref:`process <kato-command-ref-process-list>` Start, stop, or restart individual processes. Generally not required;

  * :ref:`process list <kato-command-ref-process-list>`

  * :ref:`process ready <kato-command-ref-process-ready>`

  * :ref:`process restart <kato-command-ref-process-restart>`

  * :ref:`process start <kato-command-ref-process-start>`

  * :ref:`process stop <kato-command-ref-process-stop>`
* :ref:`relocate <kato-command-ref-relocate>` Move containers, application droplets, or services to a new mount point
* :ref:`report <kato-command-ref-report>` Generate a report that can be sent to Stackato support.
* :ref:`restart <kato-command-ref-restart>` Restart Stackato or individual roles.
* :ref:`role <kato-command-ref-role-add>` Management of node roles

  * :ref:`role add <kato-command-ref-role-add>`

  * :ref:`role info <kato-command-ref-role-info>`

  * :ref:`role remove <kato-command-ref-role-remove>`
* :ref:`shell <kato-command-ref-shell>` Interactive shell for kato
* :ref:`start <kato-command-ref-start>` Start Stackato or individual roles.
* :ref:`status <kato-command-ref-status>` List configured roles and their current status across the cluster.
* :ref:`stop <kato-command-ref-stop>` Stop Stackato or individual roles.
* :ref:`version <kato-command-ref-version>` Display the version of Stackato being run.

.. _kato-command-ref-details:

Command Usage Details
---------------------


.. _kato-command-ref-config:

**config** **get** [**options**] [*<component>*] [*<key-path>*]

**config** **set** [**options**] *<component>* *<key-path>* [*<value>*]

**config** **del** [**options**] *<component>* *<key-path>*

**config** **push** [**options**] *<component>* *<key-path>* *<value>*

**config** **pop** [**options**] *<component>* *<key-path>* *<value>*

  Manipulate configuration values of Stackato components.

  *<value>*                               If value is not given for "set", then it read from STDIN.

  *<component>*                           Can be "cluster", "local" or the name of a process.


  **-h** **--help**                       Show help information

  **-j** **--json**                       For "set", use JSON format when setting config key values.

                                          For "get", use JSON format for displaying output.

  **-y** **--yaml**                       Use YAML format when retrieving or setting config key values.

                                          YAML is the default output format.

  **-f** **--flat**                       Use a flat output format "<full-config-path> <value>"

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

  **--packages**                          Include app packages

  **--exclude-packages**                  Do not include app packages

  **--resources**                         Include the upload cache

  **--exclude-resources**                 Do not include the upload cache (default)

  **--license**                           Include the Stackato license

  **--exclude-license**                   Do not include the Stackato license

  **--db-encryption-key**                 Include the key used to encrypt the Stackato DB (recommended)

  **--exclude-db-encryption-key**         Do not include the key

  **--main-db**                           Include the cloud controller's main database

  **--exclude-main-db**                   Do not include the cloud controller's main database

  **--aok-db**                            Include AOK's database

  **--exclude-aok-db**                    Do not include AOK's database

  **--aok-config**                        Include AOK's configuration 

  **--exclude-aok-config**                Do not include AOK's configuration (default)

  **--stackato-rest-db**                  Include Stackato Rest's database

  **--exclude-stackato-rest-db**          Do not include Stackato Rest's database

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

  **--rabbit3**                           Include the RabbitMQ service

  **--exclude-rabbit3**                   Do not include the RabbitMQ service

  **--exclude-rabbit3-data**              Do not include the RabbitMQ service's data

  **--exclude-rabbit3-metadata**          Do not include the RabbitMQ service's metadata



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

  **--legacy**                            Treat import as a legacy services import (internal use only)

  **--droplets**                          Include droplets (uploaded apps)

  **--exclude-droplets**                  Do not include droplets (uploaded apps)

  **--packages**                          Include app packages

  **--exclude-packages**                  Do not include app packages

  **--resources**                         Include the upload cache

  **--exclude-resources**                 Do not include the upload cache (default)

  **--license**                           Include the Stackato license

  **--exclude-license**                   Do not include the Stackato license

  **--db-encryption-key**                 Include the key used to encrypt the Stackato DB (recommended)

  **--exclude-db-encryption-key**         Do not include the key

  **--main-db**                           Include the cloud controller's main database

  **--exclude-main-db**                   Do not include the cloud controller's main database

  **--aok-db**                            Include AOK's database

  **--exclude-aok-db**                    Do not include AOK's database

  **--aok-config**                        Include AOK's configuration 

  **--exclude-aok-config**                Do not include AOK's configuration (default)

  **--stackato-rest-db**                  Include Stackato Rest's database

  **--exclude-stackato-rest-db**          Do not include Stackato Rest's database

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

  **--rabbit3**                           Include the RabbitMQ service

  **--exclude-rabbit3**                   Do not include the RabbitMQ service

  **--exclude-rabbit3-data**              Do not include the RabbitMQ service's data

  **--exclude-rabbit3-metadata**          Do not include the RabbitMQ service's metadata



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

**debug** **configwatch** [**options**] [*<process-name>...*]

  Watch changes to cluster config

  **-d** **--dump-tree**                  Dump the config tree seen since starting

  **-s** **--no-value**                   Do not print the value of path



----


.. _kato-command-ref-debug-redis:

**debug** **redis**

  Connect to the Redis server used for cluster config via redis-cli


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
    
    # Add a drain to forward all application and system logs as json
  
    kato log drain add -f json -p apptail,systail app_sys_splunk udp://logs.splunk.com:1235/
    
    # Add a drain with a custom or named format,
    
    kato log drain add -f "{{.Name}}: {{.Text}}"  system_splunk_2 udp://logs.splunk.com:1236/
    kato log drain add -f systail-syslog  system_splunk_2 udp://logs.splunk.com:1236/
  
    # Passing custom parameters to a drain
  
    kato log drain add mydrain redis://localhost:6379 key=logdata 

  **-h** **--help**                       Show help information

  **-f** **--format** *<format>*          Message format

  **-p** **--prefix** *<prefix>*          Message key prefix; possible values: systail, event, apptail (comma-separated, no spaces)



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

  **-y** **--yaml**                       Output at YAML

  **-j** **--json**                       Output at JSON



----


.. _kato-command-ref-log-drain-status:

**log** **drain** **status** [**options**] [*<drain>...*]

  Show the status of all or specified log drains

  **-h** **--help**                       Show help information

  **-n** **--not-running**                Show only drains not running

  **-y** **--yaml**                       Output at YAML

  **-j** **--json**                       Output at JSON



----


.. _kato-command-ref-log-stream:

**log** **stream** [**options**] *<key>...*

  Examples:
  
    # stream cloud events
    
    kato log stream event
  
    # stream DEA and app log stream
    
    kato log stream systail.dea systail.stager apptail
  
    # stream system logs (equivalent to 'kato log tail')
    
    kato log stream systail

  *<key>*                                 Logyard stream key prefix (eg: systail.dea)


  **-h** **--help**                       Show help information

  **--no-color**                          Turn off color

  **--raw**                               Show unformatted logs, including logyard INFO records (skipped by default)

  **--json**                              Show the original JSON

  **--time**                              Show timestamp

  **-n** **--node** *<node-IP>*           Only show logs from a specific cluster node

  **-l** **--local**                      Only show logs from the current node



----


.. _kato-command-ref-log-tail:

**log** **tail** [**options**] [*<component>...*]

  *<component>*                           Can be a process name, role name or role group name


  **-h** **--help**                       Show help information

  **--no-color**                          Turn off color

  **--raw**                               Show unformatted logs, including logyard INFO records (skipped by default)

  **--time**                              Show timestamp

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

  **-f** **--force**                      Forces this node to attach to a core node, ignoring any version mismatches



----


.. _kato-command-ref-node-detach:

**node** **detach** [**options**]

  Detach this node from a stackato core node

  **-h** **--help**                       Show help information

  **-s** **--start**                      Automatically start processes after detaching

  **-v** **--verbose**                    Show process information when starting/stopping roles



----


.. _kato-command-ref-node-list:

**node** **list** [**options**]

  List all nodes known to this cluster

  **-h** **--help**                       Show help information

  **-j** **--json**                       Use JSON format for displaying output

  **-y** **--yaml**                       Use YAML format for displaying output



----


.. _kato-command-ref-node-migrate:

**node** **migrate** *<old-node-IP>* *<new-node-IP>*

  Migrate the node configuration from old node to a new node

  **-h** **--help**                       Show help information

  **-r** **--no-restart**                 Do not restart roles after migration



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

  **-l** **--skip-ssl-regeneration**      Skip regenerating the SSL keys

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


.. _kato-command-ref-node-retire:

**node** **retire** [**options**]

  Gracefully retires a DEA node from the cluster. New instances of the
  apps are started on other available DEAs before the retiring DEA is shut
  down. 

  **-h** **--help**                       Show help information

  **-n** **--node** *<node-id>*           Retire the specified DEA node, local node is

                                          used if not specified



----


.. _kato-command-ref-node-setup-core:

**node** **setup** **core** [*<endpoint>*]

**node** **setup** **core** **--help**

  Configure the core node of your Stackato cluster

  **-h** **--help**                       Show help information

  **-v** **--verbose**                    Show process information



----


.. _kato-command-ref-node-setup-firstuser:

**node** **setup** **firstuser** [**options**] *<email>* *<org>*

  First user setup.

  *<email>*                               First user's email.

  *<org>*                                 First user's organization.


  **-h** **--help**                       Show help information

  **-p** **--password** *<password>*      First user's password.

                                          If your unix password has not been updated, then

                                          your unix password will be updated to this.

                                          Will be prompted for if not given.

  **-u** **--username** *<username>*      First user's username.

                                          Will be the provided email if not given.



----


.. _kato-command-ref-node-setup-load_balancer:

**node** **setup** **load_balancer** [*<IP>...*] [**--force**]

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


.. _kato-command-ref-node-upgrade:

**node** **upgrade** [**options**]

  Upgrades Stackato

  **-h** **--help**                       Show help information

  **-f** **--file** *<file>*              Performs the Stackato upgrade using the local provided file. Otherwise the upgrade is

                                          gathered from the ActiveState website.

  **-n** **--node** *<node>*              Targets the provided node.

  **-v** **--version** *<version>*        The version of Stackato to upgrade to. The latest version is used if this isn't supplied.

  **--rollback**                          Rolls Stackato back to the previous version.

  **--skip-confirmation**                 Skips initial confirmation of upgrade.

  **--resume**                            Resumes an upgrade process, used internally by Kato and should only be called manually when

                                          requested.

  **-c** **--cluster**                    Targets all nodes in the cluster.

  **--status**                            Shows the status of upgrades on a node.

  **--force**                             Forces an upgrade to run.



----


.. _kato-command-ref-node-version:

**node** **version** [**options**] [*<node-IP>*]

  **-h** **--help**                       Show help information.



----


.. _kato-command-ref-op:

**op** **--help**

**op** **custom_ssl_cert** **install** *<key-path>* *<cert-path>* *<domain>* [**--wildcard-subdomains**] [**--update**]

**op** **custom_ssl_cert** **remove** *<domain>*

**op** **custom_ssl_cert** **list**

**op** **dhcp**

**op** **defer** *<command>* [**--run-as-root**] [**--reset**]

**op** **import_from_yaml_files** [**--upgrade**]

**op** **max_client_upload** *<max-size>*

**op** **regenerate** **ssl_cert**

**op** **regenerate** **mysql**

**op** **regenerate** **postgresql** [**--no-restart**]

**op** **regenerate** **stackato-rest-auth**

**op** **regenerate** **cloud-controller-client-auth**

**op** **regenerate** **token-signing-secret**

**op** **remap_hosts** *<old-hostname>* *<new-hostname>*

**op** **run_deferred**

**op** **set_timezone** [**--timezone** *<TZ>*]

**op** **static_ip** [**--no-restart**]

**op** **upstream_proxy** **set** *<proxy-address>* [**-u** *<user>*] [**-p** *<pass>*]

**op** **upstream_proxy** **delete**

**op** **update_hostsfile**

**op** **generate_service_tokens**

  Various operational commands

  **custom_ssl_cert**                     Allows admin configuration of custom SSL certificates

                                          to be used in conjunction with router2g and deployed

                                          applications.

  **dhcp**                                Configures this node's networking to use DHCP

  **defer**                               Defers a kato command to be run by 'op run_deferred'

  **max_client_upload**                   Set the maximum upload size in MB

  **regenerate**                          Regenerate the configuration for a process

  **remap_hosts**                         Change the hostname to look for when remapping

  **run_deferred**                        Runs any previously deferred kato commands

  **set_timezone**                        Change the default system timezone for the host machine

  **static_ip**                           Configures this node to use a static IP

  **upstream_proxy**                      Configure Stackato to use an external or upstream proxy

                                          server and deployed apps.

  **update_hostsfile**                    Updates the /etc/hosts file with the endpoint URI mapped

                                          to the CC's internal IP

  **generate_service_tokens**             Generates service auth tokens.


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

**patch** **update**

**patch** **reinstall** *<patchname>*

  Update a Stackato cluster with post-release fixes.

  **-h** **--help**                       Show help information

  **-a** **--all**                        Show status for all patches 

  **-n** **--only-this-node**             Only patch this node (otherwise entire cluster will be patched)

  **-r** **--no-restart**                 Don't restart any roles during patching



----


.. _kato-command-ref-process-list:

**process** **list** [**options**] [*<process>...*]

  Lists configured processes and their current running status.

  **-h** **--help**                       Show help information

  **-n** **--node** *<node-IP>*           Get status for a specific cluster node (defaults to local node)

  **-c** **--cluster**                    Includes process status over all cluster nodes

  **-j** **--json**                       Use JSON format for displaying output

  **-y** **--yaml**                       Use YAML format for displaying output



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

  **-c** **--cluster**                    Restarts process on all nodes in the cluster



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

**report** **--cluster**

**report** **--help**

  Generate a report that can be sent to Stackato support.

  **-h** **--help**                       Show help information

  **-c** **--cluster**                    Gather reports from entire cluster into one tarball

  **-n** **--node** *<node-IP>*           Gather report from a specific cluster node



----


.. _kato-command-ref-restart:

**restart** [**options**] [*<role>...*]

**restart** **--help**

  Restart Stackato or individual roles.

  **-a** **--all**                        Also restart core processes

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


.. _kato-command-ref-role-info:

**role** **info** **--help**

**role** **info** [*<role>...*]

  Display info on roles

  **-h** **--help**                       Show help information



----


.. _kato-command-ref-role-remove:

**role** **remove** **--help**

**role** **remove** [**-v**] [**--node** *<node-IP>*] *<role>...*

**role** **remove** [**-v**] [**--node** *<node-IP>*] **--all**

**role** **remove** [**-v**] [**--node** *<node-IP>*] **--all-but** *<role>...*

  Disable roles for a node

  **-h** **--help**                       Show help information

  **-a** **--all**                        Disable all available roles

  **-b** **--all-but**                    Disable all available roles except these

  **-n** **--node** *<node-IP>*           Remove a role on a specific cluster node

  **-v** **--verbose**                    Show process information



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

  **-n** **--node** *<node-IP>*           Stop a specific cluster node

  **-v** **--verbose**                    Show process information



----


.. _kato-command-ref-version:

**version** [**--help**]

  Display the version of Stackato being run.

  **-h** **--help**                       Show help information



----


.. _kato-command-ref-end:




