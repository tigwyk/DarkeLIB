// /wizards/excelsior/crits/dimensional_room
// a room of death
// Excelsior 4-11-96

inherit "std/room";

void create() {
	::create();
	set_property("light",4);
	set_property("indoors",1);;
	set("short","A reality nexus");
	set("long","The area around you is like nothing you have ever seen before. "+
		"The space and matter itself seems to be in a constant state of motion, "+
		"moving and ever changing. Could it be you have found your way into some "+
		"sort or reality nexus? You catch glimpses of the fourth dimension, feel "+
		"thoughts of foriegn beings shooting through your head, and are basically "+
		"only able to comprehend a small part of this strange place. As you come to "+
		"realize this, you also come to realize you don't like it very much here. "+
		"To bad you don't see a single way out.");
	set_items((["space":"It is very pretty, actually.",
		"matter":"It is not really matter as you know it.",
		"nexus":"That is the best word you can think of for this place."]));
}

void init() {
	::init();
	call_out("go",300);
}

void go() {
	object *what;
	int n,x,y;
	what = all_inventory(this_object());
	message("info","%^CYAN%^%^BOLD%^The reality around you begins to swirl "+
		"and you are suddenly "+
		"elsewhere.",this_object());
	n = sizeof(what);
	while(n--) {
		x = random(38) + 1;
		y = random(38) + 1;
		what[n]->move("/d/damned/virtual/room_"+x+"_"+y+".world");
	}
}

