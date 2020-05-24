inherit "/std/pet";

int f_level;

void create() {
  string tmp;

  ::create();
  set_name("familiar");
  set_short("familiar");
  set_long("familiar");
  set_languages(({ "common", "serra", "treefolk", "catfolk", "elvish",
                "dwarvish", "stormspeak", "drow", "yin", "drow", "grken" }) );
  set_attack(1);
  set_carry(0);
  set_save(0);
  set_aggr_status(0);
    set_exp(20);
  set_can_change_aggr(0);
  if(f_level) this_object()->set_up(f_level);
  return;
}

int greater_familiar() { return 1; }

int what_level() { return f_level; }

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
  set_can_change_aggr(1);
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
  amt = query_mp() - 2*query_max_mp()/3;
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

int can_exceed_max_mp() { return 1; }

int help_familiar(string str) {
  int amt;

  if((string)this_player()->query_name() != query_owner()) return 0;
  if(str != "familiar") return 0;
  amt = query_mp() - 2*query_max_mp()/3;
  if(amt < 0) amt = 0;
  write("If you want to borrow magic points from the familiar, type "
        "'borrow <amount> from <name>', where <amount> is the number "
        "of magic points you want, and <name> is the name of the familiar.");
  write("\nThis familiar has "+amt+" mp available.");
  return 1;
}
     

void set_up(int pow) {
  f_level = pow;
  switch(pow) {
  case 1:
  default:
    set_name("panther");
    set_id(({ "panther", "black panther", "familiar" }));
    set_short("black panther");
    set("race", "panther");
    set_long(
    "This panther moves about lithely.  It regards you with its "
    "iridescent green eyes.");
    set_exp(20);
    set_level(10);
    set_body_type("quadruped");
    set_melee_damage(([ "cutting" : 20 ]));
    set_overall_ac(8);
    break;
  case 2:
    set_name("bear");
    set_body_type("quadruped");
    set("race", "bear");
    set_id(({ "bear", "grizzly bear", "familiar" }));
    set_short("stately grizzly bear");
    set_long("Despite his extreme size, this bear seems rather friendly.  "
    "He gowls affectionately as you approach.");
    set_melee_damage(([ "cutting" : 25, "crushing" : 25 ]));
    set_overall_ac(14);
    set_exp(20);
    set_level(11);
    break;
  case 3:
    set_name("imp");
    set("race", "daemon");
    set_id(({ "imp", "familiar" }));
    set_body_type("winged-humanoid");
    set_short("mischievous Imp");
    set_long("The imp sits on its haunches with its wings folded behind "
    "its shoulders.  It giggles in a high-pitched voice periodically.");
    set_melee_damage(([ "cutting" : 30 ]));
    set_overall_ac(20);
    set_exp(20);
    set_level(13);
    set_skill("concentrate", 70);
    set("concentrate", 1);
    set_skill("conjuration", 70);
    set_spell_level("lightning bolt", 3);
    add_spell("lightning bolt", "$A");
    add_spell("blur", "$(ME)", 1, 500);
    set_spell_level("blur", 2);
    set_combat_chance(80);
    set_skill("illusionism", 70);
    set("flying", 1);
    break;
  case 4:
    set_name("spirit");
    set("race", "spirit");
    set_id(({ "spirit", "wind spirit", "familiar" }));
    set_body_type("human");
    set_short("Wind Spirit");
    set_long("The wind spirit is slightly transparent.  He glides "
    "effortlessly about.");
    set_melee_damage(([ "cold" : 30 ]));
    set_overall_ac(20);
    set_property("physical resistance", ([ "metal" : 40, "steel" : 40,
        "iron" : 40, "wood" : 40, "default" : 40 ]));
    set_exp(20);
    set_level(15);
    set_skill("concentrate", 80);
    set("concentrate", 1);
    set_skill("conjuration", 76);
    set_spell_level("lightning bolt", 5);
    add_spell("lightning bolt", "$A");
    set_combat_chance(80);
    set_skill("prayer", 60);
    set_spell_level("cure critical wounds", 4);
    add_spell("cure critical wounds", "$(ME)");
    set_casting_chance(10);
    set_property("enhance criticals", -1);
    break;
  case 5:
    set_name("daemon");
    set("race", "daemon");
    set_id(({ "daemon", "greater daemon", "familiar" }));
    set_exp(20);
    set_body_type("winged-humanoid");
    set_short("imposing Greater Daemon");
    set_long("This large Daemon makes even Sword-Demons look pretty.  "
    "He smiles, baring large, pointed teeth!");
    set_melee_damage(([ "cutting" : 30, "electricity" : 40 ]));
    set_overall_ac(35);
    set_skill("conjuration", 65);
    set_spell_level("lightning bolt", 6);
    add_spell("lightning bolt", "$A");
    set_combat_chance(100);
    set_skill("illusionism", 75);
    set_spell_level("mirror image", 4);
    add_spell("mirror image", "$(ME)", 1, 300);
    set_skill("sorcery", 75);
    set_spell_level("mana drain", 5);
    add_spell("mana drain", "$A");
    set("flying", 1);
    set_level(16);
    set_property("enhance criticals", -1);
    set_skill("concentrate", 100);
    set("concentrate", 1);
    break;
  case 6:
case 7:
case 8:
    set_name("dragon");
    set("race", "dragon");
    set_id(({ "dragon", "chromium dragon", "familiar" }));
    set_body_type("winged-humanoid");
    set_short("Chromium Dragon");
    set_long("This stately dragon is completely reflective, and "
    "heat radiaites off its body.");
    set_melee_damage(([ "cutting" : 35, "fire" : 50 ]));
    set_skill("conjuration", 70);
    set_skill("concentrate", 50);
    set("concentrate", 1);
    set_spell_level("fireball", 3);
    add_spell("fireball", "$A");
    set_combat_chance(45);
    set("flying", 1);
    set_skill("conjuration", 65);
    set_spell_level("lightning bolt", 6);
    add_spell("lightning bolt", "$A");
    set_spell_level("blizzard", 4);
    add_spell("blizzard", "$A");
    set_skill("magery", 80);
    set_spell_level("hold monster", 4);
    add_spell("hold monster", "$A");
    set_combat_chance(100);
    set_skill("illusionism", 75);
    set_spell_level("mirror image", 4);
    add_spell("mirror image", "$(ME)", 1, 300);
    set_skill("sorcery", 75);
    set_spell_level("mana drain", 5);
    add_spell("mana drain", "$A");
set_level(12+pow);
    set_overall_ac(35);
    set_skill("concentrate", 100);
    set("concentrate", 1);
    break;
  }
  set_max_hp( pow * 110 + 400 );
  set_exp(20);
  set_hp( pow * 110 + 400 );
  set_property("base hp regen", 8 * pow);
  set_property("base mp regen", 7 * pow);
  set_max_mp(pow * 180 + 500);
  set_mp(pow * 170 + 400);
  set_gender("male");
  set_stats("strength", 70 + 8 * pow);
  set_stats("wisdom", 60 + 7 * pow);
  set_skill("perception", 70 + 5*pow);
  set_skill("melee", 65 + 7 * pow);
  set_skill("parry", 65 + 7 * pow);
  set_skill("dodge", 50 + 7 * pow);
  set_stats("dexterity", 70 + 7 * pow);
  return;
}

int query_flying() {
  return query("flying");
}

