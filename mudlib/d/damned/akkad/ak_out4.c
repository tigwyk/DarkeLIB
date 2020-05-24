inherit "std/room";


void create() {
   ::create();
     set_property("light",3);
     set_property("night light", 2);
     add_exit("/d/damned/akkad/ak_sgate", "north");
     add_exit("/d/damned/virtual/room_4_9.world","plains");
     set("short","   0\n   | \n   @   \n     \n   plains\nOutside the southern gate of Akkad");
     set("long","You are standing just outside the southern gate of Akkad."+
	 "The town looks very inviting to the weary traveler.  You hear " +
	 "faint laughter coming from the cozy taverns inside the town." +
	 "As you look away from the town, you see the plains stretch " +
	 "endlessly before you.\n   0\n   | \n   @   \n     \n   plains\n");

}
void init() {
  ::init();
  if((string)this_player()->query_true_name() == "guest") {
    add_action("block_exit", "plains");
  }
}

int block_exit(string str) {
  write("Guests are not allowed to exit the city.");
  return 1;
}
