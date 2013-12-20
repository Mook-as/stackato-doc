.. _data-services:
.. index:: Data Services

Data Services
=================

Intro
-----

Stackato includes a number of data services which can be bound to the
applications you deploy. These include several databases (PostgreSQL,
MySQL, MongoDB, Redis), the RabbitMQ messaging service, a
:ref:`persistent file system <persistent-file-system>` service and
:ref:`Memcached <memcached>`.

Configuring Stackato Data Services
----------------------------------

The data services your application requires need to be specified at the time your
app is pushed to the Stackato server.  This can be done in a number of ways:  

#. Specifying the required services in the *stackato.yml* file.
#. Configuring services during the ``push`` process.
#. Configuring services manually.

If you would like to use an external database system, see 
:ref:`Using External Database Services <database-external>`.

Using stackato.yml
^^^^^^^^^^^^^^^^^^

The `stackato.yml` file can hold a lot of application specific details that tell the Stackato
Client what to do without having to enter them when you run ``stackato push``.  For complete
details for the `stackato.yml` file, please see :ref:`Configuration With stackato.yml <stackato_yml>`.

A simple example::

    name: cirrus
    mem: 256M
    instances: 2
    services:
        cirrusdb: mysql

This tells the Stackato Client to request a MySQL database called ``cirrusdb``.  Possible service
types are:

* :term:`filesystem`
* :term:`memcached`
* :term:`mongodb`
* :term:`mysql`
* :term:`postgresql`
* :term:`rabbitmq`
* :term:`redis`

To access the data services once they've been created, see
:ref:`Accessing Configured Database Services <database-accessing>`.

Using stackato push
^^^^^^^^^^^^^^^^^^^

If you do not specify services in the `stackato.yml` file, you will be prompted to create one
during the push process.  Should you want to set up a database service, enter "y" when asked,
and follow the prompts::

	$ stackato push
	
	...
	Would you like to bind any services to 'cirrus' ?  [yN]: y
	The following system services are available
	1. mongodb            
	2. mysql              
	3. postgresql         
	4. redis              
	5. <None of the above>
	Please select one you wish to provision: 2
	Specify the name of the service [mysql-18cab]: cirrusdb
	Creating Service: OK
	Binding Service: OK
	...

In order to ensure the correct services are configured each time the app is
pushed, your services should be listed in the `stackato.yml` file.

Creating and Binding Services
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

It is possible to create services and bind them to an app after they are pushed to the Stackato 
server.  There are two ways to do this:

**stackato create-service <service> <name> <app>**
	This combines all parameters into a single command.  ``service`` is the type of service
	you want to create (mysql, redis, postgresql, mongodb).  ``name`` is the name you want to
	assign to the service. ``app`` is the name of the application the service is to be bound to.
	
	::
	
		$ stackato create-service mysql ordersdb myapp
		Creating Service: OK
		Binding Service: OK
		Stopping Application [myapp]: OK
		Staging Application [myapp]: OK                                               
		Starting Application [myapp]: OK

		$ stackato apps
		
		+-------------+---+-------------+---------------------------+----------------+
		| Application | # | Health      | URLS                      | Services       |
		+-------------+---+-------------+---------------------------+----------------+
		| myapp       | 1 | RUNNING     | myapp.stackato-xxxx.local | ordersdb       |
		+-------------+---+-------------+---------------------------+----------------+
		
		
**create-service <service> <name>**

**bind-service <servicename> <app>**
	These two commands do the same thing as if all three parameters were passed using
	``create-service``, but it allows the flexibility of creating and perhaps configuring the
	service before binding it.
	
	``service`` is the type of service you want to create (mysql, redis, postgresql, mongodb).  
	``name`` is the name you want to assign to the service. ``servicename`` is the name assigned
	during the ``create-service`` command.  ``app`` is the name of the application the service is 
	to be bound to.
	
	::
	
		$ stackato create-service mysql customerdb
		Creating Service: OK
		
		$ stackato bind-service customerdb myapp
		Binding Service: OK
		Stopping Application [myapp]: OK
		Staging Application [myapp]: OK                                               
		Starting Application [myapp]: OK

		$ stackato apps
		
		+-------------+---+---------+---------------------------+-----------------------+
		| Application | # | Health  | URLS                      | Services              |
		+-------------+---+---------+---------------------------+-----------------------+
		| myapp       | 1 | RUNNING | myapp.stackato-xxxx.local | ordersdb, customerdb  |
		+-------------+---+---------+---------------------------+-----------------------+
	
