//    The skill room of the adventurer's guild.
//
//    DarkeLIB 0.1
//    -Diewarzau 5/7/96

#include <std.h>
#define DEFAULT_SCREEN_SIZE 75
#define EXCLUDE ({ "control_change.c", "long_term.c", "skill.c", "lore_skill.c" })

inherit ROOM;

int calc_skill_inc(object who, string skill);
int dev_cost(object who, string skill);
int filter_skill(string file, mixed *info);
int skill_filter(string skill, int i);

void create() {
  ::create();
    set_property("indoors", 1);
    set_property("no attack", 1);
    set_property("no magic", 1);
    set_property("light", 2);
//Basic mapping added by Tiny 1/20/2020
    set("short", "   0\n   | \n0--@   \n     \n    \nThe Adventurer's Guild Skill Room");
    set("long",
"This room is absolutely immense and divided into several sections.  "
"A gymnasium takes a large portion, and several students engage in "
"trials of combat and dexterity there.  In the distance, separated "
"from the rest of the room by wooden partitions, are study areas, "
"where robed individuals study great tomes which have been donated "
"by the various guilds.\n   0\n   | \n0--@   \n     \n    \n\n"
"\n"
"    Type 'help list' for information on listing skills.\n"
"    Type 'train <skill>' to train a skill.\n");
    add_exit("/d/damned/akkad/adv_guild_sp", "west");
    add_exit("/d/damned/akkad/adv_guild_entrance", "north");
}

void init() {
  ::init();
    add_action("train_skill", "train");
    add_action("list_skills", "list");
    add_action("help_list", "help");
    return;
}

int help_list(string str) {
  string tmp;
  int lines;
  
  if(str != "list") return 0;
  tmp =
  "Since there are so many skills in DarkeMUD, you must pick "
  "certain criterea upon which to list skills.  You may list skills "
  "by level, by letter of the alphabet, by guild, or by any combination "
  "of these.  You do this by typing 'list skills' with any number "
  "of flags after it.  All flags must be preceeded by a dash, and must "
  "be separated by a space.\n\n"
  "-l:<level>         List skills by level.  All skills in the mud of\n"
  "-l:<level-range>   that level or level-range will be listed.\n"
  "                   Ex: 'list skills -l:8' (all 8th level skills)\n"
  "                       'list skills -l:4-10 (all skills 4-10)\n"
  "\n"
  "-a:<letter>        List skills by letter of alphabet.\n"
  "-a:<letter-range>  Ex: 'list skills -a:s (all skills beginning\n"
  "                       with 's'.\n"
  "                       'list skills -a:b-d (all skills b thru d)\n"
  "\n"
  "-g:<guild-name>    List all skills in a certain guild.\n"
  "                   Ex: 'list skills -g:fighter'\n"
  "\n"
  "Put it all together:\n"
  "  'list skills -a:s-z -l:1-5 -g:nightblade'\n"
  "The above would return all skills beginning in the letters s "
  "through z, from level 1-5, in the nightblade guild.\n"
  "\n"
  "Note that you may only cross-train at your level MINUS 5, then "
  "divided by 2 (x-train at level 10 when at level 25 for example).  "
  "Therefore spells listed are only up to (your lev-5) / 2.  "
  "If you are level 10 or lower, you may not cross train at "
  "all.  If you supply more than one flag of a given type, "
  "only the first will be used.\n"
  "NOTE: traning costs 30 mithril times the level of the spell";
  lines = DEFAULT_SCREEN_SIZE;
  if(this_player()->getenv("SCREEN"))
    lines = (int)this_player()->getenv("SCREEN");
  this_player()->more(explode(wrap(tmp, lines), "\n"));
  return 1;
}

int filter_skill(string file, mixed *info) {
  int lev;
  string skill;
  
  if(sizeof(info) != 2) return 0;
  skill = replace_string(file, "_", " ");
  file = "/std/skills/"+file;
  if(!file_exists(file+".c")) return 0;
  lev = (int)file->query_dev() + (int)file->query_fast_dev()/2;
  lev /= 4;
  if(lev < 1) lev = 1;
  if(intp(info[0]) && info[0] && lev != info[0]) return 0;
  else if(pointerp(info[0]) && sizeof(info[0]) == 2) {
    if(lev < info[0][0] || lev > info[0][1]) return 0;
  }
  if(stringp(info[1]) && strlen(skill) &&
    skill[0..0] != info[1]) return 0;
  else if(strlen(skill) && pointerp(info[1]) && sizeof(info[1]) == 2) {
    if(strcmp(skill[0..0], info[1][0]) < 0 ||
      strcmp(skill[0..0], info[1][1]) > 0) return 0;
  }
  return 1;
}

