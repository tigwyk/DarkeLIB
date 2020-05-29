//      From Maxwell's Underground mudlib
//          12th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a damp mine tunnel somewhere "
        "within the Under'Drin Mining Complex.");
    set("long","You are standing in a damp mine tunnel somewhere within the "
"Under'Drin Mining complex. Water slowly rolls down the walls in "
"little streams, soaking the moldy straw that is lining the passage. "
"You can see faint seams of mineral deposits in the walls.\n");
    set_exits( ({ UNDER+"dm11", UNDER+"dm13" }),
      ({ "west", "southeast" })
    );
    set_items( ([
       "water" : "There must be an underground spring nearby.",
       "deposits" : "The minerals sparkle in the light.",
      ]) );
}
