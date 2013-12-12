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

  This is an array of items (see YAML format above), one for each app in
  the store. Each app is defined by the following fields:

  **name**
    The name of the app as displayed in the App Store list.

  **desc**
    A short description of the app, displayed below the name.

  **id**
    A short, lowercase, unique string associated with the app. Apps are
    sorted alphabetically in the list based on this field.

  **repo**
    URL of the git repository where the app code resides.

  **commit** 
    Branch name, tag name, or exact commit hash to use. If unspecified,
    the HEAD commit of ``master`` branch is used.

  **framework** 
    The framework, if the app is deploed using the :ref:`Legacy
    Buildpack <buildpacks-built-in>` (e.g. ``perl``, ``python``,
    ``node``, ``rails3``).

  **icon** 
    An image used for the app icon specified either as a full URL, 
    a file relative to the ``store`` key **icon-url** URL, 
    ``default``, or other variable values.

  **info**
    A URL pointing to documentation for the app.

  **license** 
    Optional string indicating the software license of the app (e.g.
    ``MIT``, ``MPL``, ``BSD``).

  **mem**
    Memory requirements of the app (integer, in MB).

  **runtime** 
    The runtime, if the app is deployed using the :ref:`Legacy Buildpack
    <buildpacks-built-in>` (e.g. ``java``, ``python32``, ``ruby19``,
    ``php``, ``perl518``).

  **services**
    Data services required by the app.


.. note::
  The store definition settings do not override settings in the
  application's *stackato.yml* or *manifest.yml* file.


Hosting the Store Definition Files
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The YAML files defining the stores can be served via HTTP or HTTPS by
any web server at a URL accessible from the Cloud Controller.

	
Adding the App Store to Stackato
--------------------------------

#. Log into the :ref:`Management Console <management-console>`, 
#. Select **Settings > Cloud Controller** from the menu.
#. In the **App Store URLs** section, enter a name and content URL for 
   your store definition YAML file then click **Add App Store URL**.

To confirm the App Store is loading correctly, select "App Store" in the
menu and view the list of applications displayed. A "CC Catalog Manager"
error appear in the Event Log if an App Store URL fails to load.

App Store URLs can also be viewed, added, deleted, enabled, and disabled
with :ref:`kato config <kato-command-ref-config>`. For example::

  $ kato config get cloud_controller_ng app_store

