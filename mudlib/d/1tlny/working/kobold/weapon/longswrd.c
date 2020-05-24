/* Weapon coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit WEAPON;
 
void create() {
   ::create();
   set_name("kobold longsword");
   set("id", ({"sword", "longsword", "kobold longsword"}) );
   set("short", "kobold longsword");
   set("long",
   "This is the longsword of the kobold chieftain.  The blade looks "
   "quite sharp and its ivory hilt is very ornate.  Overall, it seems "
   "to be a fairly decent weapon."
   );
   set_weight(350);
   set_value(150);
   set_type("blade");
   set_wc(15, "cutting");
   set_ac(3);
   set_quality(4);
   set_hit_bonus(15);
   set_parry_bonus(5);
}
