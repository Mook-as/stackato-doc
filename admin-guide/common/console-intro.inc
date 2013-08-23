.. comment - Console Intro

The Stackato Management Console is a web interface that allows the
administration and management of the Stackato Server.

Your hypervisor provides :term:`tty console` access to each of its
virtual machines.  After startup, a Stackato VM displays::

	Stackato Management Console at
	
	https://stackato-xxxx.local
	
On a :term:`micro cloud` VM where the local network
supports :term:`multicast DNS`, the hostname will be
``stackato-xxxx.local``.  If you have configured the :ref:`hostname
<server-config-hostname>` and :ref:`DNS <server-config-dns>` of the
Stackato server manually, or are connecting to a server administered by
someone else, supply the assigned hostname instead
(e.g. ``api.stackato-test.example.com``).

Enter the URL into your web browser, and the Management Console will
load. The Console is supported on the following browsers:

* Chrome (WebKit)

* Firefox 4+

* IE9+

.. note::
	The SSL certificate for the Stackato Management Console is
	self-signed. You will need to manually accept this certificate
	in your browser. See the :ref:`HTTPS section <server-config-https>` for
	information on using your own certificate.

When you first access the Management Console, you will be prompted to
create a primary administrative user for Stackato. Enter an email
address as the username, set a secure password, then review and
accept the license agreement.

.. note::
  **The password you choose here becomes the login password for the**
  ``stackato`` **user on the VM** (e.g. for ``ssh`` access).
    
Once you've logged in, you can begin to add other users and admins,
enable and disable services, and generally set up the system to your
requirements.

Basic Stackato administration can be done through the Management
Console, but some maintenance and configuration tasks may need to be
done at the command line using the ``kato`` command. See
:ref:`kato-command-ref` for a full list of options.

The Stackato Management Console will periodically send non-identifying
pingbacks (Stackato version number and UUID) to ActiveState
servers to help us improve the web console experience. You can disable
this by setting ``theme_settings['pingback_allowed'] = false;`` in the
*settings.js* file described in the :ref:`Theming and Customization
<customize>` section.

