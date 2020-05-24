//    A Major Deviling

inherit "/std/pet";

int power;

void create() {
  string tmp;
  ::create();
  set_save(0);
  set_attack(1);
  set_carry(0);
  set_can_change_aggr(0);
  set_name("deviling");
  set_id(({ "major deviling", "deviling" }));
  set_short("Major Deviling");
  switch(random(6)) {
    case 0:
      tmp = "insectoid";
      break;
    case 1:
      tmp = "insectoid-winged";
      break;
    case 2:
      tmp = "serpent";
      break;
    case 3:
      tmp = "centaur";
      break;
    case 4:
      tmp = "ent";
      break;
    case 5:
      tmp = "merperson";
      break;
  }
  set_body_type(tmp);
  set("race", "devil");
  set_long(@TEXT
This is a major deviling--a spawn of hell.  The creature has been
around for a couple centuries and has grasped the fundimentals of
corruption.  It has not completed its initiation into a specialty
of sin, but is trying to discover its talents.  This creature knows
the darkness of the spiral of corruption but has yet to walk its
winding path.
TEXT
);
  return;
}

set_up(int pow) {
  string tmp;
  power = pow;
  set_level(5+pow/2);
  set_max_hp(450 + 70*pow);
  set_hp(450 + 70* pow);
  set_skill("melee", 75 + pow * 6);
  set_skill("parry", 55 + pow * 5);
  set_skill("dodge", 55 + pow * 5);

  set_max_mp(600 + 80* pow);
  switch(random(6)) {
    case 0:
      tmp = "electricity";
      break;
    case 1:
      tmp = "disruption";
      break;
    case 2:
      tmp = "plasma";
      break;
    case 3:
      tmp = "vacuum";
      break;
    case 4:
      tmp = "infernal";
      break;
    case 5:
      tmp = "constriction";
      break;
  }
  set_melee_damage(([ tmp:7+3*pow ]));
  set_mp(600 + 80*pow);

  set_skill("necromancy", 80);
  set_spell_level("hex", 6);
  add_spell("hex", "$A");
  set_spell_level("curse", 3 + pow/2);
  add_spell("curse", "$A");

  set_combat_chance(100);
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
  message("info", "%^RED%^%^BOLD%^A Major Deviling is gated back to its infernal dominion.",
    environment());
  remove();
  return;
}

