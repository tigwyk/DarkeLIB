inherit "/std/pet";

void create() {
  ::create();
  set_name("entity");
  set_id(({ "entity", "unholy ethereal entity" }));
  set("race", "ghost");
  set_body_type("human");
  set_attack(1);
  set_carry(0);
  set_save(0);
  set_level(5);
  set_short("Unholy Ethereal Entity");
  set_long("This ethereal being appears as a ghastly entity with almost "+
"no physical body.  It is strongly psychokinetic, though, and capable of "+
"carrying a great deal for its master.");
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
  set_languages(({ "common", "elvish", "dwarvish", "serra", "yin", "treefolk",
		 (string)ob->query_primary_lang() }) );
  ::set_owner(who);
  return;
}

void set_up(int pow) {
  set_max_hp( pow * 50 + 100 );
  set_hp( pow * 50 + 100 );
  set_stats("strength", 50 + 25 * pow);
  set_property("melee damage", ([ "crushing" : (4 * pow) ]) );
  return;
}

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^GREEN%^%^BOLD%^An Unholy Ethereal Entity winks out of existence.",
	  environment());
  remove();
  return;
}

