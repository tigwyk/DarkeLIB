/* Weapon coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit WEAPON;
 
void create() {
   ::create();
   set_name("broken stick");
   set("id", ({"stick", "broken stick"}) );
   set("short", "broken stick");
   set("long",
   "The broken stick is covered with dirt.  It does not look like a very "
   "good weapon."
   );
   set_weight(45);
   set_value(0);
   set_type("blunt");
   set_wc(4, "crushing");
   set_material("wood/wood");
   set_quality(0);
   set_verb("tap");
   set_hit_bonus(-15);
   set_parry_bonus(-25);
   set_property("no add quality", 1);
}
