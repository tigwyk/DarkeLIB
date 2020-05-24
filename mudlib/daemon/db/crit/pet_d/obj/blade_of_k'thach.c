#include <move.h>



inherit "/std/weapon";



object shad;

  

void create() {

    ::create();

    set("id", ({ "sword", "blade", "blade of k'thach" }));

    set_name("blade");

    set("short", "The Blade of K'thach");

    set("long",

"This is a truly impressive two-handed blade.  The hilt is gold "

"and encrusted with jewels.  The blade, which is surprisingly light "

"despite its 5 foot length, reflects the sun brilliantly.");

    set_weight(70);

    set_type("two handed holy");

    set_wc(40, "cutting");

    set_wc(15, "impaling");

    set_wc(40, "holy");

    set_ac(15);

    set_parry_bonus(5);

    set_quality(4);

    set_property("no save", 1);

    set_property("no add quality", 1);

    set_property("no decay", 1);

    set_decay_rate(1500);

    set_unwield((: call_other, this_object(), "unwield_me" :));

    set_auto_critical(([ "holy D" : 5 ]));

    set_property("enchantment", 8);

    set_value(0);

   return;

}



int unwield_me() {

  remove_delayed_call("dest_me");

  delayed_call("dest_me", 1);

  return 1;

}



void set_dur(int dur) {

  delayed_call("dest_me", dur);

  return;

}



void dest_me() {

  if(environment())

    message("info", "%^BOLD%^The Blade of K'thach disappears.",

      environment());

  if(shad) shad->external_destruct(shad);

  remove();

  return;

}



void set_shadow(object ob) {

  shad = ob;

}



int drop() {

  remove_delayed_call("dest_me");

  delayed_call("dest_me", 3);

  return 0;

}

