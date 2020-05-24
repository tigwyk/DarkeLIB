inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_out4", "south");
    add_exit("/d/damned/akkad/ak_victory2","north");
    add_exit("/d/damned/akkad/ak_guard2", "east");
    add_exit("/d/damned/akkad/ak_guard1", "west");
    set("short","   0\n   | \n0--@--0\n   | \n   0\nInside the southern gate of Akkad");
    set("long","You are standing just inside the southern gate, at the end "+
	"of Victory Street which cuts through the middle of Akkad, running "+
        "north-south. This is where the City Guards are quartered.  Guards " +
	"are training in practice areas east and west of you.\n   0\n   | \n0--@--0\n   | \n   0\n");
	

}
