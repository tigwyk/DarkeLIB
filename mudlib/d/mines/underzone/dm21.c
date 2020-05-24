//      From Maxwell's Underground mudlib
//        21st Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a small stone passage.");
    set("long",@ext 
You have entered a small stone passage. The walls look like they 
were carved a long time ago. The broken stone had been worn down 
by many years of running water. Small mineral veins run through the 
stone, along with a small gold vein. There is a fair amount of 
granite debris on the floor. It looks like some rocks fell down from 
the ceiling of the passage. The passage continues to the northeast 
and leads south to a sandy beach.   
      0  
     /   
    @
    |
    0       
ext);
    set_exits( ({ UNDER+"dm20", UNDER+"dm22" }),
      ({ "south", "northeast" })
    );
    set_items( ([
       "rocks" : "The rocks are scattered around the passage randomly.",
       "viens" : "The veins are fairly small and not worth digging.",
     "ceiling" : "The ceiling has large cracks and holes. Several rocks"
" look like they could fall from it at anytime."
      ]) );
       
     set_smell("default", "The air is becoming slightly cloudy as you "
"step in piles of dust.");
}
