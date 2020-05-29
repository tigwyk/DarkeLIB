#include <std.h>
#include <nevin.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 1);
	set_property("no castle", 1);
	set("short", "Tunnel Entrance");
	set("long",
		"To the east is a tunnel carved from the very rocks of the "
		"canyon.  Small symbols and shapes line the cave entrance.  "
		"It appears that this cave is inhabited...or it once was."
		"  The remains of a large bonfire lays smoldering in front of "
		"the tunnnel's mouth."
	);
	set_items( ([
		"tunnel": "It's too dark to see very far into the tunnel.",
		"symbols": "You are unable to make out any meaning from them.",
		"shapes":  "It looks like a picture of a battle scene.",
		"picture": "The picture shows a large group of people fighting in this very canyon.  A large, black winged creature is shown on the upper left.  It appears to be holding the sun its hands.  The next picture shows everyone dead."
	]) );
	set_exits( ([
		"west": ROOMS+"canyon3.c",
		"east": ROOMS+"tunnel1.c",
		"north": ROOMS+"canyon7.c"
	]) );
}
