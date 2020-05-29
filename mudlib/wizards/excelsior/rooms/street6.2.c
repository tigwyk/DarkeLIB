// /wizards/excelsior/rooms/street6.2

#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("light",2);
	set_property("night light",1);
	set("short","Following the second level road");
	set("long","You continue to follow the second level road. It curves here "+
		"a bit. To your east it looks as though the road curves back. 'Not "+
		"a very effecient road path' you think. But then, city planning is "+
		"non-existient in New Faerie Dust, so what do you expect? There seems "+
		"to be something going on to your east.");
	set_items( (["road":"It curves here.",
		"curve":"It points the road in a more eastward direction."]) );
	set_exits( (["north":"/wizards/excelsior/rooms/street6.1",
		"east":"/wizards/excelsior/rooms/street6.3" ]) );
}
