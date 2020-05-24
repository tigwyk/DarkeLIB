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
     ({ "conference table", "table" }) :
        "The highly, polished conference table is filled with papers that "+
        "describe a construction project to expand the town."
    ]));
    set_listen("default", "You hear seagull crys through the window.");
}

