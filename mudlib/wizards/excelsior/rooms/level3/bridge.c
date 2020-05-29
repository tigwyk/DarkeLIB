// /wizards/excelsior/rooms/level3/bridge
// Excelsior 6-16

#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors",0);
	set_property("light",2);
	set("short","On a bridge");
	set("long","You are on a bridge. To your east is the large building at "+
		"the center of the town, the large building you were (or should have been) "+
		"wondering so much about. The bridge leads right into it! The joy! You "+
		"are so overcome with glee you barely notice the large merchant stand set "+
		"up here. Maybe you are not as observant as you like to think.");
	set_items(([({"merchant stand","vendor","vendor stand","stand"}):"A large sign "+
				"on top of the stand reads 'pies'. This "+
				"must be one of the famous New Faerie Dust pie vendors!",
		"building":"You can't wait to look inside.",
		"bridge":"It is under you. How did it get there?"]));
	set_exits((["west":"/wizards/excelsior/rooms/level3/road1",
		"east":"/wizards/excelsior/rooms/level3/building1"]));
}

void reset() {
	::reset();
	if(!present("pie man")) 
		new("/wizards/excelsior/mon/pie_man")->move(this_object());
}

string query_long(string str) {
	string add_on;
	if (str) return describe(str);
	if(!present("pie man")) {
		add_on = " Unfortunately, the pie man doesn't seem to be here right now.";}
	else {
		if(query_night()) {
			add_on = " Even at this time of night, the pie man stands at the counter waiting to help you."
;
		}
		else {
			add_on = " The pie man stands behind the counter, waiting for your business."; 
		}
	}
	return ::query_long() + add_on;
}