int train_skill(string str) {
  int cost, my_dev, my_lev, sk_lev, mith;
  string file, *sp;

  if(!str) return 0;
  my_dev = (int)this_player()->query_property("dev points");
  my_lev = (int)this_player()->query_level();
  str = lower_case(str);
  sp = (string *)this_player()->query_property("sp skills");
  if(!str) return 0;
  if(!sp || member_array(str, sp) < 0) {
    write("You may not train in a skill you have not 'specialize'-ed.\n"
      "See 'help specialize'.");
    return 1;
  }
  if((int)this_player()->query_base_skill(str) >= 75) {
    write("You may not cross-train a skill past 75% base.");
    return 1;
  }
  file = "/std/skills/"+replace_string(str, " ", "_");
  if(!file_exists(file+".c") ||
    member_array(replace_string(str, " ", "_")+".c",
    EXCLUDE) >= 0) {
    write("There is no such skill.");
    return 1;
  }
  mith = ((int)file->query_dev() + (int)file->query_fast_dev()/2)/4;
  mith *= 30;
  if((int)this_player()->query_money("mithril") < mith) {
    write(sprintf("You need %d mithril to train that skill.", mith));
    return 1;
  }
  this_player()->add_money("mithril", -1*mith);
  cost = dev_cost(this_player(), str);
  if(cost > my_dev) {
    write("You need "+cost+" development points to train that skill.\n"+
	  "You only have "+my_dev+".");
    return 1;
  }
  this_player()->add_dev(-1 * cost);
  this_player()->set_skill(str, (int)this_player()->query_base_skill(str) +
			   calc_skill_inc(this_player(), str));
  this_player()->set_last_dev(str, my_lev);
  write("You now have "+str+" at "+(int)this_player()->query_skill(str)+"%");
  write("It will cost you "+dev_cost(this_player(), str)+
        " development points to advance this skill further.");
  write("You have "+sprintf("%d", (my_dev - cost)) + 
	" development points left.");
  return 1;
}
/* Zortek: 031996 Rewrote list_skills to eliminate the
 * need for file creation and removal via call_out.
 */  
