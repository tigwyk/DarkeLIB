// /wizards/excelsior/rooms/jail/cell3.2

#include <std.h>

inherit VAULT;

void reset() {
	if(!present("murderer"))
		new("/wizards/excelsior/mon/murderer")->move(this_object());
	set_open("cell 2",0);
	set_locked("cell 2",1);
	"/wizards/excelsior/rooms/jail/prison3"->set_open("cell 1",0);	
	"/wizards/excelsior/rooms/jail/prison3"->set_locked("cell 1",1);
}

void create() {
	::create();
	set_property("light",2);
	set_property("night light",0);
	set_property("indoors",1);
	set_property("no castle",1);
	set("short","In a prison cell");
	set("long","You are in a tiny prison cell. You get the feeling that whoever "+
		"is kept here is a lunitic. You get this feeling from the various "+
		"satanic symbols carved into the stone walls of this place by someone's "+
		"finger nails.");
	set_items((["symbols":"Someone carved these into the stone walls with there "+
		"fingernails. You can tell from the bits of fingernail stuck into these "+
		"carvings.",
		({"cell door","door","cell"}):"It is made out of bars that guards can "+
			"see right through."]));
	set_exits((["north":"/wizards/excelsior/rooms/jail/prison3"]));
	set_door("cell 2","/wizards/excelsior/rooms/jail/prison3",
		"north","jail keys");
	set_lock_level("cell 2",25);
	reset();
}	
		
