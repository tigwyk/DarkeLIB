inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_tavern2", "south");
    //add_exit("/d/damned/inn/main_room", "east");
    add_exit("/d/damned/akkad/clan_shop", "west");
    set("short","   \n    \n0--@   \n   | \n   0\nAt the north end of Tavern Street");
    set("long","You are at the north end of Tavern Street. There are taverns" +
	" and inns all around you.  You can hear the sounds of raucous laughter "+
	"and see a few drunken patrons stumbling home after a long day and night" +
        " of drinking.\nThere is an inn to the east.\n   \n    \n0--@   \n   | \n   0\n"
        "\n%^YELLOW%^%^BOLD%^The Clan Registry is to the west.");
    
}
