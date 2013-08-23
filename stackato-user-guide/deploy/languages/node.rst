.. _node-index:

.. index:: Node.js

Node.js
=======

.. highlight:: javascript

Stackato has a built in 'node' framework with multiple versions of the 
`Node.js <http://nodejs.org>`_ runtime. `NPM <https://npmjs.org/>`_ is
used to install Node packages automatically.

.. _node-npm:

NPM
---

Your application should list dependencies in a standard, top-level
*package.json* file (`specs <http://npmjs.org/doc/json.html>`_). 
Stackato automatically installs packages listed in the "dependencies"
section before starting the server.

Alternatively, you can call ``npm`` directly using :ref:`hooks
<stackato_yml-hooks>` in the *stackato.yml* file (e.g. see the
`RailwayJS
<https://github.com/Stackato-Apps/railwayjs/blob/master/stackato.yml>`_
Stackato sample application).

For NPM packages which include callable scripts or binaries, executable
components are automatically added to the container's $PATH, so a
"global install" (e.g, ``npm install -g``) is not required. 


Host and Port Environment Variables
-----------------------------------

Deploying Node applications to Stackato requires changing some
application settings to use instance-specific values. These values are
provided on Stackato with environment variables. For example, the
application is not allowed to arbitrarily choose which port it runs on.
It must use the one assigned by Stackato with the ``PORT``
variable. To access this in a node application::

    process.env.PORT

Likewise, the host IP address is exposed by ``VCAP_APP_HOST``::

    process.env.VCAP_APP_HOST
    
To make the application usable in both local and Stackato deployments,
use structures such as::

    var port = process.env.PORT || 1337;
    var host = process.env.VCAP_APP_HOST || "127.0.0.1";


Using Data Services
-------------------

Data services need to be configured with values from VCAP_SERVICES,
STACKATO_SERVICES, DATABASE_URL, or a database-specific environment
variable (see also :ref:`Using Configured Database Services
<database-accessing>`).

``VCAP_SERVICES`` is a JSON object containing information about all the
data service bound to the application. A typical ``VCAP_SERVICES``
variable containing a single MongoDB service might look like this::

  {
    "mongodb": [
      {
        "name": "todos",
        "label": "mongodb-2.4",
        "plan": "free",
        "tags": [
          "mongodb",
          "mongodb-2.4",
          "nosql"
        ],
        "credentials": {
          "hostname": "192.168.66.117",
          "host": "192.168.66.117",
          "port": 25001,
          "username": "4ce459bf-7a15-4c40-ac28-81adbdeba902",
          "password": "00a42612-9751-4d63-a758-186429d4903f",
          "name": "b89e2bc0-cae7-482c-8a47-8c816c67c62e",
          "db": "db"
        }
      }
    ]
  }

To use this information in your application code, use something similar
to this block from the `node-backbone-mongo
<https://github.com/Stackato-Apps/node-backbone-mongo>`__ demo
application::

  if(process.env.VCAP_SERVICES){
    var services = JSON.parse(process.env.VCAP_SERVICES);
    var dbcreds = services['mongodb'][0].credentials;
  }
  
  if(dbcreds){
    console.log(dbcreds);
    mongoose.connect(dbcreds.host, dbcreds.db, dbcreds.port, {user: dbcreds.username, pass: dbcreds.password});
  } else {
    mongoose.connect("127.0.0.1", "myappdb", 27017);
  }

This is the typical pattern used for all databases exposed by VCAP_SERVICES.

If the database module you are use supports URL-formatted connection
strings, using the :ref:`DATABASE_URL <database-database-url>` or
:ref:`database-specific URL variable <database-specific-url>`
(REDIS_URL, MONGODB_URL, etc.) is often a simpler and more concise
option.
