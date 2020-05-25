#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbns3", "south");
    add_exit(ROOMS+"dbns4","north");
    add_exit(ROOMS+"dbew5", "east");
    add_exit(ROOMS+"dbew6","west");
    //add_exit(ROOMS+"N1","portal");
    //add_exit(ROOMS+"N2","room");
//Basic mapping added by Tiny 1/19/2020 
    set("short","   0\n   | \n0--@--0\n   | \n   0\nDaybreak Square");
    set("long", "Daybreak Square is situated at the intersection of Daybreak Valley Road and Main Street.  A large fountain with a statue of Duke Traer of Daybreak Ridge spouts out water.  The Square has similar hedge rows to the rest of town, but you notice that there are no doors or windows on any of the walls that line the square. Main Street Begins here and runs east and west towards more residential areas of Daybreak Ridge while Daybreak Valley Road runs north and south and heads towards the outskirts of town.\n   0\n   | \n0--@--0\n   | \n   0\n");
}

void reset(){
object h_rune;
  ::reset();
    if(!present("fountain")){
    new(OBJ+"fountain.c")->move(this_object());
    }
    //HONSPRON 2020 - added a healing rune
    if (!present("rune")) {
	h_rune = new ("/std/diewarzau/obj/misc/h_rune");
		h_rune->move(this_object());
	}
}
