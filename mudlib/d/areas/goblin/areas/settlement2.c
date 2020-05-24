#include <std.h>
#include "../goblin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 3);
	set("short", "   0\n   | \n0--@--0\n   | \n   0\nDeeper within the goblin settlement.");
	set_long("This area seems to be the center of the settlement, the floor is made out of crudely placed marble rocks.  To the east there seems to be some sort of animal training ground.  To the north you can now see better the marble structure that you saw earlier.  The marble structure isn't exactly the best looking piece of architecture that you have seen before.\n   0\n   | \n0--@--0\n   | \n   0\n");
set_exits( ({(ROOMS+"settlement"), (ROOMS+"ngoblin1"), (ROOMS+"ngoblin2"), (ROOMS+"hill")}), ({"south", "east", "west", "north"}));
}

void reset() {
	::reset();
	if(!present("goblin"))
new(MON+"goblinc1.c")->move(this_object());
new(MON+"goblinc1.c")->move(this_object());
new(MON+"goblinc1.c")->move(this_object());
new(MON+"goblinc1.c")->move(this_object());
new(MON+"goblinc1.c")->move(this_object());
	}
