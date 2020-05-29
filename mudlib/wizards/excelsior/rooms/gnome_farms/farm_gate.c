// /wizards/excelsior/rooms/gnome_farm/farm_gate


inherit "/std/vault";

void reset() {
	object guard,guard2;
	::reset();
	if(!present("sword guard")) {
		new("/wizards/excelsior/mon/sword_guard")->move(this_object());
	}
	if(!present("spear guard")) {
		new("/wizards/excelsior/mon/spear_guard")->move(this_object());
	}
	set_open("gate",0);
	set_locked("gate",1);
	"/wizards/excelsior/rooms/gnome_farms/farm1"->set_open("gate",0);
	"/wizards/excelsior/rooms/gnome_farms/farm1"->set_locked("gate",1);
	present("spear guard")->set_money("copper",670);
	present("sword guard")->set_money("copper",300+random(1000));
}

void create() {
	::create();
	set_property("light",1);
	set_property("indoors",0);
	set("short","At a strange gate");
	set("long","This is a strange place indeed. You are in a small, dark, deadend "+
		"alleyway with brick walls. Compared to much of the rest of this city's "+
		"alleys it is suprisingly clean. To the northwest there is an "+
		"overcrowded slum, but there is almost no one here except a few guards. "+
		"Behind the guards is a large iron gate of some sort. It looks practically "+
		"impenatrable. Whatever is behind that gate however must surely be "+
		"fabulous to require such security.");
	set_items((["gate":(: call_other,this_object(),"look_at_gate":),
		"walls":"They are brick"]));
	set_exits( (["northwest":"/wizards/excelsior/rooms/gnome_farms/alley2",
		"west":"/wizards/excelsior/rooms/gnome_farms/farm1"]));
	set_door("gate","/wizards/excelsior/rooms/gnome_farms/farm1",
		"west","farm key");
	reset();
	set_door_pre_exit_function( "gate","travel_west");
	set_func("gate","unlock","check_guard");
	set_func("gate","open","stop_open");
	set_lock_level("gate",99);
}

int travel_west() {
	if(!present("guard")) return 1;
	if(present("omega",this_player())) return 1;
	write("%^CYAN%^%^BOLD%^The guard steps in your way as you try to enter "+
		"the wide open gateway. He points his weapon at you and %^RED%^%^BOLD%^growls.");
	present("guard")->force_me("speak common");
	present("guard")->force_me("say Halt right there buster. I cannot permit you "+
		"to enter these premises if you don't have a security level Omega "+
		"clearance card.");
	return 0;
}

int check_guard() {
	if(!present("guard")) return 1;
	if(present("omega",this_player())) return 1;
	write("%^CYAN%^%^BOLD%^The guard steps in your way as you try to stick "+
		"your key into the octogon shape on the gate.");
	present("guard")->force_me("speak common");
	present("guard")->force_me("say I'm sorry, but I can't allow you to unlock "+
		"this gate if you don't have a security level Omega clearance card.");
	return 0;
}

int stop_open() {
	if(!present("guard")) return 1;
		if(present("omega",this_player())) return 1;
	write("%^CYAN%^%^BOLD%^The guard steps in your way as you try to "+
		"open the large gate.");
	present("guard")->force_me("speak common");
	present("guard")->force_me("say I'm sorry, but I can't allow you to open "+
		"this gate if you don't have a security level Omega clearance card.");
	return 0;
}

	
string look_at_gate(string str) {
	string open_state,locked_state;
	if(query_locked("gate")) {
		locked_state = " and is currently locked.";
	} else {
		locked_state = " but it is not locked.";
	}
	if (query_open("gate")) { open_state = "The gate is open.";
		locked_state = " ";
	} else {
		open_state = "The gate is closed, "; 
	}
	write("This is a large iron gate that looks as though it is sturdy enough "+
		"to withstand a large battering ram for several days. In the center of "+
		"the door is a large octogon shape that looks like it could be a key "+
		"hole. Hrm, wonder where you could get hooked up with such a key. "+
		open_state+locked_state);
	return "This is a large iron gate that looks as though it is sturdy enough "+
		"to withstand a large battering ram for several days. In the center of "+
		"the door is a large octogon shape that looks like it could be a key "+
		"hole. Hrm, wonder where you could get hooked up with such a key. "+
		open_state+locked_state;
}

