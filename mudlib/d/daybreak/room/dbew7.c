#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbew6", "east");
    add_exit(ROOMS+"dbew8","west");
    add_exit(ROOMS+"dbbw1","north");
//Basic mapping added by Tiny 1/19/2020
    set("short","   0\n   | \n0--@--0\n    \n   0\nMain Street");
    set("long","Main Street runs east-west through Daybreak Ridge.\n   0\n   | \n0--@--0\n    \n   \n");
}
