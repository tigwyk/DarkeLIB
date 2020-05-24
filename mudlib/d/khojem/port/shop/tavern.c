//      Wizard:  Khojem
//      Sailor's Pleasure, One-Eyed Sparkey's
//      tavern.c

#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void reset() {
  ::reset();
    if(!present("sparkey")) 
      new("/d/khojem/port/shop/sparkey")->move(this_object());
    if(!present("merchant"))
      new("/d/khojem/port/shop/merchant")->move(this_object());
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
//Basic mapping added by Tiny 1/20/2020
    set("short", "   \n    \n   @--0\n    \n   \nSparkey's Sailor's Pleasure");
    set("long",
	"This is One-eyed Sparkey's Sailor's Pleasure Tavern.  It is world renown "+
	"for its fine drinks and food.  Sparkey keeps a fine establishment.  His "+
	"service is prompt, his table always clean, and his patrons always happy.  "+
	"The service bar is made from finely crafted teak.   The tables and chairs "+
	"made of oak and neatly arranged for your seating pleasure.  Many seafarers "+
	"and local residents can be seen dining here.  A sign above the bar lists "+
	"the menu.\n   \n    \n   @--0\n    \n   \n"
	);
    set_items(([
     ({ "pub", "alehouse", "bar", "tavern", "sparkey's" }) :
        "Its a nice place to pass the time.",
     ({ "seafarers", "patrons", "residents" }) :
        "They certainly seem to be enjoying the good food and drink.",
	 ({ "bar", "teak" }) : 
	    "The bar is made of highly polished teak and small doilies sit under "+
	    "each glass.",
	    "sign" : "A sign lists the prices.",
	 ({ "table", "tables", "chair", "chairs", "stool", "stools" }) :
	    "Many oak tables and chairs are available for your enjoyment.",
	 ({ "harbor", "dock", "wharf" }) :
	    "The harbor and dock are just to the east."
	]));
    add_exit("/d/khojem/port/room/s11","east");
    set_smell("default", "You smell the salt air from the harbor towards the east.");
}

  int read(string str) {
    object ob;
    int i;
    
    if((str != "sign") && (str != "menu")) { return 0; }
    ob = present("sparkey");
    if(!ob) {
      message("Ninfo", "Perhaps you could read the sign if all this blood wasn't covering it!",
        this_player());
	  return 1;
    }
    message("Ninfo", "For your dining enjoyment... One-eyed Sparkey's presents...\n",
      this_player());
    message("Ninfo",
      "-----------------------------------------------------------\n",
      this_player());
    write(sprintf("%30s %d silver", "A shot of whiskey  ",
      (int)ob->get_price("whiskey")));
    write(sprintf("%30s %d silver", "A glass of port  ",
      (int)ob->get_price("port")));
    write(sprintf("%30s %d silver", "A bottle of beer  ",
      (int)ob->get_price("beer")));
    write(sprintf("%30s %d silver", "A rack of lamb  ",
      (int)ob->get_price("lamb")));
    write(sprintf("%30s %d silver", "A filet of salmon  ",
      (int)ob->get_price("salmon")));
    write(sprintf("%30s %d silver", "A dinner roll  ",
      (int)ob->get_price("roll")));
    write("-----------------------------------------------------------");
    write("<buy item> gets you the food or drink.");
    return 1;
}

