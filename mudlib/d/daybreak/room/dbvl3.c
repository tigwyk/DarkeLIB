#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbvl2", "north");
    add_exit(ROOMS+"dbvl4", "east");
    add_exit("/d/damned/guilds/join_rooms/elementalist_join", "west");
        add_exit("/d/damned/guilds/join_rooms/elemental-mage_join", "south");
//Basic mapping added by Tiny 1/19/2020
    set("short","   0\n   | \nG--@--0\n   |\n   G\nVictory Lane");
    set("long","Victory Lane runs north and east through Daybreak Ridge.\n   0\n   | \nG--@--0\n   |\n   G\n");
}
