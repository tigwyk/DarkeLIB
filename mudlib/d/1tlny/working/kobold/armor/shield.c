/* Armor coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit ARMOR;
 
void create() {
   ::create();
   set_name("kobold shield");
   set("id", ({"shield", "kobold shield"}) );
   set("short", "kobold shield");
   set("long",
   "The dented iron kobold shield will provide protection from only the "
   "weakest of attacks.  There are several deep gashes on the face of "
   "shield, indicating that a previous owner engaged in combat with a "
   "fierce opponent."
   );
   set_type("shield");
   set_limbs( ({ ({"right hand", "left hand", "first branch", "second branch",
                   "third branch", "fourth branch"}) }) );
   set_ac(2, "aether");
   set_ac(6, "depression");
   set_ac(5, "acid");
   set_ac(1, "vacuum");
   set_ac(5, "fire");
   set_ac(5, "cold");
   set_ac(5, "impact");
   set_ac(3, "stress");
   set_ac(3, "strike");
   set_ac(8, "cutting");
   set_ac(8, "impaling");
   set_ac(2, "electricity");
   set_ac(0, "time");
   set_ac(2, "crushing");
   set_ac(0, "disruption");
   set_ac(4, "holy");
   set_ac(3, "plasma");
   set_ac(2, "infernal");
   set_weight(300);
   set_value(75);
}
