/* Weapon coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit WEAPON;
 
void create() {
   ::create();
   set_name("typh");
   set("id", ({"typh"}) );
   set("short", "typh");
   set("long",
   "A typh consists of two heavy, spiked, iron balls on the end of a long "
   "chain.  While this weapon can be wielded in one hand, it is more "
   "deadly when thrown at a target."
   );
   set_weight(90);
   set_value(80);
   set_type("blunt");
   set_wc(14, "crushing");
   set_quality(3+random(2));
   set_verb("bash");
   set_hit_bonus(25);
   set_parry_bonus(-15);
   set_throwable(1);
}
