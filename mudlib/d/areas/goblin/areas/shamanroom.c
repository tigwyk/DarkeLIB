#include <std.h>
#include "../goblin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 3);
	set("short", "   0\n   |  \n   @   \n    \\ \n     0\nA mystic room of ingredients.");
	set_long("This room has a strange and mysterious air to it.  The room is piled to the rim with different ingredients, including several thousand different kinds of mushrooms.  Some books are stacked to the side of the room looking idle by themselves.  A few rats scurry from side to side, nibbling at pieces of mushrooms found on the floor.\n   0\n   |  \n   @   \n    \\ \n     0\n");
	set_items(([
	"mushrooms" : "These are some mushrooms that have been chewed up by the rats that dwell here.",
	"books" : "The books are stacked without order or care, they just sit there by themselves.  The books range from the Compendium of obscure flora to The Grimm Grimoire.",
	"ingredients" : "There are many various types of ingredients here to be found, some of them are quite strange while others are just plain disgusting."
]));
set_exits( ({(ROOMS+"shaman"), (ROOMS+"hill")}), ({"north", "southeast"}));

}

void reset() {
	::reset();
	if(!present("rat"))
{
new(MON+"rat.c")->move(this_object());
new(MON+"rat.c")->move(this_object());
new(MON+"rat.c")->move(this_object());
new(MON+"rat.c")->move(this_object());
}
}

