#include <std.h>
#include "nevin.h"
inherit ROOM;

void init() {
	::init();
	add_action("read_sign", "read");
	if(this_player()->chk_dock_mob()) {
		add_action("no_exit", "east");
	}
	if(TP->chk_my_mob()) { add_action("no_exit", "north"); }
}

void reset() {
	::reset();
	if(!query_night()) {
		if(!present("watchman")) {
			new(MON+"wm_fighter")->move(TO);
				move(this_object());
		}
		if(!present("citizen")) {
			new(MON+"kuril_cit_lw")->move(TO);
		}
	}
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
	if(query_night()) {
		new(MON+"ku_wight")->move(TO);
		if(!present("ghost")) { new(MON+"ghost")->move(TO); }
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   \n     \n   @--0\n   | \n   0\nMerchant Road");
	set("long",
		"Rotting dead bodies lay in a pile heaped into a corner.  "
		"'What a waste!' you shout.  Perfectly good corpses going "
		"to waste.  Now where is a necromancer when you need one?  "
		"From the grisly choice of decor before you, you know this is "
		"not one of the most affluent areas of Kuril.  To "
		"west is an abandoned shop.  Broken windows and "
		"boarded up doors are all that is left.  Where "
		"there was once a door a sign has been hammered across the "
		"entrance.  To the north is a small shop.  Looking inside "
		"you see that is it completely empty.  What could that shop be"
		" for?  "
		"A road continues southward while to the east is "
		"a marketplace.\n   \n     \n   @--0\n   | \n   0\n" 
	);
	set_items( ([
		({"dead bodies", "bodies"}): "You feel something rising in your "
			"stomach as you peer down at the water puffed flesh "
			"that has already been partially eaten away by "
			"the street vermin that rome the city.  But as you "
			"bravely turn one over you notice a scar cut into the "
			"face.  In fact now you notice that all of the corpses"
			" have the same scar carved into their dead flesh.",
		"scar": "It looks like some type of magical glyph.",
		({"sign", "signs"}): "Try 'read'ing it.",
		({"shop", "shops"}): "They have both been long abandoned."
	]) );
	set_exits( ([
		"east": ROOMS+"marketplace1",
		"south": ROOMS+"merchant_road2",
		//"north": ROOMS+"body_shop"
	]) );
}

int read_sign(string str) {
	if(!str) {
		notify_fail("What do you want to read?\n");
		return 0;
	}
	if(str == "sign") {
		write("In multiple languages the sign says:\n\n"
			"                  %^RED%^FOR SALE\n"
			"               %^RED%^DARKEMUD REALTY\n"
			"%^RED%^(inquire when player owned shops are added)\n\n");
		return 1;
	}
}

int no_exit() {
	return 1;
}	
