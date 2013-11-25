.. _external-db:

.. index:: External Data Services

External Data Services
======================

Stackato comes with several data services that can be enabled on a micro
cloud or in a Stackto cluster. However, for implementations where high
availability or high performance databases are required, it's advisable
to configure Stackato to connect to an externally maintained database or
data service.

External data services can be configured at the discretion of
the administrator or service provider, but in many cases they can be set
up so that Stackato can allocate databases in the same way it does for
the built-in databases.

.. _external-db-general:

General Principles
------------------

Any application running on Stackato can connect to an external database
directly as long as the instance can route to the IP address and port of
the database server. Database connections can be hard coded in the
application without needing to make any changes to Stackato
configuration.

To automatically provision databases for applications on these external
servers, Stackato must have access to an administrator account on the
database server with permissions to create users and databases. The
credentials for this account, along with the hostname and port of the
database server, are set in the Stackato configuration (via
:ref:`kato config <kato-command-ref-config>`).

.. _external-db-mysql:

MySQL
-----

The MySQL server must be set up to allow connections over the network
(rather than just on 'localhost'). Make sure the 'bind-address' is set to
the host's IP address (or '0.0.0.0'). 

Enter the ``mysql`` shell and grant the root user privileges on all
tables. For example::

    $ GRANT ALL PRIVILEGES ON *.* TO 'root'@'10.5.120.%' IDENTIFIED BY
    '<PASSWORD>'
    WITH GRANT OPTION;
    $ FLUSH PRIVILEGES;

The ``10.5.120.%`` portion above should be in relation to the Stackato
``mysql_node`` IP address. For increased security you can create a special
'stackato' user with the same privileges as the 'root' user as an alternative
option.

Once the user is configured to accept connections from Stackato and to
create users and databases, change the configuration for 'mysql_node' in
Stackato. For example::

    $ kato config set mysql_node mysql/host 10.5.120.101
    $ kato config set mysql_node mysql/pass yourpassword
    $ kato config set mysql_node mysql/port 3306
    $ kato config set mysql_node mysql/user root

Once these have been set, restart mysql::

    $ kato restart mysql

.. _external-db-rds-mysql:

Amazon RDS for MySQL
--------------------

If you are using Stackato on Amazon EC2, you can set up the Stackato
MySQL service to use `Amazon RDS for MySQL
<http://aws.amazon.com/rds/mysql/>`__ as the database back end.

Launch the RDS instance on Amazon with a security group granting access
to the Stackato service node (or wherever the 'mysql' role will be
running). Set the host, port and credentials for the RDS instance in the
configuration for mysql_service via :ref:`kato config
<kato-command-ref-config>`, then set the ``aws_rds_compat`` option to
``true``.

For example::

  $ kato config set mysql_node mysql/host <rds-endpoint>
  $ kato config set mysql_node mysql/user <rds-username>
  $ kato config set mysql_node mysql/pass <rds-password>
  $ kato config set mysql_node mysql/port <rds-port>
  $ kato config set mysql_node aws_rds_compat true
  $ kato restart mysql


.. _external-db-postgresql:

PostgreSQL
----------

Make sure the PostgreSQL database server (version 9.1 or later) will
accept connections over the network. Edit *postgresql.conf* make sure
the 'listen_addresses' is uncommented and set to the networked interface
IP. For example::

    listen_addresses = 'localhost, 10.5.120.102'

Edit *pg_hba.conf* and make sure a line exists that allows all Stackato
instances to connect to it. For example::

    host    all   all       10.5.120.0/23   md5

Restart PostgreSQL.

Using the default 'postgres' user (or another account with the same
superuser privileges), change the configuration for 'postgresql_node' in
Stackato. For example::

    $ kato config set postgresql_node postgresql/host 10.5.120.102
    $ kato config set postgresql_node postgresql/pass yourpassword
    $ kato config set postgresql_node postgresql/port 5432
    $ kato config set postgresql_node postgresql/user postgres

Once these have been set, restart the postgresql_node process::

    $ kato restart postgresql_node

.. _external-db-troubleshoot:

Troubleshooting
---------------

The ``psql`` and ``mysql`` clients are available at the command line on
the Stackato VM. Log in to the Core node (i.e. the one running the Cloud
Controller) and test the database connection directly with the
appropriate client. For example::

    $ mysql -u stackato -p mypassword -h 10.5.120.101
    mysql> show databases;
    ...

If the basic client connection works, test database creation using the
``stackato create-service ...`` command::

    $ stackato create-service mysql
    Creating Service [mysql-24901]: OK

If there are problems, check the corresponding logs on the database
server. These are generally found in */var/log/postgresql* and */var/log/mysql*.

Logs from Stackato can be viewed with ``kato log tail``::

    $ kato log tail postgresql_node
    
