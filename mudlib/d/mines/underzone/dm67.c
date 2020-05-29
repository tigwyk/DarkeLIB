//      From Maxwell's Underground mudlib
//        67th Room of Dwarf Mining Zone

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
"of dust and debris on the floor.\n"); 
    set_exits( ({ UNDER+"dm3", UNDER+"dm68a" }),
      ({ "east", "west" })
    );
    set_items( ([
    "walls" : "The rough walls stretch out before you.",
       ]) );
       
    set_smell("default", "You can smell the dust in the air.");
//    set_listen("default", "You hear the sounds of code creation.");
}
