#include <std.h>
#include "nevin.h"
inherit "std/vault";

void init() {
	::init();
	add_action("read", "read");
	add_action("spank", "spank");
	add_action("listen_conv", "listen");
}

void create(){
	::create();
	set_property("indoors", 1);
	set_property("light", 2);
	set_property("no castle", 1);
	set_property("no magic", 1);
	set_property("no attack", 1);
	set_property("no steal", 1);
	set("short", "   0\n   | \n   @   \n     \n    \nGolden Beers");
	set("long",
		"The wealthy clientele do their best to avoid staring at you.  "
		"It's not often that visitors come to this city...more "
		"specifically, it's not often that visitors last very long "
		"in this city.  Those before you are still alive through "
		"money, power, and magic.  But in this city money and power "
		"have one root...magic.  At night this tavern takes on a "
		"darker character as those of the night venture out to "
		"conduct their 'business'.  Given to taking quick insults "
		"and equally fast with the blade, you had better watch "
		"yourself around here if you want to avoid leaving feet "
		"first.  There is a menu posted on the wall.\n   0\n   | \n   @   \n     \n    \n"
	);
	set_listen("default", (: call_other, this_object(), "listen_default" :));
	set_items( ([
		"menu": "Try 'read'ing it.",
		"clientele": "They are minding their own business, perhaps "
			"you should as well."
	]) );
	set_exits( ([
		"north": "noblemans_lane7",
	]) );
	set_door("door", ROOMS+"noblemans_lane5.c", "north",
		"kuril golden beers key");
	set_open("door", 1);
	set_locked("door", 0);
}

void reset() {
	::reset();
	if(!present("fierana")) {
		new(MON+"fierana.c")
			->move(this_object());
	}
}

string listen_default() {
	if(query_night() == 1) {
		return "A heated arguement is taking place in the back of the "
			"room";
	}
	else {
		return "Lively conversations ranging from esoteric "
			"magical formulae to the current exchange rate of "
			"slaves along the Kurilian coast fill the room.";
	}
}

int read(string str) {
	object ob;
	int i;
	
	if(lower_case(str) != "menu") return notify_fail("There is "
		"no '"+str+"' here.\n");
	ob = present("fierana");
	if(!ob) {
		write("You can not read the blood covered menu.");
		return 1;
	}
	write("\n");
	write("           %^RED%^The Raking Claw\n");
	write("%^RED%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	write(sprintf("%32s %d silver", "A shot of darkegrass liquor", (int)ob->get_price("liquor")));
	write(sprintf("%32s %d silver", "A bowl of fried seraph feathers", (int)ob->get_price("feathers")));
	write(sprintf("%32s %d silver", "A plate of barbequed elf ears", (int)ob->get_price("ears")));
	write(sprintf("%32s %d silver", "A steamed roc egg", (int)ob->get_price("egg")));
	write(sprintf("%32s %d silver", "A plate of kraken embryos", (int)ob->get_price("embryos")));
	write("%^RED%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	write("<buy item> gets you the food or drink you desire.");
	write("\n");
	return 1;
}

int spank(string str) {
	if(!str) {
		return 0;
	}
	if(str == "fierana") {
		write("Fierana winks at you as you spank her bottom.");
		say("Fierana pouts as "
			+(string)this_player()->
			query_cap_name()+ "spanks her bottom!");
		return 1;
	}
}

int listen_conv(string str) {
	if(!str) {
		notify_fail("What do you want to listen to?");
		return 0;
	}
	else {
		write("You overhear two men talking about some type "
			"type of underground rebellion.");
			return 1;
	}
}
