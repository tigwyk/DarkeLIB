inherit "/std/pet";

void create() {
  ::create();
  set_name("minotaur");
   set_id(({ "minotaur" }));
  set("race", "minotaur");
  set_body_type("human");
  set_attack(1);
  set_carry(1);
  set_save(1);
	set_overall_ac(1);
  set_level(15);
  set_short("huge minotaur");
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
	object ob;
  set_max_hp(1500);
  set_hp(1500);
  set_property("melee damage", ([ 
	"impaling" : 20
  ]) );
	set_skill("two handed polearm", 100);
	ob = new("/d/damned/virtual/great-axe_6.weapon");
	ob->set_short("huge double bladed battle axe");
	ob->set_long("Forged by skilled hands, this axe is well balanced "
		"very sharp.");
	ob->set_wc(2, "lightning");
	ob->move(this_object());
	force_me("wield axe in right hand and left hand");
  return;
}
