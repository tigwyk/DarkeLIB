//      Wizard:  Khojem
//      earl's mansion
//      e5.c

#include <std.h>

inherit ROOM;

void reset(){
  ::reset();
  if(!present("earl")) {
    new("/d/khojem/port/mon/earl")->move(this_object());
  }
  if(!present("viscount")) {
    new("/d/khojem/port/mon/viscount")->move(this_object());
  }
  if(!present("legionnaire")) {
    new("/d/khojem/port/mon/legion3")->move(this_object());
    new("/d/khojem/port/mon/legion3")->move(this_object());
    new("/d/khojem/port/mon/legion3")->move(this_object());
  }
}  

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set("short", "The office of the Earl of Vo'Sangor");
    set("long", "This is the office of the Earl of Vo'Sangor.  Here the Earl "+
      "transacts the business affairs of Vo'Sangor.  A large, mahogany conference "+
      "table dominates the left side of the spacious room.  To south a large, desk "+
      "rests before a large window.  The room has heavy, slate floors and many "+
      "oil paintings.  The walls are paneled in english oak.  "+
      "An archway leads north to a balcony."
    );
    add_exit("/d/khojem/port/room/e3","north");
    set_items(([
     ({ "window" }) :
        "A broad window looks out across the harbor of Vo'Sangor.",
     ({ "harbor", "ships", "water", "sea", "channel" }) :
        "Towards the south a wide harbor can be seen.  A few ships are docked "+
        "at the wharf bordering the harbor on the west and north sides.  The "+
        "harbor is enclosed by a reef to the west and a rocky breakwater to the "+
        "south.  At the south tip of the reef a broad, sandy shoreline of a small "+
        "island can be seen.  Between the island and the breakwater is a wide "+
        "channel for merchant vessels to access the open seas.",
     ({ "wharf" }) : "A wooden wharf borders the harbor to the north and west.",
     ({ "breakwater" }) :
        "A rocky breakwater was constructed to protect the harbor from storm.",
     ({ "reef", "shipwreck", "rocks" }) :
        "Where the reef and the sandy, island meet a worn, sun-bleached shipwreck "+
        "can be seen.  What was once a fine merchant vessel lays in ruin.  The "+
        "three masts have long since broken off and "+
        "only stubs remain.  The deck is wide and the hull leans to one side against "+
        "rocks of the island's north cape.",
     ({ "island", "smoke" }) :
        "A small island with numerous palm trees rests near the channel to the "+
        "open sea.  Near the reef the shoreline is rocky, but most of the island "+
        "has a wide sandy beach.  A single, slender trail of smoke can be seen "+
        "raising up through the palms before the sea breeze disperses it.",
     ({ "oil paintings", "paintings" }) :
        "Paintings of the Earl of Vo'Sangor as a young man line the balcony's "+
        "wall.  In many he is dressed as a soldier with polished armour and "+
        "armed with sword and lancet.  Often mounted on a fine white stallion.", 
     ({ "office", "balcony" }) : "It's a hell of a pad!",
     ({ "furniture", "mahogany furniture" }) :
        "The mahogany furniture was probably imported.  It's wood is highly "+
        "polished.",
     ({ "floors", "slate floors", "floor" }) :
        "The slate floors are finely crafted and well maintained.",
     ({ "walls", "wall", "english oak", "english oak walls", "paneling" }):
        "The english oak wall paneling is highly polished and of the finest "+
        "quality.  It is exquisitely molded with fine details and scrollwork.",
     ({ "conference table", "table" }) :
        "The highly, polished conference table is filled with papers that "+
        "describe a construction project to expand the town."
    ]));
    set_listen("default", "You hear seagull crys through the window.");
    new("/d/khojem/port/obj/desk")->move(this_object());
}

