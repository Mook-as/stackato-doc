.. _server-configuration:

.. index:: Detailed Configuration

Detailed Configuration
======================

.. _server-config-general:

General
-------

.. note::
  After booting the VM, run ``kato process ready all`` before starting
  the following configuration steps. This command returns ``READY`` when
  all configured system processes have started, and is particularly
  important when using ``kato`` commands in automated configuration
  scripts which run immediately after boot (the :ref:`--block
  <kato-command-ref-process-ready>` option is useful in this
  scenario).
  
.. _server-config-password:

Changing the Password
^^^^^^^^^^^^^^^^^^^^^

The default password for the ``stackato`` system user is **stackato**.

This password is changed to match the one set for the first
administrative user created in the Management Console. Once you've set
up the primary Stackato admin account, use that account's password when
logging in to the VM at the command line.

In a Stackato cluster, this change only happens on the node serving the
Management Console pages (which could be one of :ref:`multiple
Controller nodes <cluster-multi-controllers>`). In this case, it's best
to log in to each node in the cluster to change the password manually
with the ``passwd`` command.


.. _server-config-network:

.. index:: Network Setup

Network Setup
-------------

.. _server-config-hostname:

.. index:: Changing the Hostname

.. index:: Hostname

Changing the Hostname
^^^^^^^^^^^^^^^^^^^^^

You may want or need to change the hostname of the Stackato system,
either to match a DNS record you've created or just to make the system
URLs more convenient. This can be done using the :ref:`kato node rename
<kato-command-ref>` command::

	$ kato node rename mynewname.example.com
  

This command will change the system hostname in ``/etc/hostname`` and ``/etc/hosts``,
as well as performing some internal configuration for Stackato such as generating a new
server certificate for the :ref:`Management Console <management-console>`.

mDNS is only supported with ".local" hostnames. If you want to give the
VM a canonical hostname on an existing network, :ref:`configure DNS
<server-config-dns>` and disable the 'mdns' role::

  $ kato role remove mdns

.. note::
    Stackato takes a while to configure itself at boot (longer at first
    boot). Check 'kato status' to see that core services are running
    before executing 'kato node rename ..'.

In a :term:`cluster`, you may also need to manually
:ref:`modify the /etc/hosts file <server-config-etc-hosts>`.

.. _server-config-ip:

.. index:: Changing IP Addresses

Changing IP Addresses
^^^^^^^^^^^^^^^^^^^^^

The Stackato :ref:`micro cloud <quickstart-setup-server-microcloud>`
server is initially set up for :term:`DHCP` and :term:`multicast DNS`.
This is often sufficient for local testing, but in this configuration is
only a single node and can only be privately routed.

As you move toward production use of the server, further configuration
of IP addresses and hostnames will therefore be required. A production
Stackato server will most likely be a :term:`cluster` consisting of
several nodes, some of them requiring IP addresses and corresponding
hostnames.

If your server is to be exposed to the Internet, these addresses must be
routable and the hostnames must appear in the global DNS. Even if your
server is to be part of a :term:`private PaaS` for organizational use
only, it must still integrate fully with your network services, DHCP and
DNS in particular. Finally, in the rare case that such services are not
available, the Stackato server can be configured with static IP
addresses and hostnames.

Before we examine these scenarios in detail, let's review the separation
of roles in a :ref:`cluster <cluster-setup>`:

* The **core** node which we conventionally call
  ``api.stackato-xxxx.local`` in a micro cloud will be given its own
  hostname and IP address in a cluster so that you can reach it from
  both the :ref:`Management Console <management-console>` and
  the command line.

* At the same time, the other nodes in the cluster will also need to
  reach the core node, so whatever address is configured on its network
  interface will have to be known to the network, the primary node,
  and all the other nodes. This can be the same as the primary address
  assigned to the core, or a secondary address used purely within
  the cluster.

* The **router** nodes, if separate from the primary, will each
  require IP addresses of their own, reachable from any load balancer
  and through any firewall that you put in front of them.

Where you configure these hostnames and IP addresses will depend on how
you operate your data center network. You will want to confer with your
network administrator about this, starting with the MAC address
configured for each VM in the hypervisor. If your site supports a
significant number of VMs, DHCP may be set up to map MAC addresses to IP
addresses in a particular way. For example, a certain range of MAC
adddresses may be used for servers in the DMZ, and another range for
internal servers. If you follow this convention, your Stackato server
will obtain an appropriate IP address automatically. DNS at your site
may establish a similar convention, which you will want to follow when
making any name or address changes within the cluster.

