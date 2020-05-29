// /wizards/excelsior/rooms/backstage_left

inherit "std/room";

int dropped;
object bag;

void reset() {
	::reset();
	dropped = 0;
}

void create() {
	::create();
	reset();
	set_property("light",-1);
 set_property("indoors",1);
	set("short","Backstage by the curtain controls");
	bag = new("/wizards/excelsior/obj/curtain_obj");
	set("long","This is the backstage area on the left side of "+
		"the stage. This is where all the ropes and pulleys are that "+
		"control the curtains of the stage, which is located to the "+
		"east. There are many tools, a ladder, costumes, and props "+
		"lying around. What an interesting place!");
	set_items( (["stage":"To the east my child.","tools":
		"You notice a mop, a hammer, a wrench set and a rubber chicken "+
		"at first glance.","chicken":"Used to cheer up the repair man "+
		"when he is glum- a necessary thing, because so many repairs "+
		"need to be made.","ladder":"It leads up onto the catwalks "+
		"above the stage. Lets see, to get up a ladder you usually "+
		"climb it. Bogglement.","props":"Hahaha! Look! A wooden "+
		"fire hydrant! You want to sniff it.",({"ropes","pulleys"}):
		"One of the ropes looks very interesting indeed. There is a "+
		"sign by it.","sign":"Try reading it.","rope":"It is so "+
		"sophisticated you could never figure it out by yourself. "+
		"Maybe there are directions somewhere...",({"release",
		"mechanism","release mechanism"}):"A sophisticated device "+
		"that controls the movements of the rope. Wonder how it "+
		"works..."]) );
	set_exits( (["southeast":"/wizards/excelsior/rooms/front_left_stage",
		"northeast":"/wizards/excelsior/rooms/backstage_left.2",
		"east":"/wizards/excelsior/rooms/center_stage"]) );
	set_smell("hydrant","It's just not like the real thing.");
}

void init() {
	::init();
	add_action("sniff","sniff");
	add_action("climb","climb");
	add_action("release","release");
	add_action("read","read");
	add_action("pull","pull");
}

int sniff(string str) {
	if (str == "hydrant") {
		write("It's just not like the real thing.");
		return 1;
		}
	else {
	notify_fail("You sniff your armpits in front of the wooden fire "+
		"hydrant.");
		return 0;
}}

int climb(string str) {
	if (str == "ladder") {
		write("You climb up the ladder onto the catwalks above.");
		this_player()->move_player("/wizards/excelsior/rooms/catwalks");
		return 1;
	}
	else {
	notify_fail("Climb what?\n");
	return 0;
}}

int read(string str) {
	if (str == "sign") {
		write("_____________________________________________________\n"+
"|                                                    |\n"+
"|         Happy rope                                 |\n"+
"|                                                    |\n"+
"|     Instructions for working rope:                 |\n"+
"|      This rope controls some of the workings       |\n"+
"|       of the stage. You can 'pull rope'            |\n"+
"|       then 'release rope'. NEVER 'release rope'    |\n"+
"|       twice in a row. This is a piece of high-tech |\n"+
"|       equipment and must be treated with respect.  |\n"+
"|____________________________________________________|");
return 1;
} else {
notify_fail("Read what?");
return 0;
}}

int pull(string str) {
	if (str == "rope") {
		if (dropped == 0) {
			write("You pull the rope as far as allowed. Hmm, I "+
			"wonder what it did?");
			bag->move("/wizards/excelsior/rooms/center_stage");			dropped = 1;
			bag->set_state("curtain");
		}
		if (dropped == 1) {
			write("The release mechanism will not allow you to pull "+
			"the rope any farther.");
			return 1;
		}
		if (dropped == 2) {
			write("You pull the rope very hard and hook it back into "+
			"the release mechanism.");
			bag->remove();
			bag = new("/wizards/excelsior/obj/curtain_obj");
			dropped = 0;
			return 1;
		}
	}
	notify_fail("What do you wish to pull on?");
	return 0;
}

int release(string str) {
	if (str == "rope") {
		if (dropped == 0) {
			write("You release the rope, and it starts moving very "+
			"quickly. You hear a loud crashing noise to your east, "+
			"and you notice that the rope has been unhooked from "+	
			"the release mechanism.");
			bag->move("/wizards/excelsior/rooms/center_stage");
			bag->set_state("bag");
			dropped = 2;
			return 1;
		}
		if (dropped == 1) {
			write("You release the rope and glides smoothly to a new "+
			"positions and then locks into place.");
			bag->remove();
			bag = new("/wizards/excelsior/obj/curtain_obj");
			dropped = 0;
			return 1;
		}
		if (dropped == 2) {
			write("The rope will not release anymore.");
			return 1;
		}
	}
	notify_fail("Release what?");
	return 0;
}
