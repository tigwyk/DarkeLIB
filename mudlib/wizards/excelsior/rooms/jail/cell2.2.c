// /wizards/excelsior/rooms/jail/cell2.2

#include <std.h>

inherit VAULT;

void reset() {
	object guard;
	if(!present("guard")) 
		new("/wizards/excelsior/mon/whip_guard")->move(this_object());
	if(!present("prisoner"))
		new("/wizards/excelsior/mon/p_prisoner")->move(this_object());
	present("guard")->set_money("gold",300);
	set_open("cell 2",0);
	set_locked("cell 2",1);
	"/wizards/excelsior/rooms/jail/prison2"->set_open("cell 2",0);	
	"/wizards/excelsior/rooms/jail/prison2"->set_locked("cell 2",1);
}

void create() {
	::create();
	set_property("light",2);
	set_property("night light",0);
	set_property("indoors",1);
	set_property("no castle",1);
	set("short","In a prison cell");
	set("long","You are in a tiny prison cell and you get the feeling that prisoners "+
		"in this jail are not treated very well. There is blood on the wall of "+
		"this cell from 'interrogations' that have happened here. These basically "+
		"consist of a prisoner getting the crap beatin out of him until he "+
		"confesses to whatever the torturer wants him to."+
		"There is a small toilet on one wall.");
	set_items((["toilet":"It is out in the open for guards to see.",
		({"cell door","door","cell"}):"It is made out of bars that guards can "+
			"see right through.",
		"blood":"Someone went through a painful experience."]));
	set_exits((["north":"/wizards/excelsior/rooms/jail/prison2"]));
	set_door("cell 2","/wizards/excelsior/rooms/jail/prison2",
		"north","jail keys");
	set_lock_level("cell door",25);
	reset();
}	
		
