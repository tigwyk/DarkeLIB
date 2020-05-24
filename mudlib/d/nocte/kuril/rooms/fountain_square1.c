#include <std.h>
#include "nevin.h"
inherit ROOM;

void reset() {
	::reset();
	if(!present("zombie")) {
		if(random(3) == 0) {
			new(MON+"ku_zombie")->move(TO);
		}
	}
	if(!present("citizen")) {
		new(MON+"kuril_cit_lw")->move(TO);
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   0\n   | \n   @   \n   | \n   0\nFountain Square");
	set("long",
		"Passing beneath a building, you notice some runes connecting "
		"themselves to the fountain to the south.  Citizens meander "
		"through the streets.  "
		"They obviously feel much safer on this side of "
		"town.  The city watch sure must do a good job of keeping "
		"the riff-raff out of the Upper Ward.  Now how did you "
		"sneak in?  To the south is the School of Necromancy.  "
		"It appears that at one time almost all of the buildings "
		"in this city were all connected together.\n   0\n   | \n   @   \n   | \n   0\n"
	);
	set_items( ([
		"runes": "The connect to the fountain to the south."
	]) );
	set_exits( ([
		"north": ROOMS+"magus_lane1",
		"south": ROOMS+"fountain_square",
	]) );
}
