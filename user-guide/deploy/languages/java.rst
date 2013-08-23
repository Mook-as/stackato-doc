.. _java-index:

.. index:: Java

Java
====

Stackato has several Java frameworks to choose from:

* :ref:`Java Web <java-web>`
* :ref:`Spring <java-spring>`
* :ref:`Java EE (via TomEE or JBoss) <java-ee>`
* Grails
* Lift
* Buildpack - Java (see :ref:`Buildpacks <buildpacks>`)

You can push bytecode built on on your local machine 
with tools like `Apache Ant <http://ant.apache.org/>`_ and `Apache Maven
<http://maven.apache.org/>`_, or build the Java bytecode on Stackato
itself (using Buildpack - Java).

.. _java-web:

Java Web Applications
---------------------

The Java Web framework is the default Java framework in Stackato, and
requires little or no modification of application code in most cases.
Stackato simply deploys the WAR file.

`Hello Java Sample <https://github.com/Stackato-Apps/hello-java>`_ demonstrates a 
simple Servlet-based Java webapp using the Java Web framework.

Service Configuration
^^^^^^^^^^^^^^^^^^^^^

If you have created data services, you can get the service configuration
by using the :ref:`environment variables <environment-variables>` below:

* DATABASE_URL
* STACKATO_SERVICES
* VCAP_SERVICES

If your application uses only one data service, use the DATABASE_URL
variable. If it uses more than one, use :ref:`STACKATO_SERVICES
<database-services-stackato-services>` or :ref:`VCAP_SERVICES
<database-services-vcap-services>`.

.. _java-jdbc:
.. index:: JDBC

Using JDBC
^^^^^^^^^^

It is possible to access the database services using the standard JDBC API::

  String stackato_services = System.getenv("STACKATO_SERVICES");
  
  String hostname = NULL_STRING;
  String dbname = NULL_STRING;
  String user = NULL_STRING;
  String password = NULL_STRING;
  String port = NULL_STRING;
  
  if (stackato_services != null && stackato_services.length() > 0) {
    try
    {
      JsonRootNode root = new JdomParser().parse(stackato_services);
      
      JsonNode credentials = root.getNode("mysql");
      
      dbname = credentials.getStringValue("name");
      hostname = credentials.getStringValue("hostname");
      user = credentials.getStringValue("user");
      password = credentials.getStringValue("password");
      port = credentials.getNumberValue("port");
      
      String dbUrl = "jdbc:mysql://" + hostname + ":" + port + "/" + dbname;
      
      Class.forName("com.mysql.jdbc.Driver");
      Connection connection = DriverManager.getConnection(dbUrl, user, password);
      return connection;
      
    }
    catch (Exception e)
    {
      throw new SQLException(e);
    }
  }

Example
^^^^^^^

The `Java-MySQL (JDBC) <https://github.com/Stackato-Apps/hello-java-mysql>`_
sample demonstrates a simple Java application using a MySQL service.

.. _java-web-debug:

JPDA Debugging
^^^^^^^^^^^^^^

You can debug java_web applications running on Stackato via `JPDA
<http://docs.oracle.com/javase/7/docs/technotes/guides/jpda/architecture.html>`_
by using the ``-d`` option with the ``stackato push`` command::

  $ stackato push -d my-java-app
  
Stackato creates a port service for debugging and shows the external
port number in the command output::

  Debugging now enabled on port 30135
  
Alternatively, request a Harbor :ref:`port service <port-service>` in
*stackato.yml* in the format: "*app-name*-debug". For example::

  services:
    ${name}-debug: harbor

The java_web framework will recognize the service and activate debugging
through the port provided. Connect to this port with the JPDA debugger
of your choice.

To show the port number and external hostname for this service, use the
:ref:`stackato service <command-services>` command. For the
'my-java-app' example above, the command would be::

  $ stackato service my-java-app-debug
  
Use the 'hostname' (or 'host' for an IP address) and 'port' values in
the 'credentials' section of the output to configure your local
debugging client.

.. note::
  Though the ``stackato -d`` option is similar to ``vmc -d``, the
  internal implementation is different. ``vmc -d`` cannot be used to
  activate debugging in Stackato.
  

