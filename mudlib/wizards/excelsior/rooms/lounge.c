// /wizards/excelsior/rooms/lounge

inherit "std/room";

int key_there;

void reset() {
	::reset();
	key_there = 1;
}

void create() {
	::create();
	reset();
	set_property("light",2);
	set_property("indoors",1);
	set("short","In the theatre lounge");
	set("day long","This area of the theatre is where people sit and "+
	"contemplate the meaning of the nights performance or the taste "+
	"of the liquor being served. The theatre is currently closed, so "+
	"there is no one here at the moment. Peering around you see "+
	"several chairs that look like they have seen better days. "+
	"Interesting.");
	set("night long","This area is crammed full of people having a "+
	"time and drinking expensive wine. You fear what it would be like "+
	"if the theatre were actually full. With all the people here, "+
	"you barely notice several chairs that look a little bit "+
	"worn out. Gee.");
	set_search("fibers",(: call_other,this_object(),"search_fibers":) );
	set_items( (["people":"Yes, there are people here, but only at "+
	"night.","chairs":"One chair in paticular catches your attention.",
	"chair":"It seems to have a large rip in its upholstry.","rip":
	"Hmm. Could something be hidden in the cotton fibers falling out?",
	"fibers":"It looks like someone has hidden something in the fibers."
		]) );
	set_exits( (["west":"/wizards/excelsior/rooms/theatre"]) );
}

mixed search_fibers() {
	if ( key_there == 1) {
		new("/wizards/excelsior/obj/star_key")->move( this_player() );
		write("You search the fibers and find a key! Who the heck "+
	"would hide a key here?");
		key_there = 0;
		tell_room( this_object(),this_player()->query_cap_name()+
		" finds a key!", ({this_player()}) );
		return "You search the fibers and find a key! Who the heck "+
		"would hide a key here?";
}
	else {
	write("Hmm, guess you were wrong. Big surprise.");
	return 1;
	}
	key_there = 0;
}
