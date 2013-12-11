.. _orgs-spaces:

.. index:: Organizations
.. index:: Spaces

Organizations & Spaces
======================

.. only:: not public

    This documentation is derived from `Organizations and Spaces
    <http://docs.cloudfoundry.com/docs/using/managing-apps/orgs-and-spaces.html>`__
    in the Cloud Foundry documentation.

Organizations and Spaces are the main organizational units in Stackato.

* Organizations have Users, Spaces, and Domains
* Spaces have Users, Applications, and Service Instances
* Applications have Routes (which are derived from Domains)

.. _orgs-spaces-organizations:

Organizations
-------------

An organization is a top-level group of users, spaces, and domains. Only
Stackato admins (accounts with global superuser privileges) can manage
Organizations.

Each organization is assigned a :ref:`Quota Definition
<server-config-quota-definitions>`, a set of limits on memory,
applications, and service instances which is share between all members
of the organization.


.. _orgs-spaces-spaces:

Spaces
------

An organization can contain multiple spaces (e.g. **development**,
**test**, and **production**). A domain can be mapped to multiple spaces
but a route can be mapped to only one space.

.. _orgs-spaces-domains:

Domains
-------

A domain in Stackato is a fully-qualified, second-level or lower domain
name (e.g. "example.com" or "stackato.example.com").

Organizations and spaces can have custom domains, but are often able to
use a system domain by default as well (e.g. "myorg.net" and
"stackato.example.com"). Domains belong to an organization. They are
associated with one or more spaces within that organization, but are not
directly bound to apps. Apps are assigned a "hostname + domain"
combination called a Route. 


.. _orgs-spaces-routes:

Routes
------

A route is a virtual hostname followed by a domain name or
fully-qualified sub-domain (e.g. "myapp.myorg.example.com"). 

Management
----------

You can manage spaces and organizations with the :ref:`stackato client
<client>` or the :ref:`Management Console <user-console-organizations>`.

.. _orgs-spaces-roles:
  
Users & Roles
-------------

Stackato users can take on different roles within Orgs and Spaces. These
roles can be assigned by a Manager of the relevant scope or a Stackato
Admin: 

Org Roles
^^^^^^^^^

* Manager: Can invite/manage users, select/change the plan, establish
  spending limits
  
* Billing Manager: Can edit/change the billing account info, payment
  info
  
* Auditor: View only access to all org and space info, settings, reports

Space Roles
^^^^^^^^^^^

* Space Manager: Can invite/manage users, enable features for a given
  space
  
* Space Developer: Can create, delete, manage applications and services,
  full access to all usage reports and logs
  
* Space Auditor: View only access to all space information, settings,
  reports, logs
  

