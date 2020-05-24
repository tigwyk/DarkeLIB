/* Weapon coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit WEAPON;
 
void create() {
   mixed str;
   ::create();
   set_name("bone shortsword");
   set("id", ({ "sword", "shortsword", "bone shortsword"}) );
   set("short", "bone shortsword");
   set("long",
   "This shortsword has a short hilt made of bone and an iron blade "
   "that is about half a meter long.",
   );
   set_weight(150);
   set_value(750);
   set_type("blade");
   set_wc(15, "cutting");
   set_ac(1);
   set_quality(3+random(3));
   set_parry_bonus(10);
   set_property("enchantment", 1);
   str = ({ ({"This sword glows with an unholy light.", "detect magic" }) });
   set_property("extra long", str);
}
 
int weapon_hit(object attacker) {
   if((string)attacker->query_race() == "undead")
      return (random(5) + 5);
}
