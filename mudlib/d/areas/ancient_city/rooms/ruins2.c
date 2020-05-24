
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 1);
set_property("indoors", 1);
add_exit(ROOMS+"ruins3.c", "north");
add_exit(ROOMS+"ruins1.c", "south");
set("short", "Ruins Of Ancient City");
set("day long", @ext The Ruins Of An Ancient City. The grass road turns into
what looks like a very durt covered road. You see rats running along the
ruins of ancient builds looking for food. The archway that leads to the
surrounding forest is to the south. The road contuines north
    T   
    |   
    @
    |
    0
ext);
set("night long", @ext The Ruins Of An Ancient City. The grass road turns into
what looks like a very durt covered road. You see rats running along the
ruins of ancient builds looking for food. The archway that leads to the
surrounding forest is to the south. The road contuines north
    T   
    |   
    @
    |
    0
ext);

set_smell("default", "The cold wind feels like death on your skin");
set_items(([
({ "ruins", "buildings", "ruins of old buildings", "old buildings" }) :
"The ruins of a once a great building. The walls are crumbling to dust day
by day.",
({ "road" , "durt", "durt road" }) :
"The durt road turns into a grass covered road here. The durt is covered in
small rat like foot prints.",
({ "grass", "grass road", "road", "passage" }) :
"The grass covered road turns into a durt road here."
]));
set_listen("default", "The sound of rats fill the street.");
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

