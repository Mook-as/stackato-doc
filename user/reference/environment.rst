.. index:: Environment Variables
.. _environment-variables:

Environment Variables
=====================

.. only:: not public

  .. note::
  
    See here for syntax of
    `Definition Lists <http://docutils.sourceforge.net/docs/ref/rst/restructuredtext.html#definition-lists>`_.
    See here for syntax of
    `Glossary Directive <http://sphinx.pocoo.org/markup/para.html#glossary>`_.
    Due to a bug in Sphinx, this must be a leaf document with no references to labels elsewhere in the document tree.

Stackato exposes a number of predefined `environment variables
<http://manpages.ubuntu.com/manpages/man7/environ.7.html>`_
during runtime (including hook processing, cron jobs and ssh commands).

You can set your own environment variables:

* in an ``env:`` block in :ref:`stackato.yml <stackato_yml-env>`,
* via the application's Details page in the :ref:`Management Console <management-console>`, or
* using the :ref:`stackato env-add <command-env-add>` command. 

.. note::
    
    To see a complete list of environment variables in a Stackato
    application container, deploy the `node-env
    <https://github.com/Stackato-Apps/node-env>`_ sample.




.. glossary::

  DATABASE_URL
    Contains an access URL for a database service. If more than one type
    of database is present, ``DATABASE_URL`` will not be available.
    Instead, use the :ref:`Database Specific URL variables
    <database-specific-url>` below. 
    
    Example::

        mysql://u93Mm8XmGXQ9R:p8LwNeQXMrNzi@192.168.0.112:3306/d0a60c0be931f4982bbef153f993237bc

  MEMCACHE_URL
    Location of and credentials for the bound **Memcached** service, if there is (only) one.
    
  MYSQL_URL
    Location of and credentials for the bound **MySQL** service, if there is (only) one.

  POSTGRESQL_URL
    Location of and credentials for the bound **PostgreSQL** service, if there is (only) one.
    
  REDIS_URL
    Location of and credentials for the bound **Redis** service, if there is (only) one.
    
  MONGODB_URL
    Location of and credentials for the bound **MongoDB** service, if there is (only) one.
    
  RABBITMQ_URL
    Location of and credentials for the bound **RabbitMQ** service, if there is (only) one.

  HOME
    Identifies the working directory assigned to a particular user on
    login. In a Stackato application container, this is generally set to
    */home/stackato/app/* by default.

  HTTP_PROXY
    A variable recognized by many web applications to direct them to a proxy HTTP server.

  PATH
    A list of directories, separated by ":", which are to be searched for the names of executable files
    to be interpreted as commands.

  PIP_OPTS
    Custom/alternate :term:`PIP` repo location.
    See `running your own package index <http://guide.python-distribute.org/pip.html#running-your-own-package-index>`_ for more info.
    
    Example::
    
          env:
            PIP_OPTS: "--extra-index-url=http://company.com/inhouse-pypi-mirror"
  
  PORT
    Stackato alternative for VCAP_APP_PORT.
  
  PROCESSES_WEB
    This variable contains the default start command that would be used when
    :ref:`stackato.yml <stackato_yml>` doesn't override it.
    It is provided so that users can specify a wrapper around the default command, e.g.

        processes:
          web: newrelic_wrapper $PROCESSES_WEB

    Note that ``PROCESSES_WEB`` may be undefined when Stackato can't determine the
    default command (e.g. because the app uses a non-standard main application file).

  PYPM_OPTS
    Custom/alternate :term:`PyPM` repo location. Repo mirroring is sort of undocumented feature.
    Example::
    
        env:
            PYPM_OPTS: "-R http://pypm-free.activestate.com/2.7/linux-x86_64/"

  STACKATO_APP_ENV
    .. note:: Internal use, subject to change.

    Contains a list of all environment variables set with :ref:`stackato env-add <command-ref-client>`
    or :ref:`stackato.yml <stackato_yml-env>`.

  STACKATO_APP_NAME
    Contains the application name as specified during application push
    (or in *stackato.yml* or *manifest.yml*). Available during staging as
    well as in the application instance.
  
  STACKATO_APP_NAME_UPCASE
    Contains the same value as STACKATO_APP_NAME transformed to
    uppercase, with dashes replaced by underscores. For example if
    STACKATO_APP_NAME is "php-info", then STACKATO_APP_NAME_UPCASE will
    be "PHP_INFO".
    
    This makes it possible to access the environment variables for
    :ref:`harbor <port-service-env-vars>` and :ref:`filesystem
    <file-system-usage>` services.
    
  STACKATO_APP_ROOT
    This is the "root" directory from the Stackato point of view.
    It contains app specific HOME directory (app/), the log file directory
    (logs/) and various scripts.

    The :term:`HOME` environment variable will actually point to the app directory, which
    looks mostly like the directory uploaded by the client.  This is where
    *stackato.yml* and all the application files live.

  STACKATO_DOCUMENT_ROOT
    This contains the root directory where the user can access. The document-root must always be specified relative to $HOME (/home/stackato/app).

  STACKATO_FILESYSTEM
    If the app uses a single ``filesystem`` service, then the local
    mount point is stored in this variable.

    If there is more than one ``filesystem`` service, ``STACKATO_FILESYSTEM`` is not available. 
    Instead, a custom environment variable ``STACKATO_FILESYSTEM_*`` will be created based on the
    name of each filesystem service (with hyphens replaced by underscores).

    For example, if your *stackato.yml* file configures the following services::

        services:
          my-data: filesystem
          plugins: filesystem

    Two environment variables would be created:
    ``STACKATO_FILESYSTEM_MY_DATA``
    and
    ``STACKATO_FILESYSTEM_PLUGINS``.
  
  STACKATO_GROUP *(DEPRECATED: Stackato 2.x only)*
    Can be set in the local shell to specify the group
    for the ``stackato`` client. When set, the ``stackato group``
    command is ignored until the variable is explicitly unset. If empty,
    the client sets the group to 'none'. Can be overridden with the
    ``--group`` option.

  STACKATO_SERVICES
    Contains connection details and credentials for services bound to
    the application. For filesystem services, it contains the local
    mount point. See :ref:`STACKATO_SERVICES
    <database-services-stackato-services>`.

  STACKATO_TARGET
    Can be set in the local shell to specify the API endpoint target for
    the ``stackato`` client. When set, the ``stackato target`` command
    is ignored until the variable is explicitly unset. Can be overridden
    with the ``--target`` option.

  STACKATO_UWSGI
    Set by the Perl and Python frameworks only. It contains the default
    uswgi start command to run the application via uwsgi. It is provided
    in case the user wants to add additional uwsgi options in
    :ref:`stackato.yml <stackato_yml>`::

        processes:
          web: $STACKATO_UWSGI --another-uwsgi-option
  
  VCAP_APP_HOST
    This variable contains the IP address of the host that the application is running on.
    
  VCAP_APP_PORT
    This variable contains the port that the application will be exposed on.
    
  VCAP_APPLICATION
    This variable contails all relevant application details for the Stackato Application. 
    (Instance ID, App Name, App Uris, Users/Groups etc.)
  
  VCAP_SERVICES
    Contains connection details, credentials, and meta data for services
    bound to the application. See :ref:`VCAP_SERVICES
    <database-services-vcap-services>`.