int list_skills(string str) {
  int i, j, lev, skil, k;
  string *tmpv, *foo, *list, col, tmp1, tmp2, guild;
  mixed *info;

  if(!str) return notify_fail("See 'help list'.\n");  
  foo = explode(str, " ");
  if(!sizeof(foo)) return notify_fail("See 'help list'.\n");
  if(sizeof(foo) == 1 && foo[0] == "skills") {
    write("You must supply one or more flags.  See 'help list'\n");
    return 1;
  }
  lev = this_player()->query_level();
  if(lev < 11) {
    write("You must be at least level 11 to train "+
      "outside of your guild.");
    return 1;
  }
  lev = (lev-5)/2;
  if(foo[0] != "skills") return notify_fail("See 'help list'.\n");
  i = sizeof(foo);
  info = allocate(2);
  while(i--) {
    if(strlen(foo[i]) < 4 || foo[i][0] != '-')
      continue;
    skil = strlen(foo[i])-1;
    switch(foo[i][0..2]) {
    case "-l:":
      if(sscanf(foo[i][3..skil], "%d-%d", j, k) == 2) {
        if(j > k || j < 1 || k < 1) {
          write("Invalid level range.");
          return 1;
        }
        if(k > lev) {
          write("You can only view skills up to level "+
            sprintf("%d.", lev));
          return 1;
        }
        info[0] = ({ j, k });
      }
      else if(sscanf(foo[i][3..skil], "%d", j)) {
        if(j < 1) {
          write("Invalid level after -l:");
          return 1;
        }
        if(j > lev) {
          write("You can only view skills up to level "+
            sprintf("%d.", lev));
          return 1;
        }
        info[0] = j;
      }
      else {
        write("Invalid -l flag.  See 'help list'.");
        return 1;
      }
      break;
    case "-a:":
      if(sscanf(foo[i][3..skil], "%s-%s", tmp1, tmp2) == 2) {
        tmp1 = lower_case(tmp1);
        tmp2 = lower_case(tmp2);
        if(strlen(tmp1) > 1 || strlen(tmp2) > 1 ||
          strcmp("a", tmp1) > 0 || strcmp("a", tmp2) > 0 ||
          strcmp("z", tmp1) < 0 || strcmp("z", tmp2) < 0 ||
          strcmp(tmp1, tmp2) > 0) {
          write("Invalid alphabetical range.");
          return 1;
        }
        info[1] = ({ tmp1, tmp2 });
      }
      else if(strlen(foo[i]) == 4) {
        tmp1 = lower_case(foo[i][3..3]);
        if(strcmp("a", tmp1) > 0 || strcmp("z", tmp1) < 0) {
          write("Invalid alphabetical flag.");
          return 1;
        }
        info[1] = tmp1;
      }
      else {
        write("Invalid -a flag.  See 'help list'.");
        return 1;
      }
      break;
    case "-g:":
      guild = foo[i][3..skil];
      break;
    }
  }
  if(!info[0]) info[0] = ({ 1, 100 });
  if(guild) {
    guild = lower_case(replace_string(guild, " ", "-"));
    tmpv = filter_array(get_dir("/d/damned/guilds/*"),
      (: (file_size($2 + $1) == -2) :), "/d/damned/guilds/");
    if(member_array(guild, tmpv) < 0) {
      write("Guild: '"+guild+"' not found.");
      return 1;
    }
    tmpv = filter_array(map_array(get_dir("/d/damned/guilds/"+guild+"/*.c"),
      (: ($2 + replace_string($1, $3, $4)) :), "/d/damned/guilds/"+guild+"/",
      ".c", ""),
      (: call_other :), "is_skill_room");
    if(!tmpv || !sizeof(tmpv)) {
      write("No skills found in that guild.");
      return 1;
    }
    list = ({});
    i = sizeof(tmpv);
    while(i--) list +=
      (string *)call_other(tmpv[i],
        "query_all_skills");
    list = map_array(list, (: replace_string :),
      " ", "_");
  }
  else {
    list = filter_array(get_dir("/std/skills/*.c"),
      (: (member_array($1, $2) < 0) :), EXCLUDE);
    list = map_array(list, (: replace_string :),
      ".c", "");
  }
  list = filter_array(list, (: filter_skill :), info);
  list = map_array(list, (: replace_string :),
    "_", " ");
  if(!sizeof(list)) {
    write("No matching skills found.");
    return 1;
  }
  foo = ({"%^BOLD%^-=-=-=-=-=-=-=-=-=-=  %^BLUE%^Skill Listing%^RESET%^BOLD%^  =-=-=-=-=-=-=-=-=-=-%^RESET%^"});
  if(pointerp(info) && intp(info[0]) && info[0] < lev)
    lev = info[0];
  else if(pointerp(info) && pointerp(info[0]) &&
    info[0][1] < lev)
    lev = info[0][1];
  for(i=1;i <= lev; i++) {
    tmpv = filter_array(list, (: skill_filter :), i);
    if(!tmpv || !sizeof(tmpv)) continue;
    j = sizeof(tmpv);
    foo += ({"%^BLUE%^Level "+sprintf("%2d",i)+" ------------------- Cost to Increase ---- Rating%^RESET%^"});
    while(j--) {
      skil = dev_cost(this_player(), tmpv[j]);
      col = "%^BOLD%^GREEN%^";
      if(skil > this_player()->query_property("dev points") ) col = "%^RED%^";
      foo += ({ sprintf("    %-25s %s%-6d%%^RESET%%^ %6d%% %9d%%",
                tmpv[j],
                col,
                skil,
			    calc_skill_inc(this_player(), tmpv[j]),
			    (int)this_player()->query_skill(tmpv[j])) });
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
  string file;
  int my_lev;

  file = "/std/skills/"+replace_string(skill, " ", "_");
  if(!file_exists(file+".c")) return 0;
  my_lev = ((int)file->query_dev() + (int)file->query_fast_dev() / 2) / 4;
  if(my_lev < 1) my_lev = 1;
  if(lev == my_lev) return 1;
  return 0;
}

int dev_cost(object who, string skill) {
  string file;
  int times, mult;

  if(!who || !who->is_player()) return 0;
  if(!skill) return 0;
  mult = 4;
  file = "/std/skills/"+replace_string(skill, " ", "_")+".c";
  if(!file_exists(file)) return 0;
  file = replace_string(file, ".c", "");
  times = (int)who->query_dev_times(skill, (int)who->query_level());
  if(!times) return (mult * (int)file->query_dev());
  else return (mult * times * (int)file->query_fast_dev());
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

