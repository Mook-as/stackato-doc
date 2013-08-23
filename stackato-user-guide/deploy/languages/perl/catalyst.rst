.. _perl-catalyst:

.. index:: Catalyst

Catalyst
========

Catalyst is a framework for building web applications, which will run on Stackato.  To learn
more about Catalyst, see the `Catalyst documentation <https://metacpan.org/module/Catalyst>`_.
Also, take a look at the Stackato sample apps listed below to see some working code examples.

Home Directory
--------------

Catalyst makes different assumptions on its Home directory depending on
whether or not it is installed in @INC. It makes this distinction based
on the presence of a *Makefile.PL* or *BUILD.PL* file in the app
directory, so it is important to have one even if all prerequisites are
installed via *requirements.txt*.

Alternatively, the Home directory can be `set explicitly
<https://metacpan.org/module/Catalyst#Home>`_ with environment
variables. For example, you could set CATALYST_HOME in *stackato.yml*::

  env:
    CATALYST_HOME: $HOME

Examples
--------

* `Catalyst Tutorial 2 <https://github.com/Stackato-Apps/catalyst-tut2>`_: Sample application from chapter 2 of the Catalyst-Manual.
* `Catalyst Tutorial 3 <https://github.com/Stackato-Apps/catalyst-tut3>`_: Another Catalyst tutorial.
* `Catalyst Hello World <https://github.com/Stackato-Apps/catalyst-welcome>`_: A simple Catalyst example.


