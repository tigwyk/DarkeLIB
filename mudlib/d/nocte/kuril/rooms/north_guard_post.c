#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void reset() {
	::reset();
	if(!present("citizen")) {
		new(MON+"kuril_cit")->
			move(this_object());
		new(MON+"kuril_cit")->
			move(this_object());
	}
	if(query_night()) {
		if(!present("ghost")) {
			new(MON+"ghost")->move(TO);
			new(MON+"ghost")->move(TO);
		}
	}
}

void create(){
	::create();
	set_property("indoors", 1);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   \n    \n0--@   \n    \n   \nNorthern City Guard Post");
	set("long",
		"Tables, chairs, filthy clothes, and empty bottles litter "
		"the floor of this room.  Once used by the original city "
		"guard, it has been abandoned and now serves as shelter for "
		"the poor and dying.  An open window allows some light to "
		"enter while a make shift barrier has been constructed to "
		"keep out the cold at night.  From the stench in the room "
		"something is obviously rotting underneath all that trash "
		"and refuse.\n   \n    \n0--@   \n    \n   \n"
	);
	set_items( ([
		({"tables", "chairs", "clothes", "bottles"}): "What a mess!!!",
		"shelter": "This room barely offers any protection from the "
			"elements, it is disease infested and the smell is "
			"almost overwealming.",
		({"poor", "dying"}): "Those that can not leave the city, have "
			"been left here to die.  They will of course be "
			"reanimated if a necromancer ever finds the corpses.",
		"window": "All that is left of are some rusted windows hinges.",
		"barrier": (: this_object(), "look_barrier" :),
		({"trash", "refuse"}): "It lays all over the floor."
	]) );
	set_exits( ([
		"west": "guardmans_road5"
	]) );
	set_door("barrier", ROOMS+"/guardmans_road5", "west",
		0);
	set_open("barrier", 0);
	set_locked("barrier", 0);
	set_string("barrier", "open", "You slide the barrier aside.\n");
}

void look_barrier() {
	if(query_open("barrier")) {
		write("The barrier has been moved aside.");
	}
	else {
		write("The barrier is in place blocking the exit out.");
	}
}
