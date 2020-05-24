#include <move.h>



inherit "/std/weapon";



object shad;

  

void create() {

    ::create();

    set("id", ({ "staff", "holy staff" }));

    set_name("staff");

    set("short", "A holy staff");

    set("long",

"This staff is crafted of fine, light wood, and glows with a faint "

"white aura.  It is covered in religious runes.");

    set_weight(70);

    set_type("two handed holy");

    set_wc(28, "crushing");

    set_wc(18, "holy");

    set_ac(10);

    set_property("no save", 1);

    set_parry_bonus(5);

    set_quality(4);

    set_property("no add quality", 1);

    set_property("no decay", 1);

    set_decay_rate(1500);

    set_unwield((: call_other, this_object(), "unwield_me" :));

    set_auto_critical(([ "holy A" : 5 ]));

    set_property("enchantment", 3);

    set_value(0);

   return;

}



int unwield_me() {

  remove_delayed_call("dest_me");

  delayed_call("dest_me", 1);

  return 1;

}



int drop() {

  remove_delayed_call("dest_me");

  delayed_call("dest_me", 3);

  return 0;

}



void set_dur(int dur) {

  delayed_call("dest_me", dur);

  return;

}



void dest_me() {

  if(environment())

    message("info", "%^BOLD%^The holy staff disappears.",

      environment());

  if(shad) shad->external_destruct(shad);

  remove();

  return;

}



void set_shadow(object ob) {

  shad = ob;

}

