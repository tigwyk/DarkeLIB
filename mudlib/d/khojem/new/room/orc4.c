//      Wizard:  Khojem
//      orc4
//      orc4.c

#include <std.h>

inherit ROOM;

int no_exit() { return 1;}

void init() {
    ::init();
    if(this_player()->chk_my_mon()) {
      add_action("no_exit","north");
    }
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "   \n    \n   @--0\n    \n   \nAn underground passage");
    set("long", "You are in a deadend underground passage.  Dirt walls "+ 
      "surround the small passage and the dirt floor is hard and "+
      "smooth from repeated use.\n   \n    \n   @--0\n    \n   \n"
    );
    add_exit("orc3","east");
    add_exit("hill1","north");
    add_invis_exit("north");
    set_items(([
     ({ "cave","cavern", "passage" }) :
        "The is very narrow and you feel cramped.",
     ({ "walls", "floor", "wall", "dirt" }) :
        "The walls and floor are very hard, dry clay.  Digging out "+
        "would be an impossible task.  As you move about.. you "
        "happen to notice the north face of the cave's wall seems "+
        "to shimmer and move as you move.  Hmm... that's odd... ",
     ]));
    set_smell("default", "A dank, musty smell fills the air.  You can "+
      "smell wood burning and food cooking.");
    set_listen("default", "The cave is very quiet.");
}
