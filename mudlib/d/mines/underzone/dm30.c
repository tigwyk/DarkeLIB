//      From Maxwell's Underground mudlib
//        30th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short","You are standing in a small tunnel that slopes sharply "
        "down to the south." );
    set("long",@ext 
"You are standing in a small tunnel that slopes sharply down to 
"the south. The floor of the tunnel is covered with small limestone 
"formations. The white and brown formations are spread accross the 
"walls and the ceiling of the tunnel. Several of the larger formations 
"were broken off by previous visitors.
  0
   \
    @
    |
    0        
ext);
    set_exits( ({ UNDER+"dm29",UNDER+"dm31" }),
      ({ "northwest", "south" })
    );
    set_items( ([
       "wood" : "The moldy wood has DYNAMITE stamped on it.",
      ]) );
       set_smell("default", "The dust floating through the air is making "
"it hard to breathe.");
}

