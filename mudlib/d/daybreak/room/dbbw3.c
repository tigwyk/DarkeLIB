#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbbw2","east");
    add_exit("/d/damned/guilds/join_rooms/war-priest_join.c","north");
    add_exit("/d/damned/guilds/join_rooms/paladin_join.c","south");
    //add_exit("/d/damned/guilds/join_rooms/dark-paladin_join.c","west");
//Basic mapping added by Tiny 1/19/2020
    set("short","   G\n   | \n   @--0\n   | \n   G\nBlessing Way");
    set("long","Blessing Way runs east through Daybreak Ridge\n   G\n   | \n   @--0\n   | \n   G\n");
}
