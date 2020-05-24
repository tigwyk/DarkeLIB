
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 3);
set_property("night light",1);
add_exit(ROOMS+"ruins6.c", "west");
//add_exit(ROOMS+"ladder1.c", "ladder");
add_exit(ROOMS+"shop2.c", "south");
set("short", "Ruins Of Ancient City");
set("day long", @ext The Ruins Of An Ancient City. There is little to see but
ruins of old buildings. The road continues west. There is a shop to the
south which seems to still be open even through all the trouble this town
is going through. 

 0--@
    |
    S
ext);
set("night long", @ext The Ruins Of An Ancient City. There is little to see but
ruins of old buildings. The road continues west. There is a shop to the
south which seems to still be open even through all the trouble this town
is going through. 

 0--@
    |
    S
ext);
set_listen("default", "It is extremely quiet.");
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "It is extremely quiet.");
}

