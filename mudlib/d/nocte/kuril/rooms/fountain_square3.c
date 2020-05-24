#include <std.h>
#include "nevin.h"
inherit ROOM;

void init() {
	::init();
	add_action("hit_wall", "east");
	if(TP->chk_my_mob()) { add_action("no_exit", "east"); }
}

void reset() {
	::reset();
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
	if(!present("citizen")) {
		new(MON+"kuril_cit")->move(TO);
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 0);
	set_property("night light", -5);
	set_property("no castle", 1);
	set("short", "   0\n   | \n0--@   \n   | \n   0\nFountain Square");
	set("long",
		"You notice runes carved in intricate patterns on the "
		"ground.  Time, weather, and abuse has made them barely "
		"legible.  They connect and wind their way northward"
		"toward a fountain.  Directly above you is a building which "
		"is connected to the structures directly to the east and "
		"west.  To the southeast is the School of Necromancy.  It's "
		"tall spires look even taller up close.  You can barely "
		"make out the tips of the towers.  Dark clouds swirl and "
		"coil around the tips of the towers.  You shudder to think "
		"of the poor souls that will die tonight in some grisly "
		"magical experiment.  Then again, their souls will "
		"most likely live on....  A cloud of darkness blocks the "
		"sun's light.  To the west is a guard post.\n   0\n   | \n0--@   \n   | \n   0\n"
	);
	set_items( ([
		({"spires", "school"}): "You notice that there are no "
			"windows for the first couple hundred of feet.  "
			"Getting in there must be near impossible...but "
			"then again, who would really want to go in there?"
			"And then there's the strangle vine that covers "
			"the black structure of evil in a sick embrace.",
		({"lamp", "lamps"}): "Glowing softly, they light the way "
			"ahead of you.",
		"sign": "It reads: FOR SALE (inquire when player owned "
			"shops are added)",
		"vines": "They twist and thrash about along the wall."
	]) );
	set_exits( ([
		"north": ROOMS+"fountain_square",
		"south": ROOMS+"magus_lane2",
	]) );
add_exit("/d/1tlny/complete/kuril/s2/guard_post.c","west");


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
