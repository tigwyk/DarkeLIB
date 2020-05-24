// outlab

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "Outside a laboratory");
    set("long", @ext This plain reception area leads to a doorway set 
      in the west wall.  Overturned furniture is all around the 
      room, and a stairway lies to the south.

 0--@
    |
    0  
ext);
    add_item("furniture","The furniture looks as though it were broken "+
      "by a blunt object.");
    add_exit("lab1","west");
    add_exit("nstairs2","south");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
void reset() {
   ::reset();
   if(!present("hunter")) {
      new(A1MON+"hunter")->move(this_object());
   }
}
