inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_victory3", "south");
    add_exit("/d/damned/akkad/ak_center", "north");
    add_exit("/d/damned/akkad/ak_marksw", "west"); 
    add_exit("/d/damned/akkad/ak_markse", "east");
    set("short","   0\n   | \n0--@--0\n   | \n   0\nSouth side of Market Square");
    set("long",@ext You are on the South side of Market Square.
It is a place of great commerce and central to the city's 
economy.  At the center of it all stands a granite statue 
of Dranaxar, the first archmage.  It is an island of calm 
amidst the activity of the marketplace.
    T   
    |   
 0--@--0
    |
    0

ext);

}
