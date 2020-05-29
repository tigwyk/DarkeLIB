//      /d/st_adjndard/setter.c
//      Starting room for new characters choosing races
//      from the Nightmare Mudlib
//      created by Shadowwolf@Nightmare july 1992
//      modified by Descartes of Borg for the race daemon 10 june 1993

#include <std.h>
#include <security.h>
#include <rooms.h>
#include <daemons.h>
#include <ansi.h>

#define STATS ({ "strength", "constitution", "intelligence",\
		   "dexterity", "wisdom", "charisma" })
#define CLS ESC+"[H"+ESC+"[2J"

inherit ROOM;

string *tab_str = ({ "35-49   +1 point",
                    "50       0 points",
                    "51-65    1 point",
                    "66-80    2 points",
                    "81-95    3 points",
                    "96-105   4 points",
                    "106-110  5 points" });

string rand_choice =
  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

void do_rolls();
void assign_point(string str, int *points, int pts_left);
void pick_stat(string str, int *points, int pts_left);
void set_ansi();
int pt_to_stat(int pts);
string random_password(int len);

string random_password(int len) {
  string ret = "";
  int idx, ln;
  
  if(len <= 0) return "";
  ln = strlen(rand_choice);
  while(len--) {
    idx = random(ln);
    ret += rand_choice[idx..idx];
  }
  return ret;
}

int pt_to_stat(int pts) {
  pts += 15;
  switch(pts) {
  case 0..30:
    return 35+pts;
  case 31..60:
    return 65 + (pts - 30) / 2;
  case 61..105:
    return 80 + (pts - 60)/3;
  case 106..145:
    return 95 + (pts - 105)/4;
  case 146..170:
    if(pts <= 174)
      return 105 + (pts - 145)/5;
    else return 110;
  default:
    return 35;
  }
  return 0;
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no attack", 1); 
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set_property("no cast", 1);
    set("long",
      "This is the race setter room.\n \n"
      "Directions: 1) Read the faq... <help newbie>.\n"
      "            2) Read the race help... <help races>.\n"
      "            3) Pick the race... pick <race>.\n \n"
      " Note: type <read list> to see a list of the races.\n"
      "       type <help guilds> for a list of guilds.\n"
      "       type help <guild name> for more information on the guild.\n");
    skip_obvious();
    set_items(
      (["room" : "The nothingness from which you will be born "
	"into Darke Domain.",
	"list" : "A list of races that exist in the world of Darke Domain."]) );
}

void init() {
    ::init();
    this_player()->setenv("SCORE", "off");
    this_player()->set("in creation", 1);
    this_player()->set_catch("off");
    add_action("read", "read");
    add_action("pick","pick");
    if (this_player()->query_exp() <= 0) {
	write("\nWelcome to Darke Domain!   Let the CARNAGE begin!\n"
	  "Please choose a race for yourself.  Your race determines your main "
	  "genetic attributes, strength, intelligence, dexterity, constitution, "
	  "and charisma.");
	this_player()->set_rolls(0); 
    }
}

int pick(string str) {
    mapping racial_props;
    string *skill_keys, *racial_keys;
    int i, j;
    string my_class, *g_dir, name;
    object who;
who = this_player();

who->reset_xp_to_dev();
    my_class = "child";
    if(!str) {
	return notify_fail("Please supply a race from the race list.\n");
    }
    str = lower_case(str);
    if(member_array(str, (string *)RACE_D->query_races()) == -1) {
	write("You must pick a race from the list!\nType <read list>\n");
	return 1;
    }
    printf("Ok.\nCreating your character...");
    g_dir = get_dir("/d/damned/guilds/join_rooms/*_join.c");
    i = sizeof(g_dir);
    name = (string)this_player()->query_name();
    while(i--)
	call_other("/d/damned/guilds/join_rooms/"+g_dir[i], "kick_member",
	  name);
    who->remove_property("lycanthrope moon");
    who->set_overall_ac(0);
    who->remove_property("extra mp regen");
    who->remove_property("extra hp regen");
    who->set_race(str);
    who->new_body();
    who->set_class(my_class);
    who->init_skills(my_class);
    who->add_sight_bonus((int)RACE_D->query_sight_bonus(str) -
      (int)who->query_sight_bonus());
    who->set_property("ambidextry", 0);
    who->set_property("sp points", 0);
    racial_props = (mapping)RACE_D->query_racial_properties(str);
    if(mapp(racial_props)) {
	racial_keys = keys(racial_props);
	i = sizeof(racial_keys);
	while(i--) {
	    switch(racial_keys[i]) {
	    case "innate skills":
		if(!mapp(racial_props[racial_keys[i]])) break;
		skill_keys = keys(racial_props[racial_keys[i]]);
		j = sizeof(skill_keys);
		while(j--) {
		    who->set_skill(skill_keys[j],
		      racial_props["innate skills"][skill_keys[j]]);
		}
		break;
	    case "innate spells":
		if(!mapp(racial_props[racial_keys[i]])) break;
		skill_keys = keys(racial_props[racial_keys[i]]);
		j = sizeof(skill_keys);
		while(j--) {
		    who->set_spell_level(skill_keys[j],
		      racial_props["innate spells"]
		      [skill_keys[j]]);
		}
		break;
	    default:
		who->set_property(racial_keys[i],
		  racial_props[racial_keys[i]]);
	    }
	}
    }
    who->setenv("TITLE","Novice $N the " + capitalize(str));
//DEFAULT COMBAT COLOR
    who->set_property("combat color", "%^BOLD%^");
//DEFAULT COMBAT COLOR
    who->move("/d/standard/waiting_room");
    do_rolls();
    return 1;
}

