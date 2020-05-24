// nstairs 1

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "At the bottom of the stairs");
    set("long", "You are standing at the foot of a steep stairway.  "+
      "To the north you can see a well lit hallway."
  );
    add_exit("nstairs2","up");
    add_exit("nhall3","north");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
void reset() {
   ::reset();
   if(!present("zombie")) {
      new(A1MON+"zombie")->move(this_object());
   }
}
