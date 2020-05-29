// /wizards/excelsior/rooms/clownhome
// here we meet my clown

inherit "std/room";

void reset() {
	::reset();
if (!present("clown")) new("/wizards/excelsior/mon/clown")->move(
	this_object() );
}

void create() {
	::create();
	set_property("light",0);
	set_property("indoors",0);
	set("short","A dark alleyway");
	set("day long","This is a dark alley way in the city. It is not "+
		"the kind of place you'd want to be at night. And yet, "+
		"you have the strange feeling that it is your destiny "+
		"to be here. There is a bunch of trash lying around. "+
		"Despite all this, something seems to be emitting a large "+
		"amount of magic, and sinister magic at that.");
	set("night long","You walk into the dark alleyway and wonder "+
		"if it is safe to be here at night. However, a strange "+
		"feeling tells you that it is your destiny to be here. "+
		"Not one to stand in the way of destiny, you look around "+
		"and see lots of trash. Yuck. Despite all this, something "+
		"seems to be emitting a large "+
		"amount of magic, and a dark magic at that.");
	set_smell("default","There is a stench of trash in the air.");
	set_listen("default","You hear the sounds of rats going about "+
		"their rat business.");
	set_listen("rats","They sound large and scary.");
	set_smell("trash","You pick out the smell of a tuna sandwich "+
		"among it.");
	set_smell( "tuna","About 5 days old you'd say.");
	set_smell("sandwich","About 5 days old you'd say.");
	set_items( (["alley":"Dark and scary.","trash":"It doesn't smell "+
		"to good.","rats":"You can't see them, but you can hear "+
		"them."]) );
	set_exits( (["west":"/wizards/excelsior/rooms/inter1"]) );
	set_property("no attack",1);
}
