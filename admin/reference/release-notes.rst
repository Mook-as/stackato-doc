.. -*- rst -*-
..
.. This file is in reStructuredText format. For markup overview, see
.. http://sphinx.pocoo.org/rest.html
..
.. Changes except "Internal" can be made available in the release
.. notes. Changes not directly related to Stackato itself (eg: VM) should
.. be listed in its own section.

Release Notes
=============

.. only:: not public

  See `release-notes.rst` in git for the up-to-date version of this file.
        `<https://github.com/ActiveState/stackato-doc>`_

v2.91.0 (Oct. 2013)
-------------------

* Logyard updates:

  * [98998] Build with Go 1.1
  * [98325] Move drains from doozer to redis
  * [98687] Add "AppGroup" field to app log stream
  * [98836] Add "HumanTime" field to systail log stream
  * [98870] Add app crashes/exits (eg: OOM killer) to cloud events
  * [98686] Add harbor service provision events to cloud events
  * [96827] Cloud Events patterns are now configurable (kato config)
  * [99534] New ``read_limit`` setting for apptail (default 16MB) to
    cope with extremely large application log files
  * [99571] Application log drain URLs now properly sanitized (v2.10.6 'logdrain-sanitize' patch)
  * [100512] Fix a leak in growing TCP connections causing systail to crash (inotify panic), and logyard drains to malfunction.
  * [99435] New ``kato log drain status`` and ``stackato drain list`` commands for showing drain status
  * [100507] New WARNING log message on drain retries
  
* Management Console:

  * [94745,94274] New disk activity and disk space graphs.

* Ruby:

  * Ruby 1.8.7 removed (EOL)
  * Ruby 2.0.0 added
  * [99368] Fixed problem building Nokogiri 1.6 gem. Stager now uses using system libraries (``NOKOGIRI_USE_SYSTEM_LIBRARIES=true``).
  
* Perl:

  * ActivePerl 5.14 removed
  
* Python:

  * Python 3.3 support, via ActivePython 3.3.2.0
  * Upgraded to ActivePython 2.7.5.6
  
* [98649] ``kato process stop fence`` now correctly stops fence process.
* [97164] Micro cloud starts with Memcached, Redis, PostrgreSQL, RabbitMQ, and MongoDB roles disabled by default (enable via Managment Console).
* [99604] New X-Frame header configuration option for router
* [98390] ``kato node attach`` now checks for version compatibility when adding a node to a cluster
* [98930] RabbitMQ updated to 2.8.7
* [98457] RabbitMQ 3.1.3 available (disabled by default). Enable with ``kato role add rabbit3``
* [98668] Memory consumption during staging is now limited to 1.5 times the application's allocated memory by default. Configurable with ``kato config`` under ``stager app_memory_multiplier``.
* [99521] ``--no-stop`` option removed from ``kato role remove`` command.
* [99745] ``kato config`` no longer supports node-specific config; ``--node`` option removed.
* [100215] prevent crontab breakage caused by newlines in environment variables
* Replaced Doozer with Redis.
* [99518] Increased default filesystem service size to 500MB.

  
v2.10.6 (June 10, 2013)
-----------------------

* [98980] New :ref:`kato patch <kato-command-ref-patch>` command
* [96962] New :ref:`Google Apps authentication strategy for AOK <aok-strategies>`
* [96395] Upgrade ActivePython distribute version to the latest
* [98481] Fix a postgresql readiness issue on 'kato data export'
* [98785] Upgrade Nginx to v1.2.9
* [98626] Fixed 2.6.7 to 2.10 cluster data import error
* [98632] pyopenssl now installable via PyPM without an ActivePython Business Edition license
* [98602] Fixed orphaned erlang beam processes on rabbitmq service deletion
* [98636] Fixed filesystem service capacity limits
* [98626] Autoscaling: Fixed *ArgumentError in get_datastore (1 for 2)*
* [98681] Correct ownership of */home/stackato/.ssh/known_hosts*
* [98715] cloud_controller X-Accel-Mapping header missing
* [98722] Locked down redis_server port from container access
* [98735] Management Console: Overview now shows number of nodes in cluster
* [99133] App Store: re-enabled Services filter
* [98875] Fixed cloud controller error when increasing app instances in Management Console
* [98884] Cloud controller now sends router.unregister NATS message on shutdown or restart
* [98928] Fixed incorrect status codes in router2g access log
* [98942] Hooks with grails (java_web) framework fixed
* [98590] Fixed ``kato status`` role reporting overlap
* [98972] Fixed MySQL service metadata import
* [98985] Less aggressive DEA autoscaling
* [98997] Fixed potentially blocking operation during retry of TCP drains
* [99006] ``kato op upstream proxy ...`` now correctly modifies the LXC template
* [99025] Longer (and configurable) timeout for ``kato op regenerate postgresql``
* [99040] Management Console now un-maps URLs correctly
* [98966,99012] fixed broken postgresql first boot task
* [99145] Fixed an issue where services may not be deleted from the web console
* [99153] Fixed Harbor service issues with UDP backend health checks
* [99220] Fix for cloud-init Stackato 'rename' task failing
* [99230] Fixed cloud-init failing to install custom apt-packages
* [98997] Fixed potentially blocking operation (up to 10s) in drain:stop
* Fence/DEA (app container management):

  * [98979,98990] More accurate disk usage monitoring
  * [99100] Fixed a DEA memory leak with droplet management
  * [98749] Fixed ``FATAL -- Can't create DEA pid file: Process already running``
  * [98700] Fixed traceback on DEA restart (``parse_info!': undefined method `[]'``)
  * [98688] Fixed *Filesystem::node: No such file or directory - /var/vcap/sys/run/fence.sock* error
  * [97619] Improved the accuracy of (accounted) container memory usage
  * [99147] Ensure container creation failure does not crash fence
  * [99204] Fixed "No such file or directory" ENOENT error on DEA
  * [98934] Container cleanup fix
  * [99202] Fixed "can't add new key into hash during iteration" warning on container cleanup
  
