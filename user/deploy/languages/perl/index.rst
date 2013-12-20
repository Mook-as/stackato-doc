.. _perl-index:

.. index:: Perl, PSGI

Perl
====

Perl applications deployed to Stackato using the default 'perl'
framework are run with `PSGI <http://plackperl.org/>`_. Applications are
started from a top-level script, which must be called `app.psgi`. For
example, in the `mojo-helloworld
<https://github.com/Stackato-Apps/mojo-helloworld>`_
sample application::

	$ENV{MOJO_MODE} = 'production';
	require 'app.pl';

.. note::
  Both Dancer and Mojolicious scripts automatically use the PSGI
  protocol, so there is no need to create a separate `app.psgi` for
  them.

The script is a pointer to the actual application, `app.pl
<https://github.com/Stackato-Apps/mojo-helloworld/app.pl>`_. You could
instead rename `app.pl` to `app.psgi`, but using the approach above
allows you to set PSGI-specific configuration in a separate file.

It is possible to :ref:`serve static files with uWSGI <uwsgi-perl-static-files>`.

The :ref:`perlcgi <perlcgi>` framework is also available for running
tradtional Perl CGI applications without PSGI.

Deploying Applications
----------------------

The following is a list of pages with details for deploying various application types.

.. toctree::
   :maxdepth: 1

   cgiapppsgi
   perlcgi
   catalyst
   mason
   mojo
   dancer

.. _perl-data-services:

Database Services
-----------------

Authentication details for your configured database services can be found in the ``$ENV`` variable,
under ``DATABASE_URL`` or ``VCAP_SERVICES``. Here is an example of getting the correct credentials.

MYSQL_URL
^^^^^^^^^

