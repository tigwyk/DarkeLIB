inherit "std/room";


/*
void reset() {
object mon;
::reset();
if(!present("sentinal"))
new("/wizards/zephlen/mon/sentinal")->move(this_object());
}
void init() {
  ::init();
  if((string)this_player()->query_true_name() == "guest") {
    add_action("block_exit", "plains");
  }
}
*/
int block_exit(string str) {
  write("Guests are not allowed to exit the city.");
  return 1;
}
void create() {
   ::create();
     set_property("light",3);
     set_property("night light", 2);
     add_exit("/d/damned/akkad/ak_ngate", "south");
     add_exit("/d/damned/virtual/room_4_9.world","plains");
    //add_exit("/d/damned/guilds/necromancer/front_gate", "north");
     set("short","   plains\n     \n   @   \n   | \n   0\nOutside the northern gate of Akkad");
     set("long","You are standing just outside the northern gate of Akkad."+
	 "The town looks very inviting to the weary traveler.  You hear " +
	 "faint laughter coming from the cozy taverns inside the town." +
         "  As you look away from the town, you see the plains stretch "+
         "endlessly before you.  The city graveyard is north of here.\n   plains\n     \n   @   \n   | \n   0\n");

}
