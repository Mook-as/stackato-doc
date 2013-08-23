.. _aspdotnet-index:

.. index:: ASP.NET

ASP.NET
=======

If ASP.NET is available on your Stackato PaaS, it will appear in the
``stackato frameworks`` command output or in the Management Console's
Features page.

.. _aspdotnet-deploy:

Deployment
----------

Use framework ``aspdotnet`` for application deployments. For example:
::

    name: blogengine
    mem: 512M
    framework:
        type: aspdotnet

.. _aspdotnet-mssql:

MS SQL Data Service
-------------------

The Iron Foundry VM exposes a MS SQL data service. To use it, request an ``mssql`` service in *stackato.yml*, *manifest.yml*, or when prompted by the client. For example:
::

    services:
        blogengine-db: mssql
        
A ``connectionString`` attribute for this data service will be added to
the *Web.config* file during application staging. You can view the
contents of this file with the command:

.. parsed-literal::

  stackato files *appname* app/Web.config

.. _aspdotnet-sample:

Example
-------

`Orchard CMS <http://orchardproject.net/>`_ is an open source ASP.NET application. To try it out with Stackato, download a copy from the "Download-as-a-zip" link on the project's homepage, then unpack it in a convenient local directory. Change to the Orchard directory, then run::

  stackato push orchard

* Specify "aspdontnet" for the framework
* Give the instance the default 256M of memory
* Request an "mssql" data service when prompted to "Create services to bind to 'orchard'".

Orchard's "Get Started" wizard, does not automatically use the ``connectionString`` set in the *Web.config* file. To use the provisioned MS SQL service, retrieve the ``connectionString`` value as described above and paste it into the setup wizard.
