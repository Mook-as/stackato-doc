.. _app-store:

.. index:: App Store

App Store
=========

The App Store is a collection of links to ready-to-run applications
which can be deployed to Stackato by any user or group with one or two
clicks. This interface uses the same API as the CLI client, pulling the
source code in to the system using Git rather than pushing an archive
from the local filesystem.

End users have access to the main App Store interface (see the Stackato
User Guide), but do not have access to add new applications or store
definitions.

Creating an App Store
---------------------

The App Store interface exposes multiple "stores" which define lists of
Git repositories containing the desired applications. These store
definition files are specified in the main :ref:`Settings
<console-settings>` page of the Management Console or set using
:ref:`kato config <kato-command-ref-config>`.

App Store Definition
^^^^^^^^^^^^^^^^^^^^

App Store definition :term:`YAML` files describe each store and its
apps, including a link to the source location for each app::

    store:
      title: ActiveState Stackato Sample Applications
      contact: Stackato Support <stackato-support@activestate.com>
      icon: activestate.png
      icon-url: http://get.stackato.com/store/icon/
      src-url: git://github.com/Stackato-Apps/
      defaults:
        id: $id-from-name
        mem: 128
        src: $id.git
        icon: $id.png
        commit: master
        info: $github-url#readme

    apps:
    - name: Currency Converter
      desc: Currency converter using Python bottle framework
      runtime: Python 2.7
      services: Redis
      id: currency
      src: bottle-currency.git
      tags: money, foo, ingy

    - name: PHP Info
      desc: Executes the phpinfo() function.
      runtime: PHP
      id: phpinfo
      icon: php.png

    - name: Rails Movies
      desc: Sample Rails app to manage a list of movie titles.
      runtime: Ruby 1.9
      framework: Rails 3
      services: MySQL
      src: rails-movie.git
      icon: default

The YAML string requires just two keys: ``apps`` and ``store``.

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
    Branch name, tag name, or exact commit hash of the git repository to use.  If unspecified, the HEAD commit of ``master``
    branch is used.

  **framework**
    The framework the app uses. Examples include ``perl``, ``python``, ``buildpack``, ``node``, ``rails3``.

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

store
~~~~~

  Contains entries that help define the App Store itself.

  **contact**
    A name and email address that can be used to contact someone regarding the App Store.

  **defaults**
    Default values for apps. See above example for more details.

  **icon**
    An image used for the App Store icon specified either as a full URL, or a file
    relative to the **icons** URL.

  **icon-url**
    A URL pointing to an base directory used for images.

  **src-url**
    A git URL pointing to an git repository used for applications. 

  **title**
    Text used as a display name for the App Store in the Management Console.  

variable values
~~~~~~~~~~~~~~~

  **$id**
   The ID of the app.

  **$id-from-name**
   name.replace(/[^\w]+/g, '-').replace(/^-/, '').replace(/-$/, '')

  **$github-url**
   Combination of **src-url** and **src** seperated by a **/**

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
