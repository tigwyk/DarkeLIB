#include "../newbieville.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "   0\n   | \n   @   \n     \n   p\nSouth Gates.");
    set("long",@ext These are the southern gates leading out from Newbieville. To the north is Common Street, which will take you to Town Square if you follow it.
    0
    |
    @
    |
    plains
ext);
    add_exit(ROOMS+"commonstreet", "north");
    add_exit("/d/damned/virtual/room_10_10.world", "plains");
}
