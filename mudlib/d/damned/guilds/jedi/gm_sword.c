#include <move.h>
#include <std.h>

inherit "/std/lightsaber";
inherit AUTOLOAD;
  
void create() {
    ::create();
    set_saber(34);
    set("id", ({ "saber", "lightsaber", "lightsaber of the guildmaster" }));
    set("long","This beautiful lightsaber was crafted by Luke Skywalker himself!");
    set_weight(120);
    set_wc(35, "cutting");
    set_wc(18, "impaling");
    set_type("blade");
    set_quality(6);
    set_property("no add quality", 1);
    set_property("no decay", 1);
    set_property("brittle", 15);
    set_wc(20, "fire");
    set_ac(20);
    set_parry_bonus(20);
    set_property("enchantment", 20);
    set_wield((: call_other,this_object(), "make_me_gm" :));
    set_enh_critical(2);
    set_value(132);
    set_material("metal/mabril");
   return;
}

int query_always_keep() { return 1; }
int make_me_gm() {
object ob;

  seteuid(getuid());
  ob= new("d/damned/guilds/jedi/jedi_obj");
  ob->make_me_master(this_player());
  return 1;
}


