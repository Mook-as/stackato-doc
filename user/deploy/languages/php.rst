.. _php-index:

.. index:: PHP

PHP
===

PHP applications are supported through Apache and mod_php, and require very little configuration
to deploy.  

Deployment
----------

You will need at least two files to deploy a PHP app on Stackato: `index.php`, and `stackato.yml`.

The `stackato.yml` must specify the php as the framework type::

	framework:
		type: php

For full details on the `stackato.yml` and all possible options, see :ref:`Configuration With stackato.yml <stackato_yml>`.

Application URL
---------------

Some applications require the user to specify the APP_URL. Below is an example on how to obtain the correct urls::

  $appinfo = getenv("VCAP_APPLICATION");
  $appinfo_json = json_decode($appinfo,true);
  $admin = $appinfo_json['uris'][0];

.. _php-worker-apps:

.. include:: ../../common/deploy-worker.inc

Example
^^^^^^^
::

  name: php-app
  framework: php
  command: php worker.php
  processes:
    web: ~

.. _php-data-services:

Database Services
-----------------

DATABASE_URL
^^^^^^^^^^^^

Authentication details for your configured database services can be found in the ``$_SERVER`` variable,
under ``DATABASE_URL``. Here is an example of getting the correct credentials.

.. code-block:: php

  <?php
      $url_parts = parse_url($_SERVER['DATABASE_URL']);
      $db_name = substr( $url_parts['path'], 1 );
      $db_connection_string = $url_parts['host'] . ':' . $url_parts['port'];
      
      // ** MySQL settings from resource descriptor ** //
      echo $db_name;
      echo $url_parts['user'];
      echo $url_parts['pass'];
      echo $url_parts['host'];
      echo $url_parts['port'];
  ?>

VCAP_SERVICES
^^^^^^^^^^^^^

.. code-block:: php

  <?php
      $services = getenv("VCAP_SERVICES");
      $services_json = json_decode($services,true);
      $mysql_config = $services_json["mysql"][0]["credentials"];

      // ** MySQL settings from resource descriptor ** //
      echo $mysql_config["name"];
      echo $mysql_config["user"];
      echo $mysql_config["password"];
      echo $mysql_config["hostname"];
      echo $mysql_config["port"];
      );
  ?>

.. index:: PHP.ini

PHP.ini
-------

Additional PHP ini files will be loaded from the ``$STACKATO_APP_ROOT/apache/php/``
directory. Refer to the example below for more information.


.. index:: htaccess

.. index:: document-root

Document Root Access
--------------------

If your document root (the location of the main *index.php* file) is the
main application directory, the information stored in *stackato.yml* and
*manifest.yml* is exposed to the browser. Note that *manifest.yml* is 
generated automatically, even when you don't use *stackato.yml*.

To prevent exposing this information, you can use an *.htaccess* file in
the document root directory with the following rule::

  <filesmatch "^(manifest|stackato)\.yml$">
    order allow,deny
    deny from all
  </filesmatch>

Alternatively, move your application into a subdirectory (e.g. move
*index.php* to *www/index.php*) and explicitly set your document-root in 
*stackato.yml*::

  framework:
    document-root: www

Using the *.htaccess* file will generate an "HTTP 403 Forbidden" error
if a user tries to access the denied files. Changing the document-root
will generate an "HTTP 404 Not Found" error instead.

These techniques can be use to hide other files in your application
source tree which you do not want exposed to end users.

.. index:: PHP Sessions

.. _php-persistent-sessions-filesystem:

Persistent Sessions (PHP) 
-------------------------

One of the issues with managing a PHP application running multiple
instances is dealing with user sessions.

If your application uses a :ref:`shared filesystem service
<persistent-file-system>`, you can store user sessions there. The
following *stackato.yml* snippet creates a persistent filesystem
service, creates a directory for sessions, and writes a PHP config file
to set the path to the session directory::

  services:
    ${name}-fs: filesystem
  hooks:
    post-staging:
    - mkdir -p "$STACKATO_FILESYSTEM"/sessions
    - echo "session.save_path = $STACKATO_FILESYSTEM/sessions" > "$STACKATO_APP_ROOT"/apache/php/sessions.ini

For better performance, use a :ref:`Memcached <memcached>` service for
session storage instead::

  services:
    ${name}-cache: memcached
  hooks:
    post-staging:
    - echo "session.save_handler = memcached" > "$STACKATO_APP_ROOT"/apache/php/sessions.ini
    - echo "session.save_path = $MEMCACHE_URL" >> "$STACKATO_APP_ROOT"/apache/php/sessions.ini

