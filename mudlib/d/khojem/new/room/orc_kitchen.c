//      Wizard:  Khojem
//      orc_kitchen
//      orc_kitchen.c

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if (!present("cook")) {
	  new("/d/khojem/new/mon/cook")->move(this_object());
	}
}


void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "   0\n   | \n   @   \n     \n    \nA small kitchen");
    set("long", "You are in a small room that is used as the kitchen "+
      "for these underground dwellers.  A small cooking fire is "+
      "burning in the center of the kitchen and the smoke drifts "+
      "up to a hole high up in the ceiling.\n   0\n   | \n   @   \n     \n    \n"
    );
    add_exit("orc8","north");
    set_items(([
     ({ "fire", "cooking fire" }) :
        "It is a small fire fueled by wood from the nearby forest.",
     ({ "ceiling", "hole" }) :
        "The hole in the ceiling is too high for you to climb out.",
        "smoke" : "The dark smoke lazily drifts up to the hole.",
     ({ "walls", "floor" }) :
        "The walls and floor are very hard, dry clay.  Digging out "+
        "would be an impossible task."
    ]));
    set_smell("default", "The smell of cooking food is strong.");
    set_listen("default", "The cave is very quiet.");
}
