// /wizards/excelsior/rooms/jail/cell4.1

#include <std.h>

inherit VAULT;

void reset() {
	if(!present("mae-tagg"))
		new("/wizards/excelsior/mon/mae-tagg")->move(this_object());
	set_open("cell",0);
	set_locked("cell",1);
	"/wizards/excelsior/rooms/jail/prison2"->set_open("cell",0);	
	"/wizards/excelsior/rooms/jail/prison2"->set_locked("cell",1);
}

void create() {
	::create();
	set_property("light",2);
	set_property("night light",0);
	set_property("indoors",1);
	set_property("no castle",1);
	set("short","In a prison cell");
	set("long","You are in a tiny prison cell and you get the feeling that prisoners "+
		"in this jail are not treated very well. The living conditions here are very "+
		"cramped. There is a small toilet on one wall. You have a special feeling "+
		"about the occupant of this room.");
	set_items((["toilet":"It is out in the open for guards to see.",
		({"cell door","door","cell"}):"It is made out of bars that guards can "+
			"see right through."]));
	set_exits((["south":"/wizards/excelsior/rooms/jail/prison4"]));
	set_door("cell","/wizards/excelsior/rooms/jail/prison4",
		"south","jail keys");
	set_lock_level("cell",25);
	reset();
}	
		
