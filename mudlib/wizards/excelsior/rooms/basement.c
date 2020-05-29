// /wizards/excelsior/rooms/basement
// in 'da basement

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if ( !present("basement dweller")) new("/wizards/excelsior/mon"+
		"/basement_dweller")->move( this_object() );
}

void init() {
	::init();
	add_action("hole","enter");
}

void create() {
	::create();
	set_property("light",1);
	set_property("indoors",1);
	set("short","In theatre storage");
	set("long","You have found your way into the old theatre prop warehouse. "+
		"Scattered about are backdrops, fake walls, torn curtains, beds, "+
		"tables, chairs, and all sorts of other neat stuff! If only "+
		"you had time to search through it all! Well, actually you "+
		"DO have time! As you think this to yourself happily, you realize "+
		"that it looks as though something lives here...");
	set_items( (["props":"All kind of neat stuff lies around for you to search "+
				"through."]) );
	set_exits( (["south":"/wizards/excelsior/rooms/backstage_under"]) );
	set_search( "default","You find a hole in the wall that you could probably "+
		"'enter'.");
}

int hole(string str) {
	if ( str == "hole" ) {
		write("You slip through the hole in the wall...");
		this_player()->move( "/wizards/excelsior/rooms/empty_lot" );
		return 1;
	}
	notify_fail("Enter what?\n");
	return 0;
}
