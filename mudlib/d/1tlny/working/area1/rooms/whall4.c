// whall 4

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A turn in the hallway");
    set("long", "You have reached a turn from north to west in the "+
      "hallway.  The passage continues to the west for as far as you "+
      "can see, and takes another turn towards the north."
  );
    add_exit("whall3","west");
    add_exit("nhall1","north");

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
