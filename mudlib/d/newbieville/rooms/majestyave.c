#include "../newbieville.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "   0\n   | \n0--@--0\n   | \n   0\nMajesty Avenue");
    set("long", "You are walking along Majesty Avenue, which goes north from the town square. To your west is a bar, which is reputed to be one of the finest in the land. East is an armor shop, and north are gates to the town.\n   0\n   | \n0--@--0\n   | \n   0\n");
    add_exit(ROOMS+"bar", "west");
    add_exit(ROOMS+"armorshop", "east");
    add_exit(ROOMS+"townsquare", "south");
    add_exit(ROOMS+"ngates", "north");
}
