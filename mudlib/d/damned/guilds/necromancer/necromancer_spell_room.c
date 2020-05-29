//	An example skill training room for the necromancer's guild.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/spell_room";

void create() {
  ::create();
  set("short", "The Dark library of the Necromancers'");
  set("long", 
"This is the Dark Library of the Necromancers', a room where the dark magic of undeath are spun and wielded.  The floor of this room is carpeted by a sheet of cold obsidian, which gives the room a strange and eerie feeling.  The walls of the library are covered with tall shelves filled with a multitude of books about the undead.  On the far end of the room, across from the entrance, is a set of stairs which descend down to the crypt of the Necromancers' guild.
In the middle of this rooms sits a large tome titled, The Grim Grimoire.  The tome sits precariously on top of a pedastal made of human bones and skulls.
");
  //  "\n" important here, too.

  set_property("light", 2);
  set_property("indoors", 1);
  
  //  The following line is VERY, VERY important.
  set_join_room("/d/damned/guilds/join_rooms/necromancer_join");

  set_exits( 
	({"/d/damned/guilds/necromancer/train_room",
	"/d/damned/guilds/necromancer/necro_spell2_room"
	}),
	({"east", "down"}));
  //  following form:
  //  	add_spell(string spell, int level, int flag)
  //	spell 		The name of the spell which is being added
  // 	level		(optional) The level at which the player may begin
  //			developing the spell.  If not supplied,
  //			the default level is used.
  //	flag		(optional)  If a non-zero number is supplied,
  //			the skill will be considered "secondary" to
  //			the guild and cost double to develop.

    add_spell("wind of death");
  add_spell("chilling touch",1);
  add_spell("curse");
  add_spell("darkness",1);
  add_spell("nether sight", 1);
  add_spell("drain life",3);
   add_spell("lich form");
  add_spell("cold blast");
  add_spell("unholy armour");
  add_spell("decay");
  add_spell("rot");
  add_spell("lifesteal");
  add_spell("transport undead");
  add_spell("undead dimension");
  add_spell("freeze skin");
  add_spell("shadow form");
  add_spell("hex", 2);
  add_spell("embalm corpse", 2);
  return;
}






