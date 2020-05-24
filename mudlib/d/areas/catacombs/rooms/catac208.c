/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The passageway continues to bend in seemingly every direction.  From 
   this point the corridor winds north and east.  You hear the clang of 
   metal in the distance to the north.   
    0   
    |   
    @--0
ext);
   set_smell("default", "The air is very dry.");
   set_listen("default", "You hear evil laughter to the west.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "north": PATH+"catac209",
                "east": PATH+"catac207",
                ]) );
}
 
void reset() {
   ::reset();
   if(!present("giant skeleton"))
      new(MON_PATH+"giant_skeleton")->move(this_object());
}
 
