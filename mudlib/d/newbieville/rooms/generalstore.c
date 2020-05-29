#include "../newbieville.h"
#include <std.h>

inherit "/std/vault";


void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("jack")) {
      new(MON+"jack")->move(this_object());
   }

    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "   \n    \n   @--0\n    \n   \nGeneral Store");
    set("long", "This is Jack's famous general store. He sells pretty much anything to anyone, and will buy anything that you don't need. You see an iron trap door on the floor, presumably where Jack stores his things.\n   \n    \n   @--0\n    \n   \n
");
    add_exit(ROOMS+"commonstreet", "east");
//    add_exit(ROOMS+"shadowroad", "north");
    add_exit(ROOMS+"gstores", "down");
   set_door("iron door", ROOMS+"gstores", "door",
            "newbieville general store");
   set_open("iron door", 0);
   set_locked("iron door", 1);
   set_lock_level("iron door", 22);

}
