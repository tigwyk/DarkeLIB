// /wizards/excelsior/rooms/catwalks

inherit "std/room";

void create() {
	::create();
	set_property("light",1);
	set_property("indoors",1);
	set("short","On the catwalk");
	set("long","You have climbed up onto the catwalks above the stage. "+
		"Here theatre employess can adjust lights and fix curtains. "+
		"The catwalks continue to the east, or you can return to stage "+
		"level by going down.");
	set_items((["lights":"They are all over. You wonder how they are "+
		"powered."
,

		"curtains":"They are raised ones are at your level up here."]));
	set_exits((["east":"/wizards/excelsior/rooms/catwalks2",
		"down":"/wizards/excelsior/rooms/backstage_left"]));
}
