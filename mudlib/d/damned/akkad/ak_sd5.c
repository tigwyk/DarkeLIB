inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_sd4", "south");
    //add_exit("/d/damned/guilds/join_rooms/chaotic-lord_join", "north");
    set("short","    \n     \n   @   \n   | \n   0\nNorth end of Iron Trail");
    set("long","You are at the north end of Iron Trail.  You can see tinkers "+
	"entering a building to the south of you.  The entrance to the "+
	"Chaotic Lords Guild is here to the north.\n    \n     \n   @   \n   | \n   0\n");
    
}
