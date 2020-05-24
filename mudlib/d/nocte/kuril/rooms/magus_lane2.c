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
		if(random(2) == 0) {
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
	set("short", "   0\n   | \n   @   \n   | \n   0\nMagus Lane");
	set("long",
		"You shiver as you pass by the School of Necromancy "
		"to the east.  Something drops upon your shoulder...something "
		"crimson.  The cries of terror which spill nightly upon "
		"the streets and into the skies above Kuril are filled with "
		"unimaginable agony.  You would rather die quickly than live "
		"and become an experiment in that horrid building.  Only to "
		"continue living...sufering...never to find rest.  A blackish "
		"rain has begun to fall soiling your clothes and filling the "
		"streets with dirty water.  To the east is an old abandoned "
		"shop.\n   0\n   | \n   @   \n   | \n   0\n"
	);
	set_items( ([
		"school": "You see some type of movement along the walls...",
		"walls": "The are covered with some type of vine...a moving "
			"vine that twists and slides up the walls.",
		"rain": "As you look up water droplets get into your eyes "
			"making them sting.",
		"streets": "At least this rain will wash away some of the "
			"filth.",
		"vines": "The writhe about, seeking living flesh...",
		"shop": "A small sign hammered into the support beams says: "
			"Inquire when player shops are opened, Darkemud "
			"Realty."
	]) );
	set_exits( ([
		"north": ROOMS+"fountain_square3",
		"south": ROOMS+"magus_lane3",
	]) );
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
