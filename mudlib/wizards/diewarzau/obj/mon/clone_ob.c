#include <std.h>

#define STATS ({ "dexterity", "intelligence", "constitution", \

  "charisma", "wisdom", "strength" })

#define NO_CMD ({ "spells", "skills", "who", "alias", "unalias", "nickname", \

  "unnickname", "specialize", "train", "advance" })



inherit MONSTER;



object owner;

int fumble = 0;



create() {

  ::create();

    set_name("clone");

    set_id( ({ "clone" }) );

    set_short("A blank clone");

    set("race", "clone");

    set_long("Ack.");

    set_body_type("humanoid");

    set_level(7);

    set_stats("intelligence", 20);

    set_property("melee damage", ([ "cutting" : 30]));

    set_skill("melee", 60);

    set_skill("dodge", 70);

    set_skill("parry", 20);

    set_stats("dexterity", 90);

    set_max_hp(400);

    set_hp(400);

    set_die((: call_other, this_object(), "kill_me" :));

}



void copy_player(object who) {

  int i, *stats;

  string *skills, *spells, *limbs;

  string race;



  set_level((int)who->query_level());

  set_name((string)who->query_name());

  set_short((string)who->query_short());

  set_description((string)who->query_description());

  set_id((string *)who->query_id() + ({ "clone" ,

    "clone of "+(string)who->query_name() }));

  stats = map_array(STATS, (: call_other($2, $3, $1) :),

    who, "query_stats");

  i = sizeof(stats);

  while(i--) set_stats(STATS[i], stats[i]);

  skills = (string *)who->query_all_skills();

  map_array(skills, (: set_skill($1, call_other($2, $3, $1)) :),

    who, "query_skill");

  spells = (string *)who->query_all_spells();

  map_array(spells, (: set_spell_level($1, call_other($2, $3, $1)) :),

    who, "query_spell_level");

  set_hp((int)who->query_hp());

  set_max_hp((int)who->query_max_hp());

  set_mp((int)who->query_mp());

  set_max_mp((int)who->query_max_mp());

  set_languages((string *)who->query_all_languages());

  force_me("speak "+(string)who->query_primary_lang());

  limbs = query_limbs();

  i = sizeof(limbs);

  while(i--) if(limbs[i] != "torso") remove_limb(limbs[i]);

  limbs = (string *)who->query_limbs();

  i = sizeof(limbs);

  while(i--) add_limb(limbs[i], (string)who->query_ref(limbs[i]),

    (int)who->query_max_dam(limbs[i]), (int)who->query_dam(limbs[i]),

      (int)who->query_ac(limbs[i]));

  set_wielding_limbs((string *)who->query_wielding_limbs());

  set_fingers((int)who->query_fingers());

  owner = who;

  set_exp(10);

  return;

}



void set_dur(int time) {

  delayed_call("expire_me", time);

  return;

}



void set_fumble() {

  fumble = 1;

}



void catch_tell(string str) {

  if(owner && !fumble)

    message("info", "%^BOLD%^clone%^RESET%^%^CYAN%^%%%^RESET%^ "+str,

      owner);

}



void expire_me() {

  message("info", "%^GREEN%^%^BOLD%^The clone of "+

    query_cap_name()+ " disappears.", environment());

  remove();

  return;

}



void kill_me(object ob) {

  if(!owner) {

    message("info", "%^GREEN%^%^BOLD%^The clone of "+

    query_cap_name()+ " disappears!",

      environment());

    remove();

    return;

  }

  message("info", "%^GREEN%^%^BOLD%^The clone of "+

    (string)owner->query_cap_name()+" dies!", environment());

  message("info", "%^RED%^%^BOLD%^Your clone dies, taking 1/2 "

    "of your total hp with it!", owner);

  owner->add_hp(-1*(int)owner->query_max_hp() / 2);

  owner->set("has clone", 0);

  owner->set("mirror action", 0);

  remove();

  return;

}



int force_me(string cmd) {

  string *words;



  if(!cmd) return 0;

  words = explode(cmd, " ");

  if(sizeof(words) && member_array(words[0], NO_CMD) >= 0)

    return 0;

  return ::force_me(cmd);

}





void add_exp(int x) {

  if(owner) owner->add_exp(x);

}



void add_exp2(int x) {

  if(owner) owner->add_exp2(x);

}

