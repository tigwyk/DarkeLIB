inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    //add_exit("/d/damned/guilds/join_rooms/arch-mage_join", "south");
    add_exit("/d/damned/akkad/ak_res2", "north");
    //add_exit("/d/damned/guilds/join_rooms/enchanter_join", "east");
    set("short","   0\n   | \n   @   \n     \n    \nSouth end of Research Parkway");
    set("long","You are on the southern end of Research Parkway.  " +
	"The Enchanters Guild is here to the east and the Arch-Mages Guild "+
	"is south \n   0\n   | \n   @   \n     \n    \n");
    
}
