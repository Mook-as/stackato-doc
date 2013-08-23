.. _groups:

.. index:: Groups
.. index:: Limits
.. index:: Users

Groups, Users, and Limits
=========================

Stackato users can be assigned to specific groups, and each group can have a set of limits
assigned to it regarding apps, services, and memory usage.

To see commands related to groups, use ``stackato help`` or see the 
:ref:`Command Reference <command-ref-client>`.

You can also manage groups, users, and limits in the
:ref:`Management Console <management-console>`.  Users and groups have
different limit settings.  Applications pushed into groups have that
application's limits applied to that group's limits.

Basic Group Management
----------------------

To create a new group::
	
	$ stackato groups create developers
	Creating New Group: OK
	
.. note:: Group names cannot contain spaces.

To delete a group::	

	$ stackato groups delete managers
	Deleting Group: OK

For a list of all groups and members::

		
	$ stackato groups
	
	+------------+-------------------------+
	| Group      | Members                 |
	+------------+-------------------------+
	| developers | user1@mydomain.com      |
	| managers   |                         |
	+------------+-------------------------+


Limits
------

Group-Level Limits
^^^^^^^^^^^^^^^^^^

A group can have a number of limits set for it::
	
	$ stackato limits developers --mem 2048 --services 5 --apps 2 --appuris 5 --sudo true
	Updating Group Limits: OK

``--mem`` sets the amount of memory allowed in megabytes.  Can also be specified in gigabytes in
the format ``--mem 2G``.

``--services`` sets the number of services allowed.

``--apps`` sets the number of apps allowed.

``--appuris`` sets the number of app URIs allowed.

``--sudo`` sets whether or not the ``sudo`` command can be used.  Use ``true`` or ``false``. The
default setting is ``false``.

To view the current limits for a group::

	$ stackato limits developers
	
	+----------+-------+
	| Limit    | Value |
	+----------+-------+
	| mem      | 2048  |
	| services | 5     |
	| apps     | 2     |
	| appuris  | 5     |
	| sudo     | true  |
	+----------+-------+

User-Level Limits
^^^^^^^^^^^^^^^^^

A user can have limits set specifically without the use of a group::
	
	$ stackato limits user1@mydomain.com --mem 2048 --services 5 --apps 2 --appuris 5 --sudo true
	Updating Group Limits: OK

``--mem`` sets the amount of memory allowed in megabytes.  Can also be specified in gigabytes in
the format ``--mem 2G``.

``--services`` sets the number of services allowed.

``--apps`` sets the number of apps allowed.

``--appuris`` sets the number of app URIs allowed.

``--sudo`` sets whether or not the ``sudo`` command can be used.  Use ``true`` or ``false``. The
default setting is ``false``.

Use ``stackato limits`` to see limits on the user level::

	$ stackato limits user1@mydomain.com
	
	Group: user1@mydomain.com
	+----------+-------+
	| Limit    | Value |
	+----------+-------+
	| mem      | 2048  |
	| services | 10    |
	| apps     | 12    |
	| appuris  | 4     |
	| sudo     | true  |
	+----------+-------+


Managing Users and Groups
-------------------------

Users can be added to one or more groups.  To add a user to a group::
	
	$ stackato groups add-user developers user1@mydomain.com
	Adding User To Group: OK

View the users that are part of a group with this command::
	
	$ stackato groups users developers
	
	+-------------------------+
	| Member                  |
	+-------------------------+
	| user1@mydomain.com      |
	+-------------------------+

To remove a user from a group::

	$ stackato groups delete-user developers user1@mydomain.com
	Removing User From Group: OK

.. _user-import-export:

.. index:: User Export
.. index:: User Import

Importing/Exporting
^^^^^^^^^^^^^^^^^^^

To import a list of system users, or export a list of the current users
for migration to a new system, log in to the micro cloud VM or core node
as the 'stackato' user and run the :ref:`kato data users
<kato-command-ref-data-users>` command.

The ``kato data users export`` command generates CSV file with the following
columns::

  email,isadmin,groups

Using the ``--include-password-hashes`` option adds bcrypt password
hashes in a ``passwordhash`` column::

  email,passwordhash,isadmin,groups

The ``kato data users import`` will accept CSV files with the following
columns. The header row is required::

  email,password,isadmin,groups
  
Alternatively::

  email,passwordhash,isadmin,groups
  
The ``isadmin`` and ``groups`` columns are both optional. The
``password`` or ``passwordhash`` columns must be provided when adding
new users, but are optional if you are updating existing users with new
``isadmin`` or ``group`` values. Password hashes must be in bcrypt
format (as exported with ``--include-password-hashes``).

A ``--dry-run`` option is available if you would like to test the
import/export before actually running it.

Working with Groups
-------------------

While working with groups, you can set a particular one to be the "current group"::

	$ stackato group developers
	Successfully set current group to [developers]
	
Subsequent commands will use the current group if you do not specify one in a command::

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

To switch groups, just run  ``stackato group`` with another group name.  To remove the set group,
run ``stackato group --reset``.


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
  
