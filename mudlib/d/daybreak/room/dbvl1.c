#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbew10", "north");
    add_exit(ROOMS+"dbvl2", "south");
//Basic mapping added by Tiny 1/19/2020
    set("short","   0\n   | \n   @   \n   | \n   0\nVictory Lane");
    set("long","Victory Lane runs north-south through Daybreak Ridge.\n   0\n   | \n   @   \n   | \n   0\n");
}
