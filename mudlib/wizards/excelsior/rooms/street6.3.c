// /wizards/excelsior/rooms/street6.3

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if (!present("police man")) 
		new("/wizards/excelsior/mon/police_man")->move(this_object());
}

void create() {
	::create();
	set_property("light",2);
	set_property("indoors",0);
	set("short","At the site of a robbery");
	set("long","It appears that you are at the site of a recent convenience "+
		"store robbery. The 'Kiwi Market' is to your east, but it appears "+
		"to be closed due to the commotion. There are police men every where, "+
		"but no one will tell you exactly what happened. It doesn't appear "+
		"to have been an everyday robbery, but perhaps you will never know.");
	set_items( (["store":"To your east, but you cannot cross the police line.",
		"police":"They are everywhere."]) );
	set_exits( (["west":"/wizards/excelsior/rooms/street6.2",
		"south":"/wizards/excelsior/rooms/street6.4" ]) );
}
