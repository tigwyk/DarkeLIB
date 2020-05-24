/* Catacomb chest coded by Duridian for DarkeMud.  Can be unlocked by
   wightkey.c, obtained from the wight at ~duridian/catacomb/catac145. */
 
#include "std.h"
inherit "/std/bag_logic";
 
void create() {
   ::create();
   set_name("large chest");
   set("id", ({ "chest", "large chest" }) );
   set("short", "large chest");
   set("long",
   "This large chest sports a shiny, gold lock, on which is engraved a "
   "skull with two large fangs protruding from its mouth.");
   set_weight(5000);
   set("value", 0);
   set_max_internal_encumbrance(1500);
   set_possible_to_close(1);
   toggle_closed();
   set_lock("locked");
   set_key("fanged skull key");
}
