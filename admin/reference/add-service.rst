.. _add-service:

.. index:: Adding System Services

Adding System Services
======================

Stackato has two Service definitions:

* System Services: Service types (e.g. MySQL, RabbitMQ, Filesystem) available for use on the system
* Provisioned Services: Instances of the System Services created for end user applications

The :ref:`stackato services <command-services>` command will show a list
of all System Services available on the current target, as well as a
list of Provisioned Services allocated to the authenticated user.

Administrators can configure external data services to work in the same
way as core Stackato System Services, exposing existing sofware and
infrastructure for use by Stackato and its users.

Echo service sample
-------------------

A simple Ruby echo service is available in this repository:

  `<https://github.com/ActiveState/stackato-echoservice>`_
  
.. warning::
  The current echo service sample is a Stackato v2 / Cloud Foundry v1
  service. A replacement example is under development which will use the
  Cloud Foundry v2 services API.
  
The configuration files and instructions can be adapted (with reference
to the built-in system services) to create and install more complex
services to Stackato.


.. _oracle-db:

Oracle Database Add-On
----------------------

An Oracle database service add-on is available from ActiveState. It can
be added to a Stackato system to allow end users to automatically
provision databases for end user applications on an exsisting Oracle
Database server. Contact sales@activestate.com to get access to this
add-on.

This add-on can be installed on any node in a Stackato cluster, but
should generally run on a Data Services node for consistency even
though the Oracle Database server itself will generally be running on a
separate host.

Two of the configuration steps must also be run on other nodes in the
cluster (noted below) unless the nodes have been created from copies of
the VM already configured with this plugin.

Oracle Pre-requisites
^^^^^^^^^^^^^^^^^^^^^

The add-on requires the Oracle Instant Client (Basic Instant Client
Package and SDK) on the target VM. The packages can be obtained from the
`Oracle Technology Network
<http://www.oracle.com/technetwork/database/features/instant-client/index-097480.html>`__.

On the target VM, create a new */opt/oracle* directory owned by the
``stackato`` user. Copy the *instantclient-basic-linux.x64* and
*instantclient-sdk-linux.x64* files to the target VM and unzip them in
the new */opt/oracle/* directory. 

You may need to symlink a shared object for the oci8 gem to function
correctly. For example::

  $ cd /opt/oracle/instantclient_11_2
  $ ln -s libclntsh.so.11.1 libclntsh.so
  
Repeat this step on all DEA nodes in the cluster.

.. note::
  Version 11 of SQLPlus/InstantClient requires the 'libaio-dev' package,
  which is installed on the Stackato VM but not in the application
  container template (as of 2.10.6). Users can install this package by
  adding the following to *stackato.yml*::
  
    requirements:
      running:
        ubuntu:
          - libaio-dev
  
  Admins can modify the container template globally using::
  
    $ sudo chroot /lxc/template/rootfs
    ...
    $ apt-get install libaio-dev



Copying the Add-on to Stackato
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Copy the Oracle Database archive to the target VM and unzip it into
*/s/vcap/services/oracledb*. For example::

  $ scp oracledb.zip stackato@stackato-vm.example.com
  $ ssh stackato@stackato-vm.example.com
  ...
  $ unzip oracledb.zip -d /s/vcap/services/oracledb

Install the service gems
^^^^^^^^^^^^^^^^^^^^^^^^

On the VM, go to the */s/vcap/services/oracledb* directory and run
``bundle update``::

  $ cd /s/vcap/services/oracledb
  $ env LD_LIBRARY_PATH=/opt/oracle/instantclient_11_2 bundle update

Some settings in the *config/oracledb_gateway.yml* file will need to be
modified::

* **cloud_controller_uri**: Needs to match the API endpoint of your system (e.g. api.stackato.example.com)
* **token**: Can be any string. You will need to add this auth token to the cloud_controller_ng config in a later step
* **mbus**: This should match the setting for other services. You can check the correct setting using ``kato config get redis_node mbus``

Set the credentials for the external Oracle database in
`config/oracledb_node.yml`:

* **oracledb**:

  * **user**: DBA username with permissions to provision new users
  * **password**: DBA password for the above
  * **connect**: Connection string for the `OCI8 gem <https://github.com/kubo/ruby-oci8/blob/master/test/test_connstr.rb>`__
  * **host**: DB host IP
  * **port**: DB host port, default 1521
  * **database**: The Oracle service you wish to connect to
  
* **user_tablespace_max**: Maximum size in MB

You can optionally set the ``privilege`` key if you need to connect with `SYSDBA`
or `SYSOPER` privileges::

  $ kato config set oracledb_node privilege '"SYSDBA"' --json

Or::

  $ kato config set oracledb_node privilege '"SYSOPER"' --json

