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

.. _user-console-welcome:

Welcome
-------

The top-level page of the Management Console displays quick links to the
most used resources and functional pages:

* Read the Documentation: By default, a link to `docs.stackato.com <http://docs.stackato.com/>`__

* Contact Support: Link to the :ref:`Support <user-console-support>` page.

* Download the Client: Link to the locally hosted :ref:`CLI client <client>` download.

* Deploy from the App Store: Link to the :ref:`App Store <user-console-app-store>`.

* Organizations Membership: Link to the end user view of the :ref:`Organizations <user-console-welcome>` page.

* Account Details: Shows the account details of the current user. Also
  accessible from the drop down list at the top left.

.. _user-console-organizations:

Organization View
-----------------

The Organizations page shows a list of all :ref:`Organizations
<orgs-spaces>` that the current user is a member of. Depending on how
the Stackato PaaS has been set up, you may only be a member of a single
Organization.

Clicking on the Organization name opens a view of that organization, including:

* Quota Usage:

  * Memory: The amount of RAM (in GB) available to the Organization, and
    how much of it is currently used by applications.

  * Services: The number of deployed / allotted services.

* Domains: Domains belonging to the Organization that can be used by
  applications deployed to :ref:`Spaces <orgs-spaces>` in the
  Organization. Typically, these will be a subdomain of the Stackato
  system itself. For example, an Organization called "acme" on a PaaS
  with the address "api.example.org" might have the domain
  "\*.acme.example.org".
  
Tabs:

* Spaces: A list of Spaces that belong to the Organization, showing the
  current number of applications and services deployed to that space.
  Clicking on a Space in the list opens a :ref:`view of that Space
  <user-console-space>`.

* Users: A list of Users who are members of the Organization, showing
  the Email address and Organization :ref:`Roles <orgs-spaces-roles>` of
  each. A user with the Manager role can add Spaces to an Organization,
  but not Users.
  
.. note::
  There is currently no interface in the Management Console for
  Managers, Auditors, or Billing Managers to view or adjust
  billing/payment info and spending limits.
  
  
.. _user-console-space:

Space View
----------

* Apps: A filterable list of applications in the Space. Clicking an app
  name opens an :ref:`administrative view of that application
  <user-console-app>`.

* Services: A list of services bound to applications in the Space.
  Clicking a service name opens a ref:`administrative view of that
  service <user-console-service>`.

* Domains: A filterable list of Domains attached to the space. Domains
  can be added and removed by Space or Organization Managers, but must
  first be mapped to the parent Organization (by a Stackato Admin).

Tabs:
  
* Timeline: A realtime stream of events and discussions relevant to
  the Space. The creation, update, and deletion of apps and services appear
  here as notifications which can be commented on by members of the
  Space. Discussions can be started by any member, tagged, and assigned
  to an application (which makes the item visible in the Application view).

* Managers: Managers can invite/manage users, enable features for a
  given space.

* Developers: Developers can create, delete, manage applications and
  services, full access to all usage reports and logs.

* Auditors: Auditors have view only access to all space information,
  settings, reports, logs.


.. _user-console-app:

Application View
----------------

* About: General information about the app including which buildpack it
  uses, when it was created, and when it was last modified.

* Routes: Essentially, the URLs mapped to the application.
  These :ref:`Routes <orgs-spaces-routes>` are made up of the name of
  the application name (a virtual hostname) followed by a dot and a
  :ref:`Domain <orgs-spaces-domains>` (assigned to the Org and Space).

* Services: Data (and other) service instances deployed in the Space.
  May be attached to one or more applications in the Space.

* Memory Usage: Total RAM consumption (in MB) of all apps in the Space.

Tabs:

* Timeline: An application-specific subset of the Timeline for the Space.

* Instances: List of application instances showing the status and host
  DEA IP address of each.

* Logs: A real time stream of your applications logs.

* Files: A browsable list of directories and files in each application
  instance.

* Environment Variables: Environment variables that have been explicitly
  set in the application container (via application config, client
  commands, or this interface). Default variables, those set by the
  application framework, or those added by the system for data services
  are excluded from this view.

* Settings: The number of application instances, disk space, and memory
  allotment. All are configurable within the Space and Group limits.

.. _user-console-service:

Service Instance View
---------------------

Clicking a service instance name anywhere in the interface brings up a
view of that service instance showing:

* when it was created
* when it was last modified
* which host it is running on
* which port it is exposed on
* the service instance name (not the canonical database name)
* it's current state

For more information on a service instance (i.e. its credentials), use
the :ref:`stackato service <command-service>` command.


.. _user-console-app-store:

App Store
---------

The App Store is a collection of ready-to-run applications which can
be deployed to Stackato by fetching the source code from Git repositories.

Click the **Deploy App** button to start it on Stackato. You will be
prompted to choose a Space and Domain for the app if there are multiple
options available for you.

.. _user-console-support:

Support
-------

A list of resources for getting support on using Stackato.