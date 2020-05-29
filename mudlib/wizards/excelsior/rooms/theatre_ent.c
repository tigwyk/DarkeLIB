// /wizards/excelsior/rooms/theatre_ent
// a guard won't let you in without a ticket!

inherit "std/room";

object *who_stamped;

void reset() {
::reset();

who_stamped = ({});
if (!present("guard")) new("/wizards/excelsior/mon/guard")->move(this_object());
}

void create() {
	::create();
	set_property("light",1);
	set_property("night light",1);
	set_property("indoors",0);
	set("short","Theatre entrance");
	set("day long","This is the entrance to the New Faerie Dust "+
	"Theatre Company- one of the few places in the lower levels "+
	"of the city that the rich attend. Lately, however, business "+
	"has been down and the company is in trouble. They have already "+
	"had to lay off several workers. During the day trash blows "+
	"this way and that around the area. It is rather deserted here, "+
	"except for a few squatters feebishly trying to set up camp. "+
	"You know however that they will be removed as soon as night falls. "+ 		"There 
is a ticket booth here.");
	set("night long","You have arrived at the entrance to the New "+
	"Faerie Dust Theatre Company. There is a long line of well off "+
	"people waiting to get in to see tonights show. It sure doesn't "+
	"seem like the theatre is doing bad to you. In fact, as you stand "+
	"here gawking several people get quite mad at you for cutting in "+
	"line. 'Wow,' you think, 'this must be the place to be!' There "+
	"is a ticket booth here.");
	set_pre_exit_functions( ({"north"}) , ({"go_north"}) );
	set_items( (["trash":"It seems to have a mind of its own, always "+
		"seeming to find a new and unique way to blow.","squatters":
		"There are just a few of them.","line":"People are waiting "+
		"to get in and see the show.","booth":"Maybe if you had a "+
		"ticket, you could get in too." ]) );
	set_exits( (["west":"/wizards/excelsior/rooms/inter3",
		"north":"/wizards/excelsior/rooms/theatre"]) );
	set_pre_exit_functions( ({"north"}),({"go_north"}) );
}

int query_stamped(object ob) {
	if ( member_array(ob,who_stamped) != -1 ) return 1;
	else return 0;
}
int go_north() {
	object ob;
	if (!query_stamped( this_player() )) this_player()->set_property(
		"hand stamped",0);
	if ( query_stamped(this_player()) == 1 ) {
		write("You show the guard your stamped hand and he lets you in.");
		return 1;
	}
	if ( present("guard") ) {
		if ( present("ticket",this_player() ) ) {
			write("You hand over your ticket to the guard and "+
				"head into the theatre.");
			this_object()->hand_stamped( this_player() );
			ob = find_object("ticket");
			present( "ticket",this_player())->remove();
			return 1;
		}
		write("The guard will not let you proceed without a theatre "+ 				"ticket.");
		return 0;
	}
	return 1;
}


int hand_stamped(object ob ) {
	if (!interactive(ob)) {
		write("BUG. Contact Excelsior.");
		return 0;
		}
	if ( member_array(ob,who_stamped) != -1 ) {
		return 0;
		}
	who_stamped += ({ob});
	return 1;
}

