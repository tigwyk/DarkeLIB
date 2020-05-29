// /wizards/excelsior/rooms/backstage_left.2
// hrm bog wtf imho ymtc jesus enenenenen

inherit "std/room";

void create() {
	::create();
	set_property("light",0);
	set_property("indoors",1);
	set("short","The prop room");
	set("long","This is the back stage prop building room of the theatre. "+
		"Thrown about the room in seemingly random order are assorted "+
		"chairs, tables, couches, backdrops, tools, doors and tons of "+
		"other worthless junk that doesn't interest you in the slightest. "+
		"A small slip of paper, however, does catch your attention. It seems "+
		"to be begging you to look at it with its beautiful form and color.");
	set_items( ([ ({"chairs","tables","couches","backdrops","tools","doors",
		"junk","props"}):"Worthless stuff that you don't care about.",
		({"slip","paper"}):"It says: This side is freakin' RIGHT stage! "+
			"'Very deep,' you think." ]) );
	set_exits( (["east":"/wizards/excelsior/rooms/backstage",
		"southwest":"/wizards/excelsior/rooms/backstage_left" ]) );
	set_smell( "default","You smell rotting wood and props." );
}
