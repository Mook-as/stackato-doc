Stackato Client API
===================

Here is a summary of the Stackato REST API, as used by the
:ref:`stackato command line client <command-ref-client>`. It duplicates
the Cloud Foundry v1 client API with some extensions.

The main url paths are:

* :ref:`\/info <api-info>` - General information

* :ref:`\/info/services <api-info-services>` - Global services

* :ref:`\/info/resources <api-info-resources>` - Resources

* :ref:`\/stackato <api-stackato>` - Stackato usage reporting

* :ref:`\/apps <api-apps>` - Application query and manipulation

* :ref:`\/services <api-services>` - Service query and manipulation

* :ref:`\/users <api-users>` - User query and manipulation

* :ref:`\/groups <api-groups>` - Group query and manipulation (Stackato only)

Notes and Conventions
---------------------

* The <XXX> elements are placeholders for variable parts of a URL. They should be URL-encoded if they contain special characters.

* Authentication tokens are provided through the 'Authorization' HTTP header.

* Group information is provided through the 'X-Stackato-Group' HTTP header where not explicitly encoded in the URL or request parameters.

* SECURITY! - Possible security issues if not using HTTPS.

* STACKATO - Stackato-specific API extensions.

General Information
-------------------

.. _api-info:

/info
^^^^^

::

    GET Global client information.
        Response entity is JSON object: {
        Basic keys:
            "allow_debug"      : boolean
            "build"            : string/integer
            "description"      : string
            "maintenance_mode" : boolean
            "name"             : string
            "support"          : string
            "vendor_version"   : string
            "version"          : string
        Advanced keys (present for valid Authentication token in request)
            "allow_debug"      : boolean
            "user"         : string
            "groups"       : array of strings   (STACKATO)
            "usage"        : object
                memory      : integer
                apps        : integer
                services    : integer
            "limits"       : object     (STACKATO)
                memory      : integer
                app_uris    : integer
                services    : integer
                apps        : integer
                sudo        : boolean
            "frameworks"   : object
                <fw-key>    : object
                    name        : string
                    runtimes    : array of object
                        name        : string
                        version     : string
                        description : string
                    appservers  : array of object
                        name        : string
                        description : string
                    detection   : array of object
                        <pattern>   : boolean
                    sub_frameworks  : array of string
        }

.. _api-info-services:

/info/services
^^^^^^^^^^^^^^

::

    GET Get list of system services.
        Response entity is JSON object: {
            <type>  : object
                <name>  : object
                    <version>   : object
                        id      : string/int
                        vendor      : <name>
                        version     : <version>
                        tiers       : object
                            free        : object
                                options     : object (unused)
                                order       : integer
                        type        : <type>
                        description : string
        }

.. _api-info-resources:

/info/resources
^^^^^^^^^^^^^^^

::

    POST    Check server cache of available resources.
        Request entity is JSON array of the files to check.
        Response entity is JSON array of the subset of files in the cache.

        Request, array of object: {
            size    : integer
            sha1    : string
            fn      : string (filename, path)
        }

        Response has the same structure.

.. _api-stackato:

Stackato
--------

.. _api-stackato-report:

/stackato/report
^^^^^^^^^^^^^^^^

  .. note:: API calls in the /stackato/ space are only available in Stackato, not in Cloud Foundry.
  
::

        GET Retrieve stackato report.
            Response entity is a binary, gzip-compressed tar archive.

.. _api-stackato-usage:

/stackato/usage
^^^^^^^^^^^^^^^

::

    GET Get real-time usage information for current user.
        (modulo the current group, if any is set)
        Response entity is JSON object:
            usage     : object
                mem       : integer   [KB]
            allocated : object
                mem       : integer   [KB]
        }

.. _api-stackato-usage-all:

/stackato/usage?all=1
^^^^^^^^^^^^^^^^^^^^^

::

    GET See above, for the entire cluster.

.. _api-stackato-usage-group:

/stackato/usage?group=<USER-OR-GROUP>
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

::

    GET See above, for a specific user/group.


Applications
------------

.. _api-apps:

/apps
^^^^^

