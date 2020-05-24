//      Wizard:  Khojem
//      Dungeon Cell 1
//      md_cell1.c

#include <std.h>

inherit VAULT;

void create() {
    int i;
    ::create();
    set_property("light", -1);
    set_property("indoors", 1);
    set("short", "Dungeon Cell");
    set("long", 
      "You are in a dungeon cell  The floor and "+
      "walls are masoned in large stone blocks.  "+
      "It is very dark and the air is damp and musty.  "+
      "You pitty any creature forced to live in such cramped "+
      "quarters.  The cell is void of any form of comfort.  "+
      "A doorway is to the south."
   );
    set_items(([
      ({ "stones", "blocks", "stone", "block", "floor" }) :
        "The stone is rough and damp to the touch.  "+
        "It looks like these stones have been here since the beginning "+
        "of time.  They are large, massive stones.",
      ({ "door","doorway" }) : (: call_other, this_object(), "look_at_door" :),
        "rat"  :  "You spot a rat running away from you."
      ]));
    add_exit("md_dung2","south");
    set_door("door","/d/khojem/zone/md_dung2","south",0);
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "You hear a rats clawed paws nearby.");
}

void look_at_door() {
    if(query_open("door")) 
      write("The heavy wooden door stands open.\n");
    else write("The heavy wooden door is closed.\n");
}
