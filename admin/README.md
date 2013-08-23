Stackato Admin Guide
====================

The Stackato documentation is built using Sphinx:

 http://sphinx-doc.org/
 
This is the same system used for Python language documentation and
several other projects.

Documentation for the current release in HTML format is available at:

 http://docs.stackato.com/

Editing
-------

With the exception of this Markdown file, the Admin Guide is authored in
reStructuredText format with some Sphinx-specific markup. The
reStructureText Primer in the Sphinx documentation is an excellent
reference:

 http://sphinx-doc.org/rest.html

The 'index.rst' file in the top level directory defines the Table of
Contents (i.e. the "main" page for the docs). The 'conf.py' file sets a
number of Sphinx options for the build. The Makefile defines the types
of build actions that can be run.

Building
--------

You will need Python 2.7 and the 'sphinx' package to build HTML
documentation from these sources. The easiest way to set this up is to
install ActivePython 2.7:

 http://www.activestate.com/activepython/downloads
 
Once ActivePython is installed, run the following commands:
 
   $ pypm install sphinx
   $ cd doc
   $ make publicdocs
   $ open _build/public-docs/index.html

Note: `make publicdocs-production` will be run by the install script
to generate the same documentation but in the parent ./public-docs
directory, which will be served statically by nginx on the uCloud.

Public vs. Internal
-------------------

Note: This distinction will soon only apply to the stackato-doc-admin repo,
which will become a submodule of stackato-doc. The stackato-doc-user guide will
be mirrored publicly on github, so no internal docs should go there. 

The `make publicdocs` command excludes certain parts of the
documentation that are either tagged as "not public" or are under the
'internal/' directory. This content is not meant for the general public,
but is left in the documentation bundle as reference material for OEM
customers.

Depending on what information you want to expose to the end users of
your PaaS, you may wish to move additional files into the the 'internal'
folder, or modify the .rst files to hide certain sections using the
'... only:: not public' construct.

You could also create a new documentation tree and top-level index.rst
(along with conf.py and the Makefile) to include only the documentation
you wish to expose. 

Release Notes
-------------

Release notes for Stackato are maintained in reference/release-notes.rst.

Publishing
----------

The HTML docs built by Sphinx can be deployed to any Stackato system as
a Node.js application. See web-server/README.txt

Troubleshooting
---------------

If you get an error:

  "make: sphinx-build: Command not found"
  
...it may mean you haven't added '~/.local/bin' to your PATH.

Either add it to your PATH with the export command:

 $ export PATH=$PATH:/home/yourname/.local/bin

Alternatively, add it to your PATH permanently by adding the above line
to your ~/.profile. 
