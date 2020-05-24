inherit "/std/pet";

void create() {
  ::create();
  set_name("lich");
  set_combat_chance(100);
  set_id(({ "lich", "undead" }));
  set("race", "undead");
  set_body_type("human");
  set_attack(1);
  set_can_change_aggr(1);
  set_carry(0);
  set_save(1);
  set_level(14);
  set_property("enhance criticals", -2);
  set_overall_ac(8);
  set_short("rot-ridden Lich");
  set_long("This undead creature wears the robes of a long-dead mage.");
  set_property("physical resistance",
	       ([ "default" : 70, "iron" : 70, "steel" : 70, "wood" : 70,
	            "silver" : -40 ]));
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
  set_max_hp( pow * 60 + 500 );
  set_hp( pow * 60 + 500 );
  set_skill("melee", 72 + 5*pow);
  set_skill("dodge", 40 + 4*pow);
  set_skill("parry", 46 +4*pow);
  set_stats("strength", 80 + 5 * pow);
  set_property("melee damage", ([ "cold" : 20 + (4 * pow) ]) );
  set_stats("intelligence", 98);
  set_skill("elementalism", 70+3*pow);
  set_skill("chaos lore", 70+3*pow);
  set_skill("necromancy", 75+3*pow);
  set_spell_level("chill touch", 6);
  add_spell("chill touch", "$A");
  set_spell_level("cold blast", 6);
  add_spell("cold blast", "$A");
  set_mp(600+70*pow);
  set_spell_level("lifesteal", 6);
  add_spell("lifesteal", "$A");
  set_spell_level("decay", 6);
  add_spell("decay", "$A");
  add_spell("elemental bolt", "$A");
  set_spell_level("elemental bolt", 5);
  return;
}

string query_element() { return "chaos"; }

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^GREEN%^%^BOLD%^A Lich winks out of existence.",
	  environment());
  remove();
  return;
}

