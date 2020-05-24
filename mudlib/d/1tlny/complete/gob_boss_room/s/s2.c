//      Wizard:  Khojem
//      Main Gallery
//      gallery.c

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	
if (!present("goblin")) {
	  new("/d/1tlny/complete/gob_boss_room/s/m2.c")->move(this_object());
	}

}

void create() {
    ::create();
    set_property("light", -1);
    set_property("indoors", 1);
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set("short", "   \n   \n   @   \n   | \n   0\nSpecial Secret Room2");
    set("long", "Special Secret Room2\n   \n   \n   @   \n   | \n   0\n");
    add_exit("/d/1tlny/complete/gob_boss_room/s/s1.c","south");    

}
