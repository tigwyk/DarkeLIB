#include "../newbieville.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "   0\n   | \n0--@--0\n    \n   \nShadow Road");
    set("long", "This is Shadow Road. To your east is town square, to the west there are some gates, and to your north is bar. And, of course, the famous general store is south.\n   0\n   | \n0--@--0\n    \n   \n");
    add_exit(ROOMS+"bar", "north");
//    add_exit(ROOMS+"generalstore", "south");
    add_exit(ROOMS+"townsquare", "east");
    add_exit(ROOMS+"wgates", "west");
}
