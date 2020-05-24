//      Wizard:  Khojem
//      MD-alley4
//      md_alley4.c

#include <std.h>

inherit ROOM;

void init(){
  ::init();
  add_action("secret_brick","push");
}

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "Alley");
    set("long", "You stand in a damp, dirty alley.  Its narrow "+
      "walls close in around you and make you feel uncomfortable."
  );
    set_items(([
      ({ "passageway", "passage" }) : (: call_other, this_object(), "look_at_passage" :),
      ({ "wall", "walls" }) :
       "You see little of interest.  The wall is filled with graffiti.\n"
       "One brick looks alittle odd.",
      ({ "graffiti", "letters", "lettering", "writing", "write" }) :
       "It doesn't make much sense to you.",
       "brick" : "In very small lettering the brick reads:  PUSH",
      ({ "alley", "dirty", "dirt" }) : "It is surrounded by brick walls."
      ])); 
    add_exit("md_alley3","east");
    add_exit("md_house7","north");
    add_exit("md_house8","south");
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "All around you are the sounds of slow dripping water.");
}


int secret_brick(string str) {
  object ob, *inv;
  int    i;
  
  if(!str){
    notify_fail("You push alot, but nothing seems to happen.\n");
    return 0;
  }
  if(str !="brick"){
    notify_fail("Pushing that doesn't seem to accomplish much.\n");
    return 0;
  }
  write("The brick smoothly and quickly recesses into the wall.\n");
  inv = all_inventory(this_object());
  i = sizeof(inv);
  while(i--) {
    if (living(inv[i])) {
      write("Suddenly the floor tilts to a sharp angle and you fall.");
      inv[i]->move("/d/khojem/zone/md_hideout");
    write("You fall into a heap in a dark hideout.");
  write("You suspect the owners will not like finding you here.");
    }
  }
}

