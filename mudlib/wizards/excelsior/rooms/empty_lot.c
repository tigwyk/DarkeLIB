// /wizards/excelsior/rooms/empty_lot
// I love my work.

#include <std.h>

inherit ROOM;

int sifted;

void init() {
	::init();
	add_action("the_crack","enter");
	add_action("trash","sift");
}

void reset() {
	::reset();
	sifted = 0;
	remove_item("hole");
}

void create() {
	::create();
	set_property("light",1);
	set_property("night light",-2);
	set_property("indoors",0);
	set("short","In an abandoned lot");
	set("long","You have found your way into an abandoned lot in the middle "+
		"of the city. By what you've seen in the rest of the city, you can't "+
		"understand why squatters have not set up camp here. It suddenly "+
		"dawns on you- there is no obvious way to enter this courtyard. "+
		"As your slight claustrophobia turns into pure fear you look at your "+
		"surroundings. On all sides of the lot are large buildings. On the "+
		"one to your south you see a drainpipe that ends some 20 feet up and "+
		"an open window. There is trash everywhere.");
	set_items( (["buildings":"The one to your south is the theatre building.",
		"drainpipe":"The lower half of the pipe has been broken off. The "+
			"piece is lying on the ground.",
		"window":"It is almost two stories above you.",
		"trash":"Since you have nothing better to do, maybe you should 'sift' "+
			"through the trash." ]) );
	set_smell( "default","You smell the pungent aroma of garbage." );
	reset();
}

int trash( string str ) {
	if (str == "through trash" || str == "trash" ) {
		if (!sifted) {
			write("You sift through the trash and find nothing. Don't even bother "+
			"to try again...");
			sifted++;
			return 1;
		}
		write("You sift through the trash and find a hole in the theatre wall!");
		add_item("hole","It looks like this hole is large enough to 'enter'.");
		return 1;
	}
	notify_fail("Sift through what?\n");
	return 0;
}

int the_crack(string str) {
	if (str == "hole") {
		write( "You climb through the hole in the wall." );
		tell_room( this_object(), this_player()->query_cap_name()+" climbs "+
			"through a hole in the wall.", ({ this_player() }) );
		this_player()->move_player("/wizards/excelsior/rooms/basement");
		return 1;
	}
	notify_fail("Enter what orifice?\n");
	return 0;
}
