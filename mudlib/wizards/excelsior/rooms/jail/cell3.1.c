// /wizards/excelsior/rooms/jail/cell3.1

#include <std.h>

inherit VAULT;

void reset() {
	object thief,sp;
	if(!present("prisoner")) 
		new("/wizards/excelsior/mon/p_prisoner")->move(this_object());
	set_open("cell 1",0);
	set_locked("cell 1",1);
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
	set("long","You are in a tiny prison cell. It is very empty. You'd hate to be "+
		"a prisoner here.");
	set_items(([
		({"cell door","door","cell"}):"It is made out of bars that guards can "+
			"see right through."]));
	set_exits((["south":"/wizards/excelsior/rooms/jail/prison3"]));
	set_door("cell 1","/wizards/excelsior/rooms/jail/prison3",
		"south","jail keys");
	set_lock_level("cell door",25);
	reset();
}	
		
