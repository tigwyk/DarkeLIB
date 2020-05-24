#include <std.h>
#include "nevin.h"
inherit ROOM;

void init() {
	::init();
	if(TP->chk_temple_mob()) { add_action("no_exit", "west"); }
}


void reset() {
	object ob;
	::reset();
	if(!query_night()) {
		if(!present("guard")) {
			new(MON+"wm_chaotic")->move(TO);
			new(MON+"wm_chaotic")->move(TO);
			ob = new(MON+"wm_chaotic");
			ob->set_moving(1);
			ob->set_speed(120 + random(30));
			ob->move(TO);
		}
		if(!present("hound")) {
			new(MON+"chound")->move(TO);
		}
	}
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   \n    \n0--@--0\n   | \n   0\nMerchant Road");
	set("long",
		"A road branches off to the south from here.  As you "
		"go deeper into Kuril the road begins slope upwards.  "
		"Far to the east can be seen the School of Necromancy.  "
		"A dark cloud seems to hang over the structure like a "
		"smothering blanket.  To the southeast is the large temple "
		"structure you saw before.  From this distance you can see "
		"that someone has written something all over the walls.  "
		"You notice that there are not very many people on this "
		"street and that if they are here, they walk past the "
		"temple quickly...without looking back.  The citizenry "
		"obviously fear this place.  Why haven't the Necromancers "
		"ridden themselves of such an offensive temple?\n   \n    \n0--@--0\n   | \n   0\n"
	);
	set_items( ([
		
	]) );
	set_exits( ([
		"east": ROOMS+"temple_plaza1",
		"south": ROOMS+"thieves_court1",
		"west": ROOMS+"merchant_road5"
	]) );
}

int no_exit() { return 1; }
