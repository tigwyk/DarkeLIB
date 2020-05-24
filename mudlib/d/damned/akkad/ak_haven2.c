inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_haven1", "west");
    add_exit("/d/damned/akkad/ak_haven3", "east");
    set("short","   \n    \n0--@--0\n    \n   \nOn Haven Street west of Market Square");
    set("long","Haven Street runs east-west through the center of town. "+
	"Market Square lies to the east where anything can be found for "+
	"a price.  To the west is an intersection.\n   \n    \n0--@--0\n    \n   \n");

}
