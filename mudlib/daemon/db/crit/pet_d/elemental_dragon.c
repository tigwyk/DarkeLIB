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
  set_can_change_aggr(1);
  set_id(({ "elemental", "dragon", "elemental dragon" }));
  set("race", "elemental");
  set_body_type("winged-humanoid");
  set_name("elemental");
  set_short("Dragon");
  set_long("This greater elemental dragon glows with energy.");
  return;
}

int query_flying() { return 1; }

void restore_locker(string file) {
  ::restore_locker(file);
  if(elems && power && element)
  this_object()->set_up(power, elems, element);
  return;
}

string query_element() { return element; }

int id(string str) {
  if(::id(str)) return 1;
  if(!element) return 0;
  return ::id(replace_string(str, element + " ", ""));
}

set_up(int pow, string *ele, string name) {
  int i;
  mapping tmp;
  
//  element = name;
  elems = ele;
  power = pow;
  set_level(19+pow/2);
  set_exp(400000);
  set_max_hp(1400 + 120*pow);
  set_hp(1400 + 120*pow);
  set_property("base hp regen", 22 + 5*pow);
  tmp = ([]);
  i = sizeof(ele);
  while(i--) tmp += ([ ele[i] : 38 + 5*pow ]);
  set_melee_damage(tmp);
  set_skill("melee", 80 + pow * 5);
  set_skill("parry", 75 + pow * 5);
  set_skill("dodge", 70 + pow * 5);
  set_skill("elementalism", 80);
  set_max_mp(1200 + 100 *pow);
  set_mp(1200 + 100*pow);
  set_property("base mp regen", 25 + 4 * pow);
  set_spell_level("lesser elemental bolt", 6);
  add_spell("lesser elemental bolt", "$A");
  set_spell_level("elemental bolt", 6);
  add_spell("elemental bolt", "$A");
  set_spell_level("lesser elemental strike", 6);
  add_spell("lesser elemental strike", "$A");
  set_spell_level("greater elemental storm", 1+pow/5);
  add_spell("greater elemental storm", "", 1);
  add_spell("greater elemental bolt", 6);
  add_spell("greater elemental bolt", "$A");
  set_spell_level("elemental strike", 3+pow/2);
  set_spell_level("elemental storm", 6);
  add_spell("elemental storm", "", 1);
  add_spell("elemental strike", "$A");
  set_combat_chance(100);
  set_overall_ac(20+5*pow);
  return;
}
