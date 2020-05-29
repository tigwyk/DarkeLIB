// /wizards/excelsior/rooms/level3/road2
// Excelsior 6-16
// I am on a roll here
// if someone copies my poem idea I will kill them

inherit "/std/room";

void create() {
	::create();
	set_property("light",3);
	set_property("indoors",0);
	set_property("night light",2);
	set("short","The market continues");
	set("long","As you stand and watch the mass, the people come,\n"+
				"	the people pass, \n"+
				"the beggars beg, the drunkards fall, \n"+
				"	the people pass on down the mall.\n"+
				"No one seems to have a care,\n"+
				"	 for the others here and there, \n"+
				"they ignore them or scorn them, hit them or kick them, \n"+
				"but no one seems to think anything could help them.\n"+
				"Then to your horror a man draws his sword, \n"+
				"	and strikes down a beggar as though he his lord.\n"+
				"He kicks the dead body and spits on it too,\n"+ 
				"	and people pass by- this is nothing new. \n"+
				"No one cares for the lesser folk, by God no one would!\n"+ 
				"	They keep walking by, never thinking they should.");
	set_items((["man":"You can't seem to believe his little sin, and the "+
			"worse thing about it? He's going to win.",
		"beggars":"They are here, they are there. Very dirty be their hair.",
		"mall":"It is the NFD open air market. There is no red carpet.",
		"window":"You are well on your way if you know there is a window here. "+
			"Go south.",
		"poem":"Isn't it annoying? I hope you are enjoying."]));
	set_exits((["southeast":"/wizards/excelsior/rooms/level3/road1",
		"north":"/wizards/excelsior/rooms/level3/road3",
		"south":"/wizards/excelsior/rooms/level3/bard_home"]));
	add_invis_exit("south");
	add_pre_exit_function("south","go_south");
}
	
int go_south() {
	write("You climb through an open window to your south. Whee!");
	return 1;
}		
