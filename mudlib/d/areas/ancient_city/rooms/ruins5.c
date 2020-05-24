
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 1);
set_property("indoors", 1);
add_exit(ROOMS+"shop1.c", "west");
add_exit(ROOMS+"ruins4.c", "east");
add_exit(ROOMS+"ruins10.c", "south");
set("short", "Ruins Of Ancient City");
set("day long", @ext The Ruins Of An Ancient City. There is little to see but a
shop to the west and a open house to the south. There are gaint rat like
foot prints that lead into the house to the south. There is a shop to the
west which seems to still be open even though the city is infested with
rat-men. The road continues east.
   
 S--@--0
    |
    0
ext);
set("night long", @ext The Ruins Of An Ancient City. There is little to see but
a shop to the west and a open house to the south. There are gaint rat like
foot prints that lead into the house to the south. There is a shop to the
west which seems to still be open even though the city is infested with
rat-men. The road continues east.

 S--@--0
    |
    0
ext);
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "It is extremely quiet.");
}

