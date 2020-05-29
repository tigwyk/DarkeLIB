// /wizards/excelsior/rooms/level3/road8
// Excelsior 7/2/96

#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors",0);
	set_property("no mine",1);
	set_property("light",2);
	set_property("no castle",1);
	set("short","A crowd is forming");
	set("day long","There is currently a large crowd forming as "+
		"the work day is about to begin. They seem to be focusing "+
		"on the area to the east, which appears to be the entrance "+
		"to a factory of sorts. You figure that these are the people "+
		"looking for a job in that factory for the day. To the west is "+
		"the market.");
	set("night long","As night approaches people are setting up camp here "+
		"to assure themselves a good place in line for the next day. "+
		"People have to get here early or all the jobs in the factory to "+
		"the east are taken. Some of the people looking for work are "+
		"homelesss and thus just basically live here hoping to get hired "+
		"some day.");
	set_items((["market":"Many things can be bought there. Look westward.",
		"people":"They can only hope to be hired today",
		"factory":"You have heard of the factories of New Faerie Dust, "+
			"but no one seems to know what is made in them.",
		"camp":"People actually camp out here to assure themselves a better "+
			"place in the work line. What an existance."]));
	set_exits((["east":"/wizards/excelsior/rooms/level3/road9",
		"west":"/wizards/excelsior/rooms/level3/road7"]));
}
