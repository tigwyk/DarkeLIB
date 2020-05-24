// nesecond

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "The northeast corner of the second floor");
    set("long", "You are standing at northeast side of the second.  "+
      "floor of the mansion.  To the north you see a dimly lit "+
      "hallway.  To the west and south lie a path along the "+
      "balcony."
  );
    add_exit("centersecond","west");
    add_exit("sesecond","south");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
