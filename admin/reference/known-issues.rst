.. index:: Known Issues

Known Issues
============

.. _known-issues-app-import:

Importing Applications from Stackato 2.10
-----------------------------------------

Stackato 3.0 can import user applications from Stackato 2.10 systems,
and redeploy them using the :ref:`Legacy Buildpack
<buildpacks-built-in>`.

On import from a 2.10 cluster, each application will be re-staged with
the default runtime for its framework (e.g. Python 3.2 apps will be
imported as Python 2.7 apps, Node 0.10 will be imported as 0.8, etc.).
Applications that require the newer runtime versions will fail to
redeploy, and need to be re-pushed by their owners.

.. _known-issues-ruby-buildpack:

Bundled Ruby Buildpack
----------------------

The bundled Cloud Foundry Ruby :ref:`buildpack <buildpacks>` installs an
outdated build of Ruby (1.9.3p327) with a known vulnerability
(`CVE-2013-4164
<https://www.ruby-lang.org/en/news/2013/11/22/heap-overflow-in-floating-point-parsing-cve-2013-4164/>`__).

For Ruby 1.9 applications, use `Heroku's version
<https://github.com/heroku/heroku-buildpack-ruby>`__ instead, as
specified in the :ref:`Custom Buildpacks <buildpacks-custom>`
documentation. This does not affect Ruby 2.0 applications.


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
