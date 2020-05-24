#include "../newbieville.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "   0\n   | \n0--@--0\n   | \n   0\nLight Way.");
    set("long", "You are now on Light Way. To your north is an armor shop, and to the south is a weapons shop. You also see the town gates to the east, and town square to the west.\n   0\n   | \n0--@--0\n   | \n   0\n");
    add_exit(ROOMS+"armorshop", "north");
    add_exit(ROOMS+"weaponshop", "south");
    add_exit(ROOMS+"townsquare", "west");
    add_exit(ROOMS+"egates", "east");
}