Having determined the hostnames of cluster nodes to be managed by
:ref:`DNS <server-config-dns>`, the hostname on the primary node
should be set using :ref:`kato node rename <server-config-hostname>`.

Finally, if you must set a static IP on any cluster node, be sure to
test it before making the change permanent, otherwise you may not be
able to reach the node once it reboots. Assuming that the primary
address is on interface ``eth0``, a secondary address ``10.0.0.1/24``
could be set up temporarily as follows::

	$ ipcalc -nb 10.0.0.1/24
	Address:   10.0.0.1             
	Netmask:   255.255.255.0 = 24   
	Wildcard:  0.0.0.255            
	=>
	Network:   10.0.0.0/24          
	HostMin:   10.0.0.1             
	HostMax:   10.0.0.254           
	Broadcast: 10.0.0.255           
	Hosts/Net: 254                   Class A, Private Internet
	$ sudo ifconfig eth0:1 10.0.0.1 netmask 255.255.255.0 broadcast 10.0.0.255 up

Configure another cluster node using a different address on the same
subnet, and be sure that ``ping`` works correctly on the new addresses.
You should also use this opportunity to ping the router and DNS server
for this subnet. Check with your network administrator for their
addresses.

.. _server-config-static-ip:

.. index:: Static IP

Setting a Static IP
^^^^^^^^^^^^^^^^^^^

The easiest way to configure a Stackato VM with a static IP address is
to use the :ref:`kato op static_ip <kato-command-ref-op>` command.

This command will prompt for the following inputs:

* static IP address (e.g. 10.0.0.1)

* netmask (e.g. 255.255.255.0)

* network gateway (e.g. 10.0.0.254)

* (optional) comma-separated list of DNS names servers (e.g. 10.0.0.252, 10.0.0.253)

* (optional) comma-separated list of DNS search domains (e.g. example.com, example.org)

kato will verify the IP addresses given are within legal ranges,
automatically calculate the network / broadcast addresses for you, and
prompt for the 'sudo' password to write the changes.

As a precaution, the command does not automatically restart networking
services. To do so, run the following commands::

    $ sudo /etc/init.d/networking restart

.. note::

  If you are setting a new static IP *after* having configured the VM as
  a Core node in a cluster, you must run the :ref:`kato node migrate
  <kato-command-ref-node-attach>` command on each Stackato node to reset the
  MBUS_IP for the cluster.

Alternatively, these changes could be made by editing the
*/etc/network/interfaces* file manually. For example::
	
    auto eth0
    iface eth0 inet static
        address 10.0.0.1
        netmask 255.255.255.0
        network 10.0.0.0
        broadcast 10.0.0.255
        gateway 10.0.0.254
        dns-nameservers 10.0.0.252, 10.0.0.253
        dns-search example.com, example.org

When DHCP is not used, DNS server IP addresses must be set explicitly
using the ``dns-nameservers`` directive as shown above. Multiple DNS
servers can be specified in a comma separated list.

.. note::

    Stackato clusters running on :ref:`EC2 <server-vm-ec2>` will
    normally be registered with Elastic IP, which will provide local
    dynamic address and DNS configuration over DHCP while publishing an
    external static address for the cluster. You do not have to
    configure the DNS server address in */etc/network/interfaces*.

Note that ``dnsmasq`` does not necessarily reinitialize on ``SIGHUP``.
Therefore, perform the following to reinitialize::

	$ sudo /etc/init.d/dnsmasq restart
	$ sudo /etc/init.d/networking restart

Or use ``sudo shutdown -r`` to exercise a complete restart. Then use
``ifconfig`` to check that the interface has been configured, and
``ping`` to check routing to other hosts on the subnet and out in the
world. Finally, use ``dig @<DNS SERVER IP> <HOSTNAME>`` to check that
DNS is resolving correctly.

In the event of troubleshooting, you can confirm which DNS servers are
being used by dnsmasq by checking the file */var/run/dnsmasq/resolv.conf*.

.. note::

    There may be a performance advantage in locally defining a private
    secondary IP address (:rfc:`1918`) for the controller so that the
    other nodes can be assured of routing directly to it. See your network
    administrator for advice on which addresses and subnets are
    permissible. Once you have this secondary address set up, see the
    :ref:`/etc/hosts <server-config-etc-hosts>` section for final
    configuration of the server.

