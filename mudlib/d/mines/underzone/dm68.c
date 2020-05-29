//      From Maxwell's Underground mudlib
//        68th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in an mining tunnel.");
    set("long", 
"You are standing in a small tunnel. The rough walls are jagged and cut "
"at sharp angles where the miners dug out gems. There is a thick layer "
"of dust and debris on the floor.\nThe walls are getting closer together."
" The type of rock here must be harder to mine, so the miners didn't "
"attempt to open a large passage\n"); 
    set_exits( ({ UNDER+"dm50", UNDER+"dm67" }),
      ({"passage","east" })
    );
    set_items( ([
    "walls" : "The rough walls stretch out before you.",
       ]) );
       
    set_smell("default", "You can smell the dust in the air.");
//    set_listen("default", "You hear the sounds of code creation.");
}