For further information on the commands for manging services, please see the 
:ref:`stackato services <command-services>` command reference.

.. note::

  To remotely check the settings and credentials of any Stackato
  service, use the :ref:`stackato service <command-services>` command.
  
.. _database-accessing:

Using Database Services
-----------------------

When you bind a database service to an application running in Stackato,
:ref:`environment variables <environment-variables>` containing that
service's host, port, and credentials are added to the application
container. You can use these environment variables in your code to
connect to the service, rather than hard coding the details.

Examples of how to parse and use these variables can be found in the
:ref:`Language Specific Deployment <language-specific-deploy>`
section.

.. _database-database-url:

DATABASE_URL
^^^^^^^^^^^^

**If only one relational database service** is bound to an application, use the
DATABASE_URL environment variable. It contains the connection string for
the bound database in the following format::
 
  protocol://username:password@host:port/database_name
  
For example, a DATABASE_URL for a PostgreSQL service would look like this::

  postgres://u65b0afbc8f8f4a1192b73e8d0eb38a24:p9eb83c11c59c4bcabfa475a4871e9242@192.168.69.117:5432/da17e48ddc82848499cb387bc65f5d4f9 

The "protocol" portion specifies the type of database. For example:

* mysql://
* postgresql://

.. note::
  The "database name" portion of the URL is the *actual* database name
  (e.g. "da17e48ddc82848499cb387bc65f5d4f9"), not the user-specific
  service name set during deployment/service creation (e.g. "myapp-db").

.. _database-specific-url:

Database-Specific URLs
^^^^^^^^^^^^^^^^^^^^^^

**If a non-relational data service type** is bound to the
application, use the corresponding named environment variable:

* MONGODB_URL 
* REDIS_URL
* RABBITMQ_URL

**If more than one relational database service type** is bound to the
application (e.g. MySQL and PostgreSQL), the DATABASE_URL variable will
not be set but the following database-specific variables will:

* MYSQL_URL
* POSTGRESQL_URL
* ORACLE_URL (with Oracle Database add-on)

These have the same format as DATABASE_URL.

**If more than one database of the same type** is bound to the
application (e.g. two MongoDB services), none of the URL formatted
environment variables will be available. Use STACKATO_SERVICES or
VCAP_SERVICES instead.

.. _database-services-stackato-services:

STACKATO_SERVICES
^^^^^^^^^^^^^^^^^

Contains a JSON string listing the credentials for all bound services,
grouped by service name. For example::

	{
		"postdb": {
			"name": "d4854a20e5854464891dbd56c08c440d9",
			"host": "192.168.0.112",
			"hostname": "192.168.0.112",
			"port": 5432,
			"user": "u74499595373c4bea84be2a87c2089101",
			"username": "u74499595373c4bea84be2a87c2089101",
			"password": "pdbbe19398c5a4463bba0644f7798f1f1"
		},
		"mydb": {
			"name": "d0a60c0be931f4982bbef153f993237bc",
			"hostname": "192.168.0.112",
			"host": "192.168.0.112",
			"port": 3306,
			"user": "u93Mm8XmGXQ9R",
			"username": "u93Mm8XmGXQ9R",
			"password": "p8LwNeQXMrNzi"
		}
	}

.. _database-services-vcap-services:

VCAP_SERVICES
^^^^^^^^^^^^^

