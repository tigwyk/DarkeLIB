#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void reset() {
	::reset();
	if(!present("citizen")) {
		new(MON+"kuril_cit")->move(TO);
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   0\n   | \n0--@   \n     \n    \n Nobleman's Lane");
	set("long",
		"Houses of various types, sizes, colours, and makes line the "
		"lane.  Already accustomed to the great disparity between the "
		"Upper and Lower Wards of Kuril, there is no question in your "
		"mind where the ruling class lives.  Of course such power is "
		"but an illusion...for there is always someone else pulling "
		"the strings right above you...\n   0\n   | \n0--@   \n     \n    \n"
	);
	set_items( ([
		"houses": "They sure are in stark contrast to the "
			"poverty you have left behind in the Lower Ward.",
	]) );
	set_exits( ([
		"north": ROOMS+"noblemans_lane3",
		"west": ROOMS+"noblemans_lane1"
	]) );
}
