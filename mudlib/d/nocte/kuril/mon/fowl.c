// Coder: %^GREEN%^nEv!N%^RESET%^
// Darkemud

#include "nevin.h"
inherit "/std/monster";

void create() {
	::create();
	set_name("water fowl");
	set("id", ({"bird", "fowl", "duck", "water fowl"}));
	set_level(1);
	set("short", "[1]A water fowl");
	set("long",
		"Living along the shores of the river, these water fowls "
		"swim about eating and staying away from strange creatures "
		"like you."
	);
	set_gender("neuter");
	set_body_type("fowl");
	set("race", "bird");
	set_skill("parry", 0);
	set_property("melee damage", ([
		"slashing": 2
	]) );
	set_overall_ac(1);
	set("aggressive", 0);
	set_emotes(10, ({
		"A water fowl shakes its tail at you.",
		"A water fowl swims up to you for something to eat, but once "
			"it gets a whiff of you it quickly swims away."
	}), 0);
	set_emotes(5, ({
		"The water fowl squaks loadly!",
		"The water fowl tries to swim away from you."
	}), 1);
	set_moving(1);
	set_speed(30+random(30));
}

void catch_tell(string str) {
	string a;
	if(sscanf(str, "%s enters.", a) == 1) {
		call_out("move_along", 10);
	}
}

void move_along() {
	int i;
	string *exits;
	exits = ENV(TO)->query_exits();
	i = sizeof(exits);
	message("info", "The water fowl swims along the river.", ENV(TO) );
	force_me(exits[random(i)]);
	return;
}

int check_kuril_river_mob() {
	return 1;
}
