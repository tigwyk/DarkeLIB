#include <std.h>
#include "nevin.h"
inherit ROOM;

void init() {
	::init();
	add_action("read_sign", "read");
	add_action("hit_wall", "west");
	if(TP->chk_my_mob()) { add_action("no_exit", "west"); }
}

void reset() {
	::reset();
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
	if(!present("citizen")) {
		if(random(2) == 0 ) {
			new(MON+"kuril_cit_lw")->move(TO);
		}
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 0);
	set_property("night light", -5);
	set_property("no castle", 1);
	set("short", "   0\n   | \n   @   \n   | \n   0\nGuardman's Road");
	set("long",
		"As you approach the Kurilian School of Necromancy to the "
		"south, you can feel something drawing toward it.  As if "
		"something was pulling at your soul...your life force..."
		"To the east an abandoned shop.  Broken windows and "
		"decayed wood mark what may have been once a prosperous "
		"business.  To the south you can see a fountain and an "
		"entrance into the Kurilian School of Necromancy.  Covering "
		"the walls of the School of Necromancy is a dark vine.  As "
		"you move in for a closer look you notice that it begins to "
		"move...closer...closer...as if seeking your life....  An "
		"unnatural darkness surrounds the school making it difficult "
		"so see.\n   0\n   | \n   @   \n   | \n   0\n"
	);
	set_items( ([
		"school": "The main part of the school is formed my three "
			"enormous towers.  What or who is in these towers "
			"you have no idea.",
		"shop": "There is a sign swinging from a single rusted chain "
			"above the doorway.",
		"fountain": "A large tree is growing right out of it!",
		"entrance": "Dark robed figures stand in front of the "
			"entrance.",
		"vine": "It probably would not be a good idea to get any "
			"closer to the wall",
		"walls": "They are covered with that abominable vine!",
		"sign": "Try 'read'ing it."
	]) );
	set_exits( ([
		"north": ROOMS+"guardmans_road2",
		"south": ROOMS+"guardmans_road4",
	]) );
}

int read_sign(string str) {
	if(!str) {
		notify_fail("What are you trying to read?\n");
		return 0;
	}
	if(str == "sign") {
		write("In multiple languages the sign says:\n\n"
			"		   %^RED%^FOR SALE\n"
			"		%^RED%^DARKEMUD REALTY\n"
			"%^RED%^(inquire when player owned shops are added)\n\n"
		);
		return 1;
	}
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

int no_exit() { return 1; }