.. _server-config-etc-hosts:

.. index:: /etc/hosts

Modifying /etc/hosts
^^^^^^^^^^^^^^^^^^^^

The ``/etc/hosts`` file is used to resolve certain essential or local
hostnames without calling upon the DNS. Unless you need to :ref:`change
the local hostname <server-config-hostname>`, you will in general *not*
have to edit ``/etc/hosts`` manually, but when troubleshooting network
issues it never hurts to verify that the file is configured correctly.

As well, various components in a :ref:`Cluster <cluster-setup>`
rely on finding the cluster nodes in ``/etc/hosts``:
the Cloud Controller and the RabbitMQ service in particular.

Stackato will automatically configure ``/etc/hosts`` on the virtual
machine with one entry for the ``localhost`` loopback address and
another for the :rfc:`1918` private IP address of the cluster's Primary
node, for example "10.0.0.1" or "192.168.0.1". All communication between
cluster nodes should be strictly through their private IP addresses and
not on routable addresses provided by the DNS.

Remember that ``/etc/hosts`` does not support wildcards. You must use some 
form of :ref:`DNS <server-config-dns>` for that.

.. only:: not public

  .. note::
	At boot time, Stackato configures ``/etc/hosts`` in ``/etc/dhcp/dhclient-exit-hooks.d/stackato``
	with the IP address reported by ``kato info`` as ``mbusip``.
	This is the interface on which the nats-server process responsible for the MBUS is listening.

Consider a Stackato instance called ``stackato-test`` in domain
``example.com``. The following example is what you should expect to see
on a :term:`micro cloud` installation, where all roles are running on
the same node::

	$ hostname
	stackato-test
	$ ifconfig eth0
	eth0      Link encap:Ethernet  HWaddr 08:00:27:fc:1c:f6
          inet addr:10.0.0.1  Bcast:10.0.0.255  Mask:255.255.255.0
          inet6 addr: fe80::a00:27ff:fefc:1cf6/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:875142 errors:0 dropped:0 overruns:0 frame:0
          TX packets:106777 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000
          RX bytes:191340039 (191.3 MB)  TX bytes:23737389 (23.7 MB)
	$ cat /etc/hosts
	127.0.0.1	localhost stackato-test
	10.0.0.1	stackato-test.example.com api.stackato-test.example.com

On a :term:`cluster` installation, the IP address in /etc/hosts will
identify the node hosting the MBUS, usually the same as the Cloud
Controller. On this node, you will see a correspondence between the
network interface ``eth0`` address and ``/etc/hosts`` as in the above
example. On each of the *other nodes* in the cluster, for example DEA
nodes, ``eth0`` will be configured with its own address on
the same subnet, but ``/etc/hosts`` will remain the same..

If modifying ``/etc/hosts`` becomes necessary because of a hostname change,
you can simply edit it as in the following example::

	$ sudo vi /etc/hosts

.. _server-config-dns:

.. index:: DNS

DNS
^^^

The Stackato :term:`micro cloud` server is configured to support :term:`multicast DNS`.
The mDNS/DNS-SD broadcast address (``stackato-xxxx.local``) is intended for
private micro clouds running on a local machine or a local subnet.

For production use, the server will need:

* a public DNS record,
* a wildcard CNAME record, and
* a fixed IP address.

The wildcard is particularly important for locating your installed apps,
because each will run in its own :term:`container` for privilege separation,
and each container is given a separate hostname.

Detailed instructions for configuring DNS on various networks is beyond
the scope of this guide, but in essense the resulting DNS zone file should
contain something similar to::

	stackato-test.example.com          IN    A        10.0.0.1
	*.stackato-test.example.com        IN    CNAME    stackato-test.example.com

If you intend to expose your applications at URLs other than this wildcard through the
use of :ref:`stackato map <command-map>` or :ref:`stackato push --url <command-push-url>`
then you will want to add the name information to the DNS zone file as well.
Firewalls and load balancers at your site may require corresponding adjustments::

	app.domain.com                     IN    CNAME    stackato-test.example.com

