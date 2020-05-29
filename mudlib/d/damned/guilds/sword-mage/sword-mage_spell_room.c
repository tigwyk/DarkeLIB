//	An example skill training room for the fighter's guild.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/spell_room";

void init() {
	::init();
	add_action("drink","drink");
		add_action("enter","enter");
}
void create() {
  ::create();
  set("short", "The Sword Mage's Spell Training Room");
  set("long", 
"This room is even darker and more mystic then the one above. "+
"All about the room are ancient tomes and other books. Spaced "+
	"along the walls evenly are brightly burning torches. "+
	"In the middle of the room is a large pot with some sort "+
	"of mystic potion brewing in it. This is obviously the "+
	"sword-mage spell training room.\n");
  //  "\n" important here, too.

  set_property("light", 2);
  set_property("indoors", 1);
  
  //  The following line is VERY, VERY important.
  set_join_room("/d/damned/guilds/join_rooms/sword-mage_join");

  set_exits( ([ "up" : "/d/damned/guilds/sword-mage/train_room" ]) );
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

	set_items((["pot":"You don't really want to know what its for. In it is some kind of potion. Perhaps this warrants further investigation.",
		"potion":"The more you stare at this the more you think you could 'enter' it!" ]));
  add_spell("fireball", 7);
  add_spell("magic missile", 3);
  add_spell("explosive fireball", 15, 1);
  add_spell("lightning bolt", 10);
  add_spell("killing cloud", 8, 1);
  add_spell("ice dagger", 7, 1);
  add_spell("power word, stun", 5);
  add_spell("power word, blind", 9);
  add_spell("light", 3);
  add_spell("scry",12);
  add_spell("haste");
  add_spell("enlarge", 13);
  add_spell("clone");
  add_spell("darkness", 3);
  add_spell("clairvoyance", 5);
  add_spell("faerie fire", 3);
  add_spell("dark vision", 5);
  add_spell("blur", 12);
  add_spell("living weapon", 4);
  add_spell("mirror image", 16);
  add_spell("lesser plasma blade");
  add_spell("greater plasma blade");
  add_spell("mad rage",13);
  add_spell("invisibility", 15);
  add_spell("summon", 15);
  add_spell("transport", 17);
  add_spell("teleport", 17, 1);
  add_spell("create teleport beacon", 17, 1);
  add_spell("fire shield", 14);
  add_spell("blizzard", 21);
  add_spell("meteor storm", 28);
  return;
}

  

int drink(string str) {
	if(str == "potion") {
		write("You think better of drinking it.");
		return 1;
	}
	return 0;
}

int enter(string str) {
	if(str != "potion") {
		notify_fail("Type: enter potion.\n");
			return 0;
	}
	message("info","WTF! "+(string)this_player()->query_cap_name()+" jumps into the vat of liquid and disappears! Is "+(string)this_player()->query_objective()+" crazy!?!",environment(this_player()),({this_player()}));
	write("You enter the potion and reality begins to "+
				"swirl. You find yourself "+
			"elsewhere!");
			this_player()->move("/d/damned/akkad/ak_center");
		message("info",(string)this_player()->query_cap_name()+" comes out of a trap door in the statue. Weird.",
			environment(this_player()),({this_player()}));
	return 1;
}
