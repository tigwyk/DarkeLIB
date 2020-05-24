//      From Maxwell's Underground mudlib
//        32nd Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short","You are crawling in a small connection tunnel. A small "
"opening leads to a chamber to the east and the tunnel continues for "
"several more feet to the west.");
    set("long",@ext 
You are crawling in a small connection tunnel. A small opening 
leads to a chamber to the east and the tunnel continues for 
several more feet to the west. The sides of the tunnel look like 
they were carved out recently. There are no formations along 
the floor and there is still a fair amount of dust from when 
the walls were chipped away.
       
       hole   
 0--@        
ext);
    set_exits( ({ UNDER+"dm31",UNDER+"dm33" }),
      ({ "hole", "west" })
    );
    set_items( ([
       "wood" : "The moldy wood has DYNAMITE stamped on it.",
      ]) );
       set_smell("default", "Large gusts of moldy smelling wind are "
"blowing from the western end of the tunnel.");
}

