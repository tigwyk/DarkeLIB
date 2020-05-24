inherit "/std/pet";

void create() {
  ::create();
  set_name("sword");
  set_id(({ "sword", "dancing sword" }));
  set("race", "weapon");
  set_body_type("blade");
  set_attack(1);
  set_carry(0);
  set_save(1);
  set_level(1);
  set_short("Dancing Sword");
  set_long(@TEXT
The sword has a faint glow about it and it hangs in the air.
TEXT
);
  set_property("physical resistance",
         ([ "default" : 20, "iron" : 15, "steel" : 10, "wood" : 40 ]));
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
  set_languages(({ "common", (string)ob->query_primary_lang() }) );
  ::set_owner(who);
  return;
}

void set_up(int pow) {
  set_max_hp( pow * 30 + 190 );
  set_hp( pow * 30 + 190 );
  set_property("enhance criticals", ([ "electricity" : 1, "impaling" : -1 ]));
  set_skill("melee", 40 + 3*pow);
  set_skill("dodge", 10 + 2*pow);
  set_skill("parry", 18 + 3*pow);
  set_stats("strength", 55 + 9 * pow);
  set_property("melee damage", ([ "cutting" : 10 + (3 * pow) ]) );
  return;
}

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^BOLD%^%^BLUE%^A sword crumbles to dust.",
	  environment());
  remove();
  return;
}
