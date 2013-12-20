Stackato Documentation
======================

.. only:: not public

  .. note:: **internal**:
     Sections marked '.. only:: not public' in the documentation sources
     are excluded from the HTML output of the public doc build. To edit
     the documentation, clone `stackato-doc.git
     <https://github.com/ActiveState/stackato-doc>`_, modify the `*.rst`
     files and then follow *README.md* to publish the changes.


`Stackato <http://www.activestate.com/cloud>`_ is polyglot
Platform-as-a-Service (PaaS) software. You can run it in your own data
center using the hypervisor of your choice, or on your favorite cloud
hosting provider to provide a private or public PaaS.

Documentation is provided for two different, but sometimes overlapping
audiences:

* :ref:`Stackato Users <stackato-user-guide>` : Developers and other end
  users who will be using a PaaS set up and maintained by others.
* :ref:`Stackato Admins <stackato-admin-guide>`: System operators in
  charge of setting up, configuring, and maintaining the PaaS

.. note::
  Stackato 3.0 is based on Cloud Foundry v2 and there are a number of
  important differences to be aware of if you are moving from Stackato
  2.x:
  
  * app deployment is now primarily done using :ref:`buildpacks <buildpacks>`
  * some keys in :ref:`stackato.yml <stackato_yml>` have changed
  * Groups have been replaced with :ref:`Organizations and Spaces <orgs-spaces>`
  * the Stackato v3 API is not yet fully documented, but is compatible
    with the `Cloud Foundry v2 API
    <http://docs.cloudfoundry.com/docs/reference/cc-api.html>`__ 


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

