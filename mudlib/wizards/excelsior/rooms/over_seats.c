// /wizards/excelsior/rooms/over_seats

inherit "std/room";

void reset() {
	::reset();
	if(!present("paper"))
		new("/wizards/excelsior/obj/tt_mpaper")->move(this_object());
	if(!present("thief"))
		new("/wizards/excelsior/mon/thief")->move(this_object());
}

void create() {
	::create();
	set_property("light",-2);
	set_property("indoors",1);
	set("short","Over the theatre seats");
	set("long","You are in an attic type area over the theatre seats. From "+
		"here theatre employess can fix the house lights. It is pretty "+
		"spooky up here, and you suddenly get the feeling you are not alone.");
	set_items((["lights":"You can change burnt out bulbs from up here."
		]));
	set_exits((["north":"/wizards/excelsior/rooms/catwalks2"
		]));
	reset();
}
