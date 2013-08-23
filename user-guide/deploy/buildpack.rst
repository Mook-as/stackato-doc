.. index:: Buildpack

.. _buildpacks:

Buildpacks
==========

Stackato allows you to write custom frameworks by way of your own
`buildpacks <https://devcenter.heroku.com/articles/buildpacks>`__. For
a short introduction to writing buildpacks, see `this presentation
<http://talks.codegram.com/heroku-buildpacks>`_.

Deploy Using Buildpacks
-----------------------

Stackato Built-In Buildpacks
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* `Clojure <https://github.com/heroku/heroku-buildpack-clojure>`_ -
  `unofficial documentation <https://devcenter.heroku.com/articles/clojure>`__
        
* `Go <https://github.com/kr/heroku-buildpack-go>`_ - `unofficial documentation <https://gist.github.com/299535bbf56bf3016cba>`__
    
* `Java <https://github.com/heroku/heroku-buildpack-java>`_ -
  `unofficial documentation
  <https://devcenter.heroku.com/categories/java>`__
    
* `Play! (Java and Scala)
  <https://github.com/heroku/heroku-buildpack-play>`_ - `unofficial documentation <https://devcenter.heroku.com/articles/play>`__

* `Ruby/Rails <https://github.com/ActiveState/stackato-buildpack-ruby>`_ - `unofficial documentation <https://github.com/ActiveState/stackato-buildpack-ruby#readme>`__

In order to let Stackato use one of the above buildpacks, you need 
to set the framework type in your stackato.yml. **Do not specify the runtime.**
For example::
  
    framework:
        type: buildpack

Custom Buildpacks
^^^^^^^^^^^^^^^^^
.. note::
  Not all buildpacks work out of the box with Stackato due to
  environmental differences with Heroku. Reliance on custom installed
  runtimes or downloading of pre-built binaries are common reasons. It
  is important to first test any buildpack before using it in
  production deployments.

The following buildpacks are known to work with Stackato,

* `Jekyll <https://github.com/troytop/stackato-buildpack-jekyll>`_
* `JRuby <https://github.com/ActiveState/heroku-buildpack-jruby>`_
  
  * `JRuby example <https://github.com/ActiveState/heroku-jruby-example>`_
  
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

In order to let Stackato use one of the above buildpacks, you need 
to specify the git repo URL as a environment variable called ``$BUILDPACK_URL`` in your stackato.yml. For example:

::

    framework:
        type: buildpack
    env:
        BUILDPACK_URL: git://github.com/<repo>.git

Buildpack Examples
------------------

Pet-Clinic (Java)
^^^^^^^^^^^^^^^^^

First, in ``stackato.yml`` you will need to define the framework type
and to provide the buildpack url. Here is the pet-clinic stackato.yml::

    name: pet-clinic
    mem: 512M
    framework:
        type: buildpack
    services:
        mysql-spring:
            type: mysql

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

Kandan (Ruby)
^^^^^^^^^^^^^

In ``stackato.yml`` you will need to define:

* framework type
* buildpack url
* :term:`PROCESSES_WEB`
* some post-staging hooks such as precompile assets and bootstrap

Here is the kandan stackato.yml::

    name: kandan
    instances: 1
    framework:
        type: buildpack
        runtime: ruby19
    env:
        BUILDPACK_URL: git://github.com/ActiveState/stackato-buildpack-ruby.git
    processes:
        web: bundle exec rails server
    mem: 256M
    services:
        pg-kandan: postgresql
        fs-kandan: filesystem
    hooks:
        post-staging:
        # create attachments directory in the shared filesystem and link to them
        - mkdir -p $STACKATO_FILESYSTEM/attachments
        - mkdir -p public/system
        - ln -s "$STACKATO_FILESYSTEM"/attachments public/system/attachments
        # Precompile assets
        - bundle exec rake assets:precompile
        - bundle exec rake kandan:bootstrap


Asset Caching
^^^^^^^^^^^^^

To speed up deployment, utilize **Asset Caching** to store resources downloaded
by the buildpack.  See :ref:`Caching Staging Assets <caching-staging-assets>` for more
details.
