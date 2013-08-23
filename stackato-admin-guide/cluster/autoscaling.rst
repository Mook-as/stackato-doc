.. _autoscaling:

.. index:: Auto Scaling

Auto Scaling
============

Stackato includes automatic scaling functionality for vSphere, EC2, and
OpenStack environments. This allows your Stackato cloud to automatically
expand the number of available DEA's when needed.

Create the DEA template
-----------------------

The primary requisite for enabling auto scaling is to create a DEA template
from the Stackato VM. Typically you would do this by running the following
commands on a fresh Stackato VM:

  .. parsed-literal::

    $ kato op defer "node attach -e dea *CORE_IP*" --run-as-root

This will defer the ``attach`` command and enable the DEA role on the next boot,
so proceed to shut down the VM once this is done.

.. note::

    For vSphere, With the VM shut off, right click it in vCenter and select
    *Create a Template*. It is important that it is a 'template' object so that
    it can be seamlessly deployed to any of the available ESXi hosts.

Enable Auto-Scaling in the Health Manager
-----------------------------------------

On your ``primary`` node, run the following command::

    $ kato config get health_manager | grep enable_autoscaling

And ensure the following key is present and set to 'true'::

    enable_autoscaling = true

If not, run the following command::
    
    $ kato config set health_manager enable_autoscaling true

After saving this change, restart the health manager::

    $ kato process restart health_manager

You should then start seeing some scaling information in the health managers log file::

    $ kato log tail health_manager

Once confirmed you can then proceed to configure the controller.

.. _scaling_cc_config:

Configure the Controller
------------------------------

The controller requires setting a few switches before auto-scaling can be
triggered.

vSphere
^^^^^^^

On all of your ``controller`` nodes, run the following command::

    $ kato config get cloud_controller | grep vcenter

And ensure the following keys are present and set to 'vcenter'::

    primary_scaling_platform = vcenter
    vcenter_config = /home/stackato/stackato/etc/vcenter_config.yml

If not, run the following commands::

    $ kato config set cloud_controller primary_scaling_platform vcenter
    $ kato config set cloud_controller vcenter_config /home/stackato/stackato/etc/vcenter_config.yml

EC2
^^^

On all of your ``controller`` nodes, run the following command::

    $ kato config get cloud_controller | grep ec2

And ensure the following keys are present and set to 'ec2'::

    primary_scaling_platform = ec2
    vcenter_config = /home/stackato/stackato/etc/ec2_config.yml

If not, run the following commands::

    $ kato config set cloud_controller primary_scaling_platform ec2
    $ kato config set cloud_controller ec2_config /home/stackato/stackato/etc/ec2_config.yml

See the :ref:`cloud-init <cloudinit>` documentation for additional
information on customizing EC2 instance initialization.

OpenStack
^^^^^^^^^

On all of your ``controller`` nodes, run the following command::

    $ kato config get cloud_controller | grep openstack

And ensure the following keys are present and set to 'openstack'::

    primary_scaling_platform = openstack
    openstack_config = /home/stackato/stackato/etc/openstack_config.yml

If not, run the following commands::

    $ kato config set cloud_controller primary_scaling_platform openstack
    $ kato config set cloud_controller openstack_config /home/stackato/stackato/etc/openstack_config.yml


See the :ref:`cloud-init <cloudinit>` documentation for additional
information on customizing instance initialization in OpenStack Horizon.

Create the scaling configuration file
-------------------------------------

vSphere
^^^^^^^

Stackato includes everything you need to setup auto scaling on the vSphere platform.

The scaling part of Stackato talks directly to the vSphere API in the event of a scaling trigger,
which is determined by the health manager when no more DEA's are available for
deploying applications. Stackato also keeps a record of what hosts are hosting which DEA, so it can round-robin
DEA's on all your available hosts, without overloading any single one
and performing runtime health checks on the host to verify it is suitable for
deployment.

The scaling <-> vSphere API layer needs to know a few additional details before
it can succesfully talk to your vSphere setup.

Create the following file on all controller nodes::

    ~/stackato/etc/vcenter_config.yml

And place the following yaml template there:

