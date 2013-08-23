.. index:: Memcached
.. _memcached:

Memcached Service
=================

Memcached is an in-memory key-value store used for caching by many web
applications and frameworks. It is available in Stackato as a service
which can be shared by application instances.

.. _memcached-using:

Using the Service
-----------------

As with other :ref:`data services <data-services>`, the location and
port of the memcached service is exposed to the application via 
environment variables: MEMCACHE_URL or VCAP_SERVICES.

The easiest way to connect an application to a Memcached service is to
use the MEMCACHE_URL environment variable. It contains the location and
port of the service created for the application. For example::

    MEMCACHE_URL=10.13.0.6:11000

Using MEMCACHE_URL will only work if ``sasl_enabled`` is set to
``False`` in the memcached_node configuration (default). To enable SASL
for Memcached, a Stackato administrator can run the following commands
on the Cloud Controller::
  
    $ kato config set memcached_node sasl_enabled true
    $ kato restart memcached_node
  
With SASL enabled, applications must parse the :ref:`STACKATO_SERVICES
<database-services-stackato-services>` or :ref:`VCAP_SERVICES
<database-services-vcap-services>` environment variables to extract the
"name", "user", and "password" strings from the memcached "credentials"
list. Using SASL with Memcached requires client libraries/modules in the
application which support authentication via SASL.

.. warning::
    
    Running Memcached **without** SASL enabled is insecure, and should
    only be done if all system users are trusted. Any Stackato user can
    connect to the provisioned service instance if the IP address and port
    is discovered.

.. _memcached-django-example:

Django Example using Memcached
------------------------------

The `Django GTD <https://github.com/Stackato-Apps/django-gtd>`_ sample
application uses the simpler VCAP_SERVICES method for connecting to the
Memcached service without authentication.

The relevant configuration in this example:

#. specifies the location of memcache using the MEMCACHE_URL in *settings.py*::

    CACHES = {
        'default': {
        'BACKEND': 'django.core.cache.backends.memcached.MemcachedCache',
        'LOCATION': os.getenv('MEMCACHE_URL'),
        }
    }       

#. adds the cache to middleware classes::
    
    MIDDLEWARE_CLASSES = (
        'django.middleware.cache.UpdateCacheMiddleware',
        'django.middleware.cache.FetchFromCacheMiddleware',
        ...
    )

#. adds the python-memcached module and a memcached service in *stackato.yml*::

    requirements:
        pip:
        - python-memcached
        ...
    services:
        memcached-gtd: memcached
        ...

