/* Weapon coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit WEAPON;
 
void create() {
   ::create();
   set_name("kobold dagger");
   set("id", ({"dagger", "kobold dagger"}) );
   set("short", "kobold dagger");
   set("long",
   "The kobold dagger has a scratched hilt and its blade is pretty dull.  "
   "It does not look very useful or very valuable."
   );
   set_weight(100);
   set_value(25);
   set_type("knife");
   set_wc(7, "impaling");
   set_ac(1);
   set_quality(3);
   set_parry_bonus(-15);
   set_throwable(1);
}
