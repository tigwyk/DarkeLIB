/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",
   "The passageway bends slightly here as it winds its way through the "
   "the catacombs.  A faint light is coming from the south while to "
   "the northwest the corridor continues into the darkness."
   );
   set_smell("default", "The air smells of rotting flesh.");
   set_listen("default", "You hear moaning nearby.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "northwest": PATH+"catac116",
                "south": PATH+"catac118",
               ]) );
}
 
void reset() {
   ::reset();
   if(!present("skeleton")) 
      new(MON_PATH+"skeleton")->move(this_object());
   if(!present("torch"))
      new("/std/obj/torch")->move(this_object());
}
 
     
