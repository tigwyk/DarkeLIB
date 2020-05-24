inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_bless3", "west");
    add_exit("/d/damned/akkad/ak_bless1","east");
    //add_exit("/d/standard/square", "south");
//Basic mapping added by Tiny 1/20/2020
    set("short","   \n    \n0--@--0\n     \n    \nOn Blessing Way");
    set("long","You are on the Blessing Way, the street of the clerics." +
         "  The entrance to the church is here to the south. "+
	"The clerics guild is to the east.\n   \n    \n0--@--0\n     \n    \n ");
    
}
