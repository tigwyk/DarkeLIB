inherit "/std/pet";

void create() {
  ::create();
  set_name("toaster");
  set_id(({ "rock", "pet rock","joey" }));
  set("race", "rock");
  set_body_type("sphere");
  set_attack(1);
  set_can_change_aggr(1);
  set_carry(0);
  set_save(0);
  set_level(11);
  set_overall_ac(9);
  set_short("Joey, the pet rock");
	set_long("This common household mineral is here to serve you. Some sort of strange magical power has transformed it into a sturdy fighting machine. See 'help pet' "+
  	"for info on how to control it.");
  set_aggr_status(0);
  set_combat_chance(70);
  add_spell("burning hands","$A");
  set_spell_level("burning hands",5);
  set_skill("conjuration",61);
  set_skill("melee",79);
  set_skill("dodge",50);
  return;
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