.. code-block:: perl

    my($user,$password,$host,$port,$name) = $ENV{MYSQL_URL} =~ m{mysql://(.+?):(.+)\@(.+?):(\d+)/(.*)}
        or die "MySQL service not configured";
    print $host;
    print $name;
    print $password;
    print $port;
    print $user;


VCAP_SERVICES
^^^^^^^^^^^^^

.. code-block:: perl

    use DBI;
    use DBD::mysql;
    use JSON "decode_json";

    if ($ENV{VCAP_SERVICES}) {
        # Extract and convert the JSON string in the VCAP_SERVICES environment variable
        my $vcap_services = decode_json ($ENV{VCAP_SERVICES});

        # Get the database credentials
        my $cred = $vcap_services->{mysql}[0]{credentials};

        # Use the credentials to form whatever connection string your database interface requires
        my $dbh = DBI->connect("DBI:mysql:database=$cred->{name};hostname=$cred->{hostname};port=$cred->{port};",
                               $cred->{user}, $cred->{password})
            or die "Unable to connect: $DBI::errstr\n";
    }
    else {
        # No VCAP_SERVICES environment variable.  Use other connection.
        my $dbh = DBI->connect("DBI:mysql:database=mydb;hostname=127.0.0.1;port=3306;",
                               "username", "password")
            or die "Unable to connect: $DBI::errstr\n";
    }

.. _perl-worker-apps:

.. include:: ../../../common/deploy-worker.inc

Example
^^^^^^^
::

  name: perl-app
  framework: perl
  command: perl worker.pl
  processes:
    web: ~

Installing module dependencies
------------------------------

If the modules your app needs are available via PPM or CPAN, let
Stackato install them and their dependencies using one of the following
methods rather than including them in the source tree of your
application code.

.. _perl-ppm:

CPAN Modules via PPM
^^^^^^^^^^^^^^^^^^^^

`PPM <http://code.activestate.com/ppm>`_ is the binary package manager
for ActivePerl. It is usually the fastest and most reliable way of
installing CPAN modules in the Stackato application droplet. Current
versions of most CPAN modules and frameworks are available.

Modules required by your app can be specified by adding a
``requirements:`` section to the :ref:`stackato.yml <stackato_yml>`
file. For example::

	requirements:
	  ppm:
	    - CGI::Application::PSGI
	    - Plack::Builder
	    - Data::Dumper
	    - JSON
	    - JSON::Parse
	    - DBI
	    - DBD::mysql

.. note:: If you want to use cpan to download the modules, change ``ppm:`` to ``cpan:``.

Alternatively, include a top-level *requirements.txt* file. The
`requirements.txt` for a minimal Mojolicious app would be just::

	Mojolicious

Prerequisite modules for the framework are installed automatically.

For a simple Dancer application::

	Dancer
	YAML
	Plack::Request

Custom modules that are included within the project can be used in the normal method::

	use lib "lib";
	use MyCustomPM;

Any non-core dependencies required by these custom modules should be
specified explicitly in *requirements.txt*, *stackato.yml* or
*Makefile.PL* (see below) otherwise those dependencies will not be
packed in the application droplet.

.. _perl-cpanm:

CPAN Modules via cpanm
^^^^^^^^^^^^^^^^^^^^^^

If the module you require is not available in the `ActiveState PPM
repositories <http://code.activestate.com/ppm>`_, or if you need a
specific version (PPM provides only the current release), you can use
`cpanm <http://search.cpan.org/dist/App-cpanminus/bin/cpanm>`_ to
install them. Any dependencies included in ActivePerl or installed by
PPM will be reused rather than being rebuilt.

You can specify modules for installation via ``cpanm`` by including them
in one of the following files:

stackato.yml
~~~~~~~~~~~~

Add a ``cpan:`` section to *stackato.yml* that specifies version
conditions, requests a module via HTTP URL, or fetches a branch from a
git repo. For example::

  requirements:
    cpan:
      - Mojolicious~">=3.0, <3.50"
      - git://github.com/doy/try-tiny.git@Try-Tiny-0.09
      - http://www.cpan.org/authors/id/G/GA/GAAS/Data-Dump-1.20.tar.gz


This example installs a version of Mojolicious equal or later than 3.0,
but prior to 3.50. Since no such version exists on CPAN, it is fetched
from the BackPAN archive. It then installs the Try-Tiny-0.09 tag from
the try-tiny.git repository (could also be a branch or commit name), and
finally installs Data-Dump-1.20.tar.gz from an absolute download URL.

Makefile.PL
~~~~~~~~~~~

`Makefile.PL
<https://metacpan.org/module/ExtUtils::MakeMaker::Tutorial>`__ is a
standard format for specifying dependencies in Perl modules. Stackato
will use this if there is no *cpanfile* or *carton.lock* file.

cpanfile
~~~~~~~~

The `cpanfile
<https://metacpan.org/module/MIYAGAWA/Module-CPANfile-0.9031/lib/cpanfile.pod>`__
format is preferable for Perl web applications, as *Makefile.PL* is
generally intended for Perl modules. It allows for more elaborate
specification of module dependencies (see the `cpanfile SYNOPSIS
<https://metacpan.org/module/MIYAGAWA/Module-CPANfile-0.9031/lib/cpanfile.pod#SYNOPSIS>`__
for more information). 

carton.lock
~~~~~~~~~~~

The `carton <https://metacpan.org/module/Carton>`__ module dependency
manager is similar in concept to Ruby's Bundler.

To use it, first install carton locally using ``ppm`` or ``cpanm``.

Run the ``carton install`` command in the base directory of an 
application with a *cpanfile*. This installs
the modules locally and creates a *carton.lock* file.

If you want to include modules which are not in a public CPAN
repository, run ``carton bundle`` to add the source packages in a
*local/cache* sub-directory of the application. Stackato will install
those modules from the cached files.


Disable Testing
~~~~~~~~~~~~~~~

Disabling tests in cpanm can decrease staging times for applications
with numerous module dependencies, especially if those dependencies have
large test suites.

To disable testing for cpanm in staging, set `PERL_CPANM_OPT
<http://search.cpan.org/dist/App-cpanminus/bin/cpanm#OPTIONS>`_ to
'--notest' in :ref:`stackato.yml <stackato_yml>`::

  name: myapp
  env:
    PERL_CPANM_OPT: --notest

.. index:: Private CPAN Mirror

Custom CPAN Mirror
~~~~~~~~~~~~~~~~~~

To make cpanminus use a specific CPAN repository (e.g. a local mirror or
private repo), instead of the default public ones, set the ``--mirror``
and ``--mirror-only`` options in PERL_CPANM_OPT::

  env:
    PERL_CPANM_OPT: --mirror http://cpan.example.com --mirror-only

.. _uwsgi-perl-static-files:

.. include:: ../../../common/uwsgi.inc

Runtime
-------

Stackato deploys Perl applications with `ActivePerl 5.14 <http://docs.activestate.com/activeperl/5.14/>`_.

Troubleshooting
---------------

General
^^^^^^^

If your application fails to stage or launch successfully, use the stackato logs command to 
check the stdout and stderr logs.

If there are no helpful messages in those files, there are two additional log files (`staging.log` 
and `ppm4.log`) which can be accessed with the stackato files command::

	$ stackato files myapp logs/staging.log
	$ stackato files myapp logs/ppm4.log

Other Issues
^^^^^^^^^^^^

**Problem**
	Application installs but the result is an empty window.

**Possible Resolutions**
	Perl apps require the Content-Length header to be set in order for pages to display correctly.
	Some frameworks handle this already, while for others it needs to be done specifically.
	
	If you are using CGI::Application::PSGI, add the following to your `app.psgi` file::
	
		use Plack::Builder;
		
		...
		
		builder {
			...
			enable 'Plack::Middleware::ContentLength';
  			...
		};
	
Examples
--------

Several Perl samples are available in `Stackato-Apps <https://github.com/Stackato-Apps>`_ on GitHub.

* `Mojo Scaling Demo <https://github.com/Stackato-Apps/mojo-scalingdemo>`__
* `Retester <https://github.com/Stackato-Apps/retester>`__
* `PhotoBooth <https://github.com/Stackato-Apps/photobooth>`__
* `Perl Critic <https://github.com/Stackato-Apps/perlcritic.com>`__
* `Bugzilla <https://github.com/Stackato-Apps/bugzilla>`__