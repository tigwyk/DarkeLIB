
#include "../ruins.h"
inherit "/std/vault";


void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("shein")) {
new(MON+"shein.c")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
add_exit(ROOMS+"ruins5.c", "east");
add_exit(ROOMS+"shop1_store.c", "north");
set_door("iron door", (ROOMS+"shop1_store"), "north", "shop1 store");
   set_open("iron door", 0);
   set_locked("iron door", 1);
   set_lock_level("iron door", 22);
   set("short","The Shein's General Store");
   set("long", @ext This is Shein's General Store. Here, you can purchase the
various items and sundries needed for day-to-day adventuring in the ancient
city. Several useful items are seen all about. An imposing iron door is
seen to the east.

    @--0

ext);
   set_items( (["sign":"The say reads: 'say shein, help' for assistance.",
              "iron door" : "It looks very sturdy.",
              "door" : "It is a large iron door."]) );
}

