/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The passageway widens slightly as it bends to the south.  The passageway 
   continues to the northwest and northeast, while to the south the corridor 
   widens even more.
  0   0  
   \ /   
    @
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
                "northwest": PATH+"catac211",
                "northeast": PATH+"catac209",
                "south": PATH+"catac213",
                ]) );
}
 
void reset() {
   ::reset();
   if(!present("skeleton guard"))
      new(MON_PATH+"skelgrd")->move(this_object());
}
 
