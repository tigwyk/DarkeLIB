#include <dirs.h>
#include <std.h>
#include "../monk.h"
inherit ROOM;

void create() {
  ::create();
   set_property("light",2);
//   add_exit("/d/damned/guilds/join_rooms/warrior-monk_join.c", "north");
   add_exit(MONKROOMS+"room18", "south");
   add_exit(MONKROOMS+"room16", "east");
   add_exit(MONKROOMS+"room19", "west");
   add_exit(MONKROOMS+"room11", "southeast");
   set("short","Warrior-monk training area\n      \n       \n0--@--0\n   |\\ \n   0 0\n");
   set("long",
"This grassy area, empty of trees and large plants, is used "
"for warrior-monk combat training.  Since they only train "
"in hand-to-hand combat, it is devoid of weapons.  To the "
"east and west more training can be heard. There is a tent "
"to the south.\n      \n       \n0--@--0\n   |\\ \n   0 0\n");
   add_item("tent","A large tent in which the warrior-monks meet.");
   set_listen("default","The sounds of training can be heard.");
}

void reset() {
  ::reset();
   if(!present("warrior")){
      new(MONKMOBS+"war_monk1.c")->move(this_object());
      new(MONKMOBS+"war_monk1.c")->move(this_object());
   }
   if(!present("trainer"))
      new(MONKMOBS+"monk3.c")->move(this_object());
}
