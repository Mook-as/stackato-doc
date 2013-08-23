.. _customize:

.. index:: Theming and Customization

Customization
=============

A Stackato PaaS can be extensively customized and themed. PaaS
administrators can add or remove runtimes, frameworks and services from
the system, and OEM customers can change the :ref:`Management Console
<management-console>` and modify other parts of the system to match
their own brand.


Management Console Theming
--------------------------

Theming is controlled by changing settings in the *theme* directory on
the Cloud Controller node::

  /home/stackato/stackato/StackatoWebConsole/theme
  
Most changes will happen in the *settings.js* and *style.css* files, but
additional files and sub-directories can be added to the *theme*
directory as outlined in *settings.js* (or as needed).

Changes take effect immediately, but a hard refresh (e.g. Shift+Refresh)
of the browser may be necessary to see the changes.

settings.js
^^^^^^^^^^^

The *settings.js* file contains most of the configurable options for
theming which are not directly controlled by CSS. Each block of options
is preceded by comments explaining what the settings are used for. 

By default, most of these options are commented out with ``//``.
Uncommenting the line enables the option, overriding default Stackato
styles and content.

Path values should generally be locations within the *theme* directory,
but can be "\https://" URLs (using "\http://" will cause "Insecure
Content" warnings).

Styles: LESS to CSS
^^^^^^^^^^^^^^^^^^^

The CSS styles for the Management Console can be overridden by editing
the `LESS <http://lesscss.org/>`_ files in the *theme* directory and
compiling them with ``lessc`` into the `style.css` file.

* *mixins.less*: Contains `LESS mixins <http://lesscss.org/#-mixins>`_
  used in *theme.less*. 

* *theme.less*: Contains the styles themselves. This is normally the
  only file you will need to edit.

* *style.less*: Imports *mixins.less* and *theme.less* during
  compilation of the CSS.
  
To build the *style.css* file, run the following command within the
*theme* directory::

    $ lessc style.less > style.css

The ``lessc`` compiler will populate *style.css* with the styles defined
in the LESS files. The Management Console will use the styles in this
file to override the default ones.


EULA, Welcome and Support Content
---------------------------------

The *eula.txt* file in the *theme* directory contains HTML formatted
placeholder text. To customize it:

* replace the 'EULA title'
* insert your own EULA text
* add a link to an online version (optional)
* enable the line in *settings.js* for using *eula.txt*

Similarly, *welcome.txt* and *support.txt* files can be added to replace
the Welcome message and the top half of the Support page. The files
should contain HTML formatted content without higher level elements such
as \<html>, \<head>, or \<body>. With the content files created, enable
the relevant lines in *settings.js*. 

Error Pages
-----------

The *error_pages* subdirectory contains copies of the following HTTP
error status pages:

* *404.html* - Not Found: The requested resource could not be found but
  may be available again in the future.
  
* *422.html* - Unprocessable Entity: The request was well-formed but was
  unable to be followed due to semantic errors.

* *500.html* - Internal Server Error: A generic error message, given when
  no more specific message is suitable.

These pages can be modified or replaced to match the rest of the theme.

Renaming the Client
-------------------

The ``stackato`` client is distributed as a single file executable for
Windows, OS X and Linux (x86 and x86_64). Zip files containing
executables for each platform can be found in the ``~/stackato/static``
directory.

The binaries can be renamed arbitrarily, and the command line help
will use the file name as the application name. For example::

    $ cp stackato mypaas
    $ ./mypaas
    Usage: mypaas [options] command [<args>] [command_options]
    Try 'mypaas help [command]' or 'mypaas help options' for more information.

After renaming the executable, you can re-package them in .zip files
and save them in a 'client' sub-directory as suggested in *settings.js*
to make them available for download from the Management Console.

.. index:: Disabling Runtimes

.. index:: Disabling Frameworks

.. _customize-disabling:

Disabling Frameworks & Runtimes
-------------------------------

If you do not wish to expose particular frameworks or runtimes to end
users, they can be disabled.

* **To disable a framework**: On each Stager node, set ``disabled:
  true`` in the YAML file corresponding to the framework you wish to
  disable in */s/vcap/staging/lib/vcap/staging/plugin/manifests/*, then
  restart the stager (``kato restart stager``). 

* **To disable a runtime**: On each DEA node, edit the
  */s/etc/runtimes.yml* file to remove the block for that runtime, then
  restart the DEA (``kato restart dea``).
  
.. _customize-plugins:

Adding Plugins
--------------

Stackato can be extended with additional runtimes and frameworks. This
requires fairly deep technical knowledge of either Stackato and/or Cloud
Foundry, but the existing staging plugns can be used as a reference
in creating new ones. 

These plugins can be found on a Stackato VM under:
*/s/vcap/staging/lib/vcap/staging/plugins*

To avoid potential conflicts with the existing plugins, new staging
plugins should be added under the *contrib* sub-directory. Create a
directory there with the name of the plugin you are creating and add a
corresponding YAML file in the *manifest* directory. For example::

  ./contrib/java_web_jetty/
  ./contrib/manifests/java_web_jetty.yml

ActiveState can provide professional services to assist customers in
developing these plugins. Contact stackato-sales@activestate.com to
discuss your requirements.

