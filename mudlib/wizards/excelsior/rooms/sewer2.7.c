// /wizards/excelsior/rooms/sewer2.7

inherit "std/room";

void create() {
	::create();
	set_property("light",-2);
	set_property("indoors",1);
	set("short","A massive intersection");
	set("long","Here the sewer tunnels that could easily be called "+
		"a maze widen up into an intersection of amazing proportions. "+
		"There are several ways to go from here, but you can't help "+
		"thinking that this place looks familiar- like you've been here "+
		"before.");
	set_items( (["tunnels":"Pick a direction."]) );
	set_smell( "default","You smell the sewer smell.");
	set_exits( (["east":"/wizards/excelsior/rooms/sewer2.8",
		"west":"/wizards/excelsior/rooms/sewer2.6",
		"north":"/wizards/excelsior/rooms/sewer1.8",
		"southeast":"/wizards/excelsior/rooms/sewer3.8"]) );
	set_pre_exit_functions( ({"north"}),({"go_north"}) );
}

int go_north() {
	write("The tunnel turns to the right and then back to the left before "+
		"reaching another chamber.");
	return 1;
}
