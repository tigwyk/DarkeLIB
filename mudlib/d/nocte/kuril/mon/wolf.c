inherit "/std/pet";

void create() {
  ::create();
  set_name("wolf");
   set_id(({ "wolf" }));
  set("race", "wolf");
  set_body_type("quadruped");
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(1);
  set_short("slavering wolf");
  set_long("This intelligent looking animal stares right back at you.");
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
  set_languages(({ "common", "elvish", "serra", "treefolk",
		 (string)ob->query_primary_lang() }) );
  ::set_owner(who);
  return;
}

void set_up() {
  set_max_hp(150);
  set_hp(150);
  set_property("melee damage", ([ "cutting" : 10 ]) );
  return;
}
