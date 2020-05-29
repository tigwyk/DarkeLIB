// /wizards/excelsior/rooms/level3/hall1
// a hall. spooky

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if(!present("murderer")) 
		new("/wizards/excelsior/mon/murderer")->move(this_object());
}

void create() {
	::create();
	set_property("indoors",1);
	set_property("light",0);
	set("short","In a hallway");
	set("long","You appear to be traversing some kind of long and dark "+
		"hallway. The floor beneath your feet creaks, reminding you that "+
		"you are in a condemned building. It can't be safe. As you continue "+
		"down the hall, you remember a ghost story you once heard. "+
		"In this story a famous thief stole a large jewel which could take "+
		"and store the energy from anything it touched. The thief stashed it away in "+
		"an old condemned building that he used as a hideout. Soon he grew so "+
		"corrupted by the power the stone gave him he killed all his men and "+
		"died guarding the rock he feared others would take. The story goes that "+
		"his spirit guards the jewel to this very day. To the west the hallway grows "+
		"lighter.");
	set_items((["floor":"It looks unstable, but it is hard to get a good look "+
			"in this light",
		({"hall","hallway"}):"It is long and spooky.",
		"jewel":"It is not here, it is in a story you were thinking of. Do you "+
			"need lessons teaching the difference between reality and imagination?"]));
	set_exits((["east":"/wizards/excelsior/rooms/level3/back_room",
		"west":"/wizards/excelsior/rooms/level3/hall2"]));
	set_listen("default","You hear voices to the west");
	set_listen("voices","They seem to be having a good time. Who would be in this "+
		"building?");
}
