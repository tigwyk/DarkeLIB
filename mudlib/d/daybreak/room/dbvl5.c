#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbvl6", "east");
    add_exit(ROOMS+"dbvl4", "west");
    add_exit("/d/damned/guilds/join_rooms/chaotic-lord_join", "north");
//Basic mapping added by Tiny 1/19/2020
    set("short","   G\n   | \n0--@--0\n    \n   \nVictory Lane");
    set("long","Victory Lane runs north and east through Daybreak Ridge\n   G\n   | \n0--@--0\n    \n   \n");
}
