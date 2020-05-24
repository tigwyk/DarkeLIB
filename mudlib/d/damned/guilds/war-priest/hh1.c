// Coder: %^GREEN%^nEv!N%^RESET%^
// Darkemud
// Modified from train_room.c code
// 10/05/96

//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/skill_room";

void create() {
  ::create();
  set("short", "Chamber of Prowess");
  set("long", 
	"This large chamber if largely devoid of any furniture.  Instead, "
	"the room in filled with weapons and training equipment.  It is "
	"here that the Priests of K'thach come to train their fighting "
	"skills.  It is required that any Priest of K'thach be ready to "
	"defend himself and his faith at any time.\n");
  //  "\n" important here, too.
  set_property("light", 2);
  set_property("indoors", 1);
  
  //  The following line is VERY, VERY important.
  set_join_room("/d/damned/guilds/join_rooms/war-priest_join");

  add_exit("/d/damned/guilds/war-priest/hh2", "east");
  
  //  All the rest is adding the skills.  The add_skill lines are of the
  //  following form:
  //  	add_skill(string skill, int level, int flag)
  //	skill 		The name of the skill which is being added
  // 	level		The level at which the player may begin
  //			developing the skill.
  //	flag		(optional)  If a non-zero number is supplied,
  //			the skill will be considered "secondary" to
  //			the guild and cost double to develop.

  add_skill("parry", 3, 1);
  add_skill("block", 1, 1);
  add_skill("body block", 3, 1);
  add_skill("dodge", 5, 1);
  add_skill("attack", 1);
  add_skill("melee", 1, 1);
  add_skill("blunt", 1);
  add_skill("blade", 1, 1);
  add_skill("two handed blunt", 1);
  add_skill("flail", 1, 1);
  add_skill("two handed flail", 1, 1);
  add_skill("two handed blade", 1, 1);
  add_skill("offhand training", 10, 1);
  add_skill("dual attack", 17, 1);
  add_skill("concentrate",3);
  return;
}
