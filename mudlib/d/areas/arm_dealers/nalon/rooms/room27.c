#include <dirs.h>
#include <std.h>
#include "../monk.h"
inherit ROOM;

void create() {
  ::create();
   set_property("light",2);
   add_exit(MONKROOMS+"room30", "south");
   add_exit(MONKROOMS+"room28", "east");
   add_exit(MONKROOMS+"room29", "west");
   add_exit(MONKROOMS+"room10", "north");
   set("short","Outside the huts\n   0\n   | \n0--@--0\n   | \n   0\n");
   set("long",
"South of a clearing, some large huts surround here "
"in all directions but north.  The huts are sturdy, large, "
"and well-built, hinting that the monks living in these "
"might be more important then most.  Well tended gardens "
"outline the rims of these huts.\n   0\n   | \n0--@--0\n   | \n   0\n");
}
void reset() {
  ::reset();
   if(!present("monk")){
   new(MONKMOBS+"monk2.c")->move(this_object());
   new(MONKMOBS+"monk1.c")->move(this_object());
   }
}
