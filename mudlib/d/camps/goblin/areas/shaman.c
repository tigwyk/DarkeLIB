#include <std.h>
#include "../goblin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	
set_property("light", 3);
	set("short", "    \n     \n   @   \n   | \n   0\nThe room of a powerful shaman");
	set_long("This is the room of a powerful goblin shaman, his work is never done with all the goblins running around.  He is probably the most serious and powerful of all the goblins in this settlement.  The room is filled to the brim with many exotic items, like rats, bats, worms, grass, deer testicles, horns, spiders and the like.\n    \n     \n   @   \n   | \n   0\n");
set_exits( ({(ROOMS+"shamanroom")}), ({"south"}));

}
void reset() {
	::reset();
	if(!present("shaman"))
new(MON+"shaman.c")->move(this_object());
}

