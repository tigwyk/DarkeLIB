// /wizards/excelsior/rooms/jail/prison1

#include <std.h>

inherit VAULT;

void reset() {
	::reset() ;
	set_open("door",0);
	set_locked("door",1);
	"/wizards/excelsior/rooms/prison_ent"->set_open("door",0);
	"/wizards/excelsior/rooms/prison_ent"->set_locked("door",1);
}

void create() {
	::create();
	set_property("light",3);
	set_property("indoors",1);
	set("short","Inside the prison");
	set("long","You are inside the New Faerie Dust Prison facility. To your "+
		"north is the guards desk, to the south is the door to leave, and to "+
		"your east are the cells.");
	set_items((["desk":"There is a fat guard the sits behind it. You could "+
		"say hello to him more personally if you went north.",
		"cells":"They are to your east",
		"door":(: call_other,this_object(),"look_at_door":)]));
	set_exits((["north":"/wizards/excelsior/rooms/jail/behind_desk",
		"south":"/wizards/excelsior/rooms/prison_ent",
		"east":"/wizards/excelsior/rooms/jail/prison2"]));
	set_listen("default","You hear screams coming from the east");
	set_door("door","/wizards/excelsior/rooms/prison_ent","south",
			"jail keys");
	set_lock_level("door",30);
	reset();
}

string look_at_door() {
	string open_state,locked_state;
	if(query_locked("door")) {
		locked_state = " and is currently locked.";
	} else {
		locked_state = " but it is not locked.";
	}
	if (query_open("door")) { open_state = "The door is open.";
		locked_state = " ";
	} else {
		open_state = "The door is closed, "; 
	}
	write("This is a large iron door with the letters 'NFDPF' engraved on it. "+
		"It looks very sturdy, and has a very small keyhole on it. "+
		open_state+locked_state);
	return "This is a large iron door with the letters 'NFDPF' engraved on it. "+
		"It looks very sturdy, and has a very small keyhole on it. "+
		open_state+locked_state ;
}
