//      Wizard:  Khojem
//      orc1
//      orc1.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "   \n     \n   @--0\n   | \n   0\nAn underground passage");
    set("long", "You are in an underground passage.  Dirt walls "+ 
      "surround the small passage and the dirt floor is hard and "+
      "smooth from repeated use.\n   \n     \n   @--0\n   | \n   0\n"
    );
    add_exit("orc2","east");
    add_exit("hole","south");
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

