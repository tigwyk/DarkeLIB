inherit "/std/pet";

int power;

void create() {
  object ob;

  ::create();
  set_name("angel");
  set_id(({ "angel", "battle angel" }));
  set("race", "angel");
  ob = new("/daemon/db/crit/pet_d/obj/angel_sword");
  ob->move(this_object());
  set_body_type("winged-humanoid");
  force_me("wield sword in right hand and left hand");
  set_attack(1);
  set_carry(0);
  set_save(0);
  set_level(10);
  set_short("Battle Angel");
  set_long("This angel stands radiantly before you, clad in the sacred "
  "armour of K'thach.");
  set_property("physical resistance",
               ([ "default" : 50, "iron" : 50, "steel" : 50, "wood" : 50 ]));
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
  power = pow;

  set_hp(250 + 80*pow);
  set_stats("strength", 70+30*pow);
  set_property("melee damage", ([ "holy" : (6*pow) ]) );
  set_overall_ac(15 + 5*pow);
  set_mp(300+60*pow);
  set_skill("prayer", 50+6*pow);
  set_spell_level("hand of the divine", 3+pow/2);
  add_spell("hand of the divine", "$A");
  set_spell_level("cure serious wounds", 3+pow/2);
  add_spell("cure serious wounds", "$(ME)");
  set_skill("two handed blade", 55+10*pow);
  set_stats("dexterity", 70+7*pow);
  return;
}

int query_num_rounds() {
  return power/2 + 1;
}

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^GREEN%^%^BOLD%^An Ethereal Entity winks out of existence.",
	  environment());
  remove();
  return;
}

