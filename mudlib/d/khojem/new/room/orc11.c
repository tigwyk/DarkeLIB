//      Wizard:  Khojem
//      Orc Chief's Chambers
//      chief.c

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
    if (!present("half-orc guard" , this_object()) ) {
        new("/d/khojem/new/mon/orc_guard1")->move(this_object());
        new("/d/khojem/new/mon/orc_guard1")->move(this_object());	  
    }
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "    \n     \n   @   \n   | \n   0\nHalf-Orc Chief's Chamber");
    set("long", "You are in the Half-Orc Chief's Chamber.  "+
      "From here the chief makes his plans against the Wood-Elves.  "+
      "Except for the chief's chair there is no furniture.  A small "+
      "fire burns here for light and warmth in the dank cave.\n    \n     \n   @   \n   | \n   0\n"
    );
    add_exit("orc9","south");
    set_items(([
     ({ "cave","cavern", "chamber" "chief's chamber" }) :
        "The walls are bare dirt.",
     ({ "chair", "chief's chair", "throne" }) :
        "The wood chair is crudely constructed of split logs from the forest.",
     ({ "walls", "floor" }) :
        "The walls and floor are very hard, dry clay.  Digging out "+
        "would be an impossible task.",
     ({ "fire", "small fire" }) :
        "It is a very, small wood fire and close to burning out."
    ]));
    set_smell("default", "A dank, musty smell fills the air.  You can "+
      "smell wood burning and food cooking.");
    set_listen("default", "The cave is very quiet.");
}
