//  The spell room of the adventurer's guild.
//
//    DarkeLIB 0.1
//    -Diewarzau 5/7/96

#include <std.h>
#define DEFAULT_SCREEN_SIZE 75
#define EXCLUDE ({ "long_term_spell.c", "spell.c", \
  "weapon_stack_logic.c", "weapon_stack.c", \
  "shadow.c", "claim_activate.c" })

inherit ROOM;

int dev_cost(object who, string spell);
int filter_spell(string file, mixed *info);
int spell_filter(string spell, int i);

void create() {
  ::create();
    set_property("indoors", 1);
    set_property("light", 2);
//Basic mapping added by Tiny 1/20/2020
    set("short", "   \n    \n   @--0\n    \n   \n The Adventurer's Guild spell Room");
    set("long",
"This is perhaps the largest library you have ever seen.  "
"It is dim, hushed, and absolutely immense.  Robed figures "
"walk about or sit quietly studying tomes by candle light.\n   \n    \n   @--0\n    \n   \n \n"
"\n"
"    Type 'help list' for information on listing spells.\n"
"    Type 'train <spell>' to train a spell.\n");
    add_exit("/d/damned/akkad/adv_guild_sk", "east");
}

void init() {
  ::init();
    add_action("train_spell", "train");
    add_action("list_spells", "list");
    add_action("help_list", "help");
    return;
}

int help_list(string str) {
  string tmp;
  int lines;
  
  if(str != "list") return 0;
  tmp =
  "Since there are so many spells in DarkeMUD, you must pick "
  "certain criterea upon which to list spells.  You may list spells "
  "by level, by letter of the alphabet, by guild, or by any combination "
  "of these.  You do this by typing 'list spells' with any number "
  "of flags after it.  All flags must be preceeded by a dash, and must "
  "be separated by a space.\n\n"
  "-l:<level>         List spells by level.  All spells in the mud of\n"
  "-l:<level-range>   that level or level-range will be listed.\n"
  "                   Ex: 'list spells -l:8' (all 8th level spells)\n"
  "                       'list spells -l:4-10 (all spells 4-10)\n"
  "\n"
  "-a:<letter>        List spells by letter of alphabet.\n"
  "-a:<letter-range>  Ex: 'list spells -a:s (all spells beginning\n"
  "                       with 's'.\n"
  "                       'list spells -a:b-d (all spells b thru d)\n"
  "\n"
  "-g:<guild-name>    List all spells in a certain guild.\n"
  "                   Ex: 'list spells -g:fighter'\n"
  "\n"
  "Put it all together:\n"
  "  'list spells -a:s-z -l:1-5 -g:nightblade'\n"
  "The above would return all spells beginning in the letters s "
  "through z, from level 1-5, in the nightblade guild.\n"
  "\n"
  "Note that you may only cross-train at your level MINUS 5, then "
  "divided by 2 (x-train at level 10 when at level 25 for example).  "
  "Therefore spells listed are only up to (your lev-5) / 2.  "
  "If you are level 10 or lower, you may not cross train at "
  "all.  If you supply more than one flag of a given type, "
  "only the first will be used.\n"
  "NOTE: You need 100 mithril times the level of the spell "
  "times the power level you advance to to train.";
  lines = DEFAULT_SCREEN_SIZE;
  if(this_player()->getenv("SCREEN"))
    lines = (int)this_player()->getenv("SCREEN");
  this_player()->more(explode(wrap(tmp, lines), "\n"));
  return 1;
}

int filter_spell(string file, mixed *info) {
  int lev;
  string spell;
  
  if(sizeof(info) != 2) return 0;
  spell = replace_string(file, "_", " ");
  file = "/std/spells/"+file;
  if(!file_exists(file+".c")) return 0;
  lev = (int)file->query_property("spell level");
  if(!lev || lev < 1) lev = 1;
  if(intp(info[0]) && info[0] && lev != info[0]) return 0;
  else if(pointerp(info[0]) && sizeof(info[0]) == 2) {
    if(lev < info[0][0] || lev > info[0][1]) return 0;
  }
  if(stringp(info[1]) && strlen(spell) &&
    spell[0..0] != info[1]) return 0;
  else if(strlen(spell) && pointerp(info[1]) && sizeof(info[1]) == 2) {
    if(strcmp(spell[0..0], info[1][0]) < 0 ||
      strcmp(spell[0..0], info[1][1]) > 0) return 0;
  }
  return 1;
}

