inherit "/std/pet";

int f_level;

void create() {
  string tmp;

  ::create();
  set_name("hellion");
  set_short("hellion");
  set_long("hellion");
  set_languages(({ "common", "devilish", }) );
  set_attack(1);
  set_carry(0);
  set_save(0);
  set_aggr_status(1);
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
  add_action("help_hellion", "help");
  add_action("leech_mp", "leech");
  return;
}

void die() {
  object my_boss;
  my_boss = find_living(query_owner());
  if(!my_boss) ::die();
  else {
    message("info", "%^BOLD%^RED%^You feel a horrible, wrenching tug at your soul...", my_boss);
    my_boss->do_damage("head", query_level()*3);
    ::die();
  }
  return;
}

void set_aggr_status(int x) {
  write("The hellion shakes it head....and then seems cackle hysterically.");
  ::set_aggr_status(1);
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
  message("info", "%^RED%^%^BOLD%^"+query_short()+" gates back to the infernal dominion.",
      environment());
  remove();
  return;
}

int leech_mp(string str) {
  string me;
  int mp, amt;

  if(!str || str == "")
    return notify_fail("Usage: leech <amount> from <name>\n");
  if((string)this_player()->query_name() != query_owner()) return 0;
  if(sscanf(str, "%d from %s", mp, me) != 2)
    return notify_fail("Usage: leech <amount> from <name>\n");
  if(this_object() != present(me, environment(this_player())))
    return notify_fail("You don't seem to see \""+me+"\" here.\n");
  amt = query_mp() - query_max_mp()/4;
  if(amt < 0) amt = 0;
  if(mp > amt) {
    write("The \""+me+"\" doesn't have that much life energy available.");
    return 1;
  }
  this_object()->add_mp(-1 * mp);
  this_object()->do_damage("torso", mp);
  this_player()->add_mp(mp);
  this_player()->add_hp(mp);
  this_player()->do_damage("head", mp/10);
  this_player()->do_damage("torso", mp/4);
  say("A sudden arch of crackling plasma flashes toward "+
    this_player()->query_cap_name()+" seeming to come from "+
    this_object()->query_short()+".");
  write("A sudden arch of crackling plasma pierces your forehead.");
  return 1;
}

int familiar() { return 1; }
int hellion() { return 1; }

int what_level() { return f_level; }

int can_exceed_max_mp() { return 1; }

int help_hellion(string str) {
  int amt;
  
  if((string)this_player()->query_name() != query_owner()) return 0;
  if(present(str, environment()) != this_object()) return 0;
  write(@TEXT
If you desire to leech life force from the hellion, type:
     %^BOLD%^RED%^leech <amount> from <name>%^RESET%^
where <amount> is an amount of infernal power you feel you can safely
absorb, and <name> is the name of the hellion you desire to rape of
its life force.
TEXT
);
  amt = query_mp() - query_max_mp()/2;
  if(amt < 0) amt = 0;
  write("This hellion may have as much as "+amt+" infernal power available.");
  return 1;
}
     
