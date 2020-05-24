/* Armor coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ARMOUR;
 
void create() {
   ::create();
   set_name("bone shield");
   set("id", ({ "shield", "large shield", "bone shield"}) );
   set("short", "bone shield");
   set("long",
   "This rather large shield is made of fragments of bone embedded in "
   "tough steel.  It would provide any adventurer with great protection."
   );
   set_type("shield");
   set_ac(7, "aether");
   set_ac(7, "depression");
   set_ac(5, "acid");
   set_ac(5, "vacuum");
   set_ac(5, "fire");
   set_ac(5, "cold");
   set_ac(17, "impact");
   set_ac(10, "stress");
   set_ac(10, "strike");
   set_ac(17, "cutting");
   set_ac(17, "impaling");
   set_ac(7, "electricity");
   set_ac(7, "time");
   set_ac(17, "crushing");
   set_ac(7, "disruption");
   set_ac(7, "holy");
   set_ac(7, "plasma");
   set_ac(7, "infernal");

   set_limbs( ({ ({"right hand", "left hand", "first branch", "second branch",
                "third branch", "fourth branch"}) }) );
   set_weight(175);
   set("value", 977);
}
