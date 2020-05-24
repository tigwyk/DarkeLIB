//	An example skill training room for the Chaotic Lords's guild.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/spell_room";

void create() {
  ::create();
  set("short", "The Chaotic Lords' Spell Training Room");
  set("long", 
"This is where Chaotic Lords study vast amounts of dark texts in order "
"to master the various spells available to them.\n");
  //  "\n" important here, too.

  set_property("light", 2);
  set_property("indoors", 1);
  
  //  The following line is VERY, VERY important.
  set_join_room("/d/damned/guilds/join_rooms/chaotic-lord_join");

  add_exit("/d/damned/guilds/join_rooms/chaotic-lord_join","west");
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

   add_spell("demon lord sword");
  add_spell("disruption bolt",3);
   add_spell("chaos ball",10);
  add_spell("chaos storm",23);
  add_spell("summon lesser demon");
  add_spell("bind demon lord");
  add_spell("summon demon");
  add_spell("summon greater demon");
  add_spell("summon demon lord");
  add_spell("bind lesser demon");
  add_spell("bind demon");
  add_spell("bind greater demon");
  add_spell("lesser demon sword");
  add_spell("demon sword");
  add_spell("greater demon sword");
  add_spell("vampiric blade");
  add_spell("lifesteal blade");
  add_spell("essence blade");
  add_spell("soultaker blade");
  add_spell("demonic rebirth");
//ADD per question TLNY2020 - Changed to demon haste - HONSPRON2020
  //add_spell("fury of marghuul", 11);
  add_spell("demon haste", 11);
    return;
}








