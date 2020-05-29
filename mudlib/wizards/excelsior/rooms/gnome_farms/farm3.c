// /wizards/excelsior/rooms/gnome_farms/farm3

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if(!present("gnome"))
		new("/wizards/excelsior/mon/gnome")->move(this_object());
	if(!present("gnome 2"))
		new("/wizards/excelsior/mon/gnome")->move(this_object());
}

void create() {
	::create();
	set_property("light",1);
	set_property("indoors",0);
	set("short","In the gnome nursery");
	set("night long","You continue to follow the dark alleyway that seems to be some "+
		"sort of forced gnome breeding center. What could all these gnomes be "+
		"used for? In this section of the alley several gnome mothers care and "+
		"nurse their young. This must be the nursery. Above you the stone walls "+
		"stretch into the air atleast 150 feet. Above these confining walls you "+
		"can see the night sky. How could someone do this to another intelligent "+
		"race?");
	set("day long","You continue to follow the dark alleyway that seems to be some "+
		"sort of forced gnome breeding center. What could all these gnomes be "+
		"used for? In this section of the alley several gnome mothers care and "+
		"nurse their young. This must be the nursery. Above you the stone walls "+
		"stretch into the air atleast 150 feet. Above these confining walls you "+
		"can see the polluted sky. How could someone subject another intelligent "+
		"race to such treatment?");
	set_items((["mothers":"They may not be actual mothers but a nurse or wet maid "+
			"some sort. In any case they are caring for gnome young.",
		"walls":"They are smooth and slick. Nothing could climb out of here.",
		]));
	set_exits((["east":"/wizards/excelsior/rooms/gnome_farms/farm2",
		"west":"/wizards/excelsior/rooms/gnome_farms/farm4"]));
	set_listen("default","You here the moans of starving and dying gnomes.");
}

void init() {
	::init();
	add_action("climb","climb");
}

int climb() {
	write("You scramble up the slick, horizontally perpindicular surface and "+
		"make it an astounding 10 inches up the wall. Damn, if only you could "+
		"get a tiny bit higher!");
	return 1;
}
