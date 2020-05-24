// swchamber

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "The southwest corner of the chamber");
    set("long", @ext Now at the southwest corner of the large chamber.  
      You can see a doorway to the distant north, and darkness to 
      the east.
    0   
    |   
    @--0  
ext);
    add_exit("nwchamber","north");
    add_exit("indoor","east");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
