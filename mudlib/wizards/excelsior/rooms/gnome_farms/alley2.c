// /wizards/excelsior/rooms/gnome_farms/alley2

#include <std.h>
#include <clock.h>
#include <daemons.h>

inherit ROOM;

int check;

void reset() {
	int ran;
	::reset();
	if (!present("thief")) {
		new("/wizards/excelsior/mon/thief")->move(this_object());
	}
	if (!present("thief 2")) {
		if ((string)EVENTS_D->query_time_of_day() == "day") { ran = 2; }
		else { ran = 1; }
		if(!random(ran)) new("/wizards/excelsior/mon/thief")->move(
			this_object());
	}
	check = 0;
}

void init() {
	::init();
	if(present("thief 2")) {
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
	set("long","You are traveling deeper and deeper into a New Faerie "+
		"Dust slum. You wonder if anywhere in this blasted darn toot 'in "+
		"city ain't no slum. Ahhh! You've got to get out of here! You're "+
		"going crazy! You're becoming.... a redneck! Though there is plenty "+
		"of people moving idly about, no one really seems to be going to the "+
		"southeast. Hrm. Well, whatever is there can't be worse then here! "+
		"The filth of this alley way and the squatters in abondoned buildings "+
		"around you make this place very unpleasant. There are children to your "+
		"west.");
	set_items( (["children":"They seem to be immune to there disgusting environment.",
		"buildings":"Many look condemned.",
		"people":"They are very poor. You are glad you are not them. Most of "+
			"look very rough and mean."]) );
	set_exits( (["west":"/wizards/excelsior/rooms/gnome_farms/alley1",
		"southeast":"/wizards/excelsior/rooms/gnome_farms/farm_gate"]) );
	set_smell("default","You smell rotting trash that the people have dumped here.");
	set_smell("trash","Where the hell is the sanitation department?");
}
