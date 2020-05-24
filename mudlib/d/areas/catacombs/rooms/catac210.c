/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 2);
   set("short", "Dark Dungeon");
   set("long",@ext
   This small chamber is lit by several small torches affixed to the 
   northernmost wall.  A few skulls lay scattered about, as if some 
   creature had made a meal of some unlucky adventurers.  The only 
   apparent exit is to the southwest.
   
    @
   /
  0    
ext);
   set_smell("default", "The air is very dry.");
   set_listen("default", "You hear evil laughter to the west.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ({"skull", "skulls"}):
        "The small humanoid skulls lay scattered about on the floor of the chamber.",
                ]) );
   set_exits( ([
                "southwest": PATH+"catac211",
                ]) );
}
 
void reset() {
   if(!present("silver skeleton"))
      new(MON_PATH+"silvskel")->move(this_object());
}
