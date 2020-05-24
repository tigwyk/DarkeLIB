#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void init() {
	::init();
	add_action("read", "read");
	add_action("spank", "spank");
	add_action("door_open", "open");
}

void create() {
	::create();
	set_property("indoors", 1);
	set_property("light", 2);
	set_property("no castle", 1);
	set_property("no magic", 1);
	set_property("no attack", 1);
	set_property("no steal", 1);
	set("short", "   \n    \n0--@--0\n    \n   \nThe Siren's Song");
	set("long",
		"Located in the seedier side of town, the Siren's Song has "
		"been known to attract all sorts of beings to its doors.  "
		"Known throughout Kuril as a good place to swap stories and "
		"information, you can bet that most deals and under the "
		"table agreements took place here.  The back room is to the "
		"east offering those who dare to enter a place for private "
		"discussion and verbal exchange....  A menu has been posted "
		"on the wall.\n   \n    \n0--@--0\n    \n   \n"
	);
	set_items( ([
		({"room", "back room"}):  "It is to the east from the main "
			"room of the Siren's Song.",
		"menu": "Try 'read'ing it.",
		"door": (: call_other, this_object(), "look_door" :)
	]) );
	set_exits( ([
		"west": ROOMS+"merchant_road4",
		"east": ROOMS+"backroom"
	]) );
	set_door("door", ROOMS+"merchant_road4.c", "west",
		"kuril sirens song key");
	set_open("door", 1);
	set_locked("door", 0);
	set_door("curtain", ROOMS+"backroom", "east", 0);
	set_open("curtain", 1);
	set_locked("curtain", 0);
	set_open_function("open_door", "07:00:00");
	set_close_function("close_door", "15:00:00");
}

void reset() {
	::reset();
	if(!present("hsspra")) {
		new(MON+"hsspra.c")
			->move(this_object());
	}
}

int read(string str) {
	object ob;
	int i;
	
	if(lower_case(str) != "menu") return notify_fail("There is "
		"no '"+str+"' here.\n");
	ob = present("hsspra");
	if(!ob) {
		write("You can not read the blood covered menu.");
		return 1;
	}
	write("\n");
	write("           %^CYAN%^The Siren's Song\n");
	write("%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	write(sprintf("%30s %d silver", "A glass of spiced cider", (int)ob->get_price("cider")));
	write(sprintf("%30s %d silver", "A mug of dark dwarven ale", (int)ob->get_price("ale")));
	write(sprintf("%30s %d silver", "A glass of Aormalian mint wine", (int)ob->get_price("wine")));
	write(sprintf("%30s %d silver", "A bowl of stew", (int)ob->get_price("stew")));
	write(sprintf("%30s %d silver", "A serving of seeded bread", (int)ob->get_price("bread")));
	write("%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	write("<buy item> gets you the food or drink you desire.");
	write("\n");
	return 1;
}

int spank(string str) {
	if(!str) {
		return 0;
	}
	if(str == "hsspra") {
		write("Hsspra winks at you as you spank her bottom.");
		say("Hsspra takes a swipe with her claws as"
			+(string)this_player()->
			query_cap_name()+ "spanks her bottom!");
		return 1;
	}
}

int door_open(string str) {
	if(!str) { return 0; }
	if(!(str == "door")) { return 0; }
	set_open("door", 1);
	set_locked("door", 0);
	message("info", "The door opens.", TO);
	message("info", "The door to the Siren's Song opens from the "
		"other side.", ROOMS+"merchant_road4");
	call_other(ROOMS+"merchant_road4", "force_open");
	call_out("door_close", 3);
	return 1;
}

void door_close() {
	set_open("door", 0);
	set_locked("door", 1);
	call_other(ROOMS+"merchant_road4", "force_closed");
	message("info", "The door shuts...hmm.  You wonder who closed it.", TO);
	message("info", "The door to the Siren's Song shuts by itself"
		"...strange.", ROOMS+"merchant_road4");
}

void force_open() {
	set_open("door", 1);
	set_locked("door", 0);
}

void open_door() {
	set_locked("door", 0);
	set_open("door", 1);
	call_other(ROOMS+"merchant_road4", "set_locked",
		"door", 0);
	call_other(ROOMS+"merchant_road4", "set_open",
		"door", 1);
	this_object()->reset();
}

void close_door() {
	set_open("door", 0);
	set_locked("door", 1);
	call_other(ROOMS+"merchant_road4", "set_locked",
		"door", 1);
	call_other(ROOMS+"merchant_road4", "set_open",
		"door", 0);
}

void look_door() {
	if(!query_open("door")) {
		write("The door to the Siren's Song is closed.");
	}
	else {
		write("The door to the Siren's Song is wide open");
	}
}
