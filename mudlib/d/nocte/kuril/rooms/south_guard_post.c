#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void create(){
	::create();
	set_property("indoors", 1);
	set_property("light", 2);
	set_property("no castle", 1);
	set("short", "   \n    \n0--@   \n    \n   \nSouth City Guard Post");
	set("long",
		"Tables and chairs have been thrown carelessly into the "
		"corner in order to leave space for make shift beds in the "
		"center of the room.  Bottles and dirty clothing have been "
		"heaped in a corner.  This is the South City Guard Post.  "
		"With the rise of the School of Necromancy, the city guard "
		"has become lazy and inefficient.  Especially with the "
		"elite watchman patrolling the streets, the guard has been "
		"left with little to do except gamble, drink, and cause "
		"trouble.\n   \n    \n0--@   \n    \n   \n"
	);
	set_items( ([
		({"tables", "chairs"}): "From the look of them, they're in "
			"no condition to be used anyway.",
		"beds": "A bed of straw and blankets have been thrown into "
			"together.",
		({"bottles", "clothing", "heap"}): "Time to clean up perhaps?",
	]) );
	set_exits( ([
		"west": "magus_lane4"
	]) );
	set_door("door", ROOMS+"magus_lane4", "west", 
		"kuril south guard post key");
	set_open("door", 1);
	set_locked("door", 0);
}

void reset() {
	::reset();
	if(!present("watchman")) {
		new(MON+"wm_fighter")->move(TO);
		new(MON+"wm_fighter")->move(TO);
	}
}
