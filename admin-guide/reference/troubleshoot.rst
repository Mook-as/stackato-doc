.. _troubleshooting:

.. index:: Troubleshooting

Troubleshooting
===============

SSH to Failed Containers
------------------------

For troubleshooting and diagnostic purposes, it is possible to use
``stackato ssh`` to access a :term:`container` that has recently failed
or did not start correctly.  Containers are kept for one hour before
being reclaimed.  See the :ref:`Command Reference <command-ref-client>`
for details on the ``stackato ssh`` command.

Checking the Logs
-----------------

Most Stackato users will not have administrative access to the
server. If you need to troubleshoot an application deployment or runtime
failure, you can use the stackato client to view the stderr and stdout
log files. For example, if an application called ``myapp`` did not
deploy correctly, run the command::

	$ stackato logs myapp --all

This will generally show all errors encountered during deployment.

If you need to view another log file (e.g. one specific to your application), use the files 
command to explore the remote filesystem and return the contents of the files::

	$ stackato files myapp logs
	stderr.log                                 44B
	stdout.log                                101B
	myapp-err.log                             189B                        
	
	$ stackato files myapp logs/myapp-err.log

If that command should fail, try using the run command in combination with ls or cat::

	$ stackato run myapp cat ../logs/myapp-err.log

Server Log Files
----------------

If you need to troubleshoot or monitor Stackato logs with a third party, they can be found in the
`~/stackato/logs/*` directory on the Stackato server.  

These logs are under daily log rotation with the use of
`logrotate <http://manpages.ubuntu.com/manpages/man8/logrotate.8.html>`_.
Up to three days worth of compressed logs are kept before deletion of the
oldest archive.

To modify the log rotation, edit the */etc/logrotate.d/stackato* file as needed.  To disable 
Stackato log rotation, delete the file or move it to another folder.

health_manager.log
^^^^^^^^^^^^^^^^^^

The ``health_manager`` process is responsible for monitoring containers
and making sure they are relaunched if there's a problem. The
*health_manager.log* file contains information on all application
instances running on the system.

Sometimes you may see "CRASHED" notifications such as this::

    [2013-04-07 22:42:01.329571] hm - pid=2701 tid=5b3b fid=5cbf  DEBUG -- healthmanager.status: {"droplet":119,"state":"CRASHED"}

A CRASHED status means that the app crashed within the container and the
health_manager is no longer able to find a running process that looks
like that app (e.g. for a Node app, the node process isn't running; for
a Java app, there is no Java process, etc.). Most of the time this is a
problem with the app within the container.

Cross reference the droplet ID in the *dea.log* or *stager.log* files to
find the application name, then check the logs for the application (e.g.
'stackato crashlogs'). By far the most common cause of crashing apps is
a lack of memory, allocating more memory to an app is a good first step
to see if this fixes the problem.

Inspecting User Apps as an Admin
--------------------------------

Stackato Admin accounts have root-like priveleges. They can inspect all
user applications and service instances running on the system.

The `stackato group <command-users-groups-limits>` command can be used
by admin accounts to inspect applications and service instances for any
group or user. For example::

    $ stackato group jane.doe@example.com

This sets the scope of subsequent operations to the specified user. Use
``stackato group --reset`` to return to the scope of the logged-in admin
user.

System Diagnosis
----------------

There may be cases where resolving an issue requires a complete view of
the system metrics.  This functionality is provided by the
``stackato admin report`` command.
It generates a single file (by default named *<target>-report.tgz*)
that can be provided to the Stackato support team for analysis::

	$ stackato admin report

The file is several megabytes in size and will take a few seconds to generate.  
Send it, along with a detailed description of your problem, to ActiveState at:
	
	stackato-support@activestate.com

Specific Cases
--------------

**When pushing an app, the Stackato Client reports OK but app isn't running**
	
	The final output from pushing an app should look like::
	
		Staging Application: OK                                                         
		Starting Application: OK 
	
	If the app is being pushed to multiple instances, the client waits until at least one instance is
	running, and exits at that point (it does not wait until all instances are active).  If afterwards 
	you run ``stackato apps`` and find the Health status at 0%, it is because the app crashed after 
	starting successfully, not because the Stackato client reported incorrectly.
	
**DNS queries returning "connection refused"**

	This error is reported when the Stackato server does not have an IP Address.
	To investigate and resolve, try the following:

	* Verify the ARP tables on the hypervisor host, and on the Stackato server through its :term:`tty console`::

		$ arp -n

	* Check that the DHCP client is running::

		$ pgrep dhclient
		$ grep dhclient /var/log/syslog
	
	* Connect to the DHCP server and verify that it is receiving client requests from the Stackato server.

	* If your network is statically configured, assign an IP address on the Stackato server by editing the `interfaces <http://manpages.ubuntu.com/manpages/man5/interfaces.5.html>`_ file::

		/etc/network/interfaces
