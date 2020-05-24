//      From Maxwell's Underground mudlib
//      65th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a cramped mine tunnel. The tunnel "
"continues to the east and closes down to a smaller tunnel to the west.");
    set("long",@ext 
You are standing in a cramped mine tunnel somewhere in the 
Under'Drin Mine Complex. The long mine track continues to slope down 
here, running through a small tunnel that is just big enough for the 
mine carts. The top of the track has been smoothed and ground to a bright 
polish by the passing mine carts. The tunnel continues back to the 
east.
    0   
    |   
    @--0
ext);
    set_exits( ({ UNDER+"dm64",UNDER+"dm52" }),
      ({ "east","north" })
      );
    set_items( ([
       "rock" : "Crushed rock and straw is covering the floor.",
       "track" : "The track shines in the darkness.",
      ]) );
}
