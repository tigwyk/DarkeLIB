// /wizards/excelsior/rooms/street6.4

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if (!find_object( "citizen" ))
		new("/wizards/excelsior/mon/citizen")->move(this_object());
	if (present("citizen")) return;
	if (random(100) > 81) 
		new("/wizards/excelsior/mon/citizen")->move(this_object());
}

void create() {
	::create();
	set_property("indoors",0);
	set_property("light",2);
	set_property("night light",1);
	set("short","The road continues");
	set("day long","You continue to follow the road through the second level of "+
		"the city. Everywhere you look are people. Humans riding carts as their "+
		"troll slaves pull them, women carrying bags of groceries, poor beggars "+
		"earning zero money begging the passersby. Here the city is not quite "+
		"as depressing, and you can feel it in the air! To your east is the large "+
		"building that you cannont seem to find a way in to. Above you there is a "+
		"bridge leading to this building. Hrm.");
	set("night long","Even at night the streets are alive with action. Jugglers "+
		"come out in full force to entertain the public, though the people who "+
		"could afford to spare them some change the most just pass by without "+
		"even looking at them. You begin to wonder if this city ever sleeps. To "+
		"your east is a large building that reaches hundreds of feet into the air "+
		"above you. You can't see the top because there is a large bridge directly "+
		"above your head the leads into this building.");
	set_items( (["people":"They are all very busy.",
		"carts":"Humans never pull carts.",
		"women":"New Faerie Dust is a patriarchal society.",
		"building":"It is ludicrously tall.",
		"bridge":"It serves as an entrance to the large building. If only you "+
			"could get up there.",
		"jugglers":"There are more jugglers here then you've ever seen before.",
		]) );
	set_exits( (["north":"/wizards/excelsior/rooms/street6.3",
		"south":"/wizards/excelsior/rooms/street6.5" ]) );
	set_listen("default","You hear the sounds of a bustling city.");
}
