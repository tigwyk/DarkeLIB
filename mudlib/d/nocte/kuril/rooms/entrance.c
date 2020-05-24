#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void create() {
	::create();
	set_property("indoors", 1);
	set_property("light", 1);
	set_property("no castle", 1);
	set("short", "   0\n   | \n   @   \n   | \n   0\nFoyer of the School of Necromancy");
	set("long",
		"Fine rugs and finishings line the foyer with an air of "
		"incredible affluence and power.  You take care to clean "
		"your boots of the filth and grime covering the streets "
		"of Kuril.  The very walls of this place glow with an inner "
		"life...I mean light.  The pitch black wood trimmings are in "
		"contrast to the pale glow emmanating from the walls.  A "
		"passageway southwards leads further into the School of "
		"Necromancy.  Rugs line the passageway while fine paintings "
		"and tapestries decorate the walls.\n   0\n   | \n   @   \n   | \n   0\n"
	);
	set_items( ([
		({ "rugs", "finishings" }): "They are from distant lands "
			"and places you have heard been to or even heard of.",
		"foyer": "There is an exit to the north while a passageway "
			"extends to the south",
		({ "filth", "grime" }): "Sometimes it is better not to know "
			"what some things are...",
		"streets": "Taking a peek outside, you decide that it is "
			"much safer inside here.",
		"walls": "If you listen carefully you can hear voices...",
		({ "wood", "trimmings", "wood trimmings" }): "Spartan in "
			"design, yet indulgent in its usage.",
		"glow": "It fills the room with just enough light to see by.",
		"passageway": "It leads southward, further into the School "
			"of Necromancy.  You wonder what secrets and mysteries "
			"are contained within these walls.",
		"paintings": "They depict part of the history of Kuril.  One "
			"in particular catches your attention.  It is a "
			"painting of a collection of robed figures, yet they "
			"are not all grouped together.  A smaller group is "
			"being led away from a city which is aflame...as if "
			"in exile.",
		"tapestries": (: call_other, this_object(), "look_tapestry" :)
	]) );
	set_exits( ([
		"north": ROOMS+"guardmans_road4",
		"south": "/d/damned/guilds/join_rooms/necromancer_join"
                       
	]) );

	set_listen("walls", "You swear you can hear the voices of people "
		"moaning and crying...");
	set_door("iron door", ROOMS+"guardmans_road4", "north",
		"kuril school of necromancy key");
	set_open("iron door", 0);
	set_locked("iron door", 0); 
}

void look_tapestry() {
	string RACE;

	RACE = (string)this_player()->query_race();
	if((string)this_player()->query_class() == "necromancer") {
		if((RACE == "high-elf") || (RACE == "wood-elf") ||
			(RACE == "half-elf")) {
		write("A tapestry of an elven male takes your fancy.  "
			"Upon closer inspection you notice that you can "
			"almost recognize some of the writing upon his "
			"robes.  One in particular looks like an ancient "
			"form of the symbol for 'healer'.  But that same "
			"symbol had another meaning for you as well...death.");
		return;
		}
		else {
			write("A tapestry of an elven male takes your fancy.  "
				"Upon closer inspection you notice that you "
				"can almost recognize some of the writing upon "
				"his robes.  One in particular has a special "
				"meaning for you...death.");
			return;
		}
	}
	if((RACE == "high-elf") || (RACE == "wood-elf") || 
		(RACE == "half-elf")) {
		 write("A tapestry of an elven male takes your fancy.  "
			"Upon closer inspection you notcie that you can "
			"almost recognize some of the writing upon his "
			"robes.  One in particular looks like an ancient "
			"form of the symbol for 'healer'."); 
		return;
	}
	else {
		write("A tapestry of an elven male takes your fancy.  "
			"There is some type of writing upon his robes "
			"but you are unable to read any of it."
		);
		return;
	}
}
