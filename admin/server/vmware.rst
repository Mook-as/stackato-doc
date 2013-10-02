.. _vm-vmware:

.. index:: VMware

VMware Fusion/Player
====================

*Recommended version*: **VMware Fusion / VMware Player 4** or newer

Initial Setup
-------------

#. Obtain `VMware Fusion or VMware Player <https://my.vmware.com/web/vmware/downloads>`_.
#. Install it on the system you will use as the virtualization host.
#. Launch it on the virtualization host.
#. In the File menu, click Open... or Open a Virtual Machine.
#. Select your copy of the the Stackato VM.
#. When prompted with the question "Did you move this virtual machine, or did you copy it?" select "I copied it".
#. Click Settings or Edit virtual machine settings:
	* Optional: Change the Network settings from "NAT" to "Bridged"
	  (see :ref:`NAT vs. Bridged Networking <quickstart-config-nat>`.)
	* Optional: Increase the memory allocated to the VM
	  (necessary if you plan on running Java applications.)
#. Start the VM.

