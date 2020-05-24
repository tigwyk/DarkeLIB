inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_haven7", "west");
    add_exit("/d/damned/akkad/ak_out3", "east");
    add_exit("/d/damned/akkad/ak_sd3", "south");
    add_exit("/d/damned/akkad/ak_sd4", "north");
//Basic mapping added by Tiny 1/20/2020
    set("short","   0\n   | \n0--@--0\n   | \n   0\nInside the eastern gate of Akkad");
    set("long","You are standing just inside the eastern gate, at the end "+
	"of Haven Street which cuts through the middle of Akkad, running "+
	"east-west.  Iron Trail runs north-south here.  You hear "+
	"the sounds of fighters training to the south and the clink of " +
	"metal being forged to the north.\n   0\n   | \n0--@--0\n   | \n   0\n");

}
