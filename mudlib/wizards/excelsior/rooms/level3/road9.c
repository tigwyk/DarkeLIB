// /wizards/excelsior/rooms/level/road9
// Excelsior 7-3-96

inherit "/std/room";

void reset() {
	object ob;
	::reset();
	if(!present("guard")) {
		ob = new("/wizards/excelsior/mon/ogre_guard");
		ob->set("long","This a work boss. He hires people for the day mostly "+
			"on the basis of who bribed him how much. He is very big and "+
			"looks rather mean as well.");
		ob->set("short","The work boss");
		ob->set("aggressive",0);
		ob->set("id",({"ogre","work boss","boss"}));
		ob->move(this_object());
	}
}

void create() {
	::create();
	set_property("light",3);
	set_property("indoors",0);
	set("short","The entrance to a factory");
	set("night long","Directly to your north is the entrance to a factory. "+
		"You have no idea what they make there. This is the spot where "+
		"people line up daily, hoping to get a job. The factory hires on a "+
		"daily basis, providing no job security or benefits. There would "+
		"be crowds here right now fighting gfor a job, but it is night.");
	set("day long","The crowds here fighting for a job are unbearable. "+
		"The work bosses stand here calling out names and selecting people "+
		"for the daily work detail. Most of the time to get a job you have "+
		"to bribe the work boss or be on the good side with the corporation. "+
		"There are no unions. Unions are illegal.");
	set_items((["crowds":"They all want work.",
		"work bosses":"Generally big and ugly.",
		"factory":"It is to your north.",
		"people":"They are wanting a job for the day."]));
	set_exits((["north":"/wizards/excelsior/rooms/level3/factory1",
		"west":"/wizards/excelsior/rooms/level3/road8"]));
		add_pre_exit_function("north","go_north");
	reset();
}

int go_north() {
	write("You are informed that no one is allowed in the factory without permission.");
return 0;
}
