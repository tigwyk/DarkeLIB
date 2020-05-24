#include <dirs.h>
#include <std.h>
#include "../monk.h"
inherit ROOM;

void create() {
  ::create();
   set_property("light",2);
   add_exit(MONKROOMS+"room13", "west");
   add_exit(MONKROOMS+"room10", "south");
   add_exit(MONKROOMS+"room9", "north");
   add_exit(MONKROOMS+"room5", "east");
   set("short","A well\n   0\n   | \n0--@--0\n   | \n   0\n");
   set("long",
"This is the middle of a clearing, the monk's village "
"surrounds it.  A deep well is here, the one and "
"only water source of the monks.  This is the most "
"frequented area of the village, the monks coming to "
"get a nice cold drink after hard training.\n   0\n   | \n0--@--0\n   | \n   0\n");
   add_item("village","The monks village which you are in the middle of.");

}

void reset() {
   if(!present("well")) {
   new(MONKOBJ+"well.c")->move(this_object());
   }
   if(!present("monk")){
   new(MONKMOBS+"monk1.c")->move(this_object());
   new(MONKMOBS+"monk2.c")->move(this_object());
   new(MONKMOBS+"monk3.c")->move(this_object());
  }
}
