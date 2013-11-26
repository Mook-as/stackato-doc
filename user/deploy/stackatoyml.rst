.. _stackato_yml:

.. index:: stackato.yml

Stackato.yml Options
====================

Configuration options for Stackato applications can be stored in a *stackato.yml* 
file in the top-level application directory.


The *stackato.yml* file defines **keys** and associated **values** which
the ``stackato`` client uses to set options that are otherwise passed by
the user as command arguments or answers to prompts. Other values are
used by the server to install needed packages, or run setup scripts
during the staging, post-staging, or pre-running steps in deployment.

:ref:`Key substitution <stackato_yml-key-substitution>` can be used to
insert values from one key into another.

.. note::

    *stackato.yml* options take precedence over any declared in
    :ref:`manifest.yml <manifest_yml>`. Detailed specifications for
    these configuration files can be found in the `stackato-cli source
    repository <https://github.com/ActiveState/stackato-cli/>`_:

    * `stackato.yml specification <https://github.com/ActiveState/stackato-cli/blob/master/doc/stackato.yml.txt>`__
    * `manifest.yml specification <https://github.com/ActiveState/stackato-cli/blob/master/doc/manifest.yml.txt>`__
    * `stackato.yml to manifest.yml key mappings <https://github.com/ActiveState/stackato-cli/blob/master/doc/stackato-2-manifest.txt>`__
    
The following sections describe the available keys and the values that
can be assigned to them:

.. _stackato_yml-name:

name:
^^^^^

This is the name of the application being pushed.  If not specified, the user 
will be prompted during ``stackato push`` to provide a name.  The name can also 
be specified on the command line (eg. ``stackato push currency-converter``).

Example::

  name: currency-converter
	
.. note::
    
    The application name must be a valid 
    `hostname label <http://en.wikipedia.org/wiki/Hostname#Restrictions_on_valid_host_names>`_ 
    (i.e. containing only alphanumeric characters and hyphens).
    
.. _stackato_yml-buildpack:

buildpack:
^^^^^^^^^^

The Git repository URL for the specific :ref:`buildpack <buildpacks>`
used to deploy the application. For example::

    name: java-app
    mem: 512M
    buildpack: https://github.com/heroku/heroku-buildpack-java.git

If unset, Stackato will check to see if the application triggers the
``detect`` scripts in any of its :ref:`built-in buildpacks
<buildpacks-built-in>`.

.. _stackato_yml-framework:

framework:
^^^^^^^^^^

Allows the app to specify a framework and runtime to be used. Specifying
a value for the ``framework`` key triggers the use of the :ref:`Legacy
Buildpack <buildpacks-built-in>`.

type (DEPRECATED):
~~~~~~~~~~~~~~~~~~

The framework to use.  Check ``stackato frameworks`` for a complete list of 
available frameworks. If not specified, user may be prompted during 
``stackato push``. Can also be input with the command line option --framework, 
-f (eg. ``stackato push --framework python``).

.. _stackato_yml-runtime:

runtime: (DEPRECATED)
~~~~~~~~~~~~~~~~~~~~~

The runtime to use.  Check ``stackato runtimes`` for a complete list of available 
runtimes. If not specified, server will select the best option based on available 
data.  Can also be input with the command line option --runtime, -f 
(eg. ``stackato push --runtime python32``).
	
Example::

  framework:
    type: python
    runtime: python32

.. _stackato_yml-document-root:

document-root: (DEPRECATED)
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Overrides the default document-root setting ($HOME) for the web server.

.. note::
    
    Node.js, Perl, PHP, and Python frameworks only.

Setting a deeper document root directory avoids the problem of exposing
supporting files (e.g. *stackato.yml*) over HTTP.

Example::

  framework:
    type: php
    document-root: web

The document-root must always be specified relative to $HOME (/app/app).

.. _stackato_yml-start-file:

start-file: (DEPRECATED)
~~~~~~~~~~~~~~~~~~~~~~~~

Set the main application filename.

.. note::
    
    Perl and Python frameworks only.
    

If your application does not use a conventional filename (e.g. app.psgi
for Perl, wsgi.py for Python) using this option, possibly in conjunction
with **document-root**, avoids the need to refactor the application for
Stackato. For example::
    
  framework:
    start-file: temp.psgi

Or::

  framework:
    start-file: temp.py

