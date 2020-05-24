inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_wgate", "west");
    add_exit("/d/damned/akkad/ak_haven2","east");
    add_exit("/d/damned/akkad/ak_tavern3","north");
    add_exit("/d/damned/akkad/ak_res3","south");
    set("short","   0\n   | \n0--@--0\n   | \n   0\nIntersection of Haven and Research Parkway");
    set("long","You are standing at the intersection of Haven Street and "+
	"the Research Parkway.  To the south are the various mage guilds "+
	"and to the north are the inns and taverns for the times when one "+
	"grows tired of research.\n   0\n   | \n0--@--0\n   | \n   0\n");
    
}
