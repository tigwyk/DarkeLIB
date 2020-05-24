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
  set_id(({ "greater demon", "demon" }));
  set_short("Greater Demon");
  set_body_type("winged-humanoid");
  set("race", "demon");
  set_long(
  "The demon is a huge, red, winged creature with mischeivous eyes.");
  return;
}

void set_up(int pow) {
  power = pow;
  set_level(15+pow/2);
  set_max_hp(450 + 70*pow);
  set_hp(450 + 70* pow);
  set_skill("melee", 75 + pow * 6);
  set_skill("parry", 55 + pow * 5);
  set_skill("dodge", 55 + pow * 5);
  set_skill("chaos magic", 80);
  set_max_mp(600 + 80* pow);
  set_melee_damage(([ "disruption" : 20 + 4*pow ]));
  set_mp(600 + 80*pow);
  set_spell_level("disruption bolt", 6);
  add_spell("disruption bolt", "$A");
  set_spell_level("chaos ball", 3 + pow/2);
  add_spell("chaos ball", "$A");
  set_combat_chance(70);
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

