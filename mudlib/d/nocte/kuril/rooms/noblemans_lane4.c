#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void init() {
	::init();
	add_action("read_sign", "read");
}

void reset() {
	::reset();
	if(!present("zombie")) {
		if(random(2) == 0) {
			new(MON+"ku_zombie")->move(TO);
		}
	}
	if(!present("watchman")) {
		if(random(2) == 0) {
			new(MON+"wm_fighter")->move(TO);
		}
	}
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
	set("short", "   \n    \n0--@--0\n    \n   \nNobleman's Lane");
	set("long",
		"A small shop to the north has a sign posted in the window.  "
		"It appears that this area of town although in far better "
		"condition than the Lower Ward, has problems of its own as "
		"well.  To the east can be seen a tavern of sorts.  The "
		"smoke emmanating from its chimney fire swirls and twists "
		"until ripped apart by the ocean breeze.  To the west can "
		"be seen a bakery.\n   \n    \n0--@--0\n    \n   \n"
	);
	set_items( ([
		"shop": "Quaint yet spacious enough for any type of business "
			"it is a shame that a business has not moved in.",
		"tavern": "It appears to be a lively enough place.",
		"smoke": (: call_other, this_object(), "look_smoke" :),
		"chimney": "That must be some fire they have going in there!  "
			"All that smoke just billowing out!",	
		"bakery": "Ah, that must be the city's bakery.  Famous for "
			"it's cakes and cookies.  Rebecca's bakery is an "
			"island on calm in the turbulance that is Kuril.",
		"sign": "Try 'read'ing it.",
		"spires": "The homes of powerful merchant families and "
			"archmagi--they are no place for the inexperienced."
	]) );
	set_exits( ([
		"east": ROOMS+"noblemans_lane5",
		"west": ROOMS+"noblemans_lane3"
	]) );
}

void look_smoke() {
	write("You stare at the smoke dreamily as it floats into the sky.");
	say((string)this_player()->query_cap_name()+ " watches the smoke "
		"from the tavern's chimney rise into the air, all the while "
		"letting drool get all over the place.");
}

int read_sign(string str) {
	if(!str) {
		notify_fail("What do you want to read?");
		return 0;
	}
	if(str == "sign") {
		write("In multiple languages the sign says:\n\n"
		       "                   %^RED%^FOR SALE\n"
		       "		%^RED%^DARKEMUD REALTY\n"
		       "%^RED%^(inquire when player owned shops are added)\n\n"
		);
		return 1;
	}
}