This value will be used by the :term:`PROCESSES_WEB` and
STACKATO_START_FILE environment variables. Any changes to
STACKATO_START_FILE at runtime will not change the value of
:term:`PROCESSES_WEB` as the macro is expanded before the pre-running
hooks are run.

.. only:: not public

   **home-dir:**
   
   The :term:`HOME` directory where all the pre-running code is run, as well as
   the HOME directory for cron and ssh sessions.  For most frameworks this
   is the ``/app/app directory``, but slightly different for
   :ref:`java deployments <java-home>`. For example::

    framework:
      type: php
      home-dir: app/web

   This allows a user-override via framework:home-dir in stackato.yml, 
   althought this shouldn't really be necessary. The home-dir must 
   always be specified relative to $STACKATO_APP_ROOT (/app).


.. _stackato_yml-app-dir:

app-dir
^^^^^^^

The directory containing the application code to be pushed to Stackato
(if it's not in the top-level directory). This directory becomes the
$HOME directory of the application when the application is pushed to
Stackato. For example, Java applications will often have a 'target'
sub-directory containing the output of ant or mvn builds::

  name: sample
  framework:
    type: java_web
    runtime: java7
  app-dir: target

If required, you can also set :ref:`document-root
<stackato_yml-document-root>` in the :ref:`framework
<stackato_yml-framework>` section to specify a sub-directory of the
application $HOME to be used as the document root.

To launch multiple applications from multiple sub-directories use a
:ref:`manifest.yml <manifest_yml>` file.

.. _stackato_yml-services:

services:
^^^^^^^^^

A list of services to create and bind to the application.  Each sub key is the 
name of the service to create / bind, and the associated value is the type of 
the new service.  If multiple services of the same type are needed, list them on 
separate lines as in the example below.

Use ``stackato services`` for a complete list of available services.  If not 
specified, the user may be prompted during ``stackato push``.

Example::

  services:
    customerdb: mysql
    paymentsdb: mysql

The Stackato client supports :ref:`key substitution
<stackato_yml-key-substitution>` for service names, allowing you to
create service names based on the specified application name. For
example::

  services:
    ${name}-db: mysql

The application name can be set as an option to the :ref:`stackato push
<command-push>` command, overriding the **name** value defined in
*stackato.yml*. Use this technique when pushing multiple versions of the
same application (using different names) if you want them to use
separate databases. For example::

  name: sample

  framework:
    type: node
    
  services:
    ${name}-db: mysql

Using the name specified in *stackato.yml*, a data service is created to
match that name::

    $ stackato push -n
    Pushing application 'sample'...
    Framework:       node
    Runtime:         <framework-specific default>
    Application Url: sample.stackato-pjw3.local
    Creating Application [sample]: OK
    Binding service [sample-db]: OK
    ...
    Starting Application [sample]: ...OK


If you specify a new name for the application as an argument to
``stackato push``, a new service with a matching name is created rather
than binding to the existing 'sample-db' service::

    $ stackato push sample-2 -n
    Pushing application 'sample-2'...
    Framework:       node
    Runtime:         <framework-specific default>
    Application Url: sample-2.stackato-pjw3.local
    Creating Application [sample-2]: OK
    Binding service [sample-2-db]: OK
    ...
    Starting Application [sample-2]: ..OK
    
    $ stackato apps

    +-------------+---+---------+------------------------------+-------------+
    | Application | # | Health  | URLS                         | Services    |
    +-------------+---+---------+------------------------------+-------------+
    | sample      | 1 | RUNNING | sample.stackato-pjw3.local   | sample-db   |
    | sample-2    | 1 | RUNNING | sample-2.stackato-pjw3.local | sample-2-db |
    +-------------+---+---------+------------------------------+-------------+

requirements:
^^^^^^^^^^^^^

Specifies required modules, and allows the installation of additional OS packages.  

OS Packages
~~~~~~~~~~~

OS packages can be added in an ``ubuntu:`` block within a ``staging:``
and/or ``running:`` block. Plain strings are treated as package names::

  requirements:
    staging:
      ubuntu:
        - libfoo-dev
    running:
      ubuntu:
        - libfoo
        - some-app

To add the OS requirements to both the staging and running phases add
the ``ubuntu:`` block directly beneath the ``requirements:`` key::

  requirements:
    ubuntu:
      - libfoo-dev

If your account has been given sudo privileges in application
containers, you can use arrays to add additional repositories,
overriding repository restrictions set by admins.

Example::

  requirements:
    staging:
      ubuntu:
        - ["ppa:gophers/go"]
        - golang-stable
    running:
      ubuntu:
        - libfoo


Language Modules
~~~~~~~~~~~~~~~~

For the installation of language modules, replacing the *requirements.txt* file.  
For :ref:`Python <python-index>`, ``pypm:`` and ``pip:`` can be specified::

  requirements:
    pypm:
      - tornado
      - pymongo
    pip:
      - pycurl

For :ref:`Perl <perl-index>`, ``ppm:`` or ``cpan:`` can be specified::

  requirements:
    ppm:
      - CGI::Application::PSGI
      - Plack::Builder

::

  requirements:
    cpan:
      - CGI::Application::PSGI
      - Plack::Builder


.. _stackato_yml-mem:

mem:
^^^^

The amount of memory to allocate for the application.

Syntax: <int> or <int>M - Memory in megabytes. eg. 256M

Syntax: <int>G or <float>G - Memory in gigabytes. eg. 1.5G or 2G

If not specified, user may be prompted during ``stackato push``.  Can also be 
specified on the command line (eg. ``stackato push --mem 256M``).
	
Example::
	
  mem: 64M

.. _stackato_yml-disk:
	
disk:
^^^^^

The amount of disk space to allocate for the application (minimum
512MB).

Syntax: <int> or <int>M - Disk in megabytes. eg. 768M

Syntax: <int>G or <float>G - Disk in gigabytes. eg. 1.5G or 2G

If not specified, 2GB of disk space is allocated. Can also be specified
on the command line (eg. ``stackato push --disk 768M``).

Example::
	
  mem: 3.5GB
  
instances:
^^^^^^^^^^

The number of instances to allocate for the application.  If not specified, defaults 
to 1. Can be specified on the command line (eg. ``stackato push --instances 2``).
	
Example::

  instances: 2
	

.. _stackato_yml-url:

url (or urls):
^^^^^^^^^^^^^^

List of URLs mapped to the application. For example::

  name: cms-platform

  url:
    - blog.example.org
    - exampleblog.com

With this key specified, Stackato will not assign a default
"appname.paasname.com" URL to the application. If you would like this URL
assigned as well, add ``${name}.${target-base}`` to the list of URLs. 

See :ref:`Mapping App URLs <deploy-map-url>` for more information.

.. _stackato_yml-env:

env:
^^^^

A map of environment variables to initialize for the application. Each
subkey is the name of the variable, with an associated value.

Example::

  env:
    HOME_IP_ADDRESS: 127.0.0.1
	
Avoid using this for values which should not be stored in plain text,
such as API keys and passwords.

.. _stackato_yml-env-attributes:

env Attributes
~~~~~~~~~~~~~~

Each environment variable can have attributes which modify the
interactive behavior of the :ref:`stackato client <command-ref-client>`
when using the :ref:`push <command-push>` command. These attributes are
set with the following keys:

* **default** (string): The value to use if nothing is entered by the
  user interactively (no default).

* **required** (`boolean <http://yaml.org/type/bool.html>`_): If set,
  the variable must have a value (defaults to "false" == "not
  required"). 
  
* **inherit** (boolean): If set, the client looks in the local
  environment for a variable of the same name and takes its value
  (defaults to "false" == "no inheritance").
  
* **prompt** (string): The prompt to show when the client asks for the
  variable value (Defaults to "Enter <varname>:").

* **choices** (list of strings): If specified, a list of legal values
  for the variable, to be presented to the user as a menu rather than
  prompting for a string (no default).

For example::

  env:
    MY_SPECIAL_VAR:
      default: "development"
      required: y
      inherit: y
      prompt: "What type of deployment?: "
      choices:
        - "development"
        - "testing"
        - "staging"
        - "production"

Pushing with the ``--no-prompt`` option will fail with the error message
"Required variable *VAR_NAME* not set" if "required" is set but no value
is given (via "default", "inherit" or the ``--env`` option).

.. note::
    These attributes are only recognized by the :ref:`stackato client
    <command-ref-client>`.

.. only:: not public

  .. note:: **internal**:

  * hidden (boolean): If set, and the user is prompted for the value of
    the variable the user's input is shown only as \*'s. Set this for
    variables containing passwords and the like. If set "choices" (see
    below) is forbidden (defaults to "false" == "visible input").
    
    **NOTE**: Omitted from public docs because it gives a false sense of
    security. The environment variables are not actually hidden in any
    meaningful sense (e.g. are visible by admins in the Management
    Console).

  * scope: (reserved name) string. optional. One of "staging",
    "runtime", and "both". Default is "both". Specifies where the
    environment variable is visible in the backend.

    **NOTE**: This key is handled server side, and is NOT implemented
    yet (and may not be).

  The client determines the value of an environment variable FOO like this:
  
  1) Start with the value of the "default" key (note that it doesn't make
     sense to specify "required: 1" when you have a default).
  
  2) If "inherit" is true, and the variable is set in the client's
     environment, then use this value (overwriting the default).
  
  3) If the variable is mentioned in an --env option on the commandline,
     then that value takes precedence over the default and the client's
     environment.
  
  4) If we still don't have a value, but "required" is true, and push is
     given the --no-prompt option, then the client will refuse to push
     with an error message::
  
        "Required variable FOO not set"
  
  5) If the push command is running interactively, then it will prompt the
     user, providing the value selected in steps 1-4 as the default::
  
       $ FOO=foo stackato push
       Enter FOO [foo]:
  
  6) The "prompt" key above can override the standard "Enter FOO" prompt with a
  custom string. For example "Enter administrator password", etc.


