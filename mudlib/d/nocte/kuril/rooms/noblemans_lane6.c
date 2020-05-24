#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void init() {
	::init();
	add_action("read_sign", "read");
}

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
	set("short", "   \n     \n   @--0\n   | \n   0\nNobleman's Lane");
	set("long",
		"With the seedier elements of the city kept at bay by the "
		"city watchmen, the wealthy are able to enjoy life in the "
		"Noble Ward.  If fact, it's almost another city in itself "
		"from the conditions around you.  Clean buildings, swept "
		"streets, and not a ruffian to be seen!  Far to the east you "
		"can see an archway at the end of the lane.\n   \n     \n   @--0\n   | \n   0\n"
	);
	set_items( ([
		"ruffian": "Where!?!?!  Quick!  Call the watch!",
		"archway": "It stands at least thirty feet tall.  Made of "
			"pure white stone, it's beauty has not been touched "
			"by the evil around it.",
		"buildings": "To the southeast you can see a large pub.",
		"streets": "The street you happen to be on right now continues "
			"southward and eastward."
	]) );
	set_exits( ([
		"east": ROOMS+"noblemans_lane7",
		"south": ROOMS+"noblemans_lane5"
	]) );
}

int no_exit() {
	return 1;
}