.. note::
	If your site uses DHCP to assign an IP address to the Stackato server,
	you will want to configure the DHCP server to assign a fixed
	address corresponding with the MAC address of the virtual
	machine.  Be careful not to change the MAC address accidentally
	through the hypervisor.  If the Stackato server is hosted on a cloud
	provider, arrange to use a fixed IP address if possible.  For example,
	Amazon EC2 supports this with Elastic IP.

With DNS records in place, the multicast DNS broadcast is no longer necessary.
To turn it off on the Stackato server, use the command::
	
	$ kato role remove mdns

.. _server-config-dyndns:

.. index:: dyndns

Dynamic DNS
^^^^^^^^^^^

If you don't have access to a DNS server, you can use a dynamic DNS provider, such as
`ChangeIP <http://www.changeip.com/freedomains.asp>`_
and
`others <https://help.ubuntu.com/community/DynamicDNS#Registering_with_a_Dynamic_DNS_provider>`_,
to provide DNS records.
You will need one that provides wildcard subdomain assignment.

Before registering your domain, be sure that your mail server will accept
email from the provider (for example ``support@changeip.com``).

Create an account, choose a subdomain, and ensure that a wildcard
assignment is made on the subdomain to handle ``api`` and related
application subdomains.  Then wait to receive the authorization email,
and verify the zone transfer before proceeding.


.. index:: DNS Alternatives

.. _server-config-dns-alternatives:

Alternate DNS Techniques
^^^^^^^^^^^^^^^^^^^^^^^^

For situations where mDNS will not work (e.g. running in a cloud hosting
environment or connecting from a Windows system without mDNS support)
but which do not merit the effort of manually configuring a DNS record
(e.g. a test server) alternative methods are available.

.. index:: xip.io

.. _server-config-xip_io:

xip.io
~~~~~~

The quickest way to get wildcard DNS resolution is to use the `xip.io
<http://xip.io>`_ service.

:ref:`Change your hostname <server-config-hostname>` using :ref:`kato
node rename <kato-command-ref-node-attach>` to match the external IP address with
the 'xip.io' domain appended. For example::

    $ kato node rename 10.9.8.7.xip.io

This will change the system hostname and reconfigure some internal
Stackato settings. The xip.io DNS servers will resolve the domain
'10.9.8.7.xip.io' and all sub-domains to '10.9.8.7'. This works for
private subnets as well as public IP addresses.


.. index:: dnsmasq

.. _server-config-dnsmasq:

dnsmasq
~~~~~~~

Locally, you can run :term:`dnsmasq` as a simple DNS proxy which resolves
wildcards for ``*.stackato-test.example.com`` to ``10.9.8.7`` when line
such as the following is present in any of its configuration files::

	address = /.stackato-test.example.com/ 10.9.8.7

You must restart the service to pick up the changed configuration::

	$ /etc/init.d/dnsmasq restart

.. _server-config-add-nameserver:

Adding DNS Nameservers
^^^^^^^^^^^^^^^^^^^^^^

You may need to add site-specific DNS nameservers manually if the
Stackato VM or applications running in Stackato containers need to
resolve internal hosts using a particular nameserver.

To explicitly add a DNS nameserver to a Stackato VM running under DHCP,
edit */etc/dhcp/dhclient.conf* and add a line with the DNS server IP.
For example::

  append domain-name-servers 10.8.8.8;
 
Reboot to apply the changes.

For Stackato VMs with a static IP, add the nameservers when prompted
when running the ``kato op static_ip`` command (see :ref:`Setting a
Static IP <server-config-static-ip>` above).

TCP/UDP Port Configuration
^^^^^^^^^^^^^^^^^^^^^^^^^^

.. include:: ../common/ports.inc

.. _server-config-http-proxy:

.. index:: Polipo

HTTP Proxy
^^^^^^^^^^

.. note::
	If your network has an HTTP proxy, the stackato client may
	attempt to use this when connecting to api.stackato-xxxx.local
	and fail because the changes in ``/etc/hosts`` file are not
	reflected in the proxy.
	To work around this problem in Windows, enable
	``\*.local`` in the ``ProxyOverride`` registry key
	``HCU/Software/Microsoft/Windows/CurrentVersion/Internet Settings``.
	
In some cases, it may be a requirement that any HTTP request is first
handled through an upstream or parent proxy (HTTP requests may not be
directly routable otherwise).

In this case it is neccesary to tell :term:`Polipo` about the proxy so
it knows how to handle this correctly.

