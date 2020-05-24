#include <dirs.h>
#include <std.h>
#include "../monk.h"

inherit ROOM;

void create() {
  ::create();
   set_property("light",2);
   add_exit(MONKROOMS+"room31", "west");
   add_exit(MONKROOMS+"room32", "east");
   add_exit(MONKROOMS+"room25", "north");
   set("short","Meditation area\n   0\n   | \n0--@--0\n    \n   \n");
   set("long",
"The meditation area of the monks, this is where the "
"more spiritual and harmonious monks come to meditate.  "
"An area with soft grass has been cleared out for them "
"to sit, while they ponder the meaning of life. "
"There is a fire pit in which they burn materials "
"to help them contemplate more deeply.\n   0\n   | \n0--@--0\n    \n   \n");
   add_item("pit","A large fire pit in which the monks "
"burn special materials with there wood, to help expand "
"there minds.");
   add_item("fire pit","A large fire pit in which the monks "
"burn special materials with there wood, to help expand "
"there minds.");
   set_smell("default","The scent of a heavy insense is in the air");
}

void reset() {
  ::reset();
   if(!present("monk")){
   new(MONKMOBS+"med_monk.c")->move(this_object());
   new(MONKMOBS+"med_monk.c")->move(this_object());
   new(MONKMOBS+"med_monk.c")->move(this_object());
   }
}
