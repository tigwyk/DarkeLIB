//   Wizard:  Khojem
//   Akmed - Nomad Camp Shopkeeper
//   akmed.c

inherit "/std/npc_shop";

void create() {
   ::create();
   set_name("akmed");
   set("id", ({"shopkeeper", "shop keeper", "akmed", "merchant", "bazaar merchant"}));
   add_money("gold", 2000);
   add_money("silver",2000);
   add_money("copper",500);
   set_level(35);
   set("short","Akmed, a bazaar merchant");
   set("long","Akmed is a thin, spindley high-man.  His teeth are "+
     "stained from repeated use of chewing tobacco.");
   set_gender("male");
   set_body_type("human");
   set("race", "high-man");
   set_property("melee damage", ([ "crushing" : 40]));
   set_languages(({
     "common", "stormspeak", "elvish", "serra", "yin", "dwarvish", 
     "drow", "middle-english", "mountainspeak", "undead-tongue",
     "pix", "orcish", "vr'krr", "catfolk", "gr'grr", "rachk"
   }));
   set_lang_prof("common",10);
   set_lang_prof("stormspeak",8);
   set_lang_prof("elvish",9);
   set_lang_prof("serra",10);
   set_lang_prof("yin",10);
   set_lang_prof("dwarvish",9);
   set_lang_prof("drow",9);
   set_lang_prof("middle-english",8);
   set_lang_prof("mountainspeak",8);
   set_lang_prof("undead-tongue",10);
   set_lang_prof("pix",10);
   set_lang_prof("orcish",8);
   set_lang_prof("vr'krr",9);
   set_lang_prof("catfolk",9);
   set_lang_prof("gr'grr",9);
   set_lang_prof("rachk",10);
   set("storage room","/d/khojem/nomad/camp/shop_store");
   set("markup", 220);
}
