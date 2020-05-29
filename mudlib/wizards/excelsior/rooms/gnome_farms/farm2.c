// /wizards/excelsior/rooms/gnome_farms/farm2

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if(!present("guard")) 
		new("/wizards/excelsior/mon/ogre_guard")->move(this_object());
}

void create() {
	::create();
	set_property("light",1);
	set_property("indoors",0);
	set("short","The killing farms");
	set("long","Whatever this place is, it is very unpleasant. Here more "+
		"extremely unhappy looking gnomes are cramped into this small hallway "+
		"so tightly that you can't avoid stepping on some while you walk. You "+
		"feel revolted as you realize that this is the evolutionairy aid room "+
		"of this place. All the gnomes here appear to be weaker then the ones "+
		"you've already seen. Guards stomp around here killing off gnomes "+
		"whenever they feel like it. You realize with horror that the weaker "+
		"gnomes are being exterminated so as to breed only strong ones. You "+
		"want to vomit when it dawns on you that gnomes are being bred like "+
		"lab mice.");
	set_items((["gnomes":"All the gnomes in this room are doomed to be destroyed.",
		"guards":"They are goliaths."]));
	set_exits((["east":"/wizards/excelsior/rooms/gnome_farms/farm1",
		"west":"/wizards/excelsior/rooms/gnome_farms/farm3"]));
}
