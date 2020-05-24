inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_out2", "north");
    add_exit("/d/damned/akkad/ak_victory8","south");
    set("short","   0\n   | \n   @   \n   | \n   0\nInside the northern gate of Akkad");
    set("long","You are standing just inside the northern gate, at the end "+
	"of Northern Street which cuts through the middle of Akkad, running "+
        "north-south.  There is an intersection to the south\n   0\n   | \n   @   \n   | \n   0\n");

}
