//  	A join room for fighters, well commented and intended fo use as
//	an example room of this type.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

//	NOTE:  Before coding any guild, Diewarzau must know the filename
//	of the join_room so he can set the file privs accordingly.

inherit "/std/guilds/join_room";

void create() {
  //  IMPORTANT:  The following MUST appear before ::create();
  set_class_name("cleric");

  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
new("d/damned/guilds/join_rooms/tcan")->move(this_object());
  set_related_guilds(({ "paladin", "war-priest" }));
  set("short", "The Cleric's Guild Joining Room");
  set("long", 
"Several robed individuals mull about in the background.  You have entered "
"the Cleric's Guild.  The walls are adorned with marble and gold, and "
"religious symbols can be seen all about.\nSeveral clerics can be seen "
  "training to the north, and there is a door heading west leading to a small room.\n");
  //  The "\n" is important at the end of the long desc.

   set_exits( ([ "west" : "/d/damned/guilds/cleric/confess",
        "north" : "/d/damned/guilds/cleric/train_room" ]) );
  set("guildmaster", "/d/damned/guilds/cleric/cleric_gm");
  //  The guildmaster is automatically cloned if no pc guildmaster is
  //  found.

  set_guild_obj("/d/damned/guilds/cleric/cleric_obj");
  //  This is the filename for the guild's guildmaster object, carried
  //  by the PC guildmaster if any.

  //  The following lines set the properties for the guild.

  set_property("base hp regen", 3);
  set_property("base mp regen", 6);
  //  Base heling per tick.  Note that the default is 3 for both.
  //  Keep in mind that this increases with level.

  set_property("hp advance", 17);
  set_property("mp advance", 40);
  //  Base advance per level im max mp/hp.  Default is 10.

  set_property("guild mods",
	([ "wisdom" :  10 ]) );
  //  Stat mods received upon joining.

  //  The following line is necessary:
  this_object()->reset();
  return;
}




