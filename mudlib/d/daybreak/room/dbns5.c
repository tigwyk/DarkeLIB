#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbns6", "north");
    add_exit(ROOMS+"dbns4","south");
//Basic mapping added by Tiny 1/19/2020 
    set("short","   0\n   | \n   @   \n   | \n   0\nDaybreak Valley Road");
    set("long", "Daybreak Valley Road is the main north-south artery in Daybreak Ridge.  The road is lined with hedge rows about four and a half feet tall which are cut to allow entry to the various homes and shops along the road.  Tall lamp posts are placed along the road to provide light during the night. This is a more residential area of Daybreak Ridge, homes line both sides of the street, children play in the streets here and a few people are sitting on their porches watching the street.\n   0\n   | \n   @   \n   | \n   0\n");
}
