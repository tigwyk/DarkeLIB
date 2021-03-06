#include <move.h>



inherit "/std/weapon";



object shad;



void create() {

    ::create();

    set("id", ({ "hammer", "hammer of faith" }));

    set_name("hammer");

    set("short", "The Hammer of Faith");

    set("long",

"This is a huge, but impossibly light, warhammer with a "

"white and gold shaft.");

    set_weight(70);

    set_type("two handed holy");

    set_wc(40, "impact");

    set_wc(30, "holy");

    set_ac(10);

    set_parry_bonus(10);

    set_property("no save", 1);

    set_quality(4);

    set_property("no add quality", 1);

    set_property("no decay", 1);

    set_decay_rate(1500);

    set_unwield((: call_other, this_object(), "unwield_me" :));

    set_auto_critical(([ "holy C" : 6 ]));

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



int drop() {

  remove_delayed_call("dest_me");

  delayed_call("dest_me", 3);

  return 0;

}



void dest_me() {

  if(environment())

    message("info", "%^BOLD%^The Hammer of Faith disappears.",

      environment());

  if(shad) shad->external_destruct(shad);

  remove();

  return;

}



void set_shadow(object ob) {

  shad = ob;

}

