.. _autoscaling:

.. index:: DEA Auto Scaling

DEA Auto Scaling
================

Stackato can automaticaly add DEA nodes to a cluster to handle
increasing numbers of user application instances. This feature, called
DEA Auto Scaling, is available for clusters running on HPCS, vSphere,
EC2, or OpenStack.

Scaling events are triggered by a predictive algorithm in the Health
Manager which checks for potential exhaustion of DEA resources.


DEA Template
------------

Before enabling auto scaling, you will need to create a DEA template
from the standard Stackato VM. Typically you would do this by running
the following commands on a fresh Stackato VM:

  .. parsed-literal::

    $ kato op defer "node attach -e dea *CORE_IP*" --run-as-root

This defers the ``attach`` command and enables the DEA role on the next
boot. Shut down the VM once this is done.

.. note::

    When shutting down in vSphere, right click the VM in vCenter and
    select *Create a Template*. It is important that it is a 'template'
    object so that it can be seamlessly deployed to any of the available
    ESXi hosts.

DEA Scaling configuration
-------------------------

The DEA auto scaling configuration file is:

    /s/etc/autoscaling/autoscaling.yaml

This file must be modified on each node running the Controller role.

Comments throughout the file describe in detail what each option does,
and what information is required for each infrastructure platform.

The ``enabled_plugins`` key must be set to one of the following:

* EC2
* HPCS
* OpenStack
* vSphere

Blocks of configuration settings in the ``platform_config`` section will
be loaded depending on which platform is set in ``enabled_plugins``.



Enabling Auto-Scaling
-------------------------------------------

Run the following command on the Primary node::
    
    $ kato config set cloud_controller_ng autoscaling/enabled true
    $ kato config set health_manager autoscaling/enabled true

After saving this change, restart the following processes::

    $ kato process restart health_manager cloud_controller_ng

You should then start seeing some scaling information in the Health
Manager's log file::

    $ kato log tail health_manager


Troubleshooting
---------------

Most of the output from the scaling triggers comes from the health manager::

	$ kato log tail health_manager

Once scaling has been triggered by the health manager, you should then check for
the relevant platform API output in the controller::

	$ kato log tail cloud_controller

If you are using vSphere, make sure to monitor any logs and events on
the vCenter GUI.  A common issue is running out of available disk space on the
filestores for new deployments.

For EC2, you can monitor using the AWS console.  It can provide useful insights
into the health of the instance such as network reachability and OS
responsiveness, as well as setting administrative alerts.

If you are testing scaling triggers, you can force a scale-up operation by
issuing the following on the cloud controller node::

  $ nats-pub cloudcontrollers.hm.scalerequests '{"op": "scaleup"}'

