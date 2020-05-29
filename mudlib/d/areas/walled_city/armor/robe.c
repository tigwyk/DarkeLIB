/* Armor coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit ARMOR;
 
void create() {
   ::create();
   set_name("kobold robe");
   set("id", ({"kobold robe", "robe"}) );
   set("short", "kobold robe");
   set("long",
   "The dirty robe is very long and reaches to the ground.  It would "
   "probably only provide minimal protection from both the environment "
   "and from attackers."
   );
   set_type("armour");
   set_material("misc/wool");
   set_ac(1, "aether");
   set_ac(2, "depression");
   set_ac(3, "acid");
   set_ac(2, "vacuum");
   set_ac(3, "fire");
   set_ac(3, "cold");
   set_ac(2, "impact");
   set_ac(2, "stress");
   set_ac(1, "strike");
   set_ac(6, "cutting");
   set_ac(6, "impaling");
   set_ac(0, "electricity");
   set_ac(0, "time");
   set_ac(2, "crushing");
   set_ac(2, "disruption");
   set_ac(3, "holy");
   set_ac(1, "plasma");
   set_ac(0, "infernal");
   set_limbs( ({"torso", "right arm", "left arm"}) );
   set_weight(200);
   set_value(40);
}
