//      Wizard:  Khojem
//      Palace Guard's Captain's Room
//      md_captain.c

#include <std.h>

inherit VAULT;

void reset() {
   ::reset();
   if (!present("drawers")) {
      new("/d/khojem/zone/obj/drawers")->move(this_object());
   }
   if (!present("captain")) {
      new("/d/khojem/zone/mon/captain")->move(this_object());
   }
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "Palace Guard - Captain's Quarters");
    set("long", 
      "You have entered the private quarters of the Captain of the Guard "+
      "of the Palace Guards.  A few candles on a desk provide some reading "+
      "light at the captain's desk.  In the corner is a small bed with "+
      "a pinestraw matress.  Beside the single window rests a chest of "+
      "drawers.  On the floor is the skin of some animal."
   );
    set_items(([
      ({ "stairs","stair" }) :
        "A series of stone masonery steps lead down into darkness.",
        "door" : (: call_other, this_object(), "look_at_door" :),
         "window" : "The window is dirty and cracked.",
      ({ "candle", "candles" }) : 
         "A few flickering candles of common peasant quality "+
         "burn here.  They have been used extensively and only "+
         "about an inch of wick remains.",
      ({ "desk", "table" }) : (: call_other, this_object(), "look_at_desk" :),

      ({ "bed", "pinestraw", "mattress" }) :
         "The bed appears uncomfortable and lice ridden.",
      ({ "floor", "skin", "animal", "bear" }) :
         "It is a bear-skin rug.  The bear's coat is a rich, dark black. "+
         "Its head is raised slightly from the floor due to it open jaws.",
      ({ "head", "eyes", "jaws", "jaw", "teeth"}) : 
          (: call_other, this_object(), "look_at_eyes" :)
      ]));
    add_exit("md_donjon3","east");
    set_door("door","/d/khojem/zone/md_donjon3","east",0);
    set_smell("default", "A horrible, rotten smell permeates the air.");
}

void look_at_door() {
    if(query_open("door")) 
      write("The heavy wooden door stands open.\n");
    else write("The heavy wooden door is closed.\n");
}

void look_at_desk() {
      write("The captain isn't much for paperwork.\n");
}

void look_at_eyes() {
      write("The bear's dark, glassy eyes stare vacately up at you.\n");
}

