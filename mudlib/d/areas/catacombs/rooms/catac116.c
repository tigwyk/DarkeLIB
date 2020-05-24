/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The passageway bends slightly to the west as it runs north to south. 
   A three-way intersection lies to the southeast, while darkness lies 
   to the northeast.
      0  
     /   
    @
     \
      0  
ext);
   set_smell("default", "The air smells of smoke.");
   set_listen("default", "You hear moaning nearby.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "northeast": PATH+"catac153",
                "southeast": PATH+"catac117",
               ]) );
}
 
void reset() {
   ::reset();
   if(!present("gold skeleton"))
      new(MON_PATH+"goldskel")->move(this_object());
}
