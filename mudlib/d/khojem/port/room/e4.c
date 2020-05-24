//      Wizard:  Khojem
//      e4.c

#include <std.h>

inherit VAULT;

void reset(){
  set_open("brass door",0);
  set_locked("brass door",1);
  "/d/khojem/port/room/e7"->set_open("brass door",0);
  "/d/khojem/port/room/e7"->set_locked("brass door",1);
  add_invis_exit("east");
  "/d/khojem/port/room/e7"->add_invis_exit("west");
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Mansion Basement");
    set("long", "The decor of this basement is much different than the rest of "+
      "the mansion.  The Earl of Vo'Sangor chose not to lavish this portion of "+
      "his mansion with the trappings of wealth.  The rough-hewned, stone walls "+
      "and floor form a short hallway that leads to a brass door."
    );
    add_exit("/d/khojem/port/room/e1","up");
    add_exit("/d/khojem/port/room/e7","east");
    set_door("brass door","/d/khojem/port/room/e7","east","earl_desk_key");
    set_property("magic hold",80);
    set_open("brass door",0);
    set_locked("brass door",1);
    set_lock_level("brass door",35);
    set_func("brass door","open","do_open");
    set_func("brass door","close","do_close");
    set_items(([
     ({ "brass door", "door" }) : 
        (: call_other, this_object(), "look_at_door" :),
     ({ "basement", "hallway", "walls", "wall", "floor" }) :
        "The stone walls and floor are sturdy and firm.  No secret passageways "+
        "here.",
     ]));
    set_smell("default", "A damp musty smell fills the air.");
    set_listen("default", "You hear grunts and a rustling noises closeby.");
}

void look_at_door() {
  if(query_open("brass door")) 
    write("The brass door is wide open.\n");
  else 
    write("The brass door is closed.\n");
  say(this_player()->query_cap_name()+" examines a brass door.\n");
}

int do_open() {
  remove_invis_exit("east");
  "/d/khojem/port/room/e7"->remove_invis_exit("west");
  write("The brass door easily swings open.\n");
  say(this_player()->query_cap_name()+" opens a brass door to the east.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("east");
  "/d/khojem/port/room/e7"->add_invis_exit("west");
  write("A brass door is slammed shut.\n");
  say(this_player()->query_cap_name()+" slams a brass door shut.\n");
  return 1;
}