.. _stackato_yml-processes:

processes:
^^^^^^^^^^

web:
~~~~

.. note:: 

  Used with the :ref:`Legacy buildpack <buildpacks-built-in>` only. When using
  other buildpacks, create a `Procfile <https://devcenter.heroku.com/articles/procfile>`__ 
  in the application's root directory.

Specify a custom command to launch your web application or to pass custom
arguments to uWSGI. For example::

  processes:
    web: python3.2 app.py

See `app.py` in:

* `bottle-py3 <https://github.com/Stackato-Apps/bottle-py3>`_
* `cherrypy-p3 <https://github.com/Stackato-Apps/cherrypy-py3>`_

This key is required when using the :ref:`generic <generic-framework>`
framework, but is optionally available for all other frameworks.

**If defined**, this process is expected to launch a HTTP server bound
to ``0.0.0.0`` host and ``$PORT`` port.

.. _stackato_yml-processes-web-null:

**If set to Null ("~")**, the application is treated as a worker application 
and not provisioned with a URL. For example, an application that just runs 
a background Perl script might look like this::

  name: 
  framework:
    type: perl
  command: perl worker.pl
  processes:
    web: ~

A 'command:' value must be present for worker applications. 

If the application exists solely to run commands via 
:ref:`cron <stackato_yml-cron>`, a dummy command such as '*sleep 365d*' should 
be specified.

