// Wizard:  Khojem
// Vo'Sangor Harbor Map
// harbor_map.c

#include <move.h>

inherit "/std/Object";

void init() {
     ::init();
  add_action("do_read","read");
}

void create() {
  ::create();
  set_name("vo'sangor harbor map");
  set_id(({ "harbor map", "map" }) );
  set_short("a harbor map");
  set_long("The parchment is old and wrinkled, but details the harbor.  "+
    "Maybe if you attempt to 'read' the map you could make out the layout of "+
    "the Vo'Sangor harbor?"
  );
}

int do_read(string str) {
  if(str == "map" || str == "harbor map") { 
    this_player()->more("/d/khojem/port/obj/map_text");
    return 1;
  }
  return 0;
}
