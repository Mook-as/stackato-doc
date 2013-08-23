    Options:
    
      **-c**, **--cluster** - Operate on the entire cluster
      
      **-o**, --only-this-node** - Only affect this node
      
      **-m**, **--manual** - Only import/export those roles specified on the command line
      
      **-f**, **--force** - Force import/export of specified roles even if they are not enabled (only works with --manual, implies --only-this-node)
 
    Configurable exportables/importables:
    
      **--droplets** - Include droplets (uploaded apps)
      
      **--exclude-droplets** - Don't include droplets (uploaded apps)
  
      **--resources** - Include the upload cache
      
      **--exclude-resources** - Don't include the upload cache
  
      **--license** - Include the Stackato license
      
      **--exclude-license** - Don't include the Stackato license
      
      **--admins-list** - Include the list of users that are admins
      
      **--exclude-admins-list** - Don't include the list of users that are admins
      
      **--main-db** - Include the primary node's main database
      
      **--exclude-main-db** - Don't include the primary node's main database
      
      **--filesystem** - Include the filesystem service
      
      **--exclude-filesystem** - Don't include the filesystem service
      
      **--exclude-filesystem-data** - Don't include the filesystem service's user data
      
      **--exclude-filesystem-user-creation** - Don't include the filesystem service's user creation/quota
      
      **--mysql** - Include the MySQL service
      
      **--exclude-mysql** - Don't include the MySQL service
      
      **--exclude-mysql-data** - Don't include the MySQL service's data
      
      **--exclude-mysql-metadata** - Don't include the MySQL service's metadata
      
      **--postgresql** - Include the PostgreSQL service
      
      **--exclude-postgresql** - Don't include the PostgreSQL service
      
      **--exclude-postgresql-data** - Don't include the PostgreSQL service's data
      
      **--exclude-postgresql-metadata** - Don't include the PostgreSQL service's metadata
      
      **--mongodb** - Include the MongoDB service
      
      **--exclude-mongodb** - Don't include the MongoDB service
      
      **--exclude-mongodb-data** - Don't include the MongoDB service's data
      
      **--exclude-mongodb-metadata** - Don't include the MongoDB service's metadata
      
      **--memcached** - Include the memcached service
      
      **--exclude-memcached** - Don't include the memcached service
      
      **--exclude-memcached-data** - Don't include the memcached service's data
      
      **--exclude-memcached-metadata** - Don't include the memcached service's metadata
      
      **--redis** - Include the Redis service
      
      **--exclude-redis** - Don't include the Redis service
      
      **--exclude-redis-data** - Don't include the Redis service's data
      
      **--exclude-redis-metadata** - Don't include the Redis service's metadata
      
      **--rabbit** - Include the RabbitMQ service
      
      **--exclude-rabbit** - Don't include the RabbitMQ service
      
      **--exclude-rabbit-data** - Don't include the RabbitMQ service's data
      
      **--exclude-rabbit-metadata** - Don't include the RabbitMQ service's metadata
