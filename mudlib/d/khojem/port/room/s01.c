//      Wizard:  Khojem
//      s01.c

#include <std.h>

inherit VAULT;

int no_exit() { return 1;}

void init() {
    ::init();
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","north");
      add_action("no_exit","south");
    }
}

void reset(){
  set_open("blue door",0);
  set_locked("blue door",0);
  "/d/khojem/port/room/hou1"->set_open("blue door",0);
  "/d/khojem/port/room/hou1"->set_locked("blue door",0);
  add_invis_exit("north");
  "/d/khojem/port/room/hou1"->add_invis_exit("south");
  set_open("red door",0);
  set_locked("red door",0);
  "/d/khojem/port/room/hou2"->set_open("red door",0);
  "/d/khojem/port/room/hou2"->set_locked("red door",0);
  add_invis_exit("south");
  "/d/khojem/port/room/hou2"->add_invis_exit("north");
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
//Basic mapping added by Tiny 1/19/2020
    set("short", "   \n    \n0--@--0\n    \n   \nDock Street");
    set("long", "Dock Street extends eastward.  Its dry, dirt road sends up "+
      "small swirls of dust with every footstep.  Small, shabby houses line the "+
      "causeway north and south.\n   \n    \n0--@--0\n    \n   \n"
    );
    add_exit("/d/khojem/port/room/wgate","west");
    add_exit("/d/khojem/port/room/s02","east");
    add_exit("/d/khojem/port/room/hou1","north");
    add_exit("/d/khojem/port/room/hou2","south");
    add_invis_exit("north");
    set_door("blue door","/d/khojem/port/room/hou1","north",0);
    set_open("blue door",0);
    set_locked("blue door",0);
    set_func("blue door","open","do_blue_open");
    set_func("blue door","close","do_blue_close");
    add_invis_exit("south");
    set_door("red door","/d/khojem/port/room/hou2","south",0);
    set_open("red door",0);
    set_locked("red door",0);
    set_func("red door","open","do_red_open");
    set_func("red door","close","do_red_close");
    set_items(([
     ({ "blue door", "north door" }) :
        (: call_other, this_object(), "look_at_blue_door" :),
     ({ "door" }) :
        "There are two doors here, a blue door north and a red door south",
     ({ "red door", "south door" }) :
        (: call_other, this_object(), "look_at_red_door" :),
     ({ "street","dirt street","Dock Street","dock street" }) :
        "Its a dusty little road.",
     ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town surrounds you.");
}

void look_at_blue_door() {
  if(query_open("blue door")) 
    write("The blue door is wide open.\n");
  else 
    write("The blue door is closed.\n");
  say(this_player()->query_cap_name()+" examines a blue door to the north.\n");
}

int do_blue_open() {
  remove_invis_exit("north");
  "/d/khojem/port/room/hou1"->remove_invis_exit("south");
  write("The blue door easily swings open.\n");
  say(this_player()->query_cap_name()+" opens a blue door to the north.\n");
  return 1;
}
 
int do_blue_close() {
  add_invis_exit("north");
  "/d/khojem/port/room/hou1"->add_invis_exit("south");
  write("A blue door is slammed shut.\n");
  say(this_player()->query_cap_name()+" slams a blue door shut.\n");
  return 1;
}

void look_at_red_door() {
  if(query_open("red door")) 
    write("The red door is wide open.\n");
  else 
    write("The red door is closed.\n");
  say(this_player()->query_cap_name()+" examines a red door to the north.\n");
}

int do_red_open() {
  remove_invis_exit("south");
  "/d/khojem/port/room/hou2"->remove_invis_exit("north");
  write("The red door easily swings open.\n");
  say(this_player()->query_cap_name()+" opens a red door to the south.\n");
  return 1;
}
 
int do_red_close() {
  add_invis_exit("south");
  "/d/khojem/port/room/hou2"->add_invis_exit("north");
  write("A red door is slammed shut.\n");
  say(this_player()->query_cap_name()+" slams a red door shut.\n");
  return 1;
}

