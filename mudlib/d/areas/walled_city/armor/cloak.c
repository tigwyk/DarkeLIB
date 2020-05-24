/* Armor coded by Duridian for DarkeMud. */
 
#include <std.h>

inherit "/std/armour";
//inherit ARMOR;
 
void create() {
   ::create();
   set_name("kobold cloak");
   set("id", ({"kobold cloak", "cloak"}) );
   set("short", "kobold cloak");
   set("long",
   "This long, hooded cloak is covered in dust and mud.  Patches of "
   "bright green and red cloth peek between blobs of dirt."
   );
   set_type("cloak");
   set_material("misc/cloth");
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
   set_limbs( ({"torso"}) );
   set_weight(100);
   set_value(35);
}
