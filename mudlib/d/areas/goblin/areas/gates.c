#include <std.h>
#include "../goblin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 4);
	set("short", "   0\n   | \n0--@--0\n   o \n    \nInside the goblin settlement.");
	set("long", "This is inside the goblin settlement, it is built into a small hill.  You can see two caves to the left and right, obviously to harvest mushrooms, as you can see remanants of mushrooms all over the place.  To the north seems to be a more civilized part of the settlement.\n   0\n   | \n0--@--0\n   o \n    \n");
	set_items((["mushroom" : "These are some mushrooms that are lying alone the ground, you don't really want to pick them up as they have saliva all over them"]));
set_exits( ({(ROOMS+"newbie3"), (ROOMS+"settlement"), (ROOMS+"cave2"), (ROOMS+"cave1")}), ({"out", "north", "west", "east"}));
}

void reset() {
	::reset();
	if(!present("goblin"))
new(MON+"goblin_spear.c")->move(this_object());
}
