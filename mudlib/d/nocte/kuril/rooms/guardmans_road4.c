#include <std.h>
#include "nevin.h"
inherit "/std/vault";

int check_mobs();

void init() {
	::init();
	if(this_player()->chk_my_mob()) {
		add_action("no_exit", "west");
		add_action("no_exit", "south");
		if(!query_open("door")) {
			add_action("no_exit", "east");
		}
	}
	add_action("hit_wall", "west");
}

void reset() {
	::reset();
	if(!present("watchman")) {
		new(MON+"wm_necromancer")->move(TO);
		new(MON+"wm_necromancer")->move(TO);
		new(MON+"wm_necromancer")->move(TO);
		new(MON+"wm_necromancer")->move(TO);
	}
	if(!present("zombie")) {
		if(random(2) == 0) {
			new(MON+"ku_zombie")->move(TO);
		}
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
	set("short", "   0\n   | \n   @--0\n   | \n   0\nGuardman's Road");
	set("long",
		"You are now at the southern end of Guardman's Road.  To "
		"the east is the Alchemist shop while to the south is the "
		"entrance to the Kurilian School of Necromancy.  The school "
		"towers over you as it's vine covered walls writhe to an "
		"unseen wind.  A gloom seems to fill the air surrounding "
		"the school.  A dried up fountain is located in this "
		"courtyard.  Having gone dry centuries ago, a large tree has "
		"begun to grow from inside the fountain.\n   0\n   | \n   @--0\n   | \n   0\n"
	);
	set_items( ([
		({"shop","alchemist shop"}): "You can see tons of bottles "
			"and vials lining the windows.",
		"school": "A truly menacing building, snarling gargoyles " +
			"leer down at you.",
		({"vine", "vines"}): "The strangle vines twist and writhe " +
			"as they sense your .",
		"tree": "The tree stands at least one hundred halfings tall.  "
	]) );
	set_exits( ([
		"north": ROOMS+"guardmans_road3",
		"east": ROOMS+"alchemist",
		"south": ROOMS+"entrance"
	]) );
	set_door("door", ROOMS+"alchemist", "east",
		"kuril alchemist shop");
	set_open("door", 1);
	set_locked("door", 0);
	set_door("iron door", ROOMS+"entrance", 
		"south", "kuril school of necromancy key");
	set_open("iron door", 0);
	set_locked("iron door", 0);
	set_lock_level("iron door", 45);
	set_open_function("open_door", "07:00:00");
	set_close_function("close_door", "17:00:00");
	new(MISC+"dry_fountain")->
		move(this_object());
}

void open_door() {
	call_other(ROOMS+"alchemist", "open_door");
}

void close_door() {
	call_other(ROOMS+"alchemist", "close_door");
}

int no_exit() {
	return 1;
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
