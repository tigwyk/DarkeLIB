// /wizards/excelsior/rooms/street6.1


inherit "std/room";

void reset() {
	::reset();
	if (!find_object( "citizen" ))
		new("/wizards/excelsior/mon/citizen")->move(this_object());
	if (present("citizen")) return;
	if (random(100) > 85) 
		new("/wizards/excelsior/mon/citizen")->move(this_object());
}

void create() {
	::create();
	set_property("light",2);
	set_property("night light",1);
	set_property("indoors",0);
	set("short","On a busy road");
	set("night long","You are following a busy road through the heart of "+
		"New Faerie Dust. Even at night this road is well lit by several "+
		"strange lamps attached to the buildings which are on either side of "+
		"you. To the west is an expensive jewerly store that seems to have "+
		"gone out of business. It is boarded up. Above this there is another "+
		"road running parallel to the one you are on. To your east there is  "+
		"another road below you that leads into the outcast quarter. It boggles "+
		"your mind how densely this city is put together. Though it is night "+
		"people still scurry about doing their business.");
	set("day long","You are following a busy road through the heart of "+
		"New Faerie Dust. This place is abust with activity as people use this "+
		"road to reach the upper levels of the city. To the west is an "+
		"expensive jewerly store that seems to have "+
		"gone out of business. It is boarded up. Above this there is another "+
		"road running parallel to the one you are on. To your east there is  "+
		"another road below you that leads into the outcast quarter. It boggles "+
		"your mind how densely this city is put together.");
	set_items( (["store":"There is obviously no entry into it.",
		"lamps":"How does this city produce its power? Hrm.",
		"people":"They are scurrying about like ants when water is poured "+
			"down their hole.",
		({"road","roads"}):"There are three parallel roads at this spot, the "+
			"one you are on, the one above you and to your west, and the one "+
			"below you and to your east.",
		]) );
	set_exits( (["north":"/wizards/excelsior/rooms/level2",
		"south":"/wizards/excelsior/rooms/street6.2" ]) );
	reset();
}
