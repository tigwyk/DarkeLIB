
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 1);
set_property("indoors", 0);
add_exit(ROOMS+"basement5.c", "north");
add_exit(ROOMS+"basement12.c", "east");
add_exit(ROOMS+"basement10.c", "west");
set("short", "The Basement Of An Ancient House");
set("day long", @ext The Basement Of An Ancient House. This walls around you
are filled with cracks and chipped paint. The cieling is falling apart and
has alot of holes in it. There seems to be just enough light coming throw
the holes in the ceiling to let you see. You are standing in a small
passage which has come to a fork. The passage way continues east and
west.
    0   
    |   
 0--@--0
ext);
set("night long", @ext The Basement Of An Ancient House. This walls around you
are filled with cracks and chipped paint. The cieling is falling apart and
has alot of holes in it. You are standing in a small passage which has come
to a fork. The passage way continues east and west.
    0   
    |   
 0--@--0
ext);
set_smell("default", "The smell of rat guano fills your nostrils");
set_listen("default", "The sound of rats fills the room. There is a sound
of pick axes coming from the west.");
}

