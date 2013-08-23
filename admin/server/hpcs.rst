.. _vm-hpcs:

.. index:: HPCS
.. index:: HP Cloud Services

HP Cloud Services
=================

Stackato is available as a public server image on `HP Cloud Services
<http://hpcloud.com/>`_. You can run a single instance of the Stackato
VM under the terms of the `Micro Cloud License Agreement
<http://www.activestate.com/stackato/micro-cloud-license-agreement>`_.
If you intend to create a production Stackato cluster, `contact
ActiveState <http://www.activestate.com/get-quote>`_ about Stackato
Enterprise.

.. _server-vm-hpcs:

Initial Setup
-------------

1. Log in to `HP Cloud Services console <https://console.hpcloud.com/>`_.
   Choose an HP Cloud Compute region to run the Stackato server image. The
   image can be launched in any Availability Zone:

2. Click **Manage** in the zone of your choice.

.. _server-vm-hpcs-firewall:

.. index:: HPCS Security Groups

Security Group Settings
-----------------------

Before launching a Stackato VM instance, you will need to create a security
group which exposes only the necessary network ports (or use/modify an existing
group with the properties described below).

Security groups can be managed from the `Cloud Services Console
<https://console.hpcloud.com>`_, `nova commands
<https://docs.hpcloud.com/cli/nova>`_, or `API
<https://docs.hpcloud.com/api/compute>`_ (supporting JSON and XML).

If you are using the HP Cloud Services Console, click **Security
Groups** then the **Add Group** button. Specify a name (e.g.
"stackato-micro") and a short description for the new group, then
click **Create**.

.. image:: ../images/stackato-hpcs-security-group.png
   :alt: HP Cloud Security Group - Stackato
   :class: shadow
   :width: 100 %
   
If you are :ref:`creating a cluster <cluster-setup>` using only the Console,
you must to expose ports **1/tcp** through **65535/tcp** to the entire
``10.0.0.0/8`` subnet (less secure) or do so for each IP address in the
cluster explicitly. 

.. include:: ../common/harbor-ports.inc

.. note::
  See :ref:`Stackato port requirements <cluster-config-ports>` for
  details on port usage.
  
.. index:: python-novaclient

.. _server-vm-hpcs-nova:

python-novaclient
^^^^^^^^^^^^^^^^^

A more convenient way to configure security groups uses the
`python-novaclient <https://launchpad.net/python-novaclient>`_ command
line utility to allow full port access *only* between hosts in the Stackato
security group itself.

The `HP Extended Python Novaclient <https://docs.hpcloud.com/cli/nova>`_
is the recommended version to use with HP Cloud Services. The standard
version is available from the `Nova project page
<https://launchpad.net/nova>`_ or via ``pip`` or ``pypm``.

You will need to set up some local environment variables for ``nova`` to
interact with your account. For example:

.. parsed-literal::

  OS_USERNAME='*admin@example.com*'
  OS_PASSWORD='*passwd*'
  OS_TENANT_NAME='*admin@example.com*'
  OS_AUTH_URL=https://region-a.geo-1.identity.hpcloudsvc.com:35357/v2.0/
  NOVA_VERSION=1.1
  NOVA_REGION_NAME=az-*n*.region-a.geo-1

The following command would configure the Stackato security group to
allow connections on all ports within the group:

.. parsed-literal::

	# nova secgroup-add-group-rule Stackato Stackato --ip_proto tcp --from_port 1 --to_port 65535
  
See the `HP Extended Python Novaclient
<https://docs.hpcloud.com/cli/nova>`_ page for a general overview.

.. note::

	On 2012-05-28, HP Cloud Services reported a vulnerability in Nova API handling.
	When a security group is created that uses a protocol defined in the incorrect case
	(e.g. "TCP" rather than "tcp") it causes a later string comparison to fail.
	This leads to Security Groups not being set correctly.

.. index:: HPCS Launch Instance

Launching the Instance
----------------------

Click **Manage Servers** and choose an HPCS server **Flavor** of at least *standard.small (2GB memory)*.

Set the **Security Group** to the one created or modified above.

Under **Install Image** select the most recent *ActiveState Stackato* image available.

Leave the **Key Pair** as *hpdefault* (it won't be needed for the basic setup), and **Instances** as 1.

.. image:: ../images/stackato-hpcs-create-server.png
   :alt: HP Cloud Dashboard 
   :class: shadow
   :width: 100 %

When ready, select **Create** to start the instance. The new Stackato instance should appear as "Active" under Running Instances within a few minutes. Take note of the Fixed Public IP. This will be used to configure DNS entries for Stackato.

.. index:: HPCS DNS

Configuring DNS
---------------

Stackato requires :ref:`DNS mappings <server-config-dns>` to work properly in a cloud hosting environment.

For example, if you wanted your Stackato PaaS to be named "stackato-test" on your existing domain "example.com", you would insert the following in your DNS zone file::

	stackato-test   IN  A     192.0.43.11
	*.stackato-test IN  CNAME stackato-test

The first line uses the Fixed Public IP address assigned by HPCS or a
Floating Public IP that you have assigned to the Stackato instance.

The second line is a wildcard entry, used for "api" (the API Endpoint
used by clients) and the sub-domains created for the applications
deployed to Stackato.
		
If you don't have an existing domain, or want to test with an arbitrary
domain, try using a dynamic DNS provider with wildcard sub-domain
assignment (e.g. `ChangeIP.com
<https://www.changeip.com/freedomains.asp>`_) or use `xip.io
<http://xip.io/>`_ to use a wildcard DNS name based on the IP address.

.. _server-vm-hpcs-config:

.. index:: HPCS Configuring Stackato

Configuring Stackato
--------------------

Log in to the instance using ``ssh`` with the username `stackato` and default password `stackato`::

	$ ssh stackato@stackato-test.example.com
  
Do *not* change the ``stackato`` password at this point - it will happen in the next step.

Use the :ref:`kato <kato-command-ref>` utility to set the server's
hostname and internal Stackato configuration to match the DNS name you
are using. For example::

  kato node rename stackato-test.example.com
  

.. index:: HPCS Create Admin

.. _server-vm-hpcs-admin:

Create Admin User
-----------------

Copy the address set above into your web browser's address bar and load
the page. The SSL certificate for the Stackato Management Console is
self-signed, so you will need to manually accept this certificate in
your browser. See the :ref:`HTTPS section <server-config-https>` for
information on using your own certificate.

The Stackato :ref:`Management Console <management-console>` will prompt
you to create the first admin user for the system. Set a username (an
email address) and password, read and accept the Terms of Use Agreement,
and click **Complete Setup**.

.. note::
  **The password you choose here becomes the login password for the**
  ``stackato`` **user on the VM** (e.g. for ``ssh`` access).

Once you have created the first admin user, you can add additional users
and groups, start pushing applications, and configure the system further
using the Management Console. 
