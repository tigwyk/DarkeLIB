// nhall 4

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A well lit hallway");
    set("long", "The hallway you are standing in continues to the east "+
      "and the west.  To the north you can a trophy room."
  );
    add_exit("trophy1","north");
    add_exit("ehall4","east");
    add_exit("nhall3","west");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear nothing.");
}
