.. _perl-dancer:

.. index:: Dancer

Dancer
======

An app using the Dancer framework needs an *app.psgi* and *requirements.txt* file.

In the *requirements.txt* file, list any module requirements, with at least::

	Dancer
	Plack::Request
	YAML
	
In the *app.psgi* file, for a simple implementation::

	use Dancer;
	get '/' => sub { "hello world!" };
	dance;

Examples
--------

* `Dancer Hello World <https://github.com/Stackato-Apps/dancer-helloworld>`_: Hello World sample.
