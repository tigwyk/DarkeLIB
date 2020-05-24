//      Wizard:  Khojem
//      Main Gallery
//      gallery.c

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if (!present("king")) {
	  new("/d/khojem/new/mon/king")->move(this_object());
	}
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "   0\n   |\n   @   \n   | \n   0\nA broad gallery");
    set("long", "You are standing within a large gallery.  The vaulted, ceiling "+
      "is trussed with large, wooden beams.  This is a place where the wood-elf "+
      "king conducts affairs of state.  Your footsteps echo through the large "+
      "chamber.\n   0\n   |\n   @   \n   | \n   0\n"
    );
    add_exit("foyer","south");    
    add_exit("/d/khojem/new/room/s/s1","north");
    set_items(([
     ({ "ceiling","beams" }) :
        "Large, beams carved from the trunks of trees in the surrounding forest "+
        "support the large, vaulted ceiling and roof.",
     ({ "gallery" }) :
        "The gallery is void of any furnishings.  A few paintings adorn the walls.",
     ({ "paintings", "painting" }) :
        "Several cheap oil paintings of the king as a proud, young man decorate "+
        "the walls.  Hmm.. the king has a lousy taste for art."
     ]));
    set_smell("default", "The gallery smells of perfumed waters and herbs.");
    set_listen("default", "You hear people murmuring in the distance.");
}
