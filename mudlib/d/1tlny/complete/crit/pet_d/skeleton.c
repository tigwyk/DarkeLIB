inherit "/std/pet";

void create() {
  ::create();
  set_name("skeleton");
   set_id(({ "skeleton", "undead" }));
  set("race", "undead");
  set_body_type("human");
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(1);
  set_short("Skeleton");
  set_long("The odd-looking undead creature ambles about "
  "clumsily.");
  set_property("physical resistance",
	       ([ "default" : 20, "iron" : 20, "steel" : 20, "wood" : 20 ]));
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
  set_max_hp( pow * 30 + 80 );
  set_hp( pow * 30 + 80 );
  set_property("enhance criticals", ([ "holy" : 1, "impaling" : -1 ]));
  set_skill("melee", 30 + 3*pow);
  set_skill("dodge", 5 + 2*pow);
  set_skill("parry", 10 +3*pow);
  set_stats("strength", 50 + 9 * pow);
  set_property("melee damage", ([ "cutting" : 3 + (2 * pow) ]) );
  return;
}

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^GREEN%^%^BOLD%^A skeleton winks out of existence.",
	  environment());
  remove();
  return;
}

