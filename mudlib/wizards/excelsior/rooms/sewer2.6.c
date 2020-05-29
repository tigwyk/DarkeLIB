// /wizards/excelsior/rooms/sewer2.6

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if (present("manfrog")) { return; }
	else {
		new("/wizards/excelsior/mon/manfrog")->move( this_object() );
		new("/wizards/excelsior/mon/manfrog")->move( this_object() );
		new("/wizards/excelsior/mon/manfrog")->move( this_object() );
	}
}

void create() {
	::create();
	set_property("light",-1);
	set_property("indoors",1);
	set("short","A mamoth intersection");
	set("long","You have come to a large intersection in the sewer system. "+
		"Tunnels head in almost every conceivable direction. However, there "+
		"is a trail of bread crumbs leading southeast. Hrm...");
	set_items( ([ ({"bread crumbs","crumbs"}):"They seem to beckon you to "+
			"go southeast."]) );
	set_exits( (["up":"/wizards/excelsior/rooms/sewer2.6",
		"down":"/wizards/excelsior/rooms/sewer2.6",
		"north":"/wizards/excelsior/rooms/sewer2.6",
		"south":"/wizards/excelsior/rooms/sewer2.6",
		"west":"/wizards/excelsior/rooms/sewer2.6",
		"northeast":"/wizards/excelsior/rooms/sewer2.6",
		"southwest":"/wizards/excelsior/rooms/sewer2.6",
		"east":"/wizards/excelsior/rooms/sewer2.7",
		"southeast":"/wizards/excelsior/rooms/sewer3.7",
		"northwest":"/wizards/excelsior/rooms/sewer_treasure" ]) );
	reset();
}
