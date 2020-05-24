#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbns8","east");
    add_exit("/d/damned/guilds/thief/thief1","down");
    add_exit("/d/damned/guilds/join_rooms/dark-paladin_join.c","west");
    add_exit("/d/damned/guilds/join_rooms/assassin_join.c","north");
        //add_exit("/d/daybreak/room/ntf/ntfkitchen", "south");
    set("short","   G\n   |\nG--@--0\n   d\n   \nDaybreak Ridge Slums");
    set("long","   G\n   |\nG--@--0\n   d\n   \nDaybreak Ridge Slums");
}
