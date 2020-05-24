#include <move.h>



inherit "/std/weapon";



  

void create() {

    ::create();

    set("id", ({ "sword", "death knight sword" }));

    set_name("sword");

    set("short", "The Sword of Death Knights");

    set("long",

"This sword is enchanted to give deathknights the life force of their "

"vistims, but will not work with the living.");

    set_weight(250);

    set_type("two handed blade");

    set_wc(23, "cutting");

    set_wc(7, "impaling");

    set_ac(10);

    set_parry_bonus(-4);

    set_quality(4);

    set_property("no add quality", 1);

    set_property("no add quality", 1);

    set_property("no decay", 1);

    set_decay_rate(1500);

    set_hit((: call_other, this_object(), "life_steal" :));

    set_property("enchantment", 3);

    set_value(3500);

   return;

}



int life_steal(object who) {

  object knight;

  int roll;

  

  if(!(knight=query_wielded())) return 0;

  if((string)knight->query("race") != "undead") return 0;

  if(!who) return 0;

  roll = 2 + random(6) + random(6);

  who->add_hp(-1*roll);

  knight->add_hp(roll);

  return 0;

}

