Serving Static Files with uWSGI
-------------------------------

It is possible to serve static files with uWSGI using ``processes: web:`` in the 
:ref:`stackato.yml <stackato_yml>` file to specify folders that will be served statically 
and not by the app.

To make a single folder serve statically, use ``--check-static``::

	processes:
            web: $STACKATO_UWSGI --check-static $HOME/<folder>
		
To specify multiple folders with static files that do not share a common root, use ``--static-map``::

	processes:
            web: $STACKATO_UWSGI --static-map /foo=$HOME/static --static-map /bar=$HOME/sub
	
In this case */foo/index.html* would serve *$HOME/static/index.html*, and */bar/index.html*
would serve *$HOME/sub/index.html*.  If the file doesn't exist, then uWSGI will
forward the request to the app.

.. note::
    
    Serving static files via uWSGI is only available for Perl and Python frameworks.
