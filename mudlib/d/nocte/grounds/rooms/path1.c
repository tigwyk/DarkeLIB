#include <std.h>
#include <nevin.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 1);
	set_property("no castle", 1);
	set("short", "A path between two cliffs.");
	set("long",
		"Passing between the two cliffs makes you immediately more "
		"alert...for this would be the perfect place for an ambush "
		"or a trap.  The walls of the cavern where once a dull "
		"redish hue...but are are now blackened all the way to the "
		"lips of the two enclosing walls.  Silhouettes have been "
		"permanently scarred and burned into the walls by some "
		"great power.  The path continues to the east making a "
		"slight incline as it opens into a large enclosed area."
	);
	set_listen("default", "The only sound are your footsteps echoing off the cavern walls.");
	set_items( ([
		"cliffs": "They are at least one hundred feet high yet the distance between them is only ten feet.",
		"walls":  "They are shear and have a slight negative angle to them making them impossible to climb.",
		"silhouettes":  "Some of the unlucky figures on the wall where holding weapons at the time of their doom.",
		"path":  "Dust puffs up in small mushroom clouds with each step you take...no living being has disturbed the rest of the dead here for a long time...."
	]) );
	set_exits( ([
                "west": "/d/damned/virtual/room_05_12.world",
		"east": ROOMS+"path2.c"
	]) );
}
