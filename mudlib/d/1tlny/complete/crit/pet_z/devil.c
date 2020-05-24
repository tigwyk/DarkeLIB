//    A generic darke devil (pet?)

inherit "/std/pet";

int power;

void create() {
  ::create();
  set_save(0);
  set_attack(1);
  set_carry(0);
  set_can_change_aggr(0);
  set_name("devil");
  set_id(({ "devil", "darke devil", }));
  set_short("Darke Devil");
  set_body_type("devil");
  set("race", "devil");
  set_long(@TEXT
The devil is a pitch black, winged creature that oozes hate and corruption.
TEXT
);
  return;
}

set_up(int pow) {
  power = pow;
  set_level(8+pow/2);
  set_max_hp(260 + 60*pow);
  set_hp(260+60*pow);
  set_skill("melee", 40 + pow * 5);
  set_skill("parry", 30 + pow * 4);
  set_skill("dodge", 30 + pow * 4);

  set_melee_damage(([ "cutting" : 10 + 3 * pow ]));
  set_max_mp(300 + 70* pow);
  set_mp(300 + 70*pow);

  set_skill("necromancy", 60);
  set_spell_level("hex", 3+pow/2);
  add_spell("hex", "$A");
  set_spell_level("curse", 1+pow/3);
  add_spell("curse", "$A");
  set_skill("sorcery", 75);
  set_spell_level("mana drain", (pow>3)?6:pow+3);
  add_spell("mana drain", "$A");

  set_combat_chance(70);
  set_overall_ac(4*pow);
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
  message("info", "%^RED%^%^BOLD%^A Darke Devil leaps through a gate back to its infernal dominion.",
    environment());
  remove();
  return;
}

