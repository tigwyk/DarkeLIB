#include <std.h>


inherit "/std/pet";

int power;

void create() {
  ::create();
  set_name("statue");
  set_id(({ "statue" }));
  set("race", "magical-creation");
  set_body_type("human");
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(1);
  set_property("enhance criticals",-1);
  set_can_change_aggr(1);
  set_short("Statue");
  set_long("This statue is animated magically  It is vaguely humanoid in shape.");
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
  set_short((string)query_property("material_name")+" Statue");
  return;
}

void set_up(int pow) {
  int i, idx, *ac_values;
  mixed auto_crit;
  string *ac_keys, s_tmp, nothing;
  mapping tmp;

  power = pow;
  set_short((string)query_property("material_name")+" Statue");
  set_hp( pow * 30 + 80 + (int)prop("hardness")/8);
  set_skill("melee", 30 + 3*pow + (int)prop("hit bonus"));
  set_skill("dodge", 5 + 2*pow);
  set_skill("parry", 10 +3*pow);
  set_stats("strength", 50 + 9 * pow);
  tmp = ([]);
  auto_crit = (mixed)prop("extra wc");
  if(auto_crit && pointerp(auto_crit)) {
    i = sizeof(auto_crit);
    while(i--) {
      if((idx=strlen(auto_crit[i])) <= 2) continue;
      auto_crit[i] = auto_crit[i][0..idx-3];
      if(member_array(auto_crit[i], DAMAGE_TYPES) < 0)
        tmp += ([ auto_crit[i] : 45 ]);
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
      tmp += ([ ac_keys[i] : 10 * ac_values[i] ]);
    }
  }
  set_overall_ac((int)prop("armour bonus"));
  set_property("melee damage", tmp + ([ "crushing" : 3 + (2 * pow)
    + (int)prop("damage bonus") ]) );
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
     ([ "cutting" : 4+(3*pow)+(int)prop("damage bonus") ]) );
    set_stats("strength", 40+4*pow);
    break;
  case "damage spells":
    set_combat_chance(40);
    set_skill("conjuration", 25+3*pow);
    add_spell("magic missile", "$A");
    set_spell_level("magic missile", pow);
    add_spell("burning hands", "$A");
    set_spell_level("burning hands", pow);
    if(pow == 6) {
      add_spell("fireball", "$A");
      set_spell_level("fireball", 2);
    }
    break;
  case "healing spells":
    set_casting_chance(30);
    set_skill("prayer", 20+3*pow);
    set_spell_level("cure light wounds", 2+pow/2);
    add_spell("cure light wounds", "$(ME)");
    break;
  case "hit points":
    set_hp(150+35*pow + (int)prop("hardness") / 8);
    break;
  case "magic points":
    set_mp(170+35*pow);
    break;
  case "armour":
    set_overall_ac(2*pow + (int)prop("armour bonus"));
    break;
  case "protection spells":
    set_casting_chance(40);
    set_skill("elementalism", 20+3*pow);
    add_spell("elemental shield", "$(ME)", 1, 65*pow);
    set_spell_level("elemental shield", pow);
    break;
  }
  packs += ({ package });
  set_property("imp packagaes", packs);
  return;
}

string query_element() {
  return ({ "fire", "earth", "air", "water"})[random(4)];
}

