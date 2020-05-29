// /wizards/excelsior/rooms/gnome_farms/farm4

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if(!present("greater gnome")) 
		new("/wizards/excelsior/mon/greater_gnome")->move(this_object());
}


void create() {
	::create();
	set_property("light",2);
	set_property("indoors",0);
	set("short","The heart of the farms");
	set("long","You walk into this room and are immediately blasted by one "+
		"of the most intense magical fields you have ever experienced in your "+
		"life. The sheer power of this place is demonstrated when a young fun "+
		"loving gnome prisoner decides to telepathically force you to clog dance. "+
		"your performance ends abruptly when a guard realizes what is happens "+
		"and kicks the gnome in the face with his large military boot. You have "+
		"the feeling you get when you enter a clearing in the forest. The rest "+
		"of this sinfull place was a narrow hallway, but here it opens up to "+
		"better harness the power of the magical creatures. To the northwest is "+
		"a small tent.");
	set_items((["sky":"Yes, you can see it.",
		"gnome":"He has been knocked unconcious and may die without medical "+
			"attention, which he does not recieve.",
		"guard":"His boot is almost as big as most gnomes here.",
		"tent":"Check it out, maybe in it lies answers to some of your questions.",
		"clearing":"Though it is more open, it is still overcrowded and "+
			"depressing. Oh how you long for the blissfulness of ignorance again."
		]));
	set_exits((["east":"/wizards/excelsior/rooms/gnome_farms/farm3",
		"northwest":"/wizards/excelsior/rooms/gnome_farms/tent"]));
	set_smell("default","You smell the magic in the air.");
	set_listen("default","You hear many gnomes talking and surviving the "+
		"best they can.");
	reset();
}
