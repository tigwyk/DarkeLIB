#include <dirs.h>
#include <std.h>
#include "../monk.h"
inherit ROOM;

void init() {
  ::init();
   add_action("read_fun", "read");
}

void create() {
  ::create();
   set_property("light",2);
   add_exit(MONKROOMS+"room20", "south");
   set("short","An old monks home    \n     \n   @   \n   | \n   0\n");
   set("long",
"This stone building belongs to the villages eldest "
"monk.  He is so old that he can hardly manage to walk without "
"help.  His room consists of a few shelves, a table, and "
"a soft bed.  On the shelves is a history tome, it's pages "
"lined with wear.    \n     \n   @   \n   | \n   0\n");
   add_item("bed","A soft bed made to comfort the bones of an old man");
   add_item("table","A barren table.");
   add_item("shelves","The shelves contain little of interest besides "
"a history tome.");
   add_item("tome","This old text was written by an outsider, but kept "
"here by the old monk.");
   add_item("history tome","This old text was written by an outsider, but kept "
"here by the old monk.");

}

int read_fun(string str)
{
   if (!str) {
     notify_fail("read what?\n");
     return 0;
   }

   if (str == "history tome" || str == "tome") {
     this_player()->more("/wizards/shanus/nalon/history");
     return 1;
   }
   notify_fail("You do not see that here!\n");
   return 0;
}

void reset(){
object monk;
  ::reset();
  if(!present("wisened monk", this_object()))
  {
    monk = new(MONKMOBS+"wise_monk");
    monk->move(this_object());
  }
}
