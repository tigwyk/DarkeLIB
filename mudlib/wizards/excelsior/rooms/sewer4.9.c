// /wizards/excelsior/rooms/sewer4.9
// entering the sewers

inherit "std/room";

void reset() {
	::reset();
	if (!present("hard hat") ) {
	new("/wizards/excelsior/armor/hard_hat")->move(this_object());
	}
}

void create() {
	::create();
	set_property("light",-1);
	set_property("indoors",1);
	set("short","A three way intersection in the sewers");
	set("long","You have come to a three way intersection in the sewers. "+
	"Here the path goes down, north and south. You see a bit of light "+
	"streaming in from below, so you assume there is an exit that way. "+
	"It appears to the south the tunnel turns up a bit. To the north "+
	"you see nothing but darkness. You feel that it may be your destiny "+
	"venture into that darkness, and you wish it didn't have to be so "+
	"scary. On the ground here are the skeletal remains of some "+
	"unfortunate worker. It looks like something very violent happened "+
	"to him. It looks like these sewers are not very well maintained. "+
	"Hmmm. I wonder if these remains have anything to do with that.");
	set_items( (["remains":"The bones of a recently dead worker. It "+
	"as though something burnt the flesh right off of him/her.",
	"bones":"How blunt do I have to be? THERE ARE MONSTERS IN THESE "+
	"TUNNELS.","tunnel":"Three branch off from here." ]) );
	set_exits( (["north":"/wizards/excelsior/rooms/sewer3.9",
		"south":"/wizards/excelsior/rooms/sewer5.9",
		"down":"/wizards/excelsior/rooms/sewer" ]) );
	add_pre_exit_function("south","sorry");
}

int sorry() {
	write("Unfortunately, that part of the city hasn't been built yet.");
return 0;
}
