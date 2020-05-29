// /wizards/excelsior/rooms/theatre
// the entace to the theatre
// enjoy -Excelsior!>([]

inherit "std/room";

void create() {
	::create();
	set_property("light",2);
	set_property("night light",2);
	set_property("indoors",1);
	set("short","Inside the theatre");
	set("day long","At day it is rather dark in here as the company "+
	"can't afford to keep the lights on 24 hours a day- and being as "
	"people come here during the night, that is when they choose to turn "+
	"on the juice. You have heard stories of the giant generators of New "+
	"Faerie Dust, and how with magic and brute force they can produce a "+
	"massive amount of power. You suppose however that the officials "+
      " of the city choose to use most of this power on the richer "+
	"levels- because here most of the light you have seen has come "+
	"from torches and other less amazing sources.");
	set("night long","There are so many people here it is hard to move. "+
	"You really don't see how this place could be doing badly- business "+
	"is booming. The area is well lit and full of action. To the north "+
	"is the theatre itsself, to the west is a snack bar, and to the "+
	"east is a lounge of some kind. You wonder what is playing tonight.");
	set_items( (["theatre":"It is what Americans call a theater. "+
	"\"What's America?\" you think."]));
	set_exits( (["north":"/wizards/excelsior/rooms/seats","south":
		"/wizards/excelsior/rooms/theatre_ent","west":
		"/wizards/excelsior/rooms/snack_bar","east":
		"/wizards/excelsior/rooms/lounge" ]) );
	set_pre_exit_functions( ({"south"}) , ({"go_south"}) );
	set_post_exit_functions( ({"south"}),({"post_south"}) );
}

int go_south() {
	object where;
	if ( this_player()->query_property("hand stamped") == 0 ) {
	write("Before you leave you get your hand stamped so that you will "+
	"always be able to come back in- that is, until the next reset.");
	this_player()->set_property("hand stamped",1);
}
return 1;
}

