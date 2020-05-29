// /wizards/excelsior/mon/p_prisoner

#include <std.h>

inherit MONSTER;

void create() {
	::create();
	set_name("prisoner");
	set("id",({"prisoner","political prisoner"}));
	set("short","A beaten political prisoner");
	set("long","This beaten prisoner looks like he has been 'interrogated' "+
		"many times. He could put up much of a fight to anybody now.");
	set_level(4);
	set("race","high man");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(2);
	set_max_hp(200);
	set_hp(130);
}
