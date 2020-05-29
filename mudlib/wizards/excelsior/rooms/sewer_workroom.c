// /wizards/excelsior/rooms/sewer_workroom

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if (!present("toastmaster")) new("/wizards/excelsior/mon/toaster_king")->move(
			this_object());
	if (!present("joey")) { new("/wizards/excelsior/mon/living_toaster")->move(
			this_object());
		present("joey")->set_owner("toastmaster");
}
}

void create() {
	::create();
	set_property("light",1);
	set_property("indoors",1);
	set("short","A home in the sewers");
	set("long","You have met some very eccentric people in your life before, "+
		"but this one may beat them all. Apparently you are in the workroom "+
		"of some kind of rock nut. "+
	"Against the far wall there appears to be "+ 
		"some sort of bed, so you know someone has actually made a home for them"+
	"selves in the sewers. It is made of rocks and doesn't look very comfortable. "+
	"You boggle that someone would live in this dank, dark sewers with a bunch "+
	"of rocks.");
	set_items( (["rocks":"They can be found most anywhere you look when outside. "+
		"They are characterized by there hardness and their source: the planet "+
		"itself.",
		"bed":"It is solid stone. It makes you fear sleeping on it.",
		"workroom":"You wonder what the king works on." ]) );
	set_exits( (["east":"/wizards/excelsior/rooms/sewer3.7"
		]) );
}

