#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void create() {
	object ob;
	::create();
	set_property("indoors", 1);
	set_property("light", 2);
	set_property("no castle", 1);
	set_property("no magic", 1);
	set_property("no attack", 1);
	set_property("no steal", 1);
	set("short", "   \n    \n0--@   \n    \n   \nBack room of the Siren's Song");
	set("long",
		"Dim candle light illuminates the back room of the Siren's "
		"Song.  Whispering voices can be heard in the corners of the "
		"room while glowing night eyes gaze at you from the depths "
		"of the many shadows within...  Along the back wall is a "
		"plaque surrounded by a shimmering border.\n   \n    \n0--@   \n    \n   \n"
	);
	set_items( ([
		"candles": "They sputter softly while forming long trails "
			"of wax oozing down to their base.",
		"corners": "It would be disasterous to your health to "
			"interfere in the conversations of others.",
		"eyes": "You feel as if you are being constantly watched.",
		"shadows": "For some reason the light within the room "
			"is unable to penetrate into the murky depths of "
			"darkness within the room.",
		"plaque": (: call_other, this_object(), "look_plaque" :)
	]) );
	set_exits( ([
		"west": ROOMS+"sirens_song"
	]) );
	set_door("curtain", ROOMS+"sirens_song", "west", 0);
	set_open("curtain", 1);
	set_locked("curtain", 0);
	ob = new("/std/bboard");
	ob->set_name("board");
	ob->set_id( ({"board", "comment board" }) );
	ob->set_board_id("kuril-comment-board");
	ob->set_max_posts(50);
	ob->set_location(ROOMS+"backroom");
	ob->set("short", "%^CYAN%^%^BOLD%^Kuril Comment Board%^MAGENTA%^%^BOLD%^");
	ob->set("long", "Welcome to Kuril, please post any bugs, comments, or "
		"suggestions upon this board.  ");
	ob->set_weight(1000000);
}

void look_plaque() {
	write("\n\n\n");
	write("         The Plaque Commorates the Opening of the          ");
	write("                      City of Kuril                        ");
	write("                                                           ");
	write("                      Coder: nEv!N                         ");
	write("                                                           ");
	write("              Balance: Khojem and Duridian                 ");
	write("              Opening Date: July 11, 1996                  ");
	write("                                                           ");
	write("   Special thanks go to Khojem and Duridian who spent      ");
	write("   time out of their busy schedule to go through Kuril.    ");
	write("\n\n\n");
}