Contains a JSON string listing the credentials for all bound services,
grouped by service type. For example::

	{
		"mysql": [
			{
				"name": "mydb",
				"label": "mysql-5.5",
				"plan": "free",
				"tags": [
					"mysql",
					"mysql-5.5",
					"relational"
				],
				"credentials": {
					"name": "d0a60c0be931f4982bbef153f993237bc",
					"hostname": "192.168.0.112",
					"host": "192.168.0.112",
					"port": 3306,
					"user": "u93Mm8XmGXQ9R",
					"username": "u93Mm8XmGXQ9R",
					"password": "p8LwNeQXMrNzi"
				}
			}
		]
	}

This variable contains some additional meta-information, and can be used
for compatibility with Cloud Foundry.

.. note::
    
    VCAP_SERVICES variables in Stackato v2.2 and later use non-versioned
    service names The version number remains in 'label' key.

.. index:: 
	pair: Databases; External Databases
.. _database-external:

Using External Databases
------------------------

Applications running in Stackato can use external databases by
hard-coding the host and credentials, or by specifying the them in a
custom environment variable.

.. _migrating-db-connections:

Hard-coded Database Connections
-------------------------------

Applications which write database connection details during staging
rather than taking them from environment variables at run time, must be
re-staged (e.g. redeployed or updated) to pick up the new service
location and credentials. Restarting the application will not
automatically force restaging.

.. _database-accessing-services:

Accessing Database Services
---------------------------

You may need to connect to a database service directly for purposes of
initial database setup, modifying fields, running queries, or doing
backups. These operations can be done using the ``dbshell`` (preferred)
or ``tunnel`` commands. 

.. index:: dbshell

Using dbshell
^^^^^^^^^^^^^

The ``stackato dbshell`` command creates an SSH tunnel to database
services. To open an interactive shell to a service::

	$ stackato dbshell <application_name> <service_name>
	
The command will automatically open the appropriate database client for
the database you're connecting to, provided that client is installed on
the local system.

It is also available inside application containers, providing a quick
way to import data from dump files, or setting up schemas. For example,
to import data from file in an application directory, you could use a
hook in *stackato.yml* such as::

  hooks:
    post-staging:
      - dbshell < setup/sample-data.sql


.. _database-tunnel:

.. index:: tunnel

Using Tunnel
^^^^^^^^^^^^

The ``stackato tunnel`` command is an alternative method for accessing
database services. The command creates a small Ruby application which
proxies database requests over HTTP. This is the standard method for
database access in Cloud Foundry, but tends to be slower than using
``dbshell``:

To create or use a tunnel::

	$ stackato tunnel <servicename>

Depending on the service you are connecting to, a list of options will be provided.  Here is an
example of connecting to a MySQL service::

	$ stackato tunnel mydb
	
	Getting tunnel url: OK, at https://tunnel-xxxxx.stackato-xxxx.local
	Getting tunnel connection info: OK
	
	Service connection info: 
	+----------+-----------------------------------+
	| Key      | Value                             |
	+----------+-----------------------------------+
	| username | uT9efVVFCk                        |
	| password | pHFitpIU1z                        |
	| name     | d5eb2468f70ef4997b1514da1972      |
	+----------+-----------------------------------+
	
	1. none     
	2. mysql    
	3. mysqldump
	Which client would you like to start?

For simple command line access, select option **2. mysql**.

To get a dump of the entire database, select option **3. mysqldump**.  You will be prompted to enter
a path to where the dump will be saved to.

If you want to connect with a database viewer, or run multiple commands from the command line,
passing in SQL files, select option **1. none**.  This will set up a port for you to connect with
locally::
	
	1. none     
	2. mysql    
	3. mysqldump
	
	Which client would you like to start? **none**
	
	Starting tunnel to remarks on port 10000.
	Open another shell to run command-line clients or
	use a UI tool to connect using the displayed information.
	Press Ctrl-C to exit...
	
You how have all the information you need to access the data.  Notice the "Service connection info" 
box above that tells you your username, password, and the database name.

Open a new command line window.  You can connect to the MySQL database directly with::

	$ mysql --protocol=TCP --host=localhost --port=10000 --user=<user> --password=<password> <name>

	example:
	
	$ mysql --protocol=TCP --host=localhost --port=10000 --user=uT9efVVFCk --password=pHFitpIU1z d5eb2468f70ef4997b1514da1972

