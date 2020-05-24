#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"db_square", "east");
    add_exit(ROOMS+"dbew7","west");
//Basic mapping added by Tiny 1/19/2020 
    set("short","\n    \n0--@--T\n    \n   \nMain Street");
    set("long","Main Street runs east-west through Daybreak Ridge.\n\n    \n0--@--T\n    \n   \n");
}
