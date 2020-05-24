// nwchamber

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "The northwest corner of the chamber");
    set("long", @ext Now at the northwest corner of the large chamber.  
      You can see a long dining hall to the west.  To the east you 
      notice a strange tight passage under the stairs.

 0--@--0
    |
    0  
ext);
    add_exit("understairs","east");
    add_exit("swchamber","south");
    add_exit("din1","west");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
