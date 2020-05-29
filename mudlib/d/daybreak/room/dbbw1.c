#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/guilds/cleric/confess", "east");
    add_exit(ROOMS+"dbbw2","west");
    add_exit("/d/standard/square","north");
    add_exit(ROOMS+"dbew7","south");
    set("short","   C\n   | \n0--@--0\n   | \n   0\nBlessing Way");
    set("long","Blessing Way runs east-west through Daybreak Ridge\n   C\n   | \n0--@--0\n   | \n   0\n");
}
