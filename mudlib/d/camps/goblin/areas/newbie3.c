#include <std.h>
#include "../goblin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 3);
	set("short", "    \n   e \n   @   \n   | \n   0\nInfront of a goblin settlement.");
	set("long", "Infront of you is the goblin settlement, it seems to be built into a small hill, maybe from mining purposes.  The gates of the settlement are open and only guarded by a snotling.  You wonder why they only have one snotling to guard the gates.\n    \n   e \n   @   \n   | \n   0\n");
 set_exits( ({(ROOMS+"newbie2"), (ROOMS+"gates")}), ({"south", "enter"}));
}

void reset() {
	::reset();
	if(!present("snotling")) {
new(MON+"snotling_knife.c")->move(this_object());
}

}
