#include <std.h>

inherit "/std/pet";

void create() {
  ::create();
  set_name("dragon engine");
  set_id(({ "dragon engine" }));
  set("race", "magical-creation");
  set_body_type("human");
  set_attack(1);
  set_carry(1);
  set_save(1);
  set_property("enhance criticals", -3);
  set_level(18);
  set_level(1);
  set_can_change_aggr(1);
  set_short("Dragon Engine");
  set_long("This dragon engine is animated magically.  It is vaguely humanoid in shape.");
  set_aggr_status(0);
  return;
}

void restore_locker(string file) {
  ::restore_locker(file);
  set_short((string)query_property("material_name")+" Dragon Engine");
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

void set_up(int pow) {
  int i, idx, *ac_values;
  mixed auto_crit;
  mapping tmp;
  string s_tmp, *ac_keys, nothing;

  set_level(18 + pow/3);
  set_stats("intelligence", 90);
  set_stats("dexterity", 90);
  set_stats("strength", 90);
  set_short((string)query_property("material_name")+" Dragon Engine");
  set_hp( 3000 + pow*80 + (int)prop("hardness")/2);
  set_mp( 3000 + pow*80);
  set_skill("melee", 130 + 5*pow + (int)prop("hit bonus"));
  set_skill("dodge", 65 + 4*pow);
  set_skill("parry", 70 + 4*pow);
  set_stats("strength", 200 + 6 * pow);
  tmp = ([]);
  auto_crit = (mixed)prop("auto critical");
  if(auto_crit && pointerp(auto_crit)) {
    i = sizeof(auto_crit);
    while(i--) {
      if((idx=strlen(auto_crit[i])) <= 2) continue;
      auto_crit[i] = auto_crit[i][0..idx-3];
      if(member_array(auto_crit[i], DAMAGE_TYPES) < 0)
        continue;
      tmp += ([ auto_crit[i] : 75 ]);
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
      tmp += ([ ac_keys[i] : 18 * ac_values[i] ]);
    }
  }
  set_overall_ac((int)prop("armour bonus")*2 + 4*pow);
  set_property("melee damage", tmp + ([ "crushing" : (21 + (5 * pow))
    + (int)prop("damage bonus")*(pow/2 + 1) ]) );
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
     ([ "cutting" : 35+(6*pow)+(int)prop("damage bonus")*(pow/2+1) ]) );
    set_stats("strength", 100 + 5*pow);
    break;
  case "damage spells":
    set_combat_chance(75);
    set_skill("conjuration", 75 + 4*pow);
    add_spell("lightning bolt", "$A");
    set_spell_level("lightning bolt", pow);
    add_spell("explosive fireball", "", 1);
    set_spell_level("explosive fireball", 2+pow/2);
    add_spell("blizzard", "", 1);
    set_spell_level("blizzard", 1+pow/3);
    add_spell("greater elemental bolt", "$A");
    set_spell_level("greater elemental bolt", pow);
    set_skill("elementalism", 67+3*pow);
    break;
  case "healing spells":
    set_casting_chance(60);
    set_skill("prayer", 65+4*pow);
    set_spell_level("cure critical wounds", 3+pow/2);
    add_spell("cure critical wounds", "$(ME)");
    set_spell_level("heal", 21+pow/5);
    add_spell("heal", "$(ME)");
    break;
  case "hit points":
    set_hp(700 + 100*pow + (1+pow/2)*(int)prop("hardness") / 4);
    break;
  case "magic points":
    set_mp(700 + 100*pow);
    break;
  case "armour":
    set_overall_ac(7*pow + (int)prop("armour bonus")*2);
    break;
  case "protection spells":
    set_casting_chance(60);
    set_skill("elementalism", 65+3*pow);
    add_spell("elemental aegis", "$(ME)", 1, 245*pow);
    set_spell_level("elemental aegis", pow);
    if(!query_skill("prayer")) set_skill("prayer", 67+4*pow);
    add_spell("armour of faith", "$(ME)", 1, 184*(3+pow/2));
    set_spell_level("armour of faith", 3+pow/2);
    break;
  }
  packs += ({ package });
  set_property("imp packagaes", packs);
  return;
}

string query_element() {
  return ({ "fire", "earth", "air", "water", "electricity", "ice" })[random(6)];
}

