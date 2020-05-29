// /wizards/excelsior/rooms/sewer3.9

inherit "std/room";

void reset() {
	::reset();
	if (!present("slug")) {
		new("/wizards/excelsior/mon/booga_boo")->move(this_object());
	}
}

void create() {
	::create();
	set_property("light",-2);
	set_property("indoors",1);
	set("short","A disgusting sewer tunnel");
	set("long","During your visit to New Faerie Dust so far "+
		"you have come accross many disgusting things. This one ranks "+
		"close to the top. You are wading knee deep in the filth of the "+
		"New Faerie Dust Sewer System- quite ahead of its time, but recently "+
		"mantainance funding has gone way down, and quite frankly you don't "+
		"believe that they are mantained at all. All kinds of junk float "+
		"in the gunk that serves as the water of this tunnel. Fishing "+
		"poles, clothing, fence boards. On the bottom you feel with your "+
		"feet kitchen utensils and other metal objects. It is apparent the "+
		"people use the sewers of New Faerie Dust for far more then "+
		"relieving their natural body functions.");
	set_items( (["filth":"You try not to think about whatever you are "+
		"standing in.","junk":"You wonder how some of this stuff can "+
		"fit down the primitive toilets people use.","tunnel":
		"Dark and gross. You don't want to know what you just "+
		"stepped on."]) );
	set_exits( (["south":"/wizards/excelsior/rooms/sewer4.9",
		"northwest":"/wizards/excelsior/rooms/sewer2.8" ]) );
	set_smell("default","You smell god only knows what.");
}
