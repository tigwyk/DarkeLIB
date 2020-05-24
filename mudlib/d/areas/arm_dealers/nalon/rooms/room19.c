#include <dirs.h>
#include <std.h>
#include "../monk.h"
inherit ROOM;

void create() {
  ::create();
   set_property("light",2);
   add_exit(MONKROOMS+"room15", "east");
   set("short","Warrior-monk training area   \n    \n   @--0\n    \n   \n");
   set("long",
"This area has been cleared out for the warrior monks to train, the "
"ground has been worn by training to the point nothing will "
"grow.  Pieces of broken wood lie about, used to help the "
"hard working monks beef up there fists.   \n    \n   @--0\n    \n   \n");
   add_item("wood","Broken pieces of dry wood, used to "
"strengthen the warriors limbs by bashing it in twain.");
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
