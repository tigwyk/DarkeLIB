// /wizards/excelsior/rooms/backstage
// working to the finish line
// wtf that means I don't know

inherit "std/room";

void create() {
	::create();
	set_property("light",0);
	set_property("indoors",1);
	set("short","Behind the stage");
	set("long","You have managed to find your way behind the stage of the "+
		"New Faerie Dust Theatre company. There is not much in the way of "+
		"stuff back here because the stage crew and actors need to use this "+
		"portion of the back stage area to travel from one side of the theatre to "+
		"to the other very quickly without being seen. To the north are several "+
		"dressing rooms used by the stars of the theatre.");
	set_items( (["dressing rooms":"They are to the north.",
		"crew":"None are here right now.",
		"actors":"You see no actos in the vicinity."]) );
	set_exits( (["east":"/wizards/excelsior/rooms/backstage_right.2",
		"north":"/wizards/excelsior/rooms/dressing_rooms",
		"west":"/wizards/excelsior/rooms/backstage_left.2.c" ]) );
	set_listen( "defualt","You here mad shriekings coming from the north." );
}
