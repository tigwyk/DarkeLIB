#include "../newbieville.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "   \n    \n0--@  p\n    \n   \nEast Gates.");
    set("long",@ext These are the eastern gates leading out from Newbieville. To the west is Light Way, which will take you to Town Square if you follow it.

 0--@--plains

ext);
    add_exit(ROOMS+"lightway", "west");
    add_exit("/d/damned/virtual/room_10_10.world", "plains");
}
