.. _app-store:

.. index:: App Store

App Store
=========

The App Store is a collection of ready-to-run applications which can be
deployed to Stackato with a couple of clicks. This interface uses the
same API as the CLI client, pulling the source code from a Git
repository rather than pushing an archive from the user's local
filesystem.

Users have access to the main App Store interface (see the Stackato
User Guide), but do not have access to add new applications or store
definitions.

Creating an App Store
---------------------

The App Store interface exposes multiple "stores" which specify the
available applications. These stores are source from definition files
specified in the main :ref:`Settings <console-settings>` page of the
Management Console or set using :ref:`kato config
<kato-command-ref-config>`.

App Store Definition
^^^^^^^^^^^^^^^^^^^^

App Store definition :term:`YAML` files describe each store and its
apps, including a link to the source location for each app. For
example::

  store:
    title: Third Party Apps for Stackato
    contact: Stackato Support <stackato-support@activestate.com>
    icon: https://get.stackato.com/store/icon/third-party.png
  
  apps:
  - name: Bugzilla
    id: bugzilla
    desc: A bug tracking system for individuals or groups of developers
    framework: perl
    runtime: perl514
    services: mysql
    license: MPL
    commit: master
    src: https://github.com/Stackato-Apps/bugzilla.git
    info: https://github.com/Stackato-Apps/bugzilla.git#readme
    icon: https://get.stackato.com/store/icon/bugzilla.png
    mem: 256
  
  - name: Django CMS
    id: django-cms
    desc: A content management system platform for publishing content on the internet.
    framework: python
    runtime: python27
    services: postgresql
    license: BSD
    commit: stackato
    src: https://github.com/Stackato-Apps/django-cms.git
    info: https://github.com/Stackato-Apps/django-cms.git#readme
    icon: https://get.stackato.com/store/icon/django-cms.png
    mem: 128
  
  - name: Node Chat
    id: node-chat
    desc: A simple chat application in Node.js with no other dependencies. Originally written by Ryan Dahl, the creator of Node.js.
    framework: node
    runtime: node
    commit: master
    icon: https://get.stackato.com/store/icon/chat.png
    mem: 64
    license: MIT
    src: https://github.com/Stackato-Apps/node-chat.git
    info: https://github.com/Stackato-Apps/node-chat.git#readme

The YAML string requires two top-level keys: ``store`` and ``apps``.

store
~~~~~

  Contains entries that define the store.

  **title**
    Text used as a display name for the App Store in the Management Console.
    
  **contact**
    A name and email address of the store maintainer.

  **icon**
    An image used for the App Store icon. Specified as a full URL.


apps
~~~~

  This is an array of items, one for each app in the App Store.
  Each app is defined by the following fields:

  **name**
    The name of the app as displayed in the App Store list.

  **desc**
    A short description of the app, displayed below the name.

  **id**
    A short, lowercase, and unique string associated with the app.  Apps are sorted alphabetically in the list based on this field.

  **repo**
    URL of the git repository where the app code resides.

  **commit**
    Branch name, tag name, or exact commit hash to use. If unspecified,
    the HEAD commit of ``master`` branch is used.

  **framework**
    The framework the app uses. Examples include ``perl``, ``python``,
    ``buildpack``, ``node``, ``rails3``.

  **icon**
    An image used for the app icon specified either as a full URL, 
    a file relative to the ``store`` key **icon-url** URL, 
    ``default``, or other variable values.

  **info**
    A URL pointing to documentation for the app.

  **license**
    Software license of the app.

  **mem**
    Memory requirements of the app (an integer), in MB.

  **runtime**
    The runtime for the app. Examples include ``java``, ``python32``, ``ruby19``, ``php``, ``perl514``.

  **services**
    The data services to the app uses.


Hosting the Store Definition Files
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The YAML file defining the App Store needs to be placed on a server accessible by any users who
need to use it.  For a publically accessible App Store, it could be something like::

	http://www.mywebsite.com/appstore.yml
	
Adding the App Store to Stackato
--------------------------------

#. Log into the :ref:`Management Console <management-console>`, and go to the Settings section.  
#. Choose the "Stores" tab across the top.
#. Enter the full URL to your App Store YML file and press the "Add" button next to it.

To confirm the App Store is loading correctly, select "App Store" in the
left menu and view the list of applications displayed.  An error will be
displayed in the console if an App Store URL fails to load.
