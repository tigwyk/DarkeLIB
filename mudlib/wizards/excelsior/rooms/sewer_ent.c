// /wizards/excelsior/rooms/sewer_ent
// getting down to business- Excelsior

inherit "std/room";

void create() {
	::create();
	set_property("light",1);
	set_property("indoors",0);
	set("short","A dead end");
	set("long","The road you were following comes to a rather abrupt "+
	"stop. Homeless have set up quite a camp here, but you "+
	"choose to ignore them and look around. You can't believe "+
	"that the road would just end. The east wall looks peculiar.");
	set_items( (["wall":"You can't believe that the road would just end "+
	"here. Perhaps you could 'search' the wall?","homeless":"They are "+
	"minding their own business- shoudn't you too?",
	"walls":"The east walls collects your attention...",
	"east wall":"Type 'look at wall'",
	"camp":"A squatter camp is here."]) );
	set_exits( (["west":"/wizards/excelsior/rooms/inter2",
		"east":"/wizards/excelsior/rooms/sewer"]) );
	set_search("wall","You find a opening in the wall that will allow "+
		"your passage east! Woo!");
	add_invis_exit("east");
}
