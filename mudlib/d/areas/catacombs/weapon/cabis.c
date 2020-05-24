/* Weapon coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit WEAPON;
 
void create() {
   ::create();
   set_name("cabis");
   set("id", ({"cabis"}) );
   set("short", "cabis");
   set("long",
   "A cabis is a carefully-weighted throwing weapon that features several "
   "sharp blades at the end of a long thin shaft.  This weapon looks "
   "somewhat crude, but also appears to be very deadly."
   );
   set_weight(70);
   set_value(75);
   set_type("axe");
   set_wc(12, "cutting");
   set_ac(1);
   set_quality(3+random(2));
   set_verb("hack");
   set_hit_bonus(20);
   set_parry_bonus(-10);
   set_throwable(1);
}
