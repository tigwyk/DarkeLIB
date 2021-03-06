//      From Maxwell's Underground mudlib
//        68th Room of Dwarf Mining Zone

#include "/adm/include/std.h"
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in an mining tunnel.");
    set("long", 
"You are standing in a damp mining tunnel somewhere in the mining complex. "
"The rough walls are jagged and cut at sharp angles where the miners dug "
"out gems.\nYou can see the passage continue to the west here." ); 
    set_exits( ({ "/wizards/maxwell/underzone/dm68c", 
"/wizards/maxwell/underzone/dm68e" }),
      ({"northeast","west" })
    );
    set_items( ([
    "walls" : "The walls are cut and jagged.",
       ]) );
       
    set_smell("default", "You can smell the dust in the air.");
    set_listen("default", "You hear the sounds of mining in the distance.");
}
