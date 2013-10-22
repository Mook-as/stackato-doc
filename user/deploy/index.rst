.. index:: Deploying Apps
.. _deploying-apps:

General Deployment
==================

The steps for deploying applications will be slightly different
depending on the application. Instructions for deploying the `Stackato
sample applications <https://github.com/Stackato-Apps>`_ can be found in
the `README.md` file of each app.

.. warning::
  In Stackato 3.0 (Cloud Foundry v2 API), application deployment is done
  primarily using :ref:`Buildpacks <buildpacks>`. A special built-in 'Legacy'
  buildpack handles Stackato v2 frameworks for existing application
  configurations.

To deploy an app to the Server VM, target the api endpoint URL with the
:ref:`stackato client <client>`::

  $ stackato target api.stackato-xxxx.local

Use the ``stackato login`` command to authenticate with your username
and password, then use the command::

	$ stackato push

The output of the push command will be something like::
	
	$ stackato push -n
	Application Url: myapp.stackato-xxxx.local
	Creating Application [myapp]: OK
	Creating mysql Service [mydb]: OK
	Binding Service [mydb]: OK
	Uploading Application [myapp]:
		Checking for available resources: OK
		Packing application: OK
		Uploading (30K): 100% OK
	Push Status: OK
	Staging Application [myapp]: OK                                          
	Starting Application [myapp]: OK 

.. _language-specific-deploy:

Language Specific Deployment
----------------------------

See each of these sections for language specific deployment details and examples:

.. toctree::
   :maxdepth: 1

   languages/aspdotnet
   languages/clojure
   languages/go
   languages/java
   languages/node
   languages/perl/index
   languages/php
   languages/python/index
   languages/ruby


.NET support via `Mono <http://www.mono-project.com/Main_Page>`_ is
available with a Stackato add-on. Contact
stackato-support@activestate.com for more information and access to the
plugin.

.. _deploy-app-config:

Configuring Your Application For Stackato
-----------------------------------------

Most applications should be able to run under Stackato with only a few changes.

**stackato.yml / manifest.yml**
	A `stackato.yml` or `manifest.yml` file should be added to the root of your application to hold
	installation details as well as setup configuration instructions for your app.
    
	:ref:`stackato.yml <stackato_yml>`

	:ref:`manifest.yml <manifest_yml>`

**Data Services**
  If you want to use Stackato's data services, your code will need to
  use the connection details provided by special environment variables
  (e.g. DATABASE_URL). The code should generally check for the existence
  of these environment variables, use them if they exist, and otherwise
  fall back to some default setting. 
	
  See the :ref:`Data Services <data-services>` section for further
  details.
	
**Environment Variables**
  A number of special environment variables are available during staging
  and runtime. These can be used in :ref:`hooks <stackato_yml-hooks>` or
  application code (for setting up databases, filesystem services, web
  server options, and cron jobs) in places where you would normally use
  hard-coded paths, credentials, or host-specific values.
  
  See the :ref:`Environment Variables <environment-variables>` section
  for a complete list.

Stackato push and update
------------------------

The :ref:`stackato push <command-push>` and :ref:`stackato update
<command-updates>` commands will prompt the user for input or use
options from the :ref:`stackato.yml <stackato_yml>` and
:ref:`manifest.yml <manifest_yml>` files. 

* stackato push: Create, push, map, and start a new application
* stackato update: Update the application bits

.. note::
    
    The application name must be a valid `hostname label
    <http://en.wikipedia.org/wiki/Hostname#Restrictions_on_valid_host_names>`_
    (i.e. containing only alphanumeric characters and hyphens).
    
The ``push`` command implicitly stages and starts the application unless
the ``--no-start`` option is used. With this option, applications are
pushed in a pre-staged, stopped state where variables can be added (e.g.
for use in staging hooks). The application can then be staged and
started with the :ref:`stackato start <command-operations>` command or
the Start button in the :ref:`Management Console <user-console-overview>`.

The client will display staging logs while pushing the application but
will generally exit before any application logs are visible. To view the
application logs, use the :ref:`stackato logs <command-logs>` command.
    
.. index:: Allowed File Types

.. _allowed-file-types:

Allowed File Types
------------------

During the push process, Stackato includes only three file types:

#. Files
#. Folders
#. Links

All other special file types are ignored.

.. _deploy-naming:

Naming and URLs
---------------

To prevent confusion or collisions, Stackato enforces uniqueness for
URLs, application names, and service names at two different levels of
scope (global and user/group):

* **URLs** (auto-generated or :ref:`manually mapped <deploy-map-url>`)
  must be globally unique, and are allocated on a "first come, first
  serve" basis.

* **Application names** must be unique within the scope of the user or
  group. Applications deployed by different users or groups can have the
  same name, but a globally unique URL must be specified during
  deployment (overriding the auto-generated URL, which would conflict).

