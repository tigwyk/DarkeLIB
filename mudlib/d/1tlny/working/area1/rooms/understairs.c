// understairs

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 2);
    set("short", "A dark passage");
    set("long", "Underneath the long stairs, you find yourself trying "+
      "to squeeze through.  On either side of you lies a slim passage "+
      "back to the entrance chamber."
  );
    add_exit("nechamber","east");
    add_exit("nwchamber","west");

    set_smell("default", "You smell mold and mildew.");
    set_listen("default", "You hear quiet whispering.");
}
