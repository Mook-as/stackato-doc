.. _autoscaling:

.. index:: DEA Auto Scaling

DEA Auto Scaling
================

Stackato can automatically add DEA nodes to a cluster to handle
increasing numbers of user application instances. This feature, called
auto scaling, is available for clusters running on HPCS, vSphere,
EC2, or OpenStack.

When auto scaling is enabled, stackato will automatically grow the pool
of DEA nodes to accommodate new app deployments. Scaling events are
triggered the available memory in the pool falls below a certain
threshold.

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
* CloudStack

.. note::

    It is possible to enable multiple plugins, but this is generally not
    recommended. You could use this feature to implement a "ping" plugin
    that doesn't provision a DEA, but instead sends a notification
    email, or pings a remote API.

Each platform has specific tunable settings under the ``platform`` key
in *autoscaling.yaml* for setting authorization credentials, DEA
template IDs and so forth. Configure the settings for your platform in
this file before proceeding.

Enabling Auto-Scaling
---------------------

Run the following command on the Primary node::

    $ kato config set cloud_controller_ng autoscaling/enabled true
    $ kato config set health_manager autoscaling/enabled true

.. note::

    If you are running more than one cloud controller in your cluster,
    enable the scaling plugin on **only one** of the cloud controllers,
    otherwise each one will provision a separate DEA on every scaling
    event.

After saving this change, restart the following processes::

    $ kato process restart health_manager cloud_controller_ng

You should then start seeing some scaling information in the Health
Manager's log file::

    $ kato log tail health_manager

Configuration and Tuning (Advanced)
-----------------------------------

A number of configuration options in the autoscaling file can be
customized to fit your particular requirements.

The options in */s/etc/autoscaling/autoscaling.yaml* are:

``scale_op_timeout``
    Specifies how long the scaler will wait for the plugin to complete
    a scale up operation (Default: 300, Unit: seconds).

``cooldown_period``
    After a scaling event, ignore subsequent scaling requests until this
    period expires. Prevents duplicate scaling events. (Default: 120,
    Unit: seconds)

``vm_name_prefix``
    Gives the new Stackato VM instance a name with this prefix to easily
    identify autoscaled instances.

Further settings are found in the health_manager configuration
(see ``kato config get health_manager autoscaling``):

``scaleup_threshold``
    Number of cycles to wait before issuing a scaling request. The
    health manager monitors the DEA pool continually. If the forward
    buffer is not maintained during the number of cycles indicated by
    this value, the scaling event will be sent to the cloud controller.
    Decrease this value to make autoscaling more aggressive (Default: 3)

``forward_buffer``
    The number of megabytes of free memory to maintain in the DEA pool.
    Note that app memory usage on each DEA is also accounted for
    (Default: 4096, Unit: MB)

``cooldown_period``
    After a scaling event, ignore subsequent scaling requests until this
    period expires (Default: 180, Unit: seconds)

``dea_staleness``
    Maximum time to wait for DEAs to report their status via NATS. If a
    DEA fails to report in during this period (e.g. it becomes
    unresponsive) it will be removed from the pool, which may
    lead to a new scaling event being triggered (Default: 180, Unit:
    seconds)


Writing custom scaling plugins (Advanced)
-----------------------------------------

Autoscaling plugins are written in Ruby. You can see the built-in
plugins in the */s/etc/autoscaling/plugins/* directory. A simpler
"skeleton" plugin might look like this:

.. code-block:: ruby

    require 'rubygems'

    class SkeletonPlugin < Plugin

      def platform_name
        "Skeleton"
      end

      def scale_up
        log "Scaling up..."
        log platform_config.inspect
      end

      def handle_command
        log "Handling command: #{cmd}"
      end

    end

The ``log`` function is available to all plugins and operates at the cloud
controllers global log level.

Once you have written a plugin, install the file in
*/s/etc/autoscaling/plugins/*. Add configuration for the plugin in
*/s/etc/autoscaling/autoscaling.yaml* under the ``platform_config`` key
in a new section corresponding to the plugin name (in this case above:
``skeleton``). Enable the plugin by adding it to the ``enabled_plugins``
list.

Troubleshooting
---------------

Most of the output from the scaling triggers comes from the health manager::

	$ kato log tail health_manager

Once scaling has been triggered by the health manager, you can check for
the relevant platform API output in the controller::

	$ kato log tail cloud_controller

If you are using vSphere, make sure to monitor any logs and events on
the vCenter GUI. A common issue is running out of available disk space
on the filestores for new deployments.

For EC2, you can monitor using the AWS console. It can provide useful
insights into the health of the instance such as network reach-ability
and OS responsiveness, as well as setting administrative alerts.

Testing
-------

If you want to emulate a scaling trigger, you can force a scale-up
operation by issuing the following on the cloud controller node::

  $ nats-pub health.scale '{"op": "up"}'

