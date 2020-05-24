inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 1);
    add_exit("/d/damned/guilds/join_rooms/necromancer_join", "north");
    add_exit("/d/damned/akkad/ak_out2", "south");
    set("short","   0\n   | \n   @   \n   | \n   0\nGraveyard outside of Akkad");
    set("long","This is the city graveyard.  Not much is here besides a " +
	"few tumbled down tombstones.  There is a large mausolem-like "+
        "building to the north.  It looks like the Necromancers Guild, since "+
        "necromancers are the only ones would live in a place like this.\n   0\n   | \n   @   \n   | \n   0\n ");
}
