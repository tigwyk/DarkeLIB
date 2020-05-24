/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 2);
   set("short", "Dark Dungeon");
   set("long",@ext
   The corridor bends to the east here as it continues to the south.  
   The passageway continues into relative darkness to the northwest, 
   while the light to south is quite bright.  From this point in the 
   passageway you are able to spy a large piece of glass in the room 
   to the south.
  0    
   \   
    @
    |
    0   
ext);
   set_smell("default", "The air is very dry.");
   set_listen("default", "You hear evil laughter to the north.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "northwest": PATH+"catac204",
                "south": PATH+"catac206",
                ]) );
}