.. code-block:: yaml

  --- 
    server: vcenter.domain.com
    user: username
    password: password
    https: true
    port: 443
    insecure: true
    path: /sdk
    datacenter: DataCenter
    datastores: "Datastore name"
    template: "Your-Template-Name"
    vm_name_prefix: "auto-scaled-dea"

As this is just a template, you will need to replace the values with some of your
own:

vSphere settings
^^^^^^^^^^^^^^^^

* **server:** This is the endpoint of your vCenter, and should be a resolvable
  URL.
* **user:**  The user you would normally login to vCenter with.
* **password:**  The password you would normally login to vCenter with.
* **https:**  It is recommended you enable HTTPS for logins, and this should
  remain as 'true'
* **port:**  Change to '80' if you are not using HTTPS.
* **insecure:**  If left as 'true' it allows the use of self-signed SSL certs
  with vCenter.
* **path:**  Unless you have a custom vCenter install, this setting can be left
  as its default value.
* **datacenter:** This is the case-sensitive name of the datacenter on which
  the cloud controller and DEA template reside. It is **not** the name of any
  of your ESXi hosts.
* **datastores:** This is the case-sensitive name of the datastores to use as the
  file backing for the newly scaled VM. If you supply a json array value, such 
  as ``datastores: [ "datastore-1",  "datastore-2"]`` then one will be chosen at
  random when scaling occurs.
* **template:**  This is the name of the DEA template you just created, which
  will be deployed round-robin to all your available ESXi hosts when a scaling
  event is triggered by Stackato.
* **vm_name_prefix:** Prefix the name of all autoscaled VMs with this string,
  for easier identification in your cluster.

EC2 / OpenStack Configuration File
----------------------------------

EC2 and OpenStack follow a similar pattern as vSphere to enabling auto scaling. The cloud 
controller(s) will talk directly with the EC2-compatible API to spin up an new AMI instance 
whenever a scaling event is triggered.

For Openstack, the settings here can normally be found in your OpenStack/Nova credentials file,
with the keys normally prefixed with ``EC2_*``. The ``key`` setting for OpenStack normally
corresponds to the ``NOVA_API_KEY`` setting.

In the ``ec2_config.yml`` or ``openstack_config.yml`` file as set in :ref:`scaling_cc_config`
you should insert and modify the following template:

.. code-block:: yaml

    ---
    ami: <AMI_name>
    instance_type: m1.large
    security_group: <security_group>
    key: my-stackato-ec2
    url: <EC2 compatible API URL>
    accesskey: <EC2 access key>
    secretkey: <EC2 secret key>

EC2 / OpenStack Settings
^^^^^^^^^^^^^^^^^^^^^^^^

* **AMI:** This is name of the AMI image that should be deployed when a scaling event
  is triggered.
* **instance_type:** This is the EC2 instance type. Generally for DEA nodes, the m1.large
  type is recommended. See: `EC2 Instance Types <http://aws.amazon.com/ec2/instance-types/>`_
  for all the available types.
* **security_group:** The default security group to apply to the new instance, as defined
  in your AWS console.
* **url** This is the URL of the EC2 compatible API that you wish to
  use. For OpenStack, the ``url`` should be in a similar format to the
  ``EC2_URL`` provided in the OpenStack credentials, with the full path
  provided. For example::

    EC2_URL="192.168.69.234/services/Cloud"

  On EC2 itself the URL would include the region. For example::

    EC2_URL="us-west-2.ec2.amazonaws.com"

* **key** This is the name of your keypair credentials, as named in your AWS console.
* **accesskey** & **secretkey:** The keypair credentials used to access the EC2
  API under your account. For more information on EC2 credential management see:
  `EC2 Credentials <http://docs.amazonwebservices.com/AWSEC2/latest/UserGuide/using-credentials.html>`_.

Once the configuration yml file has been updated, save it and then restart the 
controller and health manager::

	$ kato restart cloud_controller health_manager

You can then proceed to test the scaling events by pushing an app with many
instances, and at least 256MB assigned.  For example::

	$ stackato push node-env --instances 10 --mem 256

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

