//      Wizard:  Khojem
//      l3.c

#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "tower");
     set("long","The spiraling staircase opens up to a large circular "+
       "catwalk.  It appears this tower was constructed as a lighthouse, "+
       "but years of neglect has taken its toll.  The light's powerful "+
       "lens is cracked and ruined.  The iron railing around the catwalk "+
       "is pitted with rust from years of exposure to the corrosive salt "+
       "air.  From this height you can see all of the town of Vo'Sangor.  "+
       "Due to your elevation, you can only accurately make out objects in "+
       "the square below.  In the distance you can see the rocky breakwater "+
       "and natural reef that protects the town's harbor.  Off to the "+
       "northwest you can see the towering precipice that overlooks the "+
       "entire town."
    );
    add_exit("/d/khojem/port/room/l2","down");
    add_exit("/d/khojem/port/room/s08","north");
    add_exit("/d/khojem/port/room/s16","northeast");
    add_exit("/d/khojem/port/room/s17","east");
    add_exit("/d/khojem/port/room/s10","south");
    add_exit("/d/khojem/port/room/s05","southwest");
    add_exit("/d/khojem/port/room/s04","west");
    add_exit("/d/khojem/port/room/s03","northwest");
    add_invis_exit("north");
    add_invis_exit("northeast");
    add_invis_exit("east");
    add_invis_exit("south");
    add_invis_exit("southwest");
    add_invis_exit("west");
    add_invis_exit("northwest");
    set_pre_exit_functions(({"north"}),({"go_north"}));
    set_pre_exit_functions(({"east"}),({"go_north"}));
    set_pre_exit_functions(({"south"}),({"go_north"}));
    set_pre_exit_functions(({"southwest"}),({"go_north"}));
    set_pre_exit_functions(({"west"}),({"go_north"}));
    set_pre_exit_functions(({"northwest"}),({"go_north"}));
    set_items(([
     ({ "breakwater" }) :
        "A rocky, breakwater borders the harbor to the south and protects it from "+
        "the sea's stormy waves.",
     ({ "reef" }) :
        "A reef borders the harbor towards the east.",
     ({ "sea" }) :
        "Beyond the breakwater and reef a restly sea can be seen.",
     ({ "catwalk", "railing" }) :
        "A rusted, iron catwalk surrounds the pinnacle of the lighthouse.  "+
        "The catwalk is bordered by a rusty, iron railing.  A stairway leads "+
        "down into the lighthouse.",
     ({ "lens" }) :
        "At one time a superbly crafted glass lens was used to shine a beacon "+
        "to guide merchant vessels into Vo'Sangor's harbor.  Now, the lens is "+
        "cracked and worthless.",
     ({ "lighthouse", "tower" }) :
        "The lighthouse stands high above Vo'Sangor's merchant square and "+
        "provides and excellent vista towards the harbor.",
     ({ "square" }) :
        "The merchant square of Vo'Sangor can be seen below.",
     ({ "precipice" }) :
        "Towards the northwest a rocky escarpment can be seen.",
     ({ "staircase" }) :
        "The iron staircase follows the curve of the tower's outer wall.  Each "+
        "step is afixed to the wall and cantilevered towards the center of the "+
        "wide tower.  The steps are rusted, but appear strong enough to support "+
        "your weight."
    ]));
    set_smell("default", "The air is filled with sea mist that tingles "+
      "as it adheres to the skin of your face.");
    set_listen("default", "You hear the wind howling.");
}

int go_north() {
  if(this_player()->query_flying()){
    write("You gently soar down from the high tower.\n");
    return 1;
  }
  write("That would be a bad idea.  A fall from this height is death.\n");
  say(this_player()->query_cap_name()+" foolishly climbs up on the railing "+
    "and for a moment appears like a jumper.\n");
  return 0;
}

