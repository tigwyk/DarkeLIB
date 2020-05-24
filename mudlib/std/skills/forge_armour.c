#include "/d/damned/virtual/virtual_table.h"
#define ARMOUR ({\
"breast-plate", \
"chain-greaves", \
"chain-mail", \
"iron-bracer",\
"great-helm", \
"metal-boots", \
"iron-greaves", \
"scale-greaves", \
"scale-mail", \
"gauntlet", \
"chain-coif", \
"corslet", \
"chain-glove", \
"tower-shield", \
"wall-shield", \
"large-shield", \
"small-shield", \
"buckler-shield", \
"plate-bracer", \
"plate-greaves", \
"banded-mail", \
"chain-vest", \
 })

inherit "/std/skills/long_term.c";

string name, type;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(12);
    set_fast_dev_cost(35);
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("prereq", "blacksmith");
}

void info() {
message("help",
"This skill is used to forge metal armour.  In order to "
"forge armour, you need an armour blank.  This is "
"a long-term skill (see 'help long-term') and may take much real time to "
"finish.  If you are interrupted, you may pick up at a later time.  "
"\nType 'help "
"armour' for armour types available.\n"
"Usage: use forge armour at <blank> with <armour-name>\n"
"Example: use forge armour at blank 2 with breast-plate\n"
"NOTE: If you are picking up the skill after leaving off, you still need to "
"supply the weapon or armour type...this is to avoid accidentally starting over.",
	this_player());
}

int filter_armour(object item, string type) {
  if(!item->id("armour blank")) return 0;
  if(!item->query_property("progress "+name)) return 0;
  if((string)item->query_property("progress "+name) != type) return 0;
  return 1;
}

void skill_func(object from, object at, string arg) {
  object *inv, tmp;
  int time, qual;

  seteuid(getuid());
  arg = lower_case(arg);
  if(member_array(arg, ARMOUR) >= 0) {
    name = (string)from->query_name();
    inv = filter_array(all_inventory(from), "filter_armour",
      this_object(), arg);
    if(sizeof(inv)) at = inv[0];
    if(!at->id("armour blank")) {
      message("info", "You must use this skill on an armour blank.", from);
      remove();
      return;
    }
    if(!present("greater forge", environment(from))) {
      message("info", "You must be in a room with a greater forge to use this skill!",
          from);
      remove();
      return;
    }
    name = arg;
    type = "armour";
    tmp = new("/d/damned/virtual/"+arg+".armour");
    if(present("infernal forge", environment(from)))
      time = (700 + 6*(int)tmp->query_value()) / (props["skill level"]/16 + 1);
    else
      time = (950 + 4*(int)tmp->query_value()) / (props["skill level"]/16 + 1);
    tmp->remove();
    tmp = new("/wizards/diewarzau/obj/misc/ingot");
    tmp->set_material(replace_string((string)at->query_material(), "/", "", 1));
    time *= to_int(pow(to_float((int)tmp->query_value()/10), 0.4));
    time /= 2;
    if(time < 60) time = 60;
    tmp->remove();
    at->set_property("progress "+name, arg);
    if(present("infernal forge", environment(from)))
      set_work_message("%^CYAN%^Wails of the damned sing as you beat on the armour blank.");
    else
      set_work_message("%^CYAN%^You pound on the armour blank.");
    start_work(at, from, time);
    return;
  }
  message("info", "See 'help armour' for the armour you can forge.",
      from);
  remove();
  return;
}

void finish_work(object from, object at) {
  object ob, ob2, ob3, db;
  class v_table tmp;
  float valf;
  int val, base_ac, bonus_ac, x, skill, lvl;

  seteuid(getuid());
  if(present("infernal forge", environment(from)))
    message("info", "%^CYAN%^With a final strike your armour is damned!", from);
  else
    message("info", "%^CYAN%^You are finished forging!", from);
  ob2 = new("/std/Object");
  ob2->set_material("metal/iron");
  ob3 = new("/std/Object");
  ob3->set_material(replace_string((string)at->query_material(), "/", "", 1));
  ob = new("/d/damned/virtual/"+name+"."+type);
  ob->move(from);
  if(!present(ob,from)) {
  	message("info","%^CYAN%^You cannot carry your creation so it falls to the ground.",
  		from);
  	ob->move(environment(from));
  }
  if(ob->query_value()) {
    val = (int)ob->query_value();
    val = val * pow(to_float((int)ob3->prop("value") / (int)ob2->prop("value")), 0.5);
    ob->set_value(val);
    if(present("infernal forge", environment(from)))
      from->add_exp(-100000 - val);
    else
      from->add_exp2(2000 + val/20);
  } else if(ob->query_float_value() && (float)ob->query_float_value() > 0.0) {
    valf = (float)ob->query_float_value();
    valf *= to_float((int)ob3->prop("value")) / to_float((int)ob2->prop("value"));
    ob->set_float_value(valf);
    from->add_exp2(974);
  }
  ob2->remove();
  ob3->remove();
  ob->set_property("extra long","Smithed by: "+from->query_cap_name());
  ob->set_material(replace_string((string)at->query_material(), "/", "", 1));
// Joutei -- Added for FA's unstable protection values 081197
  db = load_object("/d/damned/data/armour_db");
  tmp = (class v_table)db->get_table(name);
  skill = (int)from->query_skill("forge armour");
  lvl = (int)from->query_level();
  for(x=0; x < sizeof(tmp->funcs); x++)
    if(tmp->funcs[x] == "set_ac" && sizeof(tmp->args[x]) == 1)
       base_ac = (int)tmp->args[x][0];
  if(skill > lvl*3)
    bonus_ac = skill/12 + (random(skill - lvl*2) + lvl*2)/10 + to_int(lvl/5);
  else
    bonus_ac = skill/12 + random(skill)/12 + to_int(lvl/6);
  if(present("infernal forge", environment(from)))
    ob->set_ac(base_ac + bonus_ac + 1);
  else
    ob->set_ac(base_ac + bonus_ac);
  if((int)ob->query_ac() < 1) ob->set_ac(1);
  if(intp(ob->prop("hardness")))
    ob->set_decay_rate((int)ob->prop("hardness"));
  at->remove();
  remove();
  return;
}
