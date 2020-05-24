
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 1);
set_property("indoors", 1);
add_exit(ROOMS+"ruins10.c", "west");
set("short", "Ruins Of Ancient City");
set("day long", @ext The Ruins Of An Ancient House. This room is empty. The
walls around you look like there about to topple down apon you. There is a
doorway that leads to the west.
   
 0--@
ext);
set("night long", @ext The Ruins Of An Ancient House. This room is empty. The
walls around you look like there about to topple down apon you. There is a
doorway that leads to the west.

 0--@
ext);
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "It is extremely quiet.");
}
