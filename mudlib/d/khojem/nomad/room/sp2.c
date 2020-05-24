//      Wizard:  Khojem
//      sand pit 2
//      sp2.c

#include <std.h>

inherit ROOM;

void reset() {
    ::reset();
    if(!present("spider")) {
      new("/d/khojem/nomad/mon/sand_spider")->move(this_object());
      new("/d/khojem/nomad/mon/sand_spider")->move(this_object());
    }
}

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "A dark sand pit");
    set("long",
      "You are in a dark chamber.  The ceiling is very low and old cobwebs "+
      "dangle from it just above "+
      "your head.  The sand floor muffles your footsteps but any noise you make "+
      "echos off distant walls."
   );
    add_exit("/d/khojem/nomad/room/sp3","north");
    add_exit("/d/khojem/nomad/room/sp1","south");
    add_invis_exit("north");
    add_invis_exit("south");
    set_items(([
     ({ "cave","cavern", "chamber" }) :
        "All you can see is the floor you are standing on and a few feet "+
        "of the floor around you.  Everything beyond is engulfed in darkness.",
     ({ "ceiling" }) :
        "The chamber's sandstone ceiling is just above your head.",
     ({ "cobweb", "cobwebs" }) :
        "Dust covers the once sticky, silky threads.  They have long been "+
        "abandoned and hang limply from the ceiling.",
     ({ "floor", "sand" }) :
        "The floor is composed of soft, silky sand.",
     ({ "wall", "walls" }) :
        "You can't see any walls from here, but all noise reflects from them "+
        "somewhere in the distance.",
    ]));
    set_smell("default", "It smells awful here, but you can't figure out the smell.");
    set_listen("default", "You hear the sound of some small animals skirting about "+
      "on the sandy floor.");
}
