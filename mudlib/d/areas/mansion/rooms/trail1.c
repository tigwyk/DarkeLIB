// trail 1

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("long", @ext You stand on a dark, winding trail.  It narrows 
      as it slithers off to the north into the thicker forest.
    0   
    |   
    @
      out
     
ext);
set("short","A dark forest trail.");
    add_item("trail","The trail looks as though it were once well worn.");
    add_item("forest","The dark forest looms all around you.");
   add_exit("/d/damned/virtual/room_4_5.world","out");
    add_exit("trail2","north");

    set_smell("default", "You smell rotting wood.");
    set_listen("default", "You hear the rustling of leaves in the trees.");
}
