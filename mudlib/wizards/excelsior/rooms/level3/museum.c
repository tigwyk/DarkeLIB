// /wizards/excelsior/rooms/level3/museum
// Excelsior 7-2-96

inherit "/std/room";

void create() {
	::create();
	set_property("indoors",3);
	set_property("light",3);
	set("short","In the museum");
	set("long","This room is sort of a hall to the rest of the building, "+
		"as a large stairway leads up from here. All around are artifacts "+
		"to the city's and expecially the current government's greatness. "+
		"You really don't want to honor the city with looking at them, "+
		"so instead you decide to continue on your way.");
	set_items((["artifacts":"It is the mayor's propaganda.",
		"stairway":"It goes in the up direction."]));
	set_exits((["up":"/wizards/excelsior/rooms/level4/building1",
		"south":"/wizards/excelsior/rooms/level3/building1"]));
	add_pre_exit_function("up","go_up");
}

int go_up() {
	write("An apologetic city employee informs you that the building in that "+
		"direction is undergoing serious renovations and thus cannot be "+
		"accessed.");
	return 0;
}
