// /wizards/excelsior/rooms/road_up1
// headed for level 2!
// by Excelsior 8/26/95

inherit "std/room";

void create() {
	::create();
	set_property("light",1);
	set_property("night light",1);
	set("short","A road headed up");
	set("long","Here the road you are following becomes a ramp which "+
	"spirals up to the next level of the city. This allows carts and "+
	"big items to make the climb to greater heights. After the sights "+
	"of this level, you can't wait to see what lies ahead. Many people "+
	"use this road to travel back and forth between levels, as they are "+
	"doing now. To the east is a intersection.");
	set_items( (["people":"Traveling about the city they are.","road":
	"It becomes a ramp.","ramp":"It spirals up to the next levels of "+
	"the city."]) );
	set_exits( (["east":"/wizards/excelsior/rooms/inter3",
		"up":"/wizards/excelsior/rooms/level2"]) );
}

