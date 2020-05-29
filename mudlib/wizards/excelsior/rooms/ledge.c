// /wizards/excelsior/rooms/ledge
 
 
 inherit "std/room";
 
 void create() {
 	::create();
 	set_property("indoors",0);
 	set_property("light",1);
 	set("short","On the roof the the theatre");
 	set("long","You have found your way onto the roof of the New Faerie Dust "+
 		"theatre company. From up here you can see the suberban sprawl of "+
 		"the city to your north. To your south is downtown, which rises "+
 		"up hundreds of feet above you. The roof is actually quite small, "+
 		"because to your south another building is built right on top "+
 		"of the theatre. There is a small open window on the side of this "+
 		"building.");
 	set_items( (["suberban sprawl":"Somewhere that you can't get to.",
 		"buildings":"Man are they tall!",
 		"roof":"It is more of a ledge actually.",
 		"window":"Through it is the place to be." ]) );
 	set_exits( (["down":"/wizards/excelsior/rooms/pipe",
 		"window":"/wizards/excelsior/rooms/jail/behind_desk" ]) );
 }
