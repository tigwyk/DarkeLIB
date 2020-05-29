// /wizards/excelsior/rooms/prison_ent

#include <std.h>

inherit VAULT;

void reset() {
	set_open("door",0);
	set_locked("door",1);
	"/wizards/excelsior/rooms/jail/prison1"->set_open("door",0);
	"/wizards/excelsior/rooms/jail/prison1"->set_locked("door",1);
}

void create() {
	::create();
	set_property("light",2);
	set_property("night light",1);
	set_property("indoors",0);
	set("short","By a large steel door");
	set("day long","The road you are following ends here at a large steel door. "+
		"Engraved on the door are the letters 'NFDPF'- New faerie Dust Prison "+
		"facility. On either side of this large steel door are bared windows. "+
		"If you are going to get into this jail, you will either need a key or "+
		"will have to find another way in.");
	set("night long","The road you are following ends here at a large steel door. "+
		"Engranevd on the door are the letters 'NFDPF'- New faerie Dust Prison "+
		"facility. On either side of this large steel door are bared windows. "+
		"If you are going to get into this jail, you will either need a key or "+
		"will have to find another way in. Off to the side of the road is a "+
		"lamp that provides the room with light.");
	set_items((["door":(: call_other,this_object(),"look_at_door":),
		"lamp":"It provides the area with light.",
		"windows":"They have thick bars in them."]));
	set_exits((["southwest":"/wizards/excelsior/rooms/level2",
		"north":"/wizards/excelsior/rooms/jail/prison1"]));
	set_door("door","/wizards/excelsior/rooms/prison_ent","north","jail keys");
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

