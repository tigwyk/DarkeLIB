//  	A join room for your mom, well commented and intended fo use as
//	an example room of this type.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

//	NOTE:  Before coding any guild, Diewarzau must know the filename
//	of the join_room so he can set the file privs accordingly.

inherit "/std/guilds/join_room";

void create() {
  //  IMPORTANT:  The following MUST appear before ::create();
  set_class_name("chaotic-lord");

  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
new("d/damned/guilds/join_rooms/tcan")->move(this_object());
  set("short", "The Chaotic Lords's Guild Joining Room");
  set("long", 
"This is a the Chaotic Lords's Guild joining room.  It is very well lit"
" dimly with candles lining the walls.  In the center of the room there"
" is a altar with dried blood on the edges.  On west side of the room"
" there is a large statue of a demon lord.\n");
  //  The "\n" is important at the end of the long desc.
   add_exit("/d/daybreak/room/dbvl5", "south");
   add_exit("/d/damned/guilds/chaotic-lord/chaotic-lord_train_room", "west");
  add_exit("/d/damned/guilds/chaotic-lord/chaotic-lord_spell_room", "east");

  set_related_guilds(( {"necromancer"} ));

  set("guildmaster", "/d/damned/guilds/chaotic-lord/chaotic-lord_gm");
  //  The guildmaster is automatically cloned if no pc guildmaster is
  //  found.

  set_guild_obj("/d/damned/guilds/chaotic-lord/chaotic-lord_obj");
  //  This is the filename for the guild's guildmaster object, carried
  //  by the PC guildmaster if any.

  //  The following lines set the properties for the guild.

  set_property("base hp regen", 6);
  set_property("base mp regen", 6);
  //  Base heling per tick.  Note that the default is 3 for both.
  //  Keep in mind that this increases with level.

  set_property("hp advance", 30);
  set_property("mp advance", 23);
  //  Base advance per level im max mp/hp.  Default is 10.

  set_property("guild mods",
    ([ "strength" : 2, "constitution" : 4, "intelligence" : 8 ]) );
  //  Stat mods received upon joining.

  //  The following line is necessary:
  this_object()->reset();
  return;
}

