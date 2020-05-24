#include "../newbieville.h"
#include <std.h>

//      Wizard:  Khojem
//      Barfir's Pub and Alehouse
//      pub.c
//      Altered by Tailwind for Newbieville.


inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void reset() {
  ::reset();
    if(!present("dhamon")) 
      new(MON+"barkeep")->move(this_object());
}

void create() {
    ::create();
    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "   \n     \n   @--0\n   | \n   0\nA Bar");
    set("long",
        "This is the world-renowned bar of Newbieville. There are "+
        "many people in here, but they are mostly keeping to themselves. "+
        "This feels like a good place to relax, due to the clean air "+
        "and plesant smell. You see a sign in on the wall, perhaps "+
        "detailing the prices.\n   \n     \n   @--0\n   | \n   0\n"
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
    add_exit(ROOMS+"majestyave", "east");
    add_exit(ROOMS+"shadowroad", "south");
    set_property("no castle", 1);
    set_smell("default", "You smell sweet wine and.");
    set_listen("default", "You hear soft talking.");
}

  int read(string str) {
    object ob;
    int i;
    
    ob = present("dhamon");
    if(!ob) {
      write("Dhamon's blood smeared on the sign makes it unreadable.");
          return 1;
    }
    message("Ninfo", "The following classic beverages are served at the bar.\n",
      this_player());
    message("Ninfo",
      "-----------------------------------------------------------\n",
      this_player());
    message("Ninfo", "A Sweetberry Wine\t\t\t"+
      (int)ob->get_price("sweetberry wine")+" silver\n", this_player());
    message("Ninfo", "Some fine brew.\t\t"+(int)ob
      ->get_price("fine brew")+" silver\n", this_player());
    message("Ninfo", "A cheap ale\t\t\t"+(int)ob
      ->get_price("cheap ale")+" silver\n", this_player());
    message("Ninfo",
      "-----------------------------------------------------------\n",
      this_player());
    message("Ninfo", "<buy drink_name> gets you a drink.\n",
      this_player());
    return 1;
}
