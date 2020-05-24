inherit "/std/pet";

void create() {
  ::create();
  set_name("death knight");
  set_combat_chance(70);
  set_id(({ "knight", "death knight", "undead" }));
  set("race", "undead");
  set_body_type("human");
  if(!present("death knight sword", this_object()))
    new("/daemon/db/crit/pet_d/obj/dk_sword")->move(this_object());
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(14);
  set_property("enhance criticals",-2);
  set_overall_ac(4);
  set_short("Death Knight, armoured in black");
  set_long("This impressive looking undead creature stares at you with red eyes.");
  set_property("physical resistance",
	       ([ "default" : 60, "iron" : 60, "steel" : 60, "wood" : 60,
	            "silver" : -40 ]));
	force_me("wield sword in right hand and left hand");
  set_can_change_aggr(1);
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
  set_max_hp( pow * 60 + 450 );
  set_hp( pow * 60 + 450 );
  set_skill("melee", 72 + 5*pow);
  set_skill("two handed blade", 72+5*pow);
  set_skill("dodge", 40 + 4*pow);
  set_skill("parry", 46 +4*pow);
  set_stats("strength", 70 + 8 * pow);
  set_property("melee damage", ([ "crushing" : 12 + (3 * pow) ]) );
  set_stats("intelligence", 98);
  set_skill("necromancy", 60+3*pow);
  set_spell_level("chill touch", 6);
  add_spell("chill touch", "$A");
  set_spell_level("cold blast", 4+pow/3);
  add_spell("cold blast", "$A");
  set_spell_level("drain life", 6);
  add_spell("drain life", "$A");
  set_spell_level("lifesteal", 2+pow/3);
  add_spell("lifesteal", "$A");
  return;
}

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^GREEN%^%^BOLD%^A Death Knight winks out of existence.",
	  environment());
  remove();
  return;
}

