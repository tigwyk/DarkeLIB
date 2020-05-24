#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void create(){
	::create();
	set_property("indoors", 1);
	set_property("light", 2);
	set_property("no castle", 1);
	set("short", "   \n    \n   @--0\n    \n   \nCity Guard Post");
	set("long",
		"Chairs are scattered about this messy room.  An old wooden "
		"table sits in the center of the room.  Old food, cups, mugs, "
		"and plates sit molding upon its top.  A few make shift beds "
		"have been erected on the far wall to allow some to sleep.  "
		"Upon your entrance filthy looking wenches glance over at you.\n   \n    \n   @--0\n    \n   \n"
	);
	set_items( ([
		"chairs": "Old and barely standing, they are about to fall "
			"apart",
		"table": "Initials have been carved all over its surface.",
		"initials": "nEv!n was here.",
		({"food", "cups", "mugs"}): "Mold of various colours have "
			"begun to grow upon them.",
		"beds": "Old dirty rags and blankets, mingle with unwashed "
			"bodies.",
		"wenches": "The smile at you through missing teeth.  Those "
			"teeth that still remain and blackish and disgusting."
	]) );
	set_exits( ([
		"east": "fountain_square3"
	]) );
	set_door("door", ROOMS+"fountain_square3", "east", 0);
	set_open("door", 1);
	set_locked("door", 0);
}

void reset() {
	::reset();
	if(!present("watchman")) {
		new(MON+"wm_fighter")->move(TO);
		new(MON+"wm_fighter")->move(TO);
	}
}
