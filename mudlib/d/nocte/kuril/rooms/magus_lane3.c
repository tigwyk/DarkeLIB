#include <std.h>
#include "nevin.h"
inherit "std/vault";

void init() {
	::init();
	add_action("hit_wall", "east");
	if(this_player()->chk_my_mob()) {
		add_action("no_exit", "east");
		if(!query_open("door")) {
			add_action("no_exit", "west");
		}
	}
}

void reset() {
	::reset();
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
	if(!present("citizen")) {
		new(MON+"kuril_cit_lw")->move(TO);
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 0);
	set_property("night light", -5);
	set_property("no castle", 1);
	set("short", "   0\n   | \n0--@   \n   | \n   0\nMagus Lane");
	set("long",
		"You are located on Magus Lane, the slick stones under "
		"your feet provide little purchase.  To the east is the "
		"Kurilian School of Necromancy.  As far as you can tell, there "
		"is no obvious entrance into the school, it's tall walls "
		"rising upwards as if to grab the sky with it's dark "
		"towers.  A black colored vine has covered almost every "
		"square foot of the school.  To the west is the city's "
		"Magic Shop.  A shadow hangs over the School of Necromancy "
		"making vision difficult at best.  "
		"Magus Lane continues to the north and south.\n   0\n   | \n0--@   \n   | \n   0\n"
	);
	set_items( ([
		"stones": "They are covered with a thin coat of slime.  From "
			"what you cannot tell.",
		"school": "You wonder if anyone has ever tried to climb the "
			"walls into one of the school's windows...those vines "
			"sure make it easy to do.",
		"walls": "Dark shapes jut out from the sides of the school..."
			"gargoyles to keep out evil spirits.  A little too "
			"late don't you think?",
		"towers": "There are three main towers in the School of "
			"Magic, the next rising higher into the sky.  Small "
			"objects can be seen circling the tops of each tower.",
		({"vine", "vines"}):  "As you approach to get a better look, "
			"a vine lashes out to grab you...you jump back just "
			"in time to avoid it's deadly embrace.",
	]) );
	set_exits( ([
		"north": ROOMS+"magus_lane2",
		"south": ROOMS+"magus_lane4",
		"west": ROOMS+"magic_shop"
	]) );
	set_door("door", ROOMS+"magic_shop.c", "west",
		"kuril magic shop key");
	set_open("door", 1);
	set_locked("door", 0);
	set_open_function("open_door", "07:00:00");
	set_close_function("close_door", "17:00:00");
}

void open_door() {
	call_other(ROOMS+"magic_shop.c", "open_door");
}

void close_door() {
	call_other(ROOMS+"magic_shop.c", "close_door");
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
