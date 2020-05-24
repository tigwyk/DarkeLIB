#include "../newbieville.h"
#include "/adm/include/std.h"

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "   \n    \np   @--0\n    \n   \nWest Gates.");
    set("long",@ext These are the western gates leading out from Newbieville. To the east is Shadow Road, which will take you to Town Square if you follow it.

plains--@--0


ext);
    add_exit(ROOMS+"shadowroad", "east");
    add_exit("/d/damned/virtual/room_10_10.world", "plains");
}
