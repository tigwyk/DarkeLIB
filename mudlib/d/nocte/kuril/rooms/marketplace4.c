#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void reset() {
	::reset();
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
	if(!query_night()) {
		if(!present("citizen")) {
			new(MON+"kuril_cit_lw")->move(TO);
			new(MON+"kuril_cit_lw")->move(TO);
		}
		//if(!present("merchant")) {
			//new(MON+"merchant4")->move(TO);
		//}
		//if(!present("cart")) {
			//new(MISC+"cart4")->move(TO);
		//}
		if(!present("watchman")) {
			new(MON+"mp_fighter")->move(TO);
			new(MON+"mp_fighter")->move(TO);
		}
	}
	if(query_night()) {
		if(!present("ghost")) { new(MON+"ghost")->move(TO); }
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", 0);
	set_property("no castle", 1);
	set("short", "   0\n   | \n0--@   \n   | \n   0\nMarketplace");
	set("long",
		"Knee deep in the dregs of Kuril, the foul smells coming "
		"from all around you almost make you keel over and see your "
		"breakfast again.  The marketplace continues to the north and "
		"west.  To the south is an inn.\n   0\n   | \n0--@   \n   | \n   0\n"
	);
	set("night long",
		"A light in the doorway to the south offers some solace in "
		"this dark city.  Through a small window you can see that "
		"you have found an inn.\n   0\n   | \n0--@   \n   | \n   0\n"
	);
	set_items( ([
		"dregs": "Awful ain't it?",
		({"ruins", "building"}): "Having fallen into ruin years ago "
			"it now serves as a dining platter for carrion beasts "
			"and birds."
	]) );
	set_exits( ([
		"north": ROOMS+"marketplace2",
                  "west": ROOMS+"marketplace3",
            "south":"/d/nocte/kuril/inn/main_room.c"
	]) );
}
