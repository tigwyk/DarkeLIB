#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void init() {
	::init();
	if(this_player()->chk_dock_mob()) {
		add_action("no_exit", "east");
	}
	if(this_player()->chk_my_mob()) {
		if(!query_open("door")) {
			add_action("no_exit", "east");
		}
	}
	add_action("door_open", "open");
}

void reset() {
	::reset();
	if(!query_night()) {
		if(!present("watchman")) {
			new(MON+"wm_fighter")->move(TO);
		}
		if(!present("citizen")) {
			new(MON+"kuril_cit_lw")->move(TO);
			new(MON+"kuril_cit_lw")->move(TO);
		}
		if(!present("dockworker")) {
			new(MON+"dockworker")->move(TO);
		}
	}
}

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   0\n   | \n0--@--0\n   | \n   0\nMerchant Road");
	set("long",
		"Welcome to Kuril, city of darkness, city of chaos.  "
		"Here the dead out number the living.  Once "
		"a beautiful city, it has fallen into decay and corruption.  "
		"Political office is now purchased.  The knights of Kuril are "
		"nothing more than a group of bandits and brigands.  Everyone "
		"knows that you can purchase knighthood with a large donation "
		"to the city government...or the locals Necromancers Guild.  "
		"As you step foot into Kuril you are immediatly assaulted by "
		"the vileness of the city.  Thieves, murderers, and body "
		"dealers all take immediate notice of you.  But they also "
		"seem abit wary...perhaps it's the fact that you have  come here "
		"willingly.  This is a strange sight for a city that maintains "
		"it's body count by bringing new 'visitors' to Kuril by ship..."
		"and in chains if they are still alive.  Directly to the east "
		"is the local watering hole, the Siren's Song.  Serving "
		"Kuril's waterfront clientelle, the Siren's Song is known "
		"for it's strong ale and delicious stew...to name a few "
		"things.\n   0\n   | \n0--@--0\n   | \n   0\n"
	);
	set_items( ([
		"tavern": "There is a large sign that reads:  The Siren's Song",
		({"thieves", "cutpurses", "pickpockets", "informants"}): 
			"They quickly blend into the crowd as you look their "
			"way.",
		"sailors": "One empties his stomach right in front of you"
			"...  Oh!  The smell!",
		"punks": "With a quick flick from a shiv, a street punk "
			"relieves a sailor of some extra money.",
		"door": (: call_other, this_object(), "look_door" :)
	]) );
	set_exits( ([
		"north": ROOMS+"merchant_road3",
		"east": ROOMS+"sirens_song",
		"south": ROOMS+"merchant_road5",
		"west": ROOMS+"pier2"
	]) );
	set_door("door", ROOMS+"sirens_song.c", "east",
		"kuril sirens song key");
	set_open("door", 1);
	set_locked("door", 0);
	set_open_function("open_door", "07:00:00");
	set_close_function("close_door", "15:00:00");
}

void open_door() {
	call_other(ROOMS+"sirens_song", "open_door");
}

int door_open(string str) {
	if(!str) { return 0; }
	if(!(str == "door")) { return 0; }
	set_open("door", 1);
	set_locked("door", 0);
	message("info", TPQCN+" opens the door to the Siren's Song.", ENV(TP),
		({TP}) );
	message("info", "You open the door to the Siren's Song.", TP);
	message("info", "The door opens from the other side.", ROOMS+
		"sirens_song");
	call_other(ROOMS+"sirens_song", "force_open");
	call_out("door_close", 3);
	return 1;
}

void force_open() {
	set_open("door", 1);
	set_locked("door", 0);
	
}

void force_closed() {
	set_open("door", 0);
	set_locked("door", 1);
}

void door_close() {
	set_open("door", 0);
	set_locked("door", 1);
	call_other(ROOMS+"sirens_song", "door_close");
}

void close_door() {
	call_other(ROOMS+"sirens_song", "close_door");
}

void look_door() {
	if(!query_open("door")) {
		write("The door to the Siren's Song is closed.");
	}
	else {
		write("The door to the Siren's Song sits wide open.");
	}
}

int no_exit() {
	return 1;
}
