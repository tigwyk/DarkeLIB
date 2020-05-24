// centersecond

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "At the center of the second floor");
    set("long", @ext You are standing at the top of a long set of  
      stairs.  To the east and west you can see a balcony trail 
      along the second floor.
 
  0--@--0
     |
     0 
ext);
    add_exit("nwsecond","west");
    add_exit("frontstairs","south");
    add_exit("nesecond","east");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
