# CSE20312FinalProject

ND RUNNING PATHFINDER
=====================

An application for finding paths of a desired distance between two points. Perfect for planning a run! Just add a map and run.

Dependencies
------------

* g++ 4.9+
* python2.7
* Google API Key (for accessing google maps)


Install
-------

Clone the repository:
~~~
git clone https://github.com/pfalvey/CSE20312FinalProject.git
~~~

Build with the provided Makefile
~~~
make
~~~



Usage
-----

~~~
map [start_point] [end_point] [path_length(optional)]
~~~
> start_point : The string key value of the building your path will originate from. All paths start here.
> end_point : The string key value that your path will end from.
> path_length : The desired length of the path in feet. The algorithm will attempt to find the path closest in length to this value. If not specified, it returns the shortest path



Uninstall
---------

Use clean to remove executables/objects
~~~
make clean
~~~

Remove folder
~~~
cd ..
rm -r <dirname>
~~~

