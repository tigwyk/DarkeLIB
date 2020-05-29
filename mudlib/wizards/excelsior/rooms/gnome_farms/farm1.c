//  /wizards/excelsior/rooms/gnome_farm/farm1

#include <std.h>

inherit VAULT;

void reset() {
	::reset();
	if(!present("gnome"))
		new("/wizards/excelsior/mon/gnome")->move(this_object());
		set_open("gate",0);
	set_locked("gate",1);
	"/wizards/excelsior/rooms/gnome_farms/farm_gate"->set_open("gate",0);
	"/wizards/excelsior/rooms/gnome_farms/farm_gate"->set_locked("gate",1);
}

void create() {
	::create();
	set_property("light",0);
	set_property("indoors",0);
	set("short","In the gnome farms");
	set("long","You though you had seen some horrible sights in your life, "+
		"but this has got to be one of the worst. All around are deathly thin "+
		"and sick looking gnomes. They are lying practically motionless against "+
		"the cold stone walls of this small hallway while guards walk amoung them "+
		"and beat them. At first you can't tell what they are doing, but you soon "+
		"realize that the gnomes are emitting tons of magical forces. What could "+
		"this place be?");
	set_items((["gnomes":"They are in pretty bad shape.",
		"walls":"Solid stone. It would be very hard to break in, or out, "+
			"of this place.",
		"guards":"Many of them carry whips and other torture devices."
,
		"gate":(: call_other,this_object(),"look_at_gate":)]));
	set_exits((["east":"/wizards/excelsior/rooms/gnome_farms/farm_gate",
		"west":"/wizards/excelsior/rooms/gnome_farms/farm2"]));
	set_door("gate","/wizards/excelsior/rooms/gnome_farms/farm_gate",
		"east","farm key");
	set_lock_level("gate",99);
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
