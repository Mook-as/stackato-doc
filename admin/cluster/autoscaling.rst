.. _autoscaling:

.. index:: DEA Auto Scaling

DEA Auto Scaling
================

Stackato can automaticaly add DEA nodes to a cluster to handle
increasing numbers of user application instances. This feature, called
DEA Auto Scaling, is available for clusters running on vSphere, EC2, or
OpenStack.

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

DEA Scaling configuration file
------------------------------

DEA auto scaling configuration varies by orchestration/IaaS platform:

vSphere
^^^^^^^

Stackato uses the vSphere API to create the new DEA instances, and needs
some configuration specific to your installation. 

On the Primary node (i.e. the VM running Controller and Health Manager),
create a *vcenter_config.yml* file in the */s/etc/* directory with the
following template contents:

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

This is just a template. You will need to replace the values with some
of your own:

* **server:** The endpoint of your vCenter. Should be a resolvable URL.
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

EC2 & OpenStack
^^^^^^^^^^^^^^^

EC2 and OpenStack follow a similar pattern as vSphere to enabling auto scaling. The cloud 
controller(s) will talk directly with the EC2-compatible API to spin up an new AMI instance 
whenever a scaling event is triggered.

For Openstack, the settings can normally be found in your OpenStack/Nova credentials file,
with the keys normally prefixed with ``EC2_*``. The ``key`` setting for OpenStack normally
corresponds to the ``NOVA_API_KEY`` setting.

On the Primary node (i.e. the VM running Controller and Health Manager),
create an *ec2_config.yml* or *openstack_config.yml* file in the
*/s/etc/* directory with the following template contents:

.. code-block:: yaml

    ---
    ami: <AMI_name>
    instance_type: m1.large
    security_group: <security_group>
    key: my-stackato-ec2
    url: <EC2 compatible API URL>
    accesskey: <EC2 access key>
    secretkey: <EC2 secret key>


This is just a template. You will need to replace the values with your
own:

* **AMI:** This is name of the AMI image that should be deployed when a
  scaling event is triggered.
* **instance_type:** This is the EC2 instance type. Generally for DEA
  nodes, the m1.large type is recommended. See: `EC2 Instance Types
  <http://aws.amazon.com/ec2/instance-types/>`_ for all the available
  types.
* **security_group:** The default security group to apply to the new
  instance, as defined in your AWS console.
* **url** This is the URL of the EC2 compatible API that you wish to
  use. For OpenStack, the ``url`` should be in a similar format to the
  ``EC2_URL`` provided in the OpenStack credentials, with the full path
  provided. For example::

    EC2_URL="192.168.69.234/services/Cloud"

  On EC2 itself the URL would include the region. For example::

    EC2_URL="us-west-2.ec2.amazonaws.com"

* **key** This is the name of your keypair credentials, as named in your
  AWS console.
* **accesskey** & **secretkey:** The keypair credentials used to access
  the EC2 API under your account. For more information on EC2 credential
  management see: `EC2 Credentials
  <http://docs.amazonwebservices.com/AWSEC2/latest/UserGuide/using-credentials.html>`_.


Enabling Auto-Scaling in the Health Manager
-------------------------------------------

Run the following command on the Primary node::
    
    $ kato config set health_manager enable_autoscaling true

After saving this change, restart the Health Manager::

    $ kato process restart health_manager

You should then start seeing some scaling information in the Health
Manager's log file::

    $ kato log tail health_manager

Once confirmed you can then proceed to configure the controller.


.. _scaling_cc_config:

Configuring the Controller
--------------------------

The Controller requires a few settings before auto-scaling can be
triggered, most of which are loaded from the YAML files created above.

These commands should be run on the node where the YAML files were
created, but the configuration changes are distributed to all Controller
nodes:

vSphere
^^^^^^^

::

  $ kato config set cloud_controller_ng primary_scaling_platform vcenter
  $ kato config set cloud_controller_ng vcenter_config /home/stackato/stackato/etc/vcenter_config.yml

EC2
^^^

::

  $ kato config set cloud_controller_ng primary_scaling_platform ec2
  $ kato config set cloud_controller_ng ec2_config /home/stackato/stackato/etc/ec2_config.yml

See the :ref:`cloud-init <cloudinit>` documentation for additional
information on customizing EC2 instance initialization.

OpenStack
^^^^^^^^^

::

  $ kato config set cloud_controller_ng primary_scaling_platform openstack
  $ kato config set cloud_controller_ng openstack_config /home/stackato/stackato/etc/openstack_config.yml


See the :ref:`cloud-init <cloudinit>` documentation for additional
information on customizing instance initialization in OpenStack Horizon.


Restarting the Controller and Health Manager
--------------------------------------------

When all settings have been changed, restart the Health Manager and
Cloud Controller processes::

	$ kato process restart health_manager
	$ kato process restart cloud_controller
  
If you have additional nodes running the Controller role, log in to them
and run::

  $ kato process restart cloud_controller_ng 

You can then test scaling events by pushing an app with many instances,
and at least 256MB assigned. For example::

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

