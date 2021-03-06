/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The narrow corridor bends to the west here slightly.  Darkness lies to 
   the northeast and southeast, but you hear sounds of movement in both 
   directions.
      0  
     /   
    @
     \
      0  
ext);
   set_smell("default", "The air is very dry.");
   set_listen("default", "You hear evil laughter to the west.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "northeast": PATH+"catac210",
                "southeast": PATH+"catac212",
                ]) );
}
