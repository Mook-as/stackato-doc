.. _vm-openstack:

.. index:: OpenStack

OpenStack
=========

*Recommended version*: `Grizzly <http://www.openstack.org/software/grizzly/>`__

Simple Stackato deployments can be done using the OpenStack `Horizon
<http://docs.openstack.org/developer/horizon/>`__ interface. If your
system does not have Horizon enabled, if you need to configure options
not available in Horizon, or if you want to script VM operations, you
should use the following (Python) command line tools:

* `glance <http://docs.openstack.org/developer/glance/>`__: Used to
  import a Stackato VM image into the OpenStack Image Service. There are
  a number of installation options: 
  
  * `pip <http://pypi.python.org/pypi/python-glanceclient>`__: ``pip install python-glanceclient``
  * `source <git://github.com/openstack/python-glanceclient.git>`__
  * Ubuntu packages: On Ubuntu 12.04, use the version in the `Ubuntu Cloud Archive  <https://wiki.ubuntu.com/ServerTeam/CloudArchive#How_to_Enable_and_Use>`__  

* `python-novaclient <http://pypi.python.org/pypi/python-novaclient>`__.
  This provides the ``nova`` client for the OpenStack Nova API. It can
  be installed via:
  
  * `pypm <http://code.activestate.com/pypm/python-novaclient/>`__: ``pypm install python-novaclient``
  * `pip <http://pypi.python.org/pypi/python-novaclient>`__: ``pip install python-novaclient``
  * `source <https://github.com/openstack/python-novaclient>`__
  * Linux packages: e.g. ``sudo apt-get install python-novaclient``

To use these tools, set the environment variables for your OpenStack
credentials. Download the ``openrc.sh`` file from "User Settings >
OpenStack API > Download RC file" and source the settings with the
command::

  source openrc.sh
  
Alternatively, set the variables manually as per the `OpenStack CLI
documentation
<http://docs.openstack.org/cli/quick-start/content/getting_credentials_cli.html>`_.

The instructions here will focus on using these command line tools.

Import Stackato VM 
------------------

If you have not already done so, download the KVM image of the Stackato
Micro Cloud VM.

  http://www.activestate.com/stackato/download_vm

Unzip the image in a convenient local directory, then use ``glance`` to
create an image in OpenStack. For example, the following command imports
a raw image of Stackato to OpenStack and makes it publicly available:

.. parsed-literal::

  glance image-create --name="Stackato-|version|" --is-public=true \\
    --container-format=bare --disk-format=raw \\
    --file stackato-img-kvm-|version|.0.img

The unzipped KVM image is quite large (around 10GB) and will take a long
time to upload on some networks. You can use one of the following steps
to make it smaller first:

* Copy the image to create a 'sparse' file:
  
  .. parsed-literal::

    $ cp --sparse=always stackato-img-kvm-|version|.0.img stackato-sparse.img 

* Convert the image to qcow2 format:

  .. parsed-literal::

    $ qemu-img convert stackato-img-kvm-|version|.0.img -O qcow2 stackato-qcow.img

Using either of the resultant images will significantly speed up the
``glance image-create`` step. Specify ``--disk-format=qcow2`` when using
a qcow2 source image.


Adding a keypair
----------------

To launch instances on OpenStack you will need a keypair consisting of a
private and public key. See `Creation of Key Pairs
<http://docs.openstack.org/essex/openstack-compute/starter/content/Creation_of_Key_Pairs-d1e1848.html>`__
in the OpenStack documentation for details.

You can use the existing ssh public key from your local system like so::

  nova keypair-add --pubkey ~/.ssh/id_rsa.pub stackato-admin


Security Groups
---------------

Before launching a Stackato VM instance, you will need to either create
a security group which exposes only the necessary network ports, or
use/modify an existing group with the properties described below.

If you are running a single-instance Stackato Micro Cloud, you can
create a simple security group which exposes the following three ports
to the public (CIDR 0.0.0.0/0):

* HTTP (port 80)
* HTTPS (port 443)
* SSH (port 22)

All internal communication between Stackato processes on other ports
pass through 'localhost' in this configuration. See :ref:`Stackato port
requirements <cluster-config-ports>` for details on port usage in
Stackato.

When creating a **cluster** you must lock down most ports (as above) for
externally exposed nodes (e.g. Router, Load Balancer) and allow
communication on all ports between nodes internal to the cluster (e.g.
Primary node, Controller, DEA, data service nodes).

For example, you could create groups named

* stackato-ext: exposes only the HTTP, HTTPS, and SSH ports (as above) 
* stackato-int: exposes all TCP and UDP ports *only* to members of
  the stackato-int and stackato-ext groups (i.e. no ports
  exposed to the public)
  
