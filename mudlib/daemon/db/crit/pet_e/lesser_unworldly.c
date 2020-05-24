// /wizards/excelsior/crits/lesser_unworldly
// coded up for Aether critical hits by Excelsior 4/6/96

inherit "std/pet";

void create() {
	::create();
	set_name("unworldy");
	set("id",({"unwordly","thing","creature"}));
	set_level(12);
	set("short","A strange and unworldy creature");
	set("long","This unusual being has a form but has no form, has a mass but "+
		"has no mass, and is basically beyond your comprehension of reality.");
	set("race","unworldy");
	set_gender("neuter");
	set_body_type("sphere");
	set_overall_ac(10);
	set_attack(1);
	set_carry(1);
	set_melee_damage((["aether":9,"holy":12,"vacuum":13]));
	set_skill("melee",75);
	set_skill("attack",83);
}

void set_owner(string who) {
  object ob;

  ob = find_player(who);
  if(!ob) {
    ::set_owner(who);
    return;
  }
  set_languages(({ "undead-tongue", "common", "elvish", "dwarvish", "serra", 
  "yin", "treefolk",
                 (string)ob->query_primary_lang() }) );
  ::set_owner(who);
  return;
}

