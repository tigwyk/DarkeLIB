// frontstairs

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "On a long stairway");
    set("long", "You stand on a long, gradual set of stairs. "+
      "To the north lies the second floor, across a once fancy "+
      "red carpet."
  );
    add_exit("centersecond","north");
    add_exit("indoor","south");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
