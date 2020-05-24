inherit "/std/pet";
int power;
int query_power() { return power; }

void create() {
  string tmp;
  ::create();
  set_name("raver");
  set_id(({ "raver", "guardian raver" }));
  set("race", "devil");
  switch(random(12)) {
    case 0:
      tmp = "winged-humanoid";
      break;
    case 1:
      tmp = "human";
      break;
    case 2:
      tmp = "equine";
      break;
    case 3:
      tmp = "arachnid";
      break;
    case 4:
      tmp = "slime";
      break;
    case 5:
      tmp = "sphere";
      break;
    case 6:
      tmp = "insectoid";
      break;
    case 7:
      tmp = "insectoid-winged";
      break;
    case 8:
      tmp = "serpent";
      break;
    case 9:
      tmp = "centaur";
      break;
    case 10:
      tmp = "ent";
      break;
    case 11:
      tmp = "merperson";
      break;
  }
  set_body_type(tmp);
  set_attack(1);
  set_carry(0);
  set_save(0);
  set_level(15);
  set_overall_ac(25);
  set_short("%^BOLD%^GREEN%^Guardian Raver%^RESET%^");
  set_long(@TEXT
Before you is literally a bodyguard from hell!  This infernal warrior
has been charged with defending someone or something...for your sake,
you should hope it does not view you as an enemy or a risk to its charge.
TEXT
);
  set_property("physical resistance",
    (["default":40,"iron":40,"steel":40,"iysaughton":30,"wood":-50 ]));
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
  set_languages(({ "common", "devilish",(string)ob->query_primary_lang() }) );
  ::set_owner(who);
  return;
}

int query_flying() { return 1; }

void set_up(int pow) {
  power = pow;
  set_max_hp( pow * 60 + 330 );
  set_hp( pow * 60 + 330 );
  set_skill("melee", 55 + 5*pow);
  set_skill("dodge", 55 + 3*pow);
  set_skill("parry", 70 +4*pow);

  set_stats("strength", 90+15*pow);
  set_stats("wisdom", 98);

  set_property("magic resistance", 60);
  set_property("melee damage", ([ "infernal" : 12 + (3 * pow) ]) );
  set_property("enhance criticals", -1);

  set_skill("prayer", 60+3*pow);
  set_spell_level("sanctuary", 6);
  add_spell("sanctuary", "$(ME)");

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
          message("info", "An angry Raver interferes with "+
            (string)inv[i]->query_cap_name() +
            "'s attempted attack at you...!\n"+
            "%^RED%^A faint wisp of mist seems to surge from "+
            (string)inv[i]->query_cap_name() +
            "and is caught by the Raver.%^RESET%^" , own);
          message("info", "An angry Raver intercepts an attack from "+
            (string)inv[i]->query_cap_name() +
            " that was directed at "+
            (string)own->query_cap_name()+".\n"+
            "%^RED%^A faint wisp of mist seems to surge from "+
            (string)inv[i]->query_cap_name() +
            "and is caught by the Raver.%^RESET%^" , environment(),
            ({ own, inv[i] }));
          message("info", "A Guardian Raver is infuriated by your attack on "+
            (string)own->query_cap_name()+" and steps in to corrupt your soul...\n"+
            "%^BOLD%^RED%^You feel drain on your experience.%^RESET%^", inv[i]);
        }
        inv[i]->add_exp(-10 * power);
        this_object()->add_exp(-10 * power * power);
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
  message("info", "%^RED%^%^BOLD%^A Guardian Raver is gated home to its infernal dominion.",
	  environment());
  remove();
  return;
}

