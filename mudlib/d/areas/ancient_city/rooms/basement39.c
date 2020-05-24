
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 3);
set_property("night light",0); 
add_exit(ROOMS+"basement38.c", "north");
add_exit(ROOMS+"basement40.c", "south");
add_exit(ROOMS+"basement34.c", "west");
set("short", "The Great Storage Room Of An Ancient Basement");
set("day long", @ext The Great Storage Room Of An Ancient Basement. The walls
around you look are fule of cracks and holes. The ceiling is also full of
holes. There is just enough light coming throw the holes in the ceiling for
you to see.
    0   
    |   
 0--@
    |
    0
ext);
set("night long", @ext It is dark
    0   
    |   
 0--@
    |
    0
ext);
set_smell("default", "The smell of rat guano and cheeze fills your
nostrils");
set_listen("default", "The sound of rats fills the room");
}
void reset() {
::reset();
  if(!present("rat"))
{
new(MON+"rat_demon.c")->move(this_object());
new(MON+"rat_demon.c")->move(this_object());
new(MON+"rat_demon.c")->move(this_object());
new(MON+"rat_demon.c")->move(this_object());
new(MON+"rat_demon.c")->move(this_object());
}
}
