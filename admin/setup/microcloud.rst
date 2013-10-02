.. _quickstart-setup-server-microcloud:

Micro Cloud VM
==============

By default, the Stackato VM starts as a single node "micro cloud" with a
base set of roles already running and ready to use. This can be used as
a test bed for pushing applications still in development. If your
program deploys successfully to a Stackato micro cloud, it will deploy
to any Stackato PaaS of the same version. The application hosting
environment is the same in all aspects except scale.

This section describes running the Stackato VM as a micro cloud. To get started building a cluster, see the :ref:`Cluster Setup <cluster-setup>` section.

Download the VM
---------------

.. include:: ../common/download-server.inc

Import the VM
-------------

The steps for importing and starting the Stackato VM will vary depending
on which hypervisor and OS you are using. Follow the steps in the
relevant guide below, then continue with Initial Configuration:

.. include:: ../common/vm-list.inc

Start the VM
------------

On first boot, the Stackato VM generates a hostname in the form
``stackato-xxxx.local`` which is displayed on the hypervisor console. It
receives its IP address via DHCP and broadcasts the generated hostname
on the local subnet via :term:`multicast DNS`.

You will use this hostname to connect to open the :ref:`Management
Console <management-console>` in a browser or connect with the
:ref:`Stackato CLI client <client>`.

.. note::

    The default password for the ``stackato`` system user is
    **stackato**. This password is changed automatically when you set up
    the first administrative user in the Management Console.
    Once you've set up the primary Stackato admin account, use that
    account's password when logging in at the command line.

.. _quickstart-config-nat:

.. index:: NAT

NAT vs. Bridged Networking
^^^^^^^^^^^^^^^^^^^^^^^^^^

.. include:: ../common/nat.inc


.. _quickstart-dns-mdns:

DNS vs. mDNS
^^^^^^^^^^^^

By default, the Stackato VM broadcasts its generated hostname via
multicast DNS. This mDNS/DNS-SD broadcast address (e.g.
*stackato-xxxx.local*) is intended for micro clouds running on a local
machine or subnet. To use the VM on a remote subnet, the server may need
one or more of the following:

* a :ref:`wildcard DNS A or CNAME record <server-config-dns>`,
* a :ref:`fixed IP address <server-config-static-ip>`
* a :ref:`hostname that works with xip.io <quickstart-xip-io>`
* :ref:`changes to the Windows hosts file <windows-hosts>`

See the :ref:`Detailed Configuration <server-configuration>` section for
instructions on setting up the Stackato VM in these situations.

.. note::

  Windows does not properly support mDNS hostname resolution. You will
  need to use the xip.io service, :ref:`update the Windows hosts file
  <windows-hosts>`, or create a DNS record in order to target the API
  endpoint, push applications, and resolve the deployed applications.

.. _quickstart-console:

Management Console
------------------

The :ref:`Management Console <management-console>` is Stackato's web interface. 

When the Stackato server finishes the start-up process, the 
hypervisor's :term:`tty console` will display the URL of the Management
Console. Enter this URL into your web browser. 

.. note::
  The SSL certificate for the Stackato Management Console is
  self-signed. You will need to manually accept this certificate in your
  browser. See the :ref:`HTTPS section <server-config-https>` of the
  Admin Guide for information on using your own certificate.

The Management Console will load, and you will be prompted to create the
first administrative user for the system. Use these account credentials
to push applications, create additional users, and configure the system.

.. note::
  The password you set here will become the new password for the
  ``stackato`` system user for access via SSH or the hypervisor console.


Adding Users
------------

The easiest way to add additional users is in the :ref:`Users section
<console-users>` of the :ref:`Management Console <management-console>`,
but you can also use the ``stackato`` client:

.. parsed-literal::
  
    $ stackato add-user *email@example.com* [--passwd *password*]


.. _quickstart-enable-services:

Enabling Services
-----------------

In order to leave as much memory as possible available for user
applications, the micro cloud starts with a number of services
disabled by default:

* Memcached
* Redis
* Postgres
* RabbitMQ
* MongoDB

You can enable them individually by clicking the **Configure Roles**
button in the :ref:`Cluster Admin <console-cluster-admin>` section of
the Management Console.


Using Stackato
--------------

An administrator's view of the Management Console provides access to
most commonly configured system settings, control over the roles that
are running on the VM, and views of the system log streams and other
metrics.

End users of the system without admin privileges have a more limited
view, showing only information for their user or group accounts.
Deploying applications and consuming system services is covered in the
Stackato User Guide.


Resolving VM Hostname Without mDNS
----------------------------------

.. _quickstart-xip-io:

Using xip.io
^^^^^^^^^^^^

The quickest way to set up wildcard DNS resolution is to use the `xip.io
<http://xip.io>`_ (or similar) service. This service provides wildcard
DNS resolution for addresses with the format: ``<IP address>.xip.io``

To change the hostname of the Stackato VM, log in to the VM via SSH or
the hypervisor console (username: 'stackato', default password:
'stackato'), then run ``kato node rename ...`` with external IP
address and the 'xip.io' domain appended. For example:

  $ kato node rename 10.9.8.7.xip.io

This will change the system hostname and reconfigure some internal
Stackato settings. The xip.io DNS servers will resolve the domain
'10.9.8.7.xip.io' and all sub-domains to '10.9.8.7'. This works for
private subnets as well as public IP addresses.


.. _windows-hosts:

.. index:: windows hosts file

Updating the Windows Hosts File
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

If you are running Windows, :term:`multicast DNS` discovery of a locally
running Stackato micro cloud will not generally work. One solution is to
manually set the mapping for the API endpoint and for each application
in the Windows *hosts* file.

.. note::

  :ref:`Using xip.io <quickstart-xip-io>` for hostname resolution is the
  easiest way to set up a Stackato micro cloud VM if mDNS is not an
  option. 

To modify the *hosts* file use the :ref:`stackato host
<command-host-file>` command or open the file located at::

    %SystemRoot%\System32\drivers\etc\hosts
    
The *hosts* file typically has some comments and one or two entries. Add
your new entries to the bottom of the file on their own lines.

You'll need to add an entry for the API endpoint and for each
application, along with their corresponding IP addresses. To determine
the IP address of the Stackato server, open the server window and enter
the command::

    $ ifconfig
    
Then, if for example your IP address is ``192.168.68.54``, the API
endpoint is ``api.stackato-xxxx.local`` and you have an app called
``myapp.stackato-xxxx.local``, you would enter the following two lines::

    192.168.68.54 api.stackato-xxxx.local
    192.168.68.54 myapp.stackato-xxxx.local


.. _quickstart-uninstall:

Uninstalling the VM
-------------------

Using the Stackato VM makes no changes to the underlying host operating
system.

If you wish to remove it, simply select the VM in your hypervisor and
select **Remove...** or **Delete...** as appropriate.
