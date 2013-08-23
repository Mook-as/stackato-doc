.. _cloudinit:

.. index:: CloudInit

cloud-init
==========

`cloud-init <https://help.ubuntu.com/community/CloudInit>`_ (the
Ubuntu package for handling early initialization of cloud instances) can
be used to provide additional flexibility when configuring Stackato
cluster nodes, and can simplify joining a cluster and assigning roles.

cloud-init can be configured at instance launch time via the
``--user-data`` or ``--user-data-file`` arguments to `ec2-run-instances
<http://docs.amazonwebservices.com/AWSEC2/latest/CommandLineReference/ApiReference-cmd-RunInstances.html>`_,
or by pasting YAML directly into the EC2 or OpenStack Horizon
interfaces.

For example, given a core node at IP 10.2.3.4, the following cloud-config
would add a new DEA node to the cluster::

    #cloud-config

    stackato:
      nats:
        ip: 10.2.3.4
      roles: ['dea']
      extname: "paas.example.com"

* ``nats:ip`` will run ``kato attach <nats ip>`` the first time the VM
  is booted.

* ``extname`` when supplied with a fully qualified domain name will
  run ``kato rename <extname>`` on the instance first boot.

* Roles takes a list of roles to configure the node with. For guidance
  on how to work with roles see :ref:`Roles <server-cluster-roles>`.

Securing the new node
---------------------

To lock down and secure this new node, you could use standard
cloud-config directives for adding any SSH keys, randomizing passwords,
and/or disabling password based authentication entirely. An example that
creates a data services node, enables passwordless sudo for the admin
group, and disables password based authentication::

    #cloud-config

    stackato:
      nats:
        ip: 10.2.3.4
      roles: ['data-services']

    chpasswd:
     list: |
       stackato:RANDOM
       root:RANDOM
       ubuntu:RANDOM
     expire: false
    ssh_pwauth: false

    bootcmd:
    - - cloud-init-per
      - once
      - sudo_admin_group_nopasswd
      - sed
      - -ri
      - s|^%admin .*|%admin ALL=\(ALL\) NOPASSWD:ALL|
      - /etc/sudoers

Elastic DNS (EC2)
-----------------

On EC2, it is also possible to use a well-known trick to resolve the public
DNS name for an elastic IP to a local IP (within EC2). To use the DNS
name rather than a specific local IP, your configuration changes
slightly::

    #cloud-config

    stackato:
      nats:
        elastic_dns: ec2-75-101-137-243.compute-1.amazonaws.com

This configuration will automatically obtain the local IP of whichever
node is configured with the public IP 75.101.137.243 and use that when
communicating over the message bus.

Custom System Configuration
---------------------------

In addition to the Stackato node configuration tasks described above,
cloud-init can be used for a variety of system setup tasks:

* adding custom apt sources
* setting apt mirrors
* running arbitrary commands at boot
* setting up chef, puppet, salt-stack, or MCollective
* setting the locale and time zone
* resizing the root filesystem to take up all available space, making it
  easy to grow a snapshot
* set passwords
* configure ssh keys

For more information on cloud-init, refer to the `official
CloudInit documentation <https://help.ubuntu.com/community/CloudInit>`_.
