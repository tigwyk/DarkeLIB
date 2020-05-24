#include "../newbieville.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "   p\n     \n   @   \n   | \n   0\nNorth Gates.");
    set("long", @ext These are the northern gates leading out from Newbieville. To the south is Majesty Avenue, which will take you to Town Square if you follow it.

    plains
    |
    @
    |
    0
ext);
    add_exit(ROOMS+"majestyave", "south");
    add_exit("/d/damned/virtual/room_10_10.world", "plains");
}
