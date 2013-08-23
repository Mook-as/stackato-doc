.. _groups:

.. index:: Groups
.. index:: Limits
.. index:: Users

Groups, Users, and Limits
=========================

Users can be assigned to specific groups by Stackato admins. These
groups have quotas just like regular user accounts, and users can choose
to deploy applications and services owned by their user account or any
group they belong to. 

To see commands related to groups, use ``stackato help`` or see the 
:ref:`Command Reference <command-ref-client>`.

Working with Groups
-------------------

The ``--group`` option is available in many ``stackato`` commands to set
the effective group in an individual command. To set the current working
group for all client operations::

	$ stackato group developers
	Successfully set current group to [developers]
	
Subsequent commands will use the current group if you do not specify one
in a command.

To see the quotas for the current group::

	$ stackato limits
	
	Group: developers
	+----------+-------+
	| Limit    | Value |
	+----------+-------+
	| mem      | 2048  |
	| services | 10    |
	| apps     | 15    |
	| appuris  | 4     |
	| sudo     | true  |
	+----------+-------+

To switch groups, just run ``stackato group`` with another group name.
To unset the group (effectively setting the current group to your user
account), run ``stackato group --reset``.


.. _groups-STACKATO_GROUP:

STACKATO_GROUP
^^^^^^^^^^^^^^

The STACKATO_GROUP environment variable can be set in the local shell to
set the active group for the ``stackato`` client. For example::

  $ export STACKATO_GROUP='web-dev'

Subsequent ``stackato`` commands will operate under the 'web-dev' group.
To override this, use the ``--group`` option::

  $ stackato apps --group example-dev
  
With this variable set, the ``stackato group`` command is ignored until
the STACKATO_GROUP is explicitly unset::

  $ unset STACKATO_GROUP
  
