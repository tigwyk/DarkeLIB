// /wizards/excelsior/rooms/emporium/library

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if(!present("bookcase"))
		new("/wizards/excelsior/obj/emporium/bookcase")->move(this_object());
}

void create() {
	::create();
	set_property("light",2);
	set_property("night light",2);
	set_property("indoors",1);
	set("short","In the emporium libary");
	set("long","This is the emporium library, where books from all around "+
		"have been collected and stored. Who knows what you may find here...");
	set_items((["books":"They are all over the place."
		]));
	set_exits((["east":"/wizards/excelsior/rooms/emporium/foyer"]));
}
	
		
