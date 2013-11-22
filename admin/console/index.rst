.. _management-console:

.. index:: Console
.. index:: Management Console

Management Console (Admin View)
===============================

Stackato's web interface is called the Management Console. The interface
displays more options and settings for Admin users than it does for
regular end users. Many of the features described below are only
available in the Admin view.

.. note::
  The Management Console in Stackato 3.0 Beta has changed significantly
  and is still under active development. The documentation below
  describes the Stackato 2.10 interface, but will be updated for the
  3.0.0 release.


.. include:: ../common/console-intro.inc

.. _console-overview:

Overview
--------

The Overview section shows high level details on components, services, roles, applications, and users configured on the server or cluster.

Cluster Roles
^^^^^^^^^^^^^

Displays the number of nodes serving each role. Clicking any of the roles opens the :ref:`Cluster Admin <console-cluster-admin>` page for that role.

Cluster Configuration
^^^^^^^^^^^^^^^^^^^^^

Displays the current configuration of the server/cluster.

* **API Endpoint**: The URL for stackato clients to target. Normally also the URL for the Management Console.

* **MBUS IP**: The IP address that hosts the primary node. Cluster nodes (if any) will connect via this IP address. In a micro cloud setting, it will be 127.0.0.1.

Usage
^^^^^

Total memory, app, and service usage on the system.

Administrators, Users & Groups
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The bottom of the Oveview page lists administrative users, regular users, and groups configured on the system. Clicking any of these will open its User or Group Details page.


.. _console-users:

Users
-----

The Users section displays a list of users and admins, and allows the management of all accounts. 

* Click **Add New User** to add users.

* Click **Import Users** to import a user list (see :ref:`Importing/Exporting <user-import-export>` for CSV format)

* Click **Export Users** to export a user list (see :ref:`Importing/Exporting <user-import-export>` for CSV format)

* Click **Default User Settings** to modify the :ref:`account settings <console-settings-user>` for new users.

* Use the **Search** field to filter the list of users. 

.. _console-user-details:

User Details
^^^^^^^^^^^^

For details on a specific user, click on the username in the list. The
User Details page shows current usage information, group memberships,
and lists of that user's applications and provisioned services.

The following options can be set for the user by clicking **User Limits**:

.. index:: Enable Sudo

.. _console-user-details-sudo:

* **Enable sudo**: Toggles 'sudo' (root) privileges within application containers. Though applications containers (LXC) are highly secure, there are potential vulnerabilities that could be exposed with sudo enabled, so this should only be enabled for trusted end users. Privileges are added to containers during creation, so changing this setting will only affect subsequently created containers (i.e. 'sudo' will not be enabled/disabled for the user in existing containers).

* **Memory Allotted**: Sets the amount of memory allowed.

* **Services Allotted**: Sets the number of services allowed.

* **Applications Allotted**: Sets the number of apps allowed.

* **Application URIs Allotted**: Sets the number of app URIs allowed.

The default settings for new users are configured in the "Users" section
of :ref:`Settings <console-settings>` page.

.. _console-groups:

Groups
------

Displays a list of groups that currently exist.  From the list, you can click on the number of
assigned users to see the user list, as well as delete the group.

* To create a new group, press the "Add New Group" button.

* To view the details of a group, click on the name of the group.

Group Details
^^^^^^^^^^^^^

The Group Details page displays an overview of the group's status, including the resource usage,
applications and services, and a list of users that are part of the group.

A group has limits attached to it that restrict the resources its
members can use. Press the "Group Limits" button to configure these
settings. The options exposed are the same as those on the User Details
page (above). 


For more information on Group limits, see the :ref:`Groups, Users, & Limits <admin-groups>` documentation.

.. _console-applications:

Applications
------------

The Applications section displays a list of all apps on the server.  For details on the application,
click on the name of the app.  By clicking the username for the app, you can view the details on the user 
that pushed the app.  Under Actions are three buttons, to restart, stop, and view the app.

.. _console-services:

Services
--------

Displays a list of services, their type, and the user that created each one.

.. _console-features:

Features
--------

This page shows two tabs with details on the features available on the server.

Runtimes & Frameworks
^^^^^^^^^^^^^^^^^^^^^

Displays a list of runtimes and frameworks available.

Available Services
^^^^^^^^^^^^^^^^^^

Displays a list of services that can be created for use by apps.

.. _console-cloud-events:

Cloud Events
------------

