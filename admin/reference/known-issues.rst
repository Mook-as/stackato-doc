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


Service Gateway Log Errors in Maintenance Mode
----------------------------------------------

With Stackato set in :ref:`Maintenance Mode <console-settings>`, all
"_gateway" processes will report the following error once per minute::

  Failed registering with cloud controller, status=503

This is normal, and can be safely ignored. The service nodes will 
reconnect once the Controller is taken out of Maintenance Mode.


Nodes with FATAL or perpetually STARTING processes
--------------------------------------------------

If the Core node of a Stackato cluster is offline for more than 90
seconds, ``kato status`` will show processes on other nodes (systail,
apptail, router and others) in a FATAL or (hung) STARTING state. These
processes will not automatically reconnect to the Core node.

To correct this, run ``kato start`` (for FATAL processes) or ``kato
restart`` (for STARTING processes) on all affected nodes. 


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


Community Forums
----------------

Please keep up to date with the latest Known Issues, FAQs and announcements in our `online Stackato forums <http://community.activestate.com/forum/stackato>`_.
