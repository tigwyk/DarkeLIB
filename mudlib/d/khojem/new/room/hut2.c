//      Wizard:  Khojem
//      Wood-elf Hut 2
//      hut2.c

#include <std.h>

inherit ROOM;

void reset() {
   ::reset();
   if (!present("commoner")) {
      new("/d/khojem/new/mon/commoner")->move(this_object());
   }
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "   \n    \n0--@   \n    \n   \nA small wood-elf hut");
    set("long", "This is a small, one-room hut with a thatched roof.  "+
      "The small, stone hearth with its fire makes this a "+
      "warm, comfortable place.  The window provides fresh air "+
      "and light.  A short table is surrounded by equally short chairs.\n   \n    \n0--@   \n    \n   \n"   
    );
    add_exit("plat2","west");
    set_items(([
        "hut" :  "The small hut is clean, neat, and well maintained.",
     ({ "thatched roof", "roof" }) :
        "The roof is woven with leaves and vines from the forest.",
     ({ "stone hearth", "hearth", "fire" }) :
        "A small fire burns here on a well constructed stone hearth.  "+
        "Surely the elves wouldn't want a fire to break out in the village!",
        "window" : "The large window lets in much light and fresh air.",
     ({ "table", "chair", "chairs" }) : 
        "A small, wooden table is surrounded "+
        "by a few small, wooden chairs."
     ]));
    set_smell("default", "The air is fresh and vibrant.");
    set_listen("default", "You hear the occasional sound of birds singing.");
}

