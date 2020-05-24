inherit "/std/pet";

void create() {
  string tmp;

  ::create();
  set_name("seraph");
  set_id(({ "seraph", "elder seraph" }));
  set("race", "seraph");
  set_body_type("winged_humanoid");
  set_languages(({ "common", "serra", "treefolk", "catfolk", "elvish",
                "dwarvish", "stormspeak", "drow" }) );
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(15);
  set_short("Elder Seraph");
  set_gender("male");
  set_long(
"The Elder Seraph is a truly radiant being.  He is one of the first races "
"ever to walk upon this planet, and most of his race now reside in the "
"outer planes.");
  set_overall_ac(15);
  set_casting_chance(4);
  set_combat_chance(80);
  set_aggr_status(0);
  set_can_change_aggr(1);
  return;
}

void set_up(int pow) {
  set_level(11 + pow/2);
  set_max_hp( 400 + 100*pow);
  set_hp( 400 + 100*pow);
  set_property("base hp regen", 3 * pow);
  set_property("base mp regen", 5 * pow);
  set_max_mp(pow * 70 + 250);
  set_mp(pow * 70 + 250);
  set_stats("strength", 70 + 7*pow);
  set_stats("wisdom", 50 + 6*pow);
  set_skill("perception", 40 + 4*pow);
  set_skill("melee", 40 + 6 * pow);
  set_skill("parry", 35 + 6 * pow);
  set_skill("dodge", 25 + 4 * pow);
  set_property("melee damage", ([ "crushing" : (10 + 2*pow),
                               "holy" : (15 + 4*pow) ]) );
  set_skill("prayer", 50 + 6*pow);
  set_spell_level("cure serious wounds", (pow/2)+3);
  set_spell_level("cause serious wounds", (pow/2)+3);
  set_spell_level("cure critical wounds", 1+(pow/2));
  set_spell_level("cause critical wounds", 1+(pow/2));
  add_spell("cure critical wounds", "$(ME)");
  add_spell("cause critical wounds", "$A");
  add_spell("cure serious wounds", "$(ME)");
  add_spell("cause serious wounds", "$A");
  return;
}
