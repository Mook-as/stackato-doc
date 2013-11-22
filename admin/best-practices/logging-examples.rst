.. index:: Log Drain Examples

.. _logging-examples:

Log Drain Examples
==================

Detailed instructions on how to use drains with third party log analysis
software or services:

* :ref:`Papertrail <logging-examples-papertrail>`
* :ref:`Loggly <logging-examples-loggly>`
* :ref:`Splunk <logging-examples-splunk>`

.. note::

    Do not forward both application and system logs to the same destination.

.. _logging-examples-papertrail:

Papertrail
----------

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

5. Note down the **port number**. You need this later on.

.. image:: ../images/ppt4.png
    :class: shadow

Enable system logging (via udp) by executing the following kato command:

.. parsed-literal::

    kato log drain add *drain-name* udp://logs.papertrailapp.com:*port#*

.. note::
    Papertrail requires systail log lines to have ``<13>l`` at the
    beginnging of each line. Make sure the drain you are forwarding is
    formatted this way (see example in :ref:`Saving Custom Log Formats
    <logging-drains-save-format>`).


.. _logging-examples-loggly:

Loggly
------

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

Enable system logging by executing the following kato command:

.. parsed-literal::

    kato log drain add *drain-name* udp://logs.loggly.com:*port#*

OR

.. parsed-literal::

    kato log drain add *drain-name* tcp://logs.loggly.com:*port#*

Loggly supports JSON format with minor configuration changes shown above.

Enable system JSON logging by executing the following kato command:

.. parsed-literal::

    kato log drain add --format json *drain-name* tcp://logs.loggly.com:*port#*

.. _logging-examples-splunk:

Splunk
------

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

Enable system logging by executing the following kato command:

.. parsed-literal::

    kato log drain add *drain-name* udp://*splunk-server-address*:*port#*

OR

.. parsed-literal::

    kato log drain add *drain-name* tcp://*splunk-server-address*:*port#*

Splunk supports JSON format without further configuration.

Enable system JSON logging by executing the following kato command:

.. parsed-literal::

    kato log drain add --format json *drain-name* tcp://*splunk-server-address*:*port#*

Hello World Custom Drain
------------------------

The command below starts a drain target server on a node, piping to a local file::

    nc -lk 0.0.0.0 10000 > log-output.txt

As long as that `nc` command runs, this will funnel logs from all drains targeting 
it into the file log-output.txt

Enable system logging by executing the following kato command:

.. parsed-literal::

    kato log drain add *drain-name* udp://*server-address*:*port#*

OR

.. parsed-literal::

    kato log drain add *drain-name* tcp://*server-address*:*port#*