* stackato client updated to 1.7.4

  * [97359] New default behavior for ``stackato update`` preserves
    previously set environment variables. New ``--env-mode replace``
    option enables the old behavior of removing or resetting environent
    variables.
  * [96962] New ``token`` command for interactive token-based
    authentication with external SSO systems. 
    

v2.10.4 (April 5, 2013)
-----------------------

* [97520] Oracle DB add-on with ``stackato dbshell`` support

  * ORACLE_URL and JDBC_ORACLE_URL env vars if Oracle service present
  * Spring auto-configuration of Oracle DB binding
  
* Improvements to :ref:`Logyard <logging>`:

  * [96008] Fix logyard crash and uncleaned drains sometimes triggered
    by ``kato log tail``
  * [98244] Delete app drains on ``stackato delete``
  * [97614] Improve apptail reliability
  * [98279, 98354] Configurable finite retry on drains
  * [98169] Configurable maximum limit on user drains
  * [98326] Support for named custom format for use in drain URIs
  * [97856] apptail: handle NATS disconnection
  * [98280] Fix retrying behavior to reset retry delays after some
    point
  * Simplified formatting of log records in logyard.log
  * [98354] Reduced the frequency of retry warnings (esp. for Cloud
    Events)
  * Stability improvements [98091, 96337, 98342, 98243, 98240, 98423]
  
* Core runtime updates for stability and security [97667, 97978, 97857,
  97551]

  * [98515] `Upgraded PostgreSQL to 9.1.9
    <http://www.postgresql.org/about/news/1456/>`_ to address
    CVE-2013-1899 (major), CVE-2013-1900, and CVE-2013-1901
  * [97645] Improved cookie handling of token
  * [97649] Prevent REST API cross site request forgery
  * [97646] Prevent XSS vulnerability through App Store yaml file
  * [98256] Address CVE 2013-1857 in Rails
  * [98521] Reduce controller default memory limit to 50% (from 70%) before
    it is restarted
  * [98050] Updated `doozerd <https://github.com/ha/doozerd>`_

* Node.js

  * [97557] Updated node08 runtime (0.8.22)
  * [98068] Added node010 runtime (0.10.1)

* Perl:

  * upgrade to uWSGI 1.4.9
  * updated ActivePerl-5.14 runtime (5.14.4.1405)
  * added ActivePerl-5.16 runtime (5.16.3.1603)
  * latest App::cpanminus supports installation via URLs and from git
  * added support for cpanfile to specify dependencies
  * added experimental support for Carton, the Perl module dependency manager

* Python: upgrade to uWSGI 1.4.9

* Ruby: 

  * [98316] Update Ruby autoconfiguration library for MongoDB
  * [98223] Improve handling of stdsync usage
  * [98113] Updated Ruby buildpack
  
* Router improvements

  * [97806] Implement NATS connection error handling and retry logic
  * [98292, 98252] Fix possible JSON truncation in large responses
  * [98403] Correctly drop lost controller nodes from routing table
  * Additional fixes [96790, 98062, 98029, 97882]
  
* :ref:`kato <kato-command-ref>` updates:

  * [95989] ``kato users`` has moved to ``kato data users``
  * [97251] Added ``kato node list`` to list all nodes and which roles
    are running on them
  * [98137] ``kato tail`` skips logyard INFO records unless ``--raw`` is passed.
  * [98107] Correct ``kato node rename`` to handle existing pushed apps when using mdns
  * [97934] Prevent ``kato data export`` exception if memcached services was never used
  * Additional bug fixes [98067, 96792, 97597, 97769, 97808, 97810,
    97753, 97392, 97761, 97752, 97809, 97561, 98009, 96795, 98384,
    98272, 98481, 98402]

* [98281] Fix an issue with stopping apps during DEA shutdown.
* [96175] Fix a regression in ``stackato files logs/staging.log`` not returning
  `staging.log`
* [97895] Fix yajl load error in wait_for_fs.rb (when filesystem service is used)
* [98282] Speed up ssh connections to system
* Web console improvements [97736, 97702, 95765, 97701, 96121, 97777,
  98144, 97699, 98140, 97996, 97882]
  
  * [98254] Display Logyard configuration settings
  * [98042] Fix memory leak on long-open pages polling cloud events
  * [98127] Instant refresh of in-page modified components
  
