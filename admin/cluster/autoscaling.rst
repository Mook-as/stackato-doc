.. _autoscaling:

.. index:: DEA Auto Scaling

DEA Auto Scaling
================

Stackato can automatically add DEA nodes to a cluster to handle
increasing numbers of user application instances. This feature, called
Auto Scaling, is available for clusters running on HPCS, vSphere,
EC2, or OpenStack.

When auto scaling is enabled, it will automatically grow the cluster to cater
for new app deployments. Scaling events are triggered by keeping a buffer of
DEAs in the memory pool that provide enough memory for new deployments.

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

.. note::

    While it is possible to enable multiple plugins at once, this is generally
    not recommended. You could use this feature to implement a "ping" plugin
    that doesn't provision a DEA, but instead sends a notification email,
    or pings a remote API.

Each platform has specific tunables under the ``platform`` key in the scaling
configuration file, for setting authorization credentials, DEA template IDs
and so forth. Your target platform should be configured there before proceeding.

Enabling Auto-Scaling
---------------------

Run the following command on the Primary node::

    $ kato config set cloud_controller_ng autoscaling/enabled true
    $ kato config set health_manager autoscaling/enabled true

.. note::

    You should only enable scaling plugins in one of the cloud controllers
    configuration file, otherwise a DEA will be provisioned per cloud controller
    on each scaling event.

After saving this change, restart the following processes::

    $ kato process restart health_manager cloud_controller_ng

You should then start seeing some scaling information in the Health
Manager's log file::

    $ kato log tail health_manager

Configuration and Tuning (Advanced)
-----------------------------------

There are numerous configuration options in the autoscaling file that can be
customized to requirements.

A few options are in ``/s/etc/autoscaling/autoscaling.yaml``:

``scale_op_timeout``
    This value specifies how long the scaler will wait for the plugin
    to compelete a scale up operation (Default: 300, Unit: seconds).

``cooldown_period``
    All subsequent scaling requests until this period expires after the original
    scaling operation (Default: 120, Unit: seconds)

``vm_name_prefix``
    Gives the VM a name with this prefix to easily identify autoscaled instances.

A few other tunables are in the health_manager kato config
``kato config get health_manager autoscaling``:

``scaleup_threshold``
    The health manager will monitor the DEA pool continually. If the forward
    buffer is not maintained during the number of cycles indicated by this
    value, the scaling event will finally be sent to the cloud controller.

    Decrease this value to make autoscaling more aggressive.

    Default: 3

``forward_buffer``
    The number of megabytes of free memory to maintain in the DEA pool.
    Note that app memory usage on each DEA is also accounted for.

    Default: 4096, Unit: MegaBytes

``cooldown_period``
    No scaling events will be triggered after a previous scaling event during
    this period.

    Default: 180, Unit: seconds

``dea_staleness``
    The DEA pool monitoring is maintained by only keeping DEAs which report
    periodically to the health manager via NATS.
    If a DEA fails to report in during this period, for example it has become
    unresponsive, it will be removed which may subequently lead to a new scaling 
    event being triggered.

    Default: 180, Unit: seconds

Writing custom scaling plugins (Advanced)
-----------------------------------------

A skeleton plugin that does nothing would look like the following:

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

Once you have written the plugin, it can be installed to
``/s/etc/autoscaling/plugins/``. The configuration can be placed in
``/s/etc/autoscaling/autoscaling.yaml`` under the ``platform`` key (in this case
the key would be ``skeleton``) which is available the ``platform_config`` hash
in the plugin.

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

Testing
-------

If you want to emulate a scaling trigger, you can force a scale-up operation by
issuing the following on the cloud controller node::

  $ nats-pub health.scale '{"op": "up"}'

