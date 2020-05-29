// Join room for the War-Priests

//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

//	NOTE:  Before coding any guild, Diewarzau must know the filename
//	of the join_room so he can set the file privs accordingly.

inherit "/std/guilds/join_room";

// void init() {
//         ::init();
//         add_action("check_north", "north");
// }

void create() {
  //  IMPORTANT:  The following MUST appear before ::create();
  set_class_name("war-priest");

  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
new("d/damned/guilds/join_rooms/tcan")->move(this_object());
  set_related_guilds(({ "cleric", "paladin" }));
  set("short", "Hall of the Honoured");
  set("long", 
	"Upon entering the Hall of the Honoured, you swear that the building "
	"is larger on the inside.  A long hallway leads north where an "
	"an altar sits in the distance.\n"
	);
  //  The "\n" is important at the end of the long desc.

  set_exits( ([ 
                "south" : "/d/daybreak/room/dbbw3",
	      "north" : "/d/damned/guilds/war-priest/hh5" ]) );

  set("guildmaster", "/d/damned/guilds/war-priest/war-priest_gm");
  //  The guildmaster is automatically cloned if no pc guildmaster is
  //  found.

  set_guild_obj("/d/damned/guilds/war-priest/war-priest_obj");
  //  This is the filename for the guild's guildmaster object, carried
  //  by the PC guildmaster if any.

  //  The following lines set the properties for the guild.

  set_property("base hp regen", 4);
  set_property("base mp regen", 5);
  //  Base heling per tick.  Note that the default is 3 for both.
  //  Keep in mind that this increases with level.

  set_property("hp advance", 18);
   set_property("mp advance", 32);
  //  Base advance per level im max mp/hp.  Default is 10.

  set_property("guild mods",
	([ "wisdom" :  5, "constitution" : 5 ]) );
  //  Stat mods received upon joining.

  //  The following line is necessary:
  this_object()->reset();
  return;
}

int check_north() {
	if(wizardp(TP)) { return 0; }
	if(TP->query_class() == "war-priest") { return 0; }
	if(TP->is_pet()) { return 0; }
	message("info", "You may not enter the Hall of the Honoured.",
		TP);
	return 1; 
}
