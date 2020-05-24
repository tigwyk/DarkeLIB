// trail 5

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "A dark forest path");
    set("long", "You stand on a dark, winding trail.  It narrows "+
      "as it slithers off to the north into the thicker forest.  "+
      "There is some sort of a clearing to the east."
  );
    add_item("trail","The trail looks as though it were once well worn.");
    add_item("forest","The dark forest looms all around you.");
    add_exit("outdoor","north");
    add_exit("trail4","south");
    add_exit("trail6","east");

    set_smell("default", "You smell rotting wood.");
    set_listen("default", "You hear the rustling of leaves in the trees.");
}
void reset() {
   ::reset();
   if(!present("dog")) {
      new(A1MON+"dog")->move(this_object());
      new(A1MON+"dog")->move(this_object());
   }
}

