#include "../newbieville.h"
#include <std.h>

inherit "/std/vault";


void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("don")) {
      new(MON+"don")->move(this_object());
   }

    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "   0\n   | \n0--@   \n     \n    \nWeapon Store");
    set("long", "The only weapon store in all of Newbieville is run by Don Juan, who built the business by hand and hammer. He charges fair prices, and delivers high quality wares. There is a staircase leading upwards, but is blocked by a large iron door that Don also protects.\n   0\n   | \n0--@   \n     \n    \n");
    add_exit(ROOMS+"commonstreet", "west");
    add_exit(ROOMS+"lightway", "north");
    add_exit(ROOMS+"wstores", "up");
   set_door("iron door", ROOMS+"wstores", "door",
            "newbieville weapon shop store");
   set_open("iron door", 0);
   set_locked("iron door", 1);
   set_lock_level("iron door", 22);

}
