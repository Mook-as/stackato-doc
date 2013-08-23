.. index:: Clojure

Clojure
=======

.. highlight:: bash

Stackato supports deploying Clojure applications using `leiningen
<https://github.com/technomancy/leiningen>`_.

To create a new Clojure web application, install leiningen and `Noir
<http://webnoir.org/>`_ (a Clojure web framework)::

    $ lein plugin install lein-noir 1.1.0

Create a Noir project::

    $ lein noir new myapp
    ...
    $ cd myapp/

Now, deploy to Stackato, accepting the defaults for each prompt::

    $ stackato push myapp
    [...]
    Application Deployed URL: 'myapp.stackato-xxxx.local'?
    [...]
    Starting Application: OK

Open the application URL in your browser to see the default Noir welcome page.

Clojure Database Services Example
---------------------------------

Taken from the `4clojure sample app
<https://github.com/Stackato-Apps/4clojure/blob/stackato/src/foreclojure/config.clj#L6>`_:

.. code-block:: clojure

    (defn assoc-cloud-env
      "Import Cloud Foundry / Stackato environment settings"
      [config]
      (let [port (Integer/parseInt (System/getenv "PORT"))
            srv  (parse-string (System/getenv "VCAP_SERVICES"))
            cred ((first (srv "mongodb-1.8")) "credentials")]
        (assoc config
          :jetty-port port  
          :db-host    (cred "host")
          :db-port    (cred "port")
          :db-user    (cred "username")
          :db-pwd     (cred "password")
          :db-dbname  (cred "db"))))
