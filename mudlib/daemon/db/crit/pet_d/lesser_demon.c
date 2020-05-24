//    A lesser demon.

inherit "/std/pet";

int power;

void create() {
  ::create();
  set_save(0);
  set_attack(1);
  set_carry(0);
  set_can_change_aggr(0);
  set_name("demon");
  set_id(({ "demon", "lesser demon" }));
  set_short("Lesser Demon");
  set("race", "demon");
  set_body_type("winged-humanoid");
  set_long(
  "The demon is a small red, winged creature with mischeivous eyes.");
  set_name("demon");
  return;
}

set_up(int pow) {
  power = pow;
  set_level(3+pow/3);
  set_max_hp(150 + 40 * pow);
  set_hp(150 + 40 * pow);
  set_skill("melee", 30 + pow * 4);
  set_skill("parry", 30 + pow * 3);
  set_skill("dodge", 30 + pow * 3);
  set_skill("chaos magic", 40);
  set_max_mp(150 + 70*pow);
  set_mp(150 + 70*pow);
  set_melee_damage(([ "disruption" : 7 + 3*pow ]));
  set_spell_level("disruption bolt", 1+pow/2);
  add_spell("disruption bolt", "$A");
  set_combat_chance(50);
  set_overall_ac(2*pow);
  return;
}

int query_power() { return power; }

void stabilize() {
  remove_call_out("expire");
  set_save(1);
  return;
}

void set_dur(int dur) {
  call_out("expire", dur);
  return;
}

void expire() {
  message("info", "%^GREEN%^%^BOLD%^A lesser demon winks out of existence.",
    environment());
  remove();
  return;
}

