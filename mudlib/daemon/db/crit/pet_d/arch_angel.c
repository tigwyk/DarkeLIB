inherit "/std/pet";

void create() {
  string tmp;

  ::create();
  set_name("angel");
  set_id(({ "angel", "arch angel", "ethereal" }));
  set("race", "ethereal");
  set_body_type("winged_humanoid");
  set_languages(({ "common", "serra", "treefolk", "catfolk", "elvish",
                "dwarvish", "stormspeak", }) );
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(18);
  switch(random(4)) {
  case 0:
    tmp = "radiant ";
    break;
  case 1:
    tmp = "beautiful ";
    break;
  case 2:
    tmp = "divine ";
    break;
  case 3:
    tmp = "celestial ";
    break;
  }
  set_short(tmp+"Arch Angel");
  set_gender("female");
  set_long(
"The Arch Angel is perhaps one of the most incredible beings you have ever "
"seen.  She looks down upon you ominously, and divine power radiates from "
"her.");
  set_property("physical resistance",
	       ([ "default" : 30, "iron" : 30, "steel" : 30, "wood" : 30,
 		 "iysaughton" : 80 ]) );
  set_property("enhance criticals", -2);
  set_overall_ac(15);
  set_casting_chance(4);
  set_combat_chance(100);
  set_aggr_status(0);
  set_can_change_aggr(1);
  return;
}

void set_up(int pow) {
  set_level(14+pow/2);
  set_max_hp( 600 + 200 *pow );
  set_hp( 600 + 200 *pow );
  set_property("base hp regen", 5 * pow);
  set_property("base mp regen", 6 * pow);
  set_max_mp(pow * 100 + 350);
  set_mp(pow * 100 + 350);
  set_stats("strength", 70 + 15*pow);
  set_stats("wisdom", 50 + 8*pow);
  set_skill("perception", 40 + 8*pow);
  set_skill("melee", 60 + 8 * pow);
  set_skill("parry", 50 + 8 * pow);
  set_skill("dodge", 35 + 5 * pow);
  set_property("melee damage", ([ "holy" : (20 + 5*pow),
				"crushing" : (10 + 4*pow) ]) );
  set_skill("prayer", 60 + 6*pow);
  set_spell_level("cure serious wounds", 6);
  set_spell_level("cause serious wounds", 6);
  set_spell_level("heal", pow);
  set_spell_level("harm", pow);
  set_spell_level("cure critical wounds", 3+(pow/2));
  set_spell_level("cause critical wounds", 3+(pow/2));
  add_spell("heal", "$(ME)");
  add_spell("harm", "$A");
  add_spell("cure critical wounds", "$(ME)");
  add_spell("cause critical wounds", "$A");
  add_spell("cure serious wounds", "$(ME)");
  add_spell("cause serious wounds", "$A");
  return;
}
