
#include "../ruins.h"
inherit "/std/npc_shop";

void create() {
  object ob;

   ::create();
   set_name("opis");
   set("id", ({"opis armour", "opis armour smith", "shopkeeper", "shop
keeper", "opis"}));
 add_money("mithril", 500);
set_level(30);
   set_exp(300);
   set_property("enhance criticals", -10);
   set_hp(90000);
   set_max_hp(90000);
   set("short","Opis Armour smith, the shopkeeper");
   set("long", "Opis Armour smith is a young male dwarf.  His skin is
leathery, and his muscles have been hardened by years of shaping metal.");
   set_gender("male");
   set_body_type("human");
   set("race", "dwarf");
set("storage room",(ROOMS+"shop2_store"));
   set_property("melee damage", ([ "crushing" : 99]));
set_skill("choas lore", 85);
   set_skill("elementalism", 120);
   set_spell_level("elemental storm", 6);
   add_spell("elemental storm", "");
   set_combat_chance(80);
   set_stats("strength", 105);
   set_stats("dexterity", 95);
   set_skill("two handed polearm", 90);
   set_skill("dodge", 70);
   set_skill("parry", 80);
   set_skill("martial arts", 50);
   set_skill("perception", 90);
   set_languages(({"common", "stormspeak", "elvish", "serra", "yin",
"dwarvish", "drow", "pix", "treefolk", "vr'krr", "middle-english",
"catfolk", "ogryn", "ratish" }));
   set("markup", 60);
   set_property("handedness", "right hand");
   set("no sell", 0);
   set("pre sell function", (: call_other, this_object(), "only_armour" :));
   ob = new("/d/damned/virtual/breast-plate.armour");
   ob->move(this_object());
   ob = new("d/damned/virtual/studded-leather-glove.armour");
   ob->move(this_object());
   ob = new("d/damned/virtual/studded-leather-glove.armour");
   ob->move(this_object());
   ob = new("d/damned/virtual/leather-pants.armour");
   ob->move(this_object());
   force_me("wear breast plate");
   force_me("wear glove on left hand");
   force_me("wear glove 2 on right hand");
   force_me("wear pants");
}
string only_weapon(object item) {
  if(!item->is_armour()) return "I only buy armour.";
  return 0;
}
