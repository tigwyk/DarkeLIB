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
  set_id(({ "demon" }));
  set_short("Demon");
  set_body_type("winged-humanoid");
  set("race", "demon");
  set_long(
  "The demon is a red, winged creature with mischeivous eyes.");
  return;
}

set_up(int pow) {
  power = pow;
  set_level(7+pow/2);
  set_max_hp(260 + 60*pow);
  set_hp(260+60*pow);
  set_skill("melee", 40 + pow * 5);
  set_skill("parry", 30 + pow * 4);
  set_skill("dodge", 30 + pow * 4);
  set_skill("chaos magic", 60);
  set_melee_damage(([ "disruption" : 12 + 3 * pow ]));
  set_max_mp(300 + 70* pow);
  set_mp(300 + 70*pow);
  set_spell_level("disruption bolt", 3+pow/2);
  add_spell("disruption bolt", "$A");
  set_spell_level("chaos ball", 1+pow/3);
  add_spell("chaos ball", "$A");
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
  message("info", "%^GREEN%^%^BOLD%^A demon winks out of existence.",
    environment());
  remove();
  return;
}

