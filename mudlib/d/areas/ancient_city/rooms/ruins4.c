
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 1);
set_property("indoors", 1);
add_exit(ROOMS+"ruins3.c", "east");
add_exit(ROOMS+"ruins5.c", "west");
set("short", "Ruins Of Ancient City");
set("day long", @ext The Ruins Of An Ancient City. There is little to see but
ruins of old buildings. Rats run along the ground below you looking for
cheeze. The once great market square is to the east. The road continues
west

 0--@--T
ext);
set("night long", @ext The Ruins Of An Ancient City. There is little to see but
ruins of old buildings. Rats run along the ground below you looking for
cheeze. The once great market square is to the east. The road continues
west

 0--@--T
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

