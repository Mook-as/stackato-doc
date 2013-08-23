.. index:: Python
.. _python-index:

Python
======

.. note::
       See :ref:`buildpacks` for an alternative way to deploy
       Python (and PyPy) applications.

All Python applications deployed to Stackato are, by default, run with
`WSGI <http://en.wikipedia.org/wiki/Web_Server_Gateway_Interface>`_.
Applications are started from a top-level script called
``wsgi.py`` defining a global ``application`` variable
containing the WSGI application object.
For a minimal sample application, see
`wsgi-helloworld <https://github.com/Stackato-Apps/wsgi-helloworld>`_.

By default, Python applications are served through
`uWSGI <http://projects.unbit.it/uwsgi/>`_.
You may add additional arguments to uWSGI in your ``stackato.yml``, eg::

    processes:
        web: $STACKATO_UWSGI --mount foo=app.py --import module

It is possible to :ref:`serve static files with uWSGI <uwsgi-python-static-files>`.

Django
------

.. toctree::
   :maxdepth: 2

   django
   
Application URL
---------------

Some applications require the user to specify the APP_URL. Below is an example on how to obtain the correct urls::

    import json
    vcap_app = json.loads(os.environ['VCAP_APPLICATION'])
    APP_URL = 'http://' + vcap_app['uris'][0]

.. _python-data-services:

Database Services
-----------------

Some minor edits are required to make your application work with a database. Python 
database configurations are located inside ``settings.py``. 

DATABASE_URL
^^^^^^^^^^^^

Authentication details for your configured database services can be found in the ``os.environ`` variable,
under ``DATABASE_URL``. Here is an example of getting the correct credentials.

.. code-block:: python

    import urlparse
    DATABASES = {}
    if 'DATABASE_URL' in os.environ:
        url = urlparse.urlparse(os.environ['DATABASE_URL'])
        DATABASES['default'] = {
            'NAME': url.path[1:],
            'USER': url.username,
            'PASSWORD': url.password,
            'HOST': url.hostname,
            'PORT': url.port,
            }
        if url.scheme == 'postgres':
            DATABASES['default']['ENGINE'] = 'django.db.backends.postgresql_psycopg2'
        elif url.scheme == 'mysql':
            DATABASES['default']['ENGINE'] = 'django.db.backends.mysql'
    else:
        DATABASES['default'] = {
            'ENGINE': 'django.db.backends.sqlite3', # Add 'postgresql_psycopg2', 'postgresql', 'mysql', 'sqlite3' or 'oracle'.
            'NAME': 'dev.db',                      # Or path to database file if using sqlite3.
            'USER': '',                      # Not used with sqlite3.
            'PASSWORD': '',                  # Not used with sqlite3.
            'HOST': '',                      # Set to empty string for localhost. Not used with sqlite3.
            'PORT': '',                      # Set to empty string for default. Not used with sqlite3.
            }

VCAP_SERVICES
^^^^^^^^^^^^^

.. code-block:: python

    import json
    vcap_services = json.loads(os.environ['VCAP_SERVICES'])
    srv = vcap_services['mysql'][0]
    cred = srv['credentials']
    DATABASES = {
        'default': {
            'ENGINE': 'django.db.backends.mysql',
            'NAME': cred['name'],
            'USER': cred['user'],
            'PASSWORD': cred['password'],
            'HOST': cred['hostname'],
            'PORT': cred['port'],
        }
    }

.. _python-worker-apps:

.. include:: ../../../common/deploy-worker.inc

Example
^^^^^^^
::

    name: python-app
    framework:
      type: python
      runtime: python27
    command: python worker.py
    processes:
        web: ~

.. _uwsgi-python-static-files:

.. include:: ../../../common/uwsgi.inc

Using a custom web server
-------------------------

To use a different web server, instead of uWSGI, specify its startup
command in ``stackato.yml``. Here's a sample stackato.yml used to
deploy a Django 1.4 application named "dj14" using gunicorn::

    name: dj14
    
    framework:
        type: python
    
    processes:
        web: gunicorn -b 0.0.0.0:$PORT dj14.wsgi
    
    requirements:
        pypm: [gunicorn]
        pip: ["http://www.djangoproject.com/download/1.4-beta-1/tarball/#egg=django-1.4b1"]

