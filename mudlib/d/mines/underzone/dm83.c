//      From Maxwell's Underground mudlib
//        82nd Room of Dwarf Mining Zone



#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a cramped side tunnel. The walls "
"appear to have been mined recently.");
    set("long",@ext 
You are standing in a cramped side tunnel somewhere in the Mining 
Complex. The cold walls stretch off in front of you, filled with pits 
and fresh cracks from the recent mining of the Dwarves. There are 
many piles of loose rubble here.Between a couple of the piles is 
a arch leading into chamber.
     
        chamber   
    @
    |
    0
ext);
    set_exits( ({ UNDER+"dm82",UNDER+"dm84"}),
      ({ "south","chamber" }) );

}




