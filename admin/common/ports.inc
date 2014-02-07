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
  5678      tcp   DEA directory server
  9001      tcp   supervisord
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
which ports are used by which components. **Source** nodes initiate the
communication, **Destination** nodes need to listen on the specified port.

  =============  ====  ==============  ================  ===================
  Port Range     Type  Source          Destination       Required by
  =============  ====  ==============  ================  ===================
  22             tcp   all nodes       all nodes         ssh/scp/sshfs
  4222           tcp   all nodes       controller        :term:`NATS`
  3306           tcp   dea,controller  mysql nodes       MySQL
  5432           tcp   dea,controller  postgresql nodes  PostgreSQL
  5454           tcp   all nodes       controller        redis
  6464           tcp   all nodes       all nodes         applog (redis)
  7000 - 7999    tcp   all nodes       all nodes         ``kato log tail``
  7474           tcp   all nodes       all nodes         config (redis)
  9001           tcp   controller      all nodes         :term:`supervisord`
  9022           tcp   dea             controller        droplets
  9022           tcp   controller      dea               droplets
  9025           tcp   controller      router            stackato-rest
  9026           tcp   controller      all nodes         stackato-rest
  41000 - 61000  tcp   dea,controller  service nodes     service gateways
  =============  ====  ==============  ================  ===================

Each node can be internally firewalled using `iptables
<http://manpages.ubuntu.com/manpages/man8/iptables.8.html>`_ to apply
the above rules.

Comments:

* Ports 80 and 443 need only be open to the world on router nodes.

* Port 4222 should be open on all nodes for :term:`NATS` communication
  with the MBUS IP (core Cloud Controller)

* Port 9022 should be open to allow transfer of droplets to and
  from the DEAs, and Cloud Controllers.

* Port 7845 is required if you plan to stream logs from all nodes
  in a cluster using ``kato log tail`` command.

* External access on port 22 can be restricted if necessary to the
  subnet you expect to connect from. If you are providing the ``stackato
  ssh`` feature to your users (recommended), define a distinct security
  group for the public-facing Cloud Controller node that is the same as
  a generic Stackato group, but has the additional policy of allowing
  SSH (Port 22) from hosts external to the cluster.

* Within the cluster, port 22 should be open on all hosts to allow
  administrative access over SSH. Port 22 is also used to mount
  Filesystem service partitions in application containers on the DEA
  nodes (via SSHFS).
  
* The optional Harbor port service has a configurable port range
  (default 41000 - 61000) which can be exposed externally if required.
  
