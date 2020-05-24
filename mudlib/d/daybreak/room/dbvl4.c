#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbvl5", "east");
    add_exit(ROOMS+"dbvl3", "west");
//Basic mapping added by Tiny 1/19/2020
    set("short","   \n    \n0--@--0\n    \n   \n Victory Lane");
    set("long","Victory Lane runs north and east through Daybreak Ridge.\n   \n    \n0--@--0\n    \n   \n ");
}
