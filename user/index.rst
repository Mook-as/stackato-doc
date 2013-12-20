.. _stackato-user-guide:

Stackato User Guide
===================

`Stackato <http://www.activestate.com/cloud>`_ is a polyglot
Platform-as-a-Service (PaaS). You can easily deploy applications written
in a wide range of languages and web frameworks, using a variety of data
services simply by pushing your source code to the system.

Stackato handles the automatic configuration of the language runtime,
web server, application dependenies, databases, and other services.

Quick Start
-----------

.. toctree::
  :maxdepth: 2

  quick-start/index

Stackato Client
---------------

.. toctree::
   :maxdepth: 2

   client/index
   
.. toctree::
   :maxdepth: 1
   
   reference/client-ref
  
Deploying Applications
----------------------

.. toctree::
  :maxdepth: 1

  deploy/index
  deploy/stackatoyml
  deploy/manifestyml
  deploy/app-debug

* :ref:`Languages & Frameworks <language-specific-deploy>`

  .. toctree::
    :maxdepth: 1
     
    deploy/orgs-spaces
    deploy/buildpack
    deploy/other-frameworks
    deploy/languages/clojure
    deploy/languages/go
    deploy/languages/java
    deploy/languages/node
    deploy/languages/perl/index
    deploy/languages/php
    deploy/languages/python/index
    deploy/languages/ruby

Services
--------

.. toctree::
   :maxdepth: 1
   
   services/data-services
   services/filesystem
   services/memcached
   services/port-service
   services/user-provided

Logging & Monitoring
--------------------

.. toctree::
  :maxdepth: 1

  deploy/app-logs
  deploy/newrelic


Management Console
------------------

.. toctree::
   :maxdepth: 2

   console/index

Reference
---------

.. toctree::
   :maxdepth: 1

   reference/environment
   reference/glossary
   reference/troubleshoot
   reference/api

* `FAQ <http://community.activestate.com/faq-list?tid=453>`__
* :ref:`genindex`
* :ref:`search`

