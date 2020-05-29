// /wizards/excelsior/rooms/backstage_right.2
// another room. yes.

inherit "std/room";

void reset() {
	::reset();
	if (!present("mop")) {
		new("/wizards/excelsior/obj/mop")->move( this_object() );
}
}
void create() {
	::create();
	set("light",0);
	set("indoors",1);
	set("short","The quick change room");
	set("long","This is the back stage area set aside for actors and "+
		"actoresses to make those quick changes between seens. You "+
		"wonder where the cleaning staff could be. Hmm, maybe YOU "+
		"could apply for the position of janitor! Keeping that thought "+
		"in mind, you notice that there is unfortunately (or "+
		"fortunately) no one changing right now for you to watch.");
	set_items( (["clothing":"Where could the janitor be to clean up this "+
	"mess?"]) );
	set_exits( (["southeast":"/wizards/excelsior/rooms/backstage_right",
	"west":"/wizards/excelsior/rooms/backstage"]) );
	reset();
}
