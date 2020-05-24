
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 1);
set_property("indoors", 1);
add_exit(ROOMS+"ruins12.c", "west");
add_exit(ROOMS+"ruins11.c", "east");
add_exit(ROOMS+"ruins5.c", "north");
add_exit(ROOMS+"basement3.c", "stairs");
set("short", "Ruins Of Ancient City");
set("day long", @ext The Ruins Of An Ancient House. The walls around you look
like there about to topple down apon you. There are gaint rat like foot
prints on the ground leading to a set of stairs that go down into the
basement of this house. There are two other doors one to the east and the
other to the west. There is a doorway that leads outside the house to the
north.
    0   
    |s   
 0--@--0   
ext);
set("night long", @ext The Ruins Of An Ancient House. The walls around you look
like there about to topple down apon you. There are gaint rat like foot
prints on the ground leading to a set of stairs that go down into the
basement of this house. There are two other doors one to the east and the
other to the west. There is a doorway that leads outside the house to the
north.
    0   
    |s   
 0--@--0 
ext);
set_smell("default", "The cold wind feels like death on your skin");
set_items( (["sign":"The sign reads: 'Sorry this area is not ready yet'"]));
set_listen("default", "It is extremely quiet.");
}

