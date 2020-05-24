inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_out1", "west");
    add_exit("/d/damned/akkad/ak_haven1","east");
    set("short","   \n    \n0--@--0\n    \n   \nInside the western gate of Akkad");
    set("long","You are standing just inside the western gate, at the end "+
	"of Haven Street which cuts through the middle of Akkad, running "+
        "east-west.  There is an intersection to the east.\n   \n    \n0--@--0\n    \n   \n");

}
