.. _best-practices:

.. index:: Best Practices

Best Practices
==============

.. index:: Applying Updates
.. index:: Patching Stackato

.. _bestpractices-patch:

Applying Updates
----------------

Major version upgrades of Stackato require a data :ref:`migration to a
new VM or cluster <bestpractices-migration>`, but patch releases can be
applied in place using the :ref:`kato patch <kato-command-ref-patch>`
command.

To see a list of updates available from ActiveState, run the following
command on any Stackato VM::

  $ kato patch status
  
The command will list the updates available. For example::

  2 updates available to be installed.
  
  Known updates for Stackato 2.10.4:
    dea-memory-usage-reporting: Fix the reporting of stackato stats usage on the DEA end.
      severity: required
      roles affected: dea
  
    vsphere-autoscaling-fix: Fix VSphere autoscaling behavior.
      severity: required
      roles affected: controller, primary

To apply all patches to all relevant cluster nodes::

  $ kato patch install
  
To apply a particular patch, specify it by name::

  $ kato patch install dea-memory-usage-reporting

Applying patches will automatically restart all patched roles. To
prevent this, use the ``--no-restart`` option.

To apply a patch only to the local Stackato VM (not the whole cluster),
use the ``--only-this-node`` option. 


.. _bestpractices-migration:

.. _bestpractices-controller-migration:

.. index:: Server Backup and Migration

Backup, Migration and Upgrades
------------------------------

This section describes backing up Stackato data and importing it into a
new Stackato system. The export/import cycle is required for:

* backups of system data
* upgrading from one version of Stackato to the next
* moving a Stackato cluster to a new location

.. _bestpractices-migration-limitations:

Limitations
^^^^^^^^^^^

Before deciding on a backup, upgrade or migration strategy, it's
important to understand what data the Stackato system can save, and what
may have to be reset, redeployed, or reconfigured. This is especially
important when migrating to a new cluster.

.. _bestpractices-migration-custom-services:

Custom Services
~~~~~~~~~~~~~~~

Stackato can export and import data from built-in data services running
on Stackato nodes, but it has no mechanism to handle data in
:ref:`external databases <external-db>` (unless ``kato export|import``
has also been modified to recognize the custom service).

Backing up or moving such databases should be handled separately, and
user applications should be reconfigured and/or redeployed to connect
properly to the new database host if the database is not implemented as
a Stackato data service.

.. _bestpractices-migration-db-connections:

Hard-coded Database Connection Info
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Applications which write database connection details during staging
rather than taking them from environment variables at run time, must be
re-staged (e.g. redeployed or updated) to pick up the new service
location and credentials. Restarting the application will not
automatically force restaging.

.. _bestpractices-migration-dea:

DEAs
~~~~

Droplet Execution Agent (DEA) nodes are not migrated directly from old
nodes to new nodes. Instead, the application droplets (zip files
containing staged applications) are re-deployed to new DEA nodes from
the Controller.


.. _bestpractices-migration-export:

Exporting the server data
^^^^^^^^^^^^^^^^^^^^^^^^^

Data export is done with the :ref:`kato data export
<kato-command-ref-data-export>` command. The command can export:

* internal Stackato data (users, groups, quotas, settings, etc.)
* application droplets
* data services

Start by logging into the VM via ``ssh``::

	$ ssh stackato@stackato-xxxx.local
  
A single-node micro cloud VM can be backed up with a single command::

	$ kato data export --only-this-node

A clustered setup can be backed up with a single command::

	$ kato data export --cluster

Once the export completes, you can use `scp
<http://manpages.ubuntu.com/manpages/lucid/man1/scp.1.html>`_ or another
utility (e.g. sftp, rsync) to move the .tgz file to another system, or
save the file directly to a mounted external filesystem by specifying
the full path and filename during export (see backup example below). 
  
Scheduled backups
^^^^^^^^^^^^^^^^^

Regular backup of controller data, apps, droplets, and service data is
recommended for any production system. Implementation of a regular
backup routine is left to the discretion of the Stackato administrator,
but using `cron/crontab
<http://manpages.ubuntu.com/manpages/oneiric/man1/crontab.1.html>`_ is
one simple way is to automate this. For example, you could create an
entry like the following in the root user's crontab on the filesystem
node::

  0 3 * * * su - stackato /bin/bash -c '/home/stackato/bin/kato data export --cluster /mnt/nas/stackato-backup.tgz'

