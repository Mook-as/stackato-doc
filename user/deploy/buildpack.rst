.. index:: Buildpack

.. _buildpacks:

Buildpacks
==========

`Buildpacks <https://devcenter.heroku.com/articles/buildpacks>`__ are
bundles of detection and configuration scripts which set up containers
to run applications. For a short introduction to writing buildpacks, see
`this presentation <http://talks.codegram.com/heroku-buildpacks>`_.

.. note::
  In Stackato 3.0 (Cloud Foundry v2 API) and later, application
  deployment is done *primarily* using buildpacks, and the syntax for
  specifying which buildpack to use has changed. Instead of using a
  BUILDPACK_URL environment variable, set the buildpack's Git URL in
  a ``buildpack:`` key at the top level of *stackato.yml*.

Deploy Using Buildpacks
-----------------------

Buildpacks are the recommended method for deploying applications to
Stackato, replacing the built-in frameworks used in previous versions.

.. _buildpacks-built-in:

Built-In Buildpacks
^^^^^^^^^^^^^^^^^^^

For convenience a few buildpacks are bundled with Stackato:

* `Python <https://github.com/ActiveState/stackato-buildpack-python>`__
* `Java <https://github.com/cloudfoundry/java-buildpack>`__
* `Node.js <https://github.com/cloudfoundry/heroku-buildpack-nodejs>`__
* `Ruby <https://github.com/ActiveState/stackato-buildpack-ruby>`__

Stackato will cycle through the ``detect`` scripts of the built-in
buildpacks prior to staging to match the code you are pushing.

.. _buildpacks-legacy:

Legacy Buildpack
^^^^^^^^^^^^^^^^

The legacy buildpack is is special meta-buildpack for deploying
applications configured for Stackato 2.x (Cloud Foundry v1 API) without
the need for extensive reconfiguration. This buildpack has updated
versions of all the frameworks available in previous versions of
Stackato.

To use the Legacy buildpack: specify the ``framework:`` ``type:`` for your
application (e.g. php, play, rails3, sinatra, java_web, java_ee, etc.). You can
optionally set a specific ``runtime:`` as well. For example::

    name: bottle-py3
    framework:
      type: python
      runtime: python32  

.. note::
  When using the Legacy Buildpack, config-defined environment variable
  values can only be updated by re-pushing the application with new
  settings (see :ref:`Legacy Buildpack and Environment Variables
  <known-issues-legacy-env>`).

Custom Buildpacks
^^^^^^^^^^^^^^^^^

To specify the exact buildpack to use for deploying your application,
set a top-level ``buildpack:`` key in *stackato.yml* to the URL of the
buildpack's Git repository. For example::

    name: myrubyapp
    mem: 256MB
    buildpack: https://github.com/ActiveState/stackato-buildpack-ruby.git

.. note::
  Not all Heroku buildpacks work with Stackato due to environmental
  differences (e.g. relying on certain executables or libraries in
  Heroku-specific locations). Test any buildpack before using it in
  production deployments.

The following buildpacks are known to work with Stackato:

* `Jekyll <https://github.com/ActiveState/heroku-buildpack-jekyll/>`_

* `PyPy <https://github.com/ActiveState/heroku-buildpack-pypy>`_

* `Python and Django
  <https://github.com/heroku/heroku-buildpack-python>`_ - 
  `unofficial documentation 
  <https://devcenter.heroku.com/articles/python>`__

* `Scala <https://github.com/heroku/heroku-buildpack-scala>`_ -
  `unofficial documentation
  <https://devcenter.heroku.com/categories/scala>`__

* `Sphinx Documentation <https://github.com/craigkerstiens/heroku-buildpack-sphinx>`_

  * `Sphinx example <https://github.com/Stackato-Apps/sphinx-demo>`_


Buildpack Examples
------------------

Pet-Clinic (Java)
^^^^^^^^^^^^^^^^^

First, in ``stackato.yml`` you will need to define the the buildpack
url. Here is the pet-clinic stackato.yml::

    name: pet-clinic
    mem: 512M
    buildpack: https://github.com/heroku/heroku-buildpack-java.git
    services:
      ${name}-db: mysql

As it is a buildpack application, you also need to create a ``Procfile``
in which you declare how you want your application to be executed. Here
is the one from pet-clinic::

    web: java $JAVA_OPTS -jar target/dependency/jetty-runner.jar --port $PORT target/*.war

And finally, add the jetty dependency in your ``pom.xml`` in order to run your application::

    <build>
        ...
        <plugins>
            ...    
            <plugin>
                <groupId>org.apache.maven.plugins</groupId>
                <artifactId>maven-dependency-plugin</artifactId>
                <version>2.3</version>
                <executions>
                    <execution>
                        <phase>package</phase>
                        <goals><goal>copy</goal></goals>
                        <configuration>
                            <artifactItems>
                                <artifactItem>
                                    <groupId>org.mortbay.jetty</groupId>
                                    <artifactId>jetty-runner</artifactId>
                                    <version>7.5.4.v20111024</version>
                                    <destFileName>jetty-runner.jar</destFileName>
                                </artifactItem>
                            </artifactItems>
                        </configuration>
                    </execution>
                </executions>
            </plugin>
        </plugins>
    </build>


