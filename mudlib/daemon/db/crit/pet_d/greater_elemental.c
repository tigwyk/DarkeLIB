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
  set_id(({ "elemental", "greater elemental" }));
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
  
  set_short("greater "+name+" elemental");
  set_long("This greater elemental glows with the energy of "
  +name+".");
  element = name;
  elems = ele;
  power = pow;
  set_level(13+pow/2);
  set_exp(100000);
  set_max_hp(800 + 90*pow);
  set_hp(800 + 90*pow);
  set_property("base hp regen", 19 + 5*pow);
  tmp = ([]);
  i = sizeof(ele);
  while(i--) tmp += ([ ele[i] : 25 + 4*pow ]);
  set_melee_damage(tmp);
  set_skill("melee", 70 + pow * 4);
  set_skill("parry", 55 + pow * 4);
  set_skill("dodge", 55 + pow * 4);
   set_skill("elementalism", 70);
  set_max_mp(900 + 80 *pow);
  set_mp(900 + 80*pow);
  set_property("base mp regen", 21 + 4 * pow);
  set_spell_level("elemental bolt", 6);
  add_spell("elemental bolt", "$A");
  set_spell_level("lesser elemental strike", 4+pow/3);
  add_spell("lesser elemental strike", "$A");
  set_spell_level("lesser elemental storm", 6);
  add_spell("lesser elemental storm", "", 1);
  add_spell("greater elemental bolt", 3+pow/2);
  add_spell("greater elemental bolt", "$A");
  set_spell_level("elemental strike", 1+pow/3);
  add_spell("elemental strike", "$A");
  set_combat_chance(85);
  set_overall_ac(15+4*pow);
  return;
}


string query_element() { return element; }

