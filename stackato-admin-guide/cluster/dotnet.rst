.. _aspdotnet-index:

.. index:: ASP.NET

ASP.NET
=======

ASP.NET is supported via the Iron Foundry.NET project. Iron Foundry is
an open source project that extends .NET to any Cloud Foundry-based
Platform as Service (PaaS).

.NET support via `Mono <http://www.mono-project.com/Main_Page>`_ is
available with a Stackato add-on. Contact
stackato-support@activestate.com for more information and access to the
plugin.

.. _aspdotnet-get-ironfoundry:

Getting Iron Foundry
--------------------

Download a copy of the `Micro Iron Foundry VM <http://www.ironfoundry.org/download>`_, import it into your chosen hypervisor, and boot the VM. The following setup instructions refer to this distribution.

To configure a DEA Agent .NET for use with Stackato instead, follow the directions in Iron Foundry's `DEA .NET Documentation <http://help.ironfoundry.org/entries/20815258-dea-net-documentation-v1-0>`_.

.. _aspdotnet-setup:

Initial Setup
-------------


To add an Iron Foundry DEA to a existing :ref:`Stackato Cluster <cluster-setup>`, some minor modifications are required after you boot the Micro Iron Foundry VM.

.. note:: The following editing step is required for Micro Iron Foundry version 1.4 and earlier. Subsequent releases should not require this edit to *setup.rb*.

::

    C:\IronFoundry\Setup\IronFoundry>notepad setup.rb

You'll find a section near the bottom starting with def stackato. Remove the section a few lines below starting with "print "Running patch..." and ending with "puts 'Done.'" (10 lines)

.. image:: /images/ironfoundry-setup2.png
   :alt: Iron Foundry Patching setup.rb
   :class: shadow

Save and close the file, then run it with:
::

    C:\IronFoundry\Setup\IronFoundry>ruby setup.rb

You'll be prompted for the hostname of your Stackato VM (without the 'api.' prefix), the IP address and the administrator password (unused since the auto-patching code has been removed).

This is equivalent to the ``kato node attach`` command run on Stackato nodes.

.. image:: /images/ironfoundry-setup3.png
   :alt: Iron Foundry Attaching Prompt
   :class: shadow

Once the setup script finishes, you will see "ASP.NET 4.0" under "Runtimes & Frameworks" and "MS SQL" under "Available Services" in the Features section of the Stackato Management Console.

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
