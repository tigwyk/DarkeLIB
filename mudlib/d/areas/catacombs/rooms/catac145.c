/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 2);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   This secret room appears to be home to some sort of smelly creature.  
   Torn clothing lays in a pile in one corner of the room, while a pile 
   skulls sits in the opposite corner.  A few torches provide some light, 
   shining brightly in this otherwise dark system of catacombs.
  
 0--@  
ext);
   set_smell("default", "The air smells of rotting flesh.");
   set_listen("default", "You hear moaning nearby.");
   set_items( ([
                ({"torn clothing", "clothing"}):
        "The various garments are ripped to shreds.",
                ({"torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ({"skulls", "pile", "pile of skulls"}):
        "The skulls are cracked in places.  Are those teeth marks you see?",
                ]) );
   set_exits( ([
                "west": PATH+"catac130",
                ]) );
}
 
void reset() {
   ::reset();
   if(!present("ugly wight"))
      new(MON_PATH+"wight")->move(this_object());
}
