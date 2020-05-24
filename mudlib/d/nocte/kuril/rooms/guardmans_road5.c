#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void init() {
	::init();
	if(this_player()->chk_my_mob()) {
		if(!query_open("barrier")) {
			add_action("no_exit", "east");
		}
	}
}

void reset() {
	::reset();
	if(!present("zombie")) {
		if(random(2) == 0) {
			new(MON+"ku_zombie")->move(TO);
		}
	}
	if(!present("citizen")) {
		new(MON+"kuril_cit_lw")->move(TO);
	}
}

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   0\n   | \n   @--0\n   | \n   0\nNorth City Gate");
	set("long",
		"Directly to the north is the end of Guardman's Road while "
		"to the east is what was once the Northern Guard Post.  "
		"From disuse and time, it has fallen into a state of near "
		"total ruin.  A make shift barrier has been erected and placed "
		"in the doorway.  Made of cast off pieces of wood and metal, "
		"it covers the entryway.\n   0\n   | \n   @--0\n   | \n   0\n"
	);
	set_items( ([
		({"guard post", "post"}): "Do you dare even enter suck a "
			"structure.  From the condition of its exterior, it "
			"just collapse in upon you.",
		"barrier": (: call_other, this_object(), "look_barrier" :),
		({ "doorway", "entryway" }): (: call_other, this_object(), 
			"look_barrier" :),
		({ "wood", "metal" }): "Someone put this barrior together "
			"in a hurry."
	]) );
	set_exits( ([
		"north": ROOMS+"guardmans_road6",
		"east": ROOMS+"north_guard_post",
		"south": ROOMS+"guardmans_road1"
	]) );
	set_door("barrier", ROOMS+"north_guard_post.c", "east",
		0);
	set_open("barrier", 0);
	set_locked("barrier", 0);
}

void look_barrier() {
	if(query_open("barrier")) {
		write("The barrier has been pushed aside to allow entrance "
			"to the guard post.");
	}
	else {
		write("The barrier is blocking entrance to the guard post.");
	}
}

int no_exit() {
	return 1;
}
