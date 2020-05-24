inherit "/std/pet";

void create() {
  ::create();
  set_name("devil");
  set_id(({ "imp", "impish creature", "creature", "devil" }));
  set("race", "devil");
  set_body_type("devil");
  set_attack(1);
  set_carry(0);
  set_save(0);
  set_level(5);
  set_short("Impish Creature");
  set_long(@TEXT
TEXT
);
  set_property("physical resistance",([
               "default" : 30,
               "iron"    : 30,
               "steel" : 30,
               "wood" : 30
            ]));
  set_aggr_status(1);
  return;
}

void set_owner(string who) {
  object ob;

  ob = find_player(who);
  if(!ob) {
    ::set_owner(who);
    return;
  }
  set_languages(({ "common", "devilish", (string)ob->query_primary_lang() }) );
  ::set_owner(who);
  return;
}

void set_up(int pow) {
  set_max_hp( pow * 50 + 100 );
  set_hp( pow * 50 + 100 );
  set_stats("strength", 50 + 25 * pow);
  set_property("melee damage", ([ "cutting" : (4 * pow) ]) );
  return;
}

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^RED%^%^BOLD%^An Impish Creature gates back to its infernal dominion.",
	  environment());
  remove();
  return;
}

