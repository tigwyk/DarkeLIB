/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The passageway widens slightly as it runs from the west and northeast 
   from this point.  A few torches affixed to the wall provide very 
   little light in this corridor.
      0  
     /   
 0--@   
ext);
   set_smell("default", "The air smells of dust.");
   set_listen("default", "There is not a sound.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "west": PATH+"catac114",
                "northeast": PATH+"catac112",
                ]) );
}
 
void reset() {
   ::reset();
   if(!present("mithril skeleton"))
      new(MON_PATH+"mithskel")->move(this_object());
}
