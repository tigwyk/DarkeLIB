// whall 1

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A quiet hallway");
    set("long", "You are now standing in a hallway outside the dining "+
      "room that lies to the south.  The passage continues to the east "+
      "and west for a short distance."
  );
    add_exit("whall2","west");
    add_exit("whall3","east");
    add_exit("din2","south");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
