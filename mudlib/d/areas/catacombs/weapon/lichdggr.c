/* Weapon coded by Duridian for DarkeMud. */

#include "std.h"
inherit WEAPON;

void create() {
   mixed str;
   ::create();
   set_name("jewel-encrusted dagger");
   set("id", ({"jewel-encrusted dagger", "dagger", "lich dagger"}) );
   set("short", "a jewel-encrusted dagger");
   set("long",
   "This very fine dagger has an nine-inch blade, with a jewel-encrusted "
   "hilt.  Emeralds, rubies, and sapphires decorate the handle of this "
   "truly amazing weapon.  The dagger tingles in your hand as you gaze "
   "at it, suggesting that perhaps this is no ordinary weapon."
   );
   set_weight(200);
   set_value(1000);
   set_type("knife");
   set_ac(7);
   set_wc(1, "electricity");
   set_wc(15, "impaling");
   set_property("no add quality", 1);
   set_quality(6);
   set_parry_bonus(10);
   set_decay_rate(800);
/*   set_property("enchantment", 1);
   str = ({ ({"This dagger glows with an unholy light.\n", "detect magic" }) });
   set_property("extra long", str);
   set_hit( (: call_other, this_object(), "weapon_hit" :) );*/
   set_material("metal/mithril");
   set_property("brittle", 10);
}
/*
int weapon_hit(object attacker) {

   if((string)attacker->query_race() == "undead") {
      if(random(3) == 0) {
         say("%^BOLD%^%^YELLOW%^Sparks fly as the jewel-encrusted dagger tears into the undead creature!");
         write("%^BOLD%^%^YELLOW%^Sparks fly as the jewel-encrusted dagger tears into the undead creature!");
      }
      return (random(10) + 10);
   }
}

int restore_me(string file) {
  ::restore_me(file);
 
 set_hit( (: call_other, find_object_or_load("/wizards/duridian/catacomb/weapon/lichdggr"), "weapon_hit" :) );
  return 1;
}
  */
