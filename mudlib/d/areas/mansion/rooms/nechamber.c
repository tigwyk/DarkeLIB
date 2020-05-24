// nechamber

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "The northeast corner of the chamber");
    set("long", @ext Now at the northeast corner of the large chamber.  
      You can see a bedroom doorway to the east.  To the west you 
      notice a strange tight passage under the stairs.

 0--@--0
    |
    0  
ext);
    add_exit("understairs","west");
    add_exit("sechamber","south");
    add_exit("carebed1","east");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
