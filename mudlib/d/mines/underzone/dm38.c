//      From Maxwell's Underground mudlib
//        38th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

int x,w,e;
object who,here;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a small chamber. A large silver "
              "altar is in the center of the room.");
    set("long", 
"You are standing in a small chamber. The solid stone walls climb up "
"and meet in the center of the ceiling to form a dome. The dominate "
"object in the room is a large silver altar in the center of the chamber. "
"Several assorted vases and statues are in small shelves recessed in "
"the solid stone.\n");
    x = 1;
    set_exits( ({ UNDER+"dm35"}),
    ({ "northeast" }));
    set_items( ([
    "vases" : "Some of the vases are still intact but look very fragile.",
    "statues" : "The statues are creatures you have never seen before.",
    "dome"    : "The dome is very high.",
    "walls"   : "The thick walls are solid stone.",
    ]));
    set_smell("default", "The air smells musty.");
    w = 0;
    new(UNMON+"sguard")->move(this_object());
}

void reset() {

   ::reset();
    if(!present("altar")) 
      new(UNQST+"saltar")->move(this_object());    
    return;
}

