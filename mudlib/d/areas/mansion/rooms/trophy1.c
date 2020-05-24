// trophy 1

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "The trophy room");
    set("long", @ext This trophy room is filled with many heads of 
      animals lining the wall.  A wrecked display in the middle 
      of the room has some strange runes written around it.  The 
      trophy room continues to the east, and a hallway lies to the 
      south.

    @--0
    |
    0
ext);
    add_item("heads","These are of old victims of some hunter.");
    add_item("runes","These runes appear to be written in blood.");
    add_item("display","The display has some hoof prints left on it.");
    add_exit("trophy2","east");
    add_exit("nhall4","south"); 

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
void reset() {
   ::reset();
   if(!present("unicorn")) {
      new(A1MON+"unicorn")->move(this_object());
   }
}
