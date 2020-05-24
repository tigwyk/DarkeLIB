/* Armor coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ARMOR;
 
void create() {
   ::create();
   set_name("kobold helmet");
   set("id", ({"helm", "helmet", "kobold helmet", "kobold helm"}) );
   set("short", "kobold helmet");
   set("long",
   "The small kobold helmet is dented all over and is well-beaten.  It "
   "is made of iron and feels quite heavy."
   );
   set_type("helmet");
   set_ac(0, "aether");
   set_ac(0, "depression");
   set_ac(1, "acid");
   set_ac(1, "vacuum");
   set_ac(3, "fire");
   set_ac(3, "cold");
   set_ac(5, "impact");
   set_ac(5, "stress");
   set_ac(5, "strike");
   set_ac(5, "cutting");
   set_ac(5, "impaling");
   set_ac(0, "electricity");
   set_ac(0, "time");
   set_ac(5, "crushing");
   set_ac(3, "disruption");
   set_ac(0, "holy");
   set_ac(2, "plasma");
   set_ac(2, "infernal");
   set_limbs( ({"head"}) );
   set_weight(200);
   set_value(50);
}
