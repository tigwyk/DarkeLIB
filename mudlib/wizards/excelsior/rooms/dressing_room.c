// /wizards/excelsior/rooms/dressing_room
// a mad actoress is running amuck!

inherit "std/vault";

void reset() {
	object actress;
	::reset();
	actress = present("actress");
	if (actress) actress->remove();
	new("/wizards/excelsior/mon/actress.c")->move( this_object() );
}

void init() {
	::init();
	add_action("jump_pipe","jump");
}

void create() {
	::create();
	set_property("light",3);
	set_property("indoors",1);
	set("short","A dressing room");
	set("long","You are in the dressing room of a crazy actoress who apparently "+
		"locked herself in her room. The actoress's makeup and other feminine items "+
		"are recklessly thrown about the room. The mirror is smashed. To the east "+
		"is the other dressing room. On the north wall there is an open window.");
	set_items( (["makeup":"'What a waste of money' you think.",
		"mirror":"With the mirror smashed you look even uglier then normal.",
		"dressing room":"It is accross the hallway to the east.",
		"door": (: call_other, this_object(), "look_at_door" :),
		"window":"It is open. Through it you see a drain pipe that you could "+
			"probably 'jump' to. Far below is an abondoned lot of some sort." ]) );
	set_exits( (["east":"/wizards/excelsior/rooms/dressing_rooms"]) );
	set_door("door","/wizards/excelsior/rooms/dressing_rooms","east","star key");
	set_listen( "default", (: call_other, this_object(), "listen_default" :) );
}

int jump_pipe(string str) {
	if (str == "to pipe" || str == "pipe" || str == "to drainpipe" || str ==
			"drainpipe") {
		write("You leap to the nearby drainpipe.");
		message("other_action",this_player()->query_cap_name()+" leaps out the "+
		"window.", environment(this_player()), ({this_player()}));
		this_player()->move_player( "/wizards/excelsior/rooms/pipe" );
		return 1;
	}
	else
	{
		notify_fail("Jump to where?\n");
		return 0;
	}
}

string listen_default() {
	if (present("actress") ){
		return "You here the mad rantings of the lunatic.";
	} else {
		return "";
	}
}

	
string look_at_door() {
	string open_state,locked_state;
	if ( query_locked("door") ) locked_state = "It is locked.";
	else locked_state = "It is not locked.";
	if ( query_open("door") ) {
		open_state = "The door is open.";
		locked_state = " ";
	} else { open_state = "The door is closed."; }
	write( "The door is bright purple with a large five pointed yello star on "+
	"it. "+open_state+" "+locked_state );
	return "Whee";
}
int actress_home() {
	if ( present("actress") ) return 1;
	return 0;
}
