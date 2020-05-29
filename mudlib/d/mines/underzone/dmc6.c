//      From Maxwell's Underground mudlib
//        6th Room of Dwarf Mining/Crypt Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are in a musty burial chamber. There are two seperate "
"chambers to the north and south and a passage to the east.");
    set("long", "You are standing in a musty burial chamber. Long cobwebs "
"hang down in front of you. There are seperate private chambers to the "
"north and to the south. A passage to the east opens into a larger room.");
    set_exits( ({ UNDER+"dmc5",UNDER+"dmc7",UNDER+"dmc8",UNDER+"dm42"}),
      ({ "west","north","south","east" }));
    set_items( ([
    "archway" : "The archway is made of stone, and is covered in mold."]));
    set_smell("default", "You can smell the foul stench of decay and "
"mold.");
}


