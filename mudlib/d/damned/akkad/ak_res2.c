inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_res1", "south");
    //add_exit("/d/damned/guilds/join_rooms/sword-mage_join", "east");
    add_exit("/d/damned/akkad/ak_res3", "north");
    add_exit("/d/damned/akkad/ak_lib", "west");
    set("short","   0\n   | \n0--@   \n   | \n   0\nResearch Parkway");
    set("long","You are on Research Parkway east of the entrance to the " +
	"city library, where arcane lore can be found.  To the south, "+
	"you see enchanters entering a building and directly south you see "+
	"the entrance to the Arch-Mages Guild.  East, across from the library "+
	"is the Sword-Mage Guild.\n   0\n   | \n0--@   \n   | \n   0\n\n");
    
}
