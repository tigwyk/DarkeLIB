inherit "/std/pet";

void create() {
  ::create();
  set_name("brownie");
   set_id(({ "brownie" }));
  set("race", "brownie");
  set_body_type("human");
  set_attack(1);
  set_carry(1);
  set_save(1);
  set_level(2);
  set_short("[2]quick little brownie");
  set_long("Taken from its forest home, this small brownie looks at you "
	"sadly.");
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
  set_max_hp(200);
  set_hp(200);
	set_stats("dexterity", 200);
  set_property("melee damage", ([ "cutting" : 7 ]) );
  return;
}
