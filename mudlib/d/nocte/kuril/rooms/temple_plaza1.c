#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void init() {
	::init();
	add_action("pick_lock", "pick");
	add_action("open_door", "open");
	add_action("go_south", "south");
	if(this_player()->chk_my_mob()) {
		add_action("no_exit", "south");
	}
}

void reset() {
	::reset();
	if(!query_night()) {
		if(!present("guard")) {
			new(MON+"wm_chaotic")->move(TO);
			new(MON+"wm_chaotic")->move(TO);
		}		
            if(!present("hound")) {
			new(MON+"chound")->move(TO);
			new(MON+"chound")->move(TO);
		}
	}
	if(query_night()) {
		if(!present("wight")) {
			new(MON+"ku_wight")->move(TO);
		}
		if(!present("ghost")) {	new(MON+"ghost")->move(TO); }
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("light night", -5);
	set_property("no castle", 1);
	set("short", "   \n    \n0--@--0\n   | \n   0\nTemple Plaza");
	set("long",
		"A foul sense of evil and unholy corruption swirls around you. "
		" You are almost brought to your knees by a feeling of "
		"fear and uncertainty.  Steeling yourself, you manage to keep "
		"your footing.  A dull redish glow fills the air from a "
		"large black door to the south.  Runes of power crackle with "
		"energy as bolts of electricity sizzle the surface of the "
		"black door.  Looking upward you can see bodies hanging from "
		"the edges of the temple.  Carrion birds have perched "
		"themselves on the shoulders of the bodies...picking away at "
		"their flesh.  You notice that nobody can be seen walking "
		"the streets around the temple.  Perhaps you had better hurry "
		"along before you end up like one of the ornaments hanging "
		"from the temple walls.\n   \n    \n0--@--0\n   | \n   0\n"
	);
	set_items( ([
		"temple": "Glowing runes cover the temple like a web of power.",
		"runes": (: this_object(), "look_runes" :),
		"door": "Fashioned from some unknown material, the large "
			"hinges have been hammered into the temple walls.",
		"bodies": "An occasional moan escapes from one of the poor "
			"souls who hopefully only have days to live.",
		"birds": "Foul birds with large red eyes, they stare at you "
			"as you pass.",
		"walls": "You dare not touch it, for fear of what may befall "
			"you."
	]) );
	set_exits( ([
		"east": "temple_plaza2",
		"south": "temple/temple1",
		"west": "merchant_road6"
	]) );
	set_listen("default", "The cries of the tortured and damned "
		"reverberate off the walls of the surrounding buildings.");
	set_door("black door", ROOMS+"temple/temple1.c",
		"south", 0);
	set_open("black door", 0);
	set_locked("black door", 1);
}

int look_runes(string str) {
	if(!str) {
		return 0;
	}
	if(str == "runes") {
		if((string)this_player()->query_class() == "chaotic-lord") {
			write("You immediatly recognize the symbols of "
				"unholy might, summoning, and darkness.");
		}
		else {
			write("Your head begins to swim as you look at the "
				"runes.");
			say((string)this_player()->query_cap_name()+
				" collapses from looking at the door.");
			this_player()->set_paralyzed(60, "Your head is still "
				"swimming from staring at those foul runes!");
		}
		return 1;
	}
}

int pick_lock(string str) {return 0;}

int open_door(string str) {
	if(!str) {
		return 0;
	}
	if((str == "door") || (str == "black door")) {
		write("%^BOLD%^%^RED%^The flesh is seared off of your hand "
			"while a bolt of "
			"electricity blasts into your chest throwing you "
			"backwards.");
		say("%^BOLD%^%^RED%^" +(string)this_player()->query_cap_name()+
			" is thrown backwards by a bolt of lightning after "
			"trying to open the temple door.  Seared flesh "
			"hangs from the door like a piece of scorched cloth.");
		this_player()->add_hp(-((((int)TP->query_hp() ) / 10)*9 + 50));
		this_player()->set_paralyzed(60, "Your muscles are still "
			"convulsing from the intense shock!");
	}
	write_file("/d/nocte/kuril/logs/temple.log", TPQCN+" got blasted "
		"by the temple door from trying to open it at "+ctime(time())+
		".\n");
	return 1;
}

int go_south() {
	write("%^BOLD%^%^RED%^A bolt of energy blasts into you throwing you "
		"backwards.%^RESET%^");
	say("%^BOLD%^%^RED%^A bolt of energy slams into " +
		(string)this_player()->query_cap_name()+ "'s chest as " +
		(string)this_player()->query_subjective()+ " walks right into "
		"the black door of the temple.%^RESET%^");
	this_player()->add_hp(-((((int)this_player()->query_hp() ) / 10)*9 + 50));
	this_player()->set_paralyzed(90, "Your muscles are still "
		"convulsing from the intense shock!");
	write_file("/d/nocte/kuril/logs/temple.log", TPQCN+" got blasted by "
		"the temple door at "+ctime(time())+".\n");
	return 1;
}

int no_exit() {
	return 1;
}
