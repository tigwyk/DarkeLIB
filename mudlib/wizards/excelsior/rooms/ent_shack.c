// /wizards/excelsior/rooms/ent_shack

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if (!present("ent")) new("/wizards/excelsior/mon/ent")->move(
		this_object());
}

void create() {
	::create();
	set_property("light",1);
	set_property("indoors",1);
	set("short","In the house of an ent");
	set("long","This is the ruined shack of an ancient ent. Though the house "+
		"is practically falling down, it looks as though the ent who lives "+
		"here is perfectly happy and content. You wonder how this could be "+
		"in a place so full of poverty. The ent that lives here could probably "+
		"provide you with some valuable information.");
	set_items( (["shack":"It is in the corner of two large apartment buildings."
,
		"house":"It is probably condemned." ]) );
	set_exits( (["northeast":"/wizards/excelsior/rooms/street4.4"
		]) );
}
