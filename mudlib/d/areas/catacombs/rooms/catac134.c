/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The passageway narrows here, forcing you to walk sideways in order to
   pass through the area.  To both the northeast and west the corridor
   widens and winds into other passageways of the catacombs.
      0  
     /   
 0--@
ext);
   set_smell("default", "The air smells of smoke.");
   set_listen("default", "You hear light scratching.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "northeast": PATH+"catac133",
                "west": PATH+"catac135",
                ]) );
}
 
void reset() {
   ::reset();
   if(!present("shaggy zombie"))
      new(MON_PATH+"shagzomb")->move(this_object());
}
 
