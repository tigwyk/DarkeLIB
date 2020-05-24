// uehall 2

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A narrow hallway");
    set("long", "You are standing at the northern end of a short "+
      "hallway.  To the east you can see a doorway leading to "+
      "a balcony outside.  To the north you see a doorway leading "+
      "to the mansion attic."
  );
    add_exit("balcony","east");
    add_exit("uehall1","south");
    add_exit("attic1","north");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
