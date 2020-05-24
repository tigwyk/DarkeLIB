#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 3);
set_property("indoors", 1);
add_exit(ROOMS+"ruins8.c", "south");
//add_exit(ROOMS+"tunnel1.c", "tunnel");
add_exit(ROOMS+"shop3.c", "east");
set("short", "Ruins Of Ancient City");
set("day long", @ext The Ruins Of An Ancient City. There is little to see but ruins of old buildings. There is a shop to the east and it is still open and standing strong. The road continues to the south.

    @--S
    |
    0
ext);
set("night long", @ext The Ruins Of An Ancient City. There is little to see but ruins of old buildings. There is a shop to the east and it is still open and standing strong. The road continues to the south.

    @--S
    |
    0
ext);
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "It is extremely quiet.");
}
