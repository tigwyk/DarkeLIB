inherit "/std/pet";

void create() {
  string tmp;

  ::create();
  set_name("devil");
  set_id(({ "devil", "erines devil" }));
  set("race", "devil");
  set_body_type("devil");
  set_languages(({ "common", "devilish", }) );
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(15);
  set_short("Erines Devil");
  set_gender("female");
  set_long(@TEXT
This infernal creature appears to be an evil mutation of
a seraph.  Her slick black skin and leathery wings present
an evil beauty...her eyes are reminiscent of a scolded puppy,
but her occational grin and razor sharp talons hint at at a
darker and malignent interest.
TEXT
);
  set_overall_ac(15);
  set_casting_chance(4);
  set_combat_chance(80);
  set_aggr_status(0);
  set_can_change_aggr(1);
  set_achats(15, ({
     "The Erines licks her talons.",
     "The Erines spits a glob of clotted blood into her hands.",
     "With a stern bite, the Erines bites her tongue til it bleeds.",
   }) );
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

  set_skill("body alteration", 50 + 6*pow);
  set_spell_level("instill poison", (pow/2)+3);
  add_spell("instill poison", "$A");

  set_property("melee damage", (["cutting": 15 + 3*pow ]));

  return;
}
