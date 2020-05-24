inherit "/std/pet";

void create() {
  ::create();
  set_name("vampire");
  set_combat_chance(60);
  set_id(({ "vampire", "undead" }));
  set("race", "undead");
  set_body_type("human");
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(12);
  set_property("enhance criticals",-2);
  set_overall_ac(4);
  set_short("pale Vampire");
  set_long("This pale undead creature lurks about thirstily.");
  set_property("physical resistance",
	       ([ "default" : 60, "iron" : 60, "steel" : 60, "wood" : -40 ]));
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
  set_languages(({ "undead-tongue", "common", "elvish", "dwarvish", "serra", "yin", "treefolk",
		 (string)ob->query_primary_lang() }) );
  ::set_owner(who);
  return;
}

int query_flying() { return 1; }

void set_up(int pow) {
  set_max_hp( pow * 50 + 380 );
  set_hp( pow * 50 + 380 );
  set_skill("melee", 65 + 5*pow);
  set_skill("dodge", 40 + 4*pow);
  set_skill("parry", 38 +4*pow);
  set_stats("strength", 70 + 8 * pow);
  set_property("melee damage", ([ "cold" : 12 + (3 * pow) ]) );
  set_stats("intelligence", 98);
  set_skill("necromancy", 60+3*pow);
  set_spell_level("chill touch", 6);
  add_spell("chill touch", "$A");
  set_spell_level("cold blast", 3+pow/3);
  add_spell("cold blast", "$A");
  set_spell_level("drain life", 6);
  add_spell("drain life", "$A");
  set_spell_level("lifesteal", pow/5+1);
  add_spell("lifesteal", "$A");
  return;
}

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^GREEN%^%^BOLD%^A vampire winks out of existence.",
	  environment());
  remove();
  return;
}

