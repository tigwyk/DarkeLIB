
#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbcc6", "east");
    add_exit(ROOMS+"dbcc8","south");
    add_exit("/d/damned/guilds/join_rooms/tinker_join", "west");
//Basic mapping added by Tiny 1/19/2020
    set("short","   \n    \nG--@--0\n   | \n   0\nCommerce Court");
    set("long","Commerce Court runs east and south through Daybreak Ridge.\n   \n    \nG--@--0\n   | \n   0\n");
}
