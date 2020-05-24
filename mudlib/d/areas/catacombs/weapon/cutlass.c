/* Weapon coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit WEAPON;
 
void create() {
   ::create();
   set_name("sharp cutlass");
   set("id", ({ "cutlass", "sharp cutlass", "sword"}) );
   set("short", "sharp cutlass");
   set("long",
   "The sharp cutlass has a short hilt and a long, slightly curved blade "
   "which is highly polished."
   );
   set_weight(200);
   set_value(750);
   set_type("blade");
   set_wc(23, "cutting");
   set_ac(5);
   set_quality(3+random(3));
   set_parry_bonus(10);
}
