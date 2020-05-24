inherit "/std/pet";

void create() {
  ::create();
  set_name("ghoul");
  set_combat_chance(50);
  set_id(({ "ghoul", "undead" }));
  set("race", "undead");
  set_body_type("human");
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(1);
  set_short("gangrenous Ghoul");
  set_long("This small green creature has six inch claws and viscious fangs.");
  set_property("physical resistance",
	       ([ "default" : 30, "iron" : 30, "steel" : 30, "wood" : 30 ]));
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
  set_max_hp( pow * 30 + 190 );
  set_hp( pow * 30 + 190 );
  set_property("enhance criticals", ([ "holy" : 1 ]));
  set_skill("melee", 40 + 3*pow);
  set_skill("dodge", 10 + 3*pow);
  set_skill("parry", 18 +3*pow);
  set_stats("strength", 60 + 8 * pow);
  set_skill("necromancy", 45);
  add_spell("chill touch", "$A");
  set_spell_level("chill touch", 6);
  add_spell("cold blast", "$A");
  set_spell_level("cold blast", 1+pow/5);
  set_property("melee damage", ([ "cutting" : 10, "cold" : 10 + (3 * pow) ]) );
  return;
}

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^GREEN%^%^BOLD%^A ghoul winks out of existence.",
	  environment());
  remove();
  return;
}

