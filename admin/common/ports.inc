.. comment - Network Port Configuration

The Stackato :term:`micro cloud` runs with the following ports exposed:

  ========  ====  =======================
  Port      Type  Service
  ========  ====  =======================
  22        tcp   ssh
  25        tcp   smtp
  80        tcp   http
  111       tcp   portmapper
  111       udp   portmapper
  443       tcp   https
  3306      tcp   mysql
  5432      tcp   postgresql
  9001      tcp   supervisord
  9025      tcp   stackato-rest
  9026      tcp   stackato-rest
  12345     tcp   netbus
  ========  ====  =======================

On a production cluster, or a micro cloud running on a cloud hosting
provider, only ports 22 (SSH), 80 (HTTPS) and 443 (HTTPS) need to be
exposed externally (e.g. for the Router / Core node). 

Within the cluster (i.e. behind the firewall), it is advisable to allow
communication between the cluster nodes on all ports. This can be done
safely by using the security group / security policy tools provided by
your hypervisor:

* :ref:`EC2 Security Group Settings <server-vm-ec2-firewall>`
* :ref:`HP Cloud ServicesSecurity Group Settings <server-vm-hpcs-firewall>`

If you wish to restrict ports between some nodes (e.g. if you do not
have the option to use security groups), the following summary describes
which ports are used by which components:

  ==================        ====  ===========   ============= ================
  Port Range                Type  Destination   Source        Required by
  ==================        ====  ===========   ============= ================
  0 - 65535 (all)           tcp   dea           controller    ``stackato ssh``
  4222                      tcp   controller    all nodes     :term:`NATS`
  5454                      tcp   controller    all nodes     redis
  7000 - 7999               tcp   all nodes     all nodes     ``kato log tail``
  8046                      tcp   controller    all nodes     :term:`doozerd`
  9001                      tcp   all nodes     controller    :term:`supervisord`
  9022                      tcp   controller    dea           droplets
  9022                      tcp   dea           controller    droplets
  9025                      tcp   router        controller    stackato-rest
  9026                      tcp   all nodes     controller    stackato-rest
  32768 - 61000             tcp   service nodes controller    service gateways
  ==================        ====  ============= ============= ================


If you subscribe to the principle of "defense in depth", each node can
also be internally firewalled using
`iptables <http://manpages.ubuntu.com/manpages/man8/iptables.8.html>`_
to apply the above rules.

Comments:

* Port 22 can be restricted if necessary to the subnet you expect to connect from.

* Ports 80 and 443 need only be open to the world on router nodes.

* Port 4222 should be open for :term:`NATS`, and port 9022 should also be open to allow transfer
  of droplets to and from the Cloud Controller.

* Port 7845 is only required if you plan to stream logs from all nodes in a cluster using ``kato log tail`` command.

* The DEA nodes are a special case where ``stackato ssh`` functionality requires the DEA to
  allow the Cloud Controller on all ports.

* If you are providing the ``stackato ssh`` feature to your users, you might find it useful to
  define a distinct security group for the public-facing Cloud Controller node that is the same
  as a generic Stackato group, but has the additional policy of allowing SSH (Port 22) from
  hosts external to the cluster.