Open the Polipo config file ``/etc/polipo/config`` and add the lines::

	parentProxy = <IP>:<PORT>
	parentAuthCredentials = "myuser:mypassw"

Then restart Polipo::

	$ sudo /etc/init.d/polipo restart

If you are using a SOCKS proxy, edit the file in the same way but with the lines::

	socksParentProxy=<IP>:<PORT>
	socksProxyType=socks4a | OR | socks5;

Then restart Polipo::

	$ sudo /etc/init.d/polipo restart

For log info, any errors reported by Polipo are available on the Stackato server
in ``/var/log/polipo/polipo.log``.
	
.. _server-config-http-proxy-cache:

.. index:: HTTP Proxy Cache

HTTP Proxy & Staging Cache
^^^^^^^^^^^^^^^^^^^^^^^^^^

Stackato caches all application dependencies that are downloaded by
module managers that support the :term:`HTTP_PROXY` environment variable
(e.g. pip, PyPM, PPM, NPM, etc). This is limited to 100MB of in-memory
cache.

If you have an upstream HTTP proxy that deployed applications and the
staging system need to traverse to access the internet, use the ``kato
op upstream_proxy ...`` command on all DEA nodes::

	$ kato op upstream_proxy set 192.168.0.99:3128
	
To remove the proxy setting::

	$ kato op upstream_proxy delete <proxy_addr>
	
To set an HTTP proxy exclusively for apps, add an ``app_http_proxy``
entry to the ``/lxc/template/rootfs/etc/environment`` file on the DEA
nodes. For example::

	app_http_proxy=http://192.168.0.99:3128



.. _server-config-filesystem:

VM Filesystem Setup
-------------------

The Stackato VM is distributed with a simple deafult partitioning
scheme (i.e. everything but "/boot" mounted on "/").

Additionally, some hypervisors (OpenStack/KVM) will start the VM with a
relatively small disk (10GB).

.. warning::
  When setting up a production cluster, additional filesystem
  configuration is necessary to prevent certain nodes from running out
  of disk space.

Some nodes in a production cluster may require additional mount points
on external block storage for:

* services (data and filesystem service nodes)
* droplets (controller nodes)
* containers (DEA and Stager nodes)

Suggestions for mounting block storage and instructions for relocating
data can be found in the :ref:`Persistent Storage
<bestpractices-persistent-storage>` section.

Stackato Data Services vs. High Availability Databases
------------------------------------------------------

Stackato data services do not offer any built-in redundancy. For
business-critical data storage, a high-availability database or cluster
is recommended.

To use an external database instead of the data services provided by
Stackato, specify the database credentials directly in your application
code instead of using the credentials from the :term:`VCAP_SERVICES`
environment variable.

To tie external databases to Stackato as a data service, see the
examples in the :ref:`Adding System Services <add-service>` section.

.. _server-config-https:

.. index:: HTTPS
.. index:: SSL

HTTPS & SSL
-----------

HTTPS mode provides access to the provisioned apps using wild card SSL
certificates through the router or :term:`Nginx` web server.

There are self-signed certificates on the VM to match the default
hostname ``stackato-xxxx.local``. These certificates can be found in:

* ``/etc/ssl/certs/stackato.crt`` (Public Certificate)
* ``/etc/ssl/private/stackato.key`` (Used to generate the signed certificates)

If you change the hostname, you will need to regenerate the certificates
or use your own (signed or self-signed) certificate.

.. _server-config-ssl-cert-own-use:

.. index:: SSL Certificates

Using your own SSL certificate
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

On all router nodes, upload your *.key* file to the */etc/ssl/private/*
dirctory and your *.crt* file to */etc/ssl/certs/*. Change the following
settings in */s/vcap/stackato-router/config/local.json* to point to
the new files::

  "sslKeyFile": "/etc/ssl/private/example.key",
  "sslCertFile": "/etc/ssl/certs/example.crt",


.. _server-config-ssl-cert-chain:

.. index:: SSL Certificate Chain

CA Certificate Chaining
^^^^^^^^^^^^^^^^^^^^^^^

When using a signed certificate for Stackato, the certificates in the
chain must be concatenated in a specific order:

* the domain's crt file
* intermediate certs
* the root cert

For example, to create the final certificate for the chain in Nginx
format::

    $ sudo su -c "cat /etc/ssl/certs/site.crt /path/to/intermediate.crt /path/to/rootCA.crt > /etc/ssl/certs/stackato.crt"

