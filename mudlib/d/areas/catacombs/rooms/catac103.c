/* Room coded by Duridian for DarkeMud. */

 

#include "std.h"

inherit ROOM;

 

void create() {

   ::create();

   set_property("light", 1);

   set_property("indoors", 1);

   set("short", "Dark Dungeon");

   set("long",@ext
   The passageway divides here and runs off in three directions: to the 
   west, to the northeast, and to the southeast.  Heading west will take 
   you back to the entrance to this level while heading in either of the 
   other two directions will take you farther into the catacombs.
      0  
     /   
 0--@
     \
      0  
ext);

   set_smell("default", "The air smells of smoke.");

   set_items( ([

                ({"walls", "wall", "floor", "dust"}):

        "The walls and floor are covered in a thin layer of dust.",

                ({"torches", "small torches"}):

        "The small torches that are affixed to the wall provide very little light.",

                ]) );

   set_exits( ([

                "west": PATH+"catac100",

                "northeast": PATH+"catac109",

                "southeast": PATH+"catac150",

                ]) );

}

