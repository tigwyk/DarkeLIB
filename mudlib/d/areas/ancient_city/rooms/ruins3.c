
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 1);
set_property("indoors", 1);
add_exit(ROOMS+"ruins2.c", "south");
add_exit(ROOMS+"ruins8.c", "north");
add_exit(ROOMS+"ruins6.c", "east");
add_exit(ROOMS+"ruins4.c", "west");
set("short", "Ruins Of Ancient City");
set("day long", @ext The Ruins Of An Ancient City. In the middle of the once
great market square of this once great town. In the middle of the square
there is a stone fountain which still seems to be working. There are four
roads from here one west, one north, one east, and one south
    0   
    |   
 0--@--0
    |
    0
ext);
set("night long", @ext The Ruins Of An Ancient City. In the middle of the once
great market square of this once great town. In the middle of the square
there is a stone fountain which still seems to be working. There are four
roads from here one west, one north, one east, and one south
    0   
    |   
 0--@--0
    |
    0
ext);
set_smell("default", "The cold wind feels like death on your skin");
new(ITEM+"fountain.c")->move(this_object());
set_listen("default", "The trickling of the fountain is very soothing.");
}