The Cloud Events section displays a list of events (including errors and
warnings) on the Stackato server. The events can be filtered by Severity
or Type, or by using a substring match in the Search field.

.. _console-cluster-admin:

Cluster Admin
-------------

Displays a list of nodes in the current cluster, and what services are running on each node. The view can be filtered by IP Address and/or Role. In a micro cloud configuration, only the current local node ('127.0.0.1') is shown.

To enable or disable services on a node, click the **Configure Roles** button to enter its **Role Configuration** page. This page shows a list of all available roles (see :ref:`kato info <kato-command-ref-info>` for the command line interface), and a toggle button to enable or disable each one (see also :ref:`kato role <kato-command-ref-role-add>`).

To set up a Stackato cluster, or to add nodes to an existing cluster, see the :ref:`Cluster Setup <cluster-setup>` section.

.. _console-status-graphs:

Status Graphs
-------------

Displays graphs for server statistics: CPU, Load, Memory, Disk Operations, Disk Space, Processes, and Swap (primary node or micro cloud only).

.. _console-app-store:

App Store
---------

Displays a list of apps ready for install to the server. Press the
"Install" button to push an app to the server. Apps which require
frameworks or services not available on the system will not be
installable.

For information on configuring the App Store, see the :ref:`App Store documentation <app-store>`.

.. _console-settings:

Settings
--------

Allows the user to manage the Stackato Server Settings. There are
sub-menus separating the settings into the following groups.

System
^^^^^^

.. index:: maintenance mode

* **Maintenance Mode**: Shuts down API requests but continues to serve web requests, useful when performing system operations such as importing and exporting data for upgrades. When the primary node enters maintenance mode, the Management Console becomes "read only" with the exception of this toggle (to bring it back online).

* **Logging Level**: Changes the verbosity of Stackato logs from 'debug2' (most verbose) through 'off' (silent).

* **Support Email**: The email address displayed to end users when errors are encountered. Use an address which is monitored by Stackato administrators.

* **App Store URLs**: URIs for JSON files which populate the :ref:`App Store <app-store>`. The URIs need not be public, but must be accessible from the controller node.

* **Allowed Repos**: Debian package repositories allowed in application containers. End users can install additional packages (e.g. with ``apt-get`` or ``aptitude``) only from these repositories.


.. _console-settings-user:

User
^^^^

* **Default User Settings**: The defaults for new user account creation.

  * **Enable sudo**: Toggles 'sudo' (root) privileges within application containers for new users (see :ref:`User Details <console-user-details>` above). 
  
  * **Memory Allotted**: The amount of memory in a default user's quota.
  
  * **Services Allotted**: The number of services a default user can request.
  
  * **Applications Allotted**: The number of applications a default user can push.
  
  * **Application URIs Allotted**: The number of URLs a default end user can use.
  
* **Administrators**: A list of active administrative accounts.

Application
^^^^^^^^^^^

* **Allow non-local URLs**: Toggles whether end users can map external URLs (i.e. not on the Stackato system's domain) to their applications.

* **Reserved URIs**: URIs which cannot be used for end user applications.

DEA
^^^
.. index:: Max Memory Percentage
.. index:: max_memory_percentage

* **Max Memory Percentage**: The percentage of physical memory each DEA
  node can use for hosted applications. The 80% default setting leaves
  enough memory for the OS and DEA processes on a node with 4GB of RAM.
  This can be increased on nodes with more memory available (e.g. to 90%
  on a node with 8GB of RAM). Do not exceed 100% unless the system
  correctly supports swap space and has it enabled. Restart all DEA
  roles/nodes to apply the change.


Harbor
^^^^^^

Settings for the :ref:`Harbor <harbor>` TCP/UDP port service.

* **External Host**: The public IP (if configured) for the Harbor node.

* **External Hostname**: The public hostname for the Harbor node.

* **Port Range Minimum**: Sets the minimum for the exposed port range (default: 35000).

* **Port Range Maximum**: Sets the maximum for the exposed port range (default: 40000).

See :ref:`Harbor: Requirements & Setup <harbor-setup>` for more information.

Data Services
^^^^^^^^^^^^^

* **Allow Over-provisioning**: Ignore the Capacity setting.

* **Capacity**: Maximum number of service slots to allocate.

* **Max DB size**: Maximum size on disk for database services.

* **Max Memory**: Maximum amount of physical memory to allocate the service.

* **Memcached Memory**: Maximum amount of physical memory to allocate for memcached instances.

* **Max FS Size**: Maximum size on disk for filesystem services.