* [97025, 98259] Improve DEA internal connectivity speed
* [98281] Improve DEA app cleanup on shutdown
* [93626] Enforce random postgres password at first boot
* [96007] Fix JBoss database support error when no services are defined
* [97731] Reduce long polling calls from the web console
* [97772] Correct ability to do first user setup after kato factory reset
* [97993] Made log rotation more strict (rotate any log in /s/logs/ over 10MB)
* [91120, 98299, 97973] Usernames are now stored in a case insensitive manner
* [98182] Updated Mono framework add-on to 3.0 Beta (Mono version 2.11)
* [98312] Update user authentication check to return compatibility to vcap_java_client
* [97322] cloud-init updates
* [97253] Change of "cloud_controller" role to "controller", new "primary" role
* [98314] Restrict kernel messages to tty console to errors only
* [98289] Improved console tty startup process to show progressive start state
* [98288] Update MongoDB to 2.4.1
* [97322] Improved cloud-init support to allow some kato commands to be called deferred
* [98523] Make MySQL service STORAGE_QUOTA_INTERVAL and KEEP_ALIVE_INTERVAL configurable, move quota check to every 30s default
* [97760] Properly handle timeout errors when checking DB quotas
* [97619] Updated app instance memory calculation to use container group stats
* [98550] Set container memory limit exactly at app instance memory request (was overallocating 12.5%)
* Documentation updates
* stackato client updated to 1.7.2

  * [98187] New `stackato admin grant/revoke/list`
  * [98145] Fixes to some false negative key warnings
  * [98221] Fixed multi-app push from stackato.yml
  * [98045] Correct limits management between users and groups
  * [96810] Correct handling exploded .war directories
  * Additional bug fixes [98238, 96930, 98181, 92751, 98089, 97958,
    97906, 97520]

V2.8 (February 26, 2013)
------------------------

* App Store improvements

  * Now a separate component.
  * Full streaming of application deployment output to the Management Console
  * [96401] App Store output now available in app log stream (:ref:`stackato logs <command-logs>`)
  * [97622] App Store uses upstream proxy info (e.g. provided by :ref:`kato op upstream_proxy set <kato-command-ref-op>`).

* New Harbor port service

  * Allows external ports to be forwarded directly to your app
  * Supports TCP, UDP and dual TCP/UDP ports.
  * Supports multiple app instances (TCP only)
  * [95358] Supports use of custom and multiple SSL certs with your application. For apps that use frameworks, harbor provides a built-in HTTPS server with SPDY support for the custom certificate(s).
  * Passive health checking of unavailable backends or unresponsive apps.

* Fence (fully non-blocking container management):

  * Less memory usage, faster DEA/stager performance
  * Faster container startup
  * Addition of per-app enforced disk limits
  * Improved security via Unix user-level compartmentalization in the kernel (each container now has its own Unix user)
  * Support for any IP range for LXC containers (configurable)
  * Removing (deprecating) lxctrl processes (less memory use)
  
* AOK (user authentication):

  * Optional external user authentication component
  * LDAP authentication support
  
* [97274] PostgreSQL: `HSTORE <http://www.postgresql.org/docs/9.1/static/hstore.html>`__
  (key/value storage) support in the PostgreSQL service.
* Redis: upgrade to v2.6 (`release notes <https://raw.github.com/antirez/redis/2.6/00-RELEASENOTES>`__)
* Python: upgrade to uWSGI 1.4.5
* Perl: upgrade to uWSGI 1.4.5
* Java: JPDA debugging for java_web applications via Harbor port service.
* Go: upgrade to the latest `Go buildpack <https://github.com/kr/heroku-buildpack-go>`__
* Logyard updates

  * [96620]: Drains are now retry infinitely if disconnected.
  * [96338]: Added new fields to the JSON of application log stream: AppID (application ID), AppName (application Name), NodeID (host DEA IP of the instance)
  * Added a new ``file:///`` drain for debugging purposes.
  
