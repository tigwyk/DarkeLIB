//      Wizard:  Khojem
//      s02.c

#include <std.h>

inherit VAULT;

int no_exit() { return 1;}

void init() {
    ::init();
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","south");
    }
}

void reset(){
  set_open("green door",0);
  set_locked("green door",0);
  "/d/khojem/port/room/hou3"->set_open("green door",0);
  "/d/khojem/port/room/hou3"->set_locked("green door",0);
  add_invis_exit("south");
  "/d/khojem/port/room/hou3"->add_invis_exit("north");
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
//Basic mapping added by Tiny 1/19/2020
    set("short", "   \n    \n0--@--0\n    \n   \nDock Street");
    set("long", "Dock Street extends east and west.  Its dry, dirt road sends up "+
      "small swirls of dust with every footstep.  The wall of a building is to "+
      "the north and a shabby house is to the south.  The street opens to a "+
      "large square to the east.\n   \n    \n0--@--0\n    \n   \n"
    );
    add_exit("/d/khojem/port/room/s01","west");
    add_exit("/d/khojem/port/room/s04","east");
    add_exit("/d/khojem/port/room/hou3","south");
    add_invis_exit("south");
    set_door("green door","/d/khojem/port/room/hou3","south",0);
    set_open("green door",0);
    set_locked("green door",0);
    set_func("green door","open","do_green_open");
    set_func("green door","close","do_green_close");
    set_items(([
     ({ "green door", "door" }) :
        (: call_other, this_object(), "look_at_green_door" :),
     ({ "street","dirt street","Dock Street","dock street" }) :
        "Its a dusty little road.",
     ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town surrounds you.");
}

void look_at_green_door() {
  if(query_open("green door")) 
    write("The green door is wide open.\n");
  else 
    write("The green door is closed.\n");
  say(this_player()->query_cap_name()+" examines a green door to the south.\n");
}

int do_green_open() {
  remove_invis_exit("south");
  "/d/khojem/port/room/hou3"->remove_invis_exit("north");
  write("The green door easily swings open.\n");
  say(this_player()->query_cap_name()+" opens a green door to the south.\n");
  return 1;
}
 
int do_green_close() {
  add_invis_exit("south");
  "/d/khojem/port/room/hou3"->add_invis_exit("north");
  write("A green door is slammed shut.\n");
  say(this_player()->query_cap_name()+" slams a green door shut.\n");
  return 1;
}

