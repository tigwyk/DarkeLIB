//      Wizard:  Khojem
//      Barfir's Pub and Alehouse
//      pub.c

#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void reset() {
  ::reset();
    if(!present("barfir")) 
      new("/d/khojem/new/shop/barfir")->move(this_object());
    if(!present("lackey"))
      new("/d/khojem/new/shop/lackey")->move(this_object());
    if(!present("vixen"))
      new("/d/khojem/new/shop/roxfir")->move(this_object());
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Barfir's Pub & Alehouse");
    set("long",
	"You enter Barfir's Pub & Alehouse, a merry place with many "+
	"satisfied customers.  The pub is a one room establishment "+
	"with a long, darkwood bar on the left and many tables and "+
	"chairs on the right.  It is a warm, cozy place with a fire "+
	"burning in a stone hearth on the far wall.  A sign is above "+
	"the bar listing drinks for sale."
	);
    set_items(([
     ({ "pub", "alehouse" }) :
        "You can have a rockin' good time here.",
	 ({ "bar", "darkwood bar" }) : 
	    "The wooden bar was made from a large elm tree.  It's "+
	    "trunk was skillfully cut down the center and the bark "+
	    "still remains on its underside as it curves under the "+
	    "countertop.  The bar's wood is highly polished and its "+
	    "edge is worn from countless patrons leaning against it.  "+
	    "At the bar's base is a long, round wooden footrail.",
	    "sign" : "It lists the drink prices.  Read it and see.",
	 ({ "table", "tables", "chair", "chairs" }) :
	    "The room is filled with many wooden chairs and tables.",
	 ({ "fire", "fireplace", "stone hearth", "hearth" }) :
	    "A fire burns a large log in a stone hearth."
	]));
    add_exit("/d/khojem/new/room/plat6","north");
    set_property("no castle", 1);
    set_property("no attack", 1);
    set_smell("default", "You smell stale beer and pipe tobacco.");
    set_listen("default", "You hear the din of a merry pub.");
//    new("/d/khojem/new/obj/slot_machine")->move(this_object());
}

  int read(string str) {
    object ob;
    int i;
    
    ob = present("barfir");
    if(!ob) {
      write("Barfir's blood smeared on the sign makes it unreadable.");
	  return 1;
    }
    message("Ninfo", "The following classic drinks are served at Barfir's!\n",
      this_player());
    message("Ninfo",
      "-----------------------------------------------------------\n",
      this_player());
    message("Ninfo", "A firebreather\t\t\t\t"+
      (int)ob->get_price("firebreather")+" silver\n", this_player());
    message("Ninfo", "A special of the house\t\t\t"+(int)ob
      ->get_price("special")+" silver\n", this_player());
    message("Ninfo", "An elven mead ale\t\t\t"+(int)ob
      ->get_price("ale")+" silver\n", this_player());
    message("Ninfo",
      "-----------------------------------------------------------\n",
      this_player());
    message("Ninfo", "<buy drink_name> gets you a drink.\n",
      this_player());
    return 1;
}

