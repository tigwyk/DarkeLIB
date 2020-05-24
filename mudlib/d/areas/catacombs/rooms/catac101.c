/* Room coded by Duridian for DarkeMud. */

 

#include "std.h"

inherit ROOM;

 

void create() {

   ::create();

   set_property("light", 1);

   set_property("indoors", 1);

   set("short", "Dark Dungeon");

   set("long",@ext
   This small chamber of the catacombs has a high ceiling that echos your 
   footsteps quite loudly.  There is faint light to the south while 
   the passageway continues to the northeast.
      0  
     /   
    @
    |
    0   
ext);

   set_smell("default", "The air smells of smoke.");

   set_listen("default", "You hear only your heart beating.");

   set_items( ([

                ({"walls", "wall", "floor", "dust"}):

        "The walls and floor are covered in a thin layer of dust.",

                ({"torches", "small torches"}):

        "The small torches that are affixed to the wall provide very little light.",

                ]) );

   set_exits( ([

                "northeast": PATH+"catac151",

                "south": PATH+"catac100",

                ]) );

}

