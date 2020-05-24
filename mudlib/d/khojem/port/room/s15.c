//      Wizard:  Khojem
//      s15.c

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
  set_open("yellow door",0);
  set_locked("yellow door",0);
  "/d/khojem/port/room/hou4"->set_open("yellow door",0);
  "/d/khojem/port/room/hou4"->set_locked("yellow door",0);
  add_invis_exit("north");
  "/d/khojem/port/room/hou4"->add_invis_exit("south");
  set_open("acqua door",0);
  set_locked("acqua door",0);
  "/d/khojem/port/room/hou5"->set_open("acqua door",0);
  "/d/khojem/port/room/hou5"->set_locked("acqua door",0);
  add_invis_exit("south");
  "/d/khojem/port/room/hou5"->add_invis_exit("north");
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
//Basic mapping added by Tiny 1/19/2020
    set("short", "   \n    \n0--@--0\n    \n   \n Dock Street");
    set("long", "Noble Street extends eastward.  Its dry, dirt road sends up "+
      "small swirls of dust with every footstep.  Small houses line the "+
      "causeway north and south.\n   \n    \n0--@--0\n    \n   \n "
    );
    add_exit("/d/khojem/port/room/s06","west");
    add_exit("/d/khojem/port/room/s18","east");
    add_exit("/d/khojem/port/room/hou4","north");
    add_exit("/d/khojem/port/room/hou5","south");
    add_invis_exit("north");
    set_door("yellow door","/d/khojem/port/room/hou4","north",0);
    set_open("yellow door",0);
    set_locked("yellow door",0);
    set_func("yellow door","open","do_yellow_open");
    set_func("yellow door","close","do_yellow_close");
    add_invis_exit("south");
    set_door("acqua door","/d/khojem/port/room/hou5","south",0);
    set_open("acqua door",0);
    set_locked("acqua door",0);
    set_func("acqua door","open","do_acqua_open");
    set_func("acqua door","close","do_acqua_close");
    set_items(([
     ({ "yellow door", "north door" }) :
        (: call_other, this_object(), "look_at_yellow_door" :),
     ({ "acqua door", "south door" }) :
        (: call_other, this_object(), "look_at_acqua_door" :),
     ({ "door", "doors" }) :
         "There is a yellow door to the north and an acqua door south.",
     ({ "street","dirt street","Wharf Street","wharf street" }) :
        "Its a dusty little road.",
     ({ "houses", "house" }) :
        "The houses are owned by the wealthy residents of Vo'Sangor.",
     ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town surrounds you.");
}

void look_at_yellow_door() {
  if(query_open("yellow door")) 
    write("The yellow door is wide open.\n");
  else 
    write("The yellow door is closed.\n");
  say(this_player()->query_cap_name()+" examines a yellow door to the north.\n");
}

int do_yellow_open() {
  remove_invis_exit("north");
  "/d/khojem/port/room/hou4"->remove_invis_exit("south");
  write("The yellow door easily swings open.\n");
  say(this_player()->query_cap_name()+" opens a yellow door to the north.\n");
  return 1;
}
 
int do_yellow_close() {
  add_invis_exit("north");
  "/d/khojem/port/room/hou4"->add_invis_exit("south");
  write("A yellow door is slammed shut.\n");
  say(this_player()->query_cap_name()+" slams a yellow door shut.\n");
  return 1;
}

void look_at_acqua_door() {
  if(query_open("acqua door")) 
    write("The acqua door is wide open.\n");
  else 
    write("The acqua door is closed.\n");
  say(this_player()->query_cap_name()+" examines a acqua door to the north.\n");
}

int do_acqua_open() {
  remove_invis_exit("south");
  "/d/khojem/port/room/hou5"->remove_invis_exit("north");
  write("The acqua door easily swings open.\n");
  say(this_player()->query_cap_name()+" opens a acqua door to the south.\n");
  return 1;
}
 
int do_acqua_close() {
  add_invis_exit("south");
  "/d/khojem/port/room/hou5"->add_invis_exit("north");
  write("A acqua door is slammed shut.\n");
  say(this_player()->query_cap_name()+" slams a acqua door shut.\n");
  return 1;
}

