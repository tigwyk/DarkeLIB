// /d/damned/guilds/necromancer/
// Zephlen 99

#include <std.h>

inherit WEAPON;
inherit AUTOLOAD;

create() {
    ::create();
    set_ac(30);
    set_name("dagger");
    set("id", ({ "dagger", "Robed Dagger", "Dagger", "robed dagger" }));
set("short", "The Lifeless Robed Dagger");
set("long", "As though this dagger pears to be like one you never seen before, you hear the screams of undead soldiers from the relm.  It appears to be glowing, the glow of darkness.");
    set_type("knife");
    set_quality(6);
    set_property("no add quality",1);
    set_property("no decay", 1);
    set_wc(15,"cutting");
    set_wc(27, "impact");
    set_verb("stab");
    set_parry_bonus(-10);
    set_property("hit bonus", 15);
    set_wield( (: call_other, this_object(), "make_me_gm" :) ); 
    set_property("hit bonus", 25);
    set_property("enchantment",27);
    set_enh_critical(1);
    set_material("metal/mithril");
    set_weight(45);
    set_value(982);
    return;
}

int query_always_keep() { return 1; }
int query_poisoning() { return 35; }

int make_me_gm() {
  object ob;

  //  the function below will handle all necessary checking, etc.
  seteuid(getuid());
  ob = new("/d/damned/guilds/nethermancer/nethermancer_obj");
  ob->make_me_master(this_player());
  return 1;
}
