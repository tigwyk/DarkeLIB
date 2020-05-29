// /wizards/excelsior/rooms/sewer2.8

inherit "std/room";
	
string *msg,*direction;

void create() {
	::create();
	set_property("light",-2);
	set_property("indoors",1);
	set("short","A massive intersection");
	set("long","Here the sewer tunnels that could easily be called "+
		"a maze widen up into an intersection of amazing proportions. "+
		"There are several ways to go from here, but you can't help "+
		"thinking that this place looks familiar- like you've been here "+
		"before.");
	set_items( (["tunnels":"Pick a direction."]) );
	set_smell( "default","You smell the sewer smell.");
	set_exits( (["east":"/wizards/excelsior/rooms/sewer2.8",
		"west":"/wizards/excelsior/rooms/sewer2.8",
		"north":"/wizards/excelsior/rooms/sewer1.8",
		"southeast":"/wizards/excelsior/rooms/sewer3.9"]) );
	set_pre_exit_functions( ({"west","east"}),({"go_west","go_east"}) );
	msg = ({"You follow a tunnel through much muck and yuck but it "+
		"seems to just lead back to where you came from."});
}

void the_message(string str) {
	write(str);
	return;
}

int go_west() {
	
	write("You follow the tunnel through much muck and yuck but it "+
		"seems to just lead back to where you came from.");
	return 1;
}

int go_east() {
	write("You follow a tunnel through much muck and yuck but it "+
		"seems to just lead back to where you came from.");
	return 1;
}
