// whall 2

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A turn in the hallway");
    set("long", @ext You are now standing in a hallway outside the dining 
      room that lies to the south.  The passage continues to the east 
      and west for a short distance.
    0   
    |   
    @--0  
ext);
    add_exit("whall1","east");
    add_exit("deadroom","north");

    set_smell("default", "You smell death and decay.");
    set_listen("default", "You hear moaning in the distance.");
}
