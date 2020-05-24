//  	A join room for arch-mages, well commented and intended fo use as
//	an example room of this type.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95
//	NOTE:  Before coding any guild, Diewarzau must know the filename
//	of the join_room so he can set the file privs accordingly.
//  Khojem - reworked 10/22/96

inherit "/std/guilds/join_room";

void create() {
  //  IMPORTANT:  The following MUST appear before ::create();
  set_class_name("arch-mage");

  ::create();
  set_property("light", 1);
  set_property("indoors", 1);
  new("/d/damned/guilds/join_rooms/tcan")->move(this_object());
  set("short", "The Arch-Mage's Guild Joining Room");
  set("long",
    "The dark, dank hallway ends at a basalt monolith that rises up "
    "from the stone floor.  This is the location for prospective "
    "initiates to join the reclusive Arch Mage Guild.  Here great "
    "and wonderous feats of magic may be learned after much toil "
    "and study.  The walls of the hallway are moist from water "
    "seeping through the cracks of the aged stone blocks.  At "
    "numerous points along the hallway small recesses in the stone "
    "wall form small shelves.  On those shelves rest the skulls of "
    "strange and hideous creatures long extinct from the realms "
    "of DarkeMud.  Resting on each skull is a thick, lit wax candle.\n"
  );
  //  The "\n" is important at the end of the long desc.
  
  set_items(([
    ({ "floor", "stone floor" }) :
       "The basalt floor is roughly hewned into large blocks that "
       "form a maze-like pattern.  What little light cast from the "
       "candles reflects off the seepage moistened stone.",
    ({ "basalt monolith", "monolith" }) :
       "The black monolith is firmly fixed in the middle of the "
       "hallway.  It is squarish with a broad base that tapers "
       "as it rises to about eye level.  Its top is flat and level.  "
       "The surface of the black monolith is grainy and black.  "
       "At several points it is blacked and cracked.  Scorched "
       "flashmarks bear evidence to a great battle.",
    ({ "walls", "stone block", "water", "crack", "cracks" }) :
       "Roughly-cut, gray basalt stones form the walls and ceiling "
       "of this narrow hallway.  The years of water penetrating the "
       "walls have eroded the mortar between the great, massive blocks "
       "and now the water streams down the wall in small rivulets "
       "that form small pools at the base of the floor.",
    ({ "recess", "recesses", "shelf", "shelves", "small recesses" }) :
       "Small recesses frequent the walls along this hallway.  "
       "Most are the size of one of the large blocks that form "
       "the hallway.  Within each recess is a skull of "
       "a long forgotten creature that once roamed DarkeMud.  
       "Fixed upon each skull is a thick wax candle.  ", 
    ({ "candle", "candles", "skull", "skulls" }) :
       "The dim flickering light from the candles reflects off the "
       "white bones of the aged skulls.  The skull's vacant eyes "
       "seem to haunt you and chill runs up your spine.  "
       "For a moment you pause to consider the meaning of the "
       "skulls and the candles.  Of course the "
       "candles provide light in this windowless hallway... "
       "but, why the skulls of extinct animals?  Then suddenly "
       "it dawns upon you that perhaps these are a symbol of "
       "some kind.  A symbol that represents the eons of efforts "
       "by now nameless mages that helped formulate and discover "
       "the powers now possessed by those within this guild.",
  ]));

  set_related_guilds(( {"necromancer","elementalist","enchanter"}));

  add_exit("/d/damned/guilds/arch-mage/meeting","west");
  add_exit("/d/khojem/port/room/t1","east");
  
  set("guildmaster", "/d/damned/guilds/arch-mage/arch-mage_gm");
  //  The guildmaster is automatically cloned if no pc guildmaster is
  //  found.

  set_guild_obj("/d/damned/guilds/arch-mage/arch-mage_obj");
  //  This is the filename for the guild's guildmaster object, carried
  //  by the PC guildmaster if any.

  //  The following lines set the properties for the guild.
  set_property("base hp regen", 2);
  set_property("base mp regen", 14);
  //  Base heling per tick.  Note that the default is 3 for both.
  //  Keep in mind that this increases with level.

  set_property("hp advance", 7);
  set_property("mp advance", 47);
  //  Base advance per level im max mp/hp.  Default is 10.

  set_property("guild mods",
	([ "intelligence" :  10 ]) );
  //  Stat mods received upon joining.

  //  The following line is necessary:
  this_object()->reset();
  return;
}

