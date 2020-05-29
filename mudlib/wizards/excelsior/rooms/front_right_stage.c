// /wizards/excelsior/rooms/front_right_stage
// I am getting my dose of boring simple do nothing rooms

inherit "std/room";

void create() {
	::create();
	set_property("light",-1);
	set_property("indoors",1);
	set("short","To the right of the stage");
	set("day long","You are walking in front of the seats to the right of the "+
		"stage. If it were night time and people were trying to watch a play they "+
		"may be getting quite mad at you. There is a passageway to your northeast that "+
		"leads to the back stage area.");
	set("night long","You are walking in front of many angry people who want to "+
		"watch the play. You are preventing this. It is not as bad, however, "+
		"as the anger of the people to your west. To the northeast is a passageway "+
		"that appears to lead to the back stage area.");
	set_items( (["people":"You make a better door then a window.",
		"stage":"To your northwest a bit",
		"passageway":"To your northeast. Check it out." ]) );
	set_exits( (["northeast":"/wizards/excelsior/rooms/backstage_right",
		"west":"/wizards/excelsior/rooms/front_stage_center" ]) );
	set_listen( "default", (: call_other, this_object(), "listen_default" :) );
	set_listen( "play", (: call_other, this_object(),"listen_play":) );
}

string listen_default() {
	if (query_night()) {
		return "You hear the sounds of a play going on.";
	}
	else 
	{
		return "You can practically hear the theatre falling apart";
	}
}

string listen_play() {
	if (query_night()) {
		return "You are too stupid to recognize what play it is.";
	}
	else
	{
		return "You are too stupid to realize that there is no play going on right now";
	}
}
