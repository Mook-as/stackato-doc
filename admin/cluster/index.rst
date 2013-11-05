.. _cluster-setup:

.. index:: Cluster Setup

Cluster Setup
=============

This process begins with an installed :term:`micro cloud`, which must
then be cloned across several :term:`node`\s.  You connect to each node
in turn and tell it which :term:`role`\s it is to serve, thereby
distributing the processing load for maximum performance.

.. _server-cluster-roles:

Roles
-----

A Stackato :term:`node` can take on one or more of the following roles:

* :ref:`primary <architecture-primary>`
* :ref:`controller <architecture-controller>`
* :ref:`router <architecture-router>`
* :ref:`dea <architecture-dea>`
* mdns (intended for micro clouds)
* :ref:`filesystem <persistent-file-system>`
* :term:`mongodb`
* :term:`mysql`
* :term:`postgresql`
* rabbit
* redis
* :ref:`memcached <memcached>`
* :ref:`Harbor <harbor>` (TCP/UDP port service)

The command line tool used to configure Stackato servers is called
:ref:`kato <kato-command-ref>`. You can see a list of the available
roles at the command line by running the :ref:`kato info
<kato-command-ref-info>` command.

Setup of cluster nodes is done using the :ref:`kato node
<kato-command-ref-node-attach>` setup, add, attach, and remove
sub-commands.

The :ref:`kato info <kato-command-ref-info>` command will show:

* **assigned roles**: roles currently configured to run on the node
* **available roles**: roles which can be added with ``kato role add``

.. _server-cluster-core-node:

Preparing the Core Node
-----------------------

In a Stackato cluster, one node is dedicated as the Core node. This node will
have a :ref:`controller <architecture-controller>`, 
:ref:`primary <architecture-primary>`, 
:ref:`base <architecture-base>`, and 
:ref:`router <architecture-router>` role but can also include additional roles.

Boot a Stackato VM and set up the Core node as described below, then add
the other nodes and assign roles.


CORE_IP
^^^^^^^

A :ref:`static IP address <server-config-static-ip>` is necessary to
provide a consistent network interface for other nodes to connect to. If
your IaaS or cloud orchestration software provide IP addresses which
persist indefinitely and are not reset on reboot you may not have to set
this explicitly.

Take note of the IP address of the Core node. It will be required when
configuring additional nodes in the following steps, so that they can
attach to the Core node.

Make sure that the IP address of its ``eth0`` interface is registering
the correct address, which may not be the case if you have set a static
IP and not yet rebooted or restarted networking. To check the IP
address, run:

    .. parsed-literal::

	$ ifconfig eth0

If necessary, set the :ref:`static IP address <server-config-static-ip>`:

    .. parsed-literal::

	$ kato op static_ip

.. note::

  If the IP address of the Core node changes, the :ref:`kato node migrate
  <kato-command-ref-node-attach>` command must be run on all nodes in the
  cluster (starting with the Core node) to set the new CORE_IP.
  

Hostname
^^^^^^^^

Next, set the **fully qualified hostname** of the Core node. This
is required so that Stackato's internal configuration matches the
:ref:`DNS record <server-config-dns>` created for this system.

To set the hostname, run:

    .. parsed-literal::

	$ kato node rename *hostname.example.com* --no-restart

This hostname will become the basename of the "API endpoint" address
used by clients (e.g. "https://api.hostname.example.com").

.. note::
  If you are building a cluster with multiple Routers separate from the
  Core node, the load balancer or gateway router must take on the API
  endpoint address. Consult the :ref:`Load Balancer and Multiple Routers
  <cluster-load-balancer>` section below.
  

Wildcard DNS
^^^^^^^^^^^^

A wildcard DNS record is necessary to resolve not only the API endpoint,
but all applications which will subsequently be deployed on the PaaS.
:ref:`Create a wildcard DNS record <server-config-dns>` for the Core
node (or :ref:`Load Balancer/Router <cluster-load-balancer>`).


Core Node
^^^^^^^^^

On the Core node, execute the following command: 

  .. parsed-literal::

	$ kato node setup core api.\ *hostname.example.com*

This sets up the Core node with just the implicit **controller**, **primary**, and
**router** roles.

If you intend to set up the rest of the cluster immediately, you would
carry on to enable those roles you ultimately intend to run on the Core
node.  For example, to set up a Core node with the **controller**, **primary**
**router**, and **dea** roles:

  .. parsed-literal::

	$ kato node setup core api.\ *hostname.example.com*
	$ kato role add dea

Then proceed to configure the other VMs by attaching them to the Core
node and assigning their particular roles.

.. _server-cluster-attach:

Attaching Nodes and Enabling Roles
----------------------------------

