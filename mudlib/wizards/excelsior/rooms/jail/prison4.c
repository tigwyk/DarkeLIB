// /wizards/excelsior/rooms/jail/prison4

#include <std.h>

inherit VAULT;

void reset() {
	object sp;
	::reset();
	if(!present("police man")) {
		sp = new("/wizards/excelsior/mon/police_man");
		sp->set_level(9);
		sp->move(this_object());
	}
	set_open("cell",0);
	set_locked("cell",1);
	"/wizards/excelsior/rooms/jail/cell4.1"->set_open("cell",0);
	"/wizards/excelsior/rooms/jail/cell4.1"->set_locked("cell",1);
}

void create() {
	::create();
	set_property("light",3);
	set_property("night light",1);
	set("short","The cells continue");
	set("long","There is one last cell to your north. If you "+
		"have the keys you can open it.");
	set_items((["cell":"You wonder who is kept in it.",
		]));
	set_exits((["north":"/wizards/excelsior/rooms/jail/cell4.1",
		"west":"/wizards/excelsior/rooms/jail/prison3",
		]));
	set_door("cell","/wizards/excelsior/rooms/jail/cell4.1","north","jail keys");
	reset();
	set_lock_level("cell",25);
	set_lock_level("cell 2",25);
}