::

    GET List of all applications.   JSON
        Response entity is JSON array of object {
            name       : object 
                (see /apps/<NAME>)
        }

    POST    Create application.
        Request entity is specification of the new application, a JSON object: {
            instances   : integer
            name        : string
            resources   : object
                memory      : integer   [MB]
            staging     : object
                framework   : string
                runtime     : string
            uris        : array of string
        }

.. _api-apps-name:

/apps/<NAME>
^^^^^^^^^^^^

::

    GET Retrieve state information for the named application.
        Response entity is JSON object: {
             name       : string
             staging    : object
                model       : string
                stack       : string
            uris        : array of string   [mapped urls]
            instances   : integer
            runningInstances: integer
            resources   : object
                memory      : integer   [MB]
                disk        : integer   [MB]
                fds         : integer
                sudo        : bool
            state       : string  (STOPPED, RUNNING, ...)
            services    : array of string   [service-names]
            version     : string
            env         : array of string   [var=value]
            meta        : object
                debug       : unknown type  null
                console     : unknown type  null
                version     : integer
                created     : integer   [seconds/epoch]
        }

    PUT Set new state information for the named application.
        Request entity is the new/changed state information of the application.
        See GET above for JSON structure of this entity.

    DELETE  Delete the named application.

Application manipulation actions are done via GET-modify-PUT cycles through this one API.
Examples:

- Changing the application state (running, stopped).
- Changing the application's environment variables.
- Changing the set of mapped urls.
- Changing the set of services bound to the application.

.. _api-apps-name-application:

/apps/<NAME>/application
^^^^^^^^^^^^^^^^^^^^^^^^

::

    POST    upload the code for the named application.
        Request entity is a multipart/form-data with parts:

        _method        TEXT   'put'
        resources      JSON   array (see /info/resources) not uploaded, use cache.
        application    Binary Zip archive of application files not from CF cache.

.. note::  The stackato client generates a manifest.yml file, so the zip file is never empty. With other clients, if the zip file is empty, the data must be provided as x-www-form-urlencoded (instead of multipart/form-data) and the zip file argument omitted.

.. _api-apps-name-update:

/apps/<NAME>/update
^^^^^^^^^^^^^^^^^^^

::
    
    GET Get update information for the named application.
        NOT USED by command line client.
        Response entity is JSON object: {
            state   : string
            since   : integer   [seconds/epoch]
        }

.. _api-apps-name-stackato_log:

/apps/<NAME>/stackato_log?num=<N>
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

::

    GET Retrieves the last <N> log entries for the named application.
    N=0 retrieves all log entries.

        Response is a list of lines. Each line is a JSON object. {
            "text"      : string    text of the log entry
            "source"    : string    "app", "dea", "staging"
            "filename"  : string    name of the log file
            "instance"  : integer   [id of instance, -1: stager]
            "timestamp" : integer   [seconds since epoch]
        }


.. _api-apps-name-stats:

/apps/<NAME>/stats
^^^^^^^^^^^^^^^^^^

::

    GET Get statistics for the named application.
        Response entity is JSON array of object: {
            state   : string
            stats   : object
                name       : string
                host       : string   ip-address (dot notation)
                port       : integer  port number
                uris       : array    string
                mem_quota  : integer  bytes
                disk_quota : integer  bytes
                fds_quota  : integer  file descriptors
                cores      : integer
                uptime     : string   seconds
                usage      : object
                    disk      : string   bytes
                    mem       : string   KB
                    cpu       : string
                    time      : string   datestamp (last start)
        }

.. _api-apps-name-instances:

/apps/<NAME>/instances
^^^^^^^^^^^^^^^^^^^^^^

::

    GET Get instance information for the named application.
        Response entity is JSON object: {
            instances   : array of object
                index       : integer
                state       : string
                since       : integer   [seconds/epoch]
                debug_ip    : string    | STACKATO! KOMODO
                debug_port  : integer   | debug support.
                host        : string    ip-address (dot notation)
                lxcip       : string    ip-address (dot notation)
                console_ip  : string    ip-address (dot notation)
                console_port: integer   a port number
        }

