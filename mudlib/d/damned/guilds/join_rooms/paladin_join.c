//  	A join room for paladins, well commented and intended fo use as
//	an example room of this type.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

//	NOTE:  Before coding any guild, Diewarzau must know the filename
//	of the join_room so he can set the file privs accordingly.

inherit "/std/guilds/join_room";

void create() {
  //  IMPORTANT:  The following MUST appear before ::create();
  set_class_name("paladin");

  ::create();
  set_property("light", 3);
  set_property("indoors", 1);
new("d/damned/guilds/join_rooms/tcan")->move(this_object());
  set_related_guilds(({ "cleric", "fighter" }));
  set("short", "The Paladin's Guild Joining Room");
  set("long", 
"This is a the Paladin's Guild joining room.  It is very well lit with "
"candles lining the walls along with white shields.  There is a large "
"cross mounted on the wall facing the entrance.\n");
  //  The "\n" is important at the end of the long desc.

   set_exits( ([ "north" : "/d/daybreak/room/dbbw3",
	        "west" : "/d/damned/guilds/paladin/train_room" ]) );
  add_exit("/d/damned/guilds/paladin/paladin_spell_room", "east");

  set("guildmaster", "/d/damned/guilds/paladin/paladin_gm");
  //  The guildmaster is automatically cloned if no pc guildmaster is
  //  found.

  set_guild_obj("/d/damned/guilds/paladin/paladin_obj");
  //  This is the filename for the guild's guildmaster object, carried
  //  by the PC guildmaster if any.

  //  The following lines set the properties for the guild.

  set_property("base hp regen", 6);
  set_property("base mp regen", 4);
  //  Base heling per tick.  Note that the default is 3 for both.
  //  Keep in mind that this increases with level.

  set_property("hp advance", 35);
  set_property("mp advance", 18);
  //  Base advance per level im max mp/hp.  Default is 10.

  set_property("guild mods",
	([ "strength" :  5, "constitution" : 5, "wisdom" : 5 ]) );
  //  Stat mods received upon joining.

  //  The following line is necessary:
  this_object()->reset();
  return;
}

