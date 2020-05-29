// /wizards/excelsior/rooms/jail/prison3

#include <std.h>

inherit VAULT;

void reset() {
	set_open("cell 1",0);
	set_locked("cell 1",1);
	set_open("cell 2",0);
	set_locked("cell 2",1);
	"/wizards/excelsior/rooms/jail/cell3.1"->set_open("cell 1",0);
	"/wizards/excelsior/rooms/jail/cell3.1"->set_locked("cell 1",1);
	"/wizards/excelsior/rooms/jail/cell3.2"->set_open("cell 2",0);
	"/wizards/excelsior/rooms/jail/cell3.2"->set_locked("cell 2",1);
}

void create() {
	::create();
	set_property("light",3);
	set_property("night light",1);
	set("short","The cells continue");
	set("long","The prison cells continue to your north and your south. If you "+
		"have the keys you can open them, but you are not sure you want to meet "+
		"the prisoners inside. To unlock a cell, type 'unlock cell # with key'. "+
		"Because there are 2 cells here, # should be 1 or 2.");
	set_items((["cell 1":"You wonder who kept in it.",
		"cell 2":"You wonder who is kept in it."]));
	set_exits((["north":"/wizards/excelsior/rooms/jail/cell3.1",
		"south":"/wizards/excelsior/rooms/jail/cell3.2",
		"west":"/wizards/excelsior/rooms/jail/prison2",
		"east":"/wizards/excelsior/rooms/jail/prison4"]));
	set_door("cell 1","/wizards/excelsior/rooms/jail/cell3.1","north","jail keys");
	set_door("cell 2","/wizards/excelsior/rooms/jail/cell3.2","south","jail keys");
	reset();
	set_lock_level("cell 1",25);
	set_lock_level("cell 2",25);
}
