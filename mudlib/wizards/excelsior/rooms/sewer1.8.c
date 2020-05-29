// /wizards/excelsior/rooms/sewer1.8

#define MONSTERS ({"/wizards/excelsior/mon/booga_boo","/wizards/excelsior/mon/booga_boo","/wizards/excelsior/mon/manfrog","/wizards/excelsior/mon/manfrog"})

inherit "std/room";

void reset() {
	int size,ind,times;
	string *things;
	::reset();
	if (present("slug") || present("manfrog")) { return; }
	else {
		times = random(4) +1;
		while ( times > 0 ) {
			things = MONSTERS;
			size = sizeof(things);
			ind = random(size);
			new(things[ind])->move(this_object());
			times--;
		}
	}
}
		
void create() {
	::create();
	set_property("light",-2);
	set_property("indoors",1);
	set("short","Deep in the sewer system");
	set_long("You have found your way deep into the New Faerue Dust "+
	"sewer system. You really don't know what you are doing here, "+
	"but your subconcious mind seems to be going crazy trying to get "+
	"you to go just a bit deeper. You wonder why you listen to your "+
	"brain so much.");
	set_items( (["sewer":"They are incredibly intricate, unmaintained, "+
	"and complex. New Faerie Dust is defenitely ahead of its time."]) );
	set_exits( (["south":"/wizards/excelsior/rooms/sewer2.8",
		"southeast":"/wizards/excelsior/rooms/sewer2.9"]) );
}
