//      Wizard:  Khojem
//      Shakey Jakie's Still
//      still.c

#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void reset() {
  ::reset();
    if(!present("jakie")) 
      new("/d/khojem/new/shop/jakie")->move(this_object());
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Shakey Jakie's Distillery");
    set("long",
	"You enter Shakey Jakie's Distillery, a dreary dump of a place. "+
	"Jakie has built this still out in the woods to compete illegally "+
	"with Barfir's Pub in Fir'nvillee.  The dirt floor of the hut has "+
	"a few chairs and tables.  The hut is damp and cold.  The fireplace "+
    "on the far wall doesn't have a fire going to warm the room.  A sign is on "+
	"the wall listing prices."
	);
    set_items(([
     ({ "pub", "hut" }) :
        "Looks like you can get pretty drunk here.",
	    "sign" : "It lists the drink prices.  Read it and see.",
	 ({ "table", "tables", "chair", "chairs" }) :
	    "The room is filled with many wooden chairs and tables.",
	 ({ "fire", "fireplace", "stone hearth", "hearth" }) :
	    "A cold, unlit fireplace.  Looks like it hasn't been used in years.  "+
	    "The bricks are cracked and missing in a few spots."
	]));
    add_exit("/d/khojem/new/room/annex5","west");
    set_property("no castle", 1);
    set_property("no attack", 1);
    set_smell("default", "You smell stale beer and cigar smoke fills the room.");
    set_listen("default", "You hear a still in the backroom running.");
}

  int read(string str) {
    object ob;
    int i;
    
    ob = present("jakie");
    if(!ob) {
      write("Shakey Jakie's blood smeared on the sign makes it unreadable.");
	  return 1;
    }
    message("Ninfo", "The following goods are served at Shakey Jakie's!\n",
      this_player());
    message("Ninfo",
      "-----------------------------------------------------------\n",
      this_player());
    message("Ninfo", "Moonshine\t\t\t\t"+
      (int)ob->get_price("moonshine")+" silver\n", this_player());
    message("Ninfo", "Pale elven ale\t\t\t\t"+(int)ob
      ->get_price("ale")+" silver\n", this_player());
    message("Ninfo", "Brown bread\t\t\t\t"+(int)ob
      ->get_price("bread")+" silver\n", this_player());
    message("Ninfo",
      "-----------------------------------------------------------\n",
      this_player());
    message("Ninfo", "<buy drink_name> gets you what you want.\n",
      this_player());
    return 1;
}
