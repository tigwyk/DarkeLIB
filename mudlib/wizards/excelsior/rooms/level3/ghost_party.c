// /wizards/excelsior/rooms/level3/ghost_party
// whee
// Excelsior 6-26-96
// lot o' sixes ^^^^

#include <std.h>

inherit ROOM;

int chest_opened,can_open;

void reset() {
	::reset();
	if(!present("galran")) 
		new("/wizards/excelsior/mon/galran")->move(this_object());
	if(!present("poltergeist")) 
		new("/wizards/excelsior/mon/poltergeist")->move(this_object());
	if(!present("poltergeist 2")) 
		new("/wizards/excelsior/mon/poltergeist")->move(this_object());
	if(!present("drunk")) 
		new("/wizards/excelsior/mon/drunk_ghost")->move(this_object());
	if(!present("skeleton"))
		new("/wizards/excelsior/mon/skeleton")->move(this_object());
	chest_opened = 0;
	can_open = 0;
}

void create() {
	::create();
	set_property("indoors",1);
	set_property("light",3);
	set("short","A haunted party");
	set("long","You now realize what the source of the voices was. "+
		"The room  contains dozens of ghosts, spiritual "+
		"apparitions, ghouls and other undead creatures. The ones that "+
		"are solid in form are wearing various tattered clothing, and most "+
		"bear the symbol of a triangle circumscribed by a circle. At first "+
		"you feel fear, but you soon realize they are not paying the slightest "+
		"attention to you and are much more interested in having a good time. "+
		"The room is well lit but you see no light source. At the far end "+
		"of the room is a throne. There is a small chest next to it.");
	set_items(([({"ghosts","spiritual apparitions","ghouls","undead creatures"}):
			"They are intent on having a good party and aren't paying attention "+
			"to you at all.",
		({"triangle","circle","symbol"}):"You seem to recognize it from somewhere, "+
			"but from where?",
		"clothing":"Dead don't care much about their clothes",
		"light source":"There is none to speak of.",
		"throne":"It looks very neat. You wonder who sits on it.",
		"chest":(: call_other, this_object(), "look_at_chest":)]));
	set_exits((["east":"/wizards/excelsior/rooms/level3/hall2"]));
	set_listen("default","The room is filled with party music, 
		but you can find no source.");
}

void set_open() { can_open = 1; }

string look_at_chest(string str) {
	if(!can_open) {
		write("The chest seems to be sealed shut by a powerful force. There must "+
			"be some way to open it!");
		return "The chest seems to be sealed shut by a powerful force. There must "+
			"be some way to open it!";
	}
	if(!chest_opened) {
		write("Now that Galran has unsealed it for you, you can 'open' the 'chest'.");
		return "Now that Galran has unsealed it for you, you can 'open' the 'chest'.";
	}
	write("You look in the chest, but is empty!");
	if(present("galran")) 
		present("galran")->apology();
	return "You look in the chest, but is empty!";
}

void init() {
	::init();
	add_action("chest","open");
}

int chest(string str) {
	if(str != "chest") 	{
		notify_fail("What do you wish to open?\n");
		return 0;
	}
	if(!can_open) {
		write("%^GREEN%^You try to open the chest, but it is hopelessly sealed shut "+
			"by some unworldly force!");
		if(present("galran")) 
			present("galran")->question();
		return 1;
	}
	write("%^GREEN%^You open the chest! 'look at chest' to see its wonderful contents!");
	chest_opened = 1;
	return 1;
}
