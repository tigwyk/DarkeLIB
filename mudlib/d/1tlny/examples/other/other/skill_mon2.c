//    Skill training room for guilds.
//
//    DarkeLIB 0.1
//    -Diewarzau 8/8/95

#include <std.h>
inherit MONSTER;


static mapping skill_list;
static string join_room;

int calc_skill_inc(object who, string skill);
int dev_cost(object who, string skill);

void create() {
  ::create();
    if(!query_property("train verb"))
      set_property("train verb", "train");
    if(!query_property("train noun"))
      set_property("train noun", "skills");
    skill_list = ([]);
}


int is_trainer() { return 1; }

void init() {
  ::init();
    if(!query_property("train verb")) set_property("train verb", "train");
    add_action("train_skill", (string)query_property("train verb"));
    add_action("list_skills", "list");
    return;
}

int train_skill(string str, object who) {
  int cost, my_dev, my_lev;

  if(!str) return 0;
my_dev = (int)who->query_property("dev points");
my_lev = (int)who->query_level();
  str = lower_case(str);
  if(!str) return 0;
  if(!skill_list[str]) {
    write("There is no such skill in this guild.");
    return 1;
  }
  if(skill_list[str]["level"] > my_lev) {
    write("That skill is not available at your level.");
    return 1;
  }
cost = dev_cost(who, str);
  if(cost > my_dev) {
    write("You need "+cost+" development points to train that skill.\n"+
	  "You only have "+my_dev+".");
    return 1;
  }
who->add_dev(-1 * cost);
who->set_skill(str, (int)who->query_base_skill(str) +
                          calc_skill_inc(who, str));
who->set_last_dev(str, my_lev);
  write("You now have "+str+" at "+(int)this_player()->query_skill(str)+"%");
write("Test now have "+str+" at "+who->query_skill(str)+"%");
  write("It will cost you "+dev_cost(this_player(), str)+
        " development points to advance this skill further.");
write("Test cost to "+dev_cost(who, str)+" dev pts to advance further.");
  write("You have "+sprintf("%d", (my_dev - cost)) + 
	" development points left.");
  return 1;
}
/* Zortek: 031996 Rewrote list_skills to eliminate the
 * need for file creation and removal via call_out.
 */  
int list_skills(string str) {
  int i, j, lev, skil;
  string *foo, *list, col;

  if(!str || str != (string)query_property("train noun")) return 0;
  lev = this_player()->query_level();
  foo = ({"%^BOLD%^-=-=-=-=-=-=-=-=-=-=  %^BLUE%^Skill Listing%^RESET%^BOLD%^  =-=-=-=-=-=-=-=-=-=-%^RESET%^"});
  for(i=1;i <= lev; i++) {
    list = filter_array(keys(skill_list), "skill_filter", this_object(), i);
    if(!list || !sizeof(list)) continue;
    j = sizeof(list);
    foo += ({"%^BLUE%^Level "+sprintf("%2d",i)+" ------------------- Cost to Increase ---- Rating%^RESET%^"});
    while(j--) {
      skil = dev_cost(this_player(), list[j]);
      col = "%^BOLD%^GREEN%^";
      if(skil > this_player()->query_property("dev points") ) col = "%^RED%^";
      foo += ({ sprintf("    %-25s %s%-6d%%^RESET%%^ %6d%% %9d%%",
                list[j],
                col,
                skil,
			    calc_skill_inc(this_player(), list[j]),
			    (int)this_player()->query_skill(list[j])) });
    }
  }
  foo += ({"%^BOLD%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^"});
  this_player()->more(foo);
  return 1;
}

void delete_file(string file) {
  seteuid(getuid());
  rm(file);
  return;
}

int skill_filter(string skill, int lev) {
  if(!skill_list || !skill_list[skill]) return 0;
  return (skill_list[skill]["level"] == lev);
}

int dev_cost(object who, string skill) {
  string file;
  int times, mult, cost;
  int subt = (int)who->query_property("dev cost");

  if(!who || !who->is_player()) return 0;
  if(!skill) return 0;
  if(!skill_list[skill] || !skill_list[skill]["secondary"])
    mult = 1;
  else mult = 2;
  if((int)who->query_base_skill(skill) >= 80) mult *= 2;
  if((int)who->query_base_skill(skill) >= 100) mult *= 2;
  if((int)who->query_base_skill(skill) >= 150) mult *= 2;
  file = "/std/skills/"+replace_string(skill, " ", "_")+".c";
  if(!file_exists(file)) return 0;
  file = replace_string(file, ".c", "");
  times = (int)who->query_dev_times(skill, (int)who->query_level());
  if(!times) cost = (mult * (int)file->query_dev());
  else cost = (mult * times * (int)file->query_fast_dev());
  if(subt < 0) cost += subt;
  if(cost < 1) cost = 1;
  return cost;
}


string *query_all_skills() {
  if(!skill_list) return ({});
  return keys(skill_list);
}

varargs void add_skill(string skill, int lvl, int flag) {
  skill_list[skill] = ([]);
  skill_list[skill]["level"] = lvl;
  if(flag) skill_list[skill]["secondary"] = flag;
  return;
}

int calc_skill_inc(object who, string skill) {
  int base;

  if(!who || !skill) return 0;
  base = (int)who->query_base_skill(skill);
  switch(base) {
  case 0..25:
    return 5;
  case 26..40:
    return 3;
  case 41..59:
    return 2;
  case 60..10000:
    return 1;
  }
  return 1;
}

void say_this(string str, object whom) {
  string your_lang;

  if(objectp(whom))
    your_lang = (string)whom->query_primary_lang();
  if(your_lang && stringp(your_lang) &&
    (int)this_object()->query_lang_prof(your_lang)
   >= 8) force_me("speak "+your_lang);
  else force_me("speak common");
  force_me("say "+str);
  return;
}

void catch_tell(string str) {
  string lang;

  if(sscanf(str, "%*s says something in %s.", lang) == 2 && random(2)) {
    force_me("say I don't understand "+lang+".");
  return;
  }
}

