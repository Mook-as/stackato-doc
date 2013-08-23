.. index:: Persistent File System
.. _persistent-file-system:

Persistent File System
----------------------
The file system of application containers are ephemeral. Any application data or files stored 
locally within these containers is lost when the instance is stopped or restarted. To solve this, 
Stackato provides a ‘filesystem’ service that can be shared between application instances, and even 
between applications deployed by the same user or group.

A persistent file system service allows apps to do the following:

#. Share files across multiple instances of an app
#. Store files that persist if an app is removed (providing the service is not deleted) or if the server is restarted.
#. Conserve space on filesystems allocated within the VM instance by referencing the persistent filesystem instead.

.. _file-system-create:

Creating A Persistent File System
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

A ``filesystem`` service can be configured in your *stackato.yml* file::

    services:
        mydata: filesystem

You can also use the ``stackato create-service`` command::

    $ stackato create-service filesystem mydata
	Creating Service: OK
	
	$ stackato services

	=========== Provisioned Services ============
	
	+----------------+------------+
	| Name           | Service    |
	+----------------+------------+
	| mydata         | filesystem |
	+----------------+------------+

.. _file-system-usage:

Using A Persistent File System
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. note:: 
    File system service is available during pre-staging and shouldn't 
    need to be reconfigured when the application starts.
    
The filesystem service creates a path which your app can use to store and read files.

If there is only one filesystem service, the ``STACKATO_FILESYSTEM`` environment variable can
be used to get the path.

If there is more than one ``filesystem`` service, ``STACKATO_FILESYSTEM`` is not available. 
Instead, a custom environment variable ``STACKATO_FILESYSTEM_*`` will be created based on the
name of each filesystem service (with hyphens replaced by underscores).

For example, if your *stackato.yml* file configures the following services::

    services:
        my-data: filesystem
        plugins: filesystem

Two environment variables would be created:
``STACKATO_FILESYSTEM_MY_DATA`` and ``STACKATO_FILESYSTEM_PLUGINS``.

This naming scheme can be used in conjunction with the
``STACKATO_APP_NAME_UPCASE`` environment variable. For example, in an
app with the following filesystem service defined::

    services:
      ${name}-foo: filesystem
      ${name}-bar: filesystem

The filesystem mount point for the "foo" filesystem service can be
accessed within the container using constructs such as::

    FOO=STACKATO_FILESYSTEM_${STACKATO_APP_NAME_UPCASE}_FOO
    mkdir ${!FOO}/myapp

.. note::
  To use declarations like these in :ref:`hooks <stackato_yml-hooks>`,
  put them in a separate bash script. Brace expansion and grouping
  cannot be used directly in YAML files.

Alternatively, ``STACKATO_SERVICES`` contains information for all services::

    {
        "plugins": {
            "dir": "/app/fs/plugins"
		},
		"my-data": {
			"dir": "/app/fs/my-data"
		},
		"mydb": {
			"name": "db76e25bc8fc142858653a6cb8c643204",
			"hostname": "192.168.0.112",
			"host": "192.168.0.112",
			"port": 3306,
			"user": "u7Fjl8hdb4iNu",
			"username": "u7Fjl8hdb4iNu",
			"password": "p4XQAhZr8xfHg"
		}
	}

Since the :ref:`environment variables <environment-variables>` are available during the staging 
process, it is possible to make use of them in the :ref:`stackato.yml <stackato_yml>` file to 
configure a filesystem service and create a symlink to it for use by the app. (see example below)

.. _file-system-example:

Example of Using A Persistent File System
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. note::
    When linking the file system service to the application, using symlinks is strongly recommended.

We will go through how we customized our WordPress installation to use the persistent file system. 
Before you begin, find out where all the user generated contents are saved. You may have to make 
modifications to this general approach if your application stores user generated content in more 
than one location. In WordPress, they are stored in wp-content folder. 

We need to add the following to our stackato.yml::

    services:
        fs-wp: filesystem
    hooks: 
        post-staging:
        # create wp-content in the shared filesystem
        - mkdir -p "$STACKATO_FILESYSTEM"/wp-content
        
        # migrate existing wp-content data into the shared filesystem
        - mv wp-content/* "$STACKATO_FILESYSTEM"/wp-content
        
        # remove unused wp-content directories
        - rm -rf wp-content
        
        # link to wp-content folder in the shared filesystem
        - ln -s "$STACKATO_FILESYSTEM"/wp-content wp-content

.. note::
    When moving files onto the mounted filesystem with a ``mv`` hook,
    you may see an error message similar to::
    
        mv: failed to preserve ownership for... Permission denied
      
    This is a misleading warning, as the files will actually be moved
    with the correct permissions and ownership.


