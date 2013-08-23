.. _vm-virtualbox:

.. index:: VirtualBox

VirtualBox
==========

Recommended version: **VirtualBox 4.1** or later

Initial Setup
-------------

#. Get `VirtualBox <https://www.virtualbox.org/>`_.
#. Install it on the system you will use as the virtualization host.
#. Launch the Oracle VM VirtualBox Manager application on the virtualization host.
#. In the File menu, click Import Appliance.
#. In the Appliance Import Wizard dialog, click Choose and select your Stackato VM :term:`OVF` file.
   Click Continue.
#. A list of configuration settings is displayed.
   Check the "Reinitialize the MAC address of all network cards" box, then press the Import button.
#. Once the VM is imported, select it and click the Settings button, and then the Network tab.
	* Change Adapter 1 from "NAT" to "Bridged Adapter"
	  (see :ref:`NAT vs. Bridged Networking <server-config-nat>`.)
	* Optional: Under Advanced, Press the "Refresh" icon beside the MAC Address field.
	  This could be necessary if multiple cloned VMs are being installed.
#. Start the VM.

.. note::
  If you want the VM to use NAT networking, you must also set up `port
  forwarding <http://www.virtualbox.org/manual/ch06.html#network_nat>`__
  to pass network traffic between the VirtualBox and the Stackato VM.
  :term:`Multicast DNS` discovery of the hostname
  ``stackato-xxxx.local`` will not work with NAT networking.
