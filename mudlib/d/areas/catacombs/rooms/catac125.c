/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The ceiling slopes upward as the corridor runs to the southeast.  
   In that direction there seems to lie a fairly large chamber, with 
   stalactites hanging down from the chamber's ceiling.  The passageway 
   forks as it heads to the northwest.
  0 0   
   \|   
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
                "northwest": PATH+"catac126",
                "north": PATH+"catac143",
                "southeast": PATH+"catac114",
                ]) );
}
 
void reset() {
   ::reset();
   if(!present("shaggy zombie"))
      new(MON_PATH+"shagzomb")->move(this_object());
}
 
