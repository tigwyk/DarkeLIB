inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_slum3", "north");
    add_exit("/d/damned/akkad/ak_slum2", "south");
    add_exit("/d/damned/akkad/ak_bless4", "east");
    set("short","   0\n   | \n   @--0\n   | \n   0\nInside the Slums");
    set("long","You have entered the Slum Quarter of Akkad.  What a dump!"
      "You see a giant rat the size of a small dog scurry across your "
      "path.  You see some disreputable looking characters hanging around.\n   0\n   | \n   @--0\n   | \n   0\n");
}