To import an SQL file, call the same command, and pipe in the file::

	$ mysql --protocol=TCP --host=localhost --port=10000 --user=<user> --password=<pass> <name> < mydatabase.sql

To pull a dump of all databases::

	$ mysqldump -A --protocol=TCP --port=10000 --host=localhost --user=<user> --password=<pass>


.. _bestpractices-pre-populating-database:

Pre-populating a database while pushing an app
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

When a database needs to be populated with data the first time it is run, it can be done by the
use of a hook during the staging process.  This can be accomplished in two steps.

First, create a script file in the app's root directory that uses the same data source variables 
from STACKATO_SERVICES as the ones being used in the app.  This file will open a connection to the 
database, create tables, and insert records as necessary, as in this Perl example:

.. code-block:: perl

    use strict;
    use warnings;

    use DBI;
    use DBD::mysql;
    use JSON "decode_json";

    my $services = decode_json($ENV{STACKATO_SERVICES});
    my $credentials = $services->{mydb};

    my $dbh = DBI->connect("DBI:mysql:database=$credentials->{name};hostname=$credentials->{hostname};port=$credentials->{port};",
                           $credentials->{'user'}, $credentials->{'password'})
        or die "Unable to connect: $DBI::errstr\n";

    my $sql_init =
        'CREATE TABLE customers (
                        id INT(11) AUTO_INCREMENT PRIMARY KEY,
                        customername TEXT,
                        created DATETIME
                );
        ';
    $dbh->do($sql_init);

    $sql_init =
                'INSERT INTO customers
                        (customername, created)
                VALUES
                        ("John Doe", now()),
                        ("Sarah Smith", now());
        ';
    $dbh->do($sql_init);

    $dbh->disconnect;

Next, modify your *stackato.yml* file to make use of the ``post-staging`` hook which will execute
a command to run the script::
        
        name: customertracker
        services:
          mysql: customerdb     
        hooks:
          post-staging: perl preload.pl

With those changes, the data from your script will be executed after the staging process is 
complete but before the app starts to run.


.. _bestpractices-backing-up-mysql:

.. index:: MySQL Backup

Backing up a MySQL database
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Using stackato run
~~~~~~~~~~~~~~~~~~

To export a MySQL database, use the ``stackato run`` command to remotely
execute the dbexport tool:

.. parsed-literal::

  $ stackato run [*application-name*] dbexport *service-name* > dumpfile.sql

This will run a ``dbexport`` of the named data service remotely and
direct the output to a local file. If run from a directory containing
the stackato.yml file, the application name may be omitted.

Using stackato tunnel
~~~~~~~~~~~~~~~~~~~~~

.. note::
  This method of database backup is available for compatibility with Cloud
  Foundry. It tends to be slower than using ``stackato run ...``.

To back up a MySQL database, use the :ref:`tunnel <database-tunnel>`
command to make a connection to the server and export the data using
``mysqldump``.

Use the ``tunnel`` command to access the service (in this example a MySQL database named ``customerdb``)::

	$ stackato tunnel customerdb
	
	Password: ********
	Getting tunnel url: OK, at https://tunnel-xxxxx.stackato-xxxx.local
	Getting tunnel connection info: OK
	
	Service connection info: 
	+----------+-----------------------------------+
	| Key      | Value                             |
	+----------+-----------------------------------+
	| username | uT9efVVFCk                        |
	| password | pHFitpIU1z                        |
	| name     | d5eb2468f70ef4997b1514da1972      |
	+----------+-----------------------------------+
	
	1. none     
	2. mysql    
	3. mysqldump
	Which client would you like to start?

Select option **3. mysqldump**.  You will be prompted to enter a path to where the dump will be saved.

See the :ref:`tunnel <database-tunnel>` command documentation for other ways of accessing a MySQL
database.  See :ref:`Importing a MySQL database <bestpractices-importing-mysql>` for details on
importing a file created by mysqldump into an existing MySQL database service.