Install to supervisord
^^^^^^^^^^^^^^^^^^^^^^

Supervisord monitors, starts, and stops all Stackato processes, and will
need to have configuration files for the 'oracledb_gateway' and 'oracledb_node'
processes. These supervisord config files are in the *stackato-conf*
sub-directory of the add-on.

First, stop ``kato`` and ``supervisord``::

    $ kato stop
    ...
    $ stop-supervisord

Copy the supervisord config files::

  $ cp stackato-conf/oracledb_*  /s/etc/supervisord.conf.d/


Install to Kato
^^^^^^^^^^^^^^^

The 'kato' administrative tool will also need configuration to recognize
the new service. This can be done by appending the contents of
*process-snippet.yml* and *roles-snippet.yml* to their respective
``kato`` config files:

    $ cat stackato-conf/processes-snippet.yml >> /s/etc/kato/processes.yml
    $ cat stackato-conf/roles-snippet.yml >> /s/etc/kato/roles.yml

.. note::
  Repeat this step on all cluster nodes.

Optionally, you can add ``oracledb`` to the ``data-services`` group in
*role_groups.yml* or create a new logical group.

Loading the config
^^^^^^^^^^^^^^^^^^

Doozer is the centralized configuration management component in
Stackato, which must include the service configuration we have just
added. To load the settings from the YAML files in *oracledb/config/*:

First, start supervisord:

  $ start-supervisord

Run the following two commands to load the config::

  $ cat /s/vcap/services/oracledb/config/oracledb_node.yml | kato config set oracledb_node / --yaml
  $ cat /s/vcap/services/oracledb/config/oracledb_gateway.yml | kato config set oracledb_gateway / --yaml

These commands must be run after any change in the YAML config files.

Add the service AUTH token
^^^^^^^^^^^^^^^^^^^^^^^^^^

The ``auth`` token set in *config/oracledb_gateway.yml* must be added to
the cloud_controller_ng settings::

    $ kato config set cloud_controller_ng builtin_services/oracledb '{"token": "<oracledb_gateway.yml auth token>"}' --json

Replace the <oracledb_gateway.yml auth token> string above with the auth
token you set up earlier.

Enable oracledb and start
^^^^^^^^^^^^^^^^^^^^^^^^^

::

  $ kato role add oracledb
  -----> Adding roles
  adding role "oracledb"...                  ok
  -----> Starting roles
  role oracledb starting...                  ok

Finally, start all other stackato processes::

  $ kato start

Verify the service
^^^^^^^^^^^^^^^^^^

Once the oracledb service has been enabled and started in kato, clients
targeting the system should be able to see it listed in the System
Services output::

  $ stackato services

  ============== System Services ==============

  +------------+---------+------------------------------------------+
  | Service    | Version | Description                              |
  +------------+---------+------------------------------------------+
  | filesystem | 1.0     | Persistent filesystem service            |
  | harbor     | 1.0     | External port mapping service            |
  | memcached  | 1.4     | Memcached in-memory object cache service |
  | mongodb    | 2.4     | MongoDB NoSQL store                      |
  | mysql      | 5.5     | MySQL database service                   |
  | oracledb   | 1.0     | OracleDB service                         |
  | postgresql | 9.1     | PostgreSQL database service              |
  | rabbitmq   | 2.4     | RabbitMQ message queue                   |
  | redis      | 2.6     | Redis key-value store service            |
  +------------+---------+------------------------------------------+

To create a new service::

  $ stackato create-service oracledb
  Creating Service [oracledb-503db]: OK




Default tablespace
^^^^^^^^^^^^^^^^^^

The service will create a new userspace per-user at provision time to better
isolate users. A default userspace for all users can be specified by setting
the following option in kato::

    $ kato config set oracledb_node default_user_tablespace '"<tablespace>"' --json

DBshell support
^^^^^^^^^^^^^^^

End users wishing to use ``stackato dbshell`` from their local systems
with an Oracle database will need to install the `SQLPLUS client
<http://www.oracle.com/technetwork/database/features/instant-client/index-097480.html>`__
locally.

To enable dbshell Oracle support *within the application containers* on
Stackato, install the *instantclient-sqlplus-linux.x64* files alongside
the other Oracle prerequisites in the */opt/oracle/instantclient_11_2*
directory. Users can then add the instant client directory to the
LD_LIBRARY_PATH and PATH environment variables in *stackato.yml* ::

  env:
    LD_LIBRARY_PATH: "/opt/oracle/instantclient_11_2:$LD_LIBRARY_PATH"
    PATH: "/opt/oracle/instantclient_11_2:$PATH"
  services:
    ${name}-db: oracledb

The application should have a minimum of 128MB of memory to run sqlplus
and dbshell.


