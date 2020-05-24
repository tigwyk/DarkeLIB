#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dblw3", "north");
    add_exit(ROOMS+"dblw5","west");
    add_exit(ROOMS+"shop/magic","south");
//Basic mapping added by Tiny 1/19/2020
    set("short","   0\n   | \n0--@   \n   | \n   S\nLuminous Way");
    set("long","Luminous Way runs north and west through Daybreak Ridge.\n   0\n   | \n0--@   \n   | \n   S\n");
}
