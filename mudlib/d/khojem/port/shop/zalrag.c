// Wizard:  Khojem
// zalrag the magic shopkeeper
// zalrag.c

inherit "/std/npc_shop";

void create() {
  object ob;

   ::create();
   set_name("zalrag");
   set("id", ({"zalrag", "shopkeeper", "shop keeper"}));
   ob=new("std/obj/coins");
   ob->set_money("gold",300);
   ob->move(this_object());
   ob=new("std/obj/coins");
   ob->set_money("silver",2000);
   ob->move(this_object());
   set_level(10);
   set_exp(4000);
   set("short","Zalrag, the Alchemist");
   set("long",
    "Zalrag is a slender high-elf with deep grey hair and sharp features.");
   set_gender("male");
   set_body_type("human");
   set("race", "high-elf");
   set_property("melee damage", ([ "crushing" : 40]));
   set_skill("perception", 70);
   set_skill("conjuration", 75);
   set_stats("intelligence", 106);
   set_languages(({"common", "stormspeak", "elvish", "yin", "dwarvish",
     "drow", "pix", "treefolk", "vr'krr", "middle-english",
     "gnollish", "zebber", "lithic", "serra", "sylvan",
     "catfolk", "ogryn", "rachk", "gr'grr" }));
   set("storage room","/d/khojem/port/shop/zalrag_store");
   set("markup", 20);
   set("no sell",1);
   set_property("handedness", "right hand");
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

