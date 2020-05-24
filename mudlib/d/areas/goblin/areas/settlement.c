#include <std.h>
#include "../goblin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 3);
	set("short", "   0\n   | \n0--@--0\n   | \n   0\nFurther in the goblin settlement.");
	set("long", "Further in the goblin settlement, you can see that this part is more civilizied, if you can call it that, but there are huts to the west and right, where you guess the goblins live.  To the north there seems to be some  sort of marble structure built into the hill.\n   0\n   | \n0--@--0\n   | \n   0\n");
set_exits( ({(ROOMS+"gates"), (ROOMS+"settlement2"), (ROOMS+"goblin1"), (ROOMS+"goblin2")}), ({"south", "north", "east", "west"}));
}

void reset() {
	::reset();
	if(!present("goblin"))
new(MON+"goblin.c")->move(this_object());
new(MON+"goblin.c")->move(this_object());
new(MON+"goblin.c")->move(this_object());
new(MON+"goblin.c")->move(this_object());
new(MON+"goblin.c")->move(this_object());
}
