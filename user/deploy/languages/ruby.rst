.. _ruby-index:

.. index:: Ruby
.. index:: Rails Applications

Ruby
====

Deployment
----------

.. note::
	See :ref:`buildpacks` for an alternative way to deploy
	Ruby on Rails applications.

Using Ruby 2.0
^^^^^^^^^^^^^^

The `stackato.yml` must specify the Ruby runtime version and Rails as the framework type::

    framework:
        runtime: ruby20

Default Ruby version is Ruby 1.9

Known Issues
^^^^^^^^^^^^

* Rmagick gem currently not supported.

* PostgreSQL Gem (pg) version must be pinned to 0.12.2 (if used)::

    gem 'pg', '0.12.2'
    
* Must specify Rake Gem immediately before the line loading rails. This happens because when Rails 
  loads, it finds version 0.9.2 of Rake, and that becomes the only version of Rake in the process.  
  Later code wants version 0.9.2.2, and fails::

    gem 'rake', '0.9.2.2'
    gem 'rails'

* For Ruby 1.9 Cloud Foundry requires a tweak to the jquery-rails gem.

    gem 'cloudfoundry-jquery-rails'

Ruby on Rails 3.1+
^^^^^^^^^^^^^^^^^^

To get the asset pipeline working on Stackato, precompile your assets in your development 
environment, which compiles them into public/assets::

    bundle exec rake assets:precompile

Gems and Libraries
^^^^^^^^^^^^^^^^^^

A *Gemfile* must be included in your app that lists all required gems.  Run::

    $ bundle install
    $ bundle package

any time you modify the *Gemfile* and prior to pushing an app to Stackato.

If VCAP sees a Gemfile.lock in the application, it will ensure the needed gems are packaged, and 
set the BUNDLE_PATH environment variable to point at them.

Unsupported *Gemfile* features:

#. git urls or branch dependencies
#. gem :path => "some/path"
#. platform-conditional gems

Database Services
-----------------

Cloud Foundry supports database auto-reconfiguration for Rails applications.

.. _ruby-worker-apps:

.. include:: ../../common/deploy-worker.inc

Example
^^^^^^^
::

    name: ruby-app
    framework:
        type: rails3
        runtime: ruby19
    command: ruby worker.rb
    processes:
        web: ~

General Guidelines
------------------

App/Web Servers
^^^^^^^^^^^^^^^

For the best performance, using Thin Ruby web server is recommended.  Include ``gem 'thin'`` in your *Gemfile*.

* `Using Thin Webserver <https://devcenter.heroku.com/articles/ruby#webserver>`_: Heroku Dev Center.

Bundler
^^^^^^^

First, you need bundler and rails installed locally. This can be done via::

    $ sudo gem install rails bundler --no-ri --no-rdoc

Running rake commands
^^^^^^^^^^^^^^^^^^^^^   

Generally, ``bundle exec`` must be used when running any commands that
are installed through Gemfile/bundler. 

To run ``rake stats``, for instance, use the ``stackato run`` command::

    $ stackato run *appname* bundle exec rake stats

See the :ref:`Command Reference <command-ref-client>` for details on the use of ``stackato run``.

References
----------

* `Auto-Reconfiguration Part I <http://blog.cloudfoundry.com/2012/03/12/using-cloud-foundry-services-with-ruby-part-1-auto-reconfiguration/>`_: Cloud Foundry Blog.

* `Auto-Reconfiguration Part II <http://blog.cloudfoundry.com/2012/03/15/using-cloud-foundry-services-with-ruby-part-2-run-time-support-for-ruby-applications>`_: Cloud Foundry Blog.

* `Working with Ruby, Rails and Sinatra: Things to know <http://docs.cloudfoundry.com/frameworks/ruby/ruby-rails-sinatra.html>`_: Cloud Foundry Documentation.

