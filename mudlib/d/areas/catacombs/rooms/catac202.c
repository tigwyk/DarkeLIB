/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   From this point, the passageway branches in three directions.  A 
   long, dark corridor runs to the east, while the northern one seems 
   to bend to the west.  The passageway to the southwest is narrow and 
   very dark.  Torches provide only a small amount of light.
    0   
    |   
    @--0
   /
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
                "southwest": PATH+"catac201",
                "north": PATH+"catac207",
                "east": PATH+"catac203",
                ]) );
}
