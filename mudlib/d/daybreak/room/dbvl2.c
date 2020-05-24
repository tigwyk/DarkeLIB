#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbvl1", "north");
    add_exit(ROOMS+"dbvl3", "south");
    add_exit(ROOMS+"shop/tavern", "east");
    add_exit("/d/damned/guilds/join_rooms/fighter_join", "west");
    set("short","   0\n   | \nG--@--S\n   | \n   0\nVictory Lane");
    set("long","Victory Lane runs north-south through Daybreak Ridge.\n   0\n   | \nG--@--S\n   | \n   0\n");
}
