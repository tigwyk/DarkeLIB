
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 3);
set_property("night light",0); 
add_exit(ROOMS+"basement31.c", "north");
add_exit(ROOMS+"basement33.c", "east");
set("short", "The Basement Of An Ancient House");
set("day long", @ext The Basement Of An Ancient House. This walls around you
are filled with cracks and chipped paint. The cieling has falling apart and
has alot of holes in it. There seems to be just enough light coming throw
the holes in the ceiling to let you see. You are standing in a small
passage. The passage way continues east and north
    0   
    |   
    @--0
ext);
set("night long", @ext It is dark
    0   
    |   
    @--0
ext);
set_smell("default", "The smell of rat guano and cheeze fills your
nostrils");
set_listen("default", "The sound of rats fills the room");
}
void reset() {
::reset();
  if(!present("rat"))
{
new(MON+"rat_giant.c")->move(this_object());
new(MON+"rat_giant.c")->move(this_object());
new(MON+"rat_giant.c")->move(this_object());
new(MON+"rat_giant.c")->move(this_object());
new(MON+"rat_giant.c")->move(this_object());
}
}

