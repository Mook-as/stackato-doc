.. _router:

.. index:: Router

.. index:: router2g

Router
======

The Stackato Router role manages HTTP and HTTPS traffic between web
clients and application instances. In conjunction with the Cloud
Controller, it maps application URLs to the corresponding application
instances running in Linux containers on DEA nodes, distributing load
between multiple instances (containers) as required. 

Stackato's default router ('router2g') supports `WebSocket
<http://www.websocket.org/aboutwebsocket.html>`_ (including "wss://"
secure web sockets) and `SPDY <http://www.chromium.org/spdy>`_.

.. _router-settings:

Settings
--------

The Router is configured using :ref:`kato config
<kato-command-ref-config>`. The following settings are configurable:

* **client_inactivity_timeout**: time (in seconds) the router waits for
  idle clients (default 1200 seconds). To change this::

    $ kato config set router2g client_inactivity_timeout 2400
  
* **backend_inactivity_timeout**: time (in seconds) the router waits for
  applications to respond (default 1200 seconds). To change this::
  
    $ kato config set router2g client_inactivity_timeout 2400

* **prevent_x_spoofing** (true|false): Enable HTTP "X-" header spoofing
  prevention (default 'false'). When enabled, the router discards all X-
  headers sent by the client (e.g. X-Forwarded-For, X-Forwarded-proto,
  X-Real-IP, etc.) and replaces them with values determined by the
  router itself. Anti-spoofing features should only be set at the
  network gateway, so this option should not be enabled when routers are
  configured behind an external load balancer. To enable::
  
    $ kato config set router2g prevent_x_spoofing true --json

.. index:: WebSockets

.. _router-websockets:

WebSockets
----------

Applications using web sockets must use the VCAP_APP_PORT or PORT
:ref:`environment variables <environment-variables>` to set the default
listener port of the WebSocket server.

.. index:: SPDY

.. _router-spdy:

SPDY
----

`SPDY <http://dev.chromium.org/spdy/>`__ is a protocol developed by
Google for reducing web page load time. The router supports SPDY
versions 2 and 3. Applications can use SPDY over any HTTPS connection,
so long as the connection consumers (the application server and browser)
support it.


