inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_sd5", "north");
    add_exit("/d/damned/akkad/ak_egate", "south");
    //add_exit("/wizards/thrace/shop/ingot_shop", "east");
    //add_exit("/d/damned/guilds/join_rooms/tinker_join", "west");
    set("short","   0\n   | \n   @   \n   | \n   0\nIron Trail north of the East Gate");
    set("long","This is the Iron Trail where the fighting guilds reside.  " +
	"The entrance to the Tinkers Guild to the west.  The eastern gate " +
	"of the city is south of you.  The Chaotic Lords reside at the north " +
	"end of the street.\n   0\n   | \n   @   \n   | \n   0\n");

    
}
