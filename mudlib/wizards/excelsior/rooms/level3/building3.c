// /wizards/excelsior/level3/building3
// the tax man

inherit "/std/room";

void reset() {
	::reset();
	if(!present("guard"))
		new("/wizards/excelsior/mon/spear_guard")->move(this_object());
	if(!present("tax man"))
		new("/wizards/excelsior/mon/tax_man")->move(this_object());
}

void create() {
	::create();
	set_property("indoors",1);
	set_property("light",3);
	set("short","The crowd is rioting");
	set("long","You walk into the room and are almost hit by a flying chair. After "+
		"taking cover behind an overturned table you ask someone who has done "+
		"the same what all the ruckess is about. 'The tax man isn't taking any "+
		"more people today. The problem is that if many of the people don't "+
		"see him by today they will be arrested.' Then, as you watch, armed "+
		"guards storm into the room and proceed to massacre dozens of people. "+
		"The rest calm down and solemnly walk away. To the east there appears "+
		"to be an office of some sort.");
	set_items((["chair":"It was flying alright.",
		"table":"It is providing you cover",
		"someone":"They were very helpful.",
		"people":"They are mad, bad, and PISSED OFF!",
		"guards":"They showed those rioters.",
		"office":"It could be more than worth your wait in line."]));
	set_exits((["east":"/wizards/excelsior/rooms/shops/office",
		"south":"/wizards/excelsior/rooms/level3/building2"]));
	set_pre_exit_functions(({"east","south"}),({"go_east","go_south"}));
}

int go_south() {
	write("You make a leap for the exit and make it with only a small bruise "+
		"to the hip.");
	return 1;
}

int go_east() {
	if(!present("guard")) return 1;
	if(present("omega",this_player())) {
		write("You flash your security card and the guard lets you through.");
		return 1;
	}
	write("You scamper east, but the guard informs you that you need a security "+
		"level omega clearance card to enter that office. You run back to "+
		"your table, flying objects barely missing you.");
	return 0;
}

string query_long(string str) {
	if(str) return describe(str);
	if(present("guard")) return ::query_long();
	return "You walk into the room and are almost hit by a flying chair. After "+
		"taking cover behind an overturned table you ask someone who has done "+
		"the same what all the ruckess is about. 'The tax man isn't taking any "+
		"more people today. The problem is that if many of the people don't "+
		"see him by today they will be arrested.' Something seems to have "+
		"happened to the security personnel, because the people are rioting "+
		"unchecked!";
}