int train_spell(string str) {
  int cost, my_dev, my_lev, sk_lev, mith;
  string *sp, file;

  if(!str) return 0;
  my_dev = (int)this_player()->query_property("dev points");
  my_lev = (int)this_player()->query_level();
  str = lower_case(str);
  if(!str) return 0;
  sp = (string *)this_player()->query_property("sp spells");
  if(!sp || member_array(str, sp) < 0) {
    write("You may not train in a spell you have not 'specialize'-ed.\n"
      "See 'help specialize'.");
    return 1;
  }
  file = "/std/spells/"+replace_string(str, " ", "_");
  if(!file_exists(file+".c") ||
    member_array(replace_string(str, " ", "_")+".c",
    EXCLUDE) >= 0) {
    write("There is no such spell.");
    return 1;
  }
  mith = (int)file->query_property("spell level") * 100;
  mith *= (int)this_player()->query_base_spell(str) + 1;
  if((int)this_player()->query_money("mithril") < mith) {
    write(sprintf("You need %d mithril to train that spell.", mith));
    return 1;
  }
  this_player()->add_money("mithril", -1*mith);
  if((int)this_player()->query_base_spell(str) >= 4) {
    write("You cannot cross-train a spell past *4.");
    return 1;
  }
  cost = dev_cost(this_player(), str);
  if(cost > my_dev) {
    write("You need "+cost+" development points to train that spell.\n"+
	  "You only have "+my_dev+".");
    return 1;
  }
  this_player()->add_dev(-1 * cost);
  this_player()->set_spell_level(str, (int)this_player()->query_base_spell(str) + 1);
  this_player()->set_last_dev(str, my_lev);
  write("You now have "+str+" at *"+(int)this_player()->query_spell_level(str));
  write("It will cost you "+dev_cost(this_player(), str)+
        " development points to advance this spell further.");
  write("You have "+sprintf("%d", (my_dev - cost)) + 
	" development points left.");
  return 1;
}
/* Zortek: 031996 Rewrote list_spells to eliminate the
 * need for file creation and removal via call_out.
 */  
int list_spells(string str) {
  int i, j, lev, skil, k;
  string *tmpv, *foo, *list, col, tmp1, tmp2, guild;
  mixed *info;

  if(!str) return notify_fail("See 'help list'.\n");  
  foo = explode(str, " ");
  if(!sizeof(foo)) return notify_fail("See 'help list'.\n");
  if(sizeof(foo) == 1 && foo[0] == "spells") {
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
  if(foo[0] != "spells") return notify_fail("See 'help list'.\n");
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
          write("You can only view spells up to level "+
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
          write("You can only view spells up to level "+
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
      (: call_other :), "is_spell_room");
    if(!tmpv || !sizeof(tmpv)) {
      write("No spells found in that guild.");
      return 1;
    }
    list = ({});
    i = sizeof(tmpv);
    while(i--) list +=
      (string *)call_other(tmpv[i],
        "query_all_spells");
    list = map_array(list, (: replace_string :),
      " ", "_");
  }
  else {
    list = filter_array(get_dir("/std/spells/*.c"),
      (: (member_array($1, $2) < 0) :), EXCLUDE);
    list = map_array(list, (: replace_string :),
      ".c", "");
  }
  list = filter_array(list, (: filter_spell :), info);
  list = map_array(list, (: replace_string :),
    "_", " ");
  if(!list || !sizeof(list)) {
    write("No matching spells found.");
    return 1;
  }
  foo = ({"%^BOLD%^-=-=-=-=-=-=-=-=-=-=  %^BLUE%^Spell Listing%^RESET%^BOLD%^  =-=-=-=-=-=-=-=-=-=-%^RESET%^"});
  for(i=1;i <= lev; i++) {
    tmpv = filter_array(list, (: spell_filter :), i);
    if(!tmpv || !sizeof(tmpv)) continue;
    j = sizeof(tmpv);
    foo += ({ sprintf("%%^BLUE%%^Level %-2d Spell %'-'29s Cost ---- Level%%^RESET%%^",
      i, "") });
    while(j--) {
      skil = dev_cost(this_player(), tmpv[j]);
      col = "%^BOLD%^GREEN%^";
      if(skil > this_player()->query_property("dev points") ) col = "%^RED%^";
      foo += ({ sprintf("    %-40s %s%-6d%%^RESET%%^     *%1d",
                tmpv[j],
                col,
                skil,
			    (int)this_player()->query_spell_level(tmpv[j])) });
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

int spell_filter(string spell, int lev) {
  string file;
  int my_lev;

  file = "/std/spells/"+replace_string(spell, " ", "_");
  if(!file_exists(file+".c")) return 0;
  my_lev = (int)file->query_property("spell level");
  if(my_lev < 1) my_lev = 1;
  if(lev == my_lev) return 1;
  return 0;
}

int dev_cost(object who, string spell) {
  string file;
  int times, mult, lev;

  if(!who || !who->is_player()) return 0;
  if(!spell) return 0;
  lev = (int)who->query_base_spell(spell) + 1;
  if(lev > 6) return 0;
  mult = 4;
  file = "/std/spells/"+replace_string(spell, " ", "_")+".c";
  if(!file_exists(file)) return 0;
  file = replace_string(file, ".c", "");
  times = (int)who->query_spell_dev_times(spell, (int)who->query_level());
  if(!times) return (lev * mult * (int)file->query_property("dev cost"));
  else return (lev * mult * times * (int)file->query_property("fast dev cost"));
}

