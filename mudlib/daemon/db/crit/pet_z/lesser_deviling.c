//    A minor devil.

inherit "/std/pet";

int power;

void create() {
  string tmp;
  ::create();
  set_save(0);
  set_attack(1);
  set_carry(0);
  set_can_change_aggr(0);
  set_name("devil");
  set_id(({ "deviling", "minor deviling" }));
  set_short("Minor Deviling");
  set("race", "devil");
  switch(random(6)) {
    case 0:
      tmp = "insectoid";
      break;
    case 1:
      tmp = "human";
      break;
    case 2:
      tmp = "equine";
      break;
    case 3:
      tmp = "arachnid";
      break;
    case 4:
      tmp = "slime";
      break;
    case 5:
      tmp = "sphere";
      break;
  }
  set_body_type(tmp);
  set_long(@TEXT
This is a minor creature of hell.  The creature has just barely
begun its path along the spiral of corruption.  Consequently, it
has not mastered all the skills and traits that are frequently
encountered in "established" hellspawn.
TEXT
);
  return;
}

set_up(int pow) {
  string tmp;
  power = pow;
  set_level(1+pow/3);
  set_max_hp(100 + (random(25)+1) * pow);
  set_hp(100);
  set_skill("melee", 25 + pow * 2 + random(25) );
  set_skill("parry", 25 + pow * 2 + random(25) );
  set_skill("dodge", 25 + pow * 2 + random(25) );
  set_skill("necromancy", 40);
  set_max_mp(100 + (random(25)+1) * pow);
  set_mp(100);
  switch(random(7)) {
    case 0:
      tmp = "fire";
      break;
    case 1:
      tmp = "cold";
      break;
    case 2:
      tmp = "cutting";
      break;
    case 3:
      tmp = "impact";
      break;
    case 4:
      tmp = "impaling";
      break;
    case 5:
      tmp = "strike";
      break;
    case 6:
      tmp = "crushing";
      break;
  }
  set_melee_damage(([ tmp:7+3*pow ]));
  set_combat_chance(100);
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
  message("info", "%^RED%^%^BOLD%^A minor deviling is gated home to its infernal dominion.",
    environment());
  remove();
  return;
}

