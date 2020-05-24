// sechamber

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "The southeast corner of the chamber");
    set("long", "Now at the southeast corner of the large chamber.  "+
      "You can see a doorway leading to some sort of art room to  "+
      "the east, and darkness to the north and west."
  );
    add_exit("nechamber","north");
    add_exit("artroom","east");
    add_exit("indoor","west");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