* [96493,96498] UI improvements for non-admin users in Management Console.
* [95986] New 'app-dir' key in stackato.yml to support deploying from a specific sub-directory.
* [97013] No port lookup for app host in incoming HTTP header.
* [95902] Management Console: Warn when deleting the last role on a node.
* [96729] Admin-configurable web console login expiration
* [96700,96653] Rails security fixes.
* [96677] mDNS backend: avahi-daemon removed and avahi_announcer replaced with avahi_publisher and app_mdns.
* [96225] Manual SSH key configuration on systems with separate Router, Cloud Controller, or Load Balancer nodes is no longer required during setup.
* [96696] Allow simultaneous 'kato tail' sessions.
* [96932] Fix certain /files routes e.g 'stackato files' from not being routed correctly.
* [95576] Prevent CC from being blocked during a vSphere scaling operation
* [96708] Major changes to ``kato`` commands and command naming:

  * "kato start|stop|restart" now manipulates roles, not processes.
  * "kato enable|disable" is now "kato role add|remove"
  * "kato attach" is now "kato node attach"
  * "kato setup micro" is now "kato node setup micro", "kato setup core" is now "kato node setup core" and "kato setup load_balancer" is now "kato node setup load_balancer"
  * "kato setup controller" and "kato setup node" have been retired. Use "kato node setup core" and "kato node attach" instead.
  * Change to how "kato drain add" options are passed. Dropped --option key=value --option key=value in favor of a just key=value key=value
  * For "kato role add|remove" (previously kato enable|disable), --all-but and --only are now boolean flags that act on the list of roles given. Therefore "kato enable --all-but dea,prealloc" becomes "kato role add --all-but dea prealloc"
  * "kato role remove" no longer supports the flag --no-stop
  * "kato rename" is now "kato node rename"
  * Added "kato role list" to list all roles and number of nodes they are enabled on.
  * "kato config" now takes action keywords "set", "get", "del", "push" and "pop". This is not backwards compatible. Example is "kato config set <component> <key-path> <value>".
  * "kato tail" is now "kato log tail"
  * "kato drain" is now "kato log drain"
  * "kato process start|stop|restart" can now be used to manage processes, though managing *roles* via "kato start|stop|restart" is recommended.
  * "kato ready", for checking the ready status of processes, is now "kato process ready"
  * Add "--node" to "kato process ready" to check status or process on any node.
  * "kato config" default output is YAML
  * "kato debug lsdoozer" has been removed. Use "kato config get --flat" instead.
  * The previous "kato status" functionality that showed just a list of processes and their statuses can now be found under "kato process list"
  * "kato import" is now "kato data import".
  * "kato export" is now "kato data export".

* stackato client updated to 1.7.0

  * [97399] Added '-d' option to enable JPDA debugging via Harbor service.

v2.6.7 (December 19, 2012)
--------------------------
  
* [96341]: Fix --format not being respected in `kato drain add`
* [96225] Manual SSH key configuration on systems with separate Router, Cloud Controller, or Load Balancer nodes is no longer required during setup.
* [94390] Added Node.js v0.8.14 as a dual runtime along with v.0.6.20
* [96231] Java 7 has been added as a new runtime.
* stackato client updated to 1.6.2

  * [95509] References to 'stackato' in renamed client help fixed.
  * [96386] Fixed output problems with 'stats' command.
  * [96427] Fixed problem with '--no-tail' option.
  * [96429] Fixed "Ambiguous runtime" error with 'standalone' framework.
  * [96438] Added option '--token' for direct specification of the auth token.

v2.6 (November 27, 2012)
------------------------

* Log aggregation/forwarding updates (Logyard)

  * Application log streams
  * Redesigned to run on large-scale clusters with no single point of
    failure or inter-node traffic.
  * Better log forwarding via drains (tcp, udp, redis).
  * Added Splunk support (based on drains).
  * Key deployment events made available in the application log
    stream.
  * Improved documentation.

* Cloud-Events

  * Cluster support - now includes events from all nodes in the cluster.
  * Forward events via Logyard drains.
  * Build reports on top of cloud events via third party services.

* Kato import/export changes - new next generation cluster migration tool

  * ``kato import/export`` uses the cluster-aware back end formerly accessed
    with ``kato migrate`` (deprecated)
  * Bug fixes: [96065, 96072, 96073]

* Client updated to 1.6.1

  * Application log forwarding setup via ``stackato drains add`` (user-level)

* New ``kato history`` command shows a history of administrative ``kato``
  commands ran across the cluster.

* Removed Command: ``kato ls`` in favor of ``kato status --all``

* [93012] Allow multiple staging nodes

* [96026] Create "contrib" plugin frameworks directory

* [95935] Fixed misleading 'Cannot connect to doozerd' warning in various cluster situations.

* [96215] Security fix for app store installs

* [96114] New dedicated Nginx instance for handling Cloud Controller file uploads

* [94258] Configurable data services storage location

* [95703] Fixed headers being prematurely sent on error pages with router2g

* [96191] Upgrade to Ruby 1.9.3-p327

* [96255] Fix issues with `kato node rename` when `/etc/hostname` is empty

* Additional documentation for new features, plus edits and minor corrections


Release v2.4 (October 29, 2012)
-------------------------------

* Improved application logging:

  * Logs are persisted between application restarts
  * ``stackato logs`` runs much faster, returns logs from all instances, and returns logs from stopped/crashed instances
  * ``stackato logs --follow`` tails logs from all instances

* Improved system logging (BETA):

  * Aggregate stackato system logs from all nodes in the cluster
  * Output plugins to stream system logs to Loggly, papertrail, and others

* Import and export Users and Groups via web console (.csv format)

* Simplified web console theming, with improved documentation

* Upgraded Apache TomEE Plus from v 1.0.0 to v1.5.0. In addition to the support of new TomEE features as listed on the `TomEE site <http://tomee.apache.org/downloads.html>`_, this upgrade addresses additional bugs:

  * [95426] Added Hibernate
  * [95082] Fixed Grails apps
  * [95425] Fixed test failure (Java apps with mysql services)
  * Other application compatibility issues

* New Command (BETA): ``kato migrate`` - next generation cluster live migration tool

* New Command: ``kato op static_ip`` - intuitive tool for static-ip configuration

* New Command: ``kato relocate ...`` - move key shared data to a new
  location (e.g. persistent storage)

