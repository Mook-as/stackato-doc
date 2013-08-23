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
