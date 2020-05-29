// /wizards/excelsior/rooms/jail/behind_desk

#include <std.h>

inherit ROOM;

void reset() {
	object police_man;
	::reset();
	if(!present("police man")) {
		police_man = new("/wizards/excelsior/mon/police_man");
		new("/wizards/excelsior/obj/jail_keys")->move(police_man);
		police_man->set("short","A fat police man");
		police_man->set("long","This fat police man is sitting here eating "+
			"donuts. His girth disgusts you.");
		police_man->set_level(10);
		police_man->move(this_object());
	}
}

void create() {
	::create();
	set_property("light",3);
	set_property("indoors",1);
	set("short","Behind the guard's desk");
	set("long","You are behind the guards desk of the NFDPF. This is where the "+
		"supervising guard sits and makes sure things are going fine in the "+
		"prison. On the north window is an open window with no bars on it. 'Not "+
		"very secure' you think. There is a large desk that separates this area "+
		"from the one to your south.");
	set_items((["desk":"It is large and piled high with papers.",
		"papers":"To many to sift through.",
		"window":"It looks like you could go through the open window to the "+
			"ledge to your north. Just 'escape' like any good criminal would.",
		"donuts":"They look like they would make you instantly fat."]));
	set_exits((["south":"/wizards/excelsior/rooms/jail/prison1",
		"escape":"/wizards/excelsior/rooms/ledge"]));
	add_invis_exit("escape");
	reset();
} 
