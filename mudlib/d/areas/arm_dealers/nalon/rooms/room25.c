#include <dirs.h>
#include <std.h>
#include "../monk.h"
inherit ROOM;

void create() {
  ::create();
   set_property("light",2);
   add_exit(MONKROOMS+"room24", "north");
   add_exit(MONKROOMS+"room26", "south");
   set("short","Village path\n   0\n   | \n   @   \n   | \n   0\n");
   set("long",
"This is a village path leading south to the monks meditation "
"area.  To the north the path turns east and heads into "
"the center of the village.  Monks come and go, eager to "
"get there work done.\n   0\n   | \n   @   \n   | \n   0\n");
   add_item("path","A path leading to the western outskirts of town.");
}
void reset() {
  ::reset();
   if(!present("monk")){
   new(MONKMOBS+"monk3.c")->move(this_object());
   new(MONKMOBS+"monk1.c")->move(this_object());
   }
}
