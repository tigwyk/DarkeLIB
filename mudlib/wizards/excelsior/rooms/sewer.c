// /wizards/excelsior/rooms/sewer

inherit "std/room";

void create() {
	::create();
	set_property("light",0);
	set_property("indoors",1);
	set("short","Entering the sewers");
	set("long","You have found your way into an entrance to the "+
	"New Faerie Dust Sewer System. The area around you is a small "+
	"workroom area where municipal employees can set up before "+
	"traveling into the maze of tunnels that are the sewers. There is "+
	"a sign hanging on the east wall, and a ladder leads up from here "+
	"into the heart of the sewer system. You notice a newspaper lying "+
	"on the ground. Covering the walls are many pipes that carry water "+
	"to and from the sites of the city.");
	set_items( (["sign":"It says: Municipal employees only. Don't "+
	"forget a light source!","ladder":"It leads up into the sewers "+
	"themselves.","newspaper":"A story on the front page catches your "+
	"eye: 'Several Municipal workers reported missing in old and "+
"complex sewer system.'","pipes":"This city is very advanced for its "+
	"time.","tunnels":"They look very complex."]));
	set_exits( (["west":"/wizards/excelsior/rooms/sewer_ent",
	"up":"/wizards/excelsior/rooms/sewer4.9"]) );
}
