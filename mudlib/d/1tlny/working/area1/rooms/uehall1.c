// uehall 1

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A narrow hallway");
    set("long", "You are standing at the southern end of a short "+
      "hallway.  To the west you can see a balcony overlooking "+
      "the first floor.  To the north the hallway continues."
  );
    add_exit("sesecond","west");
    add_exit("uehall2","north");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
void reset() {
   if(!present("zombie"))
      new(A1MON+"zombie")->move(this_object());
}
