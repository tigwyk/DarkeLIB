inherit "/std/pet";

void create() {
  ::create();
  set_name("angel");
  set_id(({ "angel", "guardian angel" }));
  set("race", "angel");
  set_body_type("winged-humanoid");
  set_attack(1);
  set_carry(0);
  set_save(0);
  set_level(15);
  set_overall_ac(25);
  set_short("white-robed Guardian Angel");
  set_long("This angel is enveloped in a holy protective aura.");
  set_property("physical resistance",
	       ([ "default" : 40, "iron" : 40, "steel" : 40, "iysaughton" : -30 ]));
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
  set_languages(({ "yin", "common", "elvish", "dwarvish", "serra", "yin", "treefolk",
		 (string)ob->query_primary_lang() }) );
  ::set_owner(who);
  return;
}

int query_flying() { return 1; }

void set_up(int pow) {
  set_max_hp( pow * 60 + 330 );
  set_hp( pow * 60 + 330 );
  set_skill("melee", 55 + 5*pow);
  set_property("magic resistance", 60);
  set_skill("dodge", 55 + 3*pow);
  set_skill("parry", 70 +4*pow);
  set_stats("strength", 70 + 8 * pow);
  set_property("melee damage", ([ "holy" : 12 + (3 * pow) ]) );
  set_stats("wisdom", 98);
  set_skill("prayer", 60+3*pow);
  set_stats("strength", 90+5*pow);
  set_spell_level("cure serious wounds", 5);
  add_spell("cure serious wounds", "$(ME)");
  set_property("enhance criticals", -1);
  return;
}

int attack_filter(object who, object own) {
  object *att;
  
  if(!own || !who) return 0;
  if(!living(who)) return 0;
  att = (object *)who->query_attackers();
  if(!att || !sizeof(att)) return 0;
  if(member_array(own, att) < 0) return 0;
  return 1;
}

varargs void heart_beat(int flag) {
  object own, *inv;
  int i;
  
  if(query_owner() && (own=present(query_owner(), environment()))) {
    inv = filter_array(all_inventory(environment()), "attack_filter",
        this_object(), own);
    i = sizeof(inv);
    while(i--) {
      if(skill_contest((int)this_object()->query_stats("strength"),
        (int)inv[i]->query_stats("strength"), 1) != 2) {
        if(own && own == (object)inv[i]->query_current_attacker()) {
          message("info", "The Guardian Angel prevents "+
            (string)inv[i]->query_cap_name() +
            " from attcking you!", own);
          message("info", "The Guardian Angel prevents "+
            (string)inv[i]->query_cap_name() +
            " from attcking "+
            (string)own->query_cap_name()+".", environment(),
            ({ own, inv[i] }));
          message("info", "The Guardian Angel prevents you from attacking "+
            (string)own->query_cap_name()+".", inv[i]);
        }
        inv[i]->kill_ob(this_object(), 1);
      }
    }
  }
  ::heart_beat(flag);
}

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void remove_servant() {
  this_object()->force_me("drop all");
  message("info", "%^GREEN%^%^BOLD%^A guardian angel winks out of existence.",
	  environment());
  remove();
  return;
}

