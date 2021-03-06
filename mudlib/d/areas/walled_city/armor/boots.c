/* Armor coded by Duridian for DarkeMud. */
 
#include <std.h>

inherit "/std/armour";
//inherit ARMOR;
 
void create() {
   ::create();
   set_name("metal boots");
   set("id", ({"metal boots", "boots"}) );
   set("short", "iron boots");
   set("long",                               
   "The pair of iron boots are well-used and dusty.  They are "
   "dented and cracked places, and rusty on the soles."
   );
   set_type("boot");
   set_material("misc/iron");
   set_ac(0, "aether");
   set_ac(0, "depression");
   set_ac(1, "acid");
   set_ac(1, "vacuum");
   set_ac(3, "fire");
   set_ac(3, "cold");
   set_ac(2, "impact");
   set_ac(1, "stress");
   set_ac(1, "strike");
   set_ac(5, "cutting");
   set_ac(5, "impaling");
   set_ac(0, "electricity");
   set_ac(0, "time");
   set_ac(2, "crushing");
   set_ac(0, "disruption");
   set_ac(0, "holy");
   set_ac(0, "plasma");
   set_ac(0, "infernal");
   set_limbs( ({"left foot", "right foot"}) );
   set_weight(200);
   set_value(50);
}
