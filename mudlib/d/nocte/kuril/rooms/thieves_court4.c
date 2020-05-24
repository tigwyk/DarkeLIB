#include <std.h>
#include "nevin.h"
inherit ROOM;



void reset() {
	::reset();
	if(!present("guard")) {
		new(MON+"wm_chaotic")->move(TO);
		new(MON+"wm_chaotic")->move(TO);
		new(MON+"wm_chaotic")->move(TO);
	}
	if(!present("hound")) {
		new(MON+"chound")->move(TO);
		new(MON+"chound")->move(TO);
	}
	if(!query_night()) {
		if(!present("citizen")) {
			new(MON+"kuril_cit_lw")->move(TO);
		}
	}
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
	if(!present("ghost")) { new(MON+"ghost")->move(TO); }
}


void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   0\n   | \n   @   \n     \n    \nThieves' Court");
	set("long",
		"A gentle breeze blows past you as you stand before a "
		"beautiful arch.  As you look past the arch you wonder "
		"if the builders of this city ever heard of city planning..."
		"for beyond the arch is a vertical drop to a hard rocky "
		"death.  A road continues northward past a shop to the east "
		"and west.  To the south you can see a river.\n   0\n   | \n   @   \n     \n    \n"
	);
	set_items( ([
		"river": "It flows around the City of Kuril.",
		"shop": "From the signs in front of the shops, they are "
			"the local butcher and parchment maker."
	]) );
            add_exit(ROOMS+"thieves_court3","north");

}
