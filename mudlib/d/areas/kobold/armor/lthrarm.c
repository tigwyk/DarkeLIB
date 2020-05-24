/* Armor coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ARMOR;
 
void create() {
   ::create();
   set_name("kobold leather armor");
   set("id", ({"kobold leather", "leather armor", "leather",
               "kobold leather armor", "armor", "studded leather",
               "studded leather armor",}) );
   set("short", "kobold leather armor");
   set("long",
   "The studded leather armor is very stiff and well-made.  It feels quite "
   "light, as far as armor goes.  The leather itself is in pretty good "
   "shape, dried and cracked in only a few places."
   );
   set_type("armour");
   set_ac(2, "aether");
   set_ac(6, "depression");
   set_ac(3, "acid");
   set_ac(4, "vacuum");
   set_ac(3, "fire");
   set_ac(3, "cold");
   set_ac(2, "impact");
   set_ac(1, "stress");
   set_ac(1, "strike");
   set_ac(10, "cutting");
   set_ac(10, "impaling");
   set_ac(10, "electricity");
   set_ac(2, "time");
   set_ac(2, "crushing");
   set_ac(2, "disruption");
   set_ac(3, "holy");
   set_ac(4, "plasma");
   set_ac(4, "infernal");
   set_material("misc/leather");
   set_limbs( ({"torso", "right arm", "left arm"}) );
   set_weight(275);
   set_value(125);
}
