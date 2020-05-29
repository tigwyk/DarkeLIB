/* Armor coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit ARMOR;
 
void create() {
   ::create();
   set_name("chainmail");
   set("id", ({"chainmail", "chain", "chainmail","armor"}) );
   set("short", "chainmail");
   set("long",
   "This chainmail is in pretty good shape, surprisingly.  It looks "
   "like it would provide ample protection for the wearer."
   );
   set_type("armour");
   set_ac(5, "aether");
   set_ac(5, "depression");
   set_ac(5, "acid");
   set_ac(5, "vacuum");
   set_ac(15, "fire");
   set_ac(5, "cold");
   set_ac(30, "impact");
   set_ac(30, "stress");
   set_ac(40, "strike");
   set_ac(20, "cutting");
   set_ac(22, "impaling");
   set_ac(0, "electricity");
   set_ac(5, "time");
   set_ac(35, "crushing");
   set_ac(5, "disruption");
   set_ac(5, "holy");
   set_ac(5, "plasma");
   set_ac(5, "infernal");
   set_limbs( ({"torso", "right arm", "left arm"}) );
   set_weight(400);
   set_value(200);
}
