//   Wizard:  Khojem
//   Barkfir
//   barkfir.c

inherit "/std/npc_shop";

void create() {
   object money;
   ::create();
   set_name("barkfir");
   set("id", ({"shopkeeper", "shop keeper", "bark"}));
   set_level(10);
   set("short","Barkfir, the Fresh Grocer");
   set("long","Barkfir is a graying Wood-Elf who enjoys his work.");
   set_gender("male");
   set_body_type("human");
   set("race", "wood-elf");
   set_property("melee damage", ([ "crushing" : 20]));
   set_skill("melee", 40);
   set_skill("attack", 40);
   set_skill("dodge", 40);
   set_overall_ac(6);
   set_skill("perception", 75);
   set_languages(({"common", "stormspeak", "elvish", "serra", "yin",
     "catfolk",
     "dwarvish", "drow", "middle-english", "mountainspeak" }));
   set_lang_prof("catfolk",10);
   set_lang_prof("stormspeak",8);
   set_lang_prof("elvish",10);
   set_lang_prof("serra",8);
   set_lang_prof("yin",8);
   set_lang_prof("dwarvish",9);
   set_lang_prof("drow",10);
   set_lang_prof("middle-english",7);
   set_lang_prof("mountainspeak",8);
   set("storage room","/d/khojem/new/shop/barkfir_store");
   set("markup", 120);
   money=new("std/obj/coins");
   money->set_money("gold", 50);
   money->move(this_object());

}
