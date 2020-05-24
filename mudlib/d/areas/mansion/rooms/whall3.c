// whall 3

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A turn in the hallway");
    set("long", @ext You standing in the middle of a quiet hallway.  
      To the east and west you see the lanterns flicker as they 
      sparsely light more hallway.  To the north lies the music 
      room.  There is also a large hole in the ceiling here.
    0   
    |   
 0--@--0  
ext);
    add_item("hole","The hole in the ceiling is too high to reach.");
    add_exit("whall4","east");
    add_exit("music","north");
    add_exit("whall1","west");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear a few music notes.");
}
