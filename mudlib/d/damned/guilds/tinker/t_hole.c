inherit "std/vault";


string join_room;

void reset() {
  object ob;
   ::reset();
   if (!present("fruno")) {
      new("/d/damned/guilds/tinker/fruno")->move(this_object());
   }
   if(!present("furnace")) {
    ob = new("/d/excelsior/tinker/furnace");
    ob->set_property("no get", 1);
    ob->move(this_object());
   }
/*
(NO FORGE? so removed it and put in furnace room starts working JLAU)
if(!present("forge")) {
    ob = new("/d/excelsior/tinker/forge");
    ob->set_property("no get", 1);
    ob->move(this_object());
   }

   if(!present("sign"))
   	new("/wizards/excelsior/tinker/tinker_shop_sign")->move(this_object()); 
   return;
*/
}

void create() {
/* this room rocks because of Excelsior. Don't forget it!
   this is an odd place for this comment
   4-22-96

   Yeah, you're awesome Excelsior. :)  I changed the room's description
   to remove the lists of minerals, weapons, armours, etc., which are
   now located in the entrance room.

   Duridian   10/13/96
*/

   ::create();
	restore_object("/open/stuff");
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/guilds/tinker/special_room", "south");
   //add_exit("/d/damned/guilds/join_rooms/tinker_join", "east");
   add_exit("/d/damned/guilds/tinker/t_hole_storage", "north");
   set_door("iron door", "/d/damned/guilds/tinker/t_hole_storage",
      "north", "hole shop store");
   set_open("iron door", 0);
   set_locked("iron door", 1);
   set_lock_level("iron door", 25);
   set("short","The Special Shop");
   set("long",
"The tiny hole that you are in is cramped to the max.  "
"Fruno looks at you with glittering eyes as he has not seen "
"vistors in a long time. He wavees at you and becons you to come"
"closer and look to see what special items he has for sale!\n");
   set_items( (["iron door" : "It looks quite sturdy",
   "door" : "There is an iron door here.",
/*	({"element list","mineral list","list"}):
   "Element      Hardness   Type           WC Bonus  AC Bonus%^RESET%^  \n"
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n"
   "Eog             10     Nullification     XXX        XX\n"  
   "Eonmite         5      Time               XX         \n"
   "Iysaughton      6      Chaos              XX         \n"
   "Laen            9      Reflection                  XXX\n"
   "Neorolite       4      Limb Severer        X\n"
   "Mabril          4      Stunning            X\n"
   "Platnite        5      Electricity        XX\n"
   "Mithril         7      Flaming            XX        XX\n"
   "Elrodnite       6      Frost              XX\n"
   "Inniculmoid     7      Force              XX        XX\n"
   "Raysorite       6      Singing            XX\n"
   "Catoetine       4      Quickness           X        XX\n"         
   "Javednite       5      Bone Breaker        X\n"
   "Davistone       5      Weapon Breaker      X\n"
   "Mcgrail         4      Darkness            X\n"
   "Boernerine      3      Light               X\n"
   "Steel           2      None              \n"
   "Iron            1      None                 \n"
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n"
   "%^GREEN%^Note: This list is from most powerful to least.%^RESET%^\n",
   "sign" : "The say reads: 'say bruno, help' for assistance.\n"
    "There is also a list of weapons and a list of armours on the wall.",
   "weapon list" :
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n"
   "%^GREEN%^Any of these weapons can be made by tinkers. \n"
   "Please mail excelsior if you have more weapons you want added.%^RESET%^\n\n"
   "footman's-mace, battle-axe, hand-axe, dagger, footman's-flail,\n"
   "military-fork, glaive, halberd, long-sword, bastard-sword, \n"
   "short-sword, two-handed-sword, broad-sword, great-axe, quarter-staff,\n"
   "morning-star, scimitar, war-hammer, hammer, military-pick, spear,\n"
   "trident\n\nWith the carpentry skill:\nquarter-staff\n"
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n",
   "armour list" :
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n"
   "%^GREEN%^Any of these armours can be made by tinkers. \n"
   "Please mail excelsior if you have more armours you want added.%^RESET%^\n\n"
   "breast-plate, corslet, chain-coif, scale-greaves, iron-greaves,\n"
   "scale-mail, chain-greaves, chain-mail, great-helm, wall-shield,\n"
   "large-shield, small-shield, buckler-shield, gauntlet, chain-glove,\n"
   "iron-bracer.\n"
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n",
   "clothes list":
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n"
   "%^GREEN%^Any of these armours can be made by tinkers with the \n"
   "leather craft skill. Please mail excelsior if you have more \n"
   "armours you want added.%^RESET%^\n\n"
   "leather-vest, leather-jacket, leather-pants,leather-golve,\n"
   "studded-leather-vest, studded-leather-pants, studded-leather-glove\n"
   "leather-boots\n"
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n" 
*/
   "sign" : "The sign reads: 'say fruno, help' for assistance.\n"
   ]) );
   join_room = "/d/damned/guilds/join_rooms/tinker_join";
}


int allow_shop(string who) {
	object ob;
	string action;
	if(who == "all") {
		if(wizardp(this_player()) || (string)join_room->query_master() ==
				(string)this_player()->query_name() || 
				member_array("allow open",join_room->query_member_privs(
					(string)this_player()->query_name())) >= 0) {
			if(query_property("shop open")) {
				 set_property("shop open",0);
				action = "close";
			} else {
				 set_property("shop open",1);
				action = "open";
			}
			write("%^GREEN%^You "+action+" the shop to the general public.");
				save_object("/open/stuff");
			return 1;
		} else {
			notify_fail("You are not qualified to do that.\n");
		}
	}
	if(!who) notify_fail("Who do you want to allow to shop?\n");
	ob = find_player(who);
	if(!ob) notify_fail("Could not locate player \""+capitalize(who)+"\".\n");
	if(ob) {
		write("You allow "+capitalize(who)+" to enter the shop.");
		ob->set("allow shop tinker",1);
		return 1;
	}
	return 0;
}

void init() {
	::init();
	add_action("allow_shop","shopallow");
}

/*
int receive_objects() {
  object who;
  who = previous_object();
  if(!who) return 0;
  if(!who->is_player()) return ::receive_objects();
  if(!join_room) {
    write("BUG!  Join_room not found");
    return 1;
  }
  if(wizardp(who) || !who->is_player()) return ::receive_objects();
  if(environment(who) && member_array("std/guilds/spell_room.c", deep_inherit_list(environment(who)))
    >= 0) return ::receive_objects();
  if(query_property("shop open")) return ::receive_objects();
  if((int)who->query_skill("stealth") > 82+random(60)) {
  	write("%^RED%^You manage to sneak into the shop using your "+
  		"stealth skill!");
  	return 1;
  }
  if(join_room->is_member((string)who->query_name())) return 1;
  if((string)join_room->query_member_status((string)who->query_name()) ==
     "allow train") {
    return 1;
  }
  if((int)who->query("allow shop tinker")) {
  	write("You have been allowed to enter the shop, but only this once!");
  	who->set("allow shop tinker",0);
  	return 1;
  }
  write("You must be either a member of this guild or have special permission from "+
        "a guild member to use this shop.");
  return 0;
}

*/
