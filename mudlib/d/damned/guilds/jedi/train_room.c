//	An example skill training room for the paladin's guild.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/skill_room";

void create() {
  object ob;
  ::create();
  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({"board", "jedi_board"}) );
  ob->set_board_id("jedi_board");
  ob->set_max_posts(20);
  ob->set_location("d/damned/guilds/jedi/train_room");
  ob->set("short","Jedi Board");
  ob->set("long","A board for players to post notes.\n");
  set("short", "The Jedi Training Room");
set("long",
	"You are in a deep dark cave. Chains and manacles hang "+
	"from the walls. You realize that this is the Jedi "+
		"training room, and that Jedi train "+
		"with determination. To the east there "+
			"appears to be a locker room. A fee of 5 silver "+
			"is required to enter. The cave continues down.\n");
  //  "\n" important here, too.
  set_property("light", 2);
  set_property("indoors", 1);
  
  //  The following line is VERY, VERY important.
  set_join_room("/d/damned/guilds/join_rooms/jedi_join");

  add_exit("/d/damned/guilds/join_rooms/jedi_join", "up");
  add_exit("/d/damned/guilds/sword-mage/jedi_treas", "east");
  add_exit("/d/damned/guilds/sword-mage/jedi_spell_room", "down");
  
  //  All the rest is adding the skills.  The add_skill lines are of the
  //  following form:
  //  	add_skill(string skill, int level, int flag)
  //	skill 		The name of the skill which is being added
  // 	level		The level at which the player may begin
  //			developing the skill.
  //	flag		(optional)  If a non-zero number is supplied,
  //			the skill will be considered "secondary" to
  //			the guild and cost double to develop.

  add_skill("lightsaber", 1);
  add_skill("perception",1, 1);
  add_skill("trade lore", 1, 1);
   add_skill("swimming", 1);
   add_skill("melee", 1);
   add_skill("thrown", 1);
   add_skill("jedi lore", 1);
  add_skill("illusionism", 3, 1);
  add_skill("dual-bladed lightsaber", 15);
  add_skill("consider", 1);
  add_skill("compare", 3, 1);
  add_skill("dual attack", 15, 1);
  add_skill("prospecting", 1, 1);
  add_skill("offhand training", 10, 1);
  add_skill("parry", 1, 1);
  add_skill("attack", 1);
  add_skill("body block", 3);
  add_skill("reverse stroke", 15);
  add_skill("dodge", 7, 1);
  add_skill("block", 3, 1);
  add_skill("concentrate", 1);
  return;
}

void reset() {
  ::reset();
  if(!present("guard")) new("/d/damned/guilds/jedi/t_guard")->
      move(this_object());
  return;
}

