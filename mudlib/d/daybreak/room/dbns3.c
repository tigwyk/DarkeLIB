#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbns2", "south");
    add_exit(ROOMS+"db_square","north");
//Basic mapping added by Tiny 1/19/2020
    set("short","   T\n   | \n   @   \n   | \n   0\nDaybreak Valley Road");
    set("long","Daybreak Valley Road is the main north-south artery in Daybreak Ridge.  The road is lined with hedge rows about four and a half feet tall which are cut to allow entry to the various homes and shops along the road.  Tall lamp posts are placed along the road to provide light during the night.  As you get closer and closer to the center of town, you encounter more people going about their business.\n   T\n   | \n   @   \n   | \n   0\n");
}