.. _java-spring:

Spring
------

Applications that use the Spring framework are detected and automaticaly
configured if there is either a *spring-core* jar file or an
*org/springframework* folder.

Service Configuration
^^^^^^^^^^^^^^^^^^^^^

If there is only one service of a given type (e.g. one MySQL data
service), the application is automatically reconfigured to use that
service.
  
Define a datasource bean like the following::
  
  <bean class="org.apache.commons.dbcp.BasicDataSource" id="dataSource">
      <property name="driverClassName" value="com.mysql.jdbc.Driver"/>
      <property name="url" value="jdbc:mysql://localhost:3306/inventory-db"/>
      <property name="username" value="myuser"/>
      <property name="password" value="mypass"/>
  </bean>

The property values are replaced during staging with the values for the
provisioned service.
  
If you have created more than one service of a given type, you will need
to use VCAP_SERVICES environment variable to obtain the details for each
one (host, port, username, password).

<CLOUD> Namespace Version
^^^^^^^^^^^^^^^^^^^^^^^^^

If you are using <CLOUD> namespace in your application, make sure
the cloudfoundry-runtime version is 0.8.2.

Example
^^^^^^^

The `Hello-Spring-MySQL
<https://github.com/Stackato-Apps/hello-spring-mysql>`_
sample demonstrates a simple Spring application with one MySQL service.

.. _java-ee:

JavaEE 6
--------

Stackato's 'java_ee' framework has two application servers available:

* TomEE - used for WAR files
* JBoss - used for EAR files

The Java EE framework is detected if there is a *persistence.xml* file located in
*src/main/resources/META-INF/persistence.xml*.

Service Configuration
^^^^^^^^^^^^^^^^^^^^^

For JavaEE applications, you must create a ``persistence-unit`` in your
*persistence.xml* file with the name of your database service.

For example in *stackato.yml*::

    services:
        service-1:
            type: mysql
        service-2:
            type: mysql

To use ``service-1`` in your persistence.xml::

  <?xml version="1.0" encoding="UTF-8"?>
  <persistence version="2.0"
    xmlns="http://java.sun.com/xml/ns/persistence"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xsi:schemaLocation="http://java.sun.com/xml/ns/persistence http://java.sun.com/xml/ns/persistence/persistence_2_0.xsd">
      <persistence-unit name="persistence-service-1" transaction-type="JTA">
        <jta-datasource>service-1</jta-datasource>
      </persistence-unit>
  </persistence>

And in your JavaEE code::

    @PersistenceContext(unitName = "persistence-service-1")
    private EntityManager em;

Examples
^^^^^^^^

The `hello-jee-mysql <https://github.com/Stackato-Apps/hello-jee-mysql>`_
sample demonstrates a JavaEE 6 application with a MySQL service running
with Apache TomEE.

The `kitchensink-ear
<https://github.com/Stackato-Apps/kitchensink-ear>`_ sample also uses a
MySQL service, but uses the JBoss server instead of TomEE.

.. _java-home:

HOME Directories
----------------

Java applications will have different HOME directories on Stackato
depending on which Java framework is used:

* Java Web, Java EE (WAR file), Spring, Lift and Grails: **/app/tomcat/webapps/ROOT**
* Java EE (EAR file): **/app/jboss/standalone/deployments**
* Buildpack - Java, Play: **/app/app**

.. _catalina-opts:

CATALINA_OPTS
-------------

The CATALINA_OPTS environment variable can be set in the ``env:`` block
of `stackato.yml` (or set in the Management Console) to override
Stackato defaults.

Stackato sets the CATALINA_OPTS environment variable for applications
using Tomcat automatically, based on the ``mem:`` value specified for
application instances. Stackato will always leave at least 64MB for
the heap, but will otherwise reserves up to 96MB for overhead, that is
for the code of the JVM itself, for additional libraries loaded via
JNI, for additional processes to run in the background, and for the
JVM permanent pool.

This means, for example, a 128MB application will end up with 64MB for
the heap and 64MB for overhead, a 160MB application will still have 64MB for
the heap but 96MB for overhead, and a 512MB application will get a
416MB heap and allow 96MB for overhead.
