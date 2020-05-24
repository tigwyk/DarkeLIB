/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   This long passageway continues to lead to the east, away from the 
   entrance to this level of the dungeons.  The torches on the wall 
   provide a little light, but a brighter light is seem coming from 
   the southeast.

 0--@
     \
      0  
ext);
   set_smell("default", "The air is very dry.");
   set_listen("default", "You hear evil laughter to the north.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                "light":
        "The light to the southeast is fairly bright.",
                ]) );
   set_exits( ([
                "west": PATH+"catac203",
                "southeast": PATH+"catac205",
                ]) );
}
