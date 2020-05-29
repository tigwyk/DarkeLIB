// /wizards/excelsior/rooms/front_stage_center
// man the adventurer in my area is dumb

inherit "std/room";

void create() {
	::create();
	set_property("light",1);
	set_property("night light", 0 );
	set_property("indoors", 1);
	set("short","In front of stage center");
	set("day long","You have found your way directly in front of the "+
	"stage. Looking to your south, you see the vast amount of seats "+
	"the theatre has to offer. You don't think you've seen enough "+
	"people in this town so far to fill all these seats. Looking at "+
	"some of the seats closer you notice tears in the upholstery that "+
	"has been cleverly disguised with some stitches of the matching "+
	"color. You ponder the shrewdness of the maintanace crew. Maybe the "+
	"theatre is facing some hard times.");
	set("night long","You have reached the area directly before the "+
	"stage. Were this play a musical, you would be right in side the "+
	"pit orchestra right now. Wouldn't that be embarrassing! As you "+
	"stand around admiring your ability to avoid embarrassment some "+
	"angry guest pelts you with a tomato for standing in their way. "+
	"'Damnation!' you think, 'do people carry these things to theatre "+
	"productions?' Your question is answered by the tomatoes of several "+
	"other angry guests who wish you to be out of their way. Looks "+
	"like you managed to run smack into the face of embarrassment again.");
	set_listen( "default", (: call_other,this_object(), "listen_default":) );
	set_listen( "play", (: call_other, this_object(), "listen_play" :) );
	set_listen( "silence","It is very noisy in its silent sort of way.");
	set_items( (["guests":"When a production is playing you are "+
	"obstructing the view of those who wish to watch it."]) );
	set_exits( (["south":"/wizards/excelsior/rooms/seats",
	"west":"/wizards/excelsior/rooms/front_left_stage",
	"east":"/wizards/excelsior/rooms/front_right_stage"]) );
}

string listen_default() {
	if (query_night() == 1) return "You hear the sounds of a play.";
	else return  "You hear the noise of silence";
}


string listen_play() {
	if (query_night() == 1) return "Not being a theatre enthusiast, you "+
		"don't recognize the play from this distant. Maybe if you "+
		"got closer?";
	else return "There is no play right now.";
}
void init() {
	::init();
	call_out( "pelting_action" , random(10), this_player() );
}

pelting_action( object who ) {
	int stuff;
	if (query_night()) {
	if (present(who)) {
	stuff = random(5);
	if (stuff == 0) tell_object(who,"You are pelted by several tomatoes.");
if (stuff == 1) tell_object(who,"Some angry guest lobs a watermelon onto "+
	"your head.");
if (stuff == 2) tell_object(who,"You catch a couple eggs in your eye.");
if (stuff == 3) tell_object(who,"People are really pissed that you are "+
	"obstructing their view of the production.");
if (stuff == 4) tell_object(who,"A squaking chicken comes flying at your face.");
call_out( "pelting_action",random(20), who );
}
}
}

