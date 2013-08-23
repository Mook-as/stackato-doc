.. _go-index:

.. index:: Go

Go
==

Go applications (`golang <http://golang.org/>`_) are supported through a BuildPack framework, and can be pushed to Stackato with a
basic setup.

Local Install
-------------

To build Go code, install it locally using one of the `Go packages <http://code.google.com/p/go/downloads/list>`_.


Deployment
----------

Here is a basic deployment setup based on the `"Hello World" Go sample application <https://github.com/Stackato-Apps/go-hello-buildpack>`_.

Files
^^^^^

You will need the following files to deploy a Go app on Stackato::

	app.go
	Procfile
	.godir
	stackato.yml
	
app.go
~~~~~~

The Go buildpack recognizes Go apps by the existence of a .go source file anywhere in the repository::

	package main
	
	import (
		"fmt"
		"log"
		"net/http"
		"os"
	)
	
	func main() {
		http.HandleFunc("/", hello)
		err := http.ListenAndServe(":"+os.Getenv("PORT"), nil)
		if err != nil {
			log.Fatal("ListenAndServe:", err)
		}
	}
	
	func hello(w http.ResponseWriter, req *http.Request) {
		fmt.Fprintln(w, "hello, world!")
	}

Procfile
~~~~~~~~

To run your web process, you need to declare what command to use. In this case, we simply need to 
execute our Go program. Use Procfile to declare how your web process type is run::

	web: server

.godir
~~~~~~

The ``go`` tool uses the directory name of your project to name executables and determine package 
import paths.  Cretate a file called .godir, in your project root, containing the path from 
*$GOPATH/src* to your project root::
	
	example.com/hello
	

stackato.yml
~~~~~~~~~~~~

This file is optional, as the framework will automatically be detected by Stackato.  However, it
can still be used to set the app name, configure settings, create services, etc.  
See the :ref:`stackato.yml docs<stackato_yml>`.

	name:
		hello-go

Examples
--------

* `"Hello World" Go sample application
  <https://github.com/Stackato-Apps/go-hello-buildpack>`_.
* `Getting Started with Go on Heroku
  <http://mmcgrana.github.com/2012/09/getting-started-with-go-on-heroku.html>`_.

