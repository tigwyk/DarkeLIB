//  	A join room for fighters, well commented and intended fo use as
//	an example room of this type.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

//	NOTE:  Before coding any guild, Diewarzau must know the filename
//	of the join_room so he can set the file privs accordingly.

inherit "/std/guilds/vault_join_room";

void create() {
  //  IMPORTANT:  The following MUST appear before ::create();
  set_class_name("fighter");

  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
new("d/damned/guilds/join_rooms/tcan")->move(this_object());
     set_related_guilds(({ "tinker", "sword-mage" }));
  set("short", "The Fighter's Guild Joining Room");
  set("long", "The walls here are lined with decorative weapons in the "+
      "tradition of the age-old Fighter's Guild.  You see a shop to the "+
    "west and a busy room to the north.  The Fighter Trainer is Ruck.\n");
  //  The "\n" is important at the end of the long desc.

  set_exits( ([ "east" : "/d/daybreak/room/dbvl2",
		"west" : "/d/damned/guilds/fighter/fighter_shop",
	      "north" : "/d/damned/guilds/fighter/train_room" ]) );

  set_door("door", "/d/damned/guilds/fighter/fighter_shop", "west",
	   "fighter shop key");
  set_open("door", 1);
  set_locked("door", 0);
  set_close_function("close_door", "16:00:00");
  set_open_function("open_door", "7:00:00");
  set("guildmaster", "/d/damned/guilds/fighter/fighter_gm");
  //  The guildmaster is automatically cloned if no pc guildmaster is
  //  found.

  set_guild_obj("/d/damned/guilds/fighter/fighter_obj");
  //  This file points to the guildmaster object.

  //  The following lines set the properties for the guild.

  set_property("base hp regen", 10);
  set_property("base mp regen", 2);
  //  Base heling per tick.  Note that the default is 3 for both.
  //  Keep in mind that this increases with level.

  set_property("hp advance", 45);
  set_property("mp advance", 4);
  //  Base advance per level im max mp/hp.  Default is 10.

  set_property("guild mods",
	([ "strength" :  10, "constitution" : 10 ]) );
  //  Stat mods received upon joining.

  //  The following line is necessary:
  this_object()->reset();
  return;
}

void open_door() {
  call_other("/d/damned/guilds/fighter/fighter_shop", "open_door");
  return;
}

void close_door() {
  call_other("/d/damned/guilds/fighter/fighter_shop", "close_door");
  return;
}
