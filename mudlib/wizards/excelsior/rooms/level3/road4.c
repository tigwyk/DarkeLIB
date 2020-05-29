// /wizards/excelsior/rooms/level3/road4
// Excelsior 6-30-96

inherit "/std/room";

void reset() {
	::reset();
	if(!present("citizen"))
		new("/wizards/excelsior/mon/citizen")->move(this_object());
}

void create() {
	::create();
	set_property("light",3);
	set_property("indoors",0);
	set_property("no castle",1);
	set_property("no mine",1);
	set("short","The market continues");
	set("day long","The open air New Faerie Dust market, featuring "+
		"the products of farmers, tinkers, craftsmen, folk artists, "+
		"live entertainment and almost anything else you can think "+
		"of continues here, with very little that interests you. "+
		"There is an alchemist (bah! like that works!) and a clothes "+
		"washer who have set up shop in this part of the market. The road "+
		"curves to the northeast here and appears to lead to a lookout "+
		"of sorts.");
	set("night long","Even during the night the streets are alive here. "+
		"Though an alchemist's and clothes washer's shops are closed now, "+
		"people continue on their way because many other shops in this "+
		"market are opened all day and all night. There is a lot of demand "+
		"for their services in a city like this! The road continues by "+
		"curving to the northeast here. There appears to be some sort of "+
		"vista point in that direction.");
	set_items(([({"farmers","craftsmen","folk artists","farmers","tinkers",
			"live entertainment","almost anything else"}):"Though there "+
			"are none here on this very spot which you stand, there "+
			"are many throughout the open air market.",
		"alchemist":"They are a big joke. Try to pass him by without "+
			"laughing too much.",
		"clothes washer":"You have no interest in keeping your clothes clean.",
		"road":"It curves to the northeast and continues to the south.",
		({"outlook","vista point"}):"Possibly interesting."]));
	set_exits((["northeast":"/wizards/excelsior/rooms/level3/road5",
		"south":"/wizards/excelsior/rooms/level3/road3"]));
	set_pre_exit_functions(({"northeast","south"}),({"leave_room","leave_room"}));
}

int leave_room() {
	if(!query_night()) {
		write("You barely get out of the room before bursting into laughter. "+
			"An _ALCHEMIST_!! HA!");
		return 1;
	}
	return 1;
}
