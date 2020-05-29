// wizards/excelsior/rooms/level3/bard_home

#include <std.h>

inherit ROOM;

int bashed,stre;

void create() {
	::create();
	set_property("indoors",1);
	set_property("no castle",1);
	set_property("no mine",1);
	set_property("light",3);
	set("short","In a dank corner");
	set("long","After brushing yourself off from your little window escapade "+
		"you look around. You appear to be in a small closet of someones house. "
		);
	set_items((["sign":"You decide to read the sign over and over again. "+
			"'Condemned, do not enter.' 'Condemned, do not enter.' "+
			"'Condemned, do not enter.' 'Condemned, do not enter.' "+
			"'Condemned, do not enter.' 'Condemned, do not enter.' "+
			"'Condemned, do not enter.' 'Condemned, do not enter.' ",
		"poster":"The poster reads: 'Falsath the Bard is coming to a theatre "+
			"near you! Don't miss him!",
		"window":"You climbed through, you old monkey you.",
		"eyes":"You hate your stupid eyes! Damn them damn them damn them!",
		"closet":"You boggle that someone could live in such a small place.",
		"house":"The closet is a part of a larger house. The building "+ 
			"appears to have been condemned by housing authorities.",
		"door":"You may be able to 'bash' the door open."]));
	set_exits((["window":"/wizards/excelsior/rooms/level3/road2"]));
	reset();
}

void reset() {
	::reset();
	if(!present("bard")) 
		new("/wizards/excelsior/mon/bard")->move(this_object());
	stre = 1;
	if(bashed) {
		bashed = 0;
		remove_exit("south");
		remove_item("door");
		add_item("door","You may be able to 'bash' the door open.");
	}	
}

void init() {
	::init();
	add_action("bash","bash");
}

int bash(string str) {
	int i;
	string gen_message,other_gen;
	if(str != "door") {
		notify_fail("Bash what, best beloved?\n");
		return 0;
	}
	i = (int)this_player()->query_stats("strength");
	i = 2*i/3;
	if (random(120)/stre < i) {
		switch((string)this_player()->query_gender()) {
			case "male":
				gen_message = "You big lug you!";
				other_gen = "Isn't he a big muscular lug?";
				break;
			case "female":
				gen_message = "Wow! You are one buff babe!";
				other_gen = "That girl is tuff!!";
				break;
			case "neuter":
				gen_message = "Having no gender doesn't seem to impede your strength!";
				other_gen = "Even without a gender that thing is as strong as a rock!";
				break;
		}
		write("You bash in the door! You may now proceed 'south'! "+gen_message);
		message("other_action",(string)this_player()->query_cap_name()+" manages "+
			"to bash through the door, opening up the exit 'south'. "+other_gen,
			this_object(),({this_player()}));
		add_exit("/wizards/excelsior/rooms/level3/back_room","south");
		remove_item("door");
		add_item("door","Someone bashed it open! Wow! They must've been buff!");
		bashed = 1;
		return 1;
	}
	else {
		write("You bash the door, weakening it, "+
			"but it doesn't quite break. Try again?");
		message("other_action",(string)this_player()->query_cap_name()+" bashes "+
			"the door, but it doesn't quite break. It looks weakened though.",
			this_object(),({this_player()}));	
		stre++;
		return 1;
	}
}

string query_long(string str) {
	string rest_long,door_msg;
		if(str) return describe(str);
	rest_long = "This place gives you the shivers. You are about to "+
		"leave when you notice "+
		"a sign on the ground. It reads: 'Condemned, do not enter'. You have an "+
		"even stronger urge to leave. But just as you are climbing back out the "+
		"window your dang eyes see yet another interesting object- a poster! "+
		"You realize suddenly that someone has moved into this closet! "+
		"You could never do that, you are too clausterphobic. Wuss.";
	if(!bashed) {
		door_msg = "You try to open the door out of the closet but it is "+
			"hopelessly rusted shut.";
	} else {
		door_msg = "The door out of the closet seems to have been bashed open by "+
			"someone.";
	}
	return ::query_long()+" "+door_msg+" "+rest_long;
}
