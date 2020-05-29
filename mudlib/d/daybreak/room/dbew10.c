#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbew9", "east");
    add_exit("/d/damned/virtual/room_8_9.world","mountains");
    add_exit(ROOMS+"dbvl1", "south");
//Basic mapping added by Tiny 1/19/2020
    set("short","   \n    \nM  @--0\n   | \n   0\nMain Street");
    set("long","Main Street runs east-west through Daybreak Ridge\n   \n    \nM  @--0\n   | \n   0\n");
}
