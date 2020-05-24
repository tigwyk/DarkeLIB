// elven slayer

#include "mansion.h"
inherit WEAPON;

void create() {
   mixed str;
   ::create();
   set_name("elven slayer");
   set("id", ({ "sword", "slayer"}) );
   set("short", "An elven slayer");
   set("long",
   "This is a standard issue sword for elite elven rangers.  "+
   "It is a well crafted sabre with frost covering it's hilt."
   );
   set_verb("hack");
   set_weight(200);
   set_value(1500);
   set_wc(5, "cold");
   set("skill level",100);
   set_property("icy weapon", 1);
   set_property("no add quality", 1);
   set_wield("You grasp the cold handle with a slight shiver.");
   set_unwield("You feel warm again as you sheath the sword.");
   set_type("blade");
   set_wc(25, "cutting");
   set_wc(15, "impaling");
   set_ac(5);
   set_quality(5);
   set_property("brittle", 80); 
   set_parry_bonus(5);
   set_material("metal/javednite");
   TO->set_decay_rate(TO->prop("hardness"));
}