void set_up(int pow) {
  f_level = pow;
  switch(random(pow)+1) {
  case 1:
    set_name("spider");
    set_id(({ "spider", "hellish spider", "hellion" }));
    set_short("Hellish Spider");
    set("race", "spider");
    set_long(@TEXT
This spider's main thorax area is about two feet wide and with its
leg span, it is approximately eight feet across and six feet long.
Upright, this hellion is about four feet tall.  All of its eyes glow
with an infernal glow.  Its mandibles drip with a chocolate ichor.
TEXT
);
    set_level(2*pow);
    set_body_type("arachnid");
    set_melee_damage(([ "infernal" : 5+pow ]));
    set_overall_ac(4+pow);
    set_casting_chance(200);
    set_skill("concentrate", 50+pow);
    set("concentrate", 1);

    set_skill("necromancy", 75+pow);
    set_spell_level("drain life", (pow>6)?6:pow);
    add_spell("drain life", "$A");

    set_skill("body alteration", 75+pow);
    set_spell_level("instill poison", (pow>6)?6:pow);
    add_spell("instill poison", "$A");
    break;
  case 2:
    set_name("scorpion");
    set_body_type("arachnid");
    set("race", "scorpion");
    set_id(({ "scorpion", "hellish scorpion", "hellion" }));
    set_short("Hellish Scorpion");
    set_long(@TEXT
This massive hellion is encased in chitinous armour that has
a deep midnight blue cast.  The front pincers click together
creating a mesmerizing patternless rhythm.  Its tail is poised
steadily...arching smoothly over its back and the stinger will
occationally snap causing a violet ichor to fling in a spray. 
TEXT
);
    set_melee_damage(([ "infernal" : 10+pow, "impaling" : 10+pow ]));
    set_overall_ac(6+pow);
    set_level(4+pow);
    set_casting_chance(200);
    set_skill("concentrate", 50+pow);
    set("concentrate", 1);

    set_skill("necromancy", 75+pow);
    set_spell_level("drain life", (pow>6)?6:pow);
    add_spell("drain life", "$A");

    set_skill("body alteration", 75+pow);
    set_spell_level("instill poison", (pow>6)?6:pow);
    add_spell("instill poison", "$A");
    break;
  case 3:
    set_name("vulture");
    set("race", "bird");
    set_id(({ "vulture", "hellish vulture", "bird", "hellion" }));
    set_body_type("fowl");
    set_short("Hellish Vulture");
    set_long(@TEXT
A massive bird, this hellion appears to be an abnormally large
vulture that reeks of rotting carrion.  Aparently, this bird does
not appear to share its fowl kindred's resistance to disease and
decay, because it seems to lose feathers and its skin is riddled
with pox and pus oozing wounds.  There is a mustard coloured foam
that seems to bubble from it beak and nostrils.
TEXT
);
    set_melee_damage(([ "infernal" : 15+pow, "cutting" : 15+pow ]));
    set_overall_ac(8+pow);
    set_level(6+pow);
    set("flying", 1);
    set_casting_chance(200);
    set_skill("concentrate", 50+pow);
    set("concentrate", 1);

    set_skill("necromancy", 75+pow);
    set_spell_level("drain life", (pow>6)?6:pow);
    add_spell("drain life", "$A");

    set_skill("body alteration", 75+pow);
    set_spell_level("instill poison", (pow>6)?6:pow);
    add_spell("instill poison", "$A");
    set_spell_level("rot", (pow>6)?6:pow);
    add_spell("rot", "$A");
    break;
  case 4:
    set_name("panther");
    set("race", "cat");
    set_id(({ "panthar", "hellish panther", "cat", "hellion" }));
    set_body_type("quadruped");
    set_short("Hellish Panther");
    set_long(@TEXT
Sleek and lithe, this hellion has incarnated into the form of a
large jet black feline.  Its corruption is marked in its obvious
state of malnutrition.  Its ribs, hip, and shoulder joints are
clearly visible and its hide seems to drape over its frame.
TEXT
);
    set_melee_damage(([ "infernal" : 20+pow, "cutting" : 20+pow ]));
    set_overall_ac(10+pow);
    set_level(8+pow);
    set_skill("concentrate", 50+pow);
    set("concentrate", 1);
    set_casting_chance(200);

    set_skill("necromancy", 75+pow);
    set_spell_level("drain life", (pow>6)?6:pow);
    add_spell("drain life", "$A");
    set_spell_level("hex", (pow>6)?6:pow);
    add_spell("hex", "$A");
    set_spell_level("curse", (pow>6)?6:pow);
    add_spell("curse", "$A");
    break;
  case 5:
    set_name("companion");
    set("race", "devil");
    set_id(({ "companion", "hellish companion", "hellion" }));
    set_body_type("devil");
    set_short("Hellish Companion");
    set_long(@TEXT
This hellion has chosen to incarnate into the form of a leperous
human with frail looking wings.  Unlike many other of its ilk, this
creature seems to be warm and friendly.  It seems to want to get
chummy with everyone....
TEXT
);
    set_melee_damage(([ "infernal" : 20+pow, "cutting" : 20+pow, "fire" : 20+pow ]));
    set_overall_ac(10+pow);
    set_skill("necromancy", 75+pow);
    set_skill("concentrate", 50+pow);
    set("concentrate", 1);
    set_spell_level("drain life", (pow>6)?6:pow);
    add_spell("drain life", "$A");
    set_combat_chance(25+pow);
    set_casting_chance(200);
    set_spell_level("rot", (pow>6)?6:pow);
    add_spell("rot", "$A");
    set("flying", 1);
    set_level(10+pow);
    break;
  default:
    set_name("abomination");
    set("race", "devil");
    set_id(({ "abomination", "hellish abomination", "hellion" }));
    set_body_type("slime");
    set_short("Hellish Abomination");
    set_long(@TEXT
Repulsively fetid, massive glob of animated tar.  This hellion has
not bothered to find a form (even remotely) resembling any flora or
fauna known to exist (much less reproduce).  The creature seems so
embody all life energy that is hateful.  When this thing choses to
communicate it is usually in terse vulgarities relating to spite,
vengence, or retribution.  Don't delude yourself any, THIS CREATURE
HATES YOU, YOUR FAMILY, YOUR FRIENDS, and your lil'dog Toto, too!
TEXT
);
    set_melee_damage(([ "infernal" : 25+pow, "cutting" : 25+pow, "fire" : 25+pow ]));
    set_overall_ac(14+pow);
    set_skill("necromancy", 90+pow);
    set_skill("concentrate", 50+pow);
    set("concentrate", 1);
    set_spell_level("lifesteal", (pow>6)?6:pow);
    add_spell("lifesteal", "$A");
    set_spell_level("hex", (pow>6)?6:pow);
    add_spell("hex", "$A");
    set_spell_level("curse", (pow>6)?6:pow);
    add_spell("curse", "$A");
    set_spell_level("rot", (pow>6)?6:pow);
    add_spell("rot", "$A");
    set_combat_chance(45+pow);
    set_casting_chance(200);
    set_level(12+pow);
    break;
  }
  set_exp(50000 * pow + 40000 + random(10000));

  set_max_hp( pow * 30 + 100 );
  set_hp( pow * 30 + 100 );
  set_max_mp(150 + 100 * pow);
  set_mp(150 + 50 * pow);

  set_property("base hp regen", 1);
  set_property("base mp regen", 3 * pow);

  set_gender("neuter");

  set_stats("strength", 50 + 5 * pow);
  set_stats("wisdom", 50 + 5 * pow);
  set_skill("perception", 40 + 4*pow);
  set_skill("melee", 55 + 6 * pow);
  set_skill("parry", 35 + 6 * pow);
  set_skill("dodge", 45 + 4 * pow);
  set_stats("dexterity", 50 + 7 * pow);
  return;
}

int query_flying() {
  return query("flying");
}

