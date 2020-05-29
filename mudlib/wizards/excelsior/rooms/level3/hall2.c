// /wizards/excelsior/rooms/level3/hall2

#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("light",1);
	set_property("indoors",1);
	set("short","The hallway continues");
	set("long","The light in the hallway continues to grow as you proceed west. "+
		"To the west there appears to be some sort of party going on. Wtf! "+
		"The dust on the floor has not been disturbed by anyone for years. In "+
		"places it is over 2 inches thick. How could anyone get back there to "+
		"have a party! As you ponder this, you notice the walls of this "+
		"section of the hallway are completely vandalized. You should "+
		"probably take a closer look at this.");
	set_items((["walls":"They are tagged everywhere in multiple languages. "+
		"You are able to pick out a triangle in a circle- the symbol "+
		"of the Black Order. The Black Order is a legendary guild of "+
		"thieves ruled by Galran, who has now become somewhat of a "+
		"legend to the people of NFD. They say he could break into anything- "+
		"he even once broke into NFD government headquarters! The last "+
		"member of the guild died some years ago.",
		"party":"Who would be in this building.",
		"building":"The more you think about it, the more you realize "+
			"it would make a great hideout.",
		"dust":"If you have asthma this is not a good place to be.",
		"hallway":"It feels haunted."]));
	set_exits((["west":"/wizards/excelsior/rooms/level3/ghost_party",
		"east":"/wizards/excelsior/rooms/level3/hall1"]));
	set_listen("default","The sound of voices to the west is louder");
	set_listen("voices","They are having a rollicking good time!");
	set_smell("defualt","You smell the dust in the air.");
	set_smell("dust","You take a large whiff of it and almost choke!");
}
