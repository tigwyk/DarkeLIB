inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_victory4", "north");
    add_exit("/d/damned/akkad/ak_victory2", "south");
    set("short","   0\n   | \n   @   \n   | \n   0\nOutskirts of Market Square");
    set("long","You are on the southern outskirts of Market Square. "+
        "Before you lie the many shops of Akkad, where "+
	"almost anything can be bought or sold.\n   0\n   | \n   @   \n   | \n   0\n");

}
