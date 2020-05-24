#include <std.h>


inherit "/std/pet";


int power;

void create() {
  ::create();
  set_name("golem");
  set_id(({ "golem" }));
  set("race", "magical-creation");
  set_body_type("human");
  set_attack(1);
  set_carry(1);
  set_save(1);
  set_level(8);
  set_level(1);
  set_property("enhance criticals",-2);
  set_can_change_aggr(1);
  set_short("Golem");
  set_long("This golem is animated magically.  It is vaguely humanoid in shape.");
  set_aggr_status(0);
  return;
}

void set_owner(string who) {
  object ob;

  ob = find_player(who);
  if(!ob) {
    ::set_owner(who);
    return;
  }
  set_languages(({ "grken", "drow", "common", "elvish", "dwarvish", "serra", "yin", "treefolk",
		 (string)ob->query_primary_lang() }) );
  ::set_owner(who);
  return;
}

int id(string str) {
  if(::id(str)) return 1;
  return ::id(replace_string(str, query_property("material_name")+" ", ""));
}

void restore_locker(string file) {
  ::restore_locker(file);
  set_short((string)query_property("material_name")+" Golem");
  return;
}

void set_up(int pow) {
  int i, idx, tmp2, *ac_values;
  mixed auto_crit;
  mapping tmp;
  string s_tmp, *ac_keys, tmp1, nothing;

  set_level(8 + pow/3);
  set_short((string)query_property("material_name")+" Golem");
  set_hp( 550 + pow*55 + (int)prop("hardness")/4);
  set_mp( 250 + pow*55);
  set_skill("melee", 55 + 4*pow + (int)prop("hit bonus"));
  set_skill("dodge", 35 + 3*pow);
  set_skill("parry", 45 + 4*pow);
  set_stats("strength", 70 + 6 * pow);
  tmp = ([]);
  auto_crit = (mixed)prop("auto critical");
  if(auto_crit && pointerp(auto_crit)) {
    i = sizeof(auto_crit);
    while(i--) {
      sscanf(auto_crit[i], "%s %s : %d", auto_crit[i], tmp1,tmp2);
      if(member_array(auto_crit[i], DAMAGE_TYPES) < 0)
	   tmp += ([ auto_crit[i] : 50 ]);
    }
  } else if(auto_crit && mapp(auto_crit)) {
    ac_keys = keys(auto_crit);
    ac_values = values(auto_crit);
    i = sizeof(ac_keys);
    while(i--) {
      sscanf(ac_keys[i], "%s %s", s_tmp, nothing);
        ac_keys[i] = s_tmp;
      if((idx=strlen(ac_keys[i])) <= 2) continue;
      if(member_array(ac_keys[i], DAMAGE_TYPES) < 0)
        continue;
      tmp += ([ ac_keys[i] : 12 * ac_values[i] ]);
    }
  }
  set_overall_ac((int)prop("armour bonus") + 4*pow);
  set_property("melee damage", tmp + ([ "crushing" : 13 + (4 * pow)
    + (int)prop("damage bonus")*(pow/3 + 1) ]) );
  return;
}

void improve_me(string package, int pow) {
  string *packs;

  packs = (string *)query_property("imp packages");
  if(!packs) packs = ({});
  if(sizeof(packs) >= 2) return;
  switch(package) {
  case "melee damage":
    set_melee_damage( (mapping)query_property("melee damage") +
     ([ "cutting" : 20+(4*pow)+(int)prop("damage bonus")*(pow/3+1) ]) );
    set_stats("strength", 80 + 4*pow);
    break;
  case "damage spells":
    set_combat_chance(50);
    set_skill("conjuration", 55 + 4*pow);
    add_spell("fireball", "$A");
    set_spell_level("fireball", pow);
    add_spell("lightning bolt", "$A");
    set_spell_level("lightning bolt", 1 + pow/5);
    add_spell("explosive fireball", "", 1);
    set_spell_level("explosive fireball", 1 + pow/4);
    break;
  case "healing spells":
    set_casting_chance(40);
    set_skill("prayer", 55+3*pow);
    set_spell_level("cure serious wounds", 3+pow/2);
    add_spell("cure serious wounds", "$(ME)");
    set_spell_level("cure critical wounds", 1+pow/5);
    add_spell("cure critical wounds", "$(ME)");
    break;
  case "hit points":
    set_hp(350 + 65*pow + (1+pow/3)*(int)prop("hardness") / 4);
    break;
  case "magic points":
    set_mp(350 + 60*pow);
    break;
  case "armour":
    set_overall_ac(5*pow + (int)prop("armour bonus")*2);
    break;
  case "protection spells":
    set_casting_chance(40);
    set_skill("elementalism", 50+3*pow);
    add_spell("elemental barrier", "$(ME)", 1, 245*pow);
    set_spell_level("elemental barrier", pow);
    if(!query_skill("prayer")) set_skill("prayer", 50+3*pow);
    add_spell("holy armour", "$(ME)", 1, 184*(3+pow/2));
    set_spell_level("holy armour", 3+pow/2);
    break;
  }
  packs += ({ package });
  set_property("imp packagaes", packs);
  return;
}

string query_element() {
  return ({ "fire", "earth", "air", "water", "electricity", "ice" })[random(6)];
}

