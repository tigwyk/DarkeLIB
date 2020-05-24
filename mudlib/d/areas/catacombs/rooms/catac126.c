/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The passageway bends to the west slightly as it heads north, away 
   from the main part of the catacombs on this level.  The ceiling 
   is quite high and slopes down slightly as the corridor heads to 
   the north.
    0   
    |   
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
                "north": PATH+"catac127",
                "southeast": PATH+"catac125",
                ]) );
}
 
void reset() {
   ::reset();
   if(!present("shaggy zombie"))
      new(MON_PATH+"shagzomb")->move(this_object());
}
 
