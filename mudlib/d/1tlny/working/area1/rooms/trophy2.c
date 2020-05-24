// trophy 2

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "The trophy room");
    set("long", "This trophy room is filled with many heads of "+
      "animals lining the wall.  A wrecked display in the middle "+
      "of the room has some strange runes written around it.  The "+
      "trophy room continues to the west, and a hallway lies to the "+
      "south.");
    add_item("heads","These are of old victims of some hunter.");
    add_item("runes","These runes appear to be written in blood.");
    add_item("display","The display has some paw prints left on it.");
    add_exit("trophy1","west");
    add_exit("ehall4","south"); 

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
void reset() {
   ::reset();
   if(!present("chimera")) {
      new(A1MON+"chimera")->move(this_object());
   }
}
