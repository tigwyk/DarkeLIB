// /wizards/excelsior/rooms/emporium/foyer

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if(!present("news board"))
		new("/wizards/excelsior/obj/emporium/news_board")->move(this_object());
	if(!present("arrow sign"))
		new("/wizards/excelsior/obj/emporium/dir_sign")->move(this_object());
}

void create() {
	::create();
	set_property("light",3);
	set_property("indoors",1);
	set("short","In the Excelsior Emporium");
	set("long","This is the major entertainment center in new faeriedust. "+
		"Here is a place where citizens and guests of the city come to get "+
		"information, socialize, gamble and play games. This is the place "+
		"to be.");
	set_exits((["south":"/wizards/excelsior/rooms/square",
		"west":"/wizards/excelsior/rooms/emporium/library",
		"east":"/wizards/excelsior/rooms/emporium/newbie",
		"north":"/wizards/excelsior/rooms/emporium/board",
		"northwest":"/wizards/excelsior/rooms/emporium/casino",
		"northeast":"/wizards/excelsior/workroom"]));
	add_pre_exit_function("northwest","sorry");
	add_pre_exit_function("northeast","check_wiz");
	reset();
}

int sorry() {
	write("A security guard informs you that the casino is still under construction.");
	return 0;
}

int check_wiz() {
	if(wizardp(this_player())) return 1;
	write("A security guard blocks you informing you that only wizards may go this "+
		"way.");
	return 0;
}
