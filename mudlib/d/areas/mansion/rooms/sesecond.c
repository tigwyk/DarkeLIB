// sesecond

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "The southeast corner of the second floor");
    set("long", @ext You are standing at southeast side of the second.  
      floor of the mansion.  To the north lies a path along the 
      balcony.  To the east you see a narrow hallway.
    0   
    |   
    @--0  
ext);
    add_exit("nesecond","north");
    add_exit("uehall1","east");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
