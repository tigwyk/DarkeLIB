// /wizards/excelsior/rooms/jail/cell2.1

#include <std.h>

inherit VAULT;

void reset() {
	object thief,sp;
	if(present("thief")) 
		present("thief")->remove();
	thief = new("/wizards/excelsior/mon/thief");
	thief->remove_call_out("reset");
	sp = new("/std/weapon");
	sp->set_name("spork");
	sp->set("id",({"spork"}));
	sp->set("short","sharpened spork");
	sp->set("long","This spork has been sharpened to make it a weapon of "+
		"sorts.");
	sp->set_weight(4);
	
	sp->set_value(1);
	sp->set_ac(0);
	sp->set_wc(2,"cutting");
	sp->set_type("knife");
	sp->set_quality(0);
	sp->move(thief);
	thief->force_me("wield spork in right hand");
	thief->set_money("gold",0);
	thief->move( this_object());
	set_open("cell 1",0);
	set_locked("cell 1",1);
	"/wizards/excelsior/rooms/jail/prison2"->set_open("cell 1",0);	
	"/wizards/excelsior/rooms/jail/prison2"->set_locked("cell 1",1);
	call_out("clean_house",3);
}

void create() {
	::create();
	set_property("light",2);
	set_property("night light",0);
	set_property("indoors",1);
	set_property("no castle",1);
	set("short","In a prison cell");
	set("long","You are in a tiny prison cell and you get the feeling that prisoners "+
		"in this jail are not treated very well. The living conditions here are very "+
		"cramped. There is a small toilet on one wall.");
	set_items((["toilet":"It is out in the open for guards to see.",
		({"cell door","door","cell"}):"It is made out of bars that guards can "+
			"see right through."]));
	set_exits((["south":"/wizards/excelsior/rooms/jail/prison2"]));
	set_door("cell 1","/wizards/excelsior/rooms/jail/prison2",
		"south","jail keys");
	set_lock_level("cell 1",25);
	reset();
}	
		
void clean_house() {
	object thief;
	thief = present("thief");
	if(thief) {
		if(present("dagger",thief))
		present("dagger",thief)->remove();
	if(present("ring",thief))
		present("ring",thief)->remove();
	}
	if(present("ring"))
		present("ring")->remove();
	if(present("dagger"))
		present("dagger")->remove();
	if(present("spork"))
		present("spork")->remove();
}

