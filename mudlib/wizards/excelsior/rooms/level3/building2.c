// /wizards/excelsior/rooms/level3/building2
// Excelsior the formation of a riot
// 7-1-96

inherit "/std/room";

object *can_pass,*waiting;

void check_for_present();

void create() {
	::create();
	set_property("light",3);
	set_property("indoors",1);
	set("short","The crowd is getting restless");
	set("long","You continue to stand in line waiting to proceed to the "+
		"next room. Wondering what you are in line for, you ask someone "+
		"nearby who replies it is the line to see a government representative. "+
		"You wonder why anyone would want to do that. As the crowd stands in "+
		"line it becomes more and more restless. It has become apparent that "+
		"there is some kind of a comotion to the north. However, you'll just "+
		"have to wait for the line to progress enough to see for yourself.");
	set_items((["line":"You are standing in it, and you have been for quite a while",
		"someone":"You asked this person what you were in line for.",
		"crowd":"The people standing in line etc.",
		"comotion":"What could all the fuss be about?"])
)
;
	set_exits((["north":"/wizards/excelsior/rooms/level3/building3",
		"west":"/wizards/excelsior/rooms/level3/building1"]));
	set_listen("default","You hear the sound of a comotion to the north.");
	add_pre_exit_function("north","go_north");
	can_pass = ({});
	waiting = ({});
}

int go_north() {
	check_for_present();
	if(member_array(this_player(),can_pass) > 0) {
		message("info","You have to wait for "+(string)can_pass->query_cap_name()+
			"to go before you can.",this_player());
		return 0;
	}
	if(member_array(this_player(),can_pass) == 0) {
		message("info","You proceed to the next room.",this_player());
		can_pass -= ({ this_player() });
		return 1;
	}
	if(member_array(this_player(),waiting) >= 0) {
		message("info","You are still waiting for the line to move enough for "+
			"you to travel north",this_player());
		return 0;
	}
	message("info","Angry members of the line prevent you from going east. "+
		"'wait your turn' they yell.",this_player());
	return 0;
}

void init() {
	::init();
	check_for_present();
	if(member_array(this_player(),waiting) >= 0 ||
		 member_array(this_player(),can_pass) > 0) {
		write("You are already standing in the line.");
		return;
	}
	if(member_array(this_player(),can_pass) == 0) {
		write("You are already standing in line and can proceed to the next room.");
		return;
	}
	waiting += ({ this_player() });
	call_out("waiting",3,this_player(),1);
}

void check_for_present() {
	int i;
	i = sizeof(can_pass);
	while(i--) {
		if(!present(can_pass[i])) can_pass -= ({ can_pass[i] });
	}
}

void waiting(object who,int times) {
	check_for_present();
	if(!present(who)) {
		waiting -= ({ who });
		return;
	}
	if(times < 5) {
		message("info","%^MAGENTA%^You wait in line",who);
		times++;
		call_out("waiting",3,who,times);
		return;
	}
	message("info","The line has progressed enough to allow passage to the "+
		"next room.",who);
	waiting -= ({ who });
	can_pass += ({ who });
	check_for_present();
	return;
}
