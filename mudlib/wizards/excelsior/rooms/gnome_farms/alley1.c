// /wizards/excelsior/rooms/gnome_farms/alley1

#include <std.h>
#include <clock.h>
#include <daemons.h>

inherit ROOM;

int check;

void reset() {
	int ran;
	::reset();
	if (!present("thief")) {
		if ((string)EVENTS_D->query_time_of_day() == "day") { ran = 2; }
		else { ran = 1; }
		if(!random(ran)) new("/wizards/excelsior/mon/thief")->move(
			this_object());
	}
	check = 0;
}

void init() {
	::init();
	if(present("thief")) {
		if((string)EVENTS_D->query_time_of_day() == "day") {
			if(random(2)) {
				present("thief")->remove();
				check = 1;
			}
		}
	}
	else {
		if((string)EVENTS_D->query_time_of_day() != "day") {
			if(check) {
				new("/wizards/excelsior/mon/thief")->move(this_object());
				check = 0;
			}
		}
	}
}

void create() {
	::create();
	set_property("light",0);
	set_property("indoors",0);
	set("short","In a dark alleyway");
	set("day long","You are now in a long dark alleyway. All around you are "+
		"homeless people practically lying in their own waist. You slowly "+
		"approach one old human who isn't moving who you discover to your "+
		"own squimish horror is dead. You decide you'd better move along "+
		"quickly, because this area of town is no doubt crime infested. "+
		"To your south is an old abondoned apartment building that "+
		"has been condemned. And yet, children run in and out of it. You wonder "+
		"if they know who their parents are. You would not want to be here at "+
		"night. You have heared criminals are much more active at that time.");
	set("night long","You are now in a long dark alleyway. All around you are "+
		"homeless people practically lying in the own waist. You slowly "+
		"approach one old human who isn't moving who you discover to your "+
		"own squimish horror is dead. You decide you'd better move along "+
		"quickly, because this area of town is no doubt crime infested. "+
		"To your south is an old abondoned apartment building that "+
		"has been condemned. Inside you see several children sleeping. You wonder "+
		"if they know who their parents are. To bad you decided to come here at "+
		"night. You have heared criminals are much more active at this time.");
	set_items( (["children":"They are either orphans, run aways, or their parents "+
		"don't watch them that great. They will probably grow up to be criminals "+
		"of some sort. If only you could help them now. To bad you are to selfish "+
		"to pay taxes. You would rather spend your money on hair care products.",
		"building":"It looks like it is about to collapse. You do not want to "+
			"enter it to find out if it will.",
		"man":"You consider looting the corpse but soon realize it is already "+
			"picked clean.",
		"people":"They are very poor. You are glad you are not them."]) );
	set_exits( (["west":"/wizards/excelsior/rooms/street6.5",
		"east":"/wizards/excelsior/rooms/gnome_farms/alley2"]) );
	set_smell("default","You smell rotting trash that the people have dumped here.");
	set_smell("trash","Where the hell is the sanitation department?");
}
