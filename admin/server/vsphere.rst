.. _vm-vsphere:

.. index:: vSphere

vSphere
=======

*Recommended version*: **VMware vSphere 4** or newer

Initial Setup
-------------

Obtain `vSphere <http://info.vmware.com/content/9071_vSphere/>`_
and follow vendor's installation instructions.

.. note::
  VMware Tools is not pre-installed on the Stackato VM because of
  `potential incompatibilities
  <http://blogs.vmware.com/kb/2010/04/running-older-versions-of-virtual-machine-tools-on-newer-versions-of-esx-hosts.html#.UXbQJUmxgal>`_
  with different hypervisor versions. If you wish to install VMware Tools
  on the Stackato VM, make sure the version matches your ESX/ESXi
  version.

Configuration
-------------

Unlike the Stackato :term:`micro cloud` in other environments, the vSphere VM does not broadcast the 
``stackato-xxxx.local`` hostname via :term:`multicast DNS`, and it may not have the default 
``api.stackato-xxxx.local`` and ``stackato-xxxx.local`` entries in the ``/etc/hosts`` file.

* The hostname can be changed as per the steps in :ref:`Changing the Hostname <server-config-hostname>`.
* To verify the contents of ``/etc/hosts`` see :ref:`Modifying /etc/hosts <server-config-etc-hosts>`.  
* Network DNS entries may be added as outlined in the :ref:`DNS section <server-config-dns>`.

.. index:: vSphere Cloning

vSphere Cloning
---------------

To create a cluster of Stackato VMs with vSphere:

#. Import the Stackato :term:`OVF`.
#. Clone the resulting Stackato VM to create as many nodes as you need for your cluster.
#. Start the cloned Stackato VMs.
#. Run the appropriate ``kato node attach`` commands on the cloned nodes to configure their roles.

See the :ref:`Cluster Setup <cluster-setup>` and
:ref:`Assigning roles with kato <server-cluster-roles>`
sections for details on roles and the ``kato node attach`` and ``kato role add`` commands.

To scale the cluster (to add additional DEAs for example), follow the
last three steps for each additional node, running the ``kato node attach``
command to :ref:`assign the needed role <server-cluster-roles>`
and pointing it to the primary node.
