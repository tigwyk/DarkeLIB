#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbcc3", "north");
    add_exit(ROOMS+"dbcc1","south");
    add_exit(ROOMS+"shop/chest","east");
    add_exit("/d/damned/akkad/castle_shop", "west");
//Basic mapping added by Tiny 1/19/2020
    set("short","   0\n   | \nS--@--S\n   | \n   0\nCommerce Court");
    set("long","Commerce Court runs north-south through Daybreak Ridge.\n   0\n   | \nS--@--S\n   | \n   0\n");
}
