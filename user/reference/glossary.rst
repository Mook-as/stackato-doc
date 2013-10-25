.. _glossary:

.. index:: Glossary

==========
 Glossary
==========

.. only:: not public

  .. note::
    See here for syntax of
    `Definition Lists <http://docutils.sourceforge.net/docs/ref/rst/restructuredtext.html#definition-lists>`_.
    See here for syntax of
    `Glossary Directive <http://sphinx.pocoo.org/markup/para.html#glossary>`_.

    You can use the ".. only:: not public" notation, as we have here,
    to enclose definitions that should be excluded from public builds.

    Due to a bug in Sphinx, this must be a leaf document with no
    references to labels elsewhere in the document tree.

.. glossary::

  AMI
    Acronym for `Amazon Machine Image <https://aws.amazon.com/amis/>`_.

  AMQP
    Acronym for `Advanced Message Queuing Protocol <http://en.wikipedia.org/wiki/Advanced_Message_Queuing_Protocol>`_.

  Apache ANT
    A software tool for automating software build processes. See `Ant <http://ant.apache.org/>`_ for more info.

  Apache Maven
    A build automation tool typically used for Java projects. See `Maven <http://maven.apache.org/>`_ for more info.

  app   
    Any application software intended for instantiation in Stackato.
    At minimum it consists of the application, expressed in a dynamic language,
    plus a configuration file named *stackato.yml* or *manifest.yml*.

  Avahi
    An implementation of :term:`multicast DNS` and related protocols.

  cluster
    A set of interconnected physical processors or virtual
    machines, managed at least conceptually as a single entity but
    otherwise operating autonomously.  Historically the term carried
    a variety of proprietary meanings, but came into general use
    with the rapid development of supercomputing based upon
    `Beowulf Clusters <http://en.wikipedia.org/wiki/Beowulf_cluster>`_.
    A Stackato cluster is one in which :term:`role`\s are assigned or
    replicated to multiple cluster :term:`node`\s.

  component
    Within Stackato, the term **component** is used when naming a discrete part of the Stackato server.  For example,
    a :term:`role` is made up of one or more components.

  container
    A lightweight form of virtualization which provides resource isolation and secure separation for multiple
    instances of the same base system.  According to circumstances it may be used in addition to or instead of
    hypervisor virtualization.

  CPAN
    Acronym for `Comprehensive Perl Archive Network <http://www.cpan.org/>`_.
  
  doozerd
    A consistent distributed data store. Used for cluster management in
    Stackato. (see `Doozer project on GitHub <https://github.com/ha/doozerd/#readme>`_)

  DHCP
    `Dynamic Host Configuration Protocol
    <http://en.wikipedia.org/wiki/Dynamic_Host_Configuration_Protocol>`_.  
    The DHCP service is used to allocate IP addresses to clients on demand and to supply other basic
    network information they need, such as the addresses of a default router and DNS server.
  
  DNS
    `Domain Name System
    <http://en.wikipedia.org/wiki/Domain_Name_System>`_.
    Resolves domain names to IP addresses. 

  dnsmasq
    A `lightweight server <http://en.wikipedia.org/wiki/Dnsmasq>`_ for locally integrating DNS with DHCP/BOOTP.

  dynamic DNS
    A means of rapidly updating the Domain Name System, possibly making use of :rfc:`2136` Dynamic Updates.

  EC2
    Acronym for `Amazon Elastic Compute Cloud <http://aws.amazon.com/ec2/>`_.

  filesystem
    In Stackato, **filesystem** refers to persistent storage accessed by an application :term`service`
    specified in *stackato.yml* through a server which has been assigned the filesystem :term:`role`.

  JSON
    A notation for structured text data,
    acronym for `JavaScript Object Notation <http://en.wikipedia.org/wiki/JSON>`_.

  MBUS
    Stackato's implementation of an :rfc:`3259` message queue used for interprocess communication.
    *See also:* :term:`NATS`.

  memcached
    Free & open source, high-performance, distributed memory object caching system,
    generic in nature, but intended for use in speeding up dynamic web applications
    by alleviating database load. (see `Memcached project page <http://memcached.org/>`_)

  micro cloud
    A preconfigured Stackato virtual machine image consisting of a single generic :term:`node` enabled for
    all the :term:`role`\s necessary for basic operation, but with no preinstalled :term:`app`\s
    or :term:`service`\s.

  mongodb
    A popular `noSQL <http://en.wikipedia.org/wiki/NoSQL>`_ database management system.

  multicast DNS
    A distributed means of configuring DNS by `multicast discovery <http://en.wikipedia.org/wiki/Multicast_DNS>`_.
    It is supported on Stackato :term`micro cloud` servers using :term:`Avahi`.

  mysql
    A relational database management system.

  NAT
    Acronym for `Network Address Translation <http://en.wikipedia.org/wiki/Network_address_translation>`_.

  NATS
    In Stackato, a publish-subscribe message system implemented as a process called ``nats-server``
    which listens on a network interface, normally on port `4222/tcp`.
    Messages published across the network to a particular :term:`MBUS` queue
    managed by the nats-server are communicated  to clients which are subscribed to that queue.

  Nginx
    `Nginx <http://wiki.nginx.org/>`_ is a high-performance, event-driven web server.

  node
    A Stackato **node** is a single processing host in a :term:`cluster`, typically a virtual machine
    running under a hypervisor.

  OVF
    Acronym for `Open Virtualization Format <http://dmtf.org/standards/ovf>`_,
    a specification for virtual machine images developed by the DMTF industry consortium.

  PaaS
    Acronym for `Platform as a Service <http://en.wikipedia.org/wiki/Platform_as_a_service>`_.

  pip
    A tool for installing and managing Python packages, such as those found in the Python Package Index.
    It's a replacement for easy_install. See `pip-installer <http://www.pip-installer.org/en/latest/>`_ 
    for more information.

  PyPM
    PyPM  is the *binary* package manager for ActivePython. It is usually the fastest and most reliable
    way of installing PyPI packages for your Stackato applications. The PyPM repository hosts almost all 
    of the Python packages registered in PyPI and includes their latest versions.
    See `PyPM <http://code.activestate.com/pypm>`_ for more information.

  Polipo
    A lightweight caching web proxy intended for small applications.

  postgresql
    A relational database management system.

  private PaaS
    A private :term:`PaaS` is one which is hosted on your private cloud, behind your firewall.

  RabbitMQ
    A `message broker <http://en.wikipedia.org/wiki/Message_broker>`_ subsystem which
    implements :term:`AMQP`.

  Redis
    An implementation of memory resident key-value store.

  resolvconf
    A system configuration tool typically used by hook scripts at boot time.
    See the `resolvconf man page <http://manpages.ubuntu.com/manpages/man8/resolvconf.8.html>`_ 
    for details.

  role
    Each :term:`node` in a Stackato :term:`cluster` may be assigned certain selectable 
    capabilities
    within the Stackato architecture.
    These capabilities are called **roles**, and are usually denoted in lowercase.
    Examples of essential roles are **router**, **primary**, **controller**, and **dea**.
    In addition, there are **role groups** (for convenience) such as **data-services** that 
    represent all data-services. (postgresql mysql rabbit mongodb redis filesystem memcached)
    

  service
    In Stackato, a **service** is a type of :term:`role` that may be provisioned on a server and accessed by
    an application as specified in *stackato.yml*.

  supervisord
    A process control system used by Stackato internally. (see `Supervisor
    project page <http://supervisord.org/>`_)

  tty console
    The hypervisor window which provides serial console access to one of its virtual machines.

  VMDK
    Acronym for `Virtual Machine Disk Format <http://www.vmware.com/technical-resources/interfaces/vmdk.html>`_,
    a proprietary specification for virtual machine images developed by VMware.

  YAML
    A notation for structured text data,
    acronym for `YAML Ain't Markup Language <http://en.wikipedia.org/wiki/YAML>`_,
    used in *stackato.yml* and *manifest.yml* configuration files.