* Client updated to 1.5

  * [95702] Allow uploading very large applications (upload limits still
    imposed by server)
  * [92160] New subcommand ``scp`` to move data to/from app instances
  * Support for enhanced logging features

* Client installation no longer available via ``pypm``

* MongoDB upgraded from v1.8.1 to v2.0.7

* Node.js upgraded from v0.6.18 to v0.6.20

* Ruby upgraded from 1.9.3-p125 to 1.9.3-p194 (with security patches from p286)

* [95291] Fixed incompatibility with Eclipse Cloud Foundry plug-in and Spring Tool Suite

* [94769] Allow non-web background processes with the "standalone" framework

* [94734] Support non-web background processes for all other frameworks

* [95491] Show DEA host node IP in application Details page for admins

* [94076] Auto-Complete for adding users to groups

* Experimental 'load_balancer' feature available via ``kato setup`` (BETA - not for production use)

* Router2g improvements (BETA):

  * SPDY support on all HTTPS connections
  * Improved logging of events
  * Support multiple cloud controllers
  * [95280] Fixed not setting content-length for Django applications

* Tuned system logging behavior for some components (DEBUG->DEBUG2)

* Ability to deselect App Store URLs without deleting them

* The App Store can now be disabled (removed from the side menu)

* Allow auto-starting of apps deployed from the App Store

* Documentation for new features, plus edits and minor corrections


Release v2.2.3 (September 28, 2012)
------------------------------------

* [95661] Revert to older version of supervisord to fix an issue with
  cluster setup

Release v2.2.2 (September 20, 2012)
-----------------------------------

* Integrated Ruby buildpack. When using ``framework: buildpack`` in *stackato.yml* for ruby apps, BUILDPACK_URL can be omitted.

* Java: Correct copy_source_files for non java_* frameworks

* Java: Improved access to logs

* Java: Add logs for debugging EAR JEE applications

* [95287] Improved memory usage calculation in forked Apache process apps

* [95290] Tuned default Apache settings for app instances

* [95458] Prevent doozer "TOO_LATE" warning

* [95265] Handling client errors in App Store deployments more gracefully

* [95314] App Store checks if application name is already in use

* Client updated to 1.4.5

  * Fix Windows Unicode pathname handling

  * [95485] Tail stderr.log instead of startup.log on push in slow
    deployments. Latter file is not used by all frameworks.

* Documentation updates:

  * New Relic integration docs updated

  * Updated cluster docs to use the correct form of `kato attach`
    and switched from `kato setup` to `kato attach` in autobecome

  * Added pyramid-default sample to Python docs

  * Updated Ruby deployment information

  * Updated autoscaling section with EC2 URL

  * Correct use of the Authorization HTTP header in client APIs


Release v2.2 (August 15, 2012)
------------------------------

Development
~~~~~~~~~~~

* Numerous additions and changes in ``kato`` server administration commands:

  * Most of `kato` rewritten in Ruby

  * :ref:`kato node {remove|migrate} <kato-command-ref-node-attach>` to manage
    outdated nodes or changing core IP

  * :ref:`kato ready <kato-command-ref-process-ready>` to determine ready status of
    underlying components

  * :ref:`kato inspect <kato-command-ref-inspect>` to check for common
    configuration issues

  * :ref:`kato setup core <kato-command-ref-node-attach>` to replace
    `kato setup controller`

  * :ref:`kato attach <kato-command-ref-node-attach>` to replace `kato setup node`

  * :ref:`kato enable|disable data-services <kato-command-ref-role-add>`

  * [94947] Manage cloud_controller as independent role to support multiple
    instances

  * Improve help output and error handling for incorrect arugments

* [94844] stackato run dbexport: exports mysql and psql databases

* [94657] Changed the `-n` alias for `kato setup -hostname` to `-a`

* [94357] Filesystem service split into `filesystem_gateway` and
  `filesystem_node` to make multiple filesystem service nodes possible

* [94905] Adjust VCAP_SERVICES service key to use unversioned service name
  (version remains in ``label`` key) to bring parity to client service creation

* [94783] Experimental router2g with WebSockets support

* [94744] Updated doozerd binary, fixed verbose doozerd.log logging
  affecting disk i/o

* [94828] Properly url encode console links for user names with special
  characters

* [94501] Extract droplets asynchronously on DEA

* [92457] Enable `kato export` via web console

* [94638] Expose Allow Overprovisioning flag for all services

* [94823] Switch App Store format from json to yaml and add tags field

* [95204] Use core stackato client for App Store installation and make
  asynchronous [94834]

* [95130] Auto redirect to logout when old or bad credentials are passed to
  deep linked page

* [94734] Fix handling of file system links when viewed in web console

* [95090] Defer re-staging of stopped apps when application environment is
  modified to next start request.

* [95049] Ensure log rotation of cloud controller rails log

* [94933] Improve handling of postgres restart in `kato import`

* [95151] Fix auto-incrementing of uniq keys in `kato import`

* [95156] Enable apt-get blacklist of some core packages to ensure system
  stability in system apt-get update

* [93847] Set max_droplet_size via `kato op max_client_upload`

* [95211] Run pre-running hooks after env generation during deployment to
  ensure database migrations are finished before the user commands execute

