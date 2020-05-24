
#include "../ruins.h"
#include "../ruins.h"
inherit "/std/npc_shop";

void create() {
   ::create();
   set_name("shein");
   set("id", ({"shopkeeper", "shop keeper", "shein"}));
add_money("mithril", 350);
set_level(30);
   set_exp(500);
   set_max_hp(90000000);
   set_hp(90000000);
   set_property("enhance criticals", -10);
   set_property("melee damage", ([ "crushing" : 99]));
set("storage room",(ROOMS+"shop1_store"));
   set("short","Shein, the shopkeeper");
   set("long", "Shein is anything but.  She is a slander female with an
magic grin.  She looks like she wants to sell you things.");
   set_gender("male");
   set_body_type("human");
   set("race", "high-man");
   set_skill("elementalism", 75);
   set_spell_level("elemental storm", 6);
   add_spell("elemental storm", "");
   set_combat_chance(80);
   set_skill("dodge", 70);
   set_skill("parry", 80);
   set_skill("martial arts", 50);
   set_skill("perception", 95);
   set_languages(({"common", "stormspeak", "elvish", "serra", "yin",
"dwarvish", "drow", "pix", "treefolk", "vr'krr", "middle-english",
"catfolk","undead-tongue", "hisaaa", "ogryn", "ratish" }));
   set_stats("dexterity", 150);
   set_stats("strength", 200);
   set("num rounds", 2);
   set("markup", 50);
}