.. _api-apps-name-crashes:

/apps/<NAME>/crashes
^^^^^^^^^^^^^^^^^^^^

::

    GET Get crash information for the named application.
        Response entity is JSON object: {
            crashes : array of object
                since   : integer   [seconds/epoch]
        }

.. _api-apps-name-instances-id-files:

/apps/<NAME>/instances/<ID>/files/<PATH>
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

::

    GET Get content of PATH (file or directory
        (listing)) for the id'd instance of the named
        application.


.. only:: not public

  .. note:: **internal**:

    /apps/<NAME>/instances/<ID>/run/<COMMAND>

  ::

    GET Run the command on the id'd instance of the named application.
        The command result is the response entity.

    !STACKATO, LEGACY:   pre-ssh support of the 'run' command

.. _api-:

Services
--------

.. _api-services:

/services
^^^^^^^^^

::

    GET Retrieve list of provisioned services.  JSON.
        Response entity is JSON array of object:
        {
            name        : string
            email       : string
            type        : string
            vendor      : string
            version     : string
            tier        : string
            properties  : object (unused)
            meta        : object
                created     : integer [seconds since epoch]
                updated     : integer [ditto]
                tags        : array of string
                version     : string
        }

    POST    Create new service.
        Request entity is specification of the new service, a JSON object:
        {
            "name"    : string
            "tier"    : string
            "type"    : string
            "vendor"  : string  - name of system service
            "version" : string
        }

.. _api-services-name:

/services/<NAME>
^^^^^^^^^^^^^^^^

::

    DELETE  Delete the named service.

Users
-----

.. _api-users:

/users
^^^^^^

::

    GET List known users.
        Response entity is JSON array of object: {
            email   : string
            admin   : bool
            groups  : array of string
            apps    : array of object
                name    : string
                state   : string
        }

    POST    Create new user.
        Request entity is specification of the new user, a JSON object: {
            email       : string
            password    : string    SECURITY! !plain text transmission
        }


.. _api-users-name:

/users/<NAME>
^^^^^^^^^^^^^

::

    GET Get information about the named user.
        Response entity is JSON object:
            (see /users)

    PUT Set information about the named user (Change password).
        Request entity is JSON object: See above, plus key
            password    : string    SECURITY! !plain text transmission

    DELETE  Delete the named user.

.. _api-users-name-tokens:

/users/<NAME>/tokens
^^^^^^^^^^^^^^^^^^^^

::

    POST    Get authentication token for the named user.
        Request entity is JSON with !plain text password, and flags.
        Response entity is JSON with token, ssh key (stackato specific), etc.

        Request entity, JSON object: {
            password    : string    SECURITY! !plain text transmission
            ssh_privkey : bool      STACKATO SSH SUPPORT
        }

        Response entity, JSON object: {
            token   : string
            sshkey  : string
        }

Groups
------

.. _api-groups:

/groups
^^^^^^^

  .. note:: API calls in the /groups/ space are only available in Stackato, not in Cloud Foundry.
  
::

    GET Get list of groups (for current user).
        Response entity is JSON object: {
            <group> : array of string
        }

    POST    Create new group.
        Request entity is specification of the new group, a JSON object: {
            name    : string
        }

.. _api-groups-name:

/groups/<NAME>
^^^^^^^^^^^^^^

::

    DELETE  Delete the named group.

.. _api-groups-name-users:

/groups/<NAME>/users
^^^^^^^^^^^^^^^^^^^^

::

    GET List users in the named group.
        Response entity is JSON array of object: {
        }

    POST    Add user to named group.
        Request entity is specification of the new user in the group, a JSON object: {
            email   : string
        }

.. _api-groups-name-users-username:

/groups/<NAME>/users/<USERNAME>
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

::

    DELETE  Remove named user from named group.

.. _api-groups-name-limits:

/groups/<NAME>/limits
^^^^^^^^^^^^^^^^^^^^^

::

    GET Get limits of the named group.
        Response entity is JSON object: {
            memory      : integer
            app_uris    : integer
            services    : integer
            apps        : integer
            sudo        : boolean
        }
