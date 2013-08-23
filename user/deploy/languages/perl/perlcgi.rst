.. index:: perlcgi

.. _perlcgi:

Perl CGI
========

The 'perlcgi' framework can be used to run *any* CGI script, but (like
the :ref:`perl <perl-index>` framework) it provides ActivePerl in the
default PATH and supports module installation via :ref:`PPM <perl-ppm>`
and :ref:`cpanm <perl-cpanm>`.

Unlike the 'perl' framework, setting the :ref:`start-file
<stackato_yml-start-file>` option has no effect, as there is no
permanently running application. A new instance of a CGI script is
started for each request.

Perl scripts deployed with this framework should begin with::

  #!/usr/bin/env perl

Example
-------

* `perlcgi-env <https://github.com/Stackato-Apps/perlcgi-env>`_: A simple Perl CGI script that shows environment variables.
