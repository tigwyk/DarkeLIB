//      From Maxwell's Underground mudlib
//      63rd Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a cramped mine tunnel.");
    set("long", 
"You are standing in a cramped mine tunnel somewhere in the "
"Under'Drin Mine Complex. Thick straw is lying on the floor of the "
"tunnel, crushed down by hundreds of passing feet. Running down the "
"wall in small streams is blackened water. It rolls down and is trapped "
"in small pools amongst the molding straw.");
    set_exits( ({ UNDER+"dm62", UNDER+"dm64" }),
      ({ "east", "west" })
      );
    set_items( ([
       "straw" : "Crushed rock and straw is covering the floor.",
       "water" : "The murky water is slowly flooding the floor.",
      ]) );
}
