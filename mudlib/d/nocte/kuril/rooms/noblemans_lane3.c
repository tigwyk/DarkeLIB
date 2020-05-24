#include <std.h>
#include "nevin.h"
inherit ROOM;

void reset() {
	::reset();
	if(!present("watchman")) {
		if(random(2) == 0) {
			new(MON+"wm_fighter")->move(TO);
		}
	}
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
	if(!present("citizen")) {
		if(random(3) == 0) {
			new(MON+"kuril_cit")->move(TO);
		}
	}
}
 
void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   \n     \n   @--0\n   | \n   0\nNobleman's Lane");
	set("long",
		"Nobleman's Lane takes a turn to the east as it passes "
		"right next to the bakery to the west.  Fine houses, "
		"towers, and mansions line the lane.  Obviously the houses "
		"of the wealthy, they all have walls to keep the unwelcome "
		"out...\n   \n     \n   @--0\n   | \n   0\n"
	);
	set_items( ([
		"bakery": "You wonder what wondrous pastries and breads can "
			"be purchased there.",
		({"houses", "towers", "mansions"}): "They are all very nice "
			"but all well protected.",
	]) );
	set_exits( ([
		"east": ROOMS+"noblemans_lane4",
		"south": ROOMS+"noblemans_lane2"
	]) );
}
