/* Weapon coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit WEAPON;
 
void create() {
   ::create();
   set_name("kobold spear");
   set("id", ({"spear", "kobold spear"}) );
   set("short", "kobold spear");
   set("long",
   "The kobold spear has a long handle and short blade at one end.  It is "
   "most likely used for hunting the rabbits and other wildlife that "
   "populate the kobold hills."
   );
   set_weight(200);
   set_value(100);
   set_type("two handed polearm");
   set_wc(10, "impaling");
   set_ac(2);
   set_quality(3);
   set_parry_bonus(15);
   set_material("wood/wood");
   set_throwable(1);
}
