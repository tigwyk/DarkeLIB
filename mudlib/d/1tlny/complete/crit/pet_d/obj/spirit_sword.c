#include <move.h>



inherit "/std/weapon";



object shad;

  

void create() {

    ::create();

    set("id", ({ "sword", "sword of spirit", "spirit sword", 

		   "sword of the spirit" }));

    set_name("sword");

    set("short", "The Sword of the Spirit");

    set("long",

"This sword is crafted of a brilliant shiny metal, almost unearthly "

"it its quality.");

    set_weight(70);

    set_type("holy");

    set_wc(25, "cutting");

    set_wc(8, "impaling");

    set_wc(24, "holy");

    set_ac(10);

    set_parry_bonus(10);

    set_property("no save", 1);

    set_quality(4);

    set_property("no add quality", 1);

    set_property("no decay", 1);

    set_decay_rate(1500);

    set_unwield((: call_other, this_object(), "unwield_me" :));

    set_auto_critical(([ "holy B" : 6 ]));

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

    message("info", "%^BOLD%^The Sword of the Spirit disappears.",

      environment());

  if(shad) shad->external_destruct(shad);

  remove();

  return;

}



void set_shadow(object ob) {

  shad = ob;

}