void do_rolls() {
  write("Now you will assign your stats.\n"
  "Darke Domain has a point-based stat assignment system.  Basically, "
  "you start out with a 50 in each stat and 325 points to spend.  "
  "Stats get more costly as the stat increases, ie, getting from 50 "
  "to 51 in a stat costs less than getting from 90 to 91.  You may also "
  "reduce any of your stats to as low as 35 in order to obtain extra "
  "points.  You will be provided with a table of stat costs.\n"
    "By the way, if you try to raise a stat above 110, it will wrap to 35!\n");
  printf("Press [enter] to continue: ");
  input_to("press_enter", 0, ({ 0, 0, 0, 0, 0, 0 }), 325);
  return;
}

void assign_point(string str, int *points, int pts_left) {
  int idx, i, max;
  int m;
  object who;
who = this_player();
  
  if(str && lower_case(str) != "q") {
    str = lower_case(str);
    idx = member_array(str, STATS, 1);
    if(idx < 0) {
      write("'"+str+"' is not one of the available stats.\n");
      printf("Press [enter] to continue: ");
      input_to("press_enter", 0, points, pts_left);
      return;
    }
if(strlen(str) >= 2 && str[0..1] == "ch") m = 2;
    else m = 1;
    if((int)who->query("pt choice") < 0 &&
      (points[idx] + (int)who->query("pt choice")*m) < -15) {
      write("You may only reduce a stat to 35.  No lower.");
      who->set("pt choice", 0);
      printf("Press [enter] to continue: ");
      input_to("press_enter", 0, points, pts_left);
      return;
    }
    pts_left -= (int)who->query("pt choice");
    points[idx] += (int)who->query("pt choice") * m;
    who->set("pt choice", 0);
  }
  else if(str && lower_case(str) == "q") {
    write("Are you sure you want to quit?");
    if(pts_left > 0)
      write(sprintf("You have %d points left.", pts_left));
    printf("(yes or no): ");
    input_to("yes_or_no", 0, points, pts_left);
    return;
  }
  printf(CLS);
  write(sprintf("%|70s\n%|70s\n", "Stat Assignment", sprintf("points left: %d",
    pts_left)));
  max = sizeof(tab_str);
  write(sprintf("%'-='70s", ""));
  for(i=0;i < max;i++) {
    if(i < sizeof(STATS))
      write(sprintf("  %-18s     %-13s %3d %-+2d (%d points)",
        tab_str[i], STATS[i]+":", pt_to_stat(points[i]),
        (int)RACE_D->query_stat_adjustment(STATS[i][0..2],
          (string)who->query("race")),
        points[i]));
    else
      write("  "+tab_str[i]);
  }
  write(sprintf("%'-='70s", ""));
  write("\n"+
      "Choose an amount of points you wish to spend on a stat.  "
      "Type only the number.  You will be prompted for the stat.  "
      "See the above table for the cost per stat point.  You MAY type in "
      "a negative number and reduce a stat to as low as 35.\n"
      "NOTE: Charisma costs 1/2 the points of other stats and does "
      "not affect your development points.");
  printf("\nEnter a point amount ('q' to quit): ");
  input_to("pick_stat", 0, points, pts_left);
  return;
}

