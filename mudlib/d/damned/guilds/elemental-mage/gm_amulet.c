#include <move.h>
#include <std.h>

inherit "/std/armour";
inherit AUTOLOAD;
  
void create() {
    ::create();
    set("id", ({ "amulet", "necklace" }));
    set_name("amulet");
    set("short", "The Amulet of the Elemental-mage");
    set("long",
	"This ornate amulet can provide protection from %^RED%^%^BOLD%^"
	"fire, %^YELLOW%^earth, %^CYAN%^air,%^RESET%^ and%^BLUE%^%^BOLD%^ "
	"water.%^RESET%^");
    set_limbs(({"head", "torso"}));
    set_weight(25);
    set_ac(1);
    set_ac(70, "cold");
    set_ac(70, "fire");
    set_ac(70, "vacuum");
    set_ac(70, "impact");
    set_wear((: call_other,this_object(), "make_me_gm" :));
    set_enh_critical(-1);
    set_value(50000);
   return;
}

int query_always_keep() { return 1; }
int make_me_gm() {
object ob;

  seteuid(getuid());
  ob= new("d/damned/guilds/elemental-mage/elemental-mage_obj");
  ob->make_me_master(this_player());
  return 1;
}


