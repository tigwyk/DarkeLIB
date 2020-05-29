// /wizards/excelsior/rooms/level3/road3

inherit "/std/room";

void create() {
	::create();
	set_property("light",2);
	set_property("indoors",0);
	set_property("no mine",1);
	set_property("no castle",1);
	set("short","At the shoe stand");
	set("long","At this part of the open air market a kind old man has "+
		"set up a shoe shop. Perhaps you should take a look a closer look! "+
		"The market continues to both the north and the south.");
	set_items(([({"shoe shop","shop"}):"This shops deals in various footwear "+
			"and repair!",
		"market":"It is quite busy, there are people everywhere!"]));
	set_exits((["south":"/wizards/excelsior/rooms/level3/road2",
		"north":"/wizards/excelsior/rooms/level3/road4"]));
	reset();
}

void reset() {
	::reset();
	if(!present("shoe man"))
		new("/wizards/excelsior/rooms/shops/shoe_man")->move(this_object());
}
