// nstairs 2

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "At the top of the stairs");
    set("long", "You are standing at the top of a steep stairway.  "+
      "To the north you can see some sort of reception area."
  );
    add_exit("outlab","north");
    add_exit("nstairs1","down");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
void reset() {
   ::reset();
   if(!present("zombie")) {
      new(A1MON+"zombie")->move(this_object());
      new(A1MON+"zombie")->move(this_object());
   }
}
