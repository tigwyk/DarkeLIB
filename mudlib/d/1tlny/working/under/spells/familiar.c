inherit "/std/pet";

int f_level;

void create() {
  string tmp;

  ::create();
  set_name("spider");
   set_short("spider");
   set_long("A spider from the realms of the spider goddess Lolth.");
  set_languages(({ "common", "serra", "treefolk", "catfolk", "elvish",
                "dwarvish", "stormspeak", "drow", "yin", "drow", "grken" }) );
  set_attack(1);
  set_carry(0);
  set_save(0);
  set_aggr_status(0);
  set_can_change_aggr(0);
  return;
}

void restore_locker(string file) {
  ::restore_locker(file);
  if(f_level)
    this_object()->set_up(f_level);
  return;
}

void init() {
  add_action("help_familiar", "help");
  add_action("borrow_mp", "borrow");
  return;
}

void set_dur(int time) {
  call_out("wink_out", time);
}

void stabilize() {
  remove_call_out("wink_out");
  set_save(1);
  set_property("stable", 1);
  return;
}

void wink_out() {
  message("info", "%^GREEN%^%^BOLD%^"+query_short()+" winks out of existence.",
      environment());
  remove();
  return;
}

int borrow_mp(string str) {
  string me;
  int mp, amt;

  if((string)this_player()->query_name() != query_owner()) return 0;
  if(sscanf(str, "%d from %s", mp, me) != 2)
    return notify_fail("Usage: borrow <amount> from <name>\n");
  if(this_object() != present(me, environment(this_player())))
    return notify_fail("There is no '"+me+"' here.\n");
  amt = query_mp() - query_max_mp()/2;
  if(amt < 0) amt = 0;
  if(mp > amt) {
    write("This familiar only has "+amt+" mp available.");
    return 1;
  }
  this_object()->add_mp(-1 * mp);
  this_player()->add_mp(mp);
  write("Ok.");
  return 1;
}

int familiar() { return 1; }

int what_level() { return f_level; }

int can_exceed_max_mp() { return 1; }

int help_familiar(string str) {
  int amt;
  
  if((string)this_player()->query_name() != query_owner()) return 0;
  if(present(str, environment()) != this_object()) return 0;
  write("If you want to borrow magic points from the familiar, type "
        "'borrow <amount> from <name>', where <amount> is the number "
        "of magic points you want, and <name> is the name of the familiar.");
  amt = query_mp() - query_max_mp()/2;
  if(amt < 0) amt = 0;
  write("\nThis familiar has "+amt+" mp available.");
  return 1;
}
     

void set_up(int pow) {
  f_level = pow;
  switch(pow) {
  case 1:
  default:
    set_name("spider");
     set_id(({ "spider", "watch spider"}));
    set_short("Watch spider");
    set("race", "arachnid");
    set_long(
    "This is a large spider, about the size of a small dog.  Its body is"
    "covered with prickly hair.");
    set_level(8);
     set_body_type("arachnid");
     set_melee_damage(([ "impaling" : 17]));
    set_overall_ac(12);
    break;
  case 2:
    set_name("spider");
     set_body_type("arachnid");
     set("race", "arachnid");
     set_id(({ "spider", "hairy spider"}));
     set_short("hairy spider");
    set_long("This timber wolf has an unusually calm and obedient "
    "demeanor.  His eyes are deep grey.");
    set_melee_damage(([ "cutting" : 12 ]));
    set_overall_ac(6);
    set_level(4);
    break;
  case 3:
    set_name("falcon");
    set("race", "bird");
    set_id(({ "falcon", "familiar" }));
    set_body_type("fowl");
    set_short("magesitc falcon");
    set_long("The falcon perches magestically.  He regards you "
    "with a suspicious, avian eye.");
    set_melee_damage(([ "cutting" : 17 ]));
    set_overall_ac(8);
    set_level(6);
    set("flying", 1);
    break;
  case 4:
    set_name("bear");
    set("race", "bear");
    set_id(({ "bear", "black bear", "familiar" }));
    set_body_type("quadruped");
    set_short("gentle black bear");
    set_long("This small bear is irresistably cute.  He growls softly "
    "and looks at you with reddish, iridescent eyes.");
    set_melee_damage(([ "cutting" : 20 ]));
    set_overall_ac(10);
    set_level(7);
    break;
  case 5:
    set_name("drake");
    set("race", "drake");
    set_id(({ "drake", "sky drake", "familiar" }));
    set_body_type("winged-humanoid");
    set_short("blue Sky Drake");
    set_long("This small dragonoid is gentle and intelligent.  "
    "He beats his wings playfully as he regards you.");
    set_melee_damage(([ "cutting" : 22, "electricity" : 15 ]));
    set_overall_ac(10);
    set_skill("conjuration", 65);
    set_skill("concentrate", 50);
    set("concentrate", 1);
    set_spell_level("lightning bolt", 1);
    add_spell("lightning bolt", "$A");
    set_combat_chance(25);
    set("flying", 1);
    set_level(9);
    break;
  case 6:
    set_name("daemon");
    set("race", "daemon");
    set_id(({ "daemon", "lesser daemon", "familiar" }));
    set_body_type("winged-humanoid");
    set_short("lesser Daemon");
    set_long("The small daemon sits hunched and smiles "
    "mischievously.");
    set_melee_damage(([ "cutting" : 22, "fire" : 20 ]));
    set_overall_ac(14);
    set_skill("conjuration", 70);
    set_skill("concentrate", 50);
    set("concentrate", 1);
    set_spell_level("fireball", 3);
    add_spell("fireball", "$A");
    set_combat_chance(45);
    set("flying", 1);
    set_level(11);
    break;
  }
  set_max_hp( pow * 60 + 100 );
  set_exp(40000 * pow + 400000);
  set_hp( pow * 60 + 100 );
  set_property("base hp regen", 3 * pow);
  set_property("base mp regen", 3 * pow);
  set_max_mp(150 + 50 * pow);
  set_mp(150 + 50 * pow);
  set_gender("male");
  set_stats("strength", 50 + 5 * pow);
  set_stats("wisdom", 50 + 5 * pow);
  set_skill("perception", 40 + 4*pow);
  set_skill("melee", 40 + 6 * pow);
  set_skill("parry", 35 + 6 * pow);
  set_skill("dodge", 25 + 4 * pow);
  set_stats("dexterity", 50 + 7 * pow);
  return;
}

int query_flying() {
  return query("flying");
}

