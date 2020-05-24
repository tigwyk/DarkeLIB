/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   This long passageway runs east from the entrance to the level.  Small 
   torches affixed to the wall help you to guide your way down the 
   corridor.  There seems to be some light to the east.
   
 0--@--0
ext);
   set_smell("default", "The air is very dry.");
   set_listen("default", "You hear evil laughter to the north.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "west": PATH+"catac202",
                "east": PATH+"catac204",
                ]) );
}
