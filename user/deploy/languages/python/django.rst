.. index:: Django

.. _django:

Deploying Django applications
=============================

Getting started
---------------

Your app needs a top-level *wsgi.py* file with a global variable named ``application`` that refers 
to your Django WSGI application.  The file should already exist in the Django project, although a
copy of it needs to be in the root directory in order for Stackato recognize it::

	$ django-admin.py startproject dj14
	$ cd dj14
	$ cp dj14/wsgi.py wsgi.py

Typically, the *wsgi.py* file is just three lines of code::

  import os
  import django.core.handlers.wsgi
  application = django.core.handlers.wsgi.WSGIHandler()

Your project must also have a *requirements.txt* file containing at least
the ``django`` project::

  $ cat requirements.txt
  django==1.4
  mysql-python


Configuring database
--------------------

1. You must modify the ``DATABASES`` variable of your project's
   ``settings.py`` as below to detect the database service provisioned by
   stackato::
    
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
			'ENGINE': 'django.db.backends.mysql',
			'NAME': 'dev.db',
			'USER': '',
			'PASSWORD': '',
			'HOST': '', # Set to empty string for localhost.
			'PORT': '', # Set to empty string for default.
			}

  Please see :ref:`Using Configured Database Services <database-accessing>` for more information on connecting with database services.
	
.. note::
    In future, this may be automatically written to
    `local_settings.py` (similar to `ep.io` and others)


2. Then add a new dependency to `requirements.txt`::

    $ echo 'mysql-python' >> requirements.txt


Initializing database
^^^^^^^^^^^^^^^^^^^^^

Run the ``syncdb`` command to initialize the database tables::

  $ stackato run <appname> python manage.py syncdb

If you use a data migration library such as `South
<http://south.aeracode.org/>`_, also run::

  $ stackato run <appname> python manage.py migrate



Configuring static media
------------------------

There are various ways to serve static files for a Django application.
Option #1 is the most recommended for production deployments; option
#3 is the simplest for non-production/development/test deployments.

1. Directly serve static files with uWSGI. See :ref:`Serving static
   files with uWSGI <uwsgi-python-static-files>` for details. or:

2. Use ``django.contrib.staticfiles``, which is included by default in
   Django 1.3. Read the `Django documentation
   <https://docs.djangoproject.com/en/1.3/howto/static-files/#using-django-contrib-staticfiles>`_
   to understand the steps involved, or take a look at `this commit
   <https://github.com/ActiveState/stackato-samples/commit/59ec0791>`_
   in the django-gtd sample app. or:

3. Set ``DEBUG=True`` in settings.py. This is not recommended for
   production applications.



Configuring project location
----------------------------

Your project's ``settings.py`` may not always reside at the root directory.
Furthermore, you may want to extend ``sys.path`` to point to certain project
sub-directories.

To persist such environment changes (across wsgi.py, settings.py,
manage.py, etc.), add the following to stackato.yml::

  env:
    DJANGO_SETTINGS_MODULE: myproject.settings
    PYTHONPATH: myproject

This assumes that your Django project lives under the ``myproject/``
sub-directory.
