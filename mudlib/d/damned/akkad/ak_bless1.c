inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    //add_exit("/d/damned/guilds/cleric/confess", "east");
    add_exit("/d/damned/akkad/ak_bless2","west");
//Basic mapping added by Tiny 1/20/2020
    set("short","   \n    \n0--@   \n    \n   \nOn Blessing Way east of the cleric's guild");
    set("long","You are at the end of the Blessing Way, the street of the " +
	"clerics.  The clerics guild is to the east.  The rest of the city "+
	"stretches to the west of you.\n   \n    \n0--@   \n    \n   \n");
    
}
