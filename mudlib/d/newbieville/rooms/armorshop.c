//  Made by Tailwind for the BR Casino.
#include "../newbieville.h"
#include <std.h>

inherit "/std/vault";


void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("michael")) {
      new(MON+"michael")->move(this_object());
   }

    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "   \n     \n0--@   \n   | \n   0\nArmor Store");
    set("long", "This is the Fine Armor and Protections Shop, run by Michael. Michael is a great armorer. In fact, he is so great that legends spread about his armormaking prowess as far as other dimensions. There are many powerful and expensive armors hanging on the walls, and gauntlets and gloves are in a counter top case.\n   \n     \n0--@   \n   | \n   0\n");
    add_exit(ROOMS+"majestyave", "west");
    add_exit(ROOMS+"lightway", "south");
    add_exit(ROOMS+"astores", "up");
   set_door("iron door", ROOMS+"astores", "door",
            "newbieville armor store");
   set_open("iron door", 0);
   set_locked("iron door", 1);
   set_lock_level("iron door", 22);
}
