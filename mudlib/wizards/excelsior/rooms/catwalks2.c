// /wizards/excelsior/rooms/catwalks2

inherit "std/room";

void create() {
	::create();
	set_property("light",0);
	set_property("indoors",1);
	set("short","Over the stage");
	set("day long","You are now over the stage. It is very high and scary "+
		"up here. You feel like the catwalk you are walking on is about "+
		"to collapse. To your south is a door leading to over the theatre "+
		"seating. As you look around you notice food lying around. You suddenly "+
		"get the feeling that someone is LIVING up here. Hrm. Above you is "+
		"a small vent you could climb through.");
	set("night long","You are now over the stage. It is very high and scary "+
		"up here. You can see the actors on the stage. You feel like the catwalk "+
		"you are walking on is about "+
		"to collapse. To your south is a door leading to over the theatre "+
		"seating. As you look around you notice food lying around. You suddenly "+
		"get the feeling that someone is LIVING up here. Hrm. Above you is "+
		"a small vent you could climb through.");
	set_items((["food":"Is someone LIVING up here?",
		"vent":"You wonder where it leads.",
		]));
	set_exits((["west":"/wizards/excelsior/rooms/catwalks",
		"south":"/wizards/excelsior/rooms/over_seats",
		"vent":"/wizards/excelsior/rooms/crevice"]));
}
