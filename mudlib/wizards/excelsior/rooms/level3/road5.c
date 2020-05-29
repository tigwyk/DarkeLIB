// /wizards/excelsior/rooms/level3/road5
// Excelsior 7-1-96

inherit "/std/room";

void create() {
	::create();
	set_property("light",3);
	set_property("indoors",0);
	set_property("no mine",1);
	set_property("no castle",1)
;
	set("short","At the lookout");
	set("long","The road curves here, and to the northwest the view is "+
		"breathtaking. When it still existed the New Faerie Dust Department "+
		"of Recreation ordained that no buildings to the northwest of here "+
		"could be more the two stories tall, preserving the view you now "+
		"take in. Though the department no longer exists, there is no "+
		"room to build any tall buildings in that direction anymore. Thus, "+
		"you have this incredible view. The city stretches for miles and "+
		"then abruptly ends with the forests of Darke. Off in the far "+
		"distance, just barely in sight, you can make out the town of Akkad. "+
		"You wish you could stay at this spot forever.");
	set_items((["forever":"A long time.",
		"buildings":"They are all less then two stories, making your view "+
			"excellent.",
		"city":"It only stretches so far.",
		"akkad":"A nice town, complete with all the fixins."]));
	set_exits((["east":"/wizards/excelsior/rooms/level3/road6",
		"southwest":"/wizards/excelsior/rooms/level3/road4"]));
	reset();
}

void reset() {
	::reset();
	if(!present("juggler"))
		new("/wizards/excelsior/mon/juggler")->move(this_object());
}
