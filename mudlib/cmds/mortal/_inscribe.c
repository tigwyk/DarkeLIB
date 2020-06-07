//	Inscribe command used to call runes from /std/runes
//	DarkeLIB 0.1
//	Diewarzau 4/4/94

#include <std.h>

int cmd_inscribe(string str) {
    string rune, arg, file;
    int level;
    object rune_ob;


if(this_player()->query_ghost()) {
        notify_fail("You cannot do that in an immaterial state.\n");
        return 0;
   }
    seteuid(getuid());
    if(!str || (sscanf(str,"%s at %s", rune, arg) != 2 &&
        !sscanf(str,"%s",rune)))
	return notify_fail("Usage: inscribe <rune> at <weapon/armour>\n");
    if(!wizardp(TP) && !TP->query_skill("rune inscription"))
	return notify_fail("You do not know that rune.\n");
    if(wizardp(this_player())) file = "/wizards/"+
				 (string)this_player()->query_name()+"/runes/"+
      replace_string(rune, " ", "_")+".c";
    else file = 0;
    if(!file || !file_exists(file))
      file = "/std/runes/"+replace_string(rune, " ", "_")+".c";
    if(!file_exists(file))
        return notify_fail("That rune is latent and cannot be used.\n");
    if(!function_exists("rune_func",find_object_or_load(file)))
	      return notify_fail("That rune is latent and cannot be used.\n");
    rune_ob = clone_object(file);
  if(!wizardp(TP)) {
    rune_ob->set_property("skill level", (int)this_player()->query_skill("rune inscription"));
  }
   else if(wizardp(TP)) {
      if(TP->query_property("ALL SKILLS"))
        rune_ob->set_property("skill level", TP->query_property("ALL SKILLS"));
      else rune_ob->set_property("skill level", 100);
  }
  if(TP->getenv("DEBUG") == "1")
    message("info","Skill Level: "+rune_ob->query_property("skill level"), TP);
  rune_ob->do_rune(this_player(),arg);
  return 1;
}

void help() {
message("help",
"This command is used to inscribe runes.  The syntax is:\n"
"inscribe <rune> at <weapon/armour>\n"
"<rune> is the rune to be used, the rest is self-explanatory"
"See: skills",
this_player());
}















