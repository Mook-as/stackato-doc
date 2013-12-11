.. _architecture:

.. index:: Architectural Design

Architectural Design
====================

.. image:: ../images/stackato-architecture-diagram.png
	:align: center
	
The Stackato VM is a stand-alone :term:`micro cloud` virtual machine with all the components necessary 
for running a test environment in one instance. For use on a larger scale, the VM can be cloned 
and assigned specific roles: Router, Cloud Controller, Droplet Execution Agents (DEAs, or worker 
nodes), or specific database services.

.. _architecture-roles:

Roles
-----

.. index:: Base

.. _architecture-base:

Base
^^^^

The Base role comprises of several processes that are necessary for any node to
function as part of a Stackato cluster, and is mostly responsible for
communicating with the primary node and forwarding log information.

This role cannot be disabled on any node.

.. index:: Primary
.. index:: Health Manager

.. _architecture-primary:

Primary
^^^^^^^

The Primary role is a mandatory part of a Core node (or micro cloud) and runs a
number of critical system processes, including the Health Manager.

.. _architecture-health-manager:

The Health Manager keeps track of the apps on each DEA and provides
feedback on the number currently running. It works in conjunction with
the Cloud Controller and must be run on the same VM.

In a cluster setup, all nodes performing other roles are attached to the MBUS IP
of the Core node. Every cluster must include exactly one Primary role.

.. index:: Controller

.. _architecture-controller:

Cloud Controller
^^^^^^^^^^^^^^^^

The Controller manages most of the operations of a Stackato
system. It hosts the Management Console, provides the API endpoint for
client access, manages the cloud_controller_ng process, provisions services, 
dispatches applications for staging and deployment, and (with the Health Manager) 
tracks the availability of DEA nodes.

In a cluster setup, the Controller role must run on the :ref:`Core node
<server-cluster-core-node>` that all other VM's in the cluster connect to. 

A single Controller is sufficient for small and mid-sized
clusters, but :ref:`multiple Controllers <cluster-multi-controllers>`
can be configured if neccessary for larger implementations.

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

.. index:: Droplet Execution Agents
.. index:: DEA

.. _architecture-dea:

Droplet Execution Agents
^^^^^^^^^^^^^^^^^^^^^^^^

The Droplet Execution Agent (DEA) role in Stackato is responsible for
staging applications and running application instances within Linux
containers. In a Stackato cluster, there will typically be a number of
nodes running the DEA role, which in turn each host multiple user
application instances.

The DEA role is comprised of a number of processes:

 * dea_ng: Master process for staging and starting application
   instances, reporting on their state via NATS to the Health Manager.
 * dir_server: Handles requests for directories/files, responding with
   an HTTP URL.
 * fence: Responsible for the management of application containers using
   Docker.
 * apptail: Streams application logs via Logyard to various log drains.

In previous versions of Stackato, staging and running were handled by
separate components (Stager and DEA respectively), but these roles have
been combined in version 3.0 and later.

The Docker image used for the containers can be customized by admins.

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

  $ kato role add data-services
  
Additional groups can be defined by administrators in
*/s/etc/kato/role_groups.yml*.
