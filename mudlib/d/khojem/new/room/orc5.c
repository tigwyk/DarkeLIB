//      Wizard:  Khojem
//      orc5
//      orc5.c

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
    if (!present("half-orc guard" , this_object()) ) {
        new("/d/khojem/new/mon/orc_guard")->move(this_object());
        new("/d/khojem/new/mon/orc_guard")->move(this_object());
        new("/d/khojem/new/mon/orc_guard")->move(this_object());
	}
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "\n   \n    \n0--@   \n    \n   \nAn underground room");
    set("long", "This room appears to be a place for soldiers.  Weapons "+
      "line the walls.  Several benches are here to allow the soldiers "+
      "to rest after standing their long watches.\n   \n    \n0--@   \n    \n   \n"
    );
    add_exit("orc2","west");
    set_items(([
     ({ "cave","cavern", "room" }) :
        "It is an oval-shaped room with many weapons resting along the wall.",
     ({ "walls", "floor" }) :
        "The walls and floor are very hard, dry clay.  Digging out "+
        "would be an impossible task.",
     ({ "bench", "benches" }) :
        "The benches are crudely made of wood and appear uncomfortable. "+
        "It is probably that way by design so the guards don't get too fat.",
     ({ "weapons" , "weapon" }) :
        "Unfortunately, the Half-Orcs don't do a good job of maintaining "+
        "their weapons.  Right now all the weapons here are in need of repair."
    ]));
    set_smell("default", "A dank, musty smell fills the air.  You can "+
      "smell wood burning and food cooking.");
    set_listen("default", "The cave is very quiet.");
}
