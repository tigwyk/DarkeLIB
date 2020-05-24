
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 1);
set_property("indoors", 0);
add_exit(ROOMS+"basement5.c", "south");
add_exit(ROOMS+"basement2.c", "north");
add_exit(ROOMS+"basement4.c", "east");
set("short", "The Basement Of An Ancient House");
set("day long", @ext The Basement Of An Ancient House. This walls around you
are filled with cracks and chipped paint. The cieling is falling apart and
has alot of holes in it. There seems to be just enough light coming throw
the holes in the ceiling to let you see. You are standing in a mid sized
room which you are in the lower west corner of. There is a passage way to
the south.
    0   
    |   
    @--0
    |
    0
ext);
set("night long", @ext The Basement Of An Ancient House. This walls around you
are filled with cracks and chipped paint. The cieling is falling apart and
has alot of holes in it. You are standing in a mid sized room which you are
in the lower west corner of. There is a passage way to the south.
    0   
    |   
    @--0
    |
    0
ext);
set_smell("default", "The smell of rat guano fills your nostrils");
set_listen("default", "The sound of rats fills the room. You can also hear
a sound of pick axes to the south.");
}
void reset() {
::reset();
  if(!present("rat"))
{
new(MON+"smallratchild_spear.c")->move(this_object());
new(MON+"smallratchild.c")->move(this_object());
new(MON+"smallratchild.c")->move(this_object());
}
}

