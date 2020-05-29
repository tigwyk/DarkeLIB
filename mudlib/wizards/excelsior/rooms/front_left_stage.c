// /wizards/excelsior/rooms/front_left_stage
// personal note- start putting rooms in files for different areas
// heh

inherit "std/room";

void create() {
	::create();
	set_property("light",0);
	set_property("night light",0);
	set_property("indoors",1);
	set("short","Front stage left");
	set("day long","You are on the left side of the room if you are "+
		"facing the stage. Seats are rather beat up over here. You "+
		"think that they should be repaired. Does your opinion matter? "+
		"No. You could head northwest up a short flight of stairs "+
		"to the back stage area, or east to the center of the "+
		"theatre. Ymtc.");
	set("night long","You are on the left side of the room if you are "+
		"facing the stage. Seats are rather beat up over here. You "+
		"think that they should be repaired. Does your opinion matter? "+
		"No. You are not blocking anyone's view, but you are so far to "+
		"the left of the stage no one sits here anyway. In fact, no "+
		"one sits in a lot of the seats around the theatre. "+
		"You could head northwest up a short flight of stairs "+
		"to the back stage area, or east to the center of the "+
		"theatre.");
	set_items( ([ "play":"It is hard to see from here.","seats":
		"Many are in bad shape and empty."]) );
	set_exits( (["east":"/wizards/excelsior/rooms/front_stage_center",
		"northwest":"wizards/excelsior/rooms/backstage_left"]));
	set_listen( "default", (: call_other, this_object(),"listen_default" :) );
}

string listen_default() {
	if (query_night()) {
		return "You can just barely here the sounds of the play from "+
			"here."; 	}
	else return "";
}
