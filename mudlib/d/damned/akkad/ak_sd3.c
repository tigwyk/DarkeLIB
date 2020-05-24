inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_sd2", "south");
    add_exit("/d/damned/akkad/ak_egate", "north");
    //add_exit("/d/damned/guilds/join_rooms/fighter_join", "west");
    set("short","   0\n   | \n   @   \n   | \n   0\nIron Trail south of the East Gate");
    set("long","This is the Iron Trail where the fighting guilds reside.  " +
	"It seems like everyone is armed around here.  The entrance to the "+
	"Fighter's Guild is to the west.  Further south are the Cavaliers " +
	"and Paladins.\n   0\n   | \n   @   \n   | \n   0\n");
    
}
