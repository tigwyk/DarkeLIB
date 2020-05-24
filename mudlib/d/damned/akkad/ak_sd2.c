inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_sd1", "south");
    add_exit("/d/damned/akkad/ak_sd3", "north");
    set("short","   0\n   | \n   @   \n   | \n   0\nMidst of Iron Trail");
    set("long","You are in the midst of Iron Trail.  This is definitely the " +
	"place to go to learn how to fight.  You see fighters entering a "+
	"building to your north and cavaliers entering a building to your " +
        "south.  Further south, you see the Paladins Guild.\n   0\n   | \n   @   \n   | \n   0\n\n"
	"");
    
}