The ``$PROCESSES_WEB`` and ``$STACKATO_UWSGI`` variables can also be used with 
``processes: web:``.

``$PROCESSES_WEB`` contains the command that is used to start the web 
application, if you want to override the default command.

``$STACKATO_UWSGI`` is defined for runtimes using uWSGI (Perl and Python), and 
it contains the command to start uWSGI with all relevant options.  It can be 
used if you are appending additional uWSGI options to the command.


.. _stackato_yml-command:

command:
^^^^^^^^

Used for worker applications to start a background process. Below is an example
using the :ref:`standalone <standalone-framework>` framework::

  name: stackato-worker
  instances: 1
  framework:
    type: standalone
    runtime: ruby18
  command: ruby worker.rb


.. _stackato_yml-cron:

cron:
^^^^^

Commands listed here are added to the crontab file.  See the section on 
:ref:`Crontab Support <deploy-crontab>` for details.

Example::

  cron:
    - PLUGH=xyzzy
    - "*/1 * * * * env > $HOME/env"


.. _stackato_yml-ignores:

ignores:
^^^^^^^^

A list of .gitignore-style patterns. Files and directories in the application 
directory matching at least one pattern are ignored during "push" and "update".  

Example::

  ignores: ["tmp", ".git"]

To include all hidden files or folders simply use an empty list.

Example::

  ignores: []
   
If not specified, a default list is used to exclude files and folders
not typically required in a deployed application (e.g. the dot files and
folders of various source code control systems).

The default list contains the following: ~\*/, .git/, \*.svn/, \*.hg/, \*CVS/,
_FOSSIL_.fos, \*.bzr, \*.cdv, \*.pc, \*RCS, \*SCCS,\*_MTN, \*_build, \*_darcs, \*_sgbak,
\*autom4te.cache, \*blib, \*cover_db, \*~.dep, \*~.dot, \*~.nib, \*~.plst

