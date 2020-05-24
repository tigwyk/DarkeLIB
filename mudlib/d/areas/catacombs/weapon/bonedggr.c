/* Weapon coded by Duridian for DarkeMud. */

#include "std.h"
inherit WEAPON;

void create() {
   mixed str;
   
   ::create();
   set_name("bone dagger");
   set("id", ({"bone dagger", "dagger"}) );
   set("short", "bone dagger");
   set("long",
   "This dagger has a bone hilt which is highly ornate, containing intricate "
   "carvings of skulls and bones.  The blade is about ten inches long and "
   "is very sharp."
   );
   set_weight(150);
   set_value(750);
   set_type("knife");
   set_wc(15, "impaling");
   set_ac(2);
   set_quality(3+random(3));
   set_parry_bonus(-10);
   set_throwable(1);
/*   set_property("enchantment", 1);
   str = ({ ({"This dagger glows with an unholy light.", "detect magic" }) });
   set_property("extra long", str);
   set_hit( (: this_object(), "weapon_hit" :) ); */
}

/*int weapon_hit(object attacker) {

   if((string)attacker->query_race() == "undead")
      return (random(5) + 10);
}*/

/*int restore_me(string file) {
  ::restore_me(file);
  set_hit( (: call_other, find_object_or_load("/wizards/duridian/catacomb/weapon/bonedggr"), "weapon_hit" :) );
  return 1;
}*/

