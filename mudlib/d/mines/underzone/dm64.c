//      From Maxwell's Underground mudlib
//      64th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors", 1);
    set("short", "You are standing in a cramped mine tunnel. The tunnel "
"continues to the west and to the east.");
    set("long",@ext 
The tunnel begins to get smaller here. The broken 
rock lying in the trench beside the steel mine track scatters and 
crunches under your steps. You can see the track stretch to the east 
and off to the west.
  
 0--@--0
ext);
    set_exits( ({ UNDER+"dm63", UNDER+"dm65" }),
      ({ "east", "west" })
      );
    set_items( ([
       "rock" : "Crushed rock and straw is covering the floor.",
       "track" : "The track shines in the darkness.",
      ]) );
}