Adding nodes to the cluster involves attaching the new VMs to the Core
node's IP address using the :ref:`kato node attach
<kato-command-ref-node-attach>` command. This command will check that
the new node has a version number compatible with the Core node before
attaching it.

Roles can be added (or removed) on the new node after attaching using
the :ref:`kato role <kato-command-ref-role-add>` command, but it is
generally preferable to enable roles during the ``kato attach`` step
using the ``-e`` (enable) option as described below for each of the node
types.


.. _server-cluster-router:

Router Nodes
^^^^^^^^^^^^

In smaller clusters, the Router role can be run on the Core Node. To run
its own on a separate node:

  .. parsed-literal::

 	$ kato node attach -e router *CORE_IP*

Note that the public DNS entry for the Stackato cluster's API endpoint
must resolve to the Router if it is separate from the Core Node. For
clusters requiring multiple Routers, see the :ref:`Load Balancer and
Multiple Routers <cluster-load-balancer>` section below.

.. _server-cluster-data-services:

Data Services Nodes
^^^^^^^^^^^^^^^^^^^

Data services can share a single node (small clusters) or run on separate
nodes (recommended for production clusters). To set up all available data
services on a single node and attach it to the Core node, run the
following command on the data services node:

  .. parsed-literal::

 	$ kato node attach -e data-services *CORE_IP*
  
.. note::

  The :ref:`Harbor <harbor>` port service needs a publicly routable IP
  and exposed port range if you want to provide externally accessible
  TCP and UDP ports for user applications. See the :ref:`Harbor
  Requirements & Setup <harbor-setup>` documentation for details. 


DEA Nodes
^^^^^^^^^

Nodes which stage application code and run application containers are
called Droplet Execution Agents (DEAs). Once the controller node is
running, you can begin to add some of these nodes with the :ref:`kato
node attach <kato-command-ref-node-attach>` command. To turn a generic
Stackato VM into a DEA and connect it to the Core node:

  .. parsed-literal::

	$ kato node attach -e dea *CORE_IP*

Continue this process until you have added all the desired DEA nodes.

Verification
^^^^^^^^^^^^

To verify that all the cluster nodes are configured as expected,
run the following command on the Core node:

  .. parsed-literal::

	$ kato status --all

.. _cluster-remove-nodes:

Removing Nodes
^^^^^^^^^^^^^^

Use the :ref:`kato node remove <kato-command-ref-node-attach>` to remove a node from 
the cluster. Run the following command on the core node.

  .. parsed-literal::

        $ kato node remove *NODE_IP*

Role Configuration using the Management Console
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Once cluster nodes are connected to the Core node, roles can be enabled
or disabled using the :ref:`Cluster Admin <console-cluster-admin>`
interface in the :ref:`Management Console <management-console>`.

Example Clusters
----------------

Single-Node
^^^^^^^^^^^

This is a configuration (not actually a cluster) which you would not
generally deploy in production, but it helps to illustrate the role
architecture in Stackato. A node in this configuration will function
much like a micro cloud, but can be used as the starting point for
building a cluster later.

All that is required here is to enable all roles except for **mdns**
(not used in a clustered or cloud-hosted environment):

  .. parsed-literal::

	$ kato node setup core api.\ *hostname.example.com*
	$ kato role add --all-but mdns

Three-Node
^^^^^^^^^^

This is the smallest viable cluster deployment, but it lacks the
fault tolerance of larger configurations:

* 1 Core node consisting of primary, controller, and router
  (and supporting processes)
* 1 data-services node running the database, messaging and filesystem services
* 1 DEA (Droplet Execution Agent) node

This configuration can support more users and applications than a single
node, but the failure of any single node will impact hosted applications. 

Five-Node
^^^^^^^^^

A typical small Stackato cluster deployment might look like this:

* 1 Core node consisting of primary, controller, and router
  (and supporting processes)
* 1 data-services node running the database, messaging and filesystem services
* 3 DEA (Droplet Execution Agent) nodes

In this configuration, fault tolerance (and limited scalability) is
introduced in the pool of DEA nodes. If any single DEA node fails,
application instances will be automatically redeployed to the remaining
DEA nodes with little or no application down time.

20-Node
^^^^^^^

A larger cluster requires more separation and duplication of roles for
scalability and fault tolerance. For example:

* 1 Core node running the primary and controller roles (with supporting
  processes)
* 1 supplemental Controller node (sharing a filesystem and PostgreSQL
  database with the Core node)
* 1 Load Balancer (Stackato VM or hardware)
* 2 Router nodes
* 1 Filesystem service node 
* 1 PostgreSQL + MySQL data service node
* 1 MongoDB, Redis, RabbitMQ + other data service node
* 12 DEA (Droplet Execution Agent) nodes

In this configuration:

* application instances span a larger group of DEA nodes so 
  applications can be easily scaled to meet increasing demand

* web requests are evenly distributed between two Router nodes, either
  of which can fail without any interruption of service
  
* any data service node failure will be localized, not affecting data
  services on other nodes
  
* the auxiliary controller balances the load on the Management Console
  and system management tasks


.. index:: Persistent and Shared Storage

.. _cluster-shared-disk:

Roles Requiring Persistent or Shared Storage
--------------------------------------------

Though all roles can run using the VM's default filesystem, in
production clusters some roles should always be backed by a persistent
filesystem (block storage/EBS volumes) to provide scalable storage
space and easy snapshotting. Nodes with the following roles should have
their */var/stackato/services* directory on persistent storage:

* Data Services: MySQL, PostgreSQL, MongoDB, Redis
* Filesystem Service
* Memcache
* RabbitMQ
* Harbor

.. note::
    Though Memcache and Redis are in-memory data stores, system service
    info data is stored on disk, so backing them with a persistent
    filesystem is recommended.

In clusters with multiple Cloud Controllers, the nodes **must** share a
common */var/stackato/data/cloud_controller_ng/tmp* mount point as
described :ref:`below <cluster-multi-controllers>` in order to work
together properly. 

See the :ref:`Persistent Storage <bestpractices-persistent-storage>`
documentation for instructions on relocating service data, application
droplets, and containers.

.. _cluster-firewall:

.. index:: Firewall Configuration

.. _cluster-config-ports:

.. index:: Port Configuration

Port Configuration
------------------

.. include:: ../common/ports.inc

.. include:: ../common/harbor-ports.inc

.. _cluster-multi-controllers:

.. index:: Multiple Controllers

Multiple Controllers
--------------------------

A Stackato cluster can have multiple controller nodes running on
separate VMs to improve redundancy. The key element in designing this
redundancy is to have all controller nodes share a
``/var/stackato/data/cloud_controller_ng/tmp`` directory stored on a
high-availability filesystem server. For example:

* Create a shared filesystem on a Network Attached Storage device. [1]_

* Stop the controller process on the Core node before proceeding
  further::

	$ kato stop controller

* On the Core node *and each additional controller node*:

  * Create a mount point::

    $ sudo mkdir /mnt/controller

  * Mount the shared filesystem on the mount point. [1]_

  * Set aside the original ``/var/stackato/data/cloud_controller_ng/tmp``::

    $ mv /var/stackato/data/cloud_controller_ng/tmp /var/stackato/data/cloud_controller_ng/tmp.old

  * Create a symlink from ``/var/stackato/data/cloud_controller_ng/tmp`` to the mount point::

    $ ln -s /mnt/controller /var/stackato/data/cloud_controller_ng/tmp

* On the Core node, start the controller process::

	$ kato start controller

* Run the following command on the additional Controller nodes to enable
  *only* the controller process::

 	$ kato node attach -e controller *CORE_IP*

.. [1]	The type of filesystem, storage server, and network mount method are
	left to the discretion of the Stackato administrator.
	
.. _cluster-load-balancer:
	
Load Balancer and Multiple Routers
----------------------------------

For large scale deployments requiring multiple Router nodes, a Load
Balancer must be configured to distribute connections between the
Routers. The Stackato VM can be configured to take on this role.

.. note::
    A node configured as a Load Balancer cannot have any other roles
    enabled.

The :ref:`kato node setup load_balancer <kato-command-ref-node-attach>`
command retrieves IP addresses of every router in the cluster and
configures an nginx process to distribute load (via round-robin) among a
pool of Routers and handle SSL termination.

For example, to setup a cluster with a Load Balancer and multiple Routers:

Rename the Load Balancer
^^^^^^^^^^^^^^^^^^^^^^^^

The Load Balancer is the primary point of entry to the cluster. It must
have a public-facing IP address and take on the primary hostname for
the system as :ref:`configured in DNS <server-config-dns>`. Run the
following on Load Balancer node::

  $ kato node rename *hostname.example.com*

Set up the Core Node
^^^^^^^^^^^^^^^^^^^^

The Core node will need to temporarily take on the primary hostname of
the Stackato system (i.e. the same name as the Load Balancer above). Run
the following on the Core node::

  $ kato node rename *hostname.example.com*

If it is not already configured as the Core node, do so now::

  $ kato node setup core api.\ *hostname.example.com*

The ``kato node rename`` command above is being used to set internal Stackato
parameters, but all hosts on a network should ultimately have unique
hostnames. After setup, rename the Core node **manually** by editing
*/etc/hostname* and restarting.

Set up Supplemental Routers 
^^^^^^^^^^^^^^^^^^^^^^^^^^^

As with the Core node, you will need to run ``kato node rename`` on each
router with the same primary hostname. Run the following on each
Router::

  $ kato node rename *hostname.example.com*

Then enable the 'router' role and attach the node to the cluster::

  $ kato node attach -e router <MBUS_IP>

As above, rename each host manually after configuration to give them 
unique hostnames. The MBUS_IP is for the network interface of the Core
node (usually eth0).

Configure the Load Balancer
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Attach the Load Balancer to the Core node and enable the 'router' role.
On the Load Balancer node, run::

  $ kato node attach -e router <MBUS_IP>

Then set up the node as a Load Balancer::

  $ kato node setup load_balancer

This command will fetch the IP addresses for all configured routers in
the cluster. It will prompt you to remove the IP address of the local
Load Balancer from the pool of Routers (recommended).

.. note::
  If you are using the AOK authentication service, see also :ref:`AOK
  with a Load Balancer <aok-ssl-load-balancer>`

SSL Certificates
^^^^^^^^^^^^^^^^

Since the Load Balancer terminates SSL connections, SSL certificates
must be set up and maintained on this node. See the :ref:`Using your own
SSL certificate <server-config-ssl-cert-own-use>` and :ref:`CA
Certificate Chaining <server-config-ssl-cert-chain>` sections for
instructions.
