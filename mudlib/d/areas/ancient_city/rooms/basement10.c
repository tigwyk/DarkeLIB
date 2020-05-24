
#include "../ruins.h"
inherit "std/room";
void create() {
::create() ;
set_property("light", 1);
set_property("indoors", 1);
add_exit(ROOMS+"basement22.c", "west");
set_invis_exits(({ "west" }));
add_exit(ROOMS+"basement11.c", "east");
set("short", "A Tunnel");
set("day long", @ext A Tunnel. The Tunnel looks like it has just been bug. The
ceiling is also full of holes made by pick axes. There is just enough light
coming throw the holes in the ceiling for you to see. Here sits a large
golden statue of a rat god. Torches line the walls
  
    @--0
ext);
set("night long", @ext A Tunnel. The Tunnel looks like it has just been bug.
The ceiling is also full of holes made by pick axes. There is just enough
light coming throw the holes in the ceiling for you to see. Here sits a
large golden statue of a rat god. Torches line the walls

    @--0
ext);
set_smell("default", "The smell of rat guano fills your nostrils");
set_listen("default", "The sound of rats and the sound of pick axes fills
the room.");
}
void reset() {
 ::reset();
 
if(!present("rat"))
{
new(MON+"smallratchild_pick.c")->move(this_object());
new(MON+"smallratchild_pick.c")->move(this_object());
new(MON+"rat_spear.c")->move(this_object());
}
        if(!present("statue"))
{
new(MON+"statue.c")->move(this_object());
}
}
