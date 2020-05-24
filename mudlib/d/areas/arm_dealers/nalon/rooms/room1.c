inherit "std/room";
#include <dirs.h>
#include <std.h>
#include "../monk.h"


void create() {
  ::create();
   set_property("light",2);
   add_exit(MONKROOMS+"room2", "west");
   add_exit("/d/damned/virtual/room_13_14.world", "out");
   set("short","Village of Nalon   \n    \n0--@   \n    \n   O\n");
   set("long",
     "This is the entrance to the forest village of Nalon, " +
     "the abode of the peaceful monks.  " +
     "The village and surrounding forest is pleasantly green, " +
     "the plant life healthy and strong.  " +
     "The village lies to the west, " +
     "beyond the small huts a clearing is visible.   \n    \n0--@   \n    \n   O\n  ");
   add_item("huts","They are small but well contructed and stable.");
   add_item("village","The monks village spreads to the west.");
   add_item("forest","The forest is pleasantly green.");
   set_smell("default","You can smell plant life.");
}

void reset() {
  ::reset();
   if(!present("guard")){
   new(MONKMOBS+"monk_guard.c")->move(this_object());
   new(MONKMOBS+"monk_guard.c")->move(this_object());
}
}
