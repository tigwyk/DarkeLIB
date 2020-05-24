#include <dirs.h>
#include <std.h>
#include "../monk.h"
inherit ROOM;

void create() {
  ::create();
   set_property("light",2);
   add_exit(MONKROOMS+"room15", "west");
   set("short","Warrior-monk training area   \n    \n0--@   \n    \n   \n");
   set("long",
"This area has been cleared out for the warrior monks to train, the "
"ground has been worn by training to the point that nothing "
"will grow here.  Various tools to help the monks stretch out "
"there limbs lie around.   \n    \n0--@   \n    \n   \n");
   add_item("tools","Tools to help the monks stretch out "
"before they start there training.");
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
