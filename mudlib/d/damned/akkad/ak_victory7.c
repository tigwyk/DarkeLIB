inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_victory8", "north");
    add_exit("/d/damned/akkad/ak_victory6", "south");
    set("short","   0\n   | \n   @   \n   | \n   0\nOn Victory Street south of Blessing Way");
    set("long","You are on Victory Street just south of the intersection "+
        "with Blessing Way, the street of clerics.\n   0\n   | \n   @   \n   | \n   0\n");

}
