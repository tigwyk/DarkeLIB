#include <std.h>

inherit OBJECT;

void create() {
	::create();
	set_name("world map");
	set_id( ({"map", "world map"}));
	set_short("A map of the world");
	set_long("A map of the world in a *coordinate* system, for you to find out where you are.");
	set_weight(100);
	set_value(50);
}

void init() {
	add_action("coordinate", "coordinate");
}
int coordinate() {
	this_player()->more("/wizards/mikus/world_map");
	return 1;
}
