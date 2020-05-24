inherit "/std/pet";

void create() {
  ::create();
  set_name("zombie");
  set_combat_chance(30);
  set_id(({ "zombie", "undead" }));
  set("race", "undead");
  set_body_type("human");
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(1);
  set_short("hideous Zombie");
  set_long("This disgusting creature smells of rotting flesh.");
  set_property("physical resistance",
	       ([ "default" : 25, "iron" : 25, "steel" : 25, "wood" : 25 ]));
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
  set_property("enhance criticals", ([ "holy" : 1, "impaling" : -1 ]));
  set_skill("melee", 40 + 3*pow);
  set_skill("dodge", 10 + 3*pow);
  set_skill("parry", 18 +3*pow);
  set_stats("strength", 60 + 8 * pow);
  set_skill("necromancy", 45);
  add_spell("chill touch", "$A");
  set_spell_level("chill touch", 3+pow/3);
  set_property("melee damage", ([ "crushing" : 7 + (3 * pow) ]) );
  return;
}

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^GREEN%^%^BOLD%^A zombie winks out of existence.",
	  environment());
  remove();
  return;
}

