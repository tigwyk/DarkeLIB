// /wizards/excelsior/rooms/center_stage
// where it is happenin

inherit "std/room";

object actor,actor2;
int create_actor;

void reset() {
	object test_here;
	::reset();
	create_actor = 1;
	actor = new("wizards/excelsior/mon/actor");
	actor->move("/wizards/excelsior/rooms/place");
	test_here = present("actor");
	if (test_here) test_here->remove();
}

void actor_die() {
	create_actor = 0;
	if (present("actor")) {
}
}

void init() {
	object test_here;
	::init();
	test_here = present("actor");
	if (test_here) {
		if (!query_night()) {
			actor = test_here;
			actor->move("/wizards/excelsior/rooms/place");
		}

	}
	else
	{
		if (query_night()) {
			if (create_actor) {
				actor = new("/wizards/excelsior/mon/actor");
				actor->move( this_object() );
			}
		}
	}
}
void create() {
	::create();
	reset();
	set_property("light",3);
	set_property("indoors",1);
	set("short","Center stage");
	set("day long","This is center stage. If it were night everyone in "+
	"audience to your south would be looking at you. You do your little "+
	"comedy routine for the rats you know are out there. You are "+
	"being bombarded with light from all sides. It is very bright. You "+
	"wonder how the city could produce so much power in this day and age. The "+
	"stage floor looks a bit odd to you.");
	set("night long","You have pranced out onto center stage. Everyone "+
	"is looking at you. This reminds you of a dream you had once where you "+
	"got up in front of a ton of people and realized you were naked. "+
"Hopefully you aren't naked now, or people will think you are crazy. "+
	"With all the light shining on you, you barely notice that he stage "+
	"floor seems a bit odd. You can't comprehend where the city gets this light, all you "+ 
	"have ever known are those good 'ol fashioned torches.");
	set_items( (["lights":"They a very bright.","floor":"Hmm. It is a "+
	"bit bumpy at some places. Perhaps you should search it.","door":
	"Try going 'down' through the trap door."]) );
	set_exits( (["west":"/wizards/excelsior/rooms/backstage_left",
		"down":"/wizards/excelsior/rooms/backstage_under",
		"east":"/wizards/excelsior/rooms/backstage_right"]) );
	set_invis_exits( ({"down"}) );
	set_search("floor","You search the floor and discover a trap door!");
}
