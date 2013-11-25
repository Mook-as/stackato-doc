.. index:: Remote Debugging

.. _app-debug:

Remote Debugging
================

Different languages have different tools an protocols for remote
debugging, but most require a connection between the running application
code and the debugging tool or IDE on a port and protocol other than
standard HTTP(S).

Stackato makes this possible through the :ref:`Harbor port service
<port-service>`, and the :ref:`stackato push <command-push>` command has
a ``-d`` option to set up port forwarding for a remote debugging session
automatically.

See the :ref:`JPDA Debugging <java-web-debug>` section of the Java
deployment documentation for an example.

.. _app-debug-stackato-debug-command

STACKATO_DEBUG_COMMAND
----------------------

The stackato client can automatically start a local debugger client or
IDE instance with connection information for a newly pushed application.

When the ``-d`` debugging option is given to :ref:`stackato push
<command-push>` command, the client looks for a STACKATO_DEBUG_COMMAND
environment variable. If present, the command specified in that variable
is run after the push completes as child process in the foreground (i.e.
blocking the parent ``stackato`` process) in the local application
source directory.
  
Special %HOST% and %PORT% variables can be used in this command, which
are replaced with the hostname or IP address and port number of the new
Harbor debugging service.

