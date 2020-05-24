#include <std.h>
#include "../goblin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 3);
	set("short", "   \n    \n0--@--0\n    \n   \nThe east cave.");
	set("long", "This is the east caves, snotlings are here to pick up the many multicolored mushrooms all around the room.  There are some snotlings that have knives to pick mushrooms and others to carry them.\n   \n    \n0--@--0\n    \n   \n");
	set_items((["mushrooms" :
"There are lots of mushrooms here to look at, unfortunately you don't want to pick them up as you might poison yourself."]));
set_exits( ({(ROOMS+"gates"), (ROOMS+"cave3")}), ({"west", "east"}));
}
void reset()  {
	::reset();
	if(!present("snotling"))
{
new(MON+"snotling.c")->move(this_object());
new(MON+"snotling.c")->move(this_object());
new(MON+"snotling_knife.c")->move(this_object());
new(MON+"snotling_knife.c")->move(this_object());
new(MON+"snotling_knife.c")->move(this_object());
new(MON+"snotling.c")->move(this_object());
new(MON+"snotling.c")->move(this_object());
new(MON+"snotling_knife.c")->move(this_object());
new(MON+"snotling_knife.c")->move(this_object());
new(MON+"snotling_knife.c")->move(this_object());
}
}


