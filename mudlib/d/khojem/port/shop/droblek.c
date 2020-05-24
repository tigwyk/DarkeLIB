//   Wizard:  Khojem
//   Droblek
//   droblek.c

inherit "/std/npc_shop";

void create() {
   object money;
   ::create();
   set_name("Droblek");
   set("id", ({"shopkeeper", "shop keeper", "droblek"}));
   set_exp(4000);
   set_level(25);
   set("short","Droblek");
   set("long","Droblek stands intently waiting to attend to your needs.");
   set_gender("male");
   set_body_type("human");
   set("race", "high-elf");
   set_property("melee damage", ([ "impact" : 60]));
   set_property("enhance criticals", -10);
   set_skill("martial arts", 50);
   set_skill("perception", 95);
   set_languages(({"common", "stormspeak", "elvish", "serra", "yin",
     "dwarvish", "drow", "pix", "treefolk", "vr'krr", "middle-english",
     "catfolk", "hisaaa", "ogryn", "gnollish" }));
   set("storage room","/d/khojem/port/shop/droblek_store");
   set("markup", 50);
   set_skill("elementalism", 75);
   set_spell_level("elemental storm", 6);
   add_spell("elemental storm", "");
   set_combat_chance(80);
   money=new("std/obj/coins");
   money->set_money("gold", 3000);
   money->move(this_object());
   money->set_money("silver",200);
   money->move(this_object());
   set("num rounds", 2);
}
