Stackato Documentation
======================

The Stackato documentation is built using Sphinx:

 http://sphinx-doc.org/
 
This is the same system used for Python language documentation and
several other projects.

Documentation for the current release in HTML format is available at:

 http://docs.stackato.com/

Editing
-------

Documentation is authored in reStructuredText format with some
Sphinx-specific markup. The reStructureText Primer in the Sphinx
documentation is an excellent reference:

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

Public vs. Internal
-------------------

The `make publicdocs` command excludes certain parts of the
documentation that are either tagged as "not public" or are under the
'internal/' directory. This content is not meant for the general public,
but is left in the documentation bundle as reference material for OEM
customers.

Depending on what information you want to expose to the end users of
your PaaS, you may wish to move additional files into an 'internal'
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


License & Copyright
-------------------

Stackato Documentation by ActiveState Software is licensed under a [Creative
Commons Attribution 3.0 Unported License][1].

[1]: http://creativecommons.org/licenses/by/3.0/

Copyright (C) 2013 ActiveState Software Inc.
