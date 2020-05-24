#include <move.h>



inherit "/std/weapon";



  

void create() {

    ::create();

    set("id", ({ "sword", "sword of the spirit", "sword of spirit" }));

    set_name("sword");

    set("short", "The Sword of the Spirit");

    set("long",

"This is a radiant blade crafted of an unearthly pearly metal.  "

"You cannot tell if it is merely reflective or if it emits its own light.");

    set_weight(250);

    set_type("two handed blade");

    set_wc(23, "cutting");

    set_wc(7, "impaling");

    set_wc(25, "holy");

    set_ac(10);

    set_parry_bonus(-4);

    set_quality(4);

    set_property("no add quality", 1);

    set_property("no decay", 1);

    set_decay_rate(1500);

    set_wield((: call_other, this_object(), "check_angel" :));

    set_property("enchantment", 3);

    set_value(3500);

   return;

}



int check_angel() {

  if((string)this_player()->query_race() != "angel" &&

        (string)this_player()->query_race() != "seraph") {

    write("Only the holy may wield this sword!");

    return 0;

  }

  write("You feel an aura of holiness upon wielding the sword.");

  return 1;

}

