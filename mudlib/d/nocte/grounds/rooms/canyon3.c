#include <std.h>
#include <nevin.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 1);
	set_property("no castle", 1);
	set("short", "South Canyon Wall");
	set("long",
		"In this corner of the canyon, pushed up against the southern "
	"wall, is what appears to be a make shift camp.  Pots and pans "
		"as well as some animal remains can be found in a large pile.  "
		"A newly opened wine casks lay covered between some rocks...at "
		"least the bandits that are milling about know how to take care "
		"of the wine."
	);
	set_smell("default", "The smell of unwashed bodies wafts into your nose.");
	set_items( ([
		"camp":  "It's just a small collection of trail beaten tents.",
	]) );
	set_exits( ([
		"north": ROOMS+"canyon4.c",
		"east": ROOMS+"canyon6.c"
	]) );
}

void reset() {
	::reset();
	if(!find_object("_bandit1"))
		new(MON+"bandit1.c")->
		move(this_object());
	if(!find_object("_bandit2"))
		new(MON+"bandit2.c")->
		move(this_object());
	if(!find_object("_bandit3"))
		new(MON+"bandit3.c")->
		move(this_object());
	if(!find_object("_bandit4"))
		new(MON+"bandit4.c")->
		move(this_object());
	if(!find_object("bandit leader"))
		new(MON+"bandit_leader.c")->
		move(this_object());
}
