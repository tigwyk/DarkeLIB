#include <daybreak.h>
inherit "/std/npc_shop";

void create() {
  object ob;

   ::create();
   set_name("warsten");
   set("id", ({"warsten", "shopkeeper", "shop keeper"}));
   add_money("gold", 5000);
   set_level(10);
   set_hp(200000);
   set_property("enhance criticals", -10);
   set_max_hp(200000);
   set_exp(3000000);
   set("short","Warsten, the Alchemist");
   set("long","Warsten is a slender high-elf with deep grey hair and sharp features.");
   set_gender("female");
   set_body_type("human");
   set("race", "high-elf");
   set_property("melee damage", ([ "crushing" : 99]));
   set_stats("strength", 105);
   set_stats("dexterity", 95);
   set_skill("dodge", 170);
   set_skill("parry", 180);
   set_skill("martial arts", 200);
   set_skill("perception", 70);
   set_skill("conjuration", 75);
   set_stats("intelligence", 106);
   set_languages(({"common", "stormspeak", "elvish", "yin", "dwarvish", "drow", "pix", "treefolk", "vr'krr", "middle-english","catfolk", "ogryn", "rachk", "gr'grr" }));
   set("storage room","/d/damned/guilds/nethermancer/magic_store");
   set("markup", 20);
   set_property("handedness", "right hand");
   set("no sell", 1);
   set_skill("two handed staff", 200);
   ob = new("/d/damned/virtual/quarter-staff_5.weapon");
   ob->set_property("enchantment", 5);
   set_spell_level("lightning bolt", 6);
   set_skill("elementalism", 175);
   set_spell_level("elemental storm", 6);
   add_spell("elemental storm", "");
   set_combat_chance(80);
   add_spell("lightning bolt", "$A");
   set_combat_chance(100);
   set_spell_level("explosive fireball", 6);
   add_spell("explosive fireball", "$A");
}

int query_num_rounds() { return 3; }

string query_element() { return "vacid"; }
