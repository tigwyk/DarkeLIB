// ehall 1

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A stained-glass hallway");
    set("long", "This hallway leads from north to south.  To the east "+
      "the wall is made up almost entirely of fine stained glass.  To "+
      "the west you can see the art room."
  );
    add_item("glass","You see brilliantly crafted stain glass windows.");
    add_exit("artroom","west");
    add_exit("ehall2","north");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear howling nearby.");
}
