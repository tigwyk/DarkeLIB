#include <std.h>
#include "nevin.h"
inherit "std/vault";

void init() {
	::init();
	add_action("hit_wall", "south");
	if(this_player()->chk_my_mob()) {
		add_action("no_exit", "south");
		if(!query_open("door")) {
			add_action("no_exit", "north");
		}
	}
}

void reset() {
	::reset();
	if(!present("zombie")) {
		if(random(4) == 0) {
			new(MON+"ku_zombie")->move(TO);
		}
	}
	if(!present("citizen")) {
		new(MON+"kuril_cit_lw")->move(TO);
		new(MON+"kuril_cit_lw")->move(TO);
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 0);
	set_property("night light", -5);
	set_property("no castle", 1);
	set("short", "   0\n   | \n0--@--0\n    \n   \n Fountain Square");
	set("long",
		"Passing beneath a building, you see a store to the north.  "
		"On the ground you notice some runes connecting themselves "
		"to the fountain to the west.  Citizens meander through the "
		"streets.  They obviously feel much safer on this side of "
		"town.  The city watch sure must do a good job of keeping "
		"the riff-raff out of the Upper Ward.  Now how did you "
		"sneak in?  To the south is the School of Necromancy.  "
		"It appears that at one time almost all of the buildings "
		"in this city were all connected together.  Directly to the "
		"south is the Kurilian School of Necromancy.  A pall of "
		"darkness surrounds the building like a cloak.\n   0\n   | \n0--@--0\n    \n   \n "
	);
	set_items( ([
		"shop": "Fine leather goods for sale of course.",
		"pub": "A sign above the doorway reads: The Raking Claw.",
		({"lamp", "lamps"}): "Glowing softly, they light the way "
			"ahead of you.",
		"school": "You can not see much from your current location."
	]) );
	set_exits( ([
		"north": ROOMS+"general_store",
		"east": ROOMS+"guardmans_road2",
		"west": ROOMS+"fountain_square"
	]) );
	set_door("door", ROOMS+"general_store", "north",
		"kuril leather shop key");
	set_open("door", 1);
	set_locked("door", 0);
	set_open_function("open_door", "07:00:00");
	set_close_function("close_door", "17:00:00");
}

void open_door() {
	call_other(ROOMS+"general_store", "open_door");
}

void close_door() {
	call_other(ROOMS+"general_store", "close_door");
}

int hit_wall() {
	if(wizardp(TP)) { return 1; }
	if(TP->query_class() == "necromancer") {
		message("info", "%^BLUE%^%^BOLD%^You bump into the wall, "
			"the vines grasp for you, but as soon as they touch "
			"you, they quickly curl back up after tasting your "
			"foul soul.", TP);
		message("info", "%^BLUE%^%^BOLD%^"+TPQCN+" bumps into the "
			"wall of the school of necromancy, the vines wither "
			"after touching such a foul soul.", ENV(TP), ({TP}) );
		return 1;
	}
        message("info", "%^BLUE%^%^BOLD%^You bump into the wall.  The vines covering "
		"the school of necromancy coil around you...you feel very "
		"weak....%^RESET%^", TP);
	message("info", "%^BLUE%^%^BOLD%^" + (string)this_player()->query_cap_name() + 
		" bumps into the wall of the school of necromancy only to "
		"have the vines which cover the school wrap themselves "
		"around " + (string)this_player()->query_objective() + 
		"!%^RESET%^", TP, ({TP}) );
	this_player()->add_hp(-(( (int)this_player()->query_hp() )/4 + 30));
	return 1;
}

int no_exit() {
	return 1;
}
