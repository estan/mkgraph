#ifndef HELP_H
#define HELP_H

#include <string>

const std::string generalHelp =
    "Usage: mkgraph [ -h | -hn | -hu ] [ [ -n <spec> | -u <spec> ] ... ]\n"
    "  -h           Print general help.\n"
    "  -hn          Print help for the -n option.\n"
    "  -hu          Print help for the -u option.\n"
    "  -n <spec>    Generate normally distributed cluster of points.\n"
    "               Use -hn for information about format of <spec>.\n"
    "  -u <spec>    Generate uniformly distributed cluster of points.\n"
    "               Use -hu for information about format of <spec>.\n"
    "The -n and -u options may be repeated to create several clusters.\n"
    "If no options are given, the default is -n 1000,0,0,200000,200000.";

const std::string normalHelp =
    "Usage: mkgraph -n npoints,mean_x,mean_y,dev_x,dev_y\n"
    "\n"
    "Generates a normally distributed cluster of points where\n"
    "\n"
    "  npoints   is the number of points in the cluster,\n"
    "  mean_x    is the mean x value,\n"
    "  mean_y    is the mean y value,\n"
    "  dev_x     is the standard deviation in the x direction,\n"
    "  dev_y     is the standard deviation in the y direction.\n"
    "\n"
    "The option may be repeated to create several clusters";

const std::string uniformHelp =
    "Usage: mkgraph -u npoints,x,y,width,height\n"
    "\n"
    "Generates a uniformly distributed cluster of points where\n"
    "\n"
    "  npoints   is the number of points in the cluster,\n"
    "  x,y       is the position of the area to contain the points,\n"
    "  width     is the width of the area to contain the points,\n"
    "  height    is the height of the area to contain the points.\n"
    "\n"
    "The option may be repeated to create several clusters";

#endif // HELP_H

