//  	A join room for enchanters, well commented and intended fo use as
//	an example room of this type.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

//	NOTE:  Before coding any guild, Diewarzau must know the filename
//	of the join_room so he can set the file privs accordingly.

inherit "/std/guilds/join_room";

void create() {
  //  IMPORTANT:  The following MUST appear before ::create();
  set_class_name("enchanter");

  ::create();
  set_property("light", 3);
  set_property("indoors", 1);
new("d/damned/guilds/join_rooms/tcan")->move(this_object());
  set_related_guilds(({ "arch-mage", "elementalist", "necromancer" }));
  set("short", "The Enchanter's Guild Joining Room");
  set("long", 
"This is the Enchanter's Guild joining room.  It is a cluttered room "
"filled with papers and gadgets.  There are magical formulae scribbled "
"everywhere on the walls and you can see strange mechanical beasts lumbering"
"  about, doing wizard's tasks.\n ");

  //  The "\n" is important at the end of the long desc.

  set_exits( ([ "west" : "/d/daybreak/room/dbcc4",
	        "north" : "/d/damned/guilds/enchanter/train_room" ]) );

  set("guildmaster", "/d/damned/guilds/enchanter/enchanter_gm");
  //  The guildmaster is automatically cloned if no pc guildmaster is
  //  found.

  set_guild_obj("/d/damned/guilds/enchanter/enchanter_obj");
  //  This is the filename for the guild's guildmaster object, carried
  //  by the PC guildmaster if any.

  //  The following lines set the properties for the guild.

  set_property("base hp regen", 3);
  set_property("base mp regen", 10);
  //  Base heling per tick.  Note that the default is 3 for both.
  //  Keep in mind that this increases with level.

  set_property("hp advance", 14);
  set_property("mp advance", 37);
  //  Base advance per level im max mp/hp.  Default is 10.

  set_property("guild mods",
	([ "intelligence" : 10, "dexterity" : 5 ]) );
  //  Stat mods received upon joining.

  //  The following line is necessary:
  this_object()->reset();
  return;
}



