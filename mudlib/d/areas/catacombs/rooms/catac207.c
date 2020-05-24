/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   This bend in the corridor runs to the west and south from here.  You 
   hear loud laughter occasionally, and it seems to be coming from the 
   west somewhere.
  
 0--@
    |
    0   
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
                "west": PATH+"catac208",
                "south": PATH+"catac202",
                ]) );
}
 
void reset() {
   ::reset();
   if(!present("giant skeleton"))
      new(MON_PATH+"giant_skeleton")->move(this_object());
}
