// /wizards/excelsior/rooms/dressing_rooms
// a room with a locked door. The key can be found in the
// theatre lounge.

inherit "std/vault";

void reset() {
	::reset();
	set_open("door",0);
	set_locked("door",1);
	"/wizards/excelsior/rooms/dressing_room"->set_open("door",0);
	"/wizards/excelsior/rooms/dressing_room"->set_locked("door",1);
}

void init() {
	::init();
	add_action("peer","peer");
}
	
	
	
void create() {
	::create();
	set_property("light",2);
	set_property("indoors",1);
	set("short","By the dressing rooms");
	set("long","You have come to the end of a hallway that provides "+
		"access to the theatre dressing rooms from the backstage area. "+
		"There are only two dressing rooms here. There is a  door "+
		"which leads to one to your west, and to your east it appears the "+
		"dressing room has been made into an office for the "+
		"theatre manager. To your north is an open window.");
	set_items( (["dressing rooms":"There are only two, one to your "+
	"east and one to your west.",
		"door":(: call_other, this_object(), "look_at_door" :),
		({"dressing room","office"}):"A quick remodeling job "+
		"transformed this room.",
		"window":"It provides a wonderful view of an abondoned lot. "+
		"The lot is several floors below, too far for you to "+
		"leap to. 'Strange', you think. 'I thought I was on the first "+
		"floor.' Maybe you should 'peer' out the window some more." ]) );
	set_exits( (["east":"/wizards/excelsior/rooms/manager_office",
		"west":"/wizards/excelsior/rooms/dressing_room",
		"south":"/wizards/excelsior/rooms/backstage" ]) );
	set_door("door","/wizards/excelsior/rooms/dressing_room","west",
		"star key");
	set_listen( "default","You here mad shriekings coming from the west." );
	set_listen( "shrieks","They are the yells of someone truly mad.");

	reset();
}

int peer(string str) {
	if ( str == "out the window" || str == "window" || 
		str == "out window" || str == "the window") {
		write("You see an abondoned lot which is too far below to "+
		"jump to. To your west outside you see a drainpipe. You "+
		"could probably climb up this pipe to roof, but you will "+
		"have to find a window closer to it...");
		return 1;
	}
	else
	{
		notify_fail("You peer into space and drool all over yourself.\n");
		return 0;
	}
}

string look_at_door() {
	string locked_state,open_state;
	if (query_locked("door")) locked_state = "It is locked.";
	else locked_state = "It is not locked.";
	if (query_open("door")) {
		open_state = "The door is open.";
		locked_state = "";
	}
	else {
		open_state = "The door is closed.";
	}
	write( "The door is light purple with a large yellow five pointed star on it. "+open_state+" "+locked_state);
	return "The door is light purple with a large yellow 5 five "+
	"pointed star on it. "+open_state+" "+locked_state;
}

int open_door() {
	if ("/wizards/excelsior/rooms/dressing_room"->actoress_home() ) {
		write("As you open the door you are blasted by the sounds "+
			"of the yelling.");
	} else {
		write("You open the door. Wheeee!");
	}
	return 1;
}
	
	
int actress_home() {
	if (present("actress") ) return 1;
	return 0;
}
