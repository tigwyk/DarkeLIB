/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 0);
   set("short", "Dark Dungeon");
   set("long",@ext
   This narrow corridor runs north from the entrance to the level.  It 
   widens slightly as it continues to the northeast.  There are no 
   torches here, and the passageway is very dark.
      0  
     /   
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
        "There are no torches in this passageway.",
                ]) );
   set_exits( ([
                "south": PATH+"catac200",
                "northeast": PATH+"catac202",
                ]) );
}
 
void reset() {
   ::reset();
   if(!present("gold skeleton"))
      new(MON_PATH+"goldskel")->move(this_object());
   }
 