Once the cert is chained, restart the router processes::

    $ kato restart router

Verify that the full chain is being sent by Nginx using ``openssl``. You
should see more than one number in the list. For example::

    $ openssl s_client -connect api.stacka.to:443
    ---
    Certificate chain
     0 s:/C=CA/ST=British Columbia/L=Vancouver/O=ActiveState Software Inc./OU=Stackato/CN=*.stacka.to
       i:/C=US/O=DigiCert Inc/OU=www.digicert.com/CN=DigiCert High Assurance CA-3
     1 s:/C=US/O=DigiCert Inc/OU=www.digicert.com/CN=DigiCert High Assurance CA-3
       i:/C=US/O=DigiCert Inc/OU=www.digicert.com/CN=DigiCert High Assurance EV Root CA
     2 s:/C=US/O=DigiCert Inc/OU=www.digicert.com/CN=DigiCert High Assurance EV Root CA
       i:/C=US/O=Entrust.net/OU=www.entrust.net/CPS incorp. by ref. (limits liab.)/OU=(c) 1999 Entrust.net Limited/CN=Entrust.net Secure Server Certification Authority


.. _server-config-ssl-cert-own-create:

.. index:: Generating SSL Certificates

Generating a self-signed SSL certificate
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

You can generate your own self-signed SSL certificate by running the
following commands on the Stackato server, substituting
"hostname.mydomain.com" with your own details::

	$ mkdir ~/hostname.mydomain.com
	$ cd ~/hostname.mydomain.com
	$ (umask 077 && touch host.key host.cert host.info)
	$ openssl genrsa 2048 > host.key
	$ openssl req -new -x509 -nodes -sha1 -days 365 -key host.key -multivalue-rdn \
		-subj "/C=CA/emailAddress=email@mydomain.com/O=company_name/CN=*.mydomain.com/CN=mydomain.com" \
		> host.crt

For specific configurations that can be used in the ``-subj`` option,
see http://www.openssl.org/docs/apps/req.html.

Following that, run::

	$ openssl x509 -noout -fingerprint -text < host.crt > host.info
	$ chmod 400 host.key host.crt

To get the router to use the new certificate and key files, follow the
steps in the :ref:`Using your own SSL certificate
<server-config-ssl-cert-own-use>` section above.

.. MARKUP Note that spaces are necessary below for correct alignment on display.

With any self-signed SSL certificate, you will get browser warning
messages. The certificate will need to be added to the browser
exception rules, which you will be prompted to do so when visiting
one of your apps via HTTPS for the first time.

.. _server-config-router-legacy:

.. index:: router_legacy

.. index:: SPDY

.. index:: WebSockets

.. _server-config-limits:

Users and Group Limits
----------------------

Limits for specific users and groups can be set for memory usage, number
of apps, number of services, and the ability to run the ``sudo`` command
within application containers.

You can manage groups, users, and limits in the :ref:`Users
<console-users>` and :ref:`Groups <console-groups>` sections of the
:ref:`Management Console <management-console>` or by using the
``stackato`` client :ref:`administration commands
<command-administration>`.

The :ref:`kato data users <kato-command-ref-data-users>` command is
available to :ref:`import or export <user-import-export>` user lists in
CSV format.

.. _server-config-sudo:

sudo
----

Users and Groups
^^^^^^^^^^^^^^^^

Both individual users and groups can have the use of the ``sudo``
command limited (the default is to disallow its use). See the
:ref:`Managing Groups, Users, & Limits <admin-groups>` documents for
details on managing these limits.


Allowed Repositories
^^^^^^^^^^^^^^^^^^^^

Even if ``sudo`` is restricted, special access can be given to specific repositories for modules and resources needed during the staging process.

To configure these, modify the ``allowed_repos:`` parameter of the
``cloud_controller.yml`` file::

	allowed_repos:
    - "deb mirror://mirrors.ubuntu.com/mirrors.txt natty main restricted universe multiverse"
    - "deb mirror://mirrors.ubuntu.com/mirrors.txt natty-updates main restricted universe multiverse"
    - "deb http://security.ubuntu.com/ubuntu natty-security main universe"

The file is located on the Stackato server at
``~/stackato/vcap/cloud_controller/config/cloud_controller.yml``.