.. _bestpractices-importing-mysql:

.. index:: MySQL Import

Importing a MySQL database
^^^^^^^^^^^^^^^^^^^^^^^^^^

Using stackato run
~~~~~~~~~~~~~~~~~~

To import a MySQL database, use the ``stackato dbshell`` command:

.. parsed-literal::

  $ stackato dbshell [application name] [service name] < dumpfile.sql
  
This command redirects the contents of a local database dump file to the
appropriate database client running in the application instance (i.e.
equivalent to ``stackato run dbshell ...``). If run from a directory
containing the *stackato.yml* file, the application and service names
may be omitted.

Using stackato tunnel
~~~~~~~~~~~~~~~~~~~~~

.. note::
  This method of database import is available for compatibility with Cloud
  Foundry. It tends to be slower than using ``stackato run ...``.
  
To import data from a ``mysqldump`` into an existing MySQL database service, use the ``tunnel`` command::

	$ stackato tunnel <servicename>
	
	Password: ********
	Getting tunnel url: OK, at https://tunnel-xxxxx.stackato-xxxx.local
	Getting tunnel connection info: OK
	
	Service connection info: 
	+----------+-----------------------------------+
	| Key      | Value                             |
	+----------+-----------------------------------+
	| username | uT9efVVFCk                        |
	| password | pHFitpIU1z                        |
	| name     | d5eb2468f70ef4997b1514da1972      |
	+----------+-----------------------------------+
	
	1. none     
	2. mysql    
	3. mysqldump
	Which client would you like to start?

Choose option **1. none** which will allow for command line access to the database.  A MySQL service
is configured on Port 10000, so open a new Terminal window to enter commands with.

Then, import an SQL file with the following command::

	$ mysql --protocol=TCP --host=localhost --port=10000 --user=<user> --password=<pass> <name> < mydatabase.sql

See the :ref:`tunnel <database-tunnel>` command documentation for other ways of accessing a MySQL
database.  See :ref:`Backing up a MySQL database <bestpractices-backing-up-mysql>` for details on
how to create a ``mysqldump`` backup that can then be imported into another database service.

.. index:: Database Version Changes

Database Version Changes
^^^^^^^^^^^^^^^^^^^^^^^^

The VCAP_SERVICES environment variable in Stackato does not include
version numbers in the service name string. This can cause problems when
migrating applications from Cloud Foundry v1 systems which reference
versioned database names in VCAP_SERVICES.

There are two application level fixes for this issue:

Method 1
~~~~~~~~

Update references to VCAP_SERVICES in the application code to exclude
version numbers. For example::

    MySQL:         'mysql-5.x' -> 'mysql'
    PostgreSQL:    'postgresql-x.x' -> 'postgresql'
    Redis:         'redis-2.x' -> 'redis'

Method 2
~~~~~~~~

Update the application code to use the DATABASE_URL environment
variable. See :ref:`database-accessing` for general information and the
following language-specific documentation:

* :ref:`Perl Data Services <perl-data-services>`
* :ref:`PHP Data Services <php-data-services>`
* :ref:`Python Data Services <python-data-services>`

The following changes to sample applications show this modification: 

* PERL: https://github.com/Stackato-Apps/bugzilla/commit/414804f3c02dab5104f048c013b8a3127e5268b2
* PYTHON: https://github.com/Stackato-Apps/django-gtd/commit/fdc7361086c5a1f9d2b10ee5e7af918e9f60b999
* PHP: https://github.com/Stackato-Apps/owncloud-core/commit/3bd87948f48910f27fa1e059e863bcf312cce5f3


.. index:: SQLite

SQLite
------

Applications can use an `SQLite database <http://www.sqlite.org/>`__ as
an alternative to Stackato database services. However, as the filesystem
of an application container is ephemeral (i.e. it is destroyed when an
application is stopped, restarted, or updated), you should always store
the SQLite file on a :ref:`Persistent File System
<persistent-file-system>` mount point to avoid losing data.

