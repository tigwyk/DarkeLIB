#include <security.h>



inherit "/std/weapon";



create() {

    ::create();

    set_ac(20);

    set("id", ({ "sword", "skull sword" }));

    set("short", "The Skull Sword of Diewarzau");

    set("long", "This is a very impressive weapon.  The blade is "

	"crafted of an unearthly dull grey metal, and the hilt is "

	"encrusted with tiny skulls whose eyes glow deep red.  ");

    set_type("blade");

    set_quality(6);

    set_property("no decay",1);

    set_property("no add quality",1);

    set_wc(30,"cutting");

    set_hit((: call_other, this_object(), "dest_it" :) );

    set_verb("slice");

    set_parry_bonus(10);

    set_property("enchantment",10);

    set_enh_critical(4);

    set_weight(200);

    set_value(143060);

    return;

}



int dest_it(object who) {

  if(random(10) > 3) return 1;

  message("info", "The Skull Sword DESTROYS YOU!", who);

  message("info", "%^RED%^%^BOLD%^The Skull Sword DESTROYS "+

    (string)who->query_cap_name()+"!", environment());

  seteuid(UID_ROOT);

  destruct(who);

  seteuid(getuid());

  return 10;

}

