// /wizards/excelsior/rooms/level3/building1
// Excelsior the formation of a riot
// 7-1-96

inherit "/std/room";

object *can_pass,*waiting;

void check_for_present();

void create() {
	::create();
	set_property("light",3);
	set_property("indoors",1);
	set("short","The entrance to the building");
	set("long","You are at the entrance to a very large building, in fact "+
		"the largest building in New Faerie Dust. This building stretches "+
		"hundreds and hundreds of feet into the air, a mammoth monument to "+
		"the building savvy of NFD. To commend this success of architecture, "+
		"there is a plaque set in the northern wall. There is a door leading "+
		"to another room north, and to the east your current room continues. It appears "+
		"there is a long line stretching in this direction, perhaps it would "+
		"be wise to take your place in it.");
	set_items((["plaque":
"%^ORANGE%^%^BOLD%^The New Faerie Dust Renaissance Tower%^RESET%^\n"+  
"        A monument to the stars\n"+
"%^BLUE%^  Rededicated %^RED%^Stoneday Vanthus 13, 37%^RESET%^\n"+
"  by our fair city's dedicated Mayor, \n"+
"\n"+ 
"%^CYAN%^%^BOLD%^             Beelz E. Bub\n"+ 
"\n"+            
"%^RESET%^In honor of this, a museum has also been\n"+
"        dedicated to the north",
		"line":"You should probably 'stand in line'.",
		"door":"It is actually a doorway, and to the north is another room.",
		"building":"It is definitely a building.",
		"entrance":"That is where you are."]));
	set_exits((["north":"/wizards/excelsior/rooms/level3/museum",
		"west":"/wizards/excelsior/rooms/level3/bridge",
		"east":"/wizards/excelsior/rooms/level3/building2"]));
	set_listen("default","You hear the dull sound of the entities in line.");
	add_pre_exit_function("east","go_east");
	can_pass = ({});
	waiting = ({});
}

int go_east() {
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
			"you to travel east",this_player());
		return 0;
	}
	message("info","Angry members of the line prevent you from going east. "+
		"'stand in line' they yell.",this_player());
	return 0;
}

void init() {
	::init();
	check_for_present();
	add_action("stand","stand");
}

void check_for_present() {
	int i;
	i = sizeof(can_pass);
	while(i--) {
		if(!present(can_pass[i])) can_pass -= ({ can_pass[i] });
	}
}

int stand(string str) {
	check_for_present();
	if(str != "in line") {
		write("You probably want to 'stand in line'.\n");
		return 1;
	}
	if(member_array(this_player(),waiting) >= 0 ||
		 member_array(this_player(),can_pass) > 0) {
		write("You are already standing in the line.");
		return 1;
	}
	if(member_array(this_player(),can_pass) == 0) {
		write("You are already standing in line and can proceed to the next room.");
		return 1;
	}
		write("You take your place in the line.");
	waiting += ({ this_player() });
	call_out("waiting",3,this_player(),1);
		return 1;
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
