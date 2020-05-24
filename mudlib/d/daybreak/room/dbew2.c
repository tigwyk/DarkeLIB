#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbew1", "east");
    add_exit(ROOMS+"dbew3","west");
    add_exit(ROOMS+"dbcc1", "north");
    add_exit(ROOMS+"dblw1","south");
//Basic mapping added by Tiny 1/19/2020
    set("short","   0\n   | \n0--@--0\n   | \n   0\nMain Street");
    set("long","Main Street runs east-west through Daybreak Ridge.  Commerce court runs in a northerly direction from here, Luminous Way runs in a southerly direction from here.\n   0\n   | \n0--@--0\n   | \n   0\n  ");
}
