//  Wizard:   Khojem
//  Monster:  mercenary pet
//  File:     mercenary.c

inherit "/std/pet";


void create() {
  ::create();
  set_save(1);
  set_attack(1);
  set_carry(1);
  set_can_change_aggr(1);
  set_id(({ "mercenary", "merc" }));
  set("race", "high-man");
  set_body_type("human");
  set_name("mercenary");
  set_level(14);
  return;
}


void restore_locker(string file) {
  ::restore_locker(file);
  return;
}
//    A lesser elemental.

inherit "/std/pet";

string element;
string *elems;
int power;

void create() {
  ::create();
  set_save(1);
  set_attack(1);
  set_carry(0);
  set_can_change_aggr(0);
  set_id(({ "elemental" }));
  set_body_type("human");
  set("race", "elemental");
  set_name("elemental");
  return;
}

void restore_locker(string file) {
  ::restore_locker(file);
  if(elems && power && element)
    this_object()->set_up(power, elems, element);
  return;
}

int id(string str) {
  if(::id(str)) return 1;
  if(!element) return 0;
  return ::id(replace_string(str, element + " ", ""));
}

set_up(int pow, string *ele, string name) {
  int i;
  mapping tmp;
  
  set_short(name+" elemental");
  set_long("This elemental glows with the energy of "
  +name+".");
  element = name;
  elems = ele;
  power = pow;
  set_level(6+pow/3);
  set_exp(10000);
  set_max_hp(340 + 50 * pow);
  set_hp(340 + 50 * pow);
  set_property("base hp regen", 8 + 3*pow);
  tmp = ([]);
  i = sizeof(ele);
  while(i--) tmp += ([ ele[i] : 13 + 3*pow ]);
  set_melee_damage(tmp);
  set_skill("melee", 50 + pow * 4);
  set_skill("parry", 45 + pow * 4);
  set_skill("dodge", 40 + pow * 4);
  set_skill("elementalism", 59);
  set_max_mp(350 + 70*pow);
  set_mp(350 + 70*pow);
  set_property("base mp regen", 15 + 4 * pow);
  set_spell_level("lesser elemental bolt", 6);
  add_spell("lesser elemental bolt", "$A");
  set_spell_level("elemental bolt", 3+pow/2);
  add_spell("elemental bolt", "$A");
  set_spell_level("lesser elemental strike", 1+pow/5);
  add_spell("lesser elemental strike", "$A");
  set_combat_chance(70);
  set_overall_ac(2*pow);
  return;
}

void stabilize() {
  remove_call_out("expire");
  set_save(1);
  return;
}

void expire() {
  message("info", "%^GREEN%^%^BOLD%^An elemental winks out of existence.",
    environment());
  remove();
  return;
}

string query_element() { return element; }

