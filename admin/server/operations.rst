.. _server-operations:

.. index:: Server Operations

Common Server Operations
========================

Server Status
-------------

To check the status of Stackato services::

	$ kato status

This will list all the services configured to run on the VM, and whether they are running or stopped.

Starting and Stopping Services
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To control the Stackato services, use ``kato`` start, stop and restart commands::

	$ kato stop

Without any further options the operation applies to all Stackato services. To start, stop or 
restart individual services, specify them after the desired command::

	$ kato stop mysql

.. note:
	Each data service appears as two separate items in the status
	output (e.g. "mysql_gateway" and "mysql_node"). However, for
	starting and stopping use just the base name as above.

System Shutdown
^^^^^^^^^^^^^^^

To shutdown the VM, run the ``shutdown`` command as root::

	$ sudo shutdown -h now


.. index:: Set Time Zone

.. _server-operations-tz:

Setting the Time Zone
---------------------

At first boot, the time zone of the Stackato VM is set to UTC. To set
this to your local time zone, use the ``kato op set_timezone`` command.
When run without arguments, the command will prompt for time zone
selction, but the time zone can be set non-interactively with the
``--timezone`` option. For example::

  $ kato op set_timezone --timezone America/Chicago

You can also use the ``tzselect`` command to find the appropriate time
zone string for your location.


.. index:: Reset

.. index:: kato node reset

.. _server-operations-reset:

Resetting the VM
----------------

If you would like to return a Stackato VM to its original
"out-of-the-box" configuration, use the :ref:`kato node reset
<kato-command-ref-node-attach>` command. This command has two options:

* ``kato node reset factory``: Resets everything. The host will behave as it
  did on first boot (creating a new randomized hostname and starting as
  a micro cloud with no configured users). Shutdown the VM after running
  this command. The primary use for this command is to prepare a running
  VM to be cloned by removing stale data/configuration.

* ``kato node reset soft``: Resets only configuration and data, but leaves
  first boot (naming) or other state info. You would normally run this
  together with the :ref:`kato node setup <kato-command-ref-node-attach>` command.
  For example:
  
  .. parsed-literal::
    
    kato node reset soft
    kato node setup micro

.. index:: Monitoring, Server Monitoring

Monitoring The Stackato Server
------------------------------

Management Console
^^^^^^^^^^^^^^^^^^

The :ref:`Management Console <management-console>` has a Settings page
that allows an administrator to monitor the server component and
services, and restart or stop services as necessary.

New Relic
^^^^^^^^^

Please see :ref:`New Relic Server Monitoring <newrelic-server-monitoring>`.
New Relic can also be used to :ref:`monitor apps <newrelic>`.

Creating an Admin User
^^^^^^^^^^^^^^^^^^^^^^

The easiest way to add admin users to Stackato is via the Management
Console under :ref:`Users <console-users>`. The Management Console will
prompt to create the initial admin user the first time you use it.

If you do not have access to the Management Console, create a user by
logging in to the micro cloud or Core node controller via ``ssh`` or
through the VM :term:`tty console` (as the ``stackato`` user) and run
``stackato register``::

	$ stackato target api.stackato-xxxx.local
	$ stackato register superuser@example.net

Grant administrative privileges using ``kato config``::

	$ kato config push cloud_controller admins superuser@example.net
  
Subsequent new users can be added remotely with the ``stackato``
client by an admin user.

System Monitoring with Nagios
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

If Nagios is installed on your server nodes, you can use it to monitor and report resource utilization.
See the :ref:`Best Practices Guide <bestpractices-nagios>` for details.

.. _server_backup:

.. index:: Server Backup
.. index:: Import Server
.. index:: Export Server

Server Backup, Import, and Export
---------------------------------

The import and export functionality can be used to do regular backups, or to move the Stackato 
configuration from one server to another.  It is also a means of upgrading the Stackato VM without
having to install everything from the ground up.

Please see our :ref:`Best Practices <bestpractices-controller-migration>` for details on how to
:ref:`export <bestpractices-migration-export>` and :ref:`import <bestpractices-migration-import>` 
your data.
