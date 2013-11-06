.. index:: Known Issues

Known Issues
============

First Admin User Setup using LDAP and AOK (3.0 Beta)
----------------------------------------------------

If you plan to set up LDAP authentication via AOK, it's best to complete
the "Set Up First Admin User" form shown by the web Management Console
before configuring LDAP authentication. This creates an administrative
user, and changes the password of the 'stackato' user on the VM to match
whatever was entered in the form.

You may use either a temporary username (e.g. "firstuser") which will be
deleted later, or use the LDAP username you will ultimately use once AOK
is configured.

Once the first user has been created:

* Log in to the micro cloud VM or Core node as the 'stackato' user (with
  the password set previously)

* :ref:`Configure AOK <aok-configuration>` to use LDAP

* Set the ``admin_user`` key with the desired LDAP admin username::

    $ kato config set aok strategy/ldap/admin_user <username>

  This user will be granted admin privileges when logging in for the
  first time.
  
* If you created a temporary admin user, delete it at this point.


Regular LDAP User Setup (3.0 Beta)
----------------------------------

New users logging in to the Management Console for the first time using
LDAP authentication will not be a member of any organization (and won't
be able to do anything). An admin will have to add each user to an
organization after their initial login.


Nodes with FATAL or perpetually STARTING processes
--------------------------------------------------

If the Core node of a Stackato cluster is offline for more than 90
seconds, ``kato status`` will show processes on other nodes (systail,
apptail, router and others) in a FATAL or (hung) STARTING state. These
processes will not automatically reconnect to the Core node.

To correct this, run ``kato start`` (for FATAL processes) or ``kato
restart`` (for STARTING processes) on all affected nodes. 

Hypervisor network subnet conflict
----------------------------------

The most obvious symptom is that none of your apps will start successfully, will timeout and Stackato will show general network flakiness.

If you are running the Stackato VM in NAT networking mode, the hypervisor may have issued the VM with an IP that conflicts with the internal Stackato network. You can verify if this has happened on your Stackato installation by logging into it and running: ::

  $ ifconfig | grep 'inet addr:' | cut -d: -f2 | awk '{ print $1}'

If there are two addresses listed beginning with 192.168.3.x then you will have to take some additional steps to resolve the conflict:

VMware Fusion 4
~~~~~~~~~~~~~~~

Open up the following file and change the vmnet8 subnet, for example: ::

  $ sudo vim /Library/Preferences/VMware\ Fusion/networking

Change: ::

  answer VNET_8_HOSTONLY_SUBNET 192.168.3.0

To: ::

  answer VNET_8_HOSTONLY_SUBNET 192.168.120.0

or another subnet that is **not** 192.168.3.0.

Then quit and restart Fusion or run: ::

  $ sudo "/Applications/VMware Fusion.app/Contents/Library/services.sh" --stop
  $ sudo "/Applications/VMware Fusion.app/Contents/Library/services.sh" --start


VirtualBox 4.x
~~~~~~~~~~~~~~~

Shutdown the Stackato VM, and run the following command: ::

  $ VBoxManage modifyvm "Stackato-<Version>" --natnet1 "192.168.120/24"

Replace the VM <version> as it is shown on the VirtualBox main GUI. Upon restarting the VM you should now have a 192.168.120.x IP.


VMware Workstation / Player
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

For VMware WorkStation or Player specific instructions please consult the relevant manual instructions here:

Workstation:

  http://www.vmware.com/support/ws55/doc/ws_net_nat_advanced.html

Player:

  http://ykyuen.wordpress.com/2009/09/17/vm-player-modify-the-dhcp-subnet-and-nat-gateway-ip/

Avoiding App Reliance on IP Addresses
-------------------------------------

Cluster configurations make use of private IP addresses for identifying the various cluster nodes.
Best practice is to avoid the literal use of these addresses wherever possible, as these addresses
are subject to change with cluster configuration.

If the VM instance can locally resolve a hostname rather than an IP address, it's generally best
practice to use the hostname.

If not, Stackato provides various
:ref:`environment variables <environment-variables>`
so that applications do not need to hardcode them at install time.
Some examples are ``VCAP_SERVICES``, ``STACKATO_SERVICES``, and ``DATABASE_URL``.
We strongly encourage their use.

A known issue is that some applications have install procedures that can't be configured to make
use of these variables.  If the server that's providing the app's database
(mysql_gateway/node for example) gets moved to another location, the only way for the app to
become aware of the new credentials is by restaging the app as noted below.
A restart isn't sufficient.

Choose one of the following according to need, either::

	$ stackato delete -n
	$ stackato push -n

or::

	$ stackato delete -n
	$ stackato update -n 

Another possible workaround in such cases is to write a script that will pull the credentials
from ``VCAP_SERVICES`` and update the app's config as needed, then add this script to the
pre-running hooks.

Cloud Controller Memory Usage
-----------------------------

The cloud_controller process will often consume too much memory on the system over time, causing it to become unresponsive. To address this, a memory_limit option has been added which will restart the process when the limit has been reached. The default setting is 50% resident memory, but this can be modified with :ref:`kato config <kato-command-ref-config>`. For example, to raise the threshold to 80%::

  $ kato config set cloud_controller memory_limit 80

Setting memory_limit to 0% will turn this behaviour off, preventing restarts.

Cloud Events, missing errors and warnings
-----------------------------------------

Errors and warnings from router2g and harbor_proxy_connector are not
displayed by Cloud Events. This will be fixed in future releases.

Community Forums
----------------

Please keep up to date with the latest Known Issues, FAQs and announcements in our `online Stackato forums <http://community.activestate.com/forum/stackato>`_.
