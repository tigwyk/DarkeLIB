#include <std.h>
#include "nevin.h"
inherit ROOM;

void reset() {
	::reset();
	if(!present("guard")) {
		new(MON+"wm_chaotic")->move(TO);
		new(MON+"wm_chaotic")->move(TO);
	}
	if(!present("hound")) {
		new(MON+"chound")->move(TO);
		new(MON+"chound")->move(TO);
	}
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
	if(query_night()) {
		if(!present("wight")) {
			new(MON+"ku_wight")->move(TO);
		}
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   0\n   | \n   @   \n   | \n   0\nThieve's Court");
	set("long",
		"Standing before the dark temple, you feel insignificant "
		"next to the seething evil residing within.  A ball of "
		"you don't know what rises in your throat as you take in "
		"the immense structue.  Elven design is plainly evident "
		"in the once graceful arches and flying butresses.  But "
		"the once beautiful temple has been desicrated.  The once "
		"ivory white stone has been cracked and scared.  Burned and "
		"scorched by searing heat, they are now black and pitted. "
		"Runes of power have been litteraly carved into the stone. "
		"A faint red glow can be seen in each cut.  The courtyard "
		"in which you are standing continues southward.\n   0\n   | \n   @   \n   | \n   0\n"
	);
	set_items( ([
		"rock": "You have no idea what it is made of...perhaps it's "
			"not even from this world.",	
		"runes": (: call_other, this_object(), "look_runes" :)
	]) );
	set_exits( ([
		"north": ROOMS+"merchant_road6",
		"south": ROOMS+"thieves_court2"
	]) );
}

int look_runes(string str) {
	if(!str) {
		return 0;
	}
	if((str == "runes") || (str == "sigils")) {
		if((string)this_player()->query_class() == "chaotic-lord") {
			write("You immediately recognize the symbols of "
				"unholy might, summoning, and darkness.");
		}
		else {
			write("Your head begins to swim as you look at the "
				"runes and sigils.");
			say((string)this_player()->query_cap_name()+
				" collapses from looking at the wall.");
			this_player()->set_paralyzed(30, "Your head is still "
				"swimming from staring at those foul runes!");
		}
		return 1;
	}
}