.. _stackato_yml-inherit:

inherit:
^^^^^^^^

This special key has the effect of treating its value as the name of a file to 
be included into *stackato.yml*.

Example:

*parent.yml*::

  env:
    COMPANY: The ABC Company

*stackato.yml*::

  name: example-app
  inherit: parent.yml
  mem: 64M

effect from processing::

  name: example-app
  env:
    COMPANY: The ABC Company
  mem: 64M

.. _stackato_yml-hooks:

hooks:
^^^^^^

Hooks are commands that are run at various point of the staging and running 
process of an app.

pre-push:
~~~~~~~~~

Commands run **on the local system** before pushing the code to
Stackato. This can be useful for building source files (e.g. with
``make``) or performing configuration steps that need to be done on the
local system before the application code can be pushed. Commands are
executed between application creation (when the URL and application
resources are reserved) and the actual upload of the local code.

The client will set the STACKATO_HOOK_ACTION variable to "create" if the
application is new, or "update" if it detects the application already
exists. You can use this variable to run hooks differently in either
context.

pre-staging:
~~~~~~~~~~~~~

A list of commands to be run in the root of the app's directory before the 
staging process is started.  The commands are only run a single time on push 
or update.

post-staging:
~~~~~~~~~~~~~

A list of commands to be run in the root of the app's directory after the 
staging process is complete.  The commands are only run a single time on push 
or update.
		
pre-running:
~~~~~~~~~~~~

A list of commands to be run in the root of the app's directory after
staging is complete and before the app is started.  The commands are run
sequentially, in the order listed, each time an app is started or
restarted.

Example::

  hooks:
    pre-staging:
      - python prestagingsetup.py    
    post-staging:
      - python manage.py syncdb --noinput
      - python manage.py migrate --noinput
    pre-running:
    - python prerunsetup.py

Hook processing ends and staging aborts if a command returns a nonzero
exit status (i.e. if the command fails). You can suppress this behavior by
prefacing the command with "-" to force staging to proceed despite
failures. The "-" must be included in a quoted command string. For
example::

  hooks:
    post-staging:
      - "-python manage.py syncdb --noinput"

Commands used in the ``hooks:`` keys may not include shell metacharacters, such 
as "&&" for combining commands, "#" for comments, "<", ">" or "|" for I/O redirection.

If you need shell functionality such as metacharacters, signal trapping,
or forcing zero exit status, wrap your command in a *script.sh* file and
use ``sh +x script.sh`` as your hook command.

Also note that if only a single command needs to be run, the list format is not 
needed and can be included on the same line::

  hooks:
    post-staging: python staging.py
    pre-running:  python running.py
	
.. _stackato_yml-version:

min_version:
^^^^^^^^^^^^

Sets requirements for the minimum version of the client and server under which 
the app will run.

client:
~~~~~~~

The minimum version of the Stackato client needed to manage the app.

To determine the client version, use::
  
  $ stackato version		

  stackato 0.3.13.0.18
	
Example::

  min_version:
    client: 0.3.13.0.18

server:
~~~~~~~

The minimum version of the Stackato server needed to run the app.

To determine the server version, use ``stackato info`` and use the version 
number shown in the first line. In this example, the version is **2.4.3**::
			
  $ stackato info

  ActiveState Stackato v2.4.3

Example::

  min_version:
    server: 2.4.3
	
.. _stackato_yml-req:


.. index:: Stackato.yml key substitution

.. _stackato_yml-key-substitution:

Key Substitution
^^^^^^^^^^^^^^^^

The value of any key in *stackato.yml* can be inserted in other keys
using the ${*key*} syntax. For example::

  name: example-app
  env:
    MY_NAME: ${name}

This defines a "MY_NAME" environment variable with the value
"example-app".

A small number of keys are predefined for your use within *stackato.yml*:

.. list-table::
   :widths: 20 80
   :header-rows: 1

   * - key substitution
     - value
   * - ${random-word}
     - A short alphanumeric string of random characters
   * - ${target-base}
     - The hostname of the targetted Stackato system, for example **stackato-xxxx.local**
   * - ${target-url}
     - The URL of the targetted API endpoint, for example **https://api.stackato-xxxx.local**

.. note::
    See the :ref:`services <stackato_yml-services>` section for an
    example of variable key substitution for yaml key names.

