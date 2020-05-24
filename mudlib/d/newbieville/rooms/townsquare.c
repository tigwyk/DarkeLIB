#include "../newbieville.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "   0\n   | \n0--@--0\n   c \n   0\nTown Square.");
    set("long", "This is the town square of Newbieville. In every direction, roads branch out to the ends of town. In front of you is a large castle, presumably that of Lord Tailwind.\n   0\n   | \n0--@--0\n   c \n   0\n");
    add_exit(ROOMS+"castle", "castle");
    add_exit(ROOMS+"lightway", "east");
    add_exit(ROOMS+"shadowroad", "west");
    add_exit(ROOMS+"majestyave", "north");
    add_exit(ROOMS+"commonstreet", "south");
}
