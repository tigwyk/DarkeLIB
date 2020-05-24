#include <std.h>

inherit WEAPON;
inherit AUTOLOAD;


create() {
    ::create();
    set_ac(20);
    set_name("backbiter");
set("id", ({ "sword", "guildmaster sword", "backbiter", "sword of the guildmaster" }));
    set("short", "The Backbiter, sword of the Guildmaster");
    set("long", 
"This is a long, thin, one handed blade fashioned of some dark metal.  "
"It radiates various magical auras, and is extremely light for its size.");
set_type("blade");
    set_quality(6);
    set_property("no add quality",1);
    set_decay_rate(2000);
    set_material("/metal/iysaughton");
    set_wc(23,"cutting");
    set_wc(15, "impaling");
    set_verb("slice");
    set_parry_bonus(20);
    set_property("hit bonus", 25);
    set_wield( (: call_other, this_object(), "make_me_gm" :) );
    set_unwield( (: call_other, this_object(), "remove_bonus" :) );
    set_property("enchantment",20);
    set_enh_critical(1);
    set_weight(45);
    set_value(982);
    return;
}

int query_always_keep() { return 1; }

int query_poisoning(){return 35;}


int remove_bonus() {
  this_player()->add_skill_bonus("back stab", -30);
  this_player()->add_skill_bonus("assassination", -20);
  return 1;
}

int make_me_gm() {
  object ob;

  this_player()->add_skill_bonus("back stab", 30);
  this_player()->add_skill_bonus("assassination", 20);
  write("You feel as though your back stab and assassination skills are increased.");
  //  the function below will handle all necessary checking, etc.
  seteuid(getuid());
  ob = new("/d/damned/guilds/assassin/assassin_obj");
  ob->make_me_master(this_player());
  return 1;
}


