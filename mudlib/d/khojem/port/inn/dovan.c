// Khojem
// Dovan, Vo'Sangor Chest Guy
// dovan.c

inherit "/std/npc_shop";

void create() {
   ::create();
   set_name("dovan");
   set("id", ({"dovan", "shopkeeper", "shop keeper"}));
   add_money("gold", 5000);
   set_level(10);
   set_property("enhance criticals", -10);
   set_hp(200000);
   set_max_hp(200000);
   set_exp(10000);
   set("short","Dovan, the likes to build chests!");
   set("long",
    "Dovan is a dull little guy.  He is one notch up from shoe salesman.");
   set_skill("elementalism", 175);
   set_spell_level("elemental storm", 6);
   add_spell("elemental storm", "$A");
   set_combat_chance(90);
   set_gender("male");
   set_body_type("human");
   set("race", "dwarf");
   set_overall_ac(666);
   set_stats("strength", 305);
   set_stats("dexterity", 95);
   set_skill("dodge", 170);
   set_skill("parry", 180);
   set_skill("martial arts", 50);
   set_skill("perception", 70);
   set_languages(({"common", "stormspeak", "elvish", "yin", "dwarvish",
                "drow", "pix", "treefolk", "vr'krr", "middle-english",
                            "catfolk", "ogryn", "rachk", "gr'grr" }));
   set("storage room","/d/khojem/port/inn/chest_store");
   set("markup", 20);
   set_property("handedness", "right hand");
   set("no sell", 1);
}

int query_num_rounds() { return 3; }

string query_element() { return "vacid"; }

