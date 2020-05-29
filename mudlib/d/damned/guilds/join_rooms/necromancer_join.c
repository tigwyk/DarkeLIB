//  	A join room for necromancers, well commented and intended fo use as
//	an example room of this type.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

//	NOTE:  Before coding any guild, Diewarzau must know the filename
//	of the join_room so he can set the file privs accordingly.

inherit "/std/guilds/join_room";

/*
void init(){
	::init();
	add_action("no_south", "south");
}
*/
void create() {
  //  IMPORTANT:  The following MUST appear before ::create();
  set_class_name("necromancer");

  ::create();
  set_property("light", 3);
  set_property("indoors", 1);
new("d/damned/guilds/join_rooms/tcan")->move(this_object());
  set_related_guilds(({ "arch-mage", "elementalist", "enchanter" }));
  set("short", "The Necromancer's Guild Joining Room");
  set("long", 
"This is a the Necromancer's Guild joining room.  It is a darkly forbidding "
"place with the only light coming from black candles that line the wall. "
"There are jars filled with embalming fluids and other things that cannot "
"be named sitting on shelves on the far wall.  A large skull with jeweled "
"eyes is carved into the wall.\n");
  //  The "\n" is important at the end of the long desc.

  set_exits( ([ "north" : "/d/nocte/kuril/rooms/entrance",
		"south" : "/d/damned/guilds/necromancer/train_room" ]));

  set("guildmaster", "/d/damned/guilds/necromancer/necromancer_gm");
  //  The guildmaster is automatically cloned if no pc guildmaster is
  //  found.

  set_guild_obj("/d/damned/guilds/necromancer/necromancer_obj");
  //  This is the filename for the guild's guildmaster object, carried
  //  by the PC guildmaster if any.

  //  The following lines set the properties for the guild.

  set_property("base hp regen", 2);
  set_property("base mp regen", 12);
  //  Base heling per tick.  Note that the default is 3 for both.
  //  Keep in mind that this increases with level.

  set_property("hp advance", 6);
  set_property("mp advance", 45);
  //  Base advance per level im max mp/hp.  Default is 10.

  set_property("guild mods",
	([ "intelligence" : 10 ]) );
  //  Stat mods received upon joining.

  //  The following line is necessary:
  this_object()->reset();
  return;
}

/*
int no_south(){
	if(wizardp(this_player())) {return 0;}
	if(TP->is_pet()) { return 0; }
	if(this_player()->query_class() == "necromancer") {return 0;}
	message("info", "Only Necromancers may enter this school.", this_player());
	return 1;
}
*/
