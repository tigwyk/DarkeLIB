
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 3);
set_property("night light",0); 
add_exit(ROOMS+"basement29.c", "west");
add_exit(ROOMS+"basement31.c", "south");
set("short", "The Basement Of An Ancient House");
set("day long", @ext The Basement Of An Ancient House. This walls around you
are filled with cracks and chipped paint. The cieling has falling apart and
has alot of holes in it. There seems to be just enough light coming throw
the holes in the ceiling to let you see. You are standing in a small
passage. The passage way continues west and south

 0--@
    |
    0
ext);
set("night long", @ext It is dark

 0--@
    |
    0
ext);
set_smell("default", "The smell of rat guano fills your nostrils");
set_listen("default", "There is a sound of rats coming from the west");
}

