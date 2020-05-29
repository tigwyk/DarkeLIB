// /wizards/excelsior/rooms/crevice

inherit "std/room";

void reset() {
	::reset();
	if(!present("murderer")) 
		new("/wizards/excelsior/mon/murderer")->move(this_object());
}

void create() {
	::create();
	set_property("light",-2);
	set_property("indoors",1);
	set("short","In a cramped crevice");
	set("long","You have climb into a very clamped crevice. When you peak "+
		"through a closed ventalation grate on one wall you realize that you "+
		"are inbetween two jail cells. There appears to be no way into the "+
		"cells from here, but from the looks of this place, someone has been "+
		"living here. Thrown about is all kinds of trash and food.");
	set_items(([({"trash","food"}):"Some one has been hiding here!",
		"grate":"You can't get it open."]));
	set_exits((["down":"/wizards/excelsior/rooms/catwalks2"
		]));
	reset();
}
