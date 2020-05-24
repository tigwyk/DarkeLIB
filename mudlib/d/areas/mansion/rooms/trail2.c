// trail 2

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "A dark forest path");
    set("long", @ext You stand on a dark, winding trail.  It narrows ext
      as it slithers off to the north into the thicker forest.
    0   
    |   
    @
    |
    0  
ext);
    add_item("trail","The trail looks as though it were once well worn.");
    add_item("forest","The dark forest looms all around you.");
    add_exit("trail3","north");
    add_exit("trail1","south");

    set_smell("default", "You smell rotting wood.");
    set_listen("default", "You hear the rustling of leaves in the trees.");
}
