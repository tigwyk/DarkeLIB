// /wizards/excelsior/rooms/level3/back_room
// Excelsior. What a suprise, in his own directory! Wow!

inherit "/std/room";

void reset() {
	::reset();
	if(!present("lucifer")) 
		new("/wizards/excelsior/mon/lucifer")->move(this_object());
}

void create() {
	::create();
	set_property("indoors",1);
	set_property("light",-2);
	set("short","In a condemned building");
	set("long","You are in a old deserted room. The cob webs in here "+
		"are so thick you can barely see 2 feet in front of you. You have "+
		"a very bad feeling something really bad is going to happen. "+
		"You see a small speck of "+
		"light through the cobwebs to your west. To your north is the exit "+
		"out of here. You better leave quickly, you here a loud breathing "+
		"noise very close by!");
	set_smell("default","You smell rotting wood and flesh.");
	set_listen("default","You hear the sound of loud breather very very nearby.");
	set_listen("breathing","It's right behind you!");
	set_items(([({"cob webs","cobwebs","webs"}):"If they were worth anything you'd "+
		"be rich.",
		"exit":"To the north and quick.",
		"light":"It is to your west. Your curiosity is peeked, if you can "+
			"make it through these cobwebs."]));
	set_exits((["north":"/wizards/excelsior/rooms/level3/bard_home",
		"west":"/wizards/excelsior/rooms/level3/hall1"]));
	reset();
}
