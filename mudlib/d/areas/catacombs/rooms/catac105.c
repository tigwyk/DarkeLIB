/* Room coded by Duridian for DarkeMud. */

 

#include "std.h"

inherit ROOM;

 

void create() {

   ::create();

   set_property("light", 1);

   set_property("indoors", 1);

   set("short", "Dark Dungeon");

   set("long",@ext
   This passageway of the catacombs bends as it runs north to south, 
   curving to the east.  There is a faint light coming from the 
   northwest.
  0    
   \   
    @--0
   /
  0    
ext);

   set_smell("default", "The air smells of spoiled food.");

   set_listen("default", "You hear moaning nearby.");

   set_items( ([

                ({"walls", "wall", "floor", "dust"}):

        "The walls and floor are covered in a thin layer of dust.",

                ({"torches", "small torches"}):

        "The small torches that are affixed to the wall provide very little light.",

                ]) );

   set_exits( ([

                "northwest": PATH+"catac104",

                "southwest": PATH+"catac120",

                "east": PATH+"catac106",

                ]) );

}

 

