//      Wizard:  Khojem
//      Hareem Room 2
//      hareem2.c

#include <std.h>

inherit ROOM;

void init() {
    ::init();
}

void reset() {
    ::reset();
    if(!present("matron"))
      new("/d/khojem/nomad/mon/matron")->move(this_object());
    if(!present("hareem girl")) {
      new("/d/khojem/nomad/mon/hareem_girl")->move(this_object());
      new("/d/khojem/nomad/mon/hareem_girl")->move(this_object());
      new("/d/khojem/nomad/mon/hareem_girl")->move(this_object());
      new("/d/khojem/nomad/mon/hareem_girl")->move(this_object());
      new("/d/khojem/nomad/mon/hareem_girl")->move(this_object());
    }
}

void create() {
    string desc;
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set_property("night light",3);
    set("short", "inner hareem");
    desc = "This portion of the tent serves as a large boudoir.  "
      "The tent is well maintained.  It is well ventilated and "
      "lit.  Numerous pillows layer the floor.  Thin, sheer silks "
      "hang from the tent's ceiling which some what section off "
      "the room.\n";
    set("day long","The hot, desert sun beats down on the roof of "
      "the tent.  "+desc
    );
    set("night long",
      "The chill night air is warmed by the many lit torches.  "+desc
    );
    add_exit("/d/khojem/nomad/camp/hareem1","north");
    set_items(([
     ({ "tent", "ceiling" }) :
        "It looks like a clean well maintained canvas tent.",
     ({ "pillow","pillows" }) :
        "Fine silken pillows layer the floor.  You consider taking a few "+
        "but decide they are too bulky and may slow you down some.",
     ({ "torch", "torches" }) :  
        "A number of torches light the room.",
     ({ "silks", "sheer silks" }) :
        "The sheer, gossamer silks are hanging from the tents ceiling.  "+
        "They slightly mask your vision, but you easily pass by them "+
        "as you venture through the room."
    ]));
    set_smell("default", "The air is heavy with the smell of perfume.");
    set_listen("default", "This portion of the tent is quiet and shielded "
      "from the noise and bustle of the busy camp.");
}
