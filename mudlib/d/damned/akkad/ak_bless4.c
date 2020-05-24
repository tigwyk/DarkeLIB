inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_slum1", "west");
    add_exit("/d/damned/akkad/ak_victory8","east");
//Basic mapping added by Tiny 1/20/2020
    set("short","   \n    \n0--@--0\n    \n   \nOn Blessing Way west of Victory");
    set("long","You are just east of the Slum Quarter where the lurkers live." +
	"  This is definitely not a good place of town to be.  Perhaps you were " +
	"looking for the clerics?  They are to the east.  To the west lies " +
	"nothing but squalor, desolation, and death.\n   \n    \n0--@--0\n    \n   \n");
    
}
