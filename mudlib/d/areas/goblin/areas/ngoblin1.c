#include <std.h>
#include "../goblin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 3);
	set("short", "   \n    \n0--@   \n    \n   \nA little room for practice.");
	set_long("A strange looking animal pen, similar to that of a pig pen.  The floor is covered with mushroom bits, and animal dung.  The animals that are located here are called squigs, sub-terrainean animals of plant and animal stock.\n   \n    \n0--@   \n    \n   \n
");
set_exits( ({(ROOMS+"settlement2")}), ({"west"}));
}
void reset() {
	::reset();
	if(!present("squig"))
{
new(MON+"squig1.c")->move(this_object());
new(MON+"squig1.c")->move(this_object());
new(MON+"squig2.c")->move(this_object());
new(MON+"squig2.c")->move(this_object());
new(MON+"squig3.c")->move(this_object());
new(MON+"squig3.c")->move(this_object());
new(MON+"squig1.c")->move(this_object());
new(MON+"squig1.c")->move(this_object());
new(MON+"squig2.c")->move(this_object());
new(MON+"squig2.c")->move(this_object());
new(MON+"squig3.c")->move(this_object());
new(MON+"squig3.c")->move(this_object());
}
}

