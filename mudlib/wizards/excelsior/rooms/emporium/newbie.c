// /wizards/excelsior/rooms/emporium/newbie

#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("light",3);
	set_property("night light",2);
	set_property("indoors",1);
	set("short","Entering the newbie zone");
	set("long","This is a portal room to a small newbie area just outside "+
		"the city limits in the forest. Because newbies need the help, only "+
		"players levels 1 and 2 may use this transporter and thus enter the "+
		"area.");
	set_items((["portal":"Type 'portal' to use it."]));
	set_exits((["west":"/wizards/excelsior/rooms/emporium/foyer",
		"portal":"/wizards/excelsior/newbie/rooms/fr1.2"]));
	add_pre_exit_function("portal","check_level");
}

int check_level() {
	if(this_player()->query_level() > 2) {
		write("The staff of the emporium informs you that you are too experienced "+
			"to use the transporter.");
		return 0;
	}
	write("You pass through the portal...");
	return 1;
}

void init() {
	::init();
	while(present("teddy bear")) {
	present("teddy bear")->move("/wizards/excelsior/newbie/rooms/fr2.3");
}
}
