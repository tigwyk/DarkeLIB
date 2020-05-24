//	An example skill training room for the paladin's guild.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/spell_room";

void create() {
  ::create();
  set("short", "The Paladins' Spell Training Room");
  set("long", 
"This is where paladins study vast amounts of religious texts in order "
"to master the various spells available to them.\n");
  //  "\n" important here, too.

  set_property("light", 2);
  set_property("indoors", 1);
  
  //  The following line is VERY, VERY important.
  set_join_room("/d/damned/guilds/join_rooms/paladin_join");

  add_exit("/d/damned/guilds/join_rooms/paladin_join","west");
  //  All the rest is adding the spells.  The add_skill lines are of the
  //  following form:
  //  	add_spell(string spell, int level, int flag)
  //	spell 		The name of the spell which is being added
  // 	level		(optional) The level at which the player may begin
  //			developing the spell.  If not supplied,
  //			the default level is used.
  //	flag		(optional)  If a non-zero number is supplied,
  //			the skill will be considered "secondary" to
  //			the guild and cost double to develop.


  add_spell("bless armour", 3);
  add_spell("cure light wounds",3);
  add_spell("protection from chaos",3);
  add_spell("holy light",3);
  add_spell("holy word", 3);

  add_spell("bless weapon", 4);
  add_spell("divine might",4);
  add_spell("satisfy thirst",4);
  add_spell("satisfy hunger",4);

  add_spell("preserve corpse",5);
  add_spell("holy armour",5);

  add_spell("remove poison",6);

  add_spell("cure serious wounds",7);

  add_spell("blessing of agility", 8);
  add_spell("blessing of knowledge", 8);

  add_spell("sanctuary",9);
  add_spell("summon aerial servant",9);

  add_spell("cure critical wounds",11);

  add_spell("armour of faith",13);

  add_spell("divine transformation",14);

  add_spell("heal",15);
  
  add_spell("scales of justice", 16);

  add_spell("mass heal",17);
  add_spell("summon elder seraph", 17);

  add_spell("holy mission", 18);

  add_spell("deus ex machina");
  add_spell("holy strike");
  add_spell("holy fury");
  add_spell("divine punishment");
  add_spell("sanctify blade");
  add_spell("holy blade");
  add_spell("holy awareness");
  add_spell("holy aura");
  add_spell("chaos bane");
  add_spell("divine favor");
  return;
}
