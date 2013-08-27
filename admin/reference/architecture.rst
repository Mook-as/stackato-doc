.. _architecture:

.. index:: Architectural Design

Architectural Design
====================

.. image:: ../images/stackato-architecture-diagram.png
	:align: center
	
The Stackato VM is a stand-alone :term:`micro cloud` virtual machine with all the components necessary 
for running a test environment in one instance. For use on a larger scale, the VM can be cloned 
and assigned specific roles: Router, Cloud Controller, Droplet Execution Agents (DEAs, or worker 
nodes), Stager, or specific database services.

.. _architecture-roles:

Roles
-----

.. index:: Router

.. _architecture-router:

Router
^^^^^^

The router directs incoming network traffic to the appropriate application.

For smaller configurations, the router can be run on the same Stackato VM as 
the other components. 

When additional DEAs are in use and traffic increases, additional
routers can be added to handle the load. This will require a :ref:`load
balancer <cluster-load-balancer>` to be available in the cluster.

.. index:: Primary

.. _architecture-primary:

Primary
^^^^^^^

The primary node is the main entry point for a Stackato setup.  It is a mandatory part of
a Core node and runs a number of system critical processes.

In a cluster setup, this will be the node that nodes performing other roles are attached to.  Every cluster must include exactly one Primary node.

.. index:: Base

.. _architecture-base:

Base
^^^^

The base role comprises of several processes that are necessary for any node to function as part of a stackato cluster, and is mostly responsible for communicating with the primary node and forwarding log information.

This role cannot be disabled on any node.

.. index:: Controller

.. _architecture-controller:

Cloud Controller
^^^^^^^^^^^^^^^^

The Controller manages most of the operations of a Stackato
system. It hosts the Management Console, provides the API endpoint for
client access, manages the cloud_controller process, provisions services, 
dispatches applications for staging and deployment, and (with the Health Manager) 
tracks the availability of DEA nodes.

In the case of a cluster setup, it resides on the :ref:`Core node
<server-cluster-core-node>` that all other VM's in the cluster connect
to. 

A single Controller is sufficient for small and mid-sized
clusters, but :ref:`multiple Controllers <cluster-multi-controllers>`
can be configured if neccessary for larger implementations.

.. index:: Droplet Execution Agents
.. index:: DEA

.. _architecture-dea:

Droplet Execution Agents
^^^^^^^^^^^^^^^^^^^^^^^^

DEAs run on multiple nodes and receive requests from the Cloud Controller(s) to start staged 
applications.  

As traffic increases, additional Stackato VMs can be configured as DEAs in order to
reduce the load on each of them and to allow applications to be pushed to more than one
instance.

.. index:: Health Manager

.. _architecture-health-manager:

Health Manager
^^^^^^^^^^^^^^

The Health Manager keeps track of the apps on each DEA and provides
feedback on the number currently running. It works in conjunction with
the Cloud Controller and must be run on the same VM.

.. _architecture-stager:

Stager
^^^^^^

The stager provides the runtime dependency requirements to the droplet
before it is run, such as those from PyPy, PPM and NPM or
staging hooks.

For some applications, this can include compiling libraries or other
programs, which can be demanding on system resources. Running a separate
staging node on a dedicated instance, or running multiple stagers, can
balance the load on a Stackato cluster that sees frequent deployments or
application updates.

.. _architecture-services:

Service Roles
-------------

Stackato nodes can also be assigned roles for data services. The data
services can be run separately on their own nodes, or grouped together.

Databases:
^^^^^^^^^^

* mysql
* postgresql
* redis
* mongodb

.. note::
	Data services running on on Amazon EC2 instances should be backed by
	persistent storage on an EBS (Elastic Block Store) volume.
	See :ref:`server-vm-fs-relocate-ec2` for details.

Other data services:
^^^^^^^^^^^^^^^^^^^^

* filesystem ( Persistent filesystem service )
* rabbit ( RabbitMQ message queue service )
* memcached
* Harbor ( Ports service )

.. _architecture-role-groups:

Role Groups
-----------

Role groups represent a set of roles. For example the **data-services**
group provides all databases plus RabbitMQ and the filesystem service::

  $kato role add data-services
  
Additional groups can be defined by administrators in
*/s/etc/kato/role_groups.yml*.
