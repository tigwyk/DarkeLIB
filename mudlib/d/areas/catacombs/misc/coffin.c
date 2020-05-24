/* Coffin coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit "/std/bag_logic";
 
void create() {
   object ob;
   ::create();
   set_name("large chest");
   set("id", ({ "coffin", "large coffin" }) );
   set("short", "large coffin");
   set("long",
   "This large coffin is made of granite and appears to be very old.  On "
   "the lid of the coffin is carved several strange runes, none like you "
   "have ever seen before.  The lid does not appear to be attached securely."
   );
   set_weight(7000);
   set("value", 0);
   set_max_internal_encumbrance(2000);
   set_possible_to_close(1);
   ob = new("/std/obj/torch");
   ob->move(this_object());
   toggle_closed();
}
