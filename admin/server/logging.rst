.. index:: Logyard

.. _logging:

Log Streams
===========

Application and system logs in Stackato are aggregated into streams
which can be viewed, tailed, filtered, and and sent via drains to other
log aggregators for archiving or analysis. There are three general types
of streams:

* **Application log streams**: application logs (plus relevant events) from all instances

* **System log streams**: Stackato and other system logs from all nodes (dmesg, dea.log, auth.log, etc.)

* **Cloud event streams**: cloud events from all nodes (see Cloud Events in the Management Console)

A **message** is a single log line or event in a stream.

Each message has a **key** which identifies *which* stream it belongs to
(see :ref:`Keys <logging-keys>` below).

.. index:: logyard processes

.. _logging-processes:

Logyard
-------

Log streams are handled by three processes which run on all Stackato nodes:

* **logyard**: listens for incoming log messages and forwarding them to
  a configurable list of drains

* **systail**: sends system logs (/s/log/\*, etc.) to **logyard** to be
  in turn forwarded to drains

* **cloud_events**: listens for all system logs and extracts vital events
  back to **logyard**

**apptail** is an additional process which runs only on DEA and Stager
nodes. It sends user application logs to **logyard**, injecting relevant
application-specific events from the **cloud_events** stream.


.. _logging-drains:

Drains
------

A "drain" is a receiver for a log stream. Logyard has three kinds:

* TCP (e.g. tcp://10.0.11.101:12345)

* UDP (e.g. udp://logs.papertrailapp.com:12345)

* Redis (e.g. redis://192.168.1.157:5000/)

* file (e.g. file:///s/logs/custom-drain-1.log)


.. _logging-drains-system:

System Drains
^^^^^^^^^^^^^

Drains for system log and cloud event streams can be added by admins
with the :ref:`kato log drain <kato-command-ref-log-drain-add>` command.
For example::

  $ kato log drain add --prefix systail.kato mydrain udp://logs.papertrailapp.com:12345

This creates a UDP drain that recieves messages from **kato.log**
(on all nodes in the cluster) and forwards them to `Papertrail
<https://papertrailapp.com/>`_ on port 12345.

The ``--prefix`` flag takes a :ref:`key <logging-keys>` prefix as its
argument.

To delete the drain::

  $ kato log drain delete mydrain

The :ref:`kato history <kato-command-ref-history>` command uses a
built-in drain which forwards to a Redis server on the Primary node.

The 'file' drain type will append to a local file. To overwrite the
file instead, add the 'overwrite=1' option::

  $ kato log drain add debug file:///s/logs/debug-1.log overwrite=1

.. _logging-format:

Log Format
^^^^^^^^^^

Log drains can emit entries in a variety of formats:

* verbatim (default): Log entries as they appear in the source log files (plain text).

* json: Log entries wrapped as JSON objects, with keys identifying each part of the entry.

* custom: Values of the specified JSON keys arranged in an arbitrary format.

For example, to add a drain with just the timestamp, application name and message::

  $ kato log drain add -p apptail -f '{{.HumanTime}} - {{.AppName}}: {{.Text}}' \
  > all-apps file:///s/logs/apptail-short.log

JSON keys are enclosed in double curly braces and prefixed with a
period. The spaces, hyphen, and colon here are functioning as
delimiters. The resulting entry might look like this::

  2013-01-22T16:01:14-08:00 - myenv: Application 'myenv' is now running on DEA 27da51

Different JSON keys are available in different :ref:`log streams <logging-keys>`: 

**apptail.**:

* Text: actual log line
* LogFilename 
* UnixTime: timestamp (seconds since  1 January 1970)
* HumanTime: formatted time
* Source: e.g. app, staging, stackato.dea, stackato.stager, appstore
* InstanceIndex: instance number
* AppID: unique id for this app
* AppName
* AppGroup
* NodeID: Host (DEA/stager) IP of this app instance

**event.**:

* Type: type of event (eg: process_stop) 
* UnixTime: timestamp
* Desc: human-readable description of this event (as shown in the Management Console)
* Severity: INFO, WARN, ERROR
* Info: event-specific information as JSON
* Process: the process generating the event
* NodeID: Node IP from which this event originated

**systail.**:

* Text: actual log line
* UnixTime: timestamp
* Name: name of the component (eg: redis_gateway)
* NodeID: Node IP from which this log line originated

You can see a list of the default drain formats using :ref:`kato config
get <kato-command-ref-config>`::

  $ kato config get logyard drainformats
  apptail: ! '{{.HumanTime}} {{.Source}}.{{.InstanceIndex}}: {{.Text}}'
  event: ! '{{.Type}}@{{.NodeID}}: {{.Desc}} -- via {{.Process}}'
  systail: ! '{{.Name}}@{{.NodeID}}: {{.Text}}'

These default log formats are used when the corresponding prefix is used
and no format options ("-f") are specified. For example ``kato drain add
-p systail.dea ...`` would format the drain using the 'systail' drain
format.

.. _logging-drains-save-format:

Saving Custom Log Formats
^^^^^^^^^^^^^^^^^^^^^^^^^

Custom formats for drains can be saved as a named type in the Logyard
configuration. To do this, add the formatting string to a new key in
logyard/drainformats. For example, to save the log format used in the
'all-apps' drain example above::

  $ kato config set logyard drainformats/simplefmt "{{.HumanTime}} - {{.AppName}}: {{.Text}}"

You can use this named format when setting up new drains. For example, a
shorter command for creating the 'all-apps' drain would be::

  $ kato log drain add -p apptail -f simplefmt all-apps file:///s/logs/apptail-short.log

A custom "systail" log stream might look like this::

  $ kato config set logyard drainformats/systail-papertrail '{{.HumanTime}} - {{.Name}}@{{.NodeID}} -- {{.Text}}'

This could be forwarded to a log analysis service::

  $ kato log drain add papertrail udp://logs.papertrailapp.com:45678 -f systail-papertrail
  
You can also change the default apptail, event, and systail drain
formats to modify the output of any drains using these prefixes (e.g.
:ref:`stackato drain <command-drain>`, Cloud Events in the Management
Console, and :ref:`kato log tail <kato-command-ref-log-tail>`
respectively).

.. _logging-drains-custom:

Custom Drains
^^^^^^^^^^^^^

You can add custom drains to Logyard to look for certain events or parse
certain log messages (e.g. tracking application push requests or user
logins). Examples of custom drains and more advanced usage of Logyard
can be found in the `Logyard Developer Guide
<https://github.com/ActiveState/logyard-devguide/blob/master/README.md>`_


.. _logging-drains-app:

Application Drains
^^^^^^^^^^^^^^^^^^

Drains for application log streams can be added by end users with the
:ref:`stackato log drain <command-drain>` command. See the
:ref:`Application Logs <application_logs>` section of the User Guide for
an example.


.. _logging-drains-timeouts:

Drain Timeouts
^^^^^^^^^^^^^^

If a drain gets disconnected (e.g. if the log aggregation service goes
down), Logyard will retry the connection at the following intervals:

* once every 5 seconds for 1 to 2 minutes
* once every 30 seconds for 5 minutes
* once every 1 minute for 10 minutes
* once every 5 minutes until connect or destroyed

This ensures that once connectivity is restored, the drains will
re-establish their connections within (at most) 5 minutes.

Application drains will retry for one day. Temporary drains (e.g. ``kato
tail``) will retry for 25 minutes. All other drains will retry
indefinitely.

These timeouts can be configured. To see a list of the configured
timeouts, use :ref:`kato config get <kato-command-ref-config>`. For
example::

  $ kato config get logyard retrylimits
  appdrain.: 24h
  tmp.: 25m
  
To set a timout (minimum 21m), use :ref:`kato config set
<kato-command-ref-config>`. For example, to set the timeout limit to 10
hours on all drains named with the prefix "papertrail"::

  $ kato config set logyard retrylimits/papertrail 10h

These limits will take effect on new drains, deleted/re-created drains,
or for all matching drains after ``kato process restart logyard`` has
been run on all nodes.

.. _logging-user-drain-limits:

User Drain Limits
^^^^^^^^^^^^^^^^^

For performance reasons, it's necessary to limit the total number of
concurrent user application drains running on a Stackato system. This is
set by default to 200. Once this limit is reached, users will see the
following notificition when trying to add a new drain::

  $ stackato drain add mydrain udp://loghost.example.com:12346
  Error 22002: No more drains can be added; contact your cluster admin.

To change the limit, set the ``max_user_drains`` in the cloud_controller
configuration using :ref:`kato config <kato-command-ref-config>`. For
example::

  $ kato config set cloud_controller max_user_drains 250
  
Another setting, ``read_limit``, defines the maximum number of bytes (in
MB) to read from the end of any given application log file (default
16MB). This is done to prevent performance problems when extremely large
log file drain sources are present when apptail (or the node) is restarted.

When this limit is reached, a warning such as the following will appear
in both the Cloud Events stream and the application's log stream::

    WARN -- [logspam] Skipping much of a large log file (stderr); size (26122040 bytes) > read_limit (15728640 bytes)

To change the system limit to 100MB (for example)::

  $ kato config set apptail read_limit 100


.. _logging-keys:

Keys
----

Each message in a log stream is prefixed with a key, identifying what
type of message it is or to which log stream it belongs. The following
keys are available for use in defining drains using the ``--prefix``
flag for :ref:`kato log drain add <kato-command-ref-log-drain-add>`).

Systail keys are :ref:`configurable <logging-systail-manage>`.

apptail
^^^^^^^

  apptail.<app.id>


event
^^^^^

* event.<eventname>

  * process_stop

  * process_exit

  * kato_action

  * cc_waiting_for_dea

  * cc_app_update

  * stager_start

  * stager_end

  * dea_start

  * dea_stop

  * dea_ready

  * nginx_error

  * vcap_error

  * vcap_warning

  * service_provision

.. _logging-keys-systail:

systail
^^^^^^^

* systail.<processname>

* systail.<processname>.<nodeip>

  * auth
  * dmesg
  * dpkg
  * kato
  * kernel
  * nginx_error
  * stackato-lxc
  * supervisord
  * cc_nginx_error
  * app_mdns
  * app_store
  * applog_redis
  * apptail
  * avahi_publisher
  * cc_nginx
  * cloud_controller
  * cloud_events
  * dea
  * doozerd
  * aok
  * filesystem_gateway
  * filesystem_node
  * harbor_gateway
  * harbor_node
  * harbor_proxy_connector
  * harbor_redis
  * health_manager
  * logyard
  * memcached_gateway
  * memcached_node
  * mongodb_gateway
  * mongodb_node
  * mysql
  * mysql_gateway
  * mysql_node
  * nats_server
  * nginx
  * postgresql
  * postgresql_gateway
  * postgresql_node
  * prealloc
  * rabbit_gateway
  * rabbit_node
  * redis_gateway
  * redis_node
  * redis_server
  * router
  * router2g
  * stager
  * systail

.. _logging-systail-manage:

Managing the systail stream
---------------------------

The list above shows the default systail keys. These can keys can be
modified with the :ref:`kato config <kato-command-ref-config>` command
to add arbitrary system log files to the stream or change the log file
source for an existing key.

* To retrieve the current list of log files being streamed::

  $ kato config get logyard systail/log_files

* To remove a log file from the stream::

  $ kato config del logyard systail/log_files/dpkg

* To add a new log file to the stream::

  $ kato config set logyard systail/log_files/dpkg /var/log/dpkg.log

Restart the ``systail`` process after adding or removing log files::

  $ kato process restart systail


.. note::

  Do not remove the default Stackato log stream keys (i.e. anything in
  the :ref:`systail <logging-keys-systail>` list above) as this would
  affect the output of ``kato tail``.
