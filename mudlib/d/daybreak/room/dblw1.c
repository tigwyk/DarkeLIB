#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbew2", "north");
    add_exit(ROOMS+"dblw2","south");
//Basic mapping added by Tiny 1/19/2020
    set("short","   0\n   | \n   @   \n   | \n   0\nLuminous Way");
    set("long","Luminous Way runs north-south through Daybreak Ridge.\n   0\n   | \n   @   \n   | \n   0\n");
}
