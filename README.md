mkgraph
=======

Test case generator for Travelling Salesperson 2D problem on Kattis (oldkattis:tsp).

Building
--------
Simply type `make` on a system with a recent version GCC.

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

    Usage: mkgraph -n npoints,mean_x,mean_y,dev_x,dev_y\n"
    
    Generates a normally distributed cluster of points where\n"
    
      npoints   is the number of points in the cluster,\n"
      mean_x    is the mean x value,\n"
      mean_y    is the mean y value,\n"
      dev_x     is the standard deviation in the x direction,\n"
      dev_y     is the standard deviation in the y direction.\n"
    
    The option may be repeated to create several clusters";

### Generating Uniformly Distributed Points (`-u`)

    Usage: mkgraph -u npoints,x,y,width,height\n"
    
    Generates a uniformly distributed cluster of points where\n"
    
      npoints   is the number of points in the cluster,\n"
      x,y       is the position of the area to contain the points,\n"
      width     is the width of the area to contain the points,\n"
      height    is the height of the area to contain the points.\n"
    
    The option may be repeated to create several clusters";

Example
-------
TODO
