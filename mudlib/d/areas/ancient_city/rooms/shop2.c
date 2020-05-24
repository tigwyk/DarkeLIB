
#include "../ruins.h/"
#include <std.h>
inherit "/std/vault";

void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("opis")) {
new(MON+"opis.c")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
add_exit(ROOMS+"ruins7.c", "north");
add_exit(ROOMS+"shop2_store.c", "east");
set_door("iron door", (ROOMS+"shop2_store.c"), "east",
"shop2 store");
   set_open("iron door", 0);
   set_locked("iron door", 1);
   set_lock_level("iron door", 22);
   set("short","The Opis's Armour Store");
set("long", @ext This is Opis's Armour Store. Here, you can purchase the
various types of armour needed for adventuring in the ancient city. There
are many types of armour seen all about you. An imposing iron door is seen
to the north.
    0   
    |   
    @
ext);
   set_items( (["sign":"The say reads: 'say opis, help' for assistance.",
              "iron door" : "It looks very sturdy.",
              "door" : "It is a large iron door."]) );
}
