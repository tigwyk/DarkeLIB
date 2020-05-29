// /wizards/excelsior/rooms/sewer2.9

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if (!present( "cow" ) ) new("/wizards/excelsior/mon/moo_cow")->move(
		this_object());
}

void create() {
	::create();
	set_property("light",0);
	set_property("indoors",1);
	set("short","Deeper in the sewers");
	set("long","You have clawed your way even deeper into the sewer system. "+
		"All these tunnels look the same. Sigh.");
	set_items( (["sewer":"Wtf.",
		"tunnels":"They all look the same.", ]) );
	set_exits( (["northwest":"/wizards/excelsior/rooms/sewer1.8",
		"south":"/wizards/excelsior/rooms/sewer3.8"]) );
	set_pre_exit_functions( ({"south"}),({"go_south"}) );
	reset();
}

int go_south() {
	write("The tunnel curves to your right, then back to your left.");
	return 1;
}
