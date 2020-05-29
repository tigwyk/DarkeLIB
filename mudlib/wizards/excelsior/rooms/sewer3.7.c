// /wizards/excelsior/rooms/sewer3.7
// the last sewer room.

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if (!present("cow")) {
		new("/wizards/excelsior/mon/moo_cow")->move( this_object() );
		new("/wizards/excelsior/mon/moo_cow")->move( this_object() );
	}
}

void create() {
	::create();
	set_property("light",0);
	set_property("indoors",1);
	set("short","Near a light source");
	set("long","You are extremely deep in the New Faerie Dust sewer system. "+
		"To your west there is some sort of lighted room. It appears almost "+
		"as though someone lives here. The mind boggles...");
	set_items( (["workroom":"To the west, go check it out."
		]) );
	set_exits( (["west":"/wizards/excelsior/rooms/sewer_workroom",
		"northwest":"/wizards/excelsior/rooms/sewer2.6" ]) );
	set_listen( "default","You hear the sounds of someone huming." );
}
