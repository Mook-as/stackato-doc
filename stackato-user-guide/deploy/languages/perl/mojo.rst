.. _perl-mojo:

.. index:: Mojolicious

Mojolicious
===========

Mojolicious is a web framework with a native PSGI interface which is easy to build and run
on Stackato.  

A simple app using the Mojolicious framework needs four files:

#. *app.psgi*
#. *app.pl*
#. *requirements.txt* 
#. *stackato.yml*

In the *requirements.txt* file, list any module requirements, with at least::

	Mojolicious
	
In the *app.psgi* file, for a simple implementation::

	$ENV{MOJO_MODE} = 'production';
	require 'app.pl';

The *app.pl* file contains the core functionality::

	use Mojolicious::Lite;
	
	# Simple response to display Environment Variables.
	get '/' => sub {
		my $self = shift;
		$self->render_text(join("<br>", map "$_=$ENV{$_}", sort keys %ENV));
	};
	
	app->start;

The *stackato.yml* file contains deployment instructions for Stackato.  See complete details for
this file in the :ref:`Configuration With stackato.yml <stackato_yml>` section.

Examples
--------

* `Mojo Hello World <https://github.com/Stackato-Apps/mojo-helloworld>`_: the simplest possible Mojolicious demo.
* `Mojo Photobooth <https://github.com/Stackato-Apps/photobooth>`_: Mojolicious webapp to emulate public photobooths.
