
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 3);
set_property("indoors", 1);
add_exit(ROOMS+"ruins3.c", "south");
add_exit(ROOMS+"ruins9.c", "north");
set("short", "Ruins Of Ancient City");
set("day long", @ext The Ruins Of An Ancient City. There is little to see but
ruins of old buildings. The rats run up to you looking for food. The once
great market square is to the south. The road continues to the north.
    0   
    |   
    @
    |
    T
ext);
set("night long", @ext The Ruins Of An Ancient City. There is little to see but
ruins of old buildings. The rats run up to you looking for food. The once
great market square is to the south. The road continues to the north.
    0   
    |   
    @
    |
    T
ext);
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "It is extremely quiet.");
}
void reset() {
 ::reset();
if(!present("rat"))
{
new(MON+"rat.c")->move(this_object());
new(MON+"rat.c")->move(this_object());
new(MON+"rat.c")->move(this_object());
}
}

