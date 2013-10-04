Stackato Documentation
======================

.. only:: not public

  .. note:: **internal**:
     You are viewing the Stackato *internal* documentation. To edit the
     documentation, clone `stackato-doc.git
     <https://github.com/ActiveState/stackato-doc>`_, modify the `*.rst`
     files and then follow *README.md* to publish the changes.


`Stackato <http://www.activestate.com/cloud>`_ is polyglot
Platform-as-a-Service (PaaS) software. You can run it in your own data
center using the hypervisor of your choice, or on your favorite cloud
hosting provider to provide a private or public PaaS.

Documentation is provided for two different, but sometimes overlapping
audiences:

* Stackato Users: Developers and other end users who will be using a
  PaaS set up and maintained by others.
* Stackato Admins: System operators in charge of setting up,
  configuring, and maintaining the PaaS

.. warning::
  Documentation of new features in Stackato 3.0 is still in progress.
  These guides also cover many features which are not yet available in
  the Tech Preview. Please note:
  
  * only the MySQL and PostgreSQL data services are available
  * app deployment is now primarily done using :ref:`buildpacks <buildpacks>`
  * some keys in :ref:`stackato.yml <stackato_yml>` are deprecated
  * the client reference is out-of-date - use ``stackato help ...``
  * :ref:`Groups <groups>` have been replaced with `Organizations and Spaces <http://docs.cloudfoundry.com/docs/using/managing-apps/orgs-and-spaces.html>`__


Admin Guide
-----------

.. toctree::
  :maxdepth: 2
  
  admin/index


User Guide
----------

.. toctree::
  :maxdepth: 2
  
  user/index


Release & Support
-----------------

.. toctree::
   :maxdepth: 1
   
   admin/reference/release-notes
   admin/reference/known-issues
  
* `FAQ <http://community.activestate.com/faq-list?tid=453>`__
* :ref:`genindex`
* :ref:`search`

