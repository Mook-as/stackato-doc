.. index:: Generic
.. index:: Standalone

.. _generic-standalone:

Generic & Standalone Frameworks
===============================

The Generic and Standalone frameworks are for applications that might
not fit any of the other frameworks available in Stackato. 

* **Generic** is for web applications.
* **Standalone** is for background applications without an HTTP interface.

These two frameworks make no assumptions about the application type, and
can be customized to run a wide variety of non-standard applications.

Any language :ref:`runtime <stackato_yml-runtime>` available on the
server can be specified in the config file. If a runtime is not
specified, Python 2.7 is made available by default.

.. _generic-framework:

Generic
-------

The Generic framework requires a custom :ref:`processes: web:
<stackato_yml-processes>` setting in *stackato.yml* specifying a 
command to start the web process (e.g. a custom web server).

The example below shows a web process that serves static files from the
application directory using Python's `SimpleHTTPServer
<http://docs.python.org/2/library/simplehttpserver.html>`__::

    framework:
        type: generic
    processes:
        web: python -m SimpleHTTPServer $PORT

If you wish to run an application *without* a web interface (i.e. a
background "worker" process), :ref:`set 'processes: web:' to Null
<stackato_yml-processes-web-null>` or use the Standalone framework
instead.

.. _standalone-framework:

Standalone
----------

The Standalone framework uses a custom command specified in the
:ref:`command: <stackato_yml-command>` key to start a background worker
process. 

The example below shows *stackato.yml* configuration for an application
running a simple Ruby worker.
::

    framework:
        type: standalone
        runtime: ruby18
    command: ruby worker.rb

The command must start a long-running child process. If this process
exits for any reason, the Health Manager will restart the application
instance.

Stackato will not assign URLs to apps deployed with the standalone
framework, as it is intended for background worker processes. The
``stackato`` client includes a heuristic that will automatically
suppress the mapping of a URL to applications using this framework.
    
.. note::

  If the application does not serve web requests, it may appear in the
  Management Console or ``stackato apps`` command as not running. To
  verify a non-web application is actually running, use ``stackato
  logs`` or ``stackato ssh``.
