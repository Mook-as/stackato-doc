.. _management-console:

.. index:: Console
.. index:: Management Console

Management Console
==================

The Management Console is a web interface for Stackato. Using the same
API as the ``stackato`` CLI client, it provides access to a subset of
features for deploying, scaling, and configuring applications as well as
monitoring quota usage, and viewing logs.

The interface displays more options and settings for Admin users than it
does for regular end users. The features described below are available
to end users. See the Stackato Admin Guide for information on the
Management Console view for Admins.

.. _console-overview:

Overview
--------

Shows general information about your system usage.

* **Current Usage**: 

  * **Memory**: The amount of RAM (in MB) available you, and how much of
    that your applications are currently using.
  
  * **Applications Allotted**: The number of deployed vs. allotted
    applications.
  
  * **Services Allotted**: The number of deployed vs. allotted services.

* **Group Memberships**: Shows your group memberships. Only admins can grant
  an account membership in a group.

.. _console-applications:

* **Applications**: A list of applications you have deployed, showing:

  * the current state
  
  * the application name
  
  * which Stackato framework it uses
  
  * how many services it uses
  
  * the "owner" of the application (i.e. you or a group you belong to)
  
  * actions - restart, stop, start, delete, or open URL in a browser
    (options change based on the app's current state)
  
* **Provisioned Services**: A list of services (e.g. databases,
  filesystems) you have provisioned for applications.

.. _console-groups:

Groups
------

Displays a list of the groups you are a member of. Admins control group
membership.

.. _console-features:

Features
--------

Shows the the frameworks, runtimes, and services available on the system.

.. _console-app-store:

App Store
---------

The App Store is a collection of ready-to-run applications which can
be deployed to Stackato by fetching the source code from Git repositories.

The list of applications can be filtered by "Store" (each is a catalog
of applications), runtime, framework, services required by the app, and
software license.

The **Search** field dynamically filters the list by application and all
other defined properties (e.g. description, memory requirement).

Click **+Install** to fetch the sources and deploy to Stackato.

Click the **More Information** link to open the software project
homepage (e.g. a Github project page).


.. _console-support:

Support
-------

A list of resources for getting support on using Stackato.