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

.. image:: ../images/ironfoundry-setup2.png
   :alt: Iron Foundry Patching setup.rb
   :class: shadow

Save and close the file, then run it with:
::

    C:\IronFoundry\Setup\IronFoundry>ruby setup.rb

You'll be prompted for the hostname of your Stackato VM (without the 'api.' prefix), the IP address and the administrator password (unused since the auto-patching code has been removed).

This is equivalent to the ``kato node attach`` command run on Stackato nodes.

.. image:: ../images/ironfoundry-setup3.png
   :alt: Iron Foundry Attaching Prompt
   :class: shadow

Once the setup script finishes, you will see "ASP.NET 4.0" under "Runtimes & Frameworks" and "MS SQL" under "Available Services" in the Features section of the Stackato Management Console.

