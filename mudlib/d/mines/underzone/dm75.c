//      From Maxwell's Underground mudlib
//        75th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "You are standing in an underground room");
    set("long", 
"You are in a long tunnel 75.");
    set_exits( ({ UNDER+"dm80"}),
      ({ "east" })
    );
}



