//      Wizard:  Khojem
//      orc9
//      orc9.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "   0\n   | \n0--@--0\n   | \n   0\nAn underground passage");
    set("long", "You are in an underground passage.  Dirt walls "+ 
      "surround the small passage and the dirt floor is hard and "+
      "smooth from repeated use.\n   0\n   | \n0--@--0\n   | \n   0\n"
    );
    add_exit("orc8","west");
    add_exit("/d/1tlny/complete/fir_boss_room/s2/chief.c","east");
    add_exit("orc10","south");
    add_exit("orc11","north");
    set_items(([
     ({ "cave","cavern", "passage" }) :
        "The is very narrow and you feel cramped.",
     ({ "walls", "floor" }) :
        "The walls and floor are very hard, dry clay.  Digging out "+
        "would be an impossible task."
    ]));
    set_smell("default", "A dank, musty smell fills the air.  You can "+
      "smell wood burning and food cooking.");
    set_listen("default", "The cave is very quiet.");
}
