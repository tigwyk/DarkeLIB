//    A lesser elemental.

inherit "/std/pet";

string element;
string *elems;
int power;

void create() {
  ::create();
  set_save(0);
  set_attack(1);
  set_carry(0);
  set_can_change_aggr(0);
  set_id(({ "elemental", "lesser elemental" }));
  set("race", "elemental");
  set_body_type("human");
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
  
  set_short("lesser "+name+" elemental");
  set_long("This lesser elemental glows with the energy of "
  +name+".");
  element = name;
  elems = ele;
  power = pow;
  set_level(3+pow/3);
  set_max_hp(150 + 40 * pow);
  set_hp(150 + 40 * pow);
  tmp = ([]);
  i = sizeof(ele);
  while(i--) tmp += ([ ele[i] : 7 + 2*pow ]);
  set_melee_damage(tmp);
  set_skill("melee", 40 + pow * 3);
  set_skill("parry", 30 + pow * 3);
  set_skill("dodge", 30 + pow * 3);
  set_skill("elementalism", 40);
  set_max_mp(150 + 70*pow);
  set_mp(150 + 70*pow);
  set_spell_level("lesser elemental bolt", 3+pow/2);
  add_spell("lesser elemental bolt", "$A");
  set_combat_chance(50);
  set_overall_ac(2*pow);
  return;
}

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
  message("info", "%^GREEN%^%^BOLD%^A lesser elemental winks out of existence.",
    environment());
  remove();
  return;
}

string query_element() { return element; }

