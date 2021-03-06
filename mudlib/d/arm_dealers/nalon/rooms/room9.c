#include <dirs.h>
#include <std.h>
#include "/d/arm_dealers/nalon/monk.h"
inherit ROOM;

void create() {
  ::create();
   set_property("light",2);
   add_exit(MONKROOMS+"room11", "north");
   add_exit(MONKROOMS+"room12", "west");
   add_exit(MONKROOMS+"room6", "east");
   add_exit(MONKROOMS+"room8", "south");
   set("short","Small clearing");
   set("long",
"This is a small clearing in the middle of the monk's habitat.  A "
"well lies in the center of it to the south, which is "
"the source of water for the monks.  The surrounding " 
"forest is extremely peaceful and green, the animals "
"living in peace.  A path leads north.");
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