* **Service names** must be unique within the scope of the user or
  group. The name given to a service during creation is a pointer to a
  globally unique string (i.e. the *actual* database name in the system
  as shown by STACKATO_SERVICES), so there is no possiblility of naming
  conflicts with services created by other users or groups.


.. index:: Crontab Support

.. _deploy-crontab:

Crontab Support
---------------
.. note:: 
    Cron commands are only executed on instance #0 of the app.
    
Cron commands can be provided either in a regular crontab file in the root directory of the app, or
via the ``cron:`` section in *stackato.yml* (See :ref:`stackato.yml Options <stackato_yml>`).

The ``HOME`` and ``PATH`` environment variables, as well as all variables that start with ``PERL``, 
``PYTHON``, ``STACKATO``, ``VCAP``, ``BUNDLE``, ``LEIN``, ``GEM``, ``RACK``, ``RAILS``, or ``RUBY`` 
or ``http`` are exported to the top of the crontab file.  When applicable, the following database \
related environment variables are also added: ``DATABASE_URL``, ``MYSQL_URL``, ``POSTGRESQL_URL``, 
``REDIS_URL``, ``MONGODB_URL``, and ``RABBITMQ_URL``.

This happens after the ``pre-running`` hook has executed, so any changes made by those 
commands will be included in the crontab file.

After setting up environment variables, we copy the *$HOME/crontab* file, and finally the commands 
from the ``cron:`` section in *stackato.yml*. The resulting file is stored at 
*$STACKATO_APP_ROOT/crontab*.

Whitespace & Newlines in Environment Variables
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To prevent breakage in cron, embedded newlines ("\\n") in environent
variable values will be replaced with "\\\\n" when generating the
crontab. Any leading and trailing spaces in environment variable values
are also stripped.


.. index:: Map Application Url
.. _deploy-map-url:

Mapping App URLs
----------------

Stackato automatically assigns to each application a URL made up of the
application's name and the base URL for the system. An application named
"myblog" deployed to a Stackato system at "api.stacka.to" would be given
the URL "myblog.stacka.to".

In addition to this default URL, additional URLs can be set for an
application using the :ref:`stackato map <command-map>` command. The
application will respond to requests on the mapped URL, provided a DNS
record has been set up resolving to Stackato's external IP or hostname.

For example, to map a URL to an existing application on Stackato::

	$ stackato apps
	
	+--------------+---+--------+----------------------------------+------------+
	| Application  | # | Health | URLS                             | Services   |
	+--------------+---+--------+----------------------------------+------------+
	| myapp        | 1 | 100%   | myapp.stacka.to                  |            |
	+--------------+---+--------+----------------------------------+------------+

	$ stackato map myapp mydomain.com
	
	+--------------+---+--------+----------------------------------+------------+
	| Application  | # | Health | URLS                             | Services   |
	+--------------+---+--------+----------------------------------+------------+
	| myapp        | 1 | 100%   | myapp.stacka.to                  |            |
	|              |   |        | mydomain.com                     |            |
	+--------------+---+--------+----------------------------------+------------+	

If DNS is configured correctly, requests to "mydomain.com" will resolve
transparently to "myapp.stacka.to".

.. note::

  Application URLs are allocated on a "first come, first serve" basis,
  and are reserved for the user who created the URL.

URLs can be mapped to multiple applications owned by the same user,
which can be useful for A/B testing. Stackato routes requests to the
mapped URL randomly between all available app instances.

Using the 'myapp.stacka.to' example above, you could push 'myapp-v2'
(e.g. a more recent revision) then map 'mydomain.com' to that app as
well. You can access the specific versions directly using
'myapp.stacka.to' and 'myapp-v2.stacka.to', and use 'mydomain.com' to
round robin between available instances of both versions::

  +-------------+---+---------+--------------------+-------------+
  | Application | # | Health  | URLS               | Services    |
  +-------------+---+---------+--------------------+-------------+
  | myapp       | 5 | RUNNING | myapp.stacka.to    |             |
  |             |   |         | mydomain.com       |             |
  | myapp-v2    | 1 | RUNNING | myapp-v2.stacka.to |             |
  |             |   |         | mydomain.com       |             |
  +-------------+---+---------+--------------------+-------------+

As you gain confidence with the new revision, you can increase the
number of instances of 'myapp-v2' (i.e. phasing that version into
production rather than cutting over) and eventually :ref:`unmap
<command-unmap>` 'mydomain.com' from the original 'myapp'.

Best Practices
--------------

.. _bestpractices-reducing-downtime-updates:

Reducing downtime during app updates
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Updating an app can create downtime while the new code is being staged.  URL mapping can be used
to reduce this downtime by switching between two running versions of an app.

