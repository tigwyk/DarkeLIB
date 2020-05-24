#include <std.h>
#include "../goblin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 3);
	set("short", "   0\n   | \n   @   \n   | \n   0\nA pebble road.");
	set("long", "This road has been used quite frequently as you can see the pebbles are very small in size due to erosion.  Infront of you, you can see a settlement of some sort.  On the side of the road there is a sign.\n   0\n   | \n   @   \n   | \n   0\n");
	set_items((["sign" : "Players level 7 and under only!"]));
set_exits( ({ "/d/damned/virtual/room_10_11.world", (ROOMS+"newbie2.c")}), ({"south", "north"}));
	set_pre_exit_functions(({"north"}), ({"go_north"}));

}
	int go_north(){
	int xlevel;
	xlevel = this_player()->query_level();
	if(xlevel > 7) {
	if(present("templar")){
	write("The templar blocks your path");
	return 0;
}
else return 1;
}
else return 1;
}
void reset() {
	::reset();
	if(!present("knife")) 
new(ITEM+"knife.c")->move(this_object());
	if(!present("templar"))
new(MON+"templar.c")->move(this_object());
}
