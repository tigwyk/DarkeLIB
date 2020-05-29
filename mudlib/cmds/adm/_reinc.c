//    Command for reincarnating players...useful for re-openings, etc.

//    Allows players to advance levels whenever they want, so they don't

//    get waxed by fast development costs!

//

//    DarkeLIB 1.0

//    -Diewarzau 1/15/96



#include <std.h>

#include <daemons.h>

#include <security.h>



int cmd_reinc(string str) {

  object who, join_room, *inv;

  int lev, i;

  string *langs;

  

  if(!archp(this_player()))return 0;

  if(!member_group((string)this_player()->query_name(),  "superuser"))

    return notify_fail("Only superusers may do this.\n");

  if(!(who = find_player(lower_case(str)))) {

    write("Can't find '"+str+"'.");

    return 1;

  }

  if(wizardp(who)) {

    write("You can't reincarnate a wizard.");

    return 1;

  }

  who->remove_property("luck");

  who->remove_property("limb regen");

  who->remove_property("ambidextry");

  who->remove_property("flying");

  who->remove_property("natural ac");

  who->remove_property("extra hbeat");

  who->remove_property("extra hp regen");

  who->remove_property("extra mp regen");

  who->remove_property("sp points");

  who->remove_property("sp skills");

  who->remove_property("sp spells");

  who->reset_quests();

  langs = (string *)who->query_all_languages();

  if(langs && pointerp(langs) && (i=sizeof(langs))) {

    while(i--) who->remove_language(langs[i]);

  }

  inv = filter_array(all_inventory(who), (: call_other :),

    "query_auto_load");

  if(inv && sizeof(inv)) {

    i = sizeof(inv);

    while(i--)

      if(!inv[i]->id("clan symbol")) inv[i]->remove();

  }

  who->init_skills();

  who->set_property("reincarnate", 1);

  who->init_spells();

  if(who->query_class() && (string)who->query_class() != "child") {

    join_room = find_object_or_load("/d/damned/guilds/join_rooms/"+

          (string)who->query_class() + "_join");

    join_room->kick_member((string)who->query_name());

  }

  who->set_property("xp mod", 0);

  lev = (int)who->query_level();

  if(lev < 1) lev = 1;



  who->set_property("old exp", (int)ADVANCE_D->get_exp(lev) + 150);

  who->set_level(1);


  who->add_exp(-1 * (int)who->query_exp());

  who->reset_max_exp();

  who->move_player("/d/standard/setter", 0);

  seteuid(UID_LOG);

  log_file("reinc", sprintf("FREE reinc: %s to %s on %s.\n",

(string)previous_object()->query_name(), (string)who->query_name(), ctime(time())));

  message("info", "%^CYAN%^%^BOLD%^You have been reincarnated!",who);

  message("info",

  "\n     You may re-create your character now.  Afterward, you may "

  "join a guild as usual.  All of your former exp has been transferred "

  "into a 'exp bank,' and you may access it by typing 'advance'.  That "

  "will advance your level by 1 each time you type it, until you "

  "are out of exp.  If you advance your level naturally, you will "

  "forfeit ALL REMAINING EXP in the bank!", who);

  write((string)who->query_cap_name() + " has been reincarnated.");

  return 1;

}



int help() {

  write(

  "Usage: reinc 'player'\n"

  "Starts a player over with NO penality.");

  return 1;

}



  

