//    A Prince of Devils (pet?)
//    Rare...This is a "non-named" generic prince
//    All the named princes, dukes, etc are NPC's

inherit "/std/pet";

int power;

void create() {
  ::create();
  set_save(0);
  set_attack(1);
  set_carry(0);
  set_can_change_aggr(0);
  set_name("prince");
  set_id(({ "prince", "prince of devils", "devil" }));
  set_short("Prince of Devils");
  set_body_type("devil");
  set("race", "devil");
  set_long(@TEXT
Standing before you is a regal prince of the damned.  Make no mistake
this is is a foul and maligned creature that has nothing but complete
and utter contempt of all life, love, or anything that doesn't embody
a deadly sin.  In its quest for power, this monsterous being has gained
mastery over most if not all of the greatest forms of corruption.  It
is likely however that you will have time to discuss philosophy before
it decides to kill you.
TEXT
);
  set_property("physical resistance",
    (["default":30,"iron":30,"steel":30,"wood":-25,"iysaughton":80]) );
  set_property("enhance criticals", -2);
  return;
}

set_up(int pow) {
  power = pow;
  set_level(19+pow/2);
  set_max_hp(1700 + 90*pow);
  set_hp(1700 + 90*pow);
  set_max_mp(1300 + 90* pow);
  set_mp(1300 + 90*pow);

  set_melee_damage((["disruption":40+7*pow,"infernal":60+5*pow ]));

  set_skill("melee", 99 + pow * 7);
  set_skill("parry", 78 + pow * 6);
  set_skill("dodge", 80 + pow * 6);
  set_skill("necromancy", 110);
  set_spell_level("curse", 6);
  add_spell("curse", "$A");
  set_spell_level("hex", 6);
  add_spell("hex", "$A");
  set_spell_level("rot", 6);
  add_spell("rot", "$A");
  set_spell_level("lifesteal", 6);
  add_spell("lifesteal", "$A");
  set_combat_chance(250);
  return;
}

int query_power() { return power; }

void stabilize() {
  remove_call_out("expire");
  set_save(1);
  set_can_change_aggr(1);
  return;
}

void set_dur(int dur) {
  call_out("expire", dur);
  return;
}

void expire() {
  message("info", "%^RED%^%^BOLD%^A Prince of Devils gates home to its hellish dominion.",
    environment());
  remove();
  return;
}

