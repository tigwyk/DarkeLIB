#include <std.h>
#include "nevin.h"
inherit ROOM;

void reset() {
	::reset();
	if(!present("zombie")) { new(MON+"ku_zombie")->move(TO); }
	if(!present("citizen")) { 
		new(MON+"kuril_cit_lw")->move(TO); 
		new(MON+"kuril_cit_lw")->move(TO);
	}
}

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 1);
	set_property("night light", -4);
	set_property("no castle", 1);
	set("short", "   0\n   | \n0--@--0\n   | \n   0\nGuardman's Road");
	set("long",
		"You pass beneath a large building above you.  Two roads "
		"extend "
		"to the north, east, south, and west.  You can see shops "
		"in all directions.  To the south is the Kurilian School of "
		"Necromancy.  Darkness surrounds the structure.\n   0\n   | \n0--@--0\n   | \n   0\n"  
	);
	set_items( ([
		"building": "It is connected to the buildings to the west.",
		"roads": "They extend in all directions."
	]) );
	set_exits( ([
		"north": ROOMS+"guardmans_road1",
		"east": ROOMS+"noblemans_lane1",
		"south": ROOMS+"guardmans_road3",
		"west": ROOMS+"fountain_square2"
	]) );
}
