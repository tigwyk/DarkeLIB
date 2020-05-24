//      Wizard:  Khojem
//      foyer
//      foyer.c

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if (!present("champion")) {
	  new("/d/khojem/new/mon/champion")->move(this_object());
	}
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "   0\n   | \n   @   \n   | \n   0\nA wide foyer");
    set("long", "This is a wide foyer.  People that require an audience "+
      "with the king wait here.   "+
      "The foyer is filled with paintings.\n   0\n   | \n   @   \n   | \n   0\n"
    );
    add_exit("/d/1tlny/complete/fir_boss_room/s/gallery.c","north");
    add_exit("plat3","south");
    set_pre_exit_functions(({"north"}),({"go_north"}));
    set_items(([
     ({ "painting","paintings" }) :
        "The paintings are cheap watercolors of wood-elves fighting all "+
        "sorts of nasty things... (dragons, orcs, trolls...)",
     ({ "foyer" }) :
        "The foyer is a high-ceiling room with a wood floor."
     ]));
    set_smell("default", "The smell of perfumed waters and herbs.");
    set_listen("default", "You hear people murmuring in the distance.");
}

int go_north() {
  if(present("champion")) {
    write("The king's champion steps before you and blocks your exit.\n"+
      "The champion says,  Sorry, you don't have an appointment.\n");
    return 0;
  }
  else return 1;
}
