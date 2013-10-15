.. index:: Application Logging

.. _application_logs:

Application Logs
================

Logs for applications running on Stackato are aggregated into streams,
so that data from multiple instances can be viewed together and
filtered. Application log streams can be accessed via:

* the :ref:`Management Console <management-console>` using the **View
  Logs** button on the application Details page, or 

* the :ref:`stackato logs <command-logs>` command

* application log :ref:`drains <application_logs-drain>`

Log streams are tailed output from actual log files in each application
container, generally found in the */app/logs/* directory. These files
can be accessed with the :ref:`stackato files <command-files>` command or
from the Application details page of the :ref:`Management Console
<management-console>`.

.. note::
  These files are not automatically rotated. For long-running
  applications or verbose logs, you should :ref:`rotate them
  <application_logs-rotate>` to avoid filling up the application
  container's filesystem.

stackato logs
-------------

To view and application log stream, use the :ref:`stackato logs
<command-logs>` command::

    $ stackato logs myapp

To limit the number of lines displayed, use the ``--num`` option::

    $ stackato logs myapp --num 50

To view log stream as it is updated, use the ``--follow`` option::

    $ stackato logs myapp --follow

Log streams can be filtered on a number of parameters:

* **--text** does a glob pattern match on the log message

* **--instance** shows only logs from the specified application instances (starting at instance 0).

* **--filename** filters based on the log filename (e.g. 'stderr.log')

* **--source** shows only logs from the specified source ('app' or 'staging'). Without a source specified, the log stream includes staging and application logs as well as cloud events relevant to app.

The ``--json`` flag can be used to return each log line as a JSON object.


.. note::
    ``stackato logs`` buffers only 400 lines of the log stream history
    (i.e. lines generated prior to it being run). If you need earlier
    log lines, use the :ref:`stackato files <command-files>` command to
    fetch the relevant log file from the *logs/* directory or create a
    log :ref:`drain <application_logs-drain>` preemptively (where
    possible).

.. _application_logs-drain:

stackato drain
--------------

The :ref:`stackato drain <command-drain>` command is used to create a
log drain which forwards application logs to external log aggregation
services, log analysis tools, or Redis databases. For example::

  $ stackato drain add myapp appdrain udp://logs.loggly.com:12345 

This creates a UDP drain called "appdrain" for the application "myapp"
which forwards all log messages and events for that application to
`Loggly <http://loggly.com/>`_ on port 12345.

The log drain URL can contain only:

* **scheme**: "udp://" or "tcp://"
* **host**: IP address or hostname
* **port**: number

Any additional parameters are discarded.

To delete the drain::

  $ stackato drain delete appdrain
  
Use the `--json` option send the log lines in JSON format::

  $ stackato drain add myapp jsondrain --json udp://logs.loggly.com:12346
  
To check the status of your application drains, use the ``stackato drain
list`` command.
  
.. note::

  If the service at the recieving end of the drain goes offline or
  becomes disconnected, Stackato will retry the connection at increasing
  intervals.

.. _app-logging-examples:

Log Drain Examples
------------------

Detailed instructions on how to use drains with third party log analysis
software or services:

* :ref:`Papertrail <app-logging-examples-papertrail>`
* :ref:`Loggly <app-logging-examples-loggly>`
* :ref:`Splunk <app-logging-examples-splunk>`

.. _app-logging-examples-papertrail:

Papertrail
^^^^^^^^^^

1. `Create an account for Papertrail <https://papertrailapp.com/plans>`_

2. In the Dashboard screen, click *Add Systems*.

.. image:: ../images/ppt1.png
    :class: shadow

3. In the Setup Systems screen under *Other log methods*, click *Alternatives*.

.. image:: ../images/ppt2.png
    :class: shadow

4. Choose option C: *My system's hostname changes* and give it a suitable name.

.. image:: ../images/ppt3.png
    :class: shadow

5. Note the **port number**. 

.. image:: ../images/ppt4.png
    :class: shadow

6. Enable application logging (via udp) by executing the following client command:

.. parsed-literal::

    stackato drain add *drain-name* udp://logs.papertrailapp.com:*port#*

.. _app-logging-examples-loggly:

Loggly
^^^^^^

1. `Create an account for Loggly <https://app.loggly.com/pricing>`_

2. Under *Incoming Data* tab, click *Add Input*.

.. image:: ../images/loggly1.png
    :class: shadow

3. In the Add Input screen:

* Choose *Syslog UDP or TCP*
* Choose *Combination Log Type*
* [Optional] For JSON Logging, Choose UDP or TCP **with Stripe** and enable **JSON Logging**. (for system logs)

.. image:: ../images/loggly2.png
    :class: shadow

4. If we want to accept logs from any Stackato nodes or applications modify Allowed Devices section:

* Click *Add device*

.. image:: ../images/loggly3.png
    :class: shadow

* Add IP Address 0.0.0.0/0 when prompted 

.. image:: ../images/loggly4.png
    :class: shadow

5. Turn off discovery since we allowed all devices. Also, note down the **port number**.

.. image:: ../images/loggly5.png
    :class: shadow

6. Run the following client command to create the log drain:

.. parsed-literal::

    stackato drain add *drain-name* udp://logs.loggly.com:*port#*

OR

.. parsed-literal::

    stackato drain add *drain-name* tcp://logs.loggly.com:*port#*

Loggly supports JSON format with minor configuration changes shown above.

.. _app-logging-examples-splunk:

Splunk
^^^^^^

1. `Setup Splunk Server <http://www.splunk.com/download>`_.

2. In the welcome screen, click *Add data*

.. image:: ../images/splunk1.png
    :class: shadow

3. Under *Choose a Data Source*, click “From a TCP port”. (or UDP)

.. image:: ../images/splunk2.png
    :class: shadow

4. In the Add new Source screen:

* Select a TCP/UDP port greater than **9999**
* Give it a suitable **Source name**.
* Set sourcetype to **Manual**
* Leave Source Type **empty**

.. image:: ../images/splunk3.png
    :class: shadow

5. Run the following client command to create the log drain:

.. parsed-literal::

    stackato drain add *drain-name* udp://*splunk-server-address*:*port#*

OR

.. parsed-literal::

    stackato drain add *drain-name* tcp://*splunk-server-address*:*port#*

Splunk supports JSON format without further configuration.


Hello World Custom Drain
^^^^^^^^^^^^^^^^^^^^^^^^

The command below starts a drain target server on a node, piping to a local file::

    nc -lk 0.0.0.0 10000 > log-output.txt

As long as that `nc` command runs, this will funnel logs from all drains targeting 
it into the file *log-output.txt*

Run the following client command to create the log drain:

.. parsed-literal::

    stackato drain add *drain-name* udp://*server-address*:*port#*

OR

.. parsed-literal::

    stackato drain add *drain-name* tcp://*server-address*:*port#*



.. _application_logs-rotate:

Rotating Application Log Files
------------------------------

Stackato does not automatically rotate application log files in
*/app/logs/*. However, you can add log rotation for these files yourself
using ``cron`` and ``logrotate``:

1. Add a cron key in *stackato.yml* to run ``logrotate``. Set
   STACKATO_CRON_INSTANCES to "all" to specify that the job should
   be run in all application instances. For example::

    env:
      STACKATO_CRON_INSTANCES: all
    cron:
      - 0 1 * * * /usr/sbin/logrotate --status /app/app/logrotate-status /app/app/app-logrotate.conf
      
   The ``--status`` option must be set because the ``stackato`` user
   does not have permission to update the default status file.

2. Add an *app-logrotate.conf* file to the base directory of your
   application to specify which log files to rotate, and and which
   ``logrotate`` options to use. For example::

    /app/logs/\*.log {
      daily
      compress
      copytruncate
      dateext
      missingok
      notifempty
      rotate 3
      maxage 7
      size 3M
    }
  
Programming languages, frameworks, and utilities handle logging
operations in different ways. Check for incompatibilities with
``logrotate`` before implementing log rotation scheme such as the one
above.


