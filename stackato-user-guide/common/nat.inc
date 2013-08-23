.. comment: NAT vs. Bridged Networking

The VMware and VirtualBox start virtual machines with :term:`NAT`
networking enabled by default.

If you are using VirtualBox to run the Stackato VM, configuring
"Bridged" networking before starting the VM is the simplest way to set
it up. If you need to run in "NAT" mode, configure port forwarding as
per the `VirtualBox documentation
<http://www.virtualbox.org/manual/ch06.html#network_nat>`__. 

Bridged networking exposes the VM through the hypervisor host system to your local network. This makes 
it easier to connect with Stackato servers running on other hosts, but should only be done on 
trusted networks. 

NAT networking exposes the VM only to the host system (unless routing through the host is 
configured). This is a preferable configuration if you are operating on an untrusted network.

.. note::
	Multiple hosts broadcasting the same name via mDNS on the same network can cause confusion 
	and network problems. If you plan on running multiple Stackato micro clouds on one network:
	
	  * Make sure the MAC address of each virtual machine is unique.
	  * :ref:`Change the hostname <server-config-hostname>` if not already unique, or
	  * use NAT networking, or
	  * :ref:`configure DNS manually <server-config-dns>`.

