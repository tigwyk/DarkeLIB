inherit "/std/pet";

void create() {
  ::create();
  set_name("wolf");
   set_id(({ "wolf", "dire wolf" }));
  set("race", "wolf");
  set_body_type("quadruped");
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(5);
  set_short("large dire wolf");
  set_long("Yellow fangs drop drool all over the ground before this large "
	"wolf.");
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
  set_max_hp(500);
  set_hp(500);
  set_property("melee damage", ([ "cutting" : 20 ]) );
  return;
}
