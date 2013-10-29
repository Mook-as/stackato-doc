.. _docker:

Docker & Fence
==============

Stackato's :ref:`DEA role <architecture-dea>` runs Linux containers to
isolate user applications during staging and at runtime. Management of
these application containers is handled by the ``fence`` process, which
in turn uses `Docker <http://docs.docker.io/en/latest/>`__ to create and
destroy Linux containers on demand.

Typically, admins will not have to work directly Docker, but it is
available if needed to customize or create new container images.


.. _docker-modify-container:

.. index:: Modifying the Container Image
.. index:: Updating the Conatiner Image

Modifying or Updating the Container Image
-----------------------------------------

Application containers are created from a base Docker image (a template
used to create Linux containers). Admins can create new images to add
specific software required by applications or update operating system
packages.

To create a new base image for Stackato to use for application
containers, perform the following steps on all nodes running the DEA
role:

1. Start with an empty working directory::

    $ mkdir ~/newimg
    $ cd ~/newimg

2. Check which image Stackato is currently using as an app container
   template::
  
    $ kato config get fence docker/image
    stackato/app-holophonor:3.0.0
  
3. Create a `Dockerfile <http://docs.docker.io/en/latest/use/builder/>`_
   which inherits the current Docker image, then runs an update or
   installation command. For example::

    FROM stackato/app-holophonor:3.0.0
    RUN apt-get -y install libgraphite2-dev
    CMD ["start.sh"]

   The ``FROM`` instruction inherits the environment and installed
   software from Stackato's app image. The ``RUN`` instruction specifies
   arbitrary commands to run before saving the image.
   
4. Build the image, setting the maintainer's name, an image name, and a
   version number (optional, but recommended)::

    $ sudo docker build -t exampleco/newimg:1.0.0
  
   The version number at the end of the image name is 

5. Configure Stackato to use the new image::

    $ kato config set fence docker/image exampleco/newimg:1.0.0
    WARNING: Assumed type string
    exampleco/newimg:1.0.0

.. note::

  This step only needs to be done once, as the configuration change is
  shared with all nodes.
  
6. Restart the ``fence`` process::
  
    $ kato process restart fence


.. _docker-registry:

.. index:: Docker Registry

Creating a Docker Registry
--------------------------

The steps above will work with smaller clusters or micro clouds where
the creation of Docker images on each DEA can be done manually. On
larger clusters, you should set up a `Docker registry
<http://blog.docker.io/2013/07/how-to-use-your-own-registry/>`__ as a
central registry for your container tempates.

1. On the Core node of your cluster, pull the `docker-registry
   <https://index.docker.io/u/samalba/docker-registry/>` image from
   the Docker index::

    $ sudo docker pull samalba/docker-registry
    
2. Start the server::

    $ sudo docker run -d samalba/docker-registry
    dbcd0cd9e218
   
   This will return the ID of the running registry server image (also
   available via ``docker ps``).

3. Use the ID to get the public facing port for the running image. For example::

    $ sudo docker port dbcd0cd9e218 5000
    49153

   Your registry location is a combination of the API endpoint of your
   cluster (i.e. ``kato config get cluster endpoint``) combined with the
   port number returned by the command above. For example::
    
    api.paas.example.com:49153
    
   This registry location will be used to pull the images you create
   to your DEA nodes.
    
4. Go through steps 1 - 3 :ref:`above <docker-modify-container>` to
   create a Docker image file. When building the image, substitute the
   registry location for the organization name used in step 4. For
   example::
   
    $ sudo docker build -t api.paas.example.com:49153/newimg:1.0.0
   
5. Push the newly built Docker image to the registry::

    $ sudo docker push api.paas.example.com:49153/newimg:1.0.0
    
6. **On all DEA nodes**, pull the new image from the registry::

    $ sudo docker pull api.paas.example.com:49153/newimg:1.0.0

7. Configure Stackato to use the new image::

    $ kato config set fence docker/image api.paas.example.com:49153/newimg:1.0.0
    WARNING: Assumed type string
    api.paas.example.com:49153/newimg:1.0.0

.. note::

  This step only needs to be done once, as the configuration change is
  shared with all nodes.
  
8. Restart the ``fence`` process **on each DEA**::
  
    $ kato process restart fence
    