* [95082] Fix Grails incompatibility with TomEE due to conflicting
  validation jar

* [95028] Add JBoss framework JDBC service handling

* Updated Stackato client to 1.4.4:

  * [95197] Improved `logout` command to allow selective target logout

  * Fixed grails [95112] and aspdotnet [95122] framework auto-detection

  * Enhanced variable resolution in stackato manifest to resolve variables
    in the key portion of the yaml

  * Added EAR archive detection for JavaEE framework

  * Merge command line options from `push` into the stackato manifest values

  * [94852] Compare http headers case insensitively

Documentation
~~~~~~~~~~~~~

* Clarify usage of dnsmasq

* [93980] Document how to configure DNS to support access to an application URL

* Added .NET deployment section

* Improvements in:

  * client/core API docs

  * language deployment (java, VCAP_SERVICES, DATABASE_URL)

  * stackato.yml docs (variable subsitution etc.)

  * cluster & auto-scaling docs. (kato setup core)

* App-store docs rewrite. (JSON -> YAML based store, simplified)

* Best-practices docs rewrite. (migrations, export, import, dbshell...)

* Moved FAQ page to http://community.activestate.com/faq-list?tid=453

* Deprecated Kato setup controller/node. See :ref:`kato command reference <kato-command-ref>`.


Release v2.0.7 (Jul 19, 2012)
-----------------------------

* [94813] Fix for `kato import` failure when migrating from v1.x to v2.x

* [94737] Fix for potential sudo errors when sudo is enabled in the containers

* [94716] Fix for special characters causing issues in user email address

* [94740] Fix for NATS timeouts in the Stager

* [94578] Fix for Stackato usage reporting accuracy

* [94847] Fix for more precise memory usage calculation in deployed applications.

  * Improved container cleanup managment

* [94836] Optimisations for DEA app queuing after cold startups of Stackato.

  * Configurable simultaneous app starts per DEA
  * Configurable maxmium prealloc queue length

* [94812] Improved first setup workflow for statically configured IP environments.

* Update Stackato client to v1.4.2

* Various documentation improvements and updates


Release v2.0  (Jul 10, 2012)
----------------------------

* Better cluster management

  * kato, a better replacement for stackato-admin
  * Central multi-node configuration through doozer
  * Better process management through supervisord
  * CLI to edit configuration on all nodes: kato config
  * Fix: make nats-server run only on the controller node
  * Fix: automatically restart avahi-announcer and redis-server if
    they crash

* Merged with latest Cloud Foundry sources

  * New Memcached as a service
  * Router v2 upgrade
  * Configurable restart behaviour for crashing apps
  * New Java Play framework, also supported via Buildpacks

* Allow stager to be run on different node

* Avahi / mDNS now compatible with a cluster setup

* Improved `kato tail`; now includes non-vcap components such as nginx,
  postgres, redis.

* Base OS upgraded to Precise Pangolin (12.04)

* Database service versions upgrades

  * Postgresql upgraded to v9.1 (-> v8.4)
  * MySQL upgraded to v5.5 (-> v5.1)
  * Redis upgraded to v2.4 (-> 2.2)

* Python

  * Custom pypm/pip options via $PYPM_OPTS and $PIP_OPTS environment variables

* Scala support via Buildpack

* Java EE 6 support

  * New java_ee framework via Apache TomEE

* Integrated support for Iron Foundry .NET runtime

* Runtime upgrades

  * Node.js v0.6.18
  * PHP 5.3.10

* Stability bug fixes.

Release v1.2.6 ( May 15, 2012)
------------------------------

* Fix for an issue using the ``stackato-admin update-services-ip`` command

* Fix for missing Komodo debugging bits

* Fix for a groups issue when migrating from Stackato v1.0 -> v1.2

* Minor documentation updates

Release v1.2 (Apr 27, 2012)
---------------------------

* Upgraded Runtimes:

  * Ruby 1.9 upgraded to 1.9.3-p125 (from 1.9.2-p290)
  * Node.js upgraded to v0.6.15 (from v0.6.10)

* Updates to Stackato client.

* Heroku buildpack support, with built-in buildpacks for Clojure, Go,
  Java, Play! and Python

* ``stackato push|update`` will now tail the *staging.log* file simultaenously
  (like Heroku).

* Support for user groups

* Support for per-user and per-group limits

* Improved dbshell: ``stackato dbshell`` is deprecated in favour of ``stackato run
  dbshell``. The later works on cluster environment, and doesn't
  require local database clients to be installed.

* Added ``STACKATO_SERVICES`` as an alternative to ``VCAP_SERVICES``; ``PORT`` as
  an alias for ``VCAP_APP_PORT``.

* Added new service environment variables containing the respective
  connection URIs: ``DATABASE_URL``, ``MYSQL_URL``, ``POSTGRESQL_URL``, ``REDIS_URL``,
  ``MONGODB_URL``, ``RABBITMQ_URL``

* Allow SSH'ing to crashed app instances

* Optional support for caching staging files for faster ``stackato
  update``

* Disable truncation of vcap logs on component start. This preserves
  the log records when a vcap process is restarted.

* Added support for OpenStack auto-scaling

* Use geo-location aware debian mirrors in application containers
  for faster apt-get calls

