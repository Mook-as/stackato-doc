.. _newrelic:

.. index:: New Relic

New Relic Monitoring
====================

.. note:: 
    These instructions are for use with Stackato. For further details, please see the
    `New Relic site <http://newrelic.com/docs/python/new-relic-for-python>`_.

New Relic can be used to track your application analytics running in Stackato as 
well as for server monitoring. The languages it can currently be used with are:

#. :ref:`Ruby <newrelic-ruby>`
#. :ref:`Python <newrelic-python>`
#. :ref:`Java <newrelic-java>`
#. :ref:`PHP <newrelic-php>`

In order to use New Relic, you need a `New Relic account <http://newrelic.com>`_.

.. note::
	For security reasons, avoid committing your license key to source control.

.. index:: Server Monitoring

.. _newrelic-server-monitoring:

New Relic Server Monitoring
---------------------------

To use New Relic for server monitoring, you'll need a `New Relic account <http://newrelic.com>`_
and a License Key.  Then, run the following two commands on the Stackato Server::

	$ sudo nrsysmond-config --set license_key=<license key>
	
	$ sudo /etc/init.d/newrelic-sysmond start

.. _newrelic-ruby:

New Relic for Ruby
------------------

The Ruby Gem
^^^^^^^^^^^^

New Relic recommends installing the New Relic Ruby gem available on gemcutter 
as ``newrelic_rpm``::

	$ sudo gem install newrelic_rpm

Update the Ruby Gem at any time by running::

	$ sudo gem update newrelic_rpm

Once the Ruby Gem is installed, add this line to your *Gemfile*::

	$ gem 'newrelic_rpm'

Installing the Ruby agent with the Bundler Gem
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Add the gem specification to your *Gemfile*. It's best to place the New Relic gem 
as low in the list as possible, allowing the frameworks above it to be instrumented 
when the gem initializes::

	$ gem 'newrelic_rpm'

In the same folder as the *Gemfile*, run::

	$ bundle install

Configuration File
^^^^^^^^^^^^^^^^^^

After installing the agent, copy the `newrelic.yml` file into the `config` 
subdirectory of your application. You can download a fresh `newrelic.yml` 
that includes your license key from the Account Settings link when logged in 
to `rpm.newrelic.com <http://rpm.newrelic.com>`_.
	
Whenever you update the agent, double-check that your Agent configuration file 
(*config/newrelic.yml*) is up to date. To do this, you'll need to do a visual 
inspection of the default *newrelic.yml* file that lives in the Agent plugin 
folder (*vendor/plugins/newrelic_rpm/newrelic.yml*). Look for new configuration 
options that aren't in your *config/newrelic.yml* file.

.. _newrelic-python:

New Relic for Python
--------------------

The New Relic Python agent is pre-installed on Stackato.

The minimal steps requried to integrate New Relic to your Python WSGI application:

#. At the top of *wsgi.py*, add::

	import newrelic.agent
	newrelic.agent.initialize()

#. In *wsgi.py*, wrap your ``application`` WSGI entry point, eg::

        application = newrelic.agent.wsgi_application()(application)

#. Add required newrelic environment variables to *stackato.yml*::

        env:
              NEW_RELIC_LOG: stderr
              NEW_RELIC_LOG_LEVEL: DEBUG  # <- this is optional
              NEW_RELIC_APP_NAME: <your application name>
              NEW_RELIC_LICENSE_KEY: <your license key>

An alternative to modifying your python is to wrap ``$PROCESSES_WEB`` in *stackato.yml* 
with `newrelic-admin <https://newrelic.com/docs/python/python-agent-admin-script>`_.

Bottle Currency Example
^^^^^^^^^^^^^^^^^^^^^^^

`Bottle Currency with New Relic on GitHub <https://github.com/Stackato-Apps/bottle-currency/tree/newrelic>`_.

.. _newrelic-java:

New Relic for Java
------------------

The New Relic Java agent is **not** pre-installed on the Stackato VM. To add monitoring, you must include the agent with your application.

* Download a fresh `newrelic_agent<version number>.zip` that includes your license key from the Account Settings link when logged in to `rpm.newrelic.com <http://rpm.newrelic.com>`_.

* Unpack the zip file in a convenient directory to edit the `newrelic.yml` file inside.

* Set the app_name in `newrelic.yml` to the actual name of your application as you would like it to appear in your New Relic dashboard. 

* Save your changes and place the newrelic folder in the root directory of your application along with WEB-INF folder.

* Add the following section to a "hooks" section in *stackato.yml*::

    hooks:
        pre-running:
        - mv newrelic $STACKATO_APP_ROOT/tomcat/
        - cd $STACKATO_APP_ROOT/tomcat/newrelic
        - java -jar newrelic.jar install

Pet Catalog Example
^^^^^^^^^^^^^^^^^^^

`Pet Catalog (Java EE) with New Relic on GitHub <https://github.com/Stackato-Apps/pet-catalog/tree/newrelic>`_.

.. _newrelic-php:

New Relic for PHP
-----------------

The New Relic agent PHP libraries are pre-installed on Stackato. To add
monitoring, you need to add an agent configuration file to the root
directory of the application and make some modifications to *stackato.yml*.

* Add a ``newrelic.ini`` file in :term:`HOME` directory containing the following::

    extension=newrelic.so

    newrelic.daemon.logfile="/home/stackato/logs/newrelic-daemon.log"
    newrelic.daemon.loglevel="warning"

    newrelic.logfile="/home/stackato/logs/php_agent.log"
    newrelic.loglevel="warning"

    newrelic.license="XXXXXXX-your-new-relic-key-XXXXXXXXXXX"
    newrelic.appname="YourAppName"

The ``license_key`` can be found in 'Account settings' section on the

Set ``newrelic.appname`` to the actual name of your application as you
would like it to appear in your New Relic dashboard. 

The above settings are described in detail in the 
`New Relic PHP Agent Settings documentation
<http://newrelic.com/docs/php/php-agent-phpini-settings>`_.

* Add the following section to a "hooks" section in *stackato.yml*::

    hooks:
        pre-running:
        - mv -f newrelic.ini $STACKATO_APP_ROOT/apache/php/newrelic.ini

* Verify newrelic-daemon is writing logs to the specified location in newrelic.ini by running the following command: 

.. parsed-literal::

    $ stackato run *appname* "ps -ef | grep newrelic"

The output should contain:

.. parsed-literal::

    /usr/bin/newrelic-daemon -l *log-location* -d *log-level*

If it is writing to the incorrect location, try restart or update the application.

WordPress Example
^^^^^^^^^^^^^^^^^

`WordPress with New Relic on GitHub <https://github.com/Stackato-Apps/wordpress/tree/newrelic>`_.

Results
-------

Push the app to the Stackato server, and make a few requests to it in a
browser.  After a few minutes, check the New Relic dashboard to confirm the
information is being logged correctly.