void yes_or_no(string str, int *points, int pts_left) {
  int i;
  int dev_tot;
  string *hands;
  object who;
who = this_player();
  
  if(str) str = lower_case(str);
  if(!str || (str != "yes" && str != "no")) {
    printf("Please enter 'yes' or 'no': ");
    input_to("yes_or_no", 0, points, pts_left);
    return;
  }
  if(str == "no") {
    assign_point(0, points, pts_left);
    return;
  }
  write("\n Finished!");
	who->set_skill("attack",5);
	who->set_skill("trade lore", 5);
	who->set_skill("dodge", 0);
	who->set_skill("parry", 0);
	who->set_skill("melee",0);
	hands = (string *)who->query_wielding_limbs();
	who->set_property("handedness", hands[random(sizeof(hands))]);
	if(!this_player()->query_property("ambidextry"))
	    write("IMPORTANT:  You favor your "+(string)this_player()->
	      query_property("handedness") + ".  Wield weapons there\n"+
	      "when possible.");
	who->set_lang_prof("common",10+(int)this_player()->
	  query_stats("intelligence")/20);
	i=sizeof(STATS);
	dev_tot=0;
	who->set_property("dev points",0);
	while(i--) {
	  who->set_stats(STATS[i],
	    pt_to_stat(points[i]) +
	    (int)RACE_D->query_stat_adjustment(STATS[i][0..2],
              (string)who->query_race()));
	  if(STATS[i] == "charisma") continue;
          switch((int)who->query_stats(STATS[i]) -
		(int)RACE_D->query_stat_adjustment(STATS[i][0..2],
		(string)who->query_race())) {
    case 1..15:
      dev_tot += 2;
      break;
    case 16..25:
      dev_tot += 3;
      break;
    case 26..40:
      dev_tot += 5;
      break;
    case 41..60:
      dev_tot += 7;
      break;
    case 61..75:
      dev_tot += 9;
      break;
    case 76..90:
      dev_tot += 12;
      break;
    case 91..100:
      dev_tot += 15;
      break;
    case 101..105:
      dev_tot += 18;
      break;
    case 106..110:
      dev_tot += 20;
      break;
    case 111..2000:
      dev_tot += 23;
      break;
    default:
      tell_object(who,"There is an ERROR in your stats.\n"+
      "Tell an Arch IMMEDIATELY.\n");
    }
  }
  dev_tot += 9;
  if(dev_tot < 55)
      message("info", "Your stats suck.  If you would like to be deleted, "+
        "ask an Arch immediately!", who);
  who->set_property("dev points",dev_tot);
  who->set_property("dev point base",dev_tot);
  who->set_max_hp(4 * ((int)this_player()->query_stats("constitution") + 20) / 5);
  who->augment_body((int)this_player()->query_stats("constitution"));
  who->set_max_mp(4 * ((int)this_player()->query_stats("intelligence") + 20) / 5);
  who->set_property("base mp regen", 3);
  who->set_property("base hp regen", 3);
  set_ansi();
  who->set("in creation", 0);
  return ;
}

void press_enter(string null, int *points, int pts_left) {
  assign_point(0, points, pts_left);
  return;
}

void pick_stat(string str, int *points, int pts_left) {
  int pts;
  
  if(str && lower_case(str) == "q") {
    assign_point("q", points, pts_left);
    return;
  }
  if(!str || !sscanf(str, "%d", pts)) {
    printf("\nPlease enter a number ('q' to quit): ");
    input_to("pick_stat", 0, points, pts_left);
    return;
  }
  if(pts > pts_left) {
    write(sprintf("You only have %d points left.", pts_left));
    printf("Press [enter] to continue: ");
    input_to("press_enter", 0, points, pts_left);
    return;
  }
  this_player()->set("pt choice", pts);
  printf("\nOk.  To which stat do you want to assign %d points?\n(first 3 letters): ",
    pts);
  input_to("assign_point", 0, points, pts_left);
  return;
}


void set_ansi() {
    this_player()->setenv("TERM", "ansi");
    this_player()->reset_terminal();
    this_player()->reset_max_exp();
    write("\nOne more thing...\n%^RED%^Is this line red (y or n)?%^RESET%^");
    input_to("set_ansi_two");
}

void set_ansi_two(string str) {
  
    str = arrange_string(lower_case(str), 1);
    if(str == "n") {
	write("Ok.  Terminal set to \"unknown.\"  See 'help setenv' for more info.");
	this_player()->setenv("TERM","unknown");
	this_player()->reset_terminal();
          this_player()->move(ROOM_NEWBIE);
       if(wizardp(this_player()) || this_player()->query_property("reincarnate")) {
          write("You are done.");
          return;
        }
        
	return;
    }
    else if(str == "y") {
	write("Terminal set to ansi.");
          this_player()->move(ROOM_NEWBIE);
        if(wizardp(this_player()) || this_player()->query_property("reincarnate")) {
          write("You are done.");
          return;
        }
        
	return;
    }
    else {
	write("Answer y or n");
	input_to("set_ansi_two");
	return;
    }
}

void mail_pass(string pname, string email, string pass) {
  write_file("/tmp/mail_list", sprintf("%s %s %s\n",pname, pass, email));
  return;
}

void read_cb(int sock, string mesg) {
  seteuid(UID_LOG);
  log_file("mail_pass", "Message from mailer at "+ctime(time())+"\n"+
	mesg+"\n");
  seteuid(getuid());
}

void write_cb(int sock) {
  return;
}

void close_cb(int sock) {
  return;
}

int read(string str) {
    if(!str) {
	notify_fail("What do you want to read? A list?\n");
	return 0;
    }
    if(str != "list") {
	notify_fail("That is not here to be read.\n");
	return 0;
    }
    write("These are the following races available in our reality:");
    write("-----------------------------------------------------------");
    message("Ninfo", format_page((string *)RACE_D->query_races(), 4),
      this_player());
    write("----------------------------------------------------------");
    write("pick <race> will forever make you one of these races");
    write("Type help <race> for more information.");
    return 1;
}
