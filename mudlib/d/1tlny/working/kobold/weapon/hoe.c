/* Weapon coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit WEAPON;
 
void create() {
   ::create();
   set_name("hoe");
   set("id", ({"hoe", "kobold hoe"}) );
   set("short", "kobold farmer's hoe");
   set("long",
   "The hoe looks as though it would be good for tilling soil, but not for "
   "fighting.  The handle of the farming is warped, and the blade is "
   "rusted."
   );
   set_weight(300);
   set_value(25);
   set_type("two handed blunt");
   set_wc(5, "crushing");
   set_material("wood/wood");
   set_quality(2);
   set_verb("bash");
   set_hit_bonus(-5);
   set_parry_bonus(-5);
}
