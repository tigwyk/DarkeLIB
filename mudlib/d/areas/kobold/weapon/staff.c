/* Weapon coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit WEAPON;
 
void create() {
   ::create();
   set_name("kobold staff");
   set("id", ({"staff", "kobold staff"}) );
   set("short", "kobold staff");
   set("long",
   "The kobold shepherd's staff looks as though it would be effective for "
   "beating animals into shape, but not effective in doing combat."
   );
   set_weight(200);
   set_value(35);
   set_type("two handed blunt");
   set_wc(9, "crushing");
   set_material("wood/wood");
   set_ac(1);
   set_quality(2);
   set_verb("beat");
   set_hit_bonus(-5);
   set_parry_bonus(10);
   set_property("no add quality", 1);
}
