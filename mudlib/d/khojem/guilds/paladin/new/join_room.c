//  ** copy to /d/damned/guilds/join_rooms/paladin
//  	A join room for paladins, well commented and intended fo use as
//	an example room of this type.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

//	NOTE:  Before coding any guild, Diewarzau must know the filename
//	of the join_room so he can set the file privs accordingly.

//  Reworked by Khojem-10/17/96

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
    "This is the foyer of the infamous Paladin's Guild.  "
    "It serves as a focal point to join this guild.  "
    "The massive arched and buttressed ceiling is sculptured "
    "with many religious ornamentations and forms a massive "
    "space that echoes your every footstep.  The floor is "
    "constructed of marble and inlayed with an alternating "
    "sequence of white crosses against a black offset.  Rising "
    "up in the center of the floor is a massive cross that "
    "towers up and fills the void above your head.\n"
  );
//  The "\n" is important at the end of the long desc.
  set_items(([
    ({ "floor", "marble floor" }) :
       "The marble floor is finely crafted of white marble in the "
       "shape of a cross against a contrasting black marble backdrop.  "
       "The contrast brings to mind the constrast between good and "
       "evil.",
    ({ "ceiling", "arched ceiling", "buttressed ceiling", "buttress" }) :
       "The ceiling arches high above your head.  Its great height "
       "creates a massive space to an otherwise narrow hallway.  "
       "The arches are heavily sculpted and decorated with religious "
       "symbols.  Occasionally, a few white doves can be seen flying "
       "about as they move from one arch before coming to rest on "
       "another.",
    ({ "cross", "basalt cross" }) :
       "The cross is massive.  It is honed from a massive single "
       "stone of basalt.  It must weight tons.  The cross's gray "
       "surface is smooth except for a few sword and axe cuts that "
       "it suffered during the occasional siege from an evil foe.", 
  ]));

add_exit("/d/khojem/port/room/r1","northeast");
add_exit("/d/damned/guilds/paladin/meeting","southwest");
  
//  The guildmaster is automatically cloned if no pc guildmaster is
//  found.  
set("guildmaster", "/d/damned/guilds/paladin/paladin_gm");
  
//  This is the filename for the guild's guildmaster object, carried
//  by the PC guildmaster if any.
set_guild_obj("/d/damned/guilds/paladin/paladin_obj");

//  The following lines set the properties for the guild.
  
//  Base healing per tick.  Note that the default is 3 for both.
//  Keep in mind that this increases with level.
set_property("base hp regen", 6);
set_property("base mp regen", 4);

//  Base advance per level max mp/hp.  Default is 10.
set_property("hp advance", 35);
set_property("mp advance", 18);

//  Stat mods received upon joining.
set_property("guild mods",
  ([ "strength" :  5, "constitution" : 5, "wisdom" : 5 ]) );

//  The following line is necessary:
this_object()->reset();
return;
}

