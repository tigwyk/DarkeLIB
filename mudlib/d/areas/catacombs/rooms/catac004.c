/* Room coded by Duridian for DarkeMud. */

#include "std.h"
inherit ROOM;

void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   This large room lies roughly north and east from the entrance to the 
   catacombs.  The ceiling is high here, and little droplets of water 
   hit you on the head occasionally.  You gag on the horrible stench of 
   rotting flesh.
      0  
     /   
 0--@
     \
      0  
ext);
   set_smell("default", "It smells of rotting flesh here.");
   set_listen("default", "You hear water dripping.");
   set_items( ([
                "ceiling":
        "It is far above your head.",
                ({"water","droplets", "water droplets"}):
        "The water seems to be dripping from the ceiling.",
                ]) );
   set_exits( ([
                "west": PATH+"catac002",
                "southeast": PATH+"catac007",
                "northeast": PATH+"catac006",
               ]) );
}
