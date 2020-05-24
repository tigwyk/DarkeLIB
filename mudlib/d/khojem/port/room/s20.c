//      Wizard:  Khojem
//      s20.c

#include <std.h>

inherit VAULT;

int no_exit() { return 1;}

void init() {
    ::init();
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","northeast");
    }
}

void reset(){
  set_open("teal door",0);
  set_locked("teal door",1);
  "/d/khojem/port/room/e1"->set_open("teal door",0);
  "/d/khojem/port/room/e1"->set_locked("teal door",1);
  add_invis_exit("northeast");
  "/d/khojem/port/room/e1"->add_invis_exit("southwest");
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
//Basic mapping added by Tiny 1/19/2020
    set("short", "   \n     \n0--@   \n   | \n   0\nNoble Street");
    set("long", "Noble Street extends west and south.  "+
      "The street's dry dirt sends up small swirls of dust with every "+
      "footstep.  Here the street turns and a large mansion is seen to "+
      "the northeast.\n   \n     \n0--@   \n   | \n   0\n"
    );
    add_exit("/d/khojem/port/room/s18","west");
    add_exit("/d/khojem/port/room/s21","south");
    add_exit("/d/khojem/port/room/e1","northeast");
    add_invis_exit("northeast");
    set_door("teal door","/d/khojem/port/room/e1","northeast","sangor key");
    set_property("magic hold",80);
    set_lock_level("teal door", 15);
    set_open("teal door",0);
    set_locked("teal door",1);
    set_func("teal door","open","do_teal_open");
    set_func("teal door","close","do_teal_close");
    set_items(([
     ({ "teal door", "door" }) :
        (: call_other, this_object(), "look_at_teal_door" :),
     ({ "mansion" }) :
        "It looks like an expensive mansion.  Some noble must own it.  "+
        "The mansion is painted yellow and has a huge teal door facing "+
        "the road.  The windows are covered with elaborate wrought iron "+
        "to discourage any illegal entry by thieves.",
     ({ "wrought iron","iron","windows","window" }) :
        "An expensive and elaborate wrought iron grillwork protects the "+
        "mansion from illegal entry by thieves.",
     ({ "street","dirt street","Wharf Street","wharf street" }) :
        "Its a dusty little road.",
     ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town surrounds you.");
}

void look_at_teal_door() {
  if(query_open("teal door")) 
    write("The teal door is wide open.\n");
  else 
    write("The teal door is closed.\n");
  say(this_player()->query_cap_name()+" examines a teal door to the northeast.\n");
}

int do_teal_open() {
  remove_invis_exit("northeast");
  "/d/khojem/port/room/e1"->remove_invis_exit("southwest");
  write("The teal door easily swings open.\n");
  say(this_player()->query_cap_name()+" opens a teal door to the northeast.\n");
  return 1;
}
 
int do_teal_close() {
  add_invis_exit("south");
  "/d/khojem/port/room/e1"->add_invis_exit("northeast");
  write("A teal door is slammed shut.\n");
  say(this_player()->query_cap_name()+" slams a teal door shut.\n");
  return 1;
}

