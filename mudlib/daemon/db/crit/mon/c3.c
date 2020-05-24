inherit "/std/pet";

void create() {
  ::create();
  set_name("elemental");
  set_id(({ "elemental", " elemental", "earth elemental" }));
  set("race", "elemental");
  set_body_type("human");

  set_attack(1);
  set_can_change_aggr(0);
  set_carry(0);
  set_save(0);

  set_level(15);
  set_overall_ac(15);
  set_short(" earth elemental");
  set_long("This  elemental glows with the energy of earth");
  set_aggr_status(0);

	set_melee_damage( (["impact" : 15, "crushing" : 15 ]) );
    //set_property("enhance criticals",-5);
    //set_property("magic resistance", 25);
    //set_skill("resist stun", 25);
    //set_overall_ac(10);
    
    //set_stats("strength", 120 + random(30));
    //set_stats("dexterity", 120 + random(30));
    //set_stats("constitution", 120 + random(20));
    //set_stats("wisdom", 50 + random(20));
    set_stats("intelligence", 90 + random(20));
    //set_stats("charisma", 80);

    //set_skill("melee", 110);
    //set_skill("attack", 110);
    //set_skill("defense", 110);
    //set_skill("dodge", 110);
    //set_skill("reverse stroke", 110);
    //set_skill("martial arts",110);
    //set_skill("perception", 110);
    //set_skill("concentrate", 110);
    //set("concentrate", 1);
    //force_me("use concentrate");

  set_skill("elementalism", 125);
  set_skill("earth lore", 125);
  set_max_mp(500);
  set_mp(500);
  set_spell_level("lesser elemental bolt", 6);
  add_spell("lesser elemental bolt", "$A");
  set_spell_level("elemental bolt", 3);
  add_spell("elemental bolt", "$A");
  set_spell_level("lesser elemental strike", 1);
  add_spell("lesser elemental strike", "$A");
  set_combat_chance(75);
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

string query_element() { return "earth"; }

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^GREEN%^%^BOLD%^A  elemental winks out of existence.",
	  environment());
  remove();
  return;
}