For example, we have the ``customertracker`` app::

	$ stackato apps
	
	+-----------------+---+---------+-------------------------------------+------------+
	| Application     | # | Health  | URLS                                | Services   |
	+-----------------+---+---------+-------------------------------------+------------+
	| customertracker | 1 | RUNNING | customertracker.stackato-xxxx.local | customerdb |
	+-----------------+---+---------+-------------------------------------+------------+

The first time you do this, map a new URL to the existing app to ensure it continues to run once
the main URL has been remapped (for future updates you will already have two)::

	$ stackato map customertracker customertracker1.stackato-xxxx.local

Push the updated code with a new application name::

	$ stackato push customertracker2
	
	...
	
	$ stackato apps

	+------------------+---+---------+--------------------------------------+------------+
	| Application      | # | Health  | URLS                                 | Services   |
	+------------------+---+---------+--------------------------------------+------------+
	| customertracker  | 1 | RUNNING | customertracker.stackato-xxxx.local  | customerdb |
	|                  |   |         | customertracker1.stackato-xxxx.local |            |
	| customertracker2 | 1 | RUNNING | customertracker2.stackato-xxxx.local | customerdb |
	+------------------+---+---------+--------------------------------------+------------+

Note that the configured service(s) should be named the same, which will be automatically connected 
to the existing service(s).

Next, unmap the URL from the current app::

	$ stackato unmap customertracker customertracker.stackato-xxxx.local
	
And immediately map it to the new app::	
	
	$ stackato map customertracker2 customertracker.stackato-xxxx.local

	$ stackato apps
	
	+------------------+---+---------+--------------------------------------+------------+
	| Application      | # | Health  | URLS                                 | Services   |
	+------------------+---+---------+--------------------------------------+------------+
	| customertracker  | 1 | RUNNING | customertracker1.stackato-xxxx.local | customerdb |
	| customertracker2 | 1 | RUNNING | customertracker.stackato-xxxx.local  | customerdb |
	|                  |   |         | customertracker2.stackato-xxxx.local |            |
	+------------------+---+---------+--------------------------------------+------------+

Lastly, delete the old app::

	$ stackato delete customertracker

	$ stackato apps
	
	+------------------+---+---------+--------------------------------------+------------+
	| Application      | # | Health  | URLS                                 | Services   |
	+------------------+---+---------+--------------------------------------+------------+
	| customertracker2 | 1 | RUNNING | customertracker.stackato-xxxx.local  | customerdb |
	|                  |   |         | customertracker2.stackato-xxxx.local |            |
	+------------------+---+---------+--------------------------------------+------------+

.. _bestpractices-manage-multiple-targets:

Managing Multiple Targets
^^^^^^^^^^^^^^^^^^^^^^^^^

The Stackato client targets a single location with the command
``stackato target``.

If you need to target two or more instances at the same time, use one of
the following methods:

1. Use the ``--target <target>`` option. This sets the specified target
   for the current command only, and does not set it as the default::
	
    $ stackato apps --target api.stackato-xxx1.local
  

2. Use two or more terminals to access multiple targets. Within each
   terminal, set the ``STACKATO_TARGET`` environment variable for the
   API endpoint URL you want to work with in that terminal. The client
   will use this URL, overriding any target set with the ``stackato
   target`` command::
	
    $ export STACKATO_TARGET='api.stackato-xxx2.local'

  This target is used until the variable is unset or the terminal is closed. To unset it::
	
    $ unset STACKATO_TARGET


.. index:: Persistent Sessions
.. index:: Session Persistence
.. index:: Sticky Sessions

.. _persistent-sessions:

Persistent Sessions
-------------------

With multi-instance applications on Stackato, the Router will distribute
requests among all instances. Without session management, the end user
could access different application instances with each HTTP request
instead of connecting to the same instance that started their session.

Cloud-enabled applications should use a shared database (e.g. Redis),
cache (e.g. Memcached), or filesystem as a back end for session
management. Some examples of this approach are:

* Java:

  * `Tomcat session manager <http://tomcat.apache.org/tomcat-6.0-doc/config/manager.html>`__
  * `memcached-session-manager <http://code.google.com/p/memcached-session-manager/>`__
  * `tomcat-redis-session-manager <https://github.com/jcoleman/tomcat-redis-session-manager>`__

* Node.js: `connect-memcached
  <https://github.com/balor/connect-memcached#connect-memcached>`__, a
  session store that uses Memcached
  
* PHP:

  * :ref:`Persistent Sessions (PHP) <php-persistent-sessions-filesystem>`
  * `Memcached session support <http://php.net/manual/en/memcached.sessions.php>`__

* Python: `Django "How to use sessions" <https://docs.djangoproject.com/en/dev/topics/http/sessions/>`__

Stackato's default router does no special handling of ``JSESSIONID`` or
``SESSIONID`` cookies.

