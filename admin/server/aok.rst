.. _aok:

.. index:: Authentication Server (AOK)

AOK Authentication Server
=========================

Stackato's Cloud Controller has a built-in system for authenticating
users which it uses by default. It also has an authentication server
called "AOK" which supports using external systems such as LDAP.


End User Login
--------------

Web
^^^

In order to adapt to the login UI of various authentication systems,
users are redirected away from the Management Console to a page served
by AOK during Management Console login. Users should be notified of this
change in behavior if they have previously used the default interface.

Client
^^^^^^

Users connecting with the :ref:`stackato <client>` client should be aware that:

* Though prompted for ``Email:``, the user may need to enter their
  identifier in the format expected by the :ref:`strategy
  <aok-strategies>` used by AOK. For example, many LDAP systems require
  the user to enter a username rather than an email address.
  
* When using an existing authentication token to log in as a second user
  (e.g. an admin connecting as another user), use the second user's
  email address, *not the identifier used by AOK's strategy*.

These caveats also apply when using other Cloud-Foundry-compatible clients.

.. _aok-strategies:

Strategies
----------

The term *strategy* refers to the method used to authenticate users.
There are currently two supported strategies:

* **builtin**: The `builtin` strategy uses a local database of email
  addresses and passwords to authenticate users. *This strategy and
  database is distinct from the Cloud Controller's internal
  email/password database that is used when AOK is disabled.* If you
  wish to start using this strategy with the existing user login
  credentials, run the following in the */s/aok/* directory ::

    bundle exec rake import_users_from_cloud_controller

* **ldap**: The `ldap` strategy authenticates users using the LDAP server
  specified in *config/aok.yml*. **Any user that can successfully
  authenticate with the LDAP server will be allowed to use Stackato and
  will have a (non-admin) user account created for them automatically.**
  The LDAP server must return an email address for the user to allow
  them to log in to Stackato. AOK will look for the email
  address under the ``mail``, ``email``, and ``userPrincipalName`` attributes.
  
  LDAP groups are not currently supported as a visible construct in
  Stackato.
  
* **google_apps**: Authenticates users on a `Google Apps for Business
  <http://www.google.com/enterprise/apps/business/>`_ domain.
  ``stackato`` clients will need to authenticate using the
  :ref:`stackato token <command-token>` command.
      
The `use` key in the configuration file controls the strategy that AOK
will use. This value must correspond exactly to one of the supported
strategy names.

.. _aok-configuration:
  
Configuration
-------------

To configure AOK, set the following keys in the AOK config using :ref:`kato
config set <kato-command-ref-config>`:

* strategy:

  * use: set to either 'builtin', 'ldap', or 'google_apps'. The builtin
    strategy requires no further modification. The ldap and google_apps
    strategies requires setting options in the corresponding blocks
    below.
  
  * ldap:
  
    * host: hostname or IP of the LDAP server
    * port: LDAP server port, typically 389
    * method: plain, ssl, or tls
    * base: list of domain components (e.g. 'dc=example, dc=com')
    * uid: LDAP attribute name for the user name that will used in the
      login form. Active Directory (AD) is typically 'sAMAccountName' or
      'UserPrincipalName', while OpenLDAP is 'uid'.
    * email: the LDAP attribute containing the user's fully qualified
      email address. An email address attribute is necessary for AOK to
      work properly with the cloud controller. This may be a scalar
      attribute or an array of attributes to search. The default is
      shown. The first non-null attribute will be used (AOK will not
      validate that this is an email address). The default attributes are:
      
       * mail
       * email
       * userPrincipalName
       
    * bind_dn: (optional) credentials for user lookup (e.g.
      'cn=Administrator,cn=Users,dc=example,dc=com'). LDAP servers that
      allow anonymous binding will not require this setting.
    * password: (optional) default credentials for user lookup
    * try_sasl: (optional) when set to true attempts a SASL connection
      to the LDAP server
    * sasl_mechanims: (optional) 'DIGEST-MD5' or 'GSS-SPNEGO'

  * google_apps:
  
    * domain: your Google Apps domain. 

.. note::

  An aditional 'name_proc' option in the 'ldap' block allows users to
  enter email addresses instead of LDAP user names, matching the user name
  entered with the format of the uid attributes. For example, value of
  'sAMAccountName' in AD contains only the Windows user name. If your
  users prefer using email to login, the following 'name_proc' value will trim the
  email string down to just the Windows login name::
  
      Proc.new {|name| name.gsub(/@.*$/,'')}
  
  Value must be valid ruby code. Since the provided code will be
  accepting arbitrary user input. Administrators are urged to use this
  setting only when absolutely necessary, and to check the code
  thoroughly for possible security implications.
  
To see the the default AOK configuration (sample settings) run the command::

  $ kato config get aok
  
Settings are nested as per the option list above. To set an option,
specify the full config path to that option. For example::

  $ kato config set aok strategy/ldap/base 'dc=yourdomain, dc=com'

To add an attribute to the 'email' array::

  kato config push aok strategy/ldap/email "ADMailAcct"

To set the entire array in one step, use the ``--json`` option::

  kato config set --json aok strategy/ldap/email '["mail","ADMailAcct", "email"]'


Enabling
--------

AOK is disabled by default. While disabled, the Cloud Controller uses
its internal email/password database to authenticate. Execute the
following commands to enable AOK::
    
  kato config set cloud_controller aok/enabled true
  kato restart controller

If AOK is enabled before the initial admin account has been set up via
the Management Console welcome page, the ``stackato`` system user will
still have the default password. Change this as soon as possible using
the ``passwd`` command.

User Management
---------------

When using AOK with any strategy other than 'builtin', users in Stackato
will be created automatically for any user who successfully
authenticates.

Administrators can still use the functions as before, but should be
aware of the following caveats:

* Email addresses (used to identify users in Stackato) and group names
  are (currently) case sensitive. Avoid using the same string with
  different casing to refer to different entities.
  
* Admins may manually create users if they wish. This may be useful if the 
  admin wants to pre-assign users to groups in Stackato before those users
  have logged in for the first time. The admin must create the user with the
  same email address (case-sensitive) that AOK will receive from the strategy.
  
* Passwords set while creating users or using the password-change function 
  will be disregarded - Stackato/AOK does not manage the external
  authentication systems.
  
* Admins may delete users, but the user will be recreated if they log in
  again via AOK. If an admin wishes to prevent a user from using Stackato, the
  user's login credentials should be revoked in the external authentication 
  system.

SSL Certificate
---------------

AOK by default uses the same self-signed certificate as the Cloud Controller. To
prevent log warnings about the certificate, the Cloud Controller is configured 
to use a CA file on the VM to validate AOK's certificate. This is set in Doozer 
under the *aok/ca_file* key in the Cloud Controller's configuration.

.. _aok-ssl-load-balancer:

AOK with a Load Balancer
^^^^^^^^^^^^^^^^^^^^^^^^

In clusters with multiple Routers (specifically if the :ref:`Load
Balancer <cluster-load-balancer>` is used), the following steps will
correctly configure SSL certificates.

1. Take copies of the cert in */etc/ssl/certs/stackato.crt* from the Load Balancer node to each of the Controller nodes running AOK. This can be done with scp:

  ::
  
    $ scp stackato@<Load Balancer node>:/etc/ssl/certs/stackato.crt /tmp/aok.crt

2. Move the newly copied cert on your Controller into */etc/ssl/certs/* as 'root' or using sudo. Do not overwrite the existing */etc/ssl/certs/stackato.crt*:

  ::
  
    $ sudo mv /tmp/aok.crt /etc/ssl/certs/

.. note::
  These first two steps need to be repeated for *all* Controller nodes in
  the cluster.

3. Update Stackato's configuration with the following command:

  ::
    
    $ kato config set cloud_controller aok/ca_file /etc/ssl/certs/aok.crt

4. Run ``kato restart controller``