* Improved the firstboot configuration process, eliminate a timeout
  bug in some cases.

* Improved, faster VM boot process (Moved to Upstart).

* VM now uses NTP for time synchronization

* Fix for supporting externally mapped URI's on applications

* Fix for Avahi broadcasting the wrong inteface address

* Add Go language support

* Add PyPy support (external buildpack required)

* Add JRuby support (external buildpack required)

* Python:

  * Allow pip to use mirrors (``--use-mirrors``) when installing
    packages

  * Upgrade to uWSGI 1.1.2

  * uWSGI now supports running Python 3.2 applications

* Perl

  * Upgrade to uWSGI 1.1.2

* Node.js:

  * All packages installed from NPM are now automatically added to the $PATH,
    meaning sudo priveleges for 'npm install -g' are no longer required.

* Clojure:

  * Upgrade to Leiningen 1.7; switch to Heroku Buildpack

* Automated DBGP Debugging

  * Pushing an app with ``--stackato-debug <host>:<port>`` enables
    Django, Rails, and Sinatra ``get`` requests to be debugged in DBGP-supporting
    apps like Komodo IDE with a ``STACKATO_DEBUG=1`` parameter, and enables PHP
    debugging with the ``XDEBUG_SESSION_START=1`` and ``XDEBUG_SESSION_STOP=1``
    parameters.

Release v1.0.6 (Mar 08, 2012)
-----------------------------

* Fix an issue for Filesystem services not unprovisioning correctly

* Fix an issue with LXC container memory management causing a potential system lockup


Release v1.0 (Feb 28, 2012)
---------------------------

* Revamped Stackato Management Console

  * Increased the administrators control of the overall system
  * Ability for users to control their own applications
  * Core system server performance graphs
  * Improved cloud events logging

* New persistent file system service

* Support for the Cloud Foundry (vmc) *manifest.yml*

* Added "Generic framework" to deploy applications with a arbitrary
  start procedure

* Support for dynamically pre-allocating application containers.

* make app environment variables available to staging, run
  commands, ssh and cron.

* ``stackato-admin report``: wrap logs and other system information
  for future diagnosis of a problem.

* The applications timezone is now inherited from the Stackato VM host

* ``$app_http_proxy`` is now available to specify a application specific ``$http_proxy``

  * The new ``stackato-admin upstream-proxy`` command helps setting this variable,
    check the docs or ``stackato-admin help`` for more information.

