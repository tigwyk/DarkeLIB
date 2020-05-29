//      From Maxwell's Underground mudlib
//        41st Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a large dusty chamber. An arch "
"leads to another room to the south.");
    set("long", "You are standing in a large dusty chamber. The walls are "
"made of solid stone blocks that are stacked all the way to the ceiling. "
"Carved into the walls are words written in a language you can't "
"comprehend. The writing wraps around the walls on a border of marble. "
"Scattered on the floor is an assortment of debris that has fallen from "
"the ceiling. An arch leads out of the chamber to the south.\n");
    set_exits( ({ UNDER+"dm43" }),
      ({  "south" }));
    set_items( ([
"arches" : "The tall arches are supporting the ceiling."]) );
       set_smell("default", "You can smell the dust floating in the air.");
}

