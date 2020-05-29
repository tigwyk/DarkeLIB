#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbcc5", "north");
    add_exit(ROOMS+"dbcc3","south");
    add_exit("/d/damned/guilds/join_rooms/enchanter_join", "east");
    add_exit(ROOMS+"dbcc9","west");
//Basic mapping added by Tiny 1/19/2020
    set("short","   0\n   | \n0--@--G\n   | \n   0\nCommerce Court");
    set("long","Commerce Court runs north and west through Daybreak Ridge.\n   0\n   | \n0--@--G\n   | \n   0\n");
}