Adding Groups & Rules with python-novaclient
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To create the "stackato-ext" security group described above using
``nova``::

  nova secgroup-create stackato-ext "Stackato front end nodes"
  nova secgroup-add-rule stackato-ext tcp 22 22 0.0.0.0/0
  nova secgroup-add-rule stackato-ext tcp 80 80 0.0.0.0/0
  nova secgroup-add-rule stackato-ext tcp 443 443 0.0.0.0/0

To create the "stackato-int" group::

  nova secgroup-create stackato-int "stackato auxiliary nodes"
  
Use the ``secgroup-add-group-rule`` command rather than
``secgroup-add-rule`` for creating rules applying to a group rather than
a CIDR range::

  nova secgroup-add-group-rule stackato-int stackato-int \
  --ip_proto tcp --from_port 1 --to_port 65535
  nova secgroup-add-group-rule stackato-int stackato-int \
  --ip_proto udp --from_port 1 --to_port 65535
  nova secgroup-add-group-rule stackato-int stackato-ext \
  --ip_proto tcp --from_port 1 --to_port 65535
  nova secgroup-add-group-rule stackato-int stackato-ext \
  --ip_proto udp --from_port 1 --to_port 65535

Once the "stackato-int" group is created, additional rules can be
added to "stackato-ext" to allow the two groups to communicate::

  nova secgroup-add-group-rule stackato-ext stackato-ext \
  --ip_proto tcp --from_port 1 --to_port 65535
  nova secgroup-add-group-rule stackato-ext stackato-ext \
  --ip_proto udp --from_port 1 --to_port 65535
  nova secgroup-add-group-rule stackato-ext stackato-int \
  --ip_proto tcp --from_port 1 --to_port 65535
  nova secgroup-add-group-rule stackato-ext stackato-int \
  --ip_proto udp --from_port 1 --to_port 65535


Booting a Stackato VM
---------------------

Find the Stackato VM image using ``nova image-list`` or the Horizon
interface. For example above we should see the name 'Stackato-|version|'
in the list.

Use ``nova flavor-list`` to see a list of available instance sizes and
configurations and choose a flavor that provides 2GB of RAM or
greater. Make note of the flavor ID. 

To boot a single Stackato VM for use as a Micro Cloud, use the ``nova
boot`` command. For example:

.. parsed-literal::

  nova boot microcloud --image Stackato-|version| --flavor m1.medium \\
    --key_name stackato-admin --security_groups stackato-ext

Cluster Setup
-------------

Setting up a Stackato cluster on OpenStack is much the same as doing so
on any other infrastructure. Boot instances using the method above, and
follow the instructions and guidelines in the :ref:`Cluster Setup
<cluster-setup>` guide.


.. _openstack-storage:

Ephemeral & Block Storage Configuration
---------------------------------------

Machines created in OpenStack have a small default primary disk (<10G).
You need larger disks to take advantage of the full PaaS capabilities.
These can either be ephemeral (for the LXC containers) or block storage
volumes (for sharing between cloud controllers or storing of data
services). The latter are useful as you can take snapshots for backup
purposes.

In clusters with multiple Cloud Controllers, the Controller nodes need
to share a block storage volume. As only one server can mount a block
storage volume at any one time, you either need to dedicate a system for
this that serves to the others via nfs, or attach to one node and mount
on the others via sshfs.

For example, in a cluster with one Primary node and two Controller
nodes. Start with the following commands to create the volume and attach
it to the Primary::

  nova volume-create --display-name stackato-droplets 10 # GB
  nova volume-attach <ID of primary server> <ID of volume created above> /dev/vdc

SSH to the Primary node, then format and mount the volume::

  sudo mkfs.ext4 /dev/vdc
  sudo mkdir -p /mnt/add-volume
  sudo mount /dev/vdc /mnt/add-volume
  sudo mkdir -p /mnt/add-volume/stackato-shared
  sudo chown stackato:stackato /mnt/add-volume/stackato-shared
  kato relocate droplets /mnt/add-volume/stackato-shared

On the two Controller nodes, run a command such as::

  sshfs -o idmap=user -o reconnect -o ServerAliveInterval=15 stackato@<Primary node IP>:/mnt/add-volume/stackato-shared/ /home/stackato/stackato/data

The data services may be colocated onto a single node for smaller
production clusters, or separated on to individual nodes. You
can provide settings that will refer to external high availability
clusters for mysql and postgres (see
http://docs.stackato.com/cluster/external-db.html for more info).

  nova volume-create --display-name stackato-data 10 # GB
  nova volume-attach <ID of data server> <ID of volume created above> /dev/vdc

SSH to the data services node and run:

  sudo mkfs.ext4 /dev/vdc
  sudo mkdir -p /mnt/add-volume
  sudo mount /dev/vdc /mnt/add-volume
  kato relocate services /mnt/add-volume/stackato-services

