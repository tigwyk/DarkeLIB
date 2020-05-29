// /wizards/excelsior/rooms/sewer3.8

#include <std.h>

#define POSSIBLE_MONSTERS ({"/wizards/excelsior/mon/booga_boo","/wizards/excelsior/mon/manfrog","/wizards/excelsior/mon/moo_cow"})
inherit ROOM;

void reset() {
	int i,n,b;
	::reset();
	if (present("slug") || present("manfrog") || present("cow")) { return; }
	else {  
		i = sizeof( POSSIBLE_MONSTERS );
		n = i;
		i = i-random(2)
;
		while ( i > -1 ) {
			b = random(n);
			new( POSSIBLE_MONSTERS[b] )->move( this_object() );
			i--;
		}
	}
}

void create() {
	::create();
	set_property("light",-1);
	set_property("indoors",1);
	set("short","Deeper still in the sewers");
	set("long","You have forgotten whether it is day or night on the surface. "+
		"You have forgotten which way you came from. You are begining to feel "+
		"as though you will be trapped in these sewers forever.");
	set_items( (["sewer":"Scary."]) );
	set_exits( (["northwest":"/wizards/excelsior/rooms/sewer2.7",
		"north":"/wizards/excelsior/rooms/sewer2.9"]) );
	set_pre_exit_functions( ({"north"}), ({"go_north"}) );
	reset();
}

int go_north() {
	write("The tunnel turns to the right and then back to the left as you "+
		"follow it.");
	return 1;
}
