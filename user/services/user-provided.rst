.. _user-provided:
.. index:: User-Provided Services

User-Provided Services
======================

User-provided service instances allow you connect applications running
on Stackato to specified external data services, without hard coding the
credentials into the application. The service instance provides the
connection information to the application via the VCAP_SERVICES or
STACKATO_SERVICES environment variables, just like the :ref:`built-in
data services <data-services>`.

Think of user-provided services as a credentials database for your
Stackato application space. You provide the connection information,
Stackato stores it in a :ref:`JSON object <user-provided-using>` which
can be bound any applications in the space.

.. _user-provided-creating:

Creating
--------

User-provided service instances will typically be used to connect
applications hosted on Stackato to existing external database hosts or
clusters. For example, to connect an app to a PostgreSQL database hosted
outside of Stackato::

    $ stackato create-service user-provided prod-db-int
    Which credentials to use for connections [hostname, port, password]: host, port, database, user, pass    
    host: dbhost1.example.com
    port: 5432
    database: prod-django-321
    user: ro-web       
    pass: vsTLP2gs
    Creating new service ... OK

The parameter names provided in the first step will become the keys in
the JSON object exposed to the application later.

.. _user-provided-binding:

Binding
-------

Once the service instance has been created it can be bound to
applications, just like any other service::

    $ stackato bind-service prod-db-int django-cms
    Binding prod-db-int to scaling-demo ... 
    Stopping Application [django-cms] ... OK
    Starting Application [django-cms] ... 
    OK
    http://django-cms.stackato.example.com/ deployed

.. _user-provided-using:

Using
-----

The ``stackato service`` command will show the credentials::

    $ stackato service prod-db-int
    
    prod-db-int
    +--------------+------------------------------+
    | What         | Value                        |
    +--------------+------------------------------+
    | Type         | user-provided                |
    | Space        | example::example-dev         |
    |              |                              |
    | Credentials  |                              |
    | - database   | prod-django-321              |
    | - host       | dbhost1.example.com          |
    | - pass       | vsTLP2gs                     |
    | - port       | 5432                         |
    | - user       | ro-web                       |
    |              |                              |
    | Applications | django-cms                   |
    +--------------+------------------------------+
  
The :ref:`STACKATO_SERVICES <database-services-stackato-services>` and
:ref:`VCAP_SERVICES <database-services-vcap-services>` variables will
expose the connection information within the application container. The
parameter names you provided when setting up the service instance become
the keys in the ``prod-db-int`` JSON object::

    django-cms$ echo $STACKATO_SERVICES |json
    {
      "prod-db-int": {
        "database": "prod-django-321",
        "host": "dbhost1.example.com",
        "pass": "vsTLP2gs",
        "port": "5432",
        "user": "ro-web"
      }
    }

To have your application use this information, parse the variable in
your application code to extract the credentials at runtime. See the
:ref:`Language Specific Deployment <language-specific-deploy>` section
for examples.

Frameworks or buildpacks that autoconfigure bound services will do so
automatically, as they would for system-provided data services.
