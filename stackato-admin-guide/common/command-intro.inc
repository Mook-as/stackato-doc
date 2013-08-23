.. comment - Command Intro

The Stackato server has one user account initally::

	Username: stackato
	Password: stackato

If the Stackato server is running on a publicly routable network, the password should be 
changed as soon as possible.

.. note::
	The password of the ``stackato`` account is changed to match the first
	user created in the Management Console. If you've created this
	"primary admin" user, use that password instead.

Command access to the Stackato server is available in several ways:

* Over the hypervisor's :term:`tty console`.

* The :ref:`Stackato Client <command-ref-client>` command, which in addition to specialized functions can provide remote shell access to the server::

	$ stackato target stackato@stackato-xxxx.local
	$ stackato ssh api

* The familiar ``ssh`` command::

	$ ssh stackato@stackato-xxxx.local

.. note::
	For ssh access on Windows, we recommend
	`MSYS <http://sourceforge.net/apps/trac/mingw-w64/wiki/MSYS>`_.
  
On the server, the control command for Stackato is called ``kato``.
It is used for configuration and node management procedures
such as start, stop, role specialization, and status checks.
For a complete list of options, see :ref:`kato-command-ref`.
