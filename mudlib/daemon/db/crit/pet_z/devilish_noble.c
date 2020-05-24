inherit "/std/pet";

void create() {
  string tmp;

  ::create();
  set_name("noble");
  set_id(({ "noble", "noble devil", "devil" }));
  set("race", "devil");
  set_body_type("devil");
  set_languages(({ "common", "devilish", }) );
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(18);
  switch(random(7)) {
  case 0:
    tmp = "Glutony";
    break;
  case 1:
    tmp = "Greed";
    break;
  case 2:
    tmp = "Lust";
    break;
  case 3:
    tmp = "Wrath";
    break;
  case 4:
    tmp = "Sloth";
    break;
  case 5:
    tmp = "Envy";
    break;
  case 6:
    tmp = "Pride";
    break;
  }
  set_short("Noble Devil of "+tmp);
  set_gender("male");
  set_long(@TEXT
This is a true creature of the damned.  It's bearing is that of one
that is used to commanding others.  This creature has surpassed others
in its area of sinful specialty and has earned a titled position in
the hoard of the damned.
TEXT
);
  set_property("physical resistance",
	       ([ "default" : 30, "iron" : 30, "steel" : 30, "wood" : 30,
 		 "iysaughton" : 80 ]) );
  set_property("enhance criticals", -2);
  set_overall_ac(15);
  set_casting_chance(50);
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
  set_max_mp(pow * 150 + 350);
  set_mp(pow * 150 + 350);
  set_stats("strength", 70 + 15*pow);
  set_stats("wisdom", 50 + 8*pow);
  set_skill("perception", 40 + 8*pow);
  set_skill("melee", 60 + 8 * pow);
  set_skill("parry", 50 + 8 * pow);
  set_skill("dodge", 35 + 5 * pow);
  set_property("melee damage", ([ "infernal" : (20 + 5*pow),
				"crushing" : (10 + 4*pow) ]) );
  set_skill("necromancy", 75 + 6*pow);
  set_spell_level("curse", 6);
  set_spell_level("hex", 6);
  set_spell_level("rot", 6);
  add_spell("curse", "$A");
  add_spell("hex", "$A");
  add_spell("rot", "$A");
  return;
}
