.. _client:

.. index:: Stackato Client

Stackato Client
===============

The ``stackato`` client is the command-line interface to Stackato. You
can use it to push application code up to the server, start and stop
applications, create data services and link them to applications, and a
number of other application management operations.

The :ref:`Command Reference <command-ref-client>` has full descriptions
of all client commands and options. These details are also available at
the command line via the ``stackato help`` command.

.. _setup-client:

Stackato Client Setup
---------------------

.. include:: ../common/client-setup.inc

Getting Help
------------

To get a list of available commands or help on a particular command::

    $ stackato help [COMMAND]

See also the :ref:`Command Reference <command-ref-client>` for a full list of commands.

.. _target-api-endpoint:

Targeting the API Endpoint
--------------------------

Before you can use the client, you must set the target URL (also known
as the API Endpoint). This tells the client where it will be pushing
applications. For example::

  $ stackato target api.stackato.example.com

For a micro cloud VM, it might be something like::

  $ stackato target api.stackato-xxxx.local

.. _client-http-proxy:

.. index:: Stackato Client - HTTP Proxy

HTTP Proxies
------------

If there is an HTTP/HTTPS proxy on your network between your client and
the Stackato API endpoint, set the following environment variables in
your shell as appropriate for your proxy:

* https_proxy (e.g. "https://yourproxy.example.com:443/")
* http_proxy (e.g. "http://yourproxy.example.com:8080/")
* http_proxy_user
* http_proxy_pass

With these set, the client will recognize these settings and route
appropriately. On Windows the client queries the Internet Settings
values so this step should not be necessary.

