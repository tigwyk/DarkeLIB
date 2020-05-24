#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbns1", "south");
    add_exit(ROOMS+"dbns3","north");
    add_exit("/d/damned/inn/main_room", "east");
//Basic mapping added by Tiny 1/19/2020
    set("short","   0\n   | \n   @--I\n   | \n   0\nDaybreak Valley Road");
    set("long","xDaybreak Valley Road is the main north-south artery in Daybreak Ridge.  The road is lined with hedge rows about four and a half feet tall which are cut to allow entry to the various homes and shops along the road.  Tall lamp posts are placed along the road to provide light during the night.  To the east the Blue Dragon inn sits, inviting you to enter and relax, further north you can see the fountain in the town square.\n   0\n   | \n   @--I\n   | \n   0\n");
}
