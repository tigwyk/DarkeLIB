//   Wizard:  Khojem
//   Merz - Nomad Camp Shopkeeper
//   merz.c

inherit "/std/npc_shop";

void create() {
   ::create();
   set_name("merz");
   set("id", ({"shopkeeper", "merchant", "bazaar merchant", "merz"}));
   add_money("gold", 4000);
   add_money("silver",500);
   add_money("copper",200);
   set_level(33);
   set("short","Merz, a bazaar merchant");
   set("long","Merz is a wizened, high-man female.  He looks somewhat crafty.");
   set_gender("female");
   set_body_type("human");
   set("race", "high-man");
   set_property("melee damage", ([ "crushing" : 40]));
   set_languages(({
     "common", "stormspeak", "elvish", "serra", "yin", "dwarvish", 
     "drow", "middle-english", "mountainspeak", "undead-tongue",
     "pix", "orcish", "vr'krr", "catfolk", "gr'grr", "rachk"
   }));
   set_lang_prof("common",10);
   set_lang_prof("stormspeak",9);
   set_lang_prof("elvish",9);
   set_lang_prof("serra",10);
   set_lang_prof("yin",9);
   set_lang_prof("dwarvish",9);
   set_lang_prof("drow",9);
   set_lang_prof("middle-english",10);
   set_lang_prof("mountainspeak",8);
   set_lang_prof("undead-tongue",10);
   set_lang_prof("pix",10);
   set_lang_prof("orcish",8);
   set_lang_prof("vr'krr",9);
   set_lang_prof("catfolk",9);
   set_lang_prof("gr'grr",9);
   set_lang_prof("rachk",10);
   set("storage room","/d/khojem/nomad/camp/shop_store3");
   set("markup", 200);
}
