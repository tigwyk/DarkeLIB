#include <dirs.h>
#include <std.h>
#include "../monk.h"
inherit ROOM;

void create() {
  ::create();
   set_property("light",2);
   add_exit(MONKROOMS+"room13", "north");
   add_exit(MONKROOMS+"room10", "east");
   set("short","Small clearing\n   0\n   | \n   @--0\n     \n    \n");
   set("long",
"This is a small clearing in the middle of the monk's habitat.  A "
"well lies to the northeast, which is the source of water for "
"the monks.  The surrounding forest is extremeley peaceful "
"and green, the animals leaving in peace.  To the southeast "
"some huts can be seen.\n   0\n   | \n   @--0\n     \n    \n");
   add_item("forest","The forest is pleasantly green.");
   add_item("well","The monks old drinking well.");
}

void reset() {
  ::reset();
   if(!present("monk")){
   new(MONKMOBS+"monk2.c")->move(this_object());
   new(MONKMOBS+"monk1.c")->move(this_object());
   }
   if(!present("gardener"))
   new(MONKMOBS+"monk_gardener.c")->move(this_object());
}