This runs ``kato data export --cluster`` every morning at 3AM as
``root`` using the ``stackato`` user's login environment (required) and
saves a .tgz file to a mounted external filesystem.

Scheduled (non-interactive) backups using the ``kato export`` command
will need to be run by ``root`` as some shell operations performed in
the export require ``sudo`` when run interactively. For clusters,
passwordless `SSH key authentication
<https://help.ubuntu.com/community/SSH/OpenSSH/Configuring#disable-password-authentication>`__
between the Core node and all other nodes will also need to be set up.
The command should be run on the node hosting the 'filesystem' role, as
some shell commands need to be run locally for that service.

.. _bestpractices-migration-import:

Importing the server data
^^^^^^^^^^^^^^^^^^^^^^^^^

To import a Stackato dump, transfer the file to the target VM.

Login to the Stackato VM and run ``kato data import`` with the relevant
options. For example, to import all data into a new cluster::

	$ kato data import --cluster stackato-export-xxxxxxxxxx.tgz

The command can also import data remotely from a running Stackato
system. For example::

    $ kato data import --cluster stackato-host.example.com


.. _bestpractices-nagios:

System Monitoring with Nagios
-----------------------------

Though Stackato has an internal mechanism for supervising processes on a
server or cluster (`Supervisor <http://supervisord.org/>`_), it is
advisable to add some external monitoring for production systems.
`Nagios <http://www.nagios.org/>`_ is a free, open source system
monitoring tool that can provide this external monitoring. 

Below is an example Nagios config for a small cluster running on Amazon
EC2 which monitors system load, free disk space and SSH connectivity. 

.. literalinclude:: ../common/nagios.conf

Detailed instructions on installing and configuring Nagios can be found
in the `Nagios Core Documentation
<http://nagios.sourceforge.net/docs/3_0/toc.html>`_

.. _bestpractices-persistent-storage:

Persistent Storage
------------------

Cloud hosting providers have different default partition sizes and
configurations. The default root volumes on some cloud hosted VM
instances are often fairly small and are usually ephemeral. Data service
and filesystem nodes should always be backed by some kind of persistent
storage, with enough free filesystem space to accommodate the projected
use of the services.

The :ref:`Persistent storage <server-vm-fs-relocate-ec2>` section
in the :ref:`EC2 AMI <vm-ec2>` guide provides an example of how to
relocate services data to an EBS volume. The general case is covered
below.

.. _bestpractices-relocate:

Relocating Services, Droplets, and Containers
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To move database services, application droplets, and application
containers to larger partitions:

* mount the filesystem and/or block storage service on the instance (with
  :ref:`quotas enabled <bestpractices-filesystem-quotas>`),
* create directories for the items you wish to move,
* run the :ref:`kato relocate <kato-command-ref-relocate>` command(s).

For example::
  
  $ kato stop
  ...
  $ kato relocate services /mnt/ebs/services
  ...
  $ kato relocate droplets /mnt/ebs/droplets
  ...
  $ kato relocate containers /mnt/containers
  ...

.. note::

    For performance reasons, Stackato containers should not be relocated
    to EBS volumes.

.. _bestpractices-filesystem-quotas:

Enabling Filesystem Quotas
^^^^^^^^^^^^^^^^^^^^^^^^^^

The Stackato filesystem quotas cannot be enforced by the system unless
they are mounted on partitions which support Linux quotas. This may need
to be specified explicitly when running the ``mount`` command. The
:ref:`kato relocate <kato-command-ref-relocate>` command will warn if
this is necessary.

For the example above, the ``mount`` step might look like this::  

    $ sudo mount -o remount,usrjquota=aquota.user,grpjquota=aquota.group,jqfmt=vfsv0 /mnt/containers
    $ sudo quotacheck -vgumb mountpoint /mnt/containers
    $ sudo quotaon -v mountpoint /mnt/containers

To ensure the quotas are preserved after reboot, edit
*/etc/init.d/setup_stackato_lxc* to include mount commands for each
partition. The example above would require a block such as this::

  # enable quotas for Stackato containers
  if [[ -f "/mnt/containers/aquota.user" ]]; then
    mount -o remount,usrjquota=aquota.user,grpjquota=aquota.group,jqfmt=vfsv0 /mnt/containers
    quotaon -v /mnt/containers
  fi

