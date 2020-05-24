//      Wizard:  Khojem
//      Rusty Parrot
//      pub.c

#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void reset() {
  ::reset();
    if(!present("beltar")) 
      new("/d/khojem/port/shop/beltar")->move(this_object());
    if(!present("bertha")) 
      new("/d/khojem/port/shop/bertha")->move(this_object());
    if(!present("drunk")) 
      new("/d/khojem/port/shop/drunk")->move(this_object());
}

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
//Basic mapping added by Tiny 1/20/2020
    set("short", "   \n     \n   @   \n   | \n   0\nBeltar's Pub");
    set("long",
	"Beltar's Pub is a dirty hole-in-the-wall that is constructed above the "+
	"harbor's water along the dock.  The chairs and stools are in disrepair.  "+
	"The floor is filthy and never mopped.  The tables are filled with empty "+
	"bottles and ashes.  On the north wall a wood bar constructed of a plank "+
	"and a few barrels can be seen.  Above the bar is a crude sign listing "+
	"drink prices.\n   \n     \n   @   \n   | \n   0\n"
	);
    set_items(([
     ({ "pub", "alehouse", "bar" }) :
        "You seem to recall being in places like this far to many times.",
	 ({ "bar", "plank", "barrel", "barrels" }) : 
	    "The bar was hastily constructed from an available wooden plank "+
	    "and a few empty beer kegs.",
	    "sign" : "The drink prices are listed on crudely constructed sign "+
	      "and with poorly formed wording.  Try to read it.",
	 ({ "table", "tables", "chair", "chairs", "stool", "stools" }) :
	    "The pub has a few worn, wooden chairs and stools.  Some appear to "+
	    "to have recently escaped destruction in a recent brawl.  The tables "+
	    "are filled with empty bottles and cigar ash.",
	 ({ "harbor", "dock", "wharf", "floor", "water" }) :
	    "The harbor and dock are just to the south.  The floor is constructed "+
	    "of old wooden boards that allow the spilled beer to flow off between "+
	    "the cracks.  Through the cracks in the floor you can see water.  This "+
	    "pub was built on a set of pilings above the water."
	]));
    add_exit("/d/khojem/port/room/s24","south");
    set_smell("default", "You smell stale beer and cigar tobacco.");
}

  int read(string str) {
    object ob;
    int i;
    
    if(str != "sign") { return 0; }
    ob = present("beltar");
    if(!ob) {
      message("Ninfo", "Perhaps you could read the sign if all this blood wasn't covering it!",
        this_player());
      write("Perhaps you could read the sign if all this blood wasn't covering it!");
	  return 1;
    }
    if(((int)this_player()->query_stats("intelligence")) < 50) {
      message("Ninfo", "You quickly look at the sign and quickly realize "+
        "you have no idea what it says!",this_player());
      return 1;
    }
    if(((int)this_player()->query_stats("intelligence")) > 94) {
      message("Ninfo", "You can't figure out any of the words on this sign.  "+
        "Obviously, Beltar is a complete dullard and was never schooled in "+
        "writing skills!\n",this_player());
      return 1;
    }
    message("Ninfo", "With great effort you read each word of the sign slooowly...\n\n",
      this_player());
    message("Ninfo", "Don't bitch about the prices!  Take it or leave!\n",
      this_player());
    message("Ninfo",
      "-----------------------------------------------------------\n",
      this_player());
    write(sprintf("%30s %d silver", "A shot of grain alcohol  ",
      (int)ob->get_price("grain")));
    write(sprintf("%30s %d silver", "A glass of rum  ",
      (int)ob->get_price("rum")));
    write(sprintf("%30s %d silver", "A tankard of ale  ",
      (int)ob->get_price("ale")));
    write(sprintf("%30s %d silver", "A bottle of beer  ",
      (int)ob->get_price("beer")));
    write(sprintf("%30s %d silver", "A crab stew  ",
      (int)ob->get_price("stew")));
    write(sprintf("%30s %d silver", "A stick of beef jerkie  ",
      (int)ob->get_price("jerkie")));
    message("Ninfo",
      "-----------------------------------------------------------\n",
      this_player());
    message("Ninfo", "<buy drink_name> might get you a drink.\n",
      this_player());
    return 1;
}

