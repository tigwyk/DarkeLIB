//      Wizard:  Khojem
//      Donjon Room 2
//      md_donjon2.c

#include <std.h>

inherit ROOM;

void reset() {
   ::reset();
   new("/d/khojem/zone/mon/plguard2")->move(this_object());
   new("/d/khojem/zone/mon/plguard2")->move(this_object());
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Castle's Donjon");
    set("long", 
      "This is the barracks for the palace guard.  "+
      "Numerous bunks and benches line the walls. "+
      "The palace guards live with few comforts and luxuries.  "+
      "A stone stairway exits against the far wall."
   );
    set_items(([
      ({ "stair","stairs" }) :
        "A set of winding stone stairs lead up into darkness.",
      ({ "bunks","bunk" }) : 
        "These bunks are merely a few wooden planks and a straw "+
        "mattress.  The bedding smells bad and needs a good wash.",
      ({ "wall","walls" }) :
        "The walls are made of large stone masonery blocks.  "+
        "The guards have passed the time by making crude drawings "+
        "of Sword-demon females in various states of disrobement.  ",
      ({ "bench","benches","benchs" }) :
        "Most of these wooden benches are in need of repair.  "+
        "Maybe they are used as encouragement for the guards "+
        "to stand longer watches... "
    ]));
    add_exit("md_donjon3","up");
    add_exit("md_donjon1","west");
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "All around you are the sounds of slow dripping water.");
}

