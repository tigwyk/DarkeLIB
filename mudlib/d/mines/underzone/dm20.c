//      From Maxwell's Underground mudlib
//        20th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing on a sandy beach next to an underground "
                 "river.");
    set("long", 
"You are standing on a sandy beach next to an underground river. The " 
"murky water flows out from underneath a large wall, pouring into a "
"large pool. The water flows by the beach and enters a tunnel heading "
"downstream. The beach is littered with debris from the river. Piles of "
"branches and moldy leaves are everwhere. The area looks like no one "
"has been here recently. There is a passage leading to the north, "
"between two large boulders.\n"    
       );
    set_exits( ({ UNDER+"dm19", UNDER+"dm21" }),
      ({ "river", "north" })
    );
    set_items( ([
       "water" : "The murky water has flooded this chamber and formed a"
" large pool.",
       "branches" : "The river washes the debris up on the beach.",
       "leaves" : "The river washes the debris up on the beach.", 
      ]) );
       
     set_smell("default", "The smell of the moulding debris fills the "
 "air.");
}
