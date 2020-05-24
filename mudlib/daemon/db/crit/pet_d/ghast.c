inherit "/std/pet";

void create() {
  ::create();
  set_name("ghast");
  set_combat_chance(40);
  set_id(({ "ghast", "undead" }));
  set("race", "undead");
  set_body_type("human");
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(7);
  set_property("enhance criticals",-2);
  set_short("translucent Ghast");
  set_long("This ghostly creature hovers calmly above the ground.");
  set_property("physical resistance",
	       ([ "default" : 40, "iron" : 40, "steel" : 40, "wood" : 40 ]));
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

void set_up(int pow) {
  set_max_hp( pow * 40 + 250 );
  set_hp( pow * 40 + 250 );
  set_skill("melee", 50 + 4*pow);
  set_skill("dodge", 30 + 4*pow);
  set_skill("parry", 38 +4*pow);
  set_stats("strength", 70 + 8 * pow);
  set_property("melee damage", ([ "cold" : 12 + (3 * pow) ]) );
  set_skill("necromancy", 54);
  set_spell_level("chill touch", 6);
  add_spell("chill touch", "$A");
  set_spell_level("cold blast", 3+pow/3);
  add_spell("cold blast", "$A");
  return;
}

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^GREEN%^%^BOLD%^A ghast winks out of existence.",
	  environment());
  remove();
  return;
}

