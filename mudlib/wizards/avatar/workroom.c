//      from the Nightmare mudlib
//      an example workroom for new immortals

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set_property("light", 6);
    set_property("indoors",1);
    set_property("indoors", 0);
    set("short", "The workroom of a aspiring immortal");
    set("long", "This is a test\n");
    set("night long", "It is night outside.\nA aspiring immortal works here.\n");
    set("day long", "It is day outside.\nA aspiring immortal works here.\n");
    set_exits( 
      ({
	"/d/standard/square", "/d/standard/adv_main","/d/standard/adv_inner"
      }),
      ({
	"square", "hall", "boards"
      })
    );
    set_items(([ "collective" : "This is a collective" ]));
}
