inherit "/std/pet";

void create() {
  ::create();
  set_name("dracolich");
  set_combat_chance(100);
  set_id(({ "dracolich", "undead", "lich" }));
  set("race", "undead");
  set_body_type("winged-humanoid");
  set_attack(1);
  set_can_change_aggr(1);
  set_carry(0);
  set_save(1);
  set_property("enhance criticals", -3);
  set_level(23);
  set_overall_ac(20);
  set_overall_ac(4);
  set_short("ominous Dracolich");
  set_long("This undead dragon is perhaps one of the most powerful of "
  "undead creatures.");
  set_property("physical resistance",
	       ([ "default" : 95, "iron" : 95, "steel" : 95, "wood" : 95,
	            "silver" : -20 ]));
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
  set_max_hp( pow * 70 + 2000 );
  set_hp( pow * 500 + 5*pow );
  set_skill("melee", 110 + 5*pow);
  set_skill("dodge", 60 + 5*pow);
  set_skill("parry", 65 +5*pow);
  set_stats("strength", 90 + 8 * pow);
  set_property("melee damage", ([ "cold" : 39 + (4 * pow) ]) );
  set_stats("intelligence", 98);
  set_skill("elementalism", 75+3*pow);
  set_skill("chaos lore", 75+3*pow);
  set_skill("necromancy", 90+2*pow);
  set_spell_level("chill touch", 6);
  add_spell("chill touch", "$A");
  set_spell_level("cold blast", 6);
  add_spell("cold blast", "$A");
  set_max_mp(3000);
  set_mp(900+70*pow);
  set_spell_level("lifesteal", 6);
  add_spell("lifesteal", "$A");
  set_spell_level("decay", 6);
  add_spell("decay", "$A");
  add_spell("greater elemental bolt", "$A");
  set_spell_level("greater elemental bolt", 6);
  add_spell("elemental storm", "$A");
  set_spell_level("elemental storm", 6);
  add_spell("elemental strike", "$A");
  set_spell_level("elemental strike", 6);
  return;
}

string query_element() { return "chaos"; }

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^GREEN%^%^BOLD%^A Dracolich winks out of existence.",
	  environment());
  remove();
  return;
}

