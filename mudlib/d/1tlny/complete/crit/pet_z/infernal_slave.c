inherit "/std/pet";

  string tmp;

void create() {
  ::create();
  set_name("slave");
  set_id(({ "slave",
            "infernal slave",
            "servant", "soul",
            "damned soul",
            "slave of the damned",
            "infernal soul",
        }));
  set("race", "ghost");
  set_body_type("human");
  set_attack(0);
  set_carry(1);
  set_save(0);
  set_level(1);
  set_stats("strength", 450);
  set_max_hp(25);
  set_hp(25);
  set_max_mp(1);
  set_mp(1);
  switch(random(4)) {
    case 0:
      tmp = "Infernal Slave";
      break;
    case 1:
      tmp = "Damned Soul";
      break;
    case 2:
      tmp = "Slave of the Damned";
      break;
    case 3:
      tmp = "Infernal Soul";
      break;
  }
  set_short(tmp);
  set_long(@TEXT
This torchered entity has offended the infernal leadership and failed
to measure up to the spiral of corruption.  As its punishment it has
been condemned to a fate of servitude and slavery.  It is not able to
completely incarnate into a body, but has been granted minimal gifts
that allow it to fetch a carry for its liege.
TEXT
);
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
  set_languages(({ "common", "devilish", (string)ob->query_primary_lang() }) );
  ::set_owner(who);
  return;
}

void set_up(int pow) {
  set_max_hp( pow * 10 + 10 );
  set_hp( pow * 10 + 10 );
  set_stats("strength", 150 + 50 * pow);
  set_property("melee damage", ([ "crushing" : 1 ]) );
  return;
}

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info",
      "%^RED%^BOLD%^A slave of hell lets out a torchered soul scream as it is consumed by the spiral of corruption and incorporated into the sphere of corruption.",
	  environment());
  remove();
  return;
}

