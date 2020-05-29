// /wizards/excelsior/rooms/seats
// inside the theatre

inherit "std/room";

void create() {
	::create();
	set_property("light",1);
	set_property("night light" , 0);
	set_property("indoors",1);
	set("short","In the theatre");
	set("day long","This is the area of the theatre where the guests "+
	"sit. On either side of the isle you are walking on are hundreds "+
	"of seats. On the ground is all kinds of trash left over from last "+
	"night's show. You think you even see some rats scurrying around. "+
	"'It would take a lot of people to fill this theatre' you think.");
	set("night long","As you stand here in the area of the theatre "+
	"the guests sit you realize that though it is very crowded, there "+
	"isn't nearly enough people to fill this theatre. Perhaps you "+
	"you thought that it was crowded because of your county upbringing-"+
	" but I won't get into that. To your north you see the stage and a "+
	"fine actor orating his part.");
	set_items( (["actor":"You can't quite tell what the play is. Perhaps "+
	"if you got closer maybe?",({"guests","people"}):"They are watching "+
	"the play.","rats":"Gross. 'I hate rats' you think.","seats":
	"There are quite a lot of them.","trash":"Candy wrappers, soda "+
	"cups etc."]) );
	set_exits( (["south":"/wizards/excelsior/rooms/theatre",
		"north":"/wizards/excelsior/rooms/front_stage_center"]) );
	set_listen("default",(: call_other, this_object(), "default_listen" :));
	set_listen("play",(: call_other, this_object(), "hear_play" :) );
}

string default_listen(string str) {
	if ( query_night() ) return "You hear the sounds of a play.";
	else return "";
}

string hear_play(string str) {
	if (query_night()) return "You can't tell what play it is from "+
		"here. But maybe if you got closer...";
	else return "";
}
