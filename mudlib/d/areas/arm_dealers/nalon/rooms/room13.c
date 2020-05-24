#include <dirs.h>
#include <std.h>
#include "../monk.h"
inherit ROOM;

void create() {
  ::create();
   set_property("light",2);
   add_exit(MONKROOMS+"room20", "west");
   add_exit(MONKROOMS+"room14", "south");
   add_exit(MONKROOMS+"room12", "north");
   add_exit(MONKROOMS+"room8", "east");
   set("short","Small clearing\n   0\n   | \n0--@--0\n   | \n   0\n");
   set("long",
"This is a small clearing in the middle of the monk's habitat.  A "
"well lies in the center of it to the east, "
"the source of water for the monks.  The surrounding " 
"forest is extremely peaceful and green, the animals "
"living in peace.\n   0\n   | \n0--@--0\n   | \n   0\n");
   add_item("forest","The forest is pleasantly green.");
   add_item("well","The monks old drinking well.");
}

void reset() {
  ::reset();
   if(!present("monk")){
   new(MONKMOBS+"monk2.c")->move(this_object());
   new(MONKMOBS+"monk1.c")->move(this_object());
   }
}
