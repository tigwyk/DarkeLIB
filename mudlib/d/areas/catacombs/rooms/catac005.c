/* Room coded by Duridian for DarkeMud. */

#include "std.h"
inherit ROOM;

void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   This passageway curves from north to northwest here.  There are bones 
   and teeth strewn on the floor here.  There is moaning coming from 
   the chamber to the northwest, and the air smells very foul.
  0 0   
   \|   
    @  
ext);
   set_smell("default", "You smell something foul.");
   set_listen("default", "You hear moaning.");
   set_items( ([
                ({"bones", "bone", "teeth"}):
      "Bright white bones and teeth litter the floor.",
                ]) );
   set_exits( ([
                "north": PATH+"catac003",
                "northwest": PATH+"catac033",
                ]) );
}
