[![Build Status](https://travis-ci.org/estan/mkgraph.svg?branch=master)](https://travis-ci.org/estan/mkgraph)

mkgraph
=======

Test case generator for Travelling Salesperson 2D problem on Kattis (oldkattis:tsp).

Building
--------
Simply type `make` on a system with a recent version of GCC.

Documentation
-------------

The program will output the number of points followed by an "x y" pair for each generated point.

### General Usage
    Usage: mkgraph [ -h | -hn | -hu ] [ [ -n <spec> | -u <spec> ] ... ]
      -h           Print general help.
      -hn          Print help for the -n option.
      -hu          Print help for the -u option.
      -n <spec>    Generate normally distributed cluster of points.
                   Use -hn for information about format of <spec>.
      -u <spec>    Generate uniformly distributed cluster of points.
                   Use -hu for information about format of <spec>.
    The -n and -u options may be repeated to create several clusters.
    If no options are given, the default is -n 1000,0,0,200000,200000.

### Generating Normally Distributed Points (`-n`)

    Usage: mkgraph -n npoints,mean_x,mean_y,dev_x,dev_y
    
    Generates a normally distributed cluster of points where
    
      npoints   is the number of points in the cluster,
      mean_x    is the mean x value,
      mean_y    is the mean y value,
      dev_x     is the standard deviation in the x direction,
      dev_y     is the standard deviation in the y direction.
    
    The option may be repeated to create several clusters

### Generating Uniformly Distributed Points (`-u`)

    Usage: mkgraph -u npoints,x,y,width,height
    
    Generates a uniformly distributed cluster of points where
    
      npoints   is the number of points in the cluster,
      x,y       is the top left position of the area to contain the points,
      width     is the width of the area to contain the points,
      height    is the height of the area to contain the points.
    
    The option may be repeated to create several clusters

Example
-------
As a small example, lets generate 20 points normally distributed around `(5, 5)` with standard deviation 1 in both directions, and 10 points uniformly distributed over a `10 x 10` area starting at `(0, 0)`:

    $ ./mkgraph -n 20,5,5,1,1 -u 10,0,0,10,10
    30
    3.5010 4.7409
    5.1748 6.6016
    5.4582 5.1193
    5.1890 4.6980
    5.0442 5.3950
    4.3355 2.6302
    6.7313 4.3637
    4.2351 4.8288
    5.0937 5.7032
    6.2041 5.1454
    6.6814 5.2610
    4.2980 4.3080
    4.1369 5.1752
    6.1862 5.2742
    5.9426 6.3165
    5.8284 5.6810
    5.8605 4.4103
    5.2944 5.2091
    4.8683 4.5331
    6.5766 3.3312
    2.7491 2.3777
    1.6651 3.5926
    8.9766 4.8652
    0.6056 9.0921
    5.0452 9.0465
    3.1903 5.1629
    4.9398 9.8664
    0.9073 2.6614
    0.7375 9.4776
    3.8414 5.0071
