//      Wizard:  Khojem
//      Donjon Room 3
//      md_donjon3.c

#include <std.h>

inherit VAULT;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "Castle's Donjon");
    set("long", 
      "You are still in the donjon, but are now on a small landing.  "+
      "A door is against the west wall.  Stone stairs lead up and "+
      "down from this landing."
   );
    set_items(([
      ({ "stairs","stair" }) :
        "A set of worn, stone masonery steps lead down into darkness.  "+
        "Another set of steps lead up farther into the Donjon's Tower.",
        "door" : (: call_other, this_object(), "look_at_door" :)
      ]));
    add_exit("md_donjon2","down");
    add_exit("md_donjon4","up");
    add_exit("md_captain","west");
    set_door("door","/d/khojem/zone/md_captain","west",0);
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "You hear the wind blowing down the stairway "+
      "from above the landing.");
}

void look_at_door() {
    if(query_open("door")) 
      write("The heavy wooden door stands open.\n");
    else write("The heavy wooden door is closed.\n");
}

void rest() {
  set_open("door",0);
  set_locked("door",0);
  "/d/khojem/zone/md_captain"->set_open("door",0);
  "/d/khojem/zone/md_captain"->set_locked("door",0);
}