* Moved vcap logs in */tmp/vcap-run/* to *$HOME/stackato/logs/*

  * These logs are now compressed and rotated daily

* show the actual staging log, instead of `Error
  310: Staging failed`, upon push / update failures

* allow top-level dotfiles during staging

* ``stackato-admin become <node>`` now allows renaming operations
  on the VM, allowing you to speficy the FQDN and local hostname.

  * The shorthand ``all`` role has also been added to ``stackato-admin become`` to assign
    all the available roles.

* Bug fix for sporadic high load averages on DEA nodes

* NewRelic Server Monitoring bits are now preloaded onto the VM.

  * `Get Started <http://newrelic.com/features/server-monitoring>`_

* Implemented fallback console on the virtual TTY1 for unsupported
  resolutions.

* The TTY application now has fundamental error reporting built in.

* git, mercurial and subversion are now made available in application
  instances.

* Staging support for *manifest.yml*

* Support for a external MySQL Database (e.g existing cluster)

* Python:

  * Run pip with *requirements.txt*, as that is the most common filename
    used by Python projects; if only *requirements.pip* exists,
    run pip with that file. For PyPM, use *stackato.yml* or
    *requirements-pypm.txt*.
  * Fix: make "-e" (source installs) in pip *requirements.txt* work

* Clojure:

  * Automatically run ``lein deps`` to download dependencies

* Node.js:

  * Upgrade to v0.6.10

* Ruby 1.8:

  * Upgrade to patchlevel p-357



Beta Release 0.8.2 (Jan 17, 2012)
---------------------------------

* New web-based management console for administrative control of Stackato

* Merge with Cloud Foundry upstream as of Dec 21, 2011

* Application Staging now happens in LXC; thus more secure.

* Support for SSH'ing into application instances. (experimental)

* Improved and reliable ``stackato run`` based on SSH.

* Support for schedule tasks through cron (experimental)

* OpenStack build support

* Python:

  * Fix ``PYTHONPATH`` to contain correct value in the "run" command
  * Use PyPI mirrors during pip staging

* Java:

  * Move from Sun/Oracle Java packages to Open JDK/JRE packages (`why?
    <http://lwn.net/Articles/472466/>`__)

* Node.js:

  * Upgraded to version 0.6.7

* Clojure:

  * Leningen upgraded to version 1.6.2

* VM:

  * Added dynamic first boot configuration process to randomise
    the hostname and SSL certificates.
  * New console application running on tty1
  * Microcloud HTTPS/SSL certificate now supports the TLD and all subdomains
  * Udev networking rules have been disabled



Beta Release 0.6.0 (Nov 03, 2011)
---------------------------------

* Stackato admin dashboard (start with ``stackato-admin start
  dashboard``)

* Faster app deployment

* Set user's home directory to correct location within
  LXC containers

* Perl:

  * Remove Perl 5.12 and make Perl 5.14 the default
  * Store uWSGI command line in a ``$STACKATO_UWSGI`` environment
    variable.
  * Store the default Perl application startup command in a
    ``$PROCESSES_WEB`` environment variable (TBD for other frameworks)

* Python:

  * uWSGI for Python 3 is now officially supported
  * Store uWSGI command line in a ``$STACKATO_UWSGI`` environment
    variable.
  * Store the default Python application startup command in a
    ``$PROCESSES_WEB`` environment variable (TBD for other frameworks)
  * Add virtualenv's *bin/* directory to ``$PATH`` before
    starting the application

Beta release 0.5.2 (Oct 20, 2011)
---------------------------------

* Upgrade ActivePython to 3.2.2.3

* Upgrade Node.js to v0.4.12

* Upgrade Ruby 1.8 to patch level 290

* Additional LXC fixes for non starting apps

* Fix for broken clojure deployments


Beta release 0.5.1 (Oct 3, 2011)
--------------------------------

* LXC bug fixes and improvements (Error 306, etc.)

* Speed up PyPM/PPM/cpan/pip by caching file downloads from the internet

* Support for running custom hook scripts (post staging and pre running)

* Upgrade to uWSGI 0.9.8.5 (LTS)

* PHP support

* RabbitMQ support

* Python:

  * Properly show pip errors (during push/update/log) in *staging.log*
  * Add the application directory to ``$PYTHONPATH``
  * uWSGI: remove ``--catch-exceptions`` by default
  * uWSGI: allow applications to spawn threads
  * uWSGI: don't spawn an unnecessary additional server process

* Java:

  * Add ``:port`` back to ``VCAP_APPLICATION`` for the cloudfoundry runtime to work

* Server process monitoring (via monit)

* Known issues:

  * Clojure deployments are currently unavailable due to a change in the
    staging process.

PDP4 (Aug 25, 2011)
--------------------

* Instances are isolated using LXC containers on DEAs

* Clojure support

* General improvements to error reporting in *staging.log*

* Server now returns the git version info to client

* Documentation is hosted locally at http://docs.stackato.local

* ``stackato run``

  * Include app environment added via ``stackato env``
  * Wrap commands with quotes when necessary
  * Provide a ``dbshell`` command to invoke database clients
  * Run command no longer blocks the EventMachine reactor

* Python

  * Don't silently ignore packages missing in pypm repository
  * Deprecate virtualenv in favor of PEP 370 (faster deployments)
  * Allow invocation of scripts installed by package dependencies
  * Can now install packages with *./include* dir. (eg: greenlet)
  * Drop 'Generic Python' framework

* Ruby

  * Disable gem caching as it doesn't work with secure mode

* MySQL

  * Use UTF8 as the default database charset

VM
~~

* Upgrade to ActivePython 3.2.1.2
* Upgrade to NodeJS 0.4.10


PDP3 (July 13, 2011)
--------------------

* Support for PostgreSQL service

* Fix random 306 errors when push/update fails

* ``stackato run``:

  * Fix 306 errors after ~11 seconds
  * Suppress traceback for ENOENT
  * Kill the process after timeout
  * Make PPM area directory available
  * Cleanup ``$PATH``; add all runtimes to ``$PATH``

* Python

  * Note pypm/pip failures in staging.log

* Node

  * Auto install dependencies using ``npm install``

VM
~~

* Upgrade to ActivePython 2.7.2.5


PDP2 (June 22, 2011)
--------------------

* ``stackato run``:

  * Put runtime's path in front of ``$PATH``
  * Close STDIN descriptor to prevent hanging processes
  * Support ``--timeout`` option (default = 1 minute)
  * Ruby: set ``GEM_{HOME,PATH}`` environment variables so dependent
	binaries (eg: rake) can be run

* Python

  * pip and pypm can both be used to install Python
	dependencies
  * Python 3.x support for 'Generic Python' framework

* Perl

  * Perl applications must have a toplevel *app.psgi* file
  * Perl 5.14 support under the "perl514" runtime name
  * Perl modules can be installed with cpanm via *Makefile.PL*
  * new Perl logfiles: *logs/staging.log* and *logs/ppm4.log*

* Ruby:

  * Fix an issue with linking 1.9 gems with ruby1.8


VM
~~

* Support multiple uWSGI binaries (PSGI, Python 2.7, 3.2)
* No more uWSGI zombies
* Installer creates stackato service script in */etc/init.d*
* stackato-admin controls the avahi-announcer's lifecycle (no more
  need to start/stop it separately)
* Stackato client is installed on VM (necessary for multi-vm setups)
* Resource-efficient avahi-announcer
* avahi-announcer announce the apps names, not the
  mapped URLs
* stackato-admin can manage admin users

Internal
~~~~~~~~

* Remove the vcap/installer/remote after an install
* stackato-admin uses yaml parser instead of grep
* Install script is now called *install.sh* and accepts parameters
* Do not regenerate the mysql password on
  restarting ./install
* Don't pull uWSGI directly from mercurial repo
* Allow git branch argument for ./install

PDP1 (June 15, 2011)
--------------------



