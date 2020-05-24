inherit "/std/pet";

void create() {
  ::create();
  set_name("demilich");
  set_combat_chance(100);
  set_id(({ "demilich", "undead" }));
  set("race", "undead");
  set_body_type("human");
  set_attack(1);
  set_can_change_aggr(1);
  set_carry(0);
  set_save(1);
  set_level(19);
  set_property("enhance criticals", -2);
  set_overall_ac(15);
  set_overall_ac(4);
  set_short("skeletal Demilich");
  set_long("This evil creature appears as a floating skull with a ghostly body of "
    "swirling dust.");
  set_property("physical resistance",
	       ([ "default" : 80, "iron" : 80, "steel" : 80, "wood" : 80,
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
  set_max_hp( pow * 70 + 1000);
  set_hp( pow * 150 + 5*pow );
  set_skill("melee", 72 + 5*pow);
  set_skill("dodge", 60 + 5*pow);
  set_skill("parry", 65 +5*pow);
  set_stats("strength", 90 + 8 * pow);
  set_property("melee damage", ([ "cold" : 31 + (4 * pow) ]) );
  set_stats("intelligence", 98);
  set_skill("elementalism", 75+3*pow);
  set_skill("chaos lore", 75+3*pow);
  set_skill("necromancy", 80+3*pow);
  set_spell_level("chill touch", 6);
  add_spell("chill touch", "$A");
  set_spell_level("cold blast", 6);
  add_spell("cold blast", "$A");
  set_max_mp(2300);
  set_mp(2000+70*pow);
  set_spell_level("lifesteal", 6);
  add_spell("lifesteal", "$A");
  set_spell_level("decay", 6);
  add_spell("decay", "$A");
  add_spell("elemental storm", "$A");
  set_spell_level("elemental storm", 4);
  add_spell("elemental strike", "$A");
  set_spell_level("elemental strike", 3);
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

