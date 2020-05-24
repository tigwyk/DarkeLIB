#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbvl5", "west");
    add_exit(ROOMS+"shop/weaponsmith", "east");
//Basic mapping added by Tiny 1/19/2020
    set("short","   \n    \n0--@--S\n    \n   \nVictory Lane");
    set("long","Victory Lane runs west through Daybreak Ridge\n   \n    \n0--@--S\n    \n   \n");
}
