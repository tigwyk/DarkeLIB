// /wizards/excelsior/rooms/gnome_farms/tent

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if(!present("gnome king"))
		new("/wizards/excelsior/mon/gnome_king")->move(this_object());
	if(!present("greater gnome"))
		new("/wizards/excelsior/mon/greater_gnome")->move(this_object());
}

void create() {
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set("short","In the gnome king's tent");
	set("long","You are in the tent of the gnome king. You are astounded to see "+
		"that the person who runs this cursed place is himself a gnome. There are "+
		"desks here piled high with information on the gnomes so that selections "+
		"of who to breed and who to kill can be made. There is a lantern which "+
		"provides the room with light and a throne on which the gnome king sits.");
	set_items((["desks":"They are piled high with data sheets.",
		"papers":"They give info on every gnome in these farms.",
		"lantern":"Not for you to take.",
		"throne":"It is solid gold, but secured to the ground."]));
	set_exits((["southeast":"/wizards/excelsior/rooms/gnome_farms/farm4"]));
}
