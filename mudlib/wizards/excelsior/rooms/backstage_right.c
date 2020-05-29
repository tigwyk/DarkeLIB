// /wizards/excelsior/rooms/backstage_right

inherit "std/room";

void create() {
 	::create();
 	set_property("light",-1);
 	set_property("indoors",1);
 	set("short","Backstage right");
 	set("day long","This is the backstage area on the right side of the "+
 		"stage. This is where the stage director stands and does his stage "+
		"directing things. "+
		 "Because it is day time and the plays are performed at night, no one "+
		 "is here right now.");
	 set("night long","This is the backstage area on the right side of "+
		"the stage. This is where the stage director stands and does his "+
		"stage directing things. The theatre actually hires "+
		"a sorcerer of some sort to come here and control "+
		"the lights and sounds of the theatre. This is also done "+
		"here. "+
		 " Strangely enough, there is no one here doing "+
		 "anything productive now, even though a play is being performed on "+
		 "stage to your west at this very moment.");
	 set_items( ([ ({"controls","board"}):"They are not for you to play "+
		 "with. You snap your fingers in disapointment.","stage":"West."]) );
	 set_exits( (["northwest":"/wizards/excelsior/rooms/backstage_right.2",
		 "west":"/wizards/excelsior/rooms/center_stage",
		 "southwest":"/wizards/excelsior/rooms/front_right_stage"]) );
}
