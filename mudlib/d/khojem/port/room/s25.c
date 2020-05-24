//      Wizard:  Khojem
//      s25.c

#include <std.h>

inherit VAULT;

int no_exit() { return 1;}

void init() {
    ::init();
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","hatch");
      add_action("no_exit","down");
    }
}

void reset(){
  set_open("hatch",0);
  set_locked("hatch",0);
  "/d/khojem/port/room/ship2"->set_open("hatch",0);
  "/d/khojem/port/room/ship2"->set_locked("hatch",0);
  add_invis_exit("south");
  "/d/khojem/port/room/ship2"->add_invis_exit("north");
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
//Basic mapping added by Tiny 1/19/2020
    set("short", "   \n    \n0--@   \n   d \n   \nDock Street");
    set("long","Dock Street extends east and west.  "+
      "The harbor is just to the south.  "+
      "A schooner is berthed closeby to the south.  "+
      "The wooden boards beneath your feet creak with every footstep.\n   \n    \n0--@   \n   d \n   \n"
    );
    add_exit("/d/khojem/port/room/s24","west");
    add_exit("/d/khojem/port/room/h23","down");
    set_pre_exit_functions(({"down"}),({"go_down"}));
    add_exit("/d/khojem/port/room/ship2","south");
    add_invis_exit("south");
    set_door("hatch","/d/khojem/port/room/ship2","south",0);
    set_open("hatch",0);
    set_locked("hatch",0);
    set_func("hatch","open","do_open");
    set_func("hatch","close","do_close");
    set_items(([
     ({ "ladder" }) :
        "It is a simple wooden ladder that leads down from the edge of the "+
        "dock to the water's surface a few feet below.",
     ({ "ship","schooner" }) :
        "The schooner is a worn, battered ship, but appear still seaworthy.  "+
        "It has foremast and mainmast stepped near amidships.  The ship's "+
        "appear soiled and heavily patched.  Its hull is encrusted with "+
        "large amounts of algae.  Obviously, this ship has not been well-"+
        "maintained during its many years of use.",
     ({ "hatch" }) : 
        (: call_other, this_object(), "look_at_door" :),
     ({ "boards","wooden boards" }) :
        "The wooden boards of the dock are supported above the water my timbers.  "+
        "The boards are bleached from exposure to sun and salt air.",
     ({ "street","dirt street","Wharf Street","wharf street","dock" }) :
        "Wharf Street is nothing more than a wooden deck supported above the water."
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "Waves in the harbor lap against the dock's pilings.");
}

void look_at_door() {
  if(query_open("hatch")) 
    write("The hatch is wide open.\n");
  else 
    write("The hatch is closed.\n");
  say(this_player()->query_cap_name()+" examines a hatch to the south.\n");
}

int do_open() {
  remove_invis_exit("south");
  "/d/khojem/port/room/ship2"->remove_invis_exit("north");
  write("The hatch easily swings open.\n");
  say(this_player()->query_cap_name()+" opens a hatch to the south.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("south");
  "/d/khojem/port/room/ship2"->add_invis_exit("north");
  write("A hatch is slammed shut.\n");
  say(this_player()->query_cap_name()+" slams a hatch shut.\n");
  return 1;
}

int go_down() {
    write("Khojem suddenly materializes from the air and says,\n"+
      "     'I haven't implemented the water code yet.  Hang on!'\n");
    return 0;
}