The custom web server must bind to IP address ``0.0.0.0`` and
port ``$PORT``. The same trick can be used to serve non-WSGI
applications (such as Tornado). See the `bottle-py3 example
<https://github.com/Stackato-Apps/bottle-py3>`_
sample for an example.

Installing Python Packages
--------------------------
.. note::

    To install packages from custom repository/mirror. Use the
    :term:`PIP_OPTS` or :term:`PYPM_OPTS` :ref:`environment variables
    <environment-variables>`.

Application dependencies such as web frameworks or modules from PyPI can be installed using 
:term:`PyPM` and/or :term:`pip`.

PyPM
^^^^

Definition :term:`PyPM`

To install packages during application deployment with PyPM, add the
requirements to stackato.yml::

    requirements:
        pypm:
        - tornado
        - pymongo

See the `stackato.yml of tornado-chat-mongo
<https://github.com/Stackato-Apps/tornado-chat-mongo/blob/master/stackato.yml>`_
sample app for an example.

Alternatively, you can list the modules in a top-level
``requirements-pypm.txt`` file. The format is similar, if not same, as
`pip requirements files
<http://www.pip-installer.org/en/latest/requirements.html>`_ and
accepts version specification. The name of this file can be overriden
by setting the ``PYPM_REQUIREMENTS_FILE`` environment variable.

pip
^^^

Definition :term:`pip`

In addition - or as alternative - to :term:`PyPM`, your application can also
make use of pip to install certain dependencies. The above
tornado-chat-mongo sample installs "pycurl" using :term:`pip`::

    requirements:
        pypm:
        - tornado
        - pymongo
        pip:
        - pycurl

If your application already contains a ``requirements.txt`` file, that
will be automatically used to install dependencies; no need to specify
them manually in stackato.yml. The name of this file can be overriden
by setting the ``PIP_REQUIREMENTS_FILE`` environment variable.

.. note::
	A `bug in pip <https://github.com/pypa/pip/issues/219>`_ may
	prevent the log file from being accessed by ``stackato logs``.

Asset Caching for pip and PyPM
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To speed up deployment, utilize **Asset Caching** to store resources downloaded
by PyPM and pip.  See :ref:`Caching Staging Assets <caching-staging-assets>` for more
details.


PyPy Support
------------

Here is an example of pushing an app using PyPy.

First, clone the `https://github.com/Stackato-Apps/werkzeug-debugger <https://github.com/Stackato-Apps/werkzeug-debugger>`_
repository.

Then add the following ``BUILDPACK_URL`` to the *stackato.yml* file::

    env:
        BUILDPACK_URL: git://github.com/ActiveState/heroku-buildpack-pypy.git

Finally, push the app to Stackato::

	$ stackato push -n


Other Python Frameworks
-----------------------

Examples of deploying other frameworks are included in the `GitHub
samples repo <https://github.com/Stackato-Apps>`_:

* Bottle framework

  * `Bottle Currency <https://github.com/Stackato-Apps/bottle-currency>`_

  * `Python 3 <https://github.com/Stackato-Apps/bottle-py3>`_

* Django

  * `django-gtd <https://github.com/Stackato-Apps/django-gtd>`_

  * `pinax-social <https://github.com/Stackato-Apps/pinax-social>`_

* Pylons Pyramid

  * `virginia <https://github.com/Stackato-Apps/pyramid-virginia>`_

  * `default <https://github.com/Stackato-Apps/pyramid-default>`_

* Tornado

  * `chat <https://github.com/Stackato-Apps/tornado-chat-mongo>`_

* Werkzeug

  * `werkzeug-debugger <https://github.com/Stackato-Apps/werkzeug-debugger>`_

* Celery

  * `celery-demo <https://github.com/Stackato-Apps/celery-demo>`_

